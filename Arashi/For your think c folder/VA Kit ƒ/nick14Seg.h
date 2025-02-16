/* Last update: 1/9/2023 */

/* NOTE: Should be 1 and -1 but this causes text to be unreadable at small sizes */
#define FIXPLUS 0
#define FIXMINUS 0

/* NOTE: Should be nickm, but doesn't seem to be getting set in right place */
#define COLOR_TO_DRAW DRAWMODETEXT


  /**/
  thePat=DRAWMODEDARK;
  /* horiz bot */
  if(!(code&1)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+dubScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+dubScale);
  }
  /**/
  /* vert right, bot */
  if(!(code&2)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+theScale+FIXPLUS);
  NICK_LINETO(x+theScale,y+dubScale+FIXMINUS);
  }
  /**/
  /* vert right, top */  
  if(!(code&4)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+FIXPLUS);
  NICK_LINETO(x+theScale,y+theScale+FIXMINUS);
  }
  /**/
  /* horiz top */
  if(!(code&8)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y);
  NICK_LINETO(x+theScale+FIXMINUS,y);
  }
  /**/
  /* vert left, top */
  if(!(code&16)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+FIXPLUS);
  NICK_LINETO(x,y+theScale+FIXMINUS);
  }
  /**/
  /* horiz center, left */
  if(!(code&32)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+theScale);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale);
  }
  /**/
  /* top \ */
  if(!(code&64)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+FIXPLUS);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale+FIXMINUS);
  }
  /**/
  /* vert center, top */
  if(!(code&N(7))){
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale,y+FIXPLUS);
  NICK_LINETO(x+halfScale,y+theScale+FIXMINUS);
  }
  /**/
  /* top / */
  if(!(code&N(8))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale+FIXMINUS);
  NICK_LINETO(x+theScale+FIXMINUS,y+FIXPLUS);
  }
  /**/
  /* !horiz center, right */
  if(!(code&N(9))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+theScale);
  }
  /**/
  /* bot \ */
  if(!(code&N(10))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale+FIXPLUS);
  NICK_LINETO(x+theScale+FIXMINUS,y+dubScale+FIXMINUS);
  }
  /**/
  /* vert center, bot */
  if(!(code&N(11))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale,y+theScale+FIXPLUS);
  NICK_LINETO(x+halfScale,y+dubScale+FIXMINUS);
  }
  /**/
  /* bot / */
  if(!(code&N(12))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+dubScale+FIXMINUS);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale+FIXPLUS);
  }
  /**/
  /* vert left, bot */
  if(!(code&N(13))) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+theScale+FIXPLUS);
  NICK_LINETO(x,y+dubScale+FIXMINUS);
  }
  /**/
  
  /**/
  thePat=COLOR_TO_DRAW;
  /* horiz bot */
  if(code&1) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+dubScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+dubScale);
  }
  /**/
  /* vert right, bot */
  if(code&2) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+theScale+FIXPLUS);
  NICK_LINETO(x+theScale,y+dubScale+FIXMINUS);
  }
  /**/
  /* vert right, top */  
  if(code&4) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+theScale,y+FIXPLUS);
  NICK_LINETO(x+theScale,y+theScale+FIXMINUS);
  }
  /**/
  /* horiz top */
  if(code&8) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y);
  NICK_LINETO(x+theScale+FIXMINUS,y);
  }
  /**/
  /* vert left, top */
  if(code&16) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+FIXPLUS);
  NICK_LINETO(x,y+theScale+FIXMINUS);
  }
  /**/
  /* horiz center, left */
  if(code&32) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+theScale);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale);
  }
  /**/
  /* top \ */
  if(code&64) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+FIXPLUS);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale+FIXMINUS);
  }
  /**/
  /* vert center, top */
  if(code&N(7)){
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale,y+FIXPLUS);
  NICK_LINETO(x+halfScale,y+theScale+FIXMINUS);
  }
  /**/
  /* top / */
  if(code&N(8)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale+FIXMINUS);
  NICK_LINETO(x+theScale+FIXMINUS,y+FIXPLUS);
  }
  /**/
  /* !horiz center, right */
  if(code&N(9)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale);
  NICK_LINETO(x+theScale+FIXMINUS,y+theScale);
  }
  /**/
  /* bot \ */
  if(code&N(10)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale+FIXPLUS,y+theScale+FIXPLUS);
  NICK_LINETO(x+theScale+FIXMINUS,y+dubScale+FIXMINUS);
  }
  /**/
  /* vert center, bot */
  if(code&N(11)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+halfScale,y+theScale+FIXPLUS);
  NICK_LINETO(x+halfScale,y+dubScale+FIXMINUS);
  }
  /**/
  /* bot / */
  if(code&N(12)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x+FIXPLUS,y+dubScale+FIXMINUS);
  NICK_LINETO(x+halfScale+FIXMINUS,y+theScale+FIXPLUS);
  }
  /**/
  /* vert left, bot */
  if(code&N(13)) {
  NICK_SET_MODE(thePat);
  NICK_MOVETO(x,y+theScale+FIXPLUS);
  NICK_LINETO(x,y+dubScale+FIXMINUS);
  }
  /**/
  