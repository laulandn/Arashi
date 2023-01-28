/*/
     Project Arashi: LexStuff.c
     Major release: Version 1.1d2, 9/5/95

     Last modification: Thursday, August 31, 1995, 1:55
     Created: Saturday, June 25, 1994, 23:50

     Copyright � 1994-1995, Juri Munkki
/*/

#include "LexStuff.h"

short	MatchLongInt(
	StringPtr	theString,
	long		*n)
{
	short	matchCount = 0;
	char	theChar;
	long	theLong = 0;
	Boolean	sign = false;

	theChar = *theString++;

	if(theChar == '-' || theChar == '+')
	{
		sign = theChar == '-';

		matchCount++;
		theChar = *theString++;
	}

	while(theChar >= '0' && theChar <= '9')
	{	theLong = theLong * 10 + theChar - '0';

		matchCount++;
		theChar = *theString++;
	}

	*n = sign ? -theLong : theLong;
	return matchCount;
}

/*
**	Match a floating point number.
**	The input is a null-terminated string. The output
**	tells how many characters could belong to a floating
**	point number.
*/
short	MatchDouble(
	StringPtr	theString,
	double_t	*theNumber)
{
	enum	{	initialState,
				integerPartState,
				decimalPartState,
				exponentMatchState,
				endState	};

	short	matchCount = 0;
	char	theChar;
	short	state = initialState;
	decimal	numRec;
	
	numRec.sig.length = 0;
	numRec.sgn = 0;
	numRec.exp = 0;

	while(state != endState)
	{	theChar = theString[matchCount];
		
		if(theChar == 0)
			state = endState;	//	String ends with null

		switch(state)
		{	case initialState:
				if(	theChar == '+'	||	theChar == '-'	||
					(theChar >= '0' && theChar <= '9'))
				{		if(theChar == '-' || theChar == '+')
						{	numRec.sgn = (theChar == '-');
						}
						else
						{	if(theChar != '0')
								numRec.sig.text[numRec.sig.length++] = theChar;
						}
						matchCount++;
						state = integerPartState; 
				}
#define ALLOWSHORTHAND
#ifdef ALLOWSHORTHAND		//	Are numbers like . and .0 and .e1 and .0e1 valid?
				else if(theChar == '.')
				{	matchCount++;
					state = decimalPartState;
				}
#endif
				else	state = endState;
				break;

			case integerPartState:
				if(theChar >= '0' && theChar <= '9')
				{	matchCount++;
					if(SIGDIGLEN-1 > numRec.sig.length)
					{	if(numRec.sig.length != 0 || theChar != '0')
							numRec.sig.text[numRec.sig.length++] = theChar;
					}
					else
					{	numRec.exp++;
					}

				}
				else if(theChar == 'e' || theChar == 'E')
				{	state = exponentMatchState;
				}
				else if(theChar == '.')
				{	matchCount++;
					state = decimalPartState;
				}
				else	state = endState;
				break;

			case decimalPartState:
				if(theChar >= '0' && theChar <= '9')
				{	matchCount++;
					if(SIGDIGLEN-1 > numRec.sig.length)
					{
						if(numRec.sig.length != 0 || theChar != '0')
						{	numRec.sig.text[numRec.sig.length++] = theChar;
						}
						numRec.exp--;
					}
				}
				else if(theChar == 'e' || theChar == 'E')
				{	state = exponentMatchState;
				}
				else	state = endState;
				break;				

			case exponentMatchState:
				{	long	theExp;
					short	expLength = MatchLongInt(theString+matchCount+1, &theExp);
				
					numRec.exp += theExp;

					if(expLength > 0)
					{	matchCount += expLength+1;
					}
					state = endState;
				}
				break;
		}
	}
	
#ifdef powerc
	*theNumber = dec2num(&numRec);
#else
#ifdef __MWERKS__
	{
		extended80	temp;
		
		Dec2Num(&numRec, &temp);
		x80tox96(&temp, (extended96 *)theNumber);
	}

#else
#if !__option(mc68881) && __option(native_fp)
	*theNumber = dec2num(&numRec);
#else
	{
		extended	temp;
		
		temp = dec2num(&numRec);
		x80tox96(&temp, theNumber);
	}
#endif
#endif
#endif
	return matchCount;
}

short	MatchWhiteSpace(
	StringPtr	theString)
{
	short	matchCount = 0;
	char	theChar;

	theChar = theString[matchCount];
	
	while(theChar == ' ' || theChar == 9 /* tab */ || theChar == 13 /* return */)
	{	matchCount++;
		theChar = theString[matchCount];
	}
	
	return matchCount;
}

short	MatchLine(
	StringPtr	theString)
{
	short	matchCount = 0;
	char	theChar;

	theChar = theString[matchCount];
	
	while(theChar != 13 /* return */ && theChar != 10 /* NewLine */)
	{	matchCount++;
		theChar = theString[matchCount];
	}
	
	do
	{	matchCount++;
		theChar = theString[matchCount];
	} while(theChar == 13 /* return */ || theChar == 10 /* NewLine */);
	
	return matchCount;
}

short	UnmatchWhiteSpace(
	StringPtr	theString)
{
	short	matchCount = 0;
	char	theChar;

	theString--;
	theChar = theString[matchCount];
	
	while(theChar == ' ' || theChar == 9 /* tab */ || theChar == 13 /* return */)
	{	matchCount--;
		theChar = theString[matchCount];
	}
	
	return matchCount;
}

short	MatchWhiteLongInt(
	StringPtr	theString,
	long		*n)
{
	short	whiteMatch;
	short	matchCount;
	
	whiteMatch = MatchWhiteSpace(theString);
	matchCount = MatchLongInt(theString+whiteMatch, n);
	
	return matchCount ? whiteMatch+matchCount : 0;
}

short	MatchWhiteDouble(
	StringPtr	theString,
	double_t	*theNumber)
{
	short	whiteMatch;
	short	matchCount;
	
	whiteMatch = MatchWhiteSpace(theString);
	matchCount = MatchDouble(theString+whiteMatch, theNumber);
	
	return matchCount ? whiteMatch+matchCount : 0;
}

short	StringToToken(
	Handle		stringList,
	StringPtr	stringStart,
	short		stringLen)
{
	StringPtr	string;
	StringPtr	charp;
	short		tokCount;
	short		ind;
	short		i;
	
	tokCount = *(short *)(*stringList);
	string = ((StringPtr)*stringList)+2;
	
	for(ind = 1;ind <= tokCount; ind++)
	{	if(string[0] == stringLen)
		{	charp = string+1;
		
			for(i=0;i<stringLen;i++)
			{	if(*charp++ != stringStart[i])
				{	break;
				}
			}
			
			if(i==stringLen)
			{	break;
			}
		}
		
		string += string[0] + 1;
	}
	
	return ind;
}