#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
//#include <windows.h>

# define PI 3.14159265358979323846

GLfloat x = -8.0; GLfloat y = 7.0; GLfloat radius = 2.0;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;
bool nm = true;
GLfloat x_ = -7.0;

void init(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void ground()
{
	if (nm) { glColor3f(0.0, 1.0, 0.0); }
	else { glColor3f(0.0, 1.0, 0.5); }
	
	GLfloat verts_ground[8] = { -10.0, -2.0, -10.0, -10.0, 10.0, -10.0, 10.0, -2.0 };
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_ground);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	
	GLfloat verts_house[] = { 
		-7.0f, 1.0f, -7.0f, -3.0f, -5.0f, -4.0f, -1.0f, -4.0f, -1.0f, 1.5f, -5.0f, 1.5f, -6.0f, 3.0f, -7.0f, 1.0f, //�����
		-6.0f, 2.9f, -5.0f, 1.0f, -0.5f, 1.0f, -2.0f, 3.5f, -6.3f, 3.5f, -7.5f, 1.0f, -7.0f, 1.0f, -6.0f, 2.9f  //�����
	};
	
	glColor3f(1.0, 0.8, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_house);
	glDrawArrays(GL_POLYGON, 0, 8);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	glColor3f(1.0, 0.0, 0.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_house);
	glDrawArrays(GL_POLYGON, 8, 8);
	glDisableClientState(GL_VERTEX_ARRAY);


	GLfloat verts_window[] = { -3.5, -0.5, -2.0, -0.5, -2.0, -2.0, -3.5, -2.0, -3.5, -0.5 };
	glColor3f(1.0, 0.9, 0.4);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_window);
	glDrawArrays(GL_POLYGON, 0, 5);
	glDisableClientState(GL_VERTEX_ARRAY);
	
	GLfloat verts_door[] = { -6.6, -0.5, -6.6, -3.2, -5.8, -3.6, -5.8, -0.4, -6.6, -0.5 };
	glColor3f(1.0, 0.9, 0.4);
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_door);
	glDrawArrays(GL_POLYGON, 0, 5);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void sun()
{
	glColor3f(1.0, 1.0, 0.0);

	GLfloat verts_sun[46];
	verts_sun[0] = x;
	verts_sun[1] = y;
	for (int i = 1; i <= triangleAmount +1; i++) {
		GLfloat _x = x + (radius * cos(i *  twicePi / triangleAmount));
		GLfloat _y = y + (radius * sin(i * twicePi / triangleAmount));
		verts_sun[i * 2] = _x;
		verts_sun[(i * 2) + 1] = _y;
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_sun);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 22);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void moon()
{
	GLfloat verts_moon[46];
	verts_moon[0] = x;
	verts_moon[1] = y;
	for (int i = 1; i <= triangleAmount + 1; i++) {
		GLfloat _x = x + (radius * cos(i *  twicePi / triangleAmount));
		GLfloat _y = y + (radius * sin(i * twicePi / triangleAmount));
		verts_moon[i * 2] = _x;
		verts_moon[(i * 2) + 1] = _y;
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_moon);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 22);
	glDisableClientState(GL_VERTEX_ARRAY);

	glColor3f(0.0, 0.0, 0.6);
	GLfloat verts_sun[46];
	verts_sun[0] = x;
	verts_sun[1] = y;
	for (int i = 1; i <= triangleAmount + 1; i++) {
		GLfloat _x = x + 0.7 + (radius * cos(i *  twicePi / triangleAmount));
		GLfloat _y = y + (radius * sin(i * twicePi / triangleAmount));
		verts_sun[i * 2] = _x;
		verts_sun[(i * 2) + 1] = _y;
	}
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, verts_sun);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 22);
	glDisableClientState(GL_VERTEX_ARRAY);
	
}


void move_x(int value)
{
	if (x > 10 + radius || x < -8 - radius)
	{
		if (nm) { nm = false; glClearColor(0.0, 0.0, 0.6, 0.0); }

		else { nm = true; glClearColor(0.0, 0.7, 1.0, 0.0); }


		x = -8;
		x_ = -7.0;
	}

	if (nm)
	{
		x += 0.1;
	}

	if (!nm)
	{
		x += 0.1;
		x_ += 0.1;
	}

	glutPostRedisplay();
	glutTimerFunc(40, move_x, 0);
}


void display2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	if (nm == true)
	{
		glClearColor(0.0, 0.7, 1.0, 0.0);
		ground();
		sun();
		glutSwapBuffers();
	}

	if (nm == false)
	{
		glClearColor(0.0, 0.0, 0.6, 0.0);
		ground();
		moon();
		glutSwapBuffers();
	}

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowSize(640, 480);				 
	glutInitWindowPosition(350, 180);
	glutCreateWindow("Project2");					
	init();

	glutDisplayFunc(display2);

	glutTimerFunc(40, move_x, 0);
	glutMainLoop();
	return 0;

}