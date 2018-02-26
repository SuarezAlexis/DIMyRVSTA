/* Este programa dibuja una "Tetera", este objeto esta definido
* en GLUT, se crea una fuente de luz, y un material */

//Incluimos las librerias
#include <GL/glut.h>

GLfloat camPosition = 0.0f;
#define CAM_GAP 1.0f;
GLfloat size = 1.0;
#define SIZE_GAP 0.2f
GLint rot = 0;
int rotating = 0;
#define ANGLE 15
GLfloat color[] = { 0.1,0.0,0.0,1.0 };

void init(void)
{
	// Ubicamos la fuente de luz en el punto (1.0, 1.0, 1.0)
	//GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	// Activamos la fuente de luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);					// Activamos el valor de inicio del buffer de profundidad
	glEnable(GL_DEPTH_TEST);				// Hacemos la prueba de profundidad
	glDepthFunc(GL_LEQUAL);				// Tipo de prueba de profundidad a hacer
	return;
}

void reshape(int w, int h)
{
	if (!h)
		return;

	glViewport(0, camPosition, (GLsizei)w, (GLsizei)h);
	// Activamos la matriz de proyeccion.
	glMatrixMode(GL_PROJECTION);
	// "limpiamos" esta con la matriz identidad.
	glLoadIdentity();
	// Usamos proyeccion ortogonal
	//glOrtho(-200, 200, -200, 200, -200, 200);
	gluPerspective(30.0f, (GLfloat)800 / (GLfloat)600, 0.03, 1000.0);
	// Activamos la matriz de modelado/visionado. 
	glMatrixMode(GL_MODELVIEW);
	// "Limpiamos" la matriz
	glLoadIdentity();
	return;
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{
	// Propiedades del material
	GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 100.0f };

	// "Limpiamos" el frame buffer con el color de "Clear", en este 
	// caso negro. 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();

	glTranslatef(0.0, 0.0, -20+camPosition);
	// Rotacion de 30 grados en torno al eje x
	glRotated(30.0, 1.0, 0.0, 0.0);
	// Rotacion de -30 grados en torno al eje y
	glRotated(-30, 0.0, 1.0, 0.0);
	//Rotación dada por el usuario (eje y)
	glRotated(rot,0.0,0.1,0.0);

	// Dibujamos una "Tetera" y le aplico el material
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glutSolidTeapot(size);
	//glutWireCube(2.0f);

	//glFlush();
	glutSwapBuffers();
	return;
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: exit(0);
			break;
		case 'r':
			color[0] = 1.0f;
			color[1] = 0.0f;
			color[2] = 0.0f;
			break;
		case 'g':
			color[0] = 0.0f;
			color[1] = 1.0f;
			color[2] = 0.0f;
			break;
		case 'b':
			color[0] = 0.0f;
			color[1] = 0.0f;
			color[2] = 1.0f;
			break;
	}
	glutPostRedisplay();
	return;
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_LEFT:
			if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
			{
				rotating = 1;
			}
			else
			{
				rotating = 0;
				rot += ANGLE;
			}
			break;
		case GLUT_KEY_RIGHT:
			if (glutGetModifiers() == GLUT_ACTIVE_CTRL)
			{
				rotating = 2;
			}
			else
			{
				rotating = 0;
				rot -= ANGLE;
			}
			break;
		case GLUT_KEY_DOWN:
			size -= SIZE_GAP;
			break;
		case GLUT_KEY_UP:
			size += SIZE_GAP;
			break;
		case GLUT_KEY_F1:
			camPosition -= CAM_GAP;
			break;
		case GLUT_KEY_F2:
			camPosition += CAM_GAP;
			break;
	}
	glutPostRedisplay();
	return;
}

void idleFunction()
{
	switch (rotating)
	{
		case 0:
			break;
		case 1:
			rot++;
			break;
		case 2:
			rot--;
			break;
	}
	glutPostRedisplay();
}

// Main del programa.
int main(int argc, char **argv)
{
	// Inicializo OpenGL
	glutInit(&argc, argv);

	// Activamos buffer simple y colores del tipo RGB  
	//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Definimos una ventana de medidas 300 x 300 como ventana 
	// de visualizacion en pixels
	glutInitWindowSize(300, 300);

	// Posicionamos la ventana en la esquina superior izquierda de 
	// la pantalla.
	glutInitWindowPosition(0, 0);

	// Creamos literalmente la ventana y le adjudicamos el nombre que se
	// observara en su barra de titulo.
	glutCreateWindow("Tetera");

	// Inicializamos el sistema 
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutIdleFunc(idleFunction);
	glutMainLoop();

	// ANSI C requiere que main retorne un valor entero.
	return 0;
}