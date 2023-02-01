/* Last update: 1/2/2023 */

/*/
     Project Arashi: VA.h
     Major release: Version 1.1.1, 3/17/95

     Last modification: Sunday, July 18, 1993, 19:24
     Created: Sunday, February 5, 1989, 17:24

     Copyright © 1989-1993, Juri Munkki
/*/


#include <Quickdraw.h>


/* Uncomment for All orignal code */
/*#define ORIG_ARASHI 1 */

/* Uncomment to use "new" drawing engine as opposed to QuickDraw */
#define NICK_NOT_QUICKDRAW 1

/* Uncomment to use 8 bit instead of 1 bit pixels in"new" drawing engine */
/*#define NICK_256_NOT_1*/


/* Uncomment for "new" drawing engine to draw non-solid lines */
#define NICK_LINES_DOTTED 1
#define NICK_STATICS_DOTTED 1

/* Uncomment for "new" drawing engine to skip every other pixel/spot */
#define NICK_SKIP_PIXELS 1
#define NICK_SKIP_SPOTS 1


#define	NUMDISPLISTS		(3)

#define	ANGLES				120
#define	NUMCOLORS			10		/*	Currently 10 colors (3 background+7 animated)	*/

#define	MAXSAVED			1000L
#define MAXSAVEDPIX			1500L
#define	DEFAULT_FRAMESPEED	3
#define	QD32COMPATIBLE		0x0101

#define BGC					255
#define	BG2					(255-64)
#define	BG1					(255-128)

#define	VAPosRandom()		((unsigned int)VARandom())
#define	FastPosRandom()		((unsigned int)FastRandom())


#ifdef NICK_NOT_QUICKDRAW
/* For "new" drawing engine */
#define DRAWMODEDARK 0x255
#define DRAWMODELIGHT 0
#define DRAWMODETEXT DRAWMODELIGHT
#define NICK_SET_MODE(m) nickm=m
#define NICK_SET_DARK()  nickm=DRAWMODEDARK
#define NICK_SET_LIGHT()  nickm=DRAWMODELIGHT
#define NICK_MOVETO(x,y)  nickx=x;nicky=y;
#define NICK_DRAW(x,y)  nickDraw(x,y)
#define NICK_LINETO(x,y)  nickDrawLine(nickx,nicky,x,y);
#define NICK_DRAWLINE(x,y,w,z)  nickDrawLine(x,y,w,z)
#define NICK_PAINTRECT(r) nickPaintRect(r)
#define NICK_PAINTFULLSCREEN() nickPaintFullScreen()
#else
/* For using QuickDraw */
#define DRAWMODEDARK srcCopy
#define DRAWMODELIGHT srcBic
#define DRAWMODETEXT srcBic
#define NICK_SET_MODE(m) PenMode(m)
#define NICK_SET_DARK()  PenMode(DRAWMODEDARK)
#define NICK_SET_LIGHT()  PenMode(DRAWMODELIGHT)
#define NICK_MOVETO(x,y)  MoveTo(x,y);
#define NICK_DRAW(x,y)  MoveTo(x,y); LineTo(x,y)
#define NICK_LINETO(x,y)  LineTo(x,y)
#define NICK_DRAWLINE(x,y,w,z)  MoveTo(x,y); LineTo(w,z)
#define NICK_PAINTRECT(r) PaintRect(r)
#define NICK_PAINTFULLSCREEN() nickPaintFullScreen()
#endif


typedef	struct
{
	WindowPtr		window;
	int				monochrome;
#ifdef ORIG_ARASHI
	Handle			palette;
#endif
	Handle			device;
	int				refnum;

	Ptr				base;
	int				row;
	Ptr				*quickrow;

	Rect			frame;
	Rect			DisplayFrame;

	long			offset;
	unsigned int	color;
	unsigned int	field;
	unsigned int	segmscale;
	int				curbuffer;	/*	Buffer to draw into.			*/
	int				visbuffer;	/*	Visible frame buffer number.	*/

	Rect			*lines[NUMDISPLISTS];
	int				*linecolors[NUMDISPLISTS];
	int				numlines[NUMDISPLISTS];
	
	long			*pix[NUMDISPLISTS];
	short			*pixx[NUMDISPLISTS];  /* Added x coord buffer */
	short			*pixy[NUMDISPLISTS];  /* Added y coord buffer */
	int				*pixcolors[NUMDISPLISTS];
	int				numpix[NUMDISPLISTS];
	
	long			*spots[NUMDISPLISTS];
	short			*spotsx[NUMDISPLISTS];  /* Added x coord buffer */
	short			*spotsy[NUMDISPLISTS];  /* Added y coord buffer */
	int				*spotcolors[NUMDISPLISTS];
	int				numspots[NUMDISPLISTS];

	unsigned long	ticker;
	int				FrameSpeed;
	int				FrameCounter;
	int				SkipFrames;
	int				Late;
	int				SkipCounter;
	int				CurrentX;
	int				CurrentY;

}	VAGlobalsRecord;


#define	VAMoveTo(x,y) {	VA.CurrentX=(x); VA.CurrentY=(y); }
#define	VApalette	((PaletteHandle)VA.palette)
#ifdef VECTOR_ANIMATION_MAIN
		VAGlobalsRecord		VA;
		int					Sins[ANGLES];
		int					Cosins[ANGLES];
		long				VARandSeed;
#else
extern	VAGlobalsRecord		VA;
extern	int					Sins[];
extern	int					Cosins[];
extern	long				VARandSeed;
#endif

void VASetColors(Handle theColors);
Handle VAGetColors();
void VAEraseBuffer();
void VALine(int x1, int y1, int x2, int y2);
void VALineTo(int x, int y);
void VASafeLineTo(int x, int y);
void VAPixel(int,int);
void VASafePixel(int x, int y);
void VASpot(int,int);
void VASafeSpot(int,int);
void VADrawNumber(long num, int x, int y);
void VADrawPadNumber(long num, int x, int y, int width);
void VAExplosion(int x, int y, int size, int color);
void VAStaticLine(int,int,int,int);
void VAStaticLineTo(int,int);
void VAStep(void);
void VAClose(void);
Handle	ScreenSelect();
int	 VAClip(Rect *ptrec);
void VADrawText(char *,long,long);
void *VAColorToQD(int);
int VARandom(void);
void VACatchUp(void);
int FastRandom(void);
void VAInitFractalLines();
void VACloseFractalLines();
void VAFractalLine(int x1,int y1,int x2,int y2,int factor,int level);
void VARestoreColors();


#ifdef NICK_NOT_QUICKDRAW
/* For "new" drawing engine */
extern int nickm;
extern int nickx,nicky;
void nickSetMode(int m);
void nickDraw(int x,int y);
void nickDrawLine(int x,int y,int w,int z);
void nickPaintRect(Rect *r);
void nickPaintFullScreen();
#endif
