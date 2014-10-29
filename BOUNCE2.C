#include<stdio.h>
#include<graphics.h>

#include<conio.h>

#include<dos.h>

#include<math.h>

 

void drawBall(struct ball *b, int color);

 

struct ball{

int x, y;

int dx, dy;

int radius;

};

 

void main()

{

  int gd=0, gm=VGAHI;

  int i;

  struct ball b[10];

  initgraph(&gd, &gm,"c:\\tc\\bgi\\");

 

  for(i=1;i<=15;i++){

 b[i].radius = rand()%20;

 b[i].x=rand()%getmaxx();

 b[i].y=rand()%getmaxy();

 b[i].dx=2;

 b[i].dy=4;

  }

 

  while(!kbhit())

  {

 delay(5);

 cleardevice();

 for(i=1;i<=15;i++)

 drawBall(&b[i],i);

  }

closegraph();

 

}

 

void drawBall(struct ball *b, int color){

 setfillstyle(1,color);

 setcolor(color);

 fillellipse(b->x, b->y, b->radius, b->radius);

 if(b->x+b->radius > getmaxx() || b->x-b->radius<0)

 b->dx = -b->dx;

if(b->y+b->radius > getmaxy() || b->y-b->radius<0)

 b->dy = -b->dy;

 

 b->x+=b->dx;

 b->y+=b->dy;

}
