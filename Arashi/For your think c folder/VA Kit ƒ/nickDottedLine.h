/* Last update: 1/1/2023 */

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
    /* TODO: Change to only draw every other/few pixels in line */
    if(i&DOT_PATTERN) {
#include "nickDrawPixel.h"
    }
    while(err>=0) {
      if(swap) x+=s1; else y+=s2;
      err-=2*deltax;
    }
    if(swap) y+=s2; else x+=s1;
    err+=2*deltay;
  }
