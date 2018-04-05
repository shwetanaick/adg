#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float xa,xb,xc,xd,ya,yb,yc,yd,nx1,ny1,nx2,ny2,nx3,ny3,nx4,ny4;
void reflection();
void shear();
void main(int argc, char **argv)
{
	int c;
	printf("\nReflectiona nd Shearing");
	printf("\nEnetr the points:");
	scanf("%f%f%f%f%f%f%f%f",&xa,&ya,&xb,&yb,&xc,&yc,&xd,&yd);
	printf("\n\n1.Reflection\n2.Shearing\n3.Exit");
	printf("Enter your choice:");
	scanf("%d",&c);

	switch(c)
	{
		case 1: reflection(); break;
		case 2: shear(); break;
	}

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,600);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Triangle");
	glClearColor(0.9,0.9,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	gluOrtho2D(-200,200,-200,200);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	 glVertex2i(-200,0);
	 glVertex2i(200,0);
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
	printf("\nReflection");
	printf("\nReflection with respect to x axis\n2.Reflection with respect to y axis\n3.Reflection with respect to origin\n4.Reflection with respect x=y\n5.Reflection with respect to x=-y");

	printf("\nEnter your choice:");
	scanf("%d",&k);
	switch(k)
	{
	case 1: nx1=xa;
		ny1=-ya;
		nx2=xb;
		ny2=-yb;
		nx3=xc;
		ny3=-yc;
		nx4=xd;
		ny4=-yd;
		break;
	case 2: nx1=-xa;
		ny1=ya;
		nx2=-xb;
		ny2=yb;
		nx3=-xc;
		ny3=yc;
		nx4=-xd;
		ny4=yd;
		break;
	case 3: nx1=-xa;
		ny1=-ya;
		nx2=-xb;
		ny2=-yb;
		nx3=-xc;
		ny3=-yc;
		nx4=-xd;
		ny4=-yd;
		break;
	case 4: nx1=ya;
		ny1=xa;
		nx2=yb;
		ny2=xb;
		nx3=yc;
		ny3=xc;
		nx4=yd;
		ny4=xd;
		break;
	case 5: nx1=-ya;
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
printf("\n\nShearing\n");
printf("\n1.With respect to x axis\n2.With respect to y axis");
scanf("%d",&k);

switch(k)
	{
	case 1: nx1=xa+sh*ya;
		ny1=ya;
		nx2=xb+sh*yb;
		ny2=yb;
		nx3=xc+sh*yc;
		ny3=yc;
		nx4=xd+sh*yd;
		ny4=yd;
		break;
	case 2: nx1=xa;
		ny1=ya+sh*xa;
		nx2=xb;
		ny2=yb+sh*xb;
		nx3=xc;
		ny3=yc+sh*xc;
		nx4=xd;
		ny4=yd+sh*xd;
		break;
	}
}


































