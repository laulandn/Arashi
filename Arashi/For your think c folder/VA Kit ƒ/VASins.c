/*/
     Project Arashi: VASins.c
     Major release: Version 1.1.1, 3/17/95

     Last modification: Sunday, June 26, 1994, 2:23
     Created: Sunday, February 12, 1989, 22:47

     Copyright � 1989-1994, Juri Munkki
/*/

#define	_VASINS_
#include "VA.h"
#include "VAInternal.h"

#define PI 3.1415926535

#undef	_ERRORCHECK_
#define	_NOERRORCHECK_
#include <Math.h>

void	VAInitSins()
{
	register	int		a;
	
	for(a=0;a<ANGLES;a++)
	{	Sins[a]=sin(a*2*PI/ANGLES)*256;
		Cosins[a]=cos(a*2*PI/ANGLES)*256;
	}
}
