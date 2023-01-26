

#ifdef NICK_256_NOT_1
  addr=VA.quickrow[y]+x;
  if(nickm) *addr=255; else *addr=0;
#else
  addr=VA.quickrow[y];
  /*if(x<0) return;
  if(y<0) return;*/
  addr+=(x/8);
  draw=0x80>>(x%8);
  if(nickm) *addr=((*addr)&(~draw))|draw;
  else *addr=(*addr)&(~draw);
#endif