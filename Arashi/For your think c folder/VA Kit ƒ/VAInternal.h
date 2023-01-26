/*/
     Project Arashi: VAInternal.h
     Major release: Version 1.1.1, 3/17/95

     Last modification: Wednesday, September 9, 1992, 22:12
     Created: Saturday, September 29, 1990, 20:29

     Copyright � 1990-1992, Juri Munkki
/*/

/*	Internal prototypes for vector animation kit
*/

void VADoFrame(void);
void VACancelFrame(void);
void VAInitPhase2(void);
void VAEraseBufferedLines(int count, Rect *lines);
void VALoadExplosions(void);
void VAInsertExplosions(void);
void VABresenheim(int,int,int,int);
void VADrawBufferedLines(int count, Rect *lines, int *colors);
void VAPlotPixels(int count, long *pixels, int *colors,int bnum);
void VAErasePixels(int count, long *pixels,int bnum);
void VAPlotSpots(int count, long *pixels, int *colors,int bnum);
void VAEraseSpots(int count, long *pixels,int bnum);
void VAInitSins(void);
void VADrawSegments(int x, int y, int code);

#define	QuickTicks	TickCount()
