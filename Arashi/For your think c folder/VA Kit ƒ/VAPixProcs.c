/* Last update: 1/2/2023 */

/*/
     Project Arashi: VAPixProcs.c
     Major release: Version 1.1.1, 3/17/95

     Last modification: Wednesday, September 9, 1992, 21:42
     Created: Thursday, February 9, 1989, 21:21

     Copyright © 1989-1992, Juri Munkki
/*/

#include "VA.h"
#include "VAInternal.h"


#ifdef NICK_NOT_QUICKDRAW
int nickx,nicky,nickm;
#endif


#ifdef NICK_NOT_QUICKDRAW
void nickDraw(int x,int y)
{
  char draw;
  char *addr;
#include "nickWritePixel.h"
}
#endif


#ifdef NICK_NOT_QUICKDRAW
void nickDrawLine(int x1, int y1, int x2, int y2)
{
  unsigned int x,y;
  int hx,hy;
  int deltax,deltay,temp,err,i,swap,s1,s2;
  char draw,*addr;
  /*
  x=x1;  y=y1;
  hx=x2-x1;
  hy=y2-y1;
  if(hx<0) deltax=-hx; else deltax=hx;
  if(hy<0) deltay=-hy; else deltay=hy;
  if((x2-x1)<0) s1= -1; else s1=1;
  if((y2-y1)<0) s2= -1; else s2=1;
  if(deltay>deltax) {
    temp=deltax;  deltax=deltay;  deltay=temp;  swap=1;
  }
  else swap=0;
  err=2*deltay-deltax;
  for(i=1;i<=deltax;i++) {
#ifdef NICK_LINES_DOTTED
    if(i&1) {
#include "nickWritePixel.h"
    }
#else
#include "nickWritePixel.h"
#endif
    while(err>=0) {
      if(swap) x+=s1; else y+=s2;
      err-=2*deltax;
    }
    if(swap) y+=s2; else x+=s1;
    err+=2*deltay;
  }
*/
#include "nickWriteLine.h"
}
#endif


#ifdef NICK_NOT_QUICKDRAW
void nickPaintRect(Rect *r)
{
  unsigned int x,y;
  int hx,hy;
  int deltax,deltay,temp,err,i,swap,s1,s2;
  char draw,*addr;
  int x1,y1,x2,y2;
  register int tt;
  for(tt=r->top;tt<r->bottom;tt++) 
  {
    /*nickDrawLine(r->left,tt,r->right,tt);*/
#ifdef NICK_NOT_QUICKDRAW
    x1=r->left; y1=tt;
    x2=r->right; y2=tt;
/*#include "nickWriteLine.h"*/
    y=tt;
    for(x=r->left;x<r->right;x++) {
#include "nickWritePixel.h"
    }
#else
    NICK_MOVETO(r->left,tt);
    NICK_LINETO(r->right,tt]);
#endif
  }
  /*PenMode(srcCopy);
  PaintRect(r);*/
}
#endif


#ifdef NICK_NOT_QUICKDRAW
void nickPaintFullScreen()
{
#ifdef NICK_NOT_QUICKDRAW
  char b;
  char *addr;
  unsigned int x,y;
  if(nickm) b=0xff; else b=0;
  for(y=0;y<VA.frame.bottom;y++) {
    addr=VA.quickrow[y];
    /*memset(addr,VA.row,0);*/
    for(x=0;x<VA.row;x++) {
      addr+=1;
      *addr=b;
    }
  }
#else
  NICK_PAINTRECT(&VA.frame);
#endif
}
#endif


void	VAPixel(x,y)
register	int		x,y;
{
	register	long	*p;

	if(VA.numpix[VA.curbuffer]<MAXSAVEDPIX)
	{	VA.pixcolors[VA.curbuffer][VA.numpix[VA.curbuffer]]=VA.color;
	    VA.pixx[VA.curbuffer][VA.numpix[VA.curbuffer]]=x; VA.pixy[VA.curbuffer][VA.numpix[VA.curbuffer]]=y;
		p=VA.pix[VA.curbuffer]+VA.numpix[VA.curbuffer]++;
		
#ifdef ORIG_ARASHI
	asm	{
		move.l	VA.quickrow,A1		;	Pointer to base address table
		move.l	(0,A1,y.w*4),A0		;	Get pointer to row base
		add.w	x,A0				;	Add x to base address
		move.l	A0,(p)
		}
#else
#endif
	}
}


