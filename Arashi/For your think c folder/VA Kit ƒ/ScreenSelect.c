/*/
     Project Arashi: ScreenSelect.c
     Major release: Version 1.1.1, 3/17/95

     Last modification: Thursday, February 18, 1993, 16:26
     Created: Thursday, February 7, 1991, 7:21

     Copyright � 1991-1993, Juri Munkki
/*/

#include <Windows.h>
#include <Dialogs.h>
#include <Resources.h>

#include	"ScreenSelect.h"


extern void CreateOptionsDialog(void);
extern void CloseOptionsDialog(void);
extern void OptionsUpdate(int ScreenAvailable);
extern int DoStartupDialog(int item);


#define		HILITEMODE	asm {	BCLR	#7,0x938	}

extern	EventRecord		Event;

ScreenInfo			*Screens;
int					NumScreens;
PicHandle			YesPict,NoPict;
Rect				MessageFrame;

void	CreateScreenWindows()
{
	register	GDHandle	GDev;
				Rect		DispFrame,WindFrame;
				int			zero=0;
	
	GDev=GetDeviceList();

	do
	{	
		DispFrame=(*GDev)->gdRect;
		
		WindFrame.left=(DispFrame.right+DispFrame.left-MessageFrame.right)/2;
		WindFrame.right=WindFrame.left+MessageFrame.right;

#define	no_CLASSIC_SCREEN_TEST
#ifdef	CLASSIC_SCREEN_TEST
		WindFrame.bottom=342;
		WindFrame.top=WindFrame.bottom-MessageFrame.bottom;
#else
		WindFrame.top=DispFrame.bottom-MessageFrame.bottom-4;
		WindFrame.bottom=WindFrame.top+MessageFrame.bottom;
#endif
#ifdef ORIG_ARASHI
		Screens[NumScreens].status=(*(*GDev)->gdPMap)->pixelSize == 8;
#else
#ifdef NICK_NOT_QUICKDRAW
#ifdef NICK_256_NOT_1
		Screens[NumScreens].status=(*(*GDev)->gdPMap)->pixelSize == 8;
#else
		Screens[NumScreens].status=(*(*GDev)->gdPMap)->pixelSize == 1;
#endif
#else
    /* QuickDraw only version runs on any depth/screen */
    Screens[NumScreens].status=1;
#endif
#endif
		Screens[NumScreens].device=GDev;
		Screens[NumScreens].window=NewWindow(0,&WindFrame,&zero,-1,plainDBox,(void *)-1,0,0);
			
		NumScreens++;	
		GDev=GetNextDevice(GDev);
	}	while(GDev && NumScreens<MAXSCREENS);
}
/*
>>	Gets the mouse position while in a tracking loop.
>>	Returns true when the mouse button comes up.
*/

int GetMouseTrackEvent(pt)
register	Point	*pt;
{
	register	int 	r=0;
	
	r=GetNextEvent(mUpMask+mDownMask,&Event);
	*pt=Event.where;
	GlobalToLocal(pt);
	
	if(r)	r=(Event.what==mouseUp);
	return !r;
}

ScreenInfo	*Clickety(info)
register	ScreenInfo	*info;
{
	register	int		state;
	register	int		flag;
				Point	where;

	state=0;
	SetPort(info->window);
	
	do
	{	flag=GetMouseTrackEvent(&where);
		if(state != (PtInRect(where,&info->window->portRect)))
		{	state = !state;
#ifdef DONT_USE_ASM
#else
			HILITEMODE;
#endif
			InvertRect(&info->window->portRect);
		}
	}	while(flag);
	
	if(state)
	{
#ifdef DONT_USE_ASM
#else
	HILITEMODE;
#endif
		InvertRect(&info->window->portRect);
	}
	
	if(state)	return info;
	else		return 0;
}
ScreenInfo	*FindWindowInfo(window)
WindowPtr	window;
{
	register	ScreenInfo	*found;
	register	int			i;

	found=0;
	for(i=0;i<NumScreens;i++)
	{	if(Screens[i].window==window)
			found=&Screens[i];
	}
	return	found;
}

Handle	ScreenSelect()
{
	register	int			done,i;
	register	ScreenInfo	*found;
	register	GDHandle	TheDisplay;
	register	int			ScreenAvailable=1;
	register	int			OldScreenAvailable=1;
				WindowPtr	hitwindow;

	YesPict=(void *)GetResource('PICT',YESPICTID);
	NoPict=(void *)GetResource('PICT',NOPICTID);
	MessageFrame=(*YesPict)->picFrame;
	OffsetRect(&MessageFrame,-MessageFrame.left,-MessageFrame.top);
	
	Screens=(void *)NewPtr(sizeof(ScreenInfo)*MAXSCREENS);
	NumScreens=0;

	CreateScreenWindows();
	CreateOptionsDialog();

	done=NotDone;
	
	do
	{
		if(ScreenAvailable != OldScreenAvailable)
		{	OptionsUpdate(ScreenAvailable);
			OldScreenAvailable = ScreenAvailable;
		}
		
		SystemTask();
		if(	GetNextEvent(everyEvent,&Event))
		{	if(IsDialogEvent(&Event) && Event.what != keyDown)
			{	int			ItemHit;
				DialogPtr	DialogHit;
			
				if(DialogSelect(&Event,&DialogHit,&ItemHit))
				{	done=DoStartupDialog(ItemHit);
				}
			}
			else
			switch(Event.what)
			{	case keyDown:
				case autoKey:
					done=DefaultDone;
					break;
				case mouseDown:
					switch(FindWindow(Event.where,&hitwindow))
					{	case inSysWindow:
							SystemClick(&Event,hitwindow);
							break;
						case inContent:
						case inGrow:
						case inDrag:
						
							found=FindWindowInfo(hitwindow);
							if(found && found->status)
							{	found=Clickety(found);
								if(found)
								{	done= SelectDone;
									TheDisplay=found->device;
								}
							}
							break;
					}
					break;
				case updateEvt:
					SetPort((GrafPtr)Event.message);
					BeginUpdate((GrafPtr)Event.message);
					found=FindWindowInfo((GrafPtr)Event.message);
					if(found)
					{	
#ifdef ORIG_ARASHI
					    found->status= (*(*found->device)->gdPMap)->pixelSize == 8;
#else
					    found->status=1;
#endif
						DrawPicture(found->status?
										YesPict:NoPict,&MessageFrame);
					}
					EndUpdate((GrafPtr)Event.message);
					ScreenAvailable=0;
					for(i=NumScreens-1;i>=0;i--)
					{	ScreenAvailable |= Screens[i].status;
					}
					break;
			}
		}
	}	while(done==NotDone);
		
	switch(done)
	{	case DefaultDone:
			TheDisplay=0;
			for(i=NumScreens-1;i>=0;i--)
			{
#ifdef ORIG_ARASHI
			    Screens[i].status= (*(*Screens[i].device)->gdPMap)->pixelSize == 8;
#else
			    Screens[i].status=1;
#endif
				if(Screens[i].status)
				{	done=SelectDone;
					TheDisplay=Screens[i].device;
				}
			}
			break;
		case QuitDone:
			TheDisplay=0;
			break;
		case SelectDone:
			break;
	}

	CloseOptionsDialog();

	ReleaseResource(YesPict);
	ReleaseResource(NoPict);

	for(i=0;i<NumScreens;i++)
	{	DisposeWindow(Screens[i].window);
	}

	DisposPtr(Screens);

	return	(Handle)TheDisplay;
}
