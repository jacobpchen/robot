#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <iostream>

using namespace std;

// Global vars
double x, y, z;           // current robot position (initialized in main)

// Handle the menu choice
int state;

// Smooth vs flat



void setMaterial(GLfloat ambientR, GLfloat ambientG, GLfloat ambientB,
	GLfloat diffuseR, GLfloat diffuseG, GLfloat diffuseB,
	GLfloat specularR, GLfloat specularG, GLfloat specularB,
	GLfloat shininess) {

	GLfloat ambient[] = { ambientR, ambientG, ambientB };
	GLfloat diffuse[] = { diffuseR, diffuseG, diffuseB };
	GLfloat specular[] = { specularR, specularG, specularB };

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
}

void timer(int value) {
	float angle = 0;
	angle += 1.0f;
	if (angle > 360)
		angle -= 360;
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void drawSphere()
{
	glutSolidSphere(.1, 16, 16);
}

void drawCube() {
	glutSolidCube(.1);
}

void drawCone() {
	glRotatef(270, 1, 0, 0);
	glutSolidCone(.2, .5, 20, 20);
}






// Draws right arm, hand, leg, and foot
//
void drawRightSideAppendages(int z)
{	
	glPushMatrix(); // right arm
	setMaterial(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4); // gold
	glTranslatef(0.40f, 0.7f, 0.0f);
	glRotatef(35, 0, 0, 1);
	glScalef(0.5f, 4.0f, 0.5f);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // right hand
	setMaterial(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273, 0.4); // silver
	glTranslatef(0.69f, 0.28f, 0.0f);
	glRotatef(z, 0, 0, 1);
	//drawSphere();
	drawCube();
	glPopMatrix();
	glPushMatrix(); // right thigh
	setMaterial(0.24725, 0.1995, 0.0745, 0.75164, 0.60648, 0.22648, 0.628281, 0.555802, 0.366065, 0.4); // gold
	glTranslatef(0.2f, -0.4f, 0.0f);
	glRotatef(15, 0, 0, 1);
	glScalef(0.5f, 3.0f, 0.5f);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // right shin
	glTranslatef(0.3f, -0.985f, 0.0f);
	glRotatef(6, 0, 0, 1);
	glScalef(0.5f, 3.0f, 0.5f);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // right foot
	setMaterial(0.19225, 0.19225, 0.19225, 0.50754, 0.50754, 0.50754, 0.508273, 0.508273, 0.508273, 0.4); // silver
	glTranslatef(0.33f, -1.40f, 0.0f);
	glRotatef(z, 0, 0, 1);
	//drawSphere();
	drawCube();
	glPopMatrix();	
} 

// drawRightSideAppendages
// draws the desired robot object
//
void drawRobot()
{
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); // head
	setMaterial(0.25, 0.20725, 0.20725, 1, 0.829, 0.829, 0.296648, 0.296648, 0.296648, 0.088); // pearl
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	drawSphere();
	glPopMatrix();

	glPushMatrix(); // body
	setMaterial(0.135, 0.2225, 0.1575, 0.54 , 0.89, 0.63, .316228, 0.316228, 0.316228, 0.1); // jade
	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(2.5f, 7.0f, 2.5f);
	drawSphere();
	glPopMatrix();

	drawRightSideAppendages(z);
	// use reflection to draw the left side appendages
	//
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages(z);
	glPopMatrix();

	//glRotatef(10, 0, .2, 0);	// rotate whole robot
	z += 10;
	glFlush();
}

void drawRobotNoRotation() {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); // head
	setMaterial(0.25, 0.20725, 0.20725, 1, 0.829, 0.829, 0.296648, 0.296648, 0.296648, 0.088); // pearl
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	drawSphere();
	glPopMatrix();

	glPushMatrix(); // body
	setMaterial(0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, .316228, 0.316228, 0.316228, 0.1); // jade
	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(2.5f, 7.0f, 2.5f);
	drawSphere();
	glPopMatrix();

	drawRightSideAppendages(z);
	// use reflection to draw the left side appendages
	//
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages(z);
	glPopMatrix();

	//glRotatef(10, 0, .2, 0);	// rotate whole robot
	z += 0;
	glFlush();
}

void drawPartyHatRobot() {
	/* clear window */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* future matrix manipulations should affect the modelview matrix */
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix(); // head
	setMaterial(0.25, 0.20725, 0.20725, 1, 0.829, 0.829, 0.296648, 0.296648, 0.296648, 0.088); // pearl
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	drawSphere();
	glPopMatrix();
	
	glPushMatrix(); // party hat
	setMaterial(0.05, 0.0, 0.0, 0.5, 0.4, 0.4, 0.7, 0.04, 0.04, .078125);	// red plastic
	glTranslatef(0.0f, 1.75f, 0.0f);
	glScalef(1, 1, 1);
	drawCone();
	glPopMatrix();

	glPushMatrix(); // body
	setMaterial(0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, .316228, 0.316228, 0.316228, 0.1); // jade
	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(2.5f, 7.0f, 2.5f);
	drawSphere();
	glPopMatrix();

	drawRightSideAppendages(z);
	// use reflection to draw the left side appendages
	//
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages(z);
	glPopMatrix();

	glRotatef(10, 0, 1, 0);
	
	glFlush();
}

void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}

void mainMenuHandler(int choice) {
	switch (choice) {
	case 1:
		state = 1;
		//drawRobot();
		cout << state << endl;
		break;
	case 2:
		state = 2;
		//drawRobotNoRotation();
		break;
	case 3:
		state = 3;
		//drawPartyHatRobot();
		break;
	case 4:
		state = 4;
		break;
	case 5:
		state = 5;
		break;
	}
}


void display(void) {
	//drawRobot();
	//drawRobotNoRotation();
	//drawPartyHatRobot();

	if (state == 1)
		drawRobot();
	else if (state == 2)
		drawRobotNoRotation();
	else if (state == 3)
		drawPartyHatRobot();
	else if (state == 4)
		glShadeModel(GL_SMOOTH);
	else if (state == 5)
		glShadeModel(GL_FLAT);
	else
		drawRobot();
	
}

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightpos[] = { 0.0, 0.0, -4.0 };
	GLfloat lightcolor[] = { 1.0, 1.0, 1.0 };
	GLfloat ambcolor[] = { 0.0, 0.0, 1.0 };

	glEnable(GL_LIGHTING);                               // enable lighting
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambcolor);     // ambient light

	glEnable(GL_LIGHT0);                                 // enable light source
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);           // config light source
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightcolor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightcolor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightcolor);

	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST); // for hidden surface removal
	glEnable(GL_NORMALIZE); // normalize vectors for proper shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f); // background is light gray
	glViewport(0, 0, 640, 480);
	
	glutCreateMenu(mainMenuHandler);
	//glutAddSubMenu("Change Color", subMenu);
	glutAddMenuEntry("Hands and Feet Rotation", 1);
	glutAddMenuEntry("Stop Rotation", 2);
	glutAddMenuEntry("Party Mode!", 3);
	glutAddMenuEntry("Smooth Shading Model", 4);
	glutAddMenuEntry("Flat Shading Model", 5);
	glutAddMenuEntry("Exit", 6);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutTimerFunc(1400, timer, 1);



	glutMainLoop();
}