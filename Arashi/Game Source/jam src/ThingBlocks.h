/*/
     Project Arashi: ThingBlocks.h
     Major release: Version 1.1.1, 3/17/95

     Last modification: Wednesday, September 9, 1992, 21:29
     Created: Tuesday, March 10, 1992, 11:08

     Copyright � 1992, Juri Munkki
/*/

typedef	struct
{
	long	thingSize;
	long	clumpSize;
	long	numItems;
	long	logicalSize;
	long	physicalSize;
	char	theStuff[2];
}	ThingBlockHeader,**ThingBlock;


ThingBlock	NewThingBlock(long thingSize);
int			EnlargeThing(ThingBlock tb, long sizeRequested);
void		AddThing(ThingBlock tb, void *theThing);
void		DeleteWithSwap(ThingBlock tb, int index);
