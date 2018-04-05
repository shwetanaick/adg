#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#define ROUND(x) ((int)(x+0.5))
int xa,xb,ya,yb;
/*---------------------------------------------------------------*/
void display(void)
{
 int m_new;
 int slope_error_new=m_new-(xb-xa);
 int x,y;
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f(0.0,0.0,0.0);
 glPointSize(2.5);
 glBegin(GL_POINTS);
 for(x=xa,y=ya;x<=xb;x++)
 {
   glVertex2s(ROUND(x),ROUND(y));
   slope_error_new+=m_new;
   
   if(slope_error_new>=0)
   {
     y++;
     slope_error_new-=2*(xb-xa);
   }
 }
 glEnd();
 glFlush();
}
/*---------------------------------------------------------------*/
int main(int argc,char**argv)
{
	printf("enter the points");
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);

	glutCreateWindow("BRESENHAMS");
	glClearColor(1.0,0.95,0.98,1.0);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
/*--------------------------------------------------------------*/
