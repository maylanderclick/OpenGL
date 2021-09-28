#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
# define PI 3.14159265358979323846

GLfloat x = -8.0; GLfloat y = 7.0; GLfloat radius = 2.0;
int triangleAmount = 20;
GLfloat twicePi = 2.0f * PI;
bool nm = false;
GLfloat x_ = -7.0;


void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0); 
}

void ground() 
{
	if (nm) { glColor3f(0.0, 1.0, 0.0); }
	else { glColor3f(0.0, 1.0, 0.5); }
	
	glBegin(GL_QUADS);
	glVertex2f(-10.0, -2.0);
	glVertex2f(-10.0, -10.0);
	glVertex2f(10.0, -10.0);
	glVertex2f(10.0, -2.0);
	glEnd();

	glColor3f(1.0, 0.8, 0.0);
	
	glBegin(GL_POLYGON);
	glVertex2f(-7.0, 1.0);
	glVertex2f(-7.0, -3.0);
	glVertex2f(-5.0, -4.0);
	glVertex2f(-5.0, 1.5);
	glVertex2f(-6.0, 3.0);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-5.0, 1.5);
	glVertex2f(-5.0, -4.0);
	glVertex2f(-1.0, -4.0);
	glVertex2f(-1.0, 1.5);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(-7.5, 1.0);
	glVertex2f(-7.0, 1.0);
	glVertex2f(-6.0, 3.0);
	//glVertex2f(-6.0, 3.5);
	glVertex2f(-6.3, 3.5);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-5.0, 1.0);
	glVertex2f(-0.5, 1.0);
	glVertex2f(-2.0, 3.5);
	glVertex2f(-6.3, 3.5);
	glEnd();

	glColor3f(1.0, 0.9, 0.4);
	glBegin(GL_QUADS);
	glVertex2f(-3.5, -0.5);
	glVertex2f(-2.0, -0.5);
	glVertex2f(-2.0, -2.0);
	glVertex2f(-3.5, -2.0);
	glEnd();

	glColor3f(1.0, 0.7, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-6.6, -0.5);
	glVertex2f(-6.6, -3.2);
	glVertex2f(-5.8, -3.6);
	glVertex2f(-5.8, -0.4);
	glEnd();


	glColor3f(1.0, 0.6, 0.0);

	glBegin(GL_LINES);
	glVertex2f(-6.6, -0.5);
	glVertex2f(-6.6, -3.2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-6.3, -0.4);
	glVertex2f(-6.3, -3.4);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-5.8, -3.6);
	glVertex2f(-5.8, -0.4);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-5.8, -0.4);
	glVertex2f(-6.6, -0.5);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex2f(-7.5, 1.0);
	glVertex2f(-7.0, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-6.3, 3.5);
	glVertex2f(-5.0, 1.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-3.5, -0.5);
	glVertex2f(-2.0, -0.5);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-3.5, -0.5);
	glVertex2f(-3.5, -2.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-3.5, -2.0);
	glVertex2f(-2.0, -2.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-2.0, -2.0);
	glVertex2f(-2.0, -0.5);
	glEnd();


	glBegin(GL_LINES);
	glVertex2f(-2.7, -2.0);
	glVertex2f(-2.7, -0.5);
	glEnd();

	glColor3f(1.0, 0.7, 0.0);

	glBegin(GL_LINES);
	glVertex2f(-5.0, 1.0);
	glVertex2f(-5.0, -4.0);
	glEnd();

}

void sun()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(x, y); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

void moon()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(x, y); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.6);
	glVertex2f(x_, y); // center of circle
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x_ + 0.7 + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

//void sun_(int value)
//{
//	x += 0.1;
//	glutPostRedisplay();
//	glutTimerFunc(100, sun_, 0);
//}
//
//void moon_(int value)
//{
//	x += 0.1;
//	x_ += 0.2;
//	glutPostRedisplay();
//	glutTimerFunc(100, moon_, 0);
//}
//
//void display()
//{

//	//������� ������� (���������) ����
//	glClearColor(0.0, 0.7, 1.0, 0.0);
//	//�������� ����� glClear(GL_COLOR_BUFFER_BIT);
//	glClear(GL_COLOR_BUFFER_BIT);
//	sun();
//	ground();
//	
//	glutSwapBuffers();
//}
//
//void display1()
//{
//	//������� ������� (���������) ����
//	glClearColor(0.0, 0.0, 0.6, 0.0);
//	//�������� ����� glClear(GL_COLOR_BUFFER_BIT);
//	glClear(GL_COLOR_BUFFER_BIT);
//	moon();
//	ground();
//
//	glutSwapBuffers();
//}

void move(int value)
{
	if (x > 10 + radius || x < -8 - radius)   
	{
		if (nm) { nm = false; }
		else { nm = true;}

		x = -8;
		x_ = -7.0;
	}

	if (nm)  //движение солнца
	{
		x += 0.1;
	}

	if (!nm) //движение луны
	{
		x += 0.1;
		x_ += 0.1;
	}

	glutPostRedisplay();
	glutTimerFunc(40, move, 0);
}

void display()
{
	
	if (nm)
	{
		glClearColor(0.0, 0.7, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		ground();
		sun();
		glutSwapBuffers();
	}

	if (!nm)
	{
		glClearColor(0.0, 0.0, 0.6, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
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
	glutCreateWindow("Project");					
	init();
	glutDisplayFunc(display);
	glutTimerFunc(40, move, 0);

	glutMainLoop();
	return 0;

}