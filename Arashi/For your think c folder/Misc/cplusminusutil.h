/*/
     Project Arashi: cplusminusutil.h
     Major release: Version 1.1d2, 9/5/95

     Last modification: Friday, July 14, 1995, 0:34
     Created: Thursday, October 13, 1994, 11:46

     Copyright � 1994-1995, Juri Munkki
/*/

#ifndef __CPLUSMINUSUTIL__
#define __CPLUSMINUSUTIL__
#include <stddef.h>
/*
**	Because the disk init package is not used very
**	often, it can be used to determine if MacHeaders
**	has been pre-included.	
*/
#ifndef __DISKINIT__
#define NO_PRECOMPILED_HEADERS
#endif

// for MPW only
#define NO_INHERITED_IN_LANGUAGE_false

#ifdef	NO_INHERITED_IN_LANGUAGE
#define	MAKEINHERIT(superclass)	typedef superclass inherited;
#else
#define	MAKEINHERIT(superclass)
#endif
#endif