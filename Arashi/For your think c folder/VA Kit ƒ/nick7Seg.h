/* Last update: 1/9/2023 */

/* NOTE: Should be 1 and -1 but this causes text to be unreadable at small sizes */
#define FIXPLUS 0
#define FIXMINUS 0

/* NOTE: Should be nickm, but doesn't seem to be getting set in right place */
#define COLOR_TO_DRAW DRAWMODETEXT


  /**/
  /* horiz bot */
  if(code&1) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+dubScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+dubScale);
  /**/
  /* vert right bot */
  if(code&2) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+theScale+FIXPLUS);
  NICK_LINETO(x+theScale,y+dubScale+FIXMINUS);
  /**/
  /* vert right top */  
  if(code&4) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+FIXPLUS);
  NICK_LINETO(x+theScale,y+theScale+FIXMINUS);
  /**/
  /* horiz top */
  if(code&8) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y);
  NICK_LINETO(x+theScale+FIXMINUS,y);
  /**/
  /* vert left bot */
  if(code&32) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+theScale+FIXPLUS);
  NICK_LINETO(x,y+dubScale+FIXMINUS);
  /**/
  /* vert left top */
  if(code&16) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+FIXPLUS);
  NICK_LINETO(x,y+theScale+FIXMINUS);
  /**/
  /* horiz  center */
  if(code&64) thePat=COLOR_TO_DRAW;
  else thePat=DRAWMODEDARK;
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+theScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+theScale);
  /**/
  