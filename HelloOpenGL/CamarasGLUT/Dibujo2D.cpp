//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>

#include <windows.h>		// Archivo de cabecera para Windows
#include <math.h>			// Archivo de cabecera para Funciones Matemáticas
#include <stdio.h>			// Header File For Standard Input/Output
#include <stdlib.h>			// Header File For Standard Library
//#include "GL\gl.h"				// Archivo de cabecera para la libreria OpenGL32
//#include "glu.h"			// Archivo de cabecera para la libreria GLu32
//#include "glaux.h"			// Archivo de cabecera para la libreria Glaux
#include "GL\glut.h"			// Archivo de cabecera para la libreria Glut
#include <math.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;


void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void surface(void)
{
	GLfloat vertice[8][4] = {
		{ 8 * cos(angleY), 2 * sin(angleY), 0.0 },
		{ 8 * cos(angleY + 90), 2 * sin(angleY + 90), 0.0 },
		{ 8 * cos(angleY + 180),2 * sin(angleY + 180),0.0 },
		{ 8 * cos(angleY + 270),2 * sin(angleY + 270),0.0 },
		{ 4 * cos(angleY),sin(angleY),0.0 },
		{ 4 * cos(angleY + 90),sin(angleY + 90),0.0 },
		{ 4 * cos(angleY + 180),sin(angleY + 180),0.0 },
		{ 4 * cos(angleY + 270),sin(angleY + 270),0.0 }
	};
		/*= {
				{8.0 ,0.0, 0.0},    //Coordenadas Vértice 0 V0
				{0.0 ,2.0, 0.0},    //Coordenadas Vértice 1 V1
				{-8.0 ,0.0, 0.0},    //Coordenadas Vértice 2 V2
				{0.0 ,-2.0, 0.0},    //Coordenadas Vértice 3 V3
				{4.0 ,0.0, 0.0},    //Coordenadas Vértice 4 V4
				{0.0 ,1.0, 0.0},    //Coordenadas Vértice 5 V5
				{-4.0 ,0.0, 0.0},    //Coordenadas Vértice 6 V6
				{0.0 ,-1.0, 0.0},    //Coordenadas Vértice 7 V7
				}; */
	/*vertice[0] = { 8*cos(angleY), 2*sin(angleY), 0.0 };
	vertice[1] = { 8*cos(angleY + 90), 2*sin(angleY + 90), 0.0};
	vertice[2] = {8*cos(angleY + 180),2*sin(angleY + 180),0.0};
	vertice[3] = {8*cos(angleY + 270),2*sin(angleY + 270),0.0};
	vertice[4] = {4*cos(angleY),sin(angleY),0.0};
	vertice[5] = {4*cos(angleY + 90),sin(angleY + 90),0.0};
	vertice[6] = {4*cos(angleY + 180),sin(angleY + 180),0.0};
	vertice[7] = {4*cos(angleY + 270),sin(angleY + 270),0.0};
	*/
	//glPolygonMode(GL_FRONT, GL_FILL);
	//glPolygonMode(GL_BACK, GL_LINE);

		glBegin(GL_POLYGON);	
			glColor3f(0.0,0.75,0.25);
			//glNormal3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	
			glColor3f(0.0,0.75,0.25);
			//glNormal3f(1.0,0.0,0.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(0.0,0.75,0.25);
			//glNormal3f(0.0,0.0,-1.0);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);
			glColor3f(0.0,0.75,0.25);
			//glNormal3f(-1.0,0.0,0.0);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
		glEnd();

		
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
		
		glTranslatef(0.0f, 0.0f, transZ);
		glTranslatef(0.0f, transY, 0.0f);
		glTranslatef(transX, 0.0f, 0.0f);

		glRotatef(angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(angleY, 0.0f, 1.0f, 0.0f);
		glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


		surface();
		/*
		glPushMatrix();
			glTranslatef(1.5, 0.0 , 0.0);
			glRotatef(180, 1.0, 0.0, 00.0);
			surface();
		glPopMatrix();
		*/
		//Poner Código Aquí.

		
  											
  glPopMatrix();
  //glutSwapBuffers ( );
  glFlush();
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
	//glOrtho(-5,5,-5,5,0.1,20);	
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
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			printf("Posicion en X: %f\n", transX);
			break;
		case 'e':
		case 'E':
			transY +=0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'c':
		case 'C':
			transY -=0.2f;
			printf("Posicion en Y: %f\n", transY);
			break;
		case 'q':
		case 'Q':
			angleZ += 2.0f;
			break;
		case 'z':
		case 'Z':
			angleZ -= 2.0f;
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
    default:
      break;
  }

  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  //glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



