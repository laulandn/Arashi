

#ifdef NICK_256_NOT_1
  addr=VA.quickrow[y]+x;
  *addr=1;
#else
  addr=VA.quickrow[y];
  /*if(x<0) return;
  if(y<0) return;*/
  addr+=(x/8);
  draw=0x80>>(x%8);
  *addr=(*addr)&(~draw);
#endif