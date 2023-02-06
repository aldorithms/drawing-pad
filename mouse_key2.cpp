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
  gluOrtho2D( 0.0, 1.0, 0.0, 1.0 );
} //init

void display()
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glFlush();
}

void drawDot( float x, float y )
{
  glBegin( GL_POINTS );			
    glVertex2f( x, y );		//draw a points
  glEnd();
} //drawDot

void myMouse( int button, int state, int x, int y )
{
  if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    drawDot( x/500.0, (screenHeight - y)/500.0 );
  glFlush();				//send all output to screen
}

void myMovedMouse(  int mouseX, int mouseY)
{
  GLfloat x = mouseX / 500.0;
  GLfloat y = (screenHeight - mouseY)/500.0;
  GLfloat brushsize = 6/500.0;
  glColor3f( 1.0, 0.0, 0.0 );
  glRectf ( x, y, x + brushsize, y + brushsize );
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
    case 'r':
        glRecti ( x, y, x + 20, y + 30 );
	glFlush();
	break;
    case 'e':
	exit ( -1 );
    default :
	break;
  }  
}


