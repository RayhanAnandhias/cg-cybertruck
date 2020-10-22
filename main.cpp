//Rayhan Azka A.P
//181524028
//PRAKTIKUM CG-8 
//Opengl glut membuat objek 'Cybertruck Tesla'

#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

int 
    width = 500,
    height = 500;

GLfloat xangle=45.0,yangle=45.0,zangle=0.0,angle=0.0;
GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;
GLfloat xs=1.0,ys=1.0,zs=1.0;
GLUquadricObj *t;
GLfloat r=0.7922,g=0.8,b=0.8078;
GLfloat New_x;
GLfloat New_y, theta;

void Transform(GLfloat Width, GLfloat Height) {
  glViewport(0, 0, Width, Height);              
  glMatrixMode(GL_PROJECTION);                  
  glLoadIdentity();				
  gluPerspective(45.0,Width/Height,0.1,100.0);  
  glMatrixMode(GL_MODELVIEW);                  
}

void InitGL(GLfloat Width, GLfloat Height) {

    glClearColor(0.878, 1.0, 1.0, 1.0);
    glLineWidth(2.0);              
    Transform( Width, Height ); 
    t=gluNewQuadric();
    gluQuadricDrawStyle(t, GLU_FILL);
    glEnable(GL_SMOOTH);
}

void ReSizeGLScene(GLint Width, GLint Height) {
  if (Height==0)     Height=1;                   
  if (Width==0)      Width=1;
  Transform( Width, Height );                   
}

void drawBody() {
    //face body
    glBegin(GL_TRIANGLES);
        glColor3f(0.863,0.863,0.863);
        glVertex3f(0.62,0.51,0.5);
        glVertex3f(1.6,0.56,0.5);
        glVertex3f(1.0,0.66,0.4);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(0.62,0.51,0.5);
        glVertex3f(0.62,0.445,0.5);
        glVertex3f(0.84,0.42,0.5);
        glVertex3f(1.3,0.423,0.5);
        glVertex3f(1.52,0.43,0.5);
        glVertex3f(1.58,0.44,0.5);
        glVertex3f(1.6,0.56,0.5);
    glEnd();

    //back body
    glBegin(GL_TRIANGLES);
        glColor3f(0.863,0.863,0.863);
        glVertex3f(0.62,0.51,-0.1);
        glVertex3f(1.6,0.56,-0.1);
        glVertex3f(1.0,0.66,0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(0.62,0.51,-0.1);
        glVertex3f(0.62,0.445,-0.1);
        glVertex3f(0.84,0.42,-0.1);
        glVertex3f(1.3,0.423,-0.1);
        glVertex3f(1.52,0.43,-0.1);
        glVertex3f(1.58,0.44,-0.1);
        glVertex3f(1.6,0.56,-0.1);
    glEnd();

    //gambar kab mobil
    glBegin(GL_QUADS);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(0.62,0.51,0.5);
        glVertex3f(0.62,0.51,-0.1);
        glVertex3f(0.62,0.445,-0.1);
        glVertex3f(0.62,0.445,0.5);
    glEnd();

    //gambar belakang mobil
    glBegin(GL_QUADS);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(1.6,0.56,0.5);
        glVertex3f(1.58,0.44,0.5);
        glVertex3f(1.58,0.44,-0.1);
        glVertex3f(1.6,0.56,-0.1);
    glEnd();

    //gambar atas depan mobil
    glBegin(GL_QUADS);
        glColor3f(0.863,0.863,0.863);
        glVertex3f(1.0,0.66,0.4);
        glVertex3f(1.0,0.66,0.0);
        glVertex3f(0.62,0.51,-0.1);
        glVertex3f(0.62,0.51,0.5);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(1.0,0.66,0.4);
        glVertex3f(1.0,0.66,0.0);
        glVertex3f(1.0,0.51,0.0);
        glVertex3f(1.0,0.51,0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(1.0,0.66,0.4);
        glVertex3f(1.0,0.51,0.4);
        glVertex3f(1.58,0.44,0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0.714,0.714,0.714);
        glVertex3f(1.0,0.66,0.0);
        glVertex3f(1.0,0.51,0.0);
        glVertex3f(1.58,0.44,-0.1);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.863,0.863,0.863);
        glVertex3f(1.58,0.44,0.5);
        glVertex3f(1.58,0.44,-0.1);
        glVertex3f(1.0,0.51,0.0);
        glVertex3f(1.0,0.51,0.4);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.545,0,0);
        glVertex3f(1.6,0.56,0.5);
        glVertex3f(1.6,0.56,-0.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.878,1,1);
        glVertex3f(0.62,0.51,0.5);
        glVertex3f(0.62,0.51,-0.1);
    glEnd();

    //bawah mobil
    glBegin(GL_QUADS);
        glColor3f(0.863,0.863,0.863);
        glVertex3f(0.62,0.445,0.5);
        glVertex3f(0.62,0.445,-0.1);
        glVertex3f(1.58,0.44,-0.1);
        glVertex3f(1.58,0.44,0.5);
    glEnd();
}

