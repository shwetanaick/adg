#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
float xa,xb,ya,yb,xc,yc,xd,yd,nx1,nx1,nx2,nx3,nx4,ny1,ny2,ny3,ny4;
void reflection();
void main(int argc,char **argv)
{
int c;
printf("\n\t PROGRAM FOR REFLECTION AND SHEARING");
printf("\nEnter the points\n");
scanf("%f %f %f %f %f %f %f%f",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
printf("\n1.REFLECTION\n2.SHEARING\n3.EXIT");
printf("\nEnter your choice:");
scanf("%d",&c);
switch(c)
{
case 1:
reflection();
break;
case 2:
shear();
break;
}

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,600);
glutInitWindowPosition(100,150);
glutCreateWindow("Triangle");
glClearColor(0.9,0.9,1.0,1.0);
glColor3f(0.0f,0.0f,0.0f);
glClear(GL_COLOR_BUFFER_BIT);

gluOrtho2D(-200,200,-200,200);
glBegin(GL_LINES);
glVertex2i(-200,0);
glVertex2i(200,0);
glEnd();

glBegin(GL_LINES);
glVertex2i(0,-200);
glVertex2i(0,200);
glEnd();
glBegin(GL_QUADS);
glPointSize(3.0);
glVertex2f(xa,ya);
glVertex2f(xb,yb);
glVertex2f(xc,yc);
glVertex2f(xd,yd);
glEnd();
glColor3f(0.3f,0.4f,1.0f);
glPointSize(3.0);
glBegin(GL_QUADS);
glVertex2f(nx1,ny1);
glVertex2f(nx2,ny2);
glVertex2f(nx3,ny3);
glVertex2f(nx4,ny4);
glEnd();
glFlush();
glutMainLoop();
}
void reflection()
{
int k;
printf("\n REFLECTION:");
printf("\n1.REFLECTION WITH RESPECT TO X-AXIS\n2.REFLECTION WITH RESPECT TO Y-AXIS\n3.REFLECTION WITH RESPECT TO ORGIN\n4.REFLECTION WITH RESPECT TO X=Y\n5.REFLECTION WITH RESPECT TO X=-Y");
printf("\nEnter your choice:");
scanf("%d",&k);
switch(k)
{
case 1: 
nx1=xa;
ny1=-ya;
nx2=xb;
ny2=-yb;
nx3=xc;
ny3=-yc;
nx4=xd;
ny4=-yd;
break;
case 2: 
nx1=-xa;
ny1=ya;
nx2=-xb;
ny2=yb;
nx3=-xc;
ny3=yc;
nx4=-xd;
ny4=yd;
break;
case 3: 
nx1=-xa;
ny1=-ya;
nx2=-xb;
ny2=-yb;
nx3=-xc;
ny3=-yc;
nx4=-xd;
ny4=-yd;
break;
case 4: 
nx1=ya;
ny1=xa;
nx2=yb;
ny2=xb;
nx3=yc;
ny3=xc;
nx4=yd;
ny4=xd;
break;
case 5: 
nx1=-ya;
ny1=-xa;
nx2=-yb;
ny2=-xb;
nx3=-yc;
ny3=-xc;
nx4=-yd;
ny4=-xd;
break;
}
}
void shear()
{
int k;
float sh;
printf("\nSHEARING");
printf("\n1.WITH RESPECT TO X-AXIS \n 2.WITH RESPECT TO Y-AXIS");
scanf("%d",&k);
printf("Enter the shearing parameter");
scanf("%f",&sh);
switch(k)
{
case 1:
nx1=xa+sh*ya;
ny1=ya;
nx2=xb+sh*yb;
ny2=yb;
nx3=xc+sh*yc;
ny3=yc;
nx4=xd+sh*yc;
ny4=yd;
break;
case 2:
nx1=xa;
ny1=ya+sh*yc;
nx2=xb;
ny2=yb+sh*xb;
nx3=xc;
ny3=yc+sh*xc;
nx4=xd;
ny4=yd+sh*xd;
break;
}
}
