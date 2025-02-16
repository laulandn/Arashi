/*/
     Project Arashi: NumbersInternal.h
     Major release: Version 1.1d2, 9/5/95

     Last modification: Friday, July 14, 1995, 0:49
     Created: Thursday, October 13, 1994, 16:00

     Copyright � 1994-1995, Juri Munkki
/*/

#pragma once
#ifndef __NUMBERSINTERNAL__
#define __NUMBERSINTERNAL__

#ifdef powerc
	#include <fenv.h>
	#include <fp.h>
#else
	#include <SANE.h>
	#define decimal		Decimal
	#ifdef __MWERKS__
	#define	decform	DecForm
	#endif	
	#ifndef double_t
		#define double_t	long double
	#endif
#endif
void			NumberToDecimalRecord(	double_t	 num,
										decimal	*decimalRecord,
										short 	howManyDecimals);

#include "Numbers.h"
#endif
