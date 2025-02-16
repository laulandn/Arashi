/*/
     Project Arashi: LexStuff.h
     Major release: Version 1.1d2, 9/5/95

     Last modification: Thursday, October 13, 1994, 16:56
     Created: Saturday, June 25, 1994, 23:59

     Copyright � 1994, Juri Munkki
/*/

#pragma once

#ifndef __LEXSTUFF__
#define __LEXSTUFF__

#ifdef powerc
#include <fenv.h>
#include <fp.h>
#else
/*#include <SANE.h>*/
#include <sane.h>
#define decimal		Decimal
#ifndef double_t
#define double_t	long double
#endif
#ifndef SIGDIGLEN
#define SIGDIGLEN SigDigLen
#endif
#endif

short MatchLongInt(StringPtr theString, long *n);
short MatchDouble(StringPtr theString, double_t *theNumber);
short MatchWhiteSpace(StringPtr theString);
short MatchLine(StringPtr theString);
short UnmatchWhiteSpace(StringPtr theString);
short MatchWhiteLongInt(StringPtr theString, long *n);
short MatchWhiteDouble(StringPtr theString, double_t *theNumber);
short StringToToken(Handle stringList, StringPtr stringStart, short stringLen);

#endif
