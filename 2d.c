//2D Transformation

#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void main(int argc,char **argv)
{
	int gm,c,k;
	float x1,x2,x3,y1,y2,y3,nx1,nx2,nx3,ny1,ny2,ny3,xf,yf;
	float sx,sy,xt,yt,r;
	float t;
	
	printf("\nProgarm for basic 2D Transformations");
	printf("\nEnter the Points for triangle : ");
	scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
	printf("\nEnter the reference point:");
	scanf("%f%f",&xf,&yf);
	do {
		printf("\n1.Translation\n2.Rotation\n 3.Scaling\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&c);
	
		switch(c)
		{
	 		 case 1:printf("\nEnter the translation factor");
				scanf("%f%f",&xt,&yt);
				nx1=x1+xt;
				ny1=y1+yt;
				nx2=x2+xt;
				ny2=y2+yt;
				nx3=x3+xt;
				ny3=y3+yt;
				break;

	  		case 2:	printf("\nEnter the angle of rotation");
				scanf("%f",&r);
				t=3.14*(r/180);
				nx1=xf+(x1-xf)*cos(t)+-(y1-yf)*sin(t);
				ny1=yf+(x1-xf)*sin(t)+(y1-yf)*cos(t);
				nx2=xf+(x2-xf)*cos(t)-(y2-yf)*sin(t);
				ny2=yf+(x2-xf)*sin(t)+(y2-yf)*cos(t);
				nx3=xf+(x3-xf)*cos(t)-(y3-yf)*sin(t);
				ny3=yf+(x3-xf)*sin(t)+(y3-yf)*cos(t);
				break;

	  		case 3:	printf("\nEnter th scaling factor");
				scanf("%f%f",&sx,&sy);
				nx1=xf+(x1-xf)*sx;
				ny1=yf+(y1-yf)*sy;
				nx2=xf+(x2-xf)*sx;
				ny2=yf+(y2-yf)*sy;
				nx3=xf+(x3-xf)*sx;
				ny3=yf+(y3-yf)*sy;
				break;

		}
	
	
	
	

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,600);
	glutInitWindowPosition(100,150);

	glutCreateWindow("Triangle");
	glClearColor(1.0,0.95,0.98,1.0);
	glColor3f(0.8f,0.0f,0.0f);
	gluOrtho2D(-200,200,-200,200);
	
	glClear (GL_COLOR_BUFFER_BIT);
	//drawing x-axis & y-axis
	glBegin(GL_LINES);
	glVertex2i(-200,0);
	glVertex2i(200,0);
	glEnd(); 

	glBegin(GL_LINES);
	glVertex2i(0,-200);
	glVertex2i(0,200);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glEnd();

	glColor3f(0.2f,0.5f,1.0f);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(nx1,ny1);
	glVertex2f(nx2,ny2);
	glVertex2f(nx3,ny3);
	glEnd();
	
	
	glFlush();
	}while(c!=4);
	glutMainLoop();
	
}
