#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<stdlib.h>

int xc,yc,r;
void display(void)
{
    int x=r,y=0;
    int P=1-r;
  	glClear (GL_COLOR_BUFFER_BIT);
  	glColor3f(0.0,0.0,0.0);
	glPointSize(2.5);
    glBegin(GL_POINTS);
    if(r>0)
    {
	glVertex2s(x+xc,-y+yc);
        glVertex2s(y+xc,x+yc);
        glVertex2s(-y+xc,x+yc);
	}
    while(x>y)
    {
     y++;
     if(P<=0)
       P=P+2*y+1;
     else
     {
       x--;
       P=P+2*y-2*x+1;
     }
     if(x<y)
     {
     	break;
     }
	 glVertex2s(x+xc,y+yc);
     glVertex2s(-x+xc,y+yc);
     glVertex2s(x+xc,-y+yc);
     glVertex2s(-x+xc,-y+yc);
     if(x!=y)
     {
     	glVertex2s(y+xc,x+yc);
        glVertex2s(-y+xc,x+yc);
        glVertex2s(y+xc,-x+yc);
        glVertex2s(-y+xc,-x+yc);
     }
    }
    glEnd();
    glFlush();

}

int main(int argc,char**argv)
{

printf("enter the points");
scanf("%d%d%d",&xc,&yc,&r);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);

glutCreateWindow("Mid point circle");
glClearColor(1.0,0.95,0.98,1.0);
gluOrtho2D(-100.0,100.0,-100.0,100.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
