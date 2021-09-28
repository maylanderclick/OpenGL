#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <cmath>
//#include <windows.h>
#include "SOIL.h"
# define PI 3.14159265358979323846
# define HEIGHT 750
# define WIDTH 750
//=)
GLfloat angle = 0;
GLfloat twicePi = 2.0f * PI;
GLfloat gap = 0;  // зазор между гранями
GLfloat light_pos[] = { 0, 0, 0, 1 };
GLfloat x = 15; GLfloat y = 15;
GLfloat x_rotate = 0; GLfloat y_rotate = 0;
GLfloat sphere_direction = 1;
bool light_status = true;
GLfloat radius = 1;

GLuint cube;
bool cube_flag = false;

bool glass = true;

int texture_mode = 0;
GLuint textures[8];

using namespace std;

void sphere()
{
	glLoadIdentity();

	glTranslatef(0, 0, -35);
	glRotatef(angle, 0, 1, 0);
	glTranslatef(0, 0, -30);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	glColor3f(0.5, 0.5, 0.1);
	glutWireSphere(radius, 20, 20);

}

void octahedron()
{

	glLoadIdentity();

	glTranslatef(0, 0, -40);
	glRotatef(y, 0, 1, 0);
	glRotatef(x, 1, 0, 0);


	GLfloat vertices[] = { -15 - gap, 0.0 + gap, 0.0 + gap, //0 передняя грань
					  0.0 - gap, 15 + gap, 0.0 + gap,  //1
					  0.0 - gap, 0.0 + gap, 15 + gap,  //2

					  0.0 + gap, 0.0 + gap, 15 + gap,  //2 правая боковая
					  0.0 + gap, 15 + gap, 0.0 + gap,  //1
					  15 + gap, 0.0 + gap, 0.0 + gap,  //3

					  15 + gap, 0.0 + gap, 0.0 - gap,  //3 задняя грань
					  0.0 + gap, 15 + gap, 0.0 - gap,  //1
					  0.0 + gap, 0.0 + gap, -15 - gap, //4

					  0.0 - gap, 0.0 + gap, -15 - gap, //4 левая боковая
					  0.0 - gap, 15 + gap, 0.0 - gap,  //1
					  -15 - gap, 0.0 + gap, 0.0 - gap, //0

					  -15 - gap, 0.0 - gap, 0.0 + gap, //0 нижняя передняя грань
					  0.0 - gap, -15 - gap, 0.0 + gap, //5
					  0.0 - gap, 0.0 - gap, 15 + gap,  //2

					  0.0 + gap, 0.0 - gap, 15 + gap,  //2 нижняя правая грань
					  0.0 + gap, -15 - gap, 0.0 + gap, //5
					  15 + gap, 0.0 - gap, 0.0 + gap,  //3

					  15 + gap, 0.0 - gap, 0.0 - gap,  //3 нижняя задняя грань
					  0.0 + gap, -15 - gap, 0.0 - gap, //5
					  0.0 + gap, 0.0 - gap, -15 - gap, //4

					  0.0 - gap, 0.0 - gap, -15 - gap, //4 нижняя левая  грань
					  0.0 - gap, -15 - gap, 0.0 - gap, //5
					  -15 - gap, 0.0 - gap, 0.0 - gap, //0
	};

	GLfloat normal[] = {
						 1, -1, -1,
						 1, -1, -1,
						 1, -1, -1,

						 -1, -1, -1,
						 -1, -1, -1,
						 -1, -1, -1,

						 -1, -1, 1,
						 -1, -1, 1,
						 -1, -1, 1,

						 1, -1, 1,
						 1, -1, 1,
						 1, -1, 1,

						 -1, -1, 1,
						 -1, -1, 1,
						 -1, -1, 1,

						 1, -1, 1,
						 1, -1, 1,
						 1, -1, 1,

						 1, 1, -1,
						 1, 1, -1,
						 1, 1, -1,

						 -1, -1, -1,
						 -1, -1, -1,
						 -1, -1, -1,
	};
	GLfloat texCoords[] = { 0.0, 0.0,  // Нижний левый угол
							1.0, 0.0,  // Нижний правый угол
							0.5, 1.0,  // верхняя центральная сторона
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0,
							0.0, 0.0,
							1.0, 0.0,
							0.5, 1.0, };

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glNormalPointer(GL_FLOAT, 0, normal);

	GLubyte front_face[] = { 0,1,2 };             // передняя грань
	GLubyte right_side[] = { 3,4,5 };             // правая грань
	GLubyte back_face[] = { 6,7,8 };              // задняя грань
	GLubyte left_side[] = { 9,10,11 };            // левая грань
	GLubyte lower_front[] = { 12,13,14 };         // нижняя передняя грань
	GLubyte bottom_right_side[] = { 15,16,17 };   // нижняя правая грань
	GLubyte lower_back_face[] = { 18,19,20 };     // нижняя задняя грань
	GLubyte bottom_left_side[] = { 21,22,23 };    // нижняя левая грань

	if (texture_mode == 0)
	{
		glEnable(GL_COLOR_MATERIAL);
		glColor4f(0.2, 0.2, 1.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glColor4f(1.0, 0.5, 1.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glColor4f(1.0, 1.0, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glColor4f(1.0, 0.4, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glColor4f(0.1, 0.6, 1.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glColor4f(0.5, 0.1, 0.4, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glColor4f(1.0, 0.3, 0.3, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glColor4f(1.0, 0.0, 0.0, 0.5);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
	}
	if (texture_mode == 2)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
		glDisable(GL_TEXTURE_2D);
	}
	if (texture_mode == 1)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, textures[0]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_back_face);
		glBindTexture(GL_TEXTURE_2D, textures[1]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_left_side);
		glBindTexture(GL_TEXTURE_2D, textures[2]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, bottom_right_side);
		glBindTexture(GL_TEXTURE_2D, textures[3]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, lower_front);
		glBindTexture(GL_TEXTURE_2D, textures[4]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, back_face);
		glBindTexture(GL_TEXTURE_2D, textures[5]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, front_face);
		glBindTexture(GL_TEXTURE_2D, textures[6]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, right_side);
		glBindTexture(GL_TEXTURE_2D, textures[7]);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_BYTE, left_side);
		glDisable(GL_TEXTURE_2D);
	}
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void rotation(int)
{
    if (sphere_direction != 0)
	    angle += sphere_direction;
	/*if (angle > 360)
		angle -= 360;
	sphere_direction = true;*/

	x += x_rotate;
	y += y_rotate;

	glutPostRedisplay();
	glutTimerFunc(20, rotation, 0);
}

void reshape(GLsizei w, GLsizei h) {
	// предупредим деление на ноль
	// если окно сильно перетянуто будет
	if (h == 0)
		h = 1;

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(110, (GLdouble)w / h, 1, 100); //насколько широко открыто око камеры 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void display()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (!glass)
	{
		glEnable(GL_BLEND);
		glDepthMask(GL_FALSE);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	else
	{
		glDepthMask(GL_TRUE);
		glDisable(GL_BLEND);
	}

	glColor4f(1, 1, 1, 0.5);
	octahedron();

	//glColor4f(1, 1, 1, 0.5);
	if (cube_flag)
		glCallList(cube);


	sphere();
	/*octahedron();*/


	//glFlush();
	glutSwapBuffers();
}

void draw_cube() {			
	
	glNewList(cube, GL_COMPILE);
	glColor4f(1, 0, 0, 1.0);
	for (int i = 0; i < 22; i++) {
		glBegin(GL_LINE_LOOP);
		glVertex3f(-20, 20 - i * 1.8, 20);
		glVertex3f(20, 20 - i * 1.8, 20);
		glVertex3f(20, 20 - i * 1.8, -20);
		glVertex3f(-20, 20 - i * 1.8, -20);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(20 - i * 1.8, 20, 20);
		glVertex3f(20 - i * 1.8, -20, 20);
		glVertex3f(20 - i * 1.8, -20, -20);
		glVertex3f(20 - i * 1.8, 20, -20);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex3f(-20, 20, 20 - i * 1.8);
		glVertex3f(20, 20, 20 - i * 1.8);
		glVertex3f(20, -20, 20 - i * 1.8);
		glVertex3f(-20, -20, 20 - i * 1.8);
		glEnd();

	}
	glEndList();
}


void information()
{
	setlocale(LC_ALL, "Russian");
	cout
		<< "a - вращение октаэдра по часовой стрелке" << endl
		<< "d - вращение октаэдра против часовой стрелки" << endl
		<< "w - вращение октаэдра вверх" << endl
		<< "s - вращение октаэдра вниз" << endl
		<< "z/x/q - остановить вращение 'вверх/внизэ'/'против/по часовой стрелки'/ вращение октаэдра и сферы" << endl
		<< "r  - раздвинуть/сдвинуть грани октаэдра" << endl
		<< "e - смена направления движения сферы" << endl
		<< "l - включить/выключить свет" << endl
		<< "v - включить/выключить куб" << endl
		<< "t - переключить текстуры" << endl
		<< "c - включить/выключить прозрачность" << endl;
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);

	switch (key)
	{
	case 'a':  x_rotate = -1;
		break;
	case 'd': x_rotate = 1;
		break;
	case 'z': x_rotate = 0;
		break;
	case 'w': y_rotate = 1;
		break;
	case 's': y_rotate = -1;
		break;
	case 'x': y_rotate = 0;
		break;
	case 'q': x_rotate = 0; y_rotate = 0;// sphere_direction = 0;
		break;
	case 'r': if (gap == 0) gap = 5;
			  else gap = 0;
		break;
	case 'e': if (sphere_direction >= 0) { sphere_direction--; }
			  else sphere_direction = 1;
		break;
	case 'l': if (light_status) glDisable(GL_LIGHT0);
			  else glEnable(GL_LIGHT0);
		light_status = !light_status;
		break;
	case 'c': glass = !glass;
		break;
	case 'v':
		cube_flag = !cube_flag;
		break;
	case 't':
		if (texture_mode == 2)
		{
			//glDisable(GL_TEXTURE_2D);
			texture_mode = 0;
		}
		else
		{
			//glEnable(GL_TEXTURE_2D); 
			texture_mode++;
		}
		std::cout << texture_mode << std::endl;
		break;
	}
}


void processSpecialKeys(int key, int x, int y)
{
	switch (key)
	{
    case GLUT_KEY_LEFT:
        if(sphere_direction != 0)
        {
           sphere_direction = 0;
        }
         angle==360?angle=5:angle-=5;
        break;
    case GLUT_KEY_RIGHT:
       if(sphere_direction != 0)
        {
           sphere_direction = 0;
        }
         angle==360?angle=5:angle+=5;
        break;
	case GLUT_KEY_UP:
	{
		if (gap < 5)
		{
			gap++;
			glutPostRedisplay();
			break;
		}
		else
			break;
	}
	case GLUT_KEY_DOWN:
	{
		if (gap > 0)
		{
			gap--;
			glutPostRedisplay();
			break;
		}
		else
			break;
	}
	}
}

//остановить начальные характеристики окна
//зарегистрировать дисплейную функцию обратного вызова
//войти в главный цикл
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //инициализация дисплея
													//сообщаем, как будем рисовать
													//GLUT_SINGLE - статическа¤ картинка цветами GLUT_RGB - красный зеленый синий
	glutInitWindowSize(WIDTH, HEIGHT);				 //размеры окна
	glutInitWindowPosition(250, 60);
	glutCreateWindow("Project7");					//создает окно

	information();

	cube = glGenLists(1);
	draw_cube();

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutTimerFunc(20, rotation, 0);
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	int width[8];
	int height[8];
	unsigned char* image[8];
	if (!image)
		std::cout << "Error: SOIL_load_image";
	glGenTextures(8, textures);

	unsigned char* image0 = SOIL_load_image("texture_1.bmp", &width[0], &height[0], 0, SOIL_LOAD_RGB);
	unsigned char* image1 = SOIL_load_image("texture_2.bmp", &width[1], &height[1], 0, SOIL_LOAD_RGB);
	unsigned char* image2 = SOIL_load_image("texture_3.bmp", &width[2], &height[2], 0, SOIL_LOAD_RGB);
	unsigned char* image3 = SOIL_load_image("texture_4.bmp", &width[3], &height[3], 0, SOIL_LOAD_RGB);
	unsigned char* image4 = SOIL_load_image("texture_5.bmp", &width[4], &height[4], 0, SOIL_LOAD_RGB);
	unsigned char* image5 = SOIL_load_image("texture_6.bmp", &width[5], &height[5], 0, SOIL_LOAD_RGB);
	unsigned char* image6 = SOIL_load_image("texture_7.bmp", &width[6], &height[6], 0, SOIL_LOAD_RGB);
	unsigned char* image7 = SOIL_load_image("texture_8.bmp", &width[7], &height[7], 0, SOIL_LOAD_RGB);

	unsigned char* images[8] = { image0, image1, image2, image3, image4, image5, image6, image7 };

	for (int i = 0; i < 8; i++) {
		glBindTexture(GL_TEXTURE_2D, textures[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width[i], height[i], 0, GL_RGB, GL_UNSIGNED_BYTE, images[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	}
	for (int i = 0; i < 8; i++)
	{
		SOIL_free_image_data(images[i]);
	}

	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);


	glutMainLoop();
	return 0;
}