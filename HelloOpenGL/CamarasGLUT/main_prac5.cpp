//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;

float rot1 = 0.0f;
float rot2 = 0.0f;
float rot3 = 0.0f;
float rot4 = 0.0f;
float rot5 = 0.0f;
float rot6 = 0.0f;
float rot7 = 0.0f;
float rot8 = 0.0f;
float rot9 = 0.0f;
float rot10 = 0.0f;
float rot11 = 0.0f;

int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
		glTranslatef(transX, 0.0f, transZ);
		glRotatef(angleY, 0.0, 1.0, 0.0);
		glRotatef(angleX, 1.0, 0.0, 0.0);
		
		glColor3f(1.0f, 0.0f, 0.0f);
		
		//A
		glRotatef(rot1,0.0f,0.0f,1.0f);
		glTranslatef(1.75f,0.0f,0.0f);
		glPushMatrix();
			glScalef(3.5f,2.0f,2.0f);
			prisma();
		glPopMatrix();
		
		//B
		glTranslatef(1.75f,0.0f,0.0f);
		glRotatef(rot2,0.0f,1.0f,0.0f);
		glTranslatef(1.5f,0.0f,0.0f);
		glPushMatrix();
			glScalef(3.0f,2.0f,2.0f);
			glColor3f(0.0f,1.0f,0.0f);
			prisma();
		glPopMatrix();

		//C
		glTranslatef(1.5f,0.0f,0.0f);
		glRotatef(rot3,0.0f,0.0f,1.0f);
		glTranslatef(0.5f,0.0f,0.0f);
		glPushMatrix(); //C
			glScalef(1.0f,2.0f,2.0f);
			glColor3f(0.0f,0.0f,1.0f);
			prisma();
		glPopMatrix();

		glPushMatrix();
			//D
			glTranslatef(0.5f,-0.625f,0.75f);
			glRotatef(rot4,0.0f,1.0f,0.0f);
			glTranslatef(0.75f,0.0f,0.0f);
			glPushMatrix();
				glScalef(1.5f,0.75f,0.5f);
				glColor3f(1.0f,1.0f,0.0f);
				prisma();
			glPopMatrix();

			//E
			glTranslatef(0.75f,0.0f,0.0f);
			glRotatef(rot5,0.0f,1.0f,0.0f);
			glTranslatef(0.75f,0.0f,0.0f);
			glPushMatrix();
				glScalef(1.5f,0.75f,0.5f);
				glColor3f(0.0f,1.0f,1.0f);
				prisma();
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
			//F
			glTranslatef(0.5f,0.75f,0.75f);
			glRotatef(rot6,0.0f,0.0f,1.0f);
			glTranslatef(0.75f,0.0f,0.0f);
			glPushMatrix();
				glScalef(1.5f,0.5f,0.5f);
				glColor3f(1.0f,1.0f,0.0f);
				prisma();
			glPopMatrix();

			//G
			glTranslatef(0.75f,0.0f,0.0f);
			glRotatef(rot7,0.0f,0.0f,1.0f);
			glTranslatef(1.0f,0.0f,0.0f);
			glPushMatrix(); //G
				glScalef(2.0f,0.5f,0.5f);
				glColor3f(0.0f,1.0f,1.0f);
				prisma();
			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			//H
			glTranslatef(0.5f,0.75f,0.0f);
			glRotatef(rot8,0.0f,0.0f,1.0f);
			glTranslatef(1.0f,0.0f,0.0f);
			glPushMatrix();
				glScalef(2.0f,0.5f,0.5f);
				glColor3f(1.0f,1.0f,0.0f);
				prisma();
			glPopMatrix();
			//I
			glTranslatef(1.0f,0.0f,0.0f);
			glRotatef(rot9,0.0f,0.0f,1.0f);
			glTranslatef(0.825f,0.0f,0.0f);
			glPushMatrix();
				glScalef(1.75f,0.5f,0.5f);
				glColor3f(0.0f,1.0f,1.0f);
				prisma();
			glPopMatrix();
		glPopMatrix();

	glPushMatrix();
		
		//J
		glTranslatef(0.5f,0.75f,-0.75f);
		glRotatef(rot10,0.0f,0.0f,1.0f);
		glTranslatef(1.0f,0.0f,0.0f);
		glPushMatrix();
			glScalef(2.0f,0.5f,0.5f);
			glColor3f(1.0f,1.0f,0.0f);
			prisma();
		glPopMatrix();

		//K
		glTranslatef(1.0f,0.0f,0.0f);
		glRotatef(rot11,0.0f,0.0f,1.0f);
		glTranslatef(1.0f,0.0f,0.0f);
		glPushMatrix();
			glScalef(2.0f,0.5f,0.5f);
			glColor3f(0.0f,1.0f,1.0f);
			prisma();
		glPopMatrix();

  	glPopMatrix();					
  glPopMatrix();
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'z':
		case 'Z':
			rot1 -= 1.2f;
			break;
		case 'x':
		case 'X':
			rot1 += 1.2f;
			break;
		case 'c':
		case 'C':
			if(rot2  > -90)
				rot2 -= 1.2f;
			break;
		case 'v':
		case 'V':
			if(rot2 <= 0)
				rot2 += 1.2f;
			break;
		case 'b':
		case 'B':
			if(rot3 >= -45)
				rot3 -= 1.2f;
			break;
		case 'n':
		case 'N':
			if(rot3 <= 45)
				rot3 += 1.2f;
			break;
		case 'e':
		case 'E':
			if(rot4 >= -45)
				rot4 -= 1.2f;
			break;
		case 'r':
		case 'R':
			if(rot4 <= 45)
				rot4 += 1.2f;
			break;
		case 't':
		case 'T':
			if(rot5 >= 0)
				rot5 -= 1.2f;
			break;
		case 'y':
		case 'Y':
			if(rot5 <= 90)
				rot5 += 1.2f;
			break;
		case 'f':
		case 'F':
			if(rot6 >= -45)
				rot6 -= 1.2f;
			break;
		case 'g':
		case 'G':
			if(rot6 <= 0)
				rot6 += 1.2f;
			break;
		case 'h':
		case 'H':
			if(rot7 >= -120)
				rot7 -= 1.2f;
			break;
		case 'j':
		case 'J':
			if(rot7 <= 0)
				rot7 += 1.2f;
			break;
		case 'u':
		case 'U':
			if(rot8 >= -45)
				rot8 -= 1.2f;
			break;
		case 'i':
		case 'I':
			if(rot8 <= 0)
				rot8 += 1.2f;
			break;
		case 'o':
		case 'O':
			if(rot9 >= -120)
				rot9 -= 1.2f;
			break;
		case 'p':
		case 'P':
			if(rot9 <= 0)
				rot9 += 1.2f;
			break;
		case '1':
			if(rot10 >= -45)
				rot10 -= 1.2f;
			break;
		case '2':
			if(rot10 <= 0)
				rot10 += 1.2f;
			break;
		case '3':
			if(rot11 >= -120)
				rot11 -= 1.2f;
			break;
		case '4':
			if(rot11 <= 0)
				rot11 += 1.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



