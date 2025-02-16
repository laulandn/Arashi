/*/
     Project Arashi: Numbers.h
     Major release: Version 1.1d2, 9/5/95

     Last modification: Thursday, October 13, 1994, 16:18
     Created: Sunday, July 25, 1993, 18:48

     Copyright � 1993-1994, Juri Munkki
/*/

#pragma once

#ifndef __NUMBERS__
#define __NUMBERS__

#include "cplusminusutil.h"

#ifdef NO_PRECOMPILED_HEADERS
#include <Types.h>
#endif

typedef enum { kSNaN, kQNaN, kInfinite, kZero, kNormalNum, kDenormalNum } NumberClass;

double_t		StringToLongDouble(StringPtr pstr);
NumberClass		FindNumClass(double_t n);
double_t		MakeNaN(short n);
void			SetRoundToNearest(void);
#endif