void	VASafePixel(x,y)
register	int	x,y;
{
	register	long	*p;

	if(VA.numpix[VA.curbuffer]<MAXSAVEDPIX)
	{	if(x<VA.frame.left)	return;
		if(x>=VA.frame.right)	return;
		if(y<VA.frame.top)	return;
		if(y>=VA.frame.bottom)return;
		{	VA.pixcolors[VA.curbuffer][VA.numpix[VA.curbuffer]]=VA.color;
	        VA.pixx[VA.curbuffer][VA.numpix[VA.curbuffer]]=x; VA.pixy[VA.curbuffer][VA.numpix[VA.curbuffer]]=y;
			p=VA.pix[VA.curbuffer]+VA.numpix[VA.curbuffer]++;
			
#ifdef ORIG_ARASHI
		asm	{
			move.l	VA.quickrow,A1		;	Pointer to base address table
			move.l	(0,A1,y.w*4),A0		;	Get pointer to row base
			add.w	x,A0				;	Add x to base address
			move.l	A0,(p)
			}
#else
#endif
		}
	}
}


void	VAPlotPixels(count,pixels,colors,bnum)
int		count;
long	*pixels;
int		*colors;
int		bnum;
{
#ifdef ORIG_ARASHI
asm	{
		movem.l	D5/A2,-(sp)
		move.w	count,D2
		subq.w	#1,D2
		bmi.s	@nopix

		move.l	pixels,A2
		move.l	colors,A1
		move.l	VA.offset,D0
		move.w	VA.field,D5	;	Field width to D5
@loop
		move.l	(A2)+,A0	;	Read next address
		move.w	(A1)+,D1	;	Read next VA.color
		dc.l	0xEFD01825	;	BFINS	BitValue,(RowBase){OffSet:4}
		dbra	D2,@loop
		
@nopix
		movem.l	(sp)+,D5/A2
	}
#else
  unsigned int t;
  unsigned short x,y;
  char draw,*addr;
#ifdef NICK_NOT_QUICKDRAW
#else
  NICK_SET_LIGHT();
#endif
  for(t=0;t<count;t++) {
    x=VA.pixx[bnum][t]; y=VA.pixy[bnum][t];
#ifdef NICK_NOT_QUICKDRAW
#ifdef NICK_SKIP_PIXELS
    if(t&1) {
#include "nickDrawPixel.h"
    }
#else
#include "nickDrawPixel.h"
#endif
#else
    NICK_MOVETO(x,y);
    NICK_LINETO(x,y);
#endif
  }
#endif
}

void	VAErasePixels(count,pixels,bnum)
int		count;
long	*pixels;
int		bnum;
{
#ifdef ORIG_ARASHI
asm	{
		move.l	D5,-(sp)
		move.w	count,D2
		subq.w	#1,D2
		bmi.s	@nopix

		move.l	pixels,A1
		move.l	VA.offset,D0
		move.w	VA.field,D1	;	Field width to D5
@loop
		move.l	(A1)+,A0	;	Read next address
		dc.l	0xEED01821	;	BFINS	BitValue,(RowBase){OffSet:4}
		dbra	D2,@loop
		
@nopix
		move.l	(sp)+,D5
	}
#else
  unsigned int t;
  unsigned short x,y;
  char draw,*addr;
#ifdef NICK_NOT_QUICKDRAW
#else
  NICK_SET_DARK();
#endif
  for(t=0;t<count;t++) {
    x=VA.pixx[bnum][t]; y=VA.pixy[bnum][t];
#ifdef NICK_NOT_QUICKDRAW
#ifdef NICK_SKIP_PIXELS
    if(t&1) {
#include "nickErasePixel.h"
    }
#else
#include "nickErasePixel.h"
#endif
#else
    NICK_MOVETO(x,y);
    NICK_LINETO(x,y);
#endif
  }
#endif
}

void	VASpot(x,y)
register	int	x,y;
{
	register	long	*p;

	y--;
	if(VA.numspots[VA.curbuffer]<MAXSAVEDPIX)
	{	VA.spotcolors[VA.curbuffer][VA.numspots[VA.curbuffer]]=VA.color;
	    VA.spotsx[VA.curbuffer][VA.numspots[VA.curbuffer]]=x; VA.spotsy[VA.curbuffer][VA.numspots[VA.curbuffer]]=y;
		p=VA.spots[VA.curbuffer]+VA.numspots[VA.curbuffer]++;
		
#ifdef ORIG_ARASHI
	asm	{
		move.l	VA.quickrow,A1		;	Pointer to base address table
		move.l	(0,A1,y.w*4),A0		;	Get pointer to row base
		add.w	x,A0				;	Add x to base address
		move.l	A0,(p)
		}
#else
#endif
	}
}

