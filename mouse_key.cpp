//mouse_key.cpp 
#include <GL/glut.h>
#include <stdlib.h>

#define   screenHeight  500

using namespace std;

//initialization
void init( void )
{
	glClearColor( 1.0, 1.0, 1.0, 0.0 );	//get white background color
  	glColor3f( 0.0f, 0.0f, 0.0f );	//set drawing color
  	glPointSize( 8.0 );			//a dot is 4x4
  	glMatrixMode( GL_PROJECTION );
  	glLoadIdentity();
  	gluOrtho2D( 0.0, 500.0, 0.0, 500.0 );
} //init

void display()
{
  	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
 	glFlush();
}

void drawDot( int x, int y )
{
  	glBegin( GL_POINTS );			
    glVertex2i( x, y );		//draw a points
 	glEnd();
} //drawDot

void myMouse( int button, int state, int x, int y )
{
  	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) drawDot( x, screenHeight - y );
  	glFlush();				//send all output to screen
}

void myMovedMouse(  int mouseX, int mouseY)
{
  	GLint x = mouseX;
  	GLint y = screenHeight - mouseY;
  	GLint brushsize = 6;
  	//glColor3f( 1.0, 0.0, 0.0 );
  	glRecti ( x, y, x + brushsize, y + brushsize );
  	glFlush();
} //myMovedMouse

void myKeyboard ( unsigned char key, int mouseX, int mouseY )
{
  	GLint x = mouseX;
  	GLint y = screenHeight - mouseY;
  	switch( key )
  	{
    	case 'p':
 			drawDot ( x, y );
			glFlush();
			break;
    	case 'R':
        	glRecti ( x, y, x + 20, y + 30 );
			glFlush();
			break;
		case 'r':
			glColor3f( 1, 0, 0 );
			break;
		case 'g':
			glColor3f( 0, 1, 0 );
			break;
    	case 'b':
			glColor3f( 0, 0, 1 );
			break;
    	case 'e':
    	case 27:
			exit ( -1 );
         	break;
		default :
	break;
  }  
}


