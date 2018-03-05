//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		//Comentar si estamos en Windows
#include "Main.h"


// Variables used to calculate frames per second:
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement
int year = 0, day = 0;
int year_m = 0, day_m = 0;
int year_l = 0, day_l = 0;
int year_j = 0, day_j = 0;
int year_s = 0, day_s = 0;
int year_u = 0, day_u = 0;
int year_lj = 0, day_lj = 0;
int sol=0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.9f, 0.3f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupDiffuse[]= { 0.7f, 0.5f, 0.1f, 1.0f };			// Jupiter
GLfloat JupSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupShininess[] = { 50.0 };

GLfloat LunaJDiffuse[]= { 0.9f, 0.9f, 0.1f, 1.0f };			// LunaJ
GLfloat LunaJSpecular[] = { 0.5, 0.9, 0.2, 1.0 };
GLfloat LunaJShininess[] = { 50.0 };

GLfloat UraDiffuse[]= { 0.1f, 0.5f, 0.8f, 1.0f };			// Urano
GLfloat UraSpecular[] = { 0.1, 0.4, 0.7, 1.0 };
GLfloat UraShininess[] = { 50.0 };

GLfloat SatDiffuse[]= { 0.8f, 0.8f, 0.1f, 1.0f };			// Saturno
GLfloat SatSpecular[] = { 0.5, 1.0, 0.0, 1.0 };
GLfloat SatShininess[] = { 50.0 };

GLfloat NepDiffuse[]= { 0.1f, 0.4f, 0.8f, 1.0f };			// Neptuno
GLfloat NepSpecular[] = { 0.1, 0.5, 0.2, 1.0 };
GLfloat NepShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glLightfv(GL_LIGHT1,GL_DIFFUSE,SunDiffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,SunSpecular);
	//glLightfv(GL_LIGHT1,GL_SHININESS,SunShininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-26.0+camaraZ);			//camara
	glPushMatrix();
	glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
	glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
	glDisable(GL_LIGHTING);
	glLightfv(GL_LIGHT1,GL_POSITION, SunPosition);
	glutWireSphere(1.9,14,14);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glRotatef(year,0.0f,1.0f,0.0f);
	glTranslatef(6.0f,0.0f,0.0f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,EarthDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,EarthSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,EarthShininess);
	glPushMatrix();
	glRotatef(day,0.0f,1.0f,0.0f);
	glColor3f(0.2f,0.2f,0.8f);

	glutSolidSphere(0.6f,14,14); //Tierra
	glPopMatrix();

	glRotatef(year_l,0.0f,0.0f,1.0f);
	glTranslatef(1.5f,0.0f,0.0f);
	glRotatef(day_l,0.0f,1.0f,0.0f);
	glColor3f(0.85f,0.85f,0.85f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,MoonDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,MoonSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,MoonShininess);
	glutSolidSphere(0.1f,14,14); //Luna
	
	glPopMatrix();


	glPushMatrix();
	glRotatef(year_m,0.0f,0.0f,1.0f);
	glTranslatef(13.0f,0.0f,0.0f);
	glRotatef(day_m,1.0f,0.0f,0.0f);
	glColor3f(0.8f,0.4f,0.1f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,MarsDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,MarsSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,MarsShininess);
	glutSolidSphere(0.4f,14,14); //Marte
	glPopMatrix();

	glPushMatrix();
	glRotatef(year_j,1.0f,0.0f,0.0f);
	glTranslatef(0.0f,-16.0f,0.0f);
	glPushMatrix();
	glRotatef(day_j,1.0f,0.0f,0.0f);
	glColor3f(0.5f,0.6f,0.1f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,JupDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,JupSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,JupShininess);
	glutSolidSphere(0.8f,14,14); //Júpiter

	glPopMatrix();

	glRotatef(year_lj,0.0f,0.0f,-1.0f);
	glTranslatef(2.5f,0.0f,0.0f);
	glRotatef(day_lj,0.0f,1.0f,0.0f);
	glColor3f(0.85f,0.85f,0.85f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,LunaJDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,LunaJSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,LunaJShininess);
	glutSolidSphere(0.25f,14,14); //LunaJ
	
	glPopMatrix();

	glPushMatrix();
	glRotatef(35.0f,0.0f,0.0f,1.0f);
	glRotatef(year_s,1.0f,0.0f,0.0f);
	glTranslatef(0.0f,21.0f,0.0f);
	glRotatef(day_s,1.0f,0.0f,0.0f);
	glColor3f(0.0f,0.8f,0.4f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,SatDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,SatSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,SatShininess);
	glutSolidSphere(0.8f,14,14); //Saturno
	glPopMatrix();

	glPushMatrix();
	glRotatef(-110.0f,0.0f,0.0f,1.0f);
	glRotatef(year_u,0.0f,1.0f,0.0f);
	glTranslatef(25.0f,0.0f,0.0f);
	glRotatef(day_u,1.0f,0.0f,0.0f);
	glColor3f(0.4f,0.0f,0.6f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,UraDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,UraSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,UraShininess);
	glutSolidSphere(0.7f,14,14); //Urano
	glPopMatrix();

	glPushMatrix();
	glRotatef(75.0f,0.0f,0.0f,1.0f);
	glRotatef(year_u,0.0f,0.0f,-1.0f);
	glTranslatef(0.0f,29.0f,0.0f);
	glRotatef(day_u,1.0f,0.0f,0.0f);
	glColor3f(0.4f,0.5f,0.8f);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,NepDiffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,NepSpecular);
	glMaterialfv(GL_FRONT,GL_SHININESS,NepShininess);
	glutSolidSphere(0.7f,14,14); //Neptuno
	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		year = ((year - 2) % 360);
		sol = (sol - 5) % 360;
		day = (day + 5) % 360;
		day_m = (day_m - 16) % 360;
		year_m = (year_m + 1) % 360;
		year_l = (year_l + 4) % 360;
		day_l = (day_l - 10) % 360;
		year_j = (year_j + 4) % 360;
		day_j = (day_j - 10) % 360;
		year_s = (year_s + 2) % 360;
		day_s = (day_s - 7) % 360;
		year_u = (year_u + 2) % 360;
		day_u = (day_u - 7) % 360;
		year_lj = (year_lj + 2) % 360;
		day_lj = (day_lj - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 175.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}