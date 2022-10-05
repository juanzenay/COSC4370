/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/
//./script.sh
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
  double size = .15; //size of each tea pot
  double r = 0; //start

  while(r <= 360){
    glPushMatrix();//push matrix
    //start the teapots from the top of the y axis
    glRotated(90, 0, 0, 1); //rotates 90 degrees
    glRotated(r, 0, 0, 1); //rotate amount of r on z axis
    glTranslated(1.5, 0, 0); //through x, bigger x = bigger radius/spacing between pots
    glutSolidTeapot(size); //creates teapot
    glPopMatrix();
    r = r + 36;
  }
}

void problem2() {
  int cubeNum = 0; //tracks which cube we are at
  double x = -1.35; //x pos start
  double y = 0; //y pos
  double size = .2; //cube size
  double height = .1; //height of next step

  for(int i = 0; i < 21; i++){ //moving backwards
    glPushMatrix();
    glTranslated(-x, y, 0); //move on x and y
    glScaled(1, 1.5 + (cubeNum * .2), 1); //1.5 + raises the min level, cubeNum * .2 is the height
    glutSolidCube(size); //creates cube
    glPopMatrix();
    x+=.15; //spacing of cubes
    y += height * .2; //iterates through y to keep bottom of cubes level to each other
    cubeNum++;
  }
}

//6 rows, 6 pots --
//size is .15
//height by -.55
void problem3() {
  double spacing = -1.15;//start of teapot, -.2 for next row
  int num = 0; //current pot
  while (num < 6){ //for top row
    glPushMatrix();
    glTranslated(spacing, 1.1, 0); //spacing is between each teapot, 1.25 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }

  num = 0; //current pot
  spacing = -.95; //start of teapot
  while(num < 5){ //2nd row
    glPushMatrix();
    glTranslated(spacing, .55, 0); //spacing is between each teapot, .75 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }

  num = 0; //current pot
  spacing = -.75; //start of teapot
  while(num < 4){ //3rd row
    glPushMatrix();
    glTranslated(spacing, 0, 0); //spacing is between each teapot, .75 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }

  num = 0; //current pot
  spacing = -.55; //start of teapot
  while(num < 3){ //4th row
    glPushMatrix();
    glTranslated(spacing, -.55, 0); //spacing is between each teapot, .75 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }

  num = 0; //current pot
  spacing = -.35; //start of teapot
  while(num < 2){ //5th row
    glPushMatrix();
    glTranslated(spacing, -1.1, 0); //spacing is between each teapot, .75 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }

  num = 0; //current pot
  spacing = -.15; //start of teapot
  while(num < 1){ //6th row
    glPushMatrix();
    glTranslated(spacing, -1.65, 0); //spacing is between each teapot, .75 is height of row
    glutSolidTeapot(.15); //creates teapot
    glPopMatrix();
    spacing+=.45; //increment spacing
    num++; //increment num
  }
}

void problem4() { //spider, when commented shifts/rotates X, the axes are the ones being shifted/rotated
  double r = .1; //radius of cylinder
  double h = .4; //height of legs
  double ss = 30; //constant to make cylinder round

  //spider
  glPushMatrix();
  glTranslated(0,.5,0);//used to slide whole model up and down the y axis
  glutSolidSphere(.5, ss, ss);

  //eyes
  glPushMatrix();
  glTranslated(.2, 0, .4);
  glutSolidSphere(.1, ss, ss);
  
  glPushMatrix();
  glTranslated(-.4, 0, 0);
  glutSolidSphere(.1, ss, ss);
  
  glPopMatrix();
  
  glPopMatrix();

  glTranslated(0, -.8, 0); //used to slide legs up or down body together on the y axis

  //leg 1
  glPushMatrix();
  glScaled(.9,.9,.9);
  glTranslated(.2,.5,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  
  glPopMatrix();

  glPopMatrix();

  //leg 2
  glPushMatrix();
  glScaled(.9,.9,.9); //initial placement transformations
  glRotated(180, 0, 1, 0); //rotates leg
  glTranslated(0, .8, 0); //shifts leg up
  
  glTranslated(.2,-.3,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere
  
  glPopMatrix();

  glPopMatrix();
  
  //leg 3
  glPushMatrix();
  glScaled(.9,.9,.9); //initial placement transformations
  glRotated(225, 0, 1, 0); //rotates leg
  glTranslated(0, .8, 0); //shifts leg up
  
  glTranslated(.2,-.3,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere
  
  glPopMatrix();

  glPopMatrix();

  //leg 4
  glPushMatrix();
  glScaled(.9,.9,.9); //initial placement transformations
  glRotated(45, 0, 1, 0); //rotates leg
  glTranslated(0, .8, 0); //shifts leg up
  
  glTranslated(.2,-.3,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere
  
  glPopMatrix();

  glPopMatrix();

  //leg 5
  glPushMatrix();
  glScaled(.9,.9,.9); //initial placement transformations
  glRotated(45, 0, -1, 0); //rotates leg
  glTranslated(0, .8, 0); //shifts leg up
  
  glTranslated(.2,-.3,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere
  
  glPopMatrix();

  glPopMatrix();

  //leg 6
  glPushMatrix();
  glScaled(.9,.9,.9); //initial placement transformations
  glRotated(225, 0, -1, 0); //rotates leg
  glTranslated(0, .8, 0); //shifts leg up
  
  glTranslated(.2,-.3,0); //shifts cylinder to position
  glRotated(90, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere

  glPushMatrix();
  glScaled(.9,.9,.9);
  glRotated(90, 0, 0, -1); //rotates cylinder to position
  glRotated(45, 0, 1, 0); //rotates cylinder to position
  glutSolidCylinder(r, h, ss, ss); //creates cylinder
  glTranslated(0, 0, h); //shift to the right point of cylinder
  glScaled(1.1,1.1,1.1); //scale sphere up
  glutSolidSphere(r, ss, ss); //creates right sphere
  
  glPopMatrix();

  glPopMatrix();

  glPopMatrix();

}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
