/*/
     Project Arashi: STInterface.c
     Major release: Version 1.1.1, 3/17/95

     Last modification: Tuesday, March 2, 1993, 19:05
     Created: Tuesday, January 8, 1991, 8:38

     Copyright © 1991-1993, Juri Munkki
/*/

#include "VA.h"
#include "STORM.h"
#include "PlayOptions.h"


extern void InitCStars(void);
extern void InitPlayer(void);
extern void InitFuseBalls(void);
extern void InitTankers(void);
extern void InitCracks(void);
extern void InitSpikes(void);
extern void InitShots(void);
extern void InitFlippers(void);
extern void InitPulsars(void);
extern void InitFloatingScores(void);

extern void AllocGrids(void);
extern void AllocParser(void);
extern void AllocSpikers(void);

extern void AllocCStars(void);
extern void AllocPlayer(void);
extern void AllocFuseBalls(void);
extern void AllocTankers(void);
extern void AllocCracks(void);
extern void AllocSpikes(void);
extern void AllocShots(void);
extern void AllocFlippers(void);
extern void AllocPulsars(void);
extern void AllocFloatingScores(void);

extern void UpdateCStars(void);
extern void UpdatePlayer(void);
extern void UpdateFuseBalls(void);
extern void UpdateTankers(void);
extern void UpdateCracks(void);
extern void UpdateSpikes(void);
extern void UpdateShots(void);
extern void UpdateFlippers(void);
extern void UpdatePulsars(void);
extern void UpdateFloatingScores(void);


/*
>>	Called at program startup to allocate storage.
*/
void	STAllocate()
{
	AllocParser();		/*	Allocate & init memory for game compiler.		*/
	AllocCracks();
	AllocGrids();		/*	Allocate memory for grid structures.			*/
	AllocCStars();		/*	Allocate memory for center star structures.		*/
	AllocFlippers();	/*	Allocate memory for flippers.					*/
	AllocPulsars();		/*	Allocate memory for pulsars.					*/
	AllocSpikers();		/*	Allocate memory for spikers & spikes & -shots.	*/
	AllocFuseBalls();	/*	Allocate memory for fuseballs.					*/
	AllocTankers();		/*	Allocate memory for tankers.					*/
	AllocFloatingScores(); /* Allocate memory for floating scores (mz)		*/
}
/*
>>	Called at level startup to initialize variables.
*/
void	STInitialize()
{
	InitCStars();
	InitPlayer();
	InitSpikes();
	InitShots();
	InitPlayer();
	InitFlippers();
	InitPulsars();
	InitFuseBalls();
	InitTankers();
	InitCracks();
	InitFloatingScores();	/* mz */
}
/*
>>	Called each time through event/animation loop.
*/
void	STUpdate()
{
	UpdateCStars();

	ThisLevel.edgeCount=0;	/*	Some routines below must update this variable!	*/
	ThisLevel.starCount=0;	/*	Same as above, if you need baby stars.			*/

	UpdatePlayer();
	UpdateFuseBalls(); /* */
	UpdatePulsars();
	UpdateFlippers(); /* */
	UpdateShots();
	UpdateSpikes();
	UpdateTankers();
	UpdateCracks();
	if(PlayOptions->showfscores)
		UpdateFloatingScores();	/* mz */
}
