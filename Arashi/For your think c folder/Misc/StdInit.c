/*/
     Project Arashi: StdInit.c
     Major release: Version 1.1d2, 9/5/95

     Last modification: Monday, April 3, 1995, 22:58
     Created: Thursday, April 23, 1987, 17:38

     Copyright � 1987-1995, Juri Munkki
/*/

#include <Quickdraw.h>
#include <Dialogs.h>
#include <LowMem.h>


#define	STACKSPACE	32768L

void	DoInits();

void	DoInits()
{
#ifdef DefltStack
	SetApplLimit(GetApplLimit() - (STACKSPACE - DefltStack));
	InitGraf(&thePort);
#else
	SetApplLimit(GetApplLimit() - (STACKSPACE - LMGetDefltStack()));
	InitGraf(&qd.thePort);
#endif
	InitCursor();
	InitFonts();
	InitWindows();
	InitMenus();
	TEInit();
	InitDialogs(0L);
	InitCursor();
	MaxApplZone();
}

void	DoInitsStackSize(
	long	stackSize)
{
#ifdef DefltStack
	SetApplLimit(GetApplLimit() - (stackSize - DefltStack));
	InitGraf(&thePort);
#else
	SetApplLimit(GetApplLimit() - (stackSize - LMGetDefltStack()));
	InitGraf(&qd.thePort);
#endif

	InitCursor();
	InitFonts();
	InitWindows();
	InitMenus();
	TEInit();
	InitDialogs(0L);
	InitCursor();
	MaxApplZone();
}

