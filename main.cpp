#include <gl/glut.h>
#include <math.h>
#include<stdio.h>
#include<conio.h>
#include <iostream>
#include<vector>
#include <bits/stdc++.h>
#define PI 3.141592654

using namespace std;

struct Point {
	int x;
	int y;
};

struct Shape {
	vector<float> x;
	vector<float> y;
};
struct Shape Sh;

Point p1, p2;
int decision;
void draw_dda(Point p1, Point p2) {

	//printf("sin 30 degree = %f", sin(-30*PI/180));
	glColor3f(0.0f, 0.0f, 0.0f);

	Sh.x.clear();
	Sh.y.clear();


	//glClear(GL_COLOR_BUFFER_BIT);
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if (abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else {
		step = abs(dy);
	}

	GLfloat xInc = dx / step;
	GLfloat yInc = dy / step;

	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (float i = 1; i <= step; i++) {
		Sh.x.push_back(x1);
		Sh.y.push_back(y1);

		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}


	/*
	printf("P1_x %d p1_y %d\n", p1.x,p1.y);
	for(int w=0; w< Sh.x.size(); w++)
		{
			//glVertex2i(Sh.x[w]+100, Sh.y[w]+100);
			printf("line points x %f y %f \n",Sh.x[w],Sh.y[w]);
		}
	printf("P2_x %d p2_y %d\n", p2.x,p2.y);
	*/
	glEnd();
	//glFlush();
}

void Midpoint_circle(Point p1, Point p2)
{
    glColor3f(0.0f, 0.0f, 0.0f);
	Sh.x.clear();
	Sh.y.clear();

	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int radious = (int)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	int d = 1 - 1 * radious;
	int x = 0, y = radious;
	//cout << "Midpoint circle.";
	while (x <= y)
	{
		Sh.x.push_back(p1.x + x);
		Sh.y.push_back(p1.y + y);
		glVertex2i(p1.x + x, p1.y + y);

		Sh.x.push_back(p1.x + x);
		Sh.y.push_back(p1.y - y);
		glVertex2i(p1.x + x, p1.y - y);

		Sh.x.push_back(p1.x - x);
		Sh.y.push_back(p1.y + y);
		glVertex2i(p1.x - x, p1.y + y);

		Sh.x.push_back(p1.x - x);
		Sh.y.push_back(p1.y - y);
		glVertex2i(p1.x - x, p1.y - y);

		Sh.x.push_back(p1.x + y);
		Sh.y.push_back(p1.y + x);
		glVertex2i(p1.x + y, p1.y + x);

		Sh.x.push_back(p1.x + y);
		Sh.y.push_back(p1.y - x);
		glVertex2i(p1.x + y, p1.y - x);

		Sh.x.push_back(p1.x - y);
		Sh.y.push_back(p1.y + x);
		glVertex2i(p1.x - y, p1.y + x);

		Sh.x.push_back(p1.x - y);
		Sh.y.push_back(p1.y - x);
		glVertex2i(p1.x - y, p1.y - x);

		if (d < 0)
		{
			d = d + 2 * x + 3;
		}
		else
		{
			d = d + 2 * (x - y) + 10 / 2;
			y--;
		}
		x++;
	}

	glEnd();
	//glFlush();
}

void Bresenham_circle(Point p1, Point p2)
{

    glColor3f(0.0f, 0.0f, 0.0f);
	Sh.x.clear();
	Sh.y.clear();

	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int radious = (int)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	int d = 3 - 2 * radious;
	int x = 0, y = radious;
	while (x <= y)
	{

		Sh.x.push_back(p1.x + x);
		Sh.y.push_back(p1.y + y);
		glVertex2i(p1.x + x, p1.y + y);

		Sh.x.push_back(p1.x + x);
		Sh.y.push_back(p1.y - y);
		glVertex2i(p1.x + x, p1.y - y);

		Sh.x.push_back(p1.x - x);
		Sh.y.push_back(p1.y + y);
		glVertex2i(p1.x - x, p1.y + y);

		Sh.x.push_back(p1.x - x);
		Sh.y.push_back(p1.y - y);
		glVertex2i(p1.x - x, p1.y - y);

		Sh.x.push_back(p1.x + y);
		Sh.y.push_back(p1.y + x);
		glVertex2i(p1.x + y, p1.y + x);

		Sh.x.push_back(p1.x + y);
		Sh.y.push_back(p1.y - x);
		glVertex2i(p1.x + y, p1.y - x);

		Sh.x.push_back(p1.x - y);
		Sh.y.push_back(p1.y + x);
		glVertex2i(p1.x - y, p1.y + x);

		Sh.x.push_back(p1.x - y);
		Sh.y.push_back(p1.y - x);
		glVertex2i(p1.x - y, p1.y - x);

		if (d < 0)
		{
			d = d + 4 * x + 6;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	glEnd();
	int akash = 0;
	//glFlush();
}

void Bresenham_line(Point p1, Point p2)
{
    glColor3f(0.0f, 0.0f, 0.0f);
	Sh.x.clear();
	Sh.y.clear();


	//glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	int dx = abs(p2.x - p1.x);
	int dy = abs(p2.y - p1.y);
	float m = float(p2.y - p1.y) / float(p2.x - p1.x);
	if (m >= 0 && m <= 1)
	{
		/*
		234 348
485 278
		*/


		int d = 2 * dy - dx;
		int ds = 2 * dy;
		int dt = 2 * (dy - dx);
		//float m = (float)dy / (float)dx;
		int xn, yn, xend, yend;
		xn = p1.x;
		yn = p1.y;
		xend = p2.x;
		if (p2.x < p1.x)
		{
			xn = p2.x;
			yn = p2.y;
			xend = p1.x;
		}
		d = 2 * dy - dx;

		Sh.x.push_back(xn);
		Sh.y.push_back(yn);

		glVertex2i(xn, yn);
		while (xn < xend)
		{
			xn++;
			if (d < 0)
			{
				d += ds;
			}
			else
			{
				yn++;
				d += dt;
			}

			Sh.x.push_back(xn);
			Sh.y.push_back(yn);
			glVertex2i(xn, yn);
		}
	}
	else if (m > 1)
	{
		int d = 2 * dy - dx;
		int ds = 2 * dy;
		int dt = 2 * (dy - dx);
		//float m = (float)dy / (float)dx;
		int xn, yn, xend, yend;
		xn = p1.x;
		yn = p1.y;
		yend = p2.y;
		if (p2.y < p1.y)
		{
			xn = p2.x;
			yn = p2.y;
			yend = p1.y;
		}

		Sh.x.push_back(xn);
		Sh.y.push_back(yn);

		glVertex2i(xn, yn);
		d = 2 * dx - dy;

		ds = 2 * dx;
		dt = 2 * dx - 2 * dy;
		while (yn < yend)
		{
			yn++;
			if (d < 0)
			{
				d += ds;
			}
			else
			{
				xn++;
				d += dt;
			}

			Sh.x.push_back(xn);
			Sh.y.push_back(yn);
			glVertex2i(xn, yn);
		}
	}
	else if (m <= -1)
	{

		if (dx >= 0)
		{
			dx = dx * (-1);
		}

		//float m = (float)dy / (float)dx;
		int xn, yn, xend, yend;
		xn = p1.x;
		yn = p1.y;
		yend = p2.y;
		int d = -2 * dx - dy;
		if (p2.y < p1.y)
		{
			xn = p2.x;
			yn = p2.y;
			yend = p1.y;
		}
		int ds = -2 * dx;
		int dt = -2 * dx - 2 * dy;

		Sh.x.push_back(xn);
		Sh.y.push_back(yn);
		glVertex2i(xn, yn);
		while (yn < yend)
		{
			yn++;
			if (d < 0)
			{
				d += ds;
			}
			else
			{
				xn--;
				d += dt;
			}

			Sh.x.push_back(xn);
			Sh.y.push_back(yn);
			glVertex2i(xn, yn);
		}

	}
	else
	{
		if (dx >= 0)
		{
			dx = dx * (-1);
		}
		int d = +2 * dy + dx;
		int xn = p1.x;
		int yn = p1.y;
		int xend = p2.x;
		if (p2.x > p1.x)
		{
			xn = p2.x;
			yn = p2.y;
			xend = p1.x;
		}

		Sh.x.push_back(xn);
		Sh.y.push_back(yn);
		glVertex2i(xn, yn);
		int ds = +2 * dy;
		int dt = +2 * dy + 2 * dx;
		while (xn > xend)
		{
			xn--;
			if (d < 0)
			{
				d += ds;
			}
			else
			{
				yn++;
				d += dt;
			}

			Sh.x.push_back(xn);
			Sh.y.push_back(yn);
			glVertex2i(xn, yn);
		}
	}
	glEnd();
	//glFlush();
}




void Translate(Point p1, Point p2)
{
	if (p1.x == p2.x && p1.y == p2.y)
	{
		printf("root point :%d %d AND %d %d\n", p1.x, p1.y, p2.x, p2.y);
		printf("translate point :%f %f\n", Sh.x[0], Sh.y[0]);
		float translate_x = p2.x - Sh.x[0];
		float translate_y = p2.y - Sh.y[0];

		printf("translation distance x %f y %f \n", translate_x, translate_x);

		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 0.0f);

		for (int r = 0; r < Sh.x.size(); r++)
		{

			glVertex2i(Sh.x[r], Sh.y[r]);
		}


        glColor3f(0.0f, 0.0f, 1.0f);
		for (int r = 0; r < Sh.x.size(); r++)
		{

			glVertex2i(Sh.x[r] + translate_x, Sh.y[r] + translate_y);
		}

	}

	glEnd();
}





void Rotate()
{
	int T;
	float xp;
	float yp;
	float h, k;

	h = Sh.x[0];
	k = Sh.y[0];
	//scanf("Please enter the angle of rotation in degree: %d",&T );
	cout << "Please enter the angle of rotation in degree: ";
	cin >> T;
	glBegin(GL_POINTS);

	glColor3f(0.0f, 0.0f, 0.0f);
	for (int r = 0; r < Sh.x.size(); r++)
	{

		glVertex2i(Sh.x[r], Sh.y[r]);
	}

    glColor3f(0.0f, 0.0f, 1.0f);
	for (int r = 0; r < Sh.x.size(); r++)
	{

		xp = Sh.x[r] * cos(T * PI / 180) - Sh.y[r] * sin(T * PI / 180) - h * cos(T * PI / 180) + k * sin(T * PI / 180) + h;
		yp = Sh.x[r] * sin(T * PI / 180) + Sh.y[r] * cos(T * PI / 180) - h * sin(T * PI / 180) - k * cos(T * PI / 180) + k;
		glVertex2i(xp, yp);
	}

	glEnd();
}


void Scale()
{
	float Sx, Sy;
	float xp;
	float yp;
	float h, k;

	h = Sh.x[0];
	k = Sh.y[0];

	cout << "Please enter the scaling factor Sx :";
	cin >> Sx;
	cout << "\nPlease enter the scaling factor Sy :";
	cin >> Sy;

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);

	for (int r = 0; r < Sh.x.size(); r++)
	{
		glVertex2i(Sh.x[r], Sh.y[r]);
	}

    glColor3f(0.0f, 0.0f, 1.0f);
	for (int r = 0; r < Sh.x.size(); r++)
	{
		xp = Sh.x[r] * Sx - Sx * h + h;
		yp = Sh.y[r] * Sy - Sy * k + k;
		glVertex2i(xp, yp);
	}

	glEnd();
}


void mirror(){

	// 0 , 640
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	int i;
	for (i = 0; i <= 640; i++)
	{
		glVertex2i(i , 240);
	}

	for (i = -50; i <= 480; i++)
	{
		glVertex2i(320, i);
	}

	for (int r = 0; r < Sh.x.size(); r++)
	{
		glVertex2i(Sh.x[r], Sh.y[r]);
	}

	glColor3f(0.0f, 0.0f, 1.0f);

	for (i = 0; i < Sh.x.size(); i++)
	{
		if (Sh.y[i] > 240)
		{
			glVertex2i(Sh.x[i], 240 - (Sh.y[i] - 240));
		}
		else if (Sh.y[i] < 240)
		{
			glVertex2i(Sh.x[i], 240 + (240 - Sh.y[i]));
		}
	}


	for (i = 0; i < Sh.x.size(); i++)
	{
		if (Sh.x[i] > 320)
		{
			glVertex2i( 320 - (  Sh.x[i] - 320 ) ,  Sh.y[i] );
		}
		else if (Sh.x[i] < 320)
		{
			glVertex2i( 320 + ( 320 - Sh.x[i] )  ,  Sh.y[i] );
		}
	}

	glEnd();

}

void draw_dda_box(Point p1, Point p2) {




	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if (abs(dx) > abs(dy)) {
		step = abs(dx);
	}
	else {
		step = abs(dy);
	}

	GLfloat xInc = dx / step;
	GLfloat yInc = dy / step;

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	for (float i = 1; i <= step; i++) {
		Sh.x.push_back(x1);
		Sh.y.push_back(y1);

		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}

	//glEnd();

}

void Box(Point p1, Point p2)
{

	Sh.x.clear();
	Sh.y.clear();

	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;

	p2.y = y1;
	draw_dda_box(p1, p2);

	p1.x = x2;
	p2.y = y2;
	draw_dda_box(p1, p2);

	p1.x = x2;
	p1.y = y2;
	p2.x = x1;
	p2.y = y2;
	draw_dda_box(p1, p2);

	p1.x = x1;
	p1.y = y2;
	p2.x = x1;
	p2.y = y1;
	draw_dda_box(p1, p2);

	glEnd();
}



void myMouseFunc(int button, int state, int x, int y)
{

	int d;
	bool b = 1;

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		p1.x = x;
		p1.y = 480 - y;

		cout << x << " " << y << "\n";
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		p2.x = x;
		p2.y = 480 - y;

		cout << x << " " << y << "\n";
		b = 0;
		//draw_dda(p1, p2);
	}

	if (b == 0)
	{


		//draw_dda(p1, p2);
		if (decision == 1)
			draw_dda(p1, p2);
		else if (decision == 2)
		{
			Bresenham_line(p1, p2);
		}
		else if (decision == 3)
		{
			Bresenham_circle(p1, p2);
		}
		else if (decision == 4)
		{
			Midpoint_circle(p1, p2);
		}
		else if (decision == 5)
		{
			//printf("root point before translate func :%d %d AND %d %d\n",p1.x,p1.y,p2.x,p2.y);
			Translate(p1, p2);
		}
		else if (decision == 6)
		{
			Rotate();
		}
		else if (decision == 7)
		{
			Scale();
		}
		else if (decision == 8)
		{
			Box(p1, p2);
		}
		else if (decision == 9)
		{
			mirror();
		}
	}

}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	//glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}



void display()
{
	glFlush();
}

void mainMenuHandler(int c)
{
	glClear(GL_COLOR_BUFFER_BIT);
	decision = c;

	glutMouseFunc(myMouseFunc);





}




int main(int argc, char** argv) {

	//cout << "What do you want to draw: \n1.Bresenham Line\n2.Bresenham Circle\n3.Midpoint Circle\n4.DDA Line\n";
	//cin >> decision;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	//glutMouseFunc(myMouseFunc);
	init();

	glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("1.DDA Line", 1);
	glutAddMenuEntry("2.Bresenham Line", 2);
	glutAddMenuEntry("3.Bresenham Circle", 3);
	glutAddMenuEntry("4.Midpoint Circle", 4);
	glutAddMenuEntry("5.Translation", 5);
	glutAddMenuEntry("6.Rotation", 6);
	glutAddMenuEntry("7.Scaling", 7);
	glutAddMenuEntry("8.Box", 8);
	glutAddMenuEntry("9.Mirror", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	//cout << "\n";
	_getch();
	return 0;
}