void drawWindow() {
    //face window
    glBegin(GL_TRIANGLES);
        glColor3f(0.378,0.378,0.378);
        glVertex3f(0.65,0.51,0.51);
        glVertex3f(1.4,0.56,0.51);
        glVertex3f(1.0,0.64,0.45);
    glEnd();

    
    //back window
    glBegin(GL_TRIANGLES);
        glColor3f(0.378,0.378,0.378);
        glVertex3f(0.65,0.51,-0.11);
        glVertex3f(1.4,0.56,-0.11);
        glVertex3f(1.0,0.64,-0.05);
    glEnd();

    //kaca depan mobil
    glBegin(GL_QUADS);
        glColor3f(0.378,0.378,0.378);
        glVertex3f(0.97,0.66,0.4);
        glVertex3f(0.97,0.66,0.0);
        glVertex3f(0.66,0.51,-0.1);
        glVertex3f(0.66,0.51,0.5);
    glEnd();
}

void drawWheel() {

    //roda kiri depan
    glColor3f(0.378,0.378,0.378);
    glPushMatrix();
    glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20) {
        glVertex3f(0.8,0.38,0.5);
        glVertex3f(0.8+(0.08*(cos(((theta+angle)*3.14)/180))),0.38+(0.08*(sin(((theta+angle)*3.14)/180))),0.5);
	  }
    glEnd();

    //roda kiri belakang
    glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20) {
        glVertex3f(0.8,0.38,-0.1);
        glVertex3f(0.8+(0.08*(cos(((theta+angle)*3.14)/180))),0.38+(0.08*(sin(((theta+angle)*3.14)/180))),-0.1);
	  }
    glEnd();

    glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20) {
        glVertex3f(1.4,0.38,-0.1);
        glVertex3f(1.4+(0.08*(cos(((theta+angle)*3.14)/180))),0.38+(0.08*(sin(((theta+angle)*3.14)/180))),-0.1);
	  }
    glEnd();

    glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+20) {
        glVertex3f(1.4,0.38,0.5);
        glVertex3f(1.4+(0.08*(cos(((theta+angle)*3.14)/180))),0.38+(0.08*(sin(((theta+angle)*3.14)/180))),0.5);
	  }
    glEnd();

    glColor3f(0,0,0);
    glTranslatef(0.8,0.38,0.5);
    glutSolidTorus(0.025,0.07,10,25);

    glTranslatef(0.0,0.0, -0.6);
    glutSolidTorus(0.025,0.07,10,25);

    glTranslatef(0.6,0.0, 0.0);
    glutSolidTorus(0.025,0.07,10,25);

    glTranslatef(0.0,0.0, 0.6);
    glutSolidTorus(0.025,0.07,10,25);
}

