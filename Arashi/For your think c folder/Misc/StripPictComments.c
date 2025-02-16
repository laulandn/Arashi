/*/
     Project Arashi: StripPictComments.c
     Major release: Version 1.1d2, 9/5/95

     Last modification: Thursday, January 13, 1994, 8:08
     Created: Wednesday, December 1, 1993, 20:08

     Copyright � 1993-1994, Juri Munkki
/*/

#include <Quickdraw.h>
#include <Memory.h>
#include <Resources.h>


static
pascal
void	NoComment(
	short	kind,
	short	dataSize,
	Handle	theHandle)
{
#ifdef PRESERVECOMMENTS
	if(kind != kCommentKind)
	{	StdComment(kind, dataSize, theHandle);
	}
#endif
}

void	StripPictComments(
	short	resId)
{
	CGrafPort	tempPort;
	GrafPtr		saved;
	PicHandle	oldPic;
	PicHandle	newPic;
	Rect		bounds;
	long		regSize, picSize;
	short		i;
	CQDProcsPtr	theProcs;
	
	GetPort(&saved);
	
	OpenCPort(&tempPort);
	SetPort(&tempPort);
	PortSize(0,0);

	theProcs = (CQDProcsPtr) NewPtr(sizeof(CQDProcs));
	SetStdCProcs(theProcs);
	theProcs->commentProc = (void *)NoComment;
	
	tempPort.grafProcs = (void *)theProcs;

	oldPic = GetPicture(resId);
	bounds = (*oldPic)->picFrame;
	
	newPic = OpenPicture(&bounds);
	ClipRect(&bounds);
	DrawPicture(oldPic, &bounds);

	ClosePicture();
	SetPort(saved);
	ClosePort(&tempPort);
	DisposeHandle(theProcs);
	
	picSize = GetHandleSize(newPic);
	SetHandleSize(oldPic, picSize);
	picSize = GetHandleSize(oldPic);
	BlockMove(*newPic, *oldPic, picSize);
	ChangedResource(oldPic);
	WriteResource(oldPic);
	KillPicture(newPic);
	ReleaseResource(oldPic);
}

void	StripAllPictComments()
{
	short	counter;
	Handle	thePic;
	short	theId;
	OSType	theType;
	Str255	theName;
	
	counter = Count1Resources('PICT');
	
	while(counter)
	{
		thePic = Get1IndResource('PICT', counter--);
		GetResInfo(thePic, &theId, &theType, theName);
		StripPictComments(theId);
	}
}