void	VASafeSpot(x,y)
register	int	x,y;
{
	register	long	*p;

	y--;
	if(VA.numspots[VA.curbuffer]<MAXSAVEDPIX)
	{	if(x<=VA.frame.left)		return;
		if(x>=VA.frame.right-2)	return;
		if(y<=VA.frame.top)		return;
		if(y>=VA.frame.bottom-2)	return;
		{	VA.spotcolors[VA.curbuffer][VA.numspots[VA.curbuffer]]=VA.color;
	        VA.spotsx[VA.curbuffer][VA.numspots[VA.curbuffer]]=x; VA.spotsy[VA.curbuffer][VA.numspots[VA.curbuffer]]=y;
			p=VA.spots[VA.curbuffer]+VA.numspots[VA.curbuffer]++;
			
#ifdef ORIG_ARASHI
		asm	{
			move.l	VA.quickrow,A1		;	Pointer to base address table
			move.l	(0,A1,y.w*4),A0		;	Get pointer to row base
			add.w	x,A0				;	Add x to base address
			move.l	A0,(p)
			}
#else
#endif
		}
	}
}


void	VAPlotSpots(count,pixels,colors,bnum)
int		count;
long 	*pixels;
int		*colors;
int		bnum;
{
#ifdef ORIG_ARASHI
asm	{
		movem.l	D3-D5/A2,-(sp)

		move.w	count,D2
		subq.w	#1,D2
		bmi.s	@nopix

		move.w	VA.row,D4
		subq.w	#1,D4
		moveq.l	#8,D5
		move.l	pixels,A2
		move.l	colors,A1
		move.l	VA.offset,D0
		move.w	VA.field,D3	;	Field width to D5

@loop
		move.w	(A1)+,D1	;	Read next VA.color
		move.l	(A2)+,A0	;	Read next address
		dc.l	0xEFD01823	;	BFINS	VA.color,(RowBase){OffSet:field}
		add.w	D4,A0
		dc.l	0xEFD01823	;	BFINS	VA.color,(RowBase){OffSet:field}
		add.l	D5,D0
		dc.l	0xEFD01823	;	BFINS	VA.color,(RowBase){OffSet:field}
		add.l	D5,D0
		dc.l	0xEFD01823	;	BFINS	VA.color,(RowBase){OffSet:field}
		add.w	D4,A0
		dc.l	0xEFD01823	;	BFINS	VA.color,(RowBase){OffSet:field}
		sub.l	D5,D0
		sub.l	D5,D0
		dbra	D2,@loop
		
@nopix
		movem.l	(sp)+,D3-D5/A2
	}
#else
  unsigned int t;
  unsigned short x,y;
  char draw,*addr;
#ifdef NICK_NOT_QUICKDRAW
#else
  NICK_SET_LIGHT();
#endif
  for(t=0;t<count;t++) {
    x=VA.spotsx[bnum][t]; y=VA.spotsy[bnum][t];
#ifdef NICK_NOT_QUICKDRAW
#ifdef NICK_SKIP_SPOTS
    if(t&1) {
#include "nickDrawPixel.h"
    }
#else
#include "nickDrawPixel.h"
#endif
#else
    NICK_MOVETO(x,y);
    NICK_LINETO(x+1,y+1);
#endif
  }
#endif
}

void	VAEraseSpots(count,pixels,bnum)
int		count;
long	*pixels;
int		bnum;
{
#ifdef ORIG_ARASHI
asm	{
		movem.l	D3-D5,-(sp)
		move.w	VA.row,D4
		subq.w	#1,D4
		moveq.l	#8,D5
		move.w	count,D2
		move.l	pixels,A1
		move.l	VA.offset,D0
		move.w	VA.field,D3	;	Field width to D5
		subq.w	#1,D2
		bmi.s	@nopix
@loop
		move.l	(A1)+,A0	;	Read next address
		dc.l	0xEED00823	;	BFTST	(RowBase){OffSet:field}
		add.w	D4,A0
		dc.l	0xEED00823	;	BFTST	(RowBase){OffSet:field}
		add.l	D5,D0
		dc.l	0xEED00823	;	BFTST	(RowBase){OffSet:field}
		add.l	D5,D0
		dc.l	0xEED00823	;	BFTST	(RowBase){OffSet:field}
		add.w	D4,A0
		dc.l	0xEED00823	;	BFTST	(RowBase){OffSet:field}
		sub.l	D5,D0
		sub.l	D5,D0
		dbra	D2,@loop
		
@nopix
		movem.l	(sp)+,D3-D5
	}
#else
  unsigned int t;
  unsigned short x,y;
  char draw,*addr;
#ifdef NICK_NOT_QUICKDRAW
#else
  NICK_SET_DARK();
#endif
  for(t=0;t<count;t++) {
    x=VA.spotsx[bnum][t]; y=VA.spotsy[bnum][t];
#ifdef NICK_NOT_QUICKDRAW
#ifdef NICK_SKIP_SPOTS
    if(t&1) {
#include "nickErasePixel.h"
    }
#else
#include "nickErasePixel.h"
#endif
#else
    NICK_MOVETO(x,y);
    NICK_LINETO(x+1,y+1);
#endif
  }
#endif
}