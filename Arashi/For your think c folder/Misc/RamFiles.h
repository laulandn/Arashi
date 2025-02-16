/*/
     Project Arashi: RamFiles.h
     Major release: Version 1.1d2, 9/5/95

     Last modification: Thursday, October 13, 1994, 12:03
     Created: Friday, October 23, 1992, 15:57

     Copyright � 1992-1994, Juri Munkki
/*/

#include "cplusminusutil.h"

#ifdef NO_PRECOMPILED_HEADERS
#include <Types.h>
#endif


short	IncreaseRamFile(
	Handle	theFile,
	long	*realSize,
	long	*logicalSize,
	long	increase);

short	IncreaseByClump(
	Handle	theFile,
	long	*realSize,
	long	*logicalSize,
	long	increase,
	long	clumpSize);

short	OddIncreaseRamFile(
	Handle	theFile,
	long	*realSize,
	long	*logicalSize,
	long	increase);

short	OddIncreaseByClump(
	Handle	theFile,
	long	*realSize,
	long	*logicalSize,
	long	increase,
	long	clumpSize);

void	PackRamFile(
	Handle	theFile,
	long	*realSize,
	long	*logicalSize);
