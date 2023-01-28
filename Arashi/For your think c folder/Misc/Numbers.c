/*/
     Project Arashi: Numbers.c
     Major release: Version 1.1d2, 9/5/95

     Last modification: Friday, July 14, 1995, 0:49
     Created: Sunday, July 25, 1993, 18:48

     Copyright � 1993-1995, Juri Munkki
/*/

/*
**	Some floating point number conversion utilies.
*/
#include "cplusminusutil.h"
#include "NumbersInternal.h"
#include "LexStuff.h"

#ifdef NO_PRECOMPILED_HEADERS
#include <Memory.h>
#include <TextUtils.h>
#endif

double_t	StringToLongDouble(
	StringPtr	pstr)
{
#ifdef __cplusplus
	double_t	result;
	decimal		d;
	char		tempString[256];
	
	
	BlockMoveData(pstr + 1, tempString, pstr[0]);	//<fp.h>
	tempString[pstr[0]] = '\0';

	if(MatchDouble((StringPtr) tempString, &result) == 0)
	{	result = MakeNaN(255);
	}
	
	return result;
#else
	#if !__option(mc68881) && __option(native_fp)
		return str2num(pstr);
	#else
		extended	temp;
		double_t	result;
		
		temp = str2num(pstr);
		x80tox96(&temp, &result);
		return result;
	#endif
#endif
}

NumberClass	FindNumClass(
	double_t	n)
{
#ifdef powerc
	return (NumberClass) fpclassify(n);
#else
	#ifdef __MWERKS__
		extended80	temp;
		NumClass	theClass;
		
		x96tox80((extended96 *)&n, &temp);
		ClassExtended(&temp, &theClass);

		return (NumberClass) theClass;
	#else
	#if !__option(mc68881) && __option(native_fp)
		return (NumberClass) classextended(n);
	#else
		extended	temp;
		
		x96tox80(&n, &temp);
		return (NumberClass) classextended(temp);
	#endif
	#endif
#endif
}

double_t	MakeNaN(
	short	n)
{
#ifdef powerc
	char	temp[32];
	
	NumToString((long) n, (StringPtr) temp);
	temp[temp[0] +1] = '\0';
	return nanl(temp + 1);	// fp.h
	
#else
	#if __MWERKS__
		extended80	temp;
		double_t	result;
		
		temp = NAN(n);
		x80tox96(&temp, (extended96 *)&result);
		return result;
	#else
	#if !__option(mc68881) && __option(native_fp)
		return nan(n);
	#else
		extended	temp;
		double_t	result;
		
		temp = nan(n);
		x80tox96(&temp, &result);
		return result;
	#endif
	#endif
#endif
}

void	NumberToDecimalRecord(
	double_t		number,
	decimal			*decimalRecord,
	short			howManyDecimals)
{
	decform		myDecForm;
	
	myDecForm.style = 1;
	myDecForm.digits = howManyDecimals;
	decimalRecord->exp = 0;

#ifdef powerc
	num2dec(&myDecForm, number, decimalRecord);
#else
	#if __MWERKS__
	{
		extended80	temp;
	
		x96tox80((extended96 *)&number, &temp);
		Num2Dec(&myDecForm, &temp, decimalRecord);
	}
	#else
	#if !__option(mc68881) && __option(native_fp)
		num2dec(&myDecForm,number,decimalRecord);
	#else
	{
		extended	temp;
	
		x96tox80(&number, &temp);
		num2dec(&myDecForm, temp, decimalRecord);
	}
	#endif
	#endif
#endif
}

void	SetRoundToNearest(void)
{
#ifdef powerc
	fesetround(FE_TONEAREST);	//	fenv.h
#else
#ifdef __MWERKS__
	SetRound(ToNearest);		//	<SANE.h> types.h
#else
	setround(TONEAREST);		//	<SANE.h> types.h
#endif
#endif
}
