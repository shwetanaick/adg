//Animation-Analog 

#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<ctime>
using namespace std;

float minx=0,miny=250,hourx=0,houry=180,posx=0,posy=300;
float x=0,y=280;

void drawcircle(int xc,int yc,int r)
{
float p0;
int xa[1000],ya[1000],n=0,i;
int x,y;
p0=5/4-r;
x=0;
y=r;
glPointSize(3.0);
glBegin(GL_POINTS);
glVertex2i(xc,yc);
glColor3f(0.0,0.0,0.0);
x=x;
y=y;
glVertex2i(x+xc,y+yc);
i=0;
xa[i]=x;
ya[i]=y;
n++;
i++;
while(x<y)
{
if(p0<0)
{
x=x+1;
p0=p0+(2*x+1);
glVertex2i(x+xc,y+yc);
xa[i]=x;
ya[i]=y;
n++;
i++;
}
else
{
x=x+1;
y=y-1;
p0=p0+(2*x+1)-(2*y+1);
glVertex2i(x+xc,y+yc);
xa[i]=x;
ya[i]=y;
n++;
i++;
}
}

i=0;
while(i<n)
{

glVertex2i(-xa[i]+xc,-ya[i]+yc);
glVertex2i(ya[i]+xc,xa[i]+yc);
glVertex2i(-ya[i]+xc,-xa[i]+yc);
glVertex2i(-xa[i]+xc,ya[i]+yc);
glVertex2i(xa[i]+xc,-ya[i]+yc);
glVertex2i(-ya[i]+xc,xa[i]+yc);
glVertex2i(ya[i]+xc,-xa[i]+yc);
i++;
}
}

void display()
{
int xr=0,yr=0;
glPointSize(3.0f);
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINES);
glColor3f(0.0f,0.0f,0.0f);
glVertex2i(0.0,0.0);
glVertex2i(x,y);
glVertex2i(0.0,0.0);
glVertex2i(minx,miny);
glVertex2i(0.0,0.0);
glVertex2i(hourx,houry);
glEnd();

drawcircle(0,0,300);
glEnd();

//Draw points for hours

glPointSize(6.0);
glBegin(GL_LINES);
int i=0;
while(i<12)
{
float angle=(3.14/180)*i*30;
posx=(0-xr)*cosf(-angle)-(250-yr)*sinf(-angle)+xr;
posy=(0-xr)*sinf(-angle)+(250-yr)*cosf(-angle)+yr;
glVertex2i(posx,posy);
posx=(0-xr)*cosf(-angle)-(285-yr)*sinf(-angle)+xr;
posy=(0-xr)*sinf(-angle)+(285-yr)*cosf(-angle)+yr;
glVertex2i(posx,posy);
i++;
}
glEnd();
glFlush();

//Update

time_t now=time(0);
tm*ltm=localtime(&now);

//print varios components of tm structure

float angle=(3.14/180)*ltm->tm_sec*6;
x=(0-xr)*cosf(-angle)-(280-yr)*sinf(-angle)+xr;
y=(0-xr)*sinf(-angle)+(280-yr)*cosf(-angle)+yr;
angle=(3.14/180)*ltm->tm_min*6;
minx=(0-xr)*cosf(-angle)-(250-yr)*sinf(-angle)+xr;
miny=(0-xr)*sinf(-angle)+(250-yr)*cosf(-angle)+yr;
angle=(3.14/180)*(ltm->tm_hour*30+(ltm->tm_min*0.5));
hourx=(0-xr)*cosf(-angle)-(180-yr)*sinf(-angle)+xr;
houry=(0-xr)*sinf(-angle)+(180-yr)*cosf(-angle)+yr;
 
//redraw
glutPostRedisplay();
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640,640);
glutInitWindowPosition(500,500);
glutCreateWindow("First Attempt");
glClearColor(1.0,1.0,1.0,1.0);
glPointSize(6.0);
gluOrtho2D(-600,600,-600,600);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

