void drawEnvironment() {
    glBegin(GL_QUADS);
    glPushMatrix();
	glTranslatef(xw,0,0);
    glColor3f(0.957,0.643,0.376);
    glVertex3f(-100,-0.1,-100);
    glVertex3f(-100,-0.1,-0.8);         //a sand surroundings
    glVertex3f(100,-0.1,-0.8);
    glVertex3f(100,-0.1,-100);

    glColor3f(0.118,0.137,0.161);
    glVertex3f(-100,-0.1,-0.8);
    glVertex3f(-100,-0.1,0.3);         //a long road
    glVertex3f(100,-0.1,0.3);
    glVertex3f(100,-0.1,-0.8);

    glColor3f(0.957,0.643,0.376);
    glVertex3f(-100,-0.1,0.3);
    glVertex3f(-100,-0.1,100);         //a sand surroundings
    glVertex3f(100,-0.1,100);
    glVertex3f(100,-0.1,0.3);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers

    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-1.0,0.0,-3.5);
    glRotatef(xangle,1.0,0.0,0.0);
    glRotatef(yangle,0.0,1.0,0.0);
    glRotatef(zangle,0.0,0.0,1.0);
    glTranslatef(xt,yt,zt);
    glScalef(xs,ys,zs);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    drawBody();
    drawWindow();
    drawWheel();
    drawEnvironment();

    glPopMatrix();
    glEnable(GL_DEPTH_TEST);
    glutPostRedisplay();
    glutSwapBuffers();
}

void resize(GLsizei new_width, GLsizei new_height) {
    if(new_height == 0)
        new_height = 1;
    
    GLfloat aspect_ratio = (GLfloat) new_width / (GLfloat) new_height;

    glViewport(0,0,new_width,new_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(new_width <= new_height) {
        glOrtho(-2.0, 2.0, -2.0/aspect_ratio, 2.0/aspect_ratio, -10.0, 10.0);
    } else {
        glOrtho(-2.0*aspect_ratio, 2.0*aspect_ratio, -2.0, 2.0, -10.0, 10.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void MyMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		New_x = x;
		New_y = y;
	}
}
void MyMotion(int x, int y)
{
	xangle = x - New_x;
	yangle = y - New_y;
	display();
	glutPostRedisplay();
}

void NormalKey(GLubyte key, GLint x, GLint y)
{
    switch ( key )    {
     case 27 : 
            exit(0);
            break;

      case 'x': xangle += 5.0;
                      glutPostRedisplay();
                      break;

       case 'X':xangle -= 5.0;
                       glutPostRedisplay();
                       break;

      case 'y':
        yangle += 5.0;
        glutPostRedisplay();
        break;

     case 'Y':
        yangle -= 5.0;
        glutPostRedisplay();
        break;

     case 'z':
        zangle += 5.0;
        glutPostRedisplay();
        break;

     case 'Z':
        zangle -= 5.0;
        glutPostRedisplay();
        break;

      case 'u':                          /* Move up */
        yt += 0.2;
        glutPostRedisplay();
        break;

      case 'U':
        yt -= 0.2;                      /* Move down */
        glutPostRedisplay();
        break;

      case 'f':                          /* Move forward */
        zt += 0.2;
        glutPostRedisplay();
        break;

      case 'F':
        zt -= 0.2;                      /* Move away */
        glutPostRedisplay();
        break;

	  case 's':zs+=.2;
		  glutPostRedisplay();
		  break;

	  case 'S':zs-=0.2;
		  glutPostRedisplay();
		  break;

	  case 'a':ys+=.2;
		  glutPostRedisplay();
		  break;

	  case 'A':ys-=0.2;
		  glutPostRedisplay();
		  break;

	  case 'q':xs+=.2;
		  glutPostRedisplay();
		  break;

	  case 'Q':xs-=0.2;
		  glutPostRedisplay();
		  break;
     default:
	break;
    }

}

static void SpecialKeyFunc( int Key, int x, int y )
{
	switch ( Key ) {
	case GLUT_KEY_RIGHT:
		xt += 0.2;
	    glutPostRedisplay();
		break;
    case GLUT_KEY_LEFT:
		xt -= 0.2;
        glutPostRedisplay();
		break;
	}
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(width,height);
    glutCreateWindow("PRAKTIKUM CG-8 181524028 'Cybertruck Tesla' ");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutReshapeFunc(ReSizeGLScene);
    glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);
    glutKeyboardFunc(NormalKey);
    glutSpecialFunc( SpecialKeyFunc );
    InitGL(width,height);
    glutMainLoop();
    return 0;
}
