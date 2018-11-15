#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int N, counter = 0 ;
struct Point
{
	float x, y;
}P[10];

//Draw point
void drawPnt(float x,float y){
	glPointSize(5.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	glFlush();
	
}
//draw a line
void drawLine(float x1, float y1, float x2, float y2)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
}
//factorial
int fact(int n)
{
    if (n >= 1)
        return n*fact(n-1);
    else
        return 1;
}
//draw Curve
void drawCurve(struct Point P[])
{
	glColor3f(1.0,0.0,.0);
	glPointSize(2.0);
	struct Point p;
	
	float u;
	int i = 0;
	for(u=0; u<=1; u=u+0.001)
	{
		p.x = 0; p.y =0 ;
		for(i = 0; i<= N-1; i++)
		{
			p.x += P[i].x*((fact(N-1))/((fact(i))*(fact(N-1-i))))*pow(u, i)*pow(1-u, N-1-i);
			p.y += P[i].y*((fact(N-1))/((fact(i))*(fact(N-1-i))))*pow(u, i)*pow(1-u, N-1-i);
			
			
		}	
		glBegin(GL_POINTS);
		glVertex2f(p.x,p.y);
		glEnd();
		glFlush();
	//	printf("%f\t%f\n",p.x, p.y);
	}

}
//beizer curve function
void bezierCurve()
{
	
}
//mouse function
void MyMouseFunc(int button, int state, int x, int y)
{
	if(counter<N)
	{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int  i= 0;
		for(i = 0; i<N; i++)
		{
			if(counter%N == i)
			{
					P[counter].x = x;
		P[counter].y = 500 - y;
		drawPnt(P[counter].x, P[counter].y);
		if(counter!=0)
		drawLine(P[counter-1].x, P[counter-1].y, P[counter].x, P[counter].y);
		break;
			}
		
		
		}
		counter++;
		if(counter == N)
		{
			drawCurve(P);
		}
	}
}

}
void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(1.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0 , 500 , 0 , 500);
}

int main(int argc, char **argv)
{
  printf("Enter the number of control Points less than 10\n");
  scanf("%d",&N);
  while(1)
  {
  	if(N>10)
  	{
  		printf("Enter the number of control Points less than 10\n");
  scanf("%d",&N);
	  }
	  else break;
  }
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("Beizer Curve");
  Init();
  glutMouseFunc(MyMouseFunc);
  glutDisplayFunc(bezierCurve);
  glutMainLoop();
}
