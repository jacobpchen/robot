#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

double x, y, z;           // current robot position (initialized in main)

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

void drawSphere()
{
	glutSolidSphere(.1, 16, 16);
}

// Draws right arm, hand, leg, and foot
//
void drawRightSideAppendages()
{
	glPushMatrix(); // right arm
	glTranslatef(0.40f, 0.7f, 0.0f);
	glRotatef(35, 0, 0, 1);
	glScalef(0.5f, 4.0f, 0.5f);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // right hand
	glTranslatef(0.69f, 0.28f, 0.0f);
	//glRotatef(feetAndHandsRotation[Z], 0, 0, 1);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // right thigh
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
	glTranslatef(0.33f, -1.40f, 0.0f);
	//glRotatef(feetAndHandsRotation[Z], 0, 0, 1);
	drawSphere();
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
	glTranslatef(0.0f, 1.5f, 0.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	drawSphere();
	glPopMatrix();
	glPushMatrix(); // body
	glTranslatef(0.0f, 0.5f, 0.0f);
	glScalef(2.5f, 7.0f, 2.5f);
	drawSphere();
	glPopMatrix();
	drawRightSideAppendages();
	// use reflection to draw the left side appendages
	//
	glPushMatrix();
	glScalef(-1.0, 1.0, 1.0);
	drawRightSideAppendages();
	glPopMatrix();

	glFlush();
}

void reshape(int width, int height) {
	/* define the viewport transformation */
	glViewport(0, 0, width, height);
}

//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot");
	glutDisplayFunc(drawRobot);
	glutReshapeFunc(reshape);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);
	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	/* define the projection transformation */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, 1, 4, 20);
	/* define the viewing transformation */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	
	glEnable(GL_LIGHTING); // enable the light source
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); // for hidden surface removal
	glEnable(GL_NORMALIZE); // normalize vectors for proper shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f); // background is light gray
	glViewport(0, 0, 640, 480);
	

	glutMainLoop();
}