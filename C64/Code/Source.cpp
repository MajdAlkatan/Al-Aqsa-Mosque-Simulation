///////مجد اسماعيل القطان 
///////علاء غالب عماد 
///////علي اياد قاسم 
///////مايكل ابراهيم غصن 
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>
#include <glut.h>// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "camera.h"
#include "Point.h" // Header File For Point
#include "PrimitiveDrawer.h" // // Header File For PrimitiveDrawer
#include <fstream>
#include "Model_3DS.h"
#include"Sound.h"+
#include <vector>
#include <cmath>
#include <iostream>

#define M_PI  3.14159265358979323846
const int slices=50;
const int stacks=50;
int alaqsawall , gold , black ,wow ;
struct Pointa {
    float x;
    float y;
};

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

int image4a , starimage,image3,image6,img,imgm,imgm1,imgm2,imgm3,imgm4,imgm44,carpet;
int house1,house2,house3,house4,house5,house6,house7,house8,house9;
int salsla1;
int selver;
int displays;
int curvewallmm,hajar,kobaa;

const int numSegments = 100 ; // Number of line segments to approximate the circle
const float radius = 0.5f;    // Radius of the circle
const float centerX = 0;   // X-coordinate of the center
const float centerY = 0;   // Y-coordinate of the center

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


void fordisplaya(float x,float y , float z ,int texture)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x/2,-y/2,-z/2);
	glTexCoord2d(1,0);
	glVertex3d(x/2,-y/2,-z/2);
	glTexCoord2d(1,1);
	glVertex3d(x/2,y/2,-z/2);
	glTexCoord2d(0,1);
	glVertex3d(-x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(x/2,-y/2,-z/2);
	glTexCoord2d(1,0);
	glVertex3d(x/2,-y/2,z/2);
	glTexCoord2d(1,1);
	glVertex3d(x/2,y/2,z/2);
	glTexCoord2d(0,1);
	glVertex3d(x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x/2,-y/2,z/2);
	glTexCoord2d(1,0);
	glVertex3d(x/2,-y/2,z/2);
	glTexCoord2d(1,1);
	glVertex3d(x/2,y/2,z/2);
	glTexCoord2d(0,1);
	glVertex3d(-x/2,y/2,z/2);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x/2,-y/2,-z/2);
	glTexCoord2d(1,0);
	glVertex3d(-x/2,-y/2,z/2);
	glTexCoord2d(1,1);
	glVertex3d(-x/2,y/2,z/2);
	glTexCoord2d(0,1);
	glVertex3d(-x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x/2,-y/2,-z/2);
	glTexCoord2d(1,0);
	glVertex3d(x/2,-y/2,-z/2);
	glTexCoord2d(1,1);
	glVertex3d(x/2,-y/2,z/2);
	glTexCoord2d(0,1);
	glVertex3d(-x/2,-y/2,z/2);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3d(-x/2,y/2,-z/2);
	glTexCoord2d(1,0);
	glVertex3d(x/2,y/2,-z/2);
	glTexCoord2d(1,1);
	glVertex3d(x/2,y/2,z/2);
	glTexCoord2d(0,1);
	glVertex3d(-x/2,y/2,z/2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void displaya(int texture)
{

	glPushMatrix();
	glTranslated(0,0.1,0);
	fordisplaya(1,0.2,1,texture);
	glTranslated(0,0.2,0);
	fordisplaya(1.4,0.2,1.4,texture);
	glTranslated(0,0.2,0);
	fordisplaya(1.7,0.2,1.7,texture);
	glPopMatrix();
	///////////////
	////////////////
	//////////////
	glPushMatrix();
	glTranslated(0,-4,0);
	fordisplaya(1,0.2,1,texture);
	glTranslated(0,-0.2,0);
	fordisplaya(1.4,0.2,1.4,texture);
	glTranslated(0,-0.2,0);
	fordisplaya(1.7,0.2,1.7,texture);
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
    int cdd=0;
	for (int i = 0; i < numSegments; i++)
    {
		cdd++;
        float theta1 = 2.0f * PI * float(i) / float(numSegments);
        float theta2 = 2.0f * PI * float(i + 1) / float(numSegments);
        float x1 = centerX + radius * cos(theta1);
        float z1 = centerY + radius * sin(theta1);
        float x2 = centerX + radius * cos(theta2);
        float z2 = centerY + radius * sin(theta2);
     glBegin(GL_QUADS);
        glVertex3f(x1, 0.1, z1);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(x2, 0.1, z2);
    glEnd();
	
	glBegin(GL_QUADS);
	
	    glTexCoord2d((cdd-1)*(0.01),0);
        glVertex3f(x1, 0.1, z1);
		glTexCoord2d((cdd-1)*(0.01),1);
        glVertex3f(x1, -4, z1);
		glTexCoord2d((cdd)*(0.01),1);
        glVertex3f(x2, -4, z2);
		glTexCoord2d((cdd)*(0.01),0);
        glVertex3f(x2, 0.1, z2);
    glEnd();

	glBegin(GL_QUADS);
        glVertex3f(x1, -4, z1);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(x2, -4, z2);
    glEnd();


    }
	glDisable(GL_TEXTURE_2D);
	//glFlush();
}

DirectSoundBuffer Sound;
DirectSoundManager SoundManager;


DirectSoundBuffer Sound1;
DirectSoundManager SoundManager1;


DirectSoundBuffer Sound2;
DirectSoundManager SoundManager2;

// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 1200);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

Camera MyCamera;
//
int  image, image2,img55;


// skybox
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;

Model_3DS *tree;
GLTexture leaf,bark;
void fordisplay(float x,float y , float z)
{
	 
	glBegin(GL_QUADS);
	glVertex3d(-x/2,-y/2,-z/2);
	glVertex3d(x/2,-y/2,-z/2);
	glVertex3d(x/2,y/2,-z/2);
	glVertex3d(-x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(x/2,-y/2,-z/2);
	glVertex3d(x/2,-y/2,z/2);
	glVertex3d(x/2,y/2,z/2);
	glVertex3d(x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(-x/2,-y/2,z/2);
	glVertex3d(x/2,-y/2,z/2);
	glVertex3d(x/2,y/2,z/2);
	glVertex3d(-x/2,y/2,z/2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(-x/2,-y/2,-z/2);
	glVertex3d(-x/2,-y/2,z/2);
	glVertex3d(-x/2,y/2,z/2);
	glVertex3d(-x/2,y/2,-z/2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(-x/2,-y/2,-z/2);
	glVertex3d(x/2,-y/2,-z/2);
	glVertex3d(x/2,-y/2,z/2);
	glVertex3d(-x/2,-y/2,z/2);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3d(-x/2,y/2,-z/2);
	glVertex3d(x/2,y/2,-z/2);
	glVertex3d(x/2,y/2,z/2);
	glVertex3d(-x/2,y/2,z/2);
	glEnd();
}
void display()
{
	glPushMatrix();
	glTranslated(0,0.1,0);
	fordisplay(1,0.2,1);
	glTranslated(0,0.2,0);
	fordisplay(1.4,0.2,1.4);
	glTranslated(0,0.2,0);
	fordisplay(1.7,0.2,1.7);
	glPopMatrix();
	///////////////
	////////////////
	//////////////
	glPushMatrix();
	glTranslated(0,-4,0);
	fordisplay(1,0.2,1);
	glTranslated(0,-0.2,0);
	fordisplay(1.4,0.2,1.4);
	glTranslated(0,-0.2,0);
	fordisplay(1.7,0.2,1.7);
	glPopMatrix();
    for (int i = 0; i < numSegments; i++)
    {
        float theta1 = 2.0f * PI * float(i) / float(numSegments);
        float theta2 = 2.0f * PI * float(i + 1) / float(numSegments);
        float x1 = centerX + radius * cos(theta1);
        float z1 = centerY + radius * sin(theta1);
        float x2 = centerX + radius * cos(theta2);
        float z2 = centerY + radius * sin(theta2);
     glBegin(GL_QUADS);
        glVertex3f(x1, 0.1, z1);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(x2, 0.1, z2);
    glEnd();
	
	glBegin(GL_QUADS);
        glVertex3f(x1, 0.1, z1);
        glVertex3f(x1, -4, z1);
        glVertex3f(x2, -4, z2);
        glVertex3f(x2, 0.1, z2);
    glEnd();

	glBegin(GL_QUADS);
        glVertex3f(x1, -4, z1);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(x2, -4, z2);
    glEnd();


    }
	//glFlush();
}
void drawUnitCube() {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, image3);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}
void drawUnitCube1() {
	glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, img);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, 0.5);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}
void drawUnitCube2() {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, image4a);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(10, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(10, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, 0.5);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
}
void drawUnitCube3() {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, house3);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glDisable(GL_TEXTURE_2D);
	
	 glEnd();
	 glDisable(GL_TEXTURE_2D);
	 		glBindTexture(GL_TEXTURE_2D, house3);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	 
	 glEnd();
	 	glDisable(GL_TEXTURE_2D);
			 		glBindTexture(GL_TEXTURE_2D, house3);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, house3);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void drawUnitCube4() {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, house8);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glDisable(GL_TEXTURE_2D);
	
	 glEnd();
	 glDisable(GL_TEXTURE_2D);
	 		glBindTexture(GL_TEXTURE_2D, house8);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	 
	 glEnd();
	 	glDisable(GL_TEXTURE_2D);
			 		glBindTexture(GL_TEXTURE_2D, house8);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, house8);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void drawUnitCube5() {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, house4);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glDisable(GL_TEXTURE_2D);
	
	 glEnd();
	 glDisable(GL_TEXTURE_2D);
	 		glBindTexture(GL_TEXTURE_2D, house4);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	 
	 glEnd();
	 	glDisable(GL_TEXTURE_2D);
			 		glBindTexture(GL_TEXTURE_2D, house4);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, house4);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void drawUnitCube6() {
			glEnable(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, img55);

	glBegin(GL_QUADS);

	//Front Face
	glNormal3f(0, 0, 1);
	 glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	 glTexCoord2f(5, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	 glTexCoord2f(5, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glDisable(GL_TEXTURE_2D);
	
	 glEnd();
	 glDisable(GL_TEXTURE_2D);
	 		glBindTexture(GL_TEXTURE_2D, img55);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Back Face
	glNormal3f(0, 0, -1);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(5, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(5	, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	 
	 glEnd();
	 	glDisable(GL_TEXTURE_2D);
			 		glBindTexture(GL_TEXTURE_2D, img55);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Right Face
	glNormal3f(1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, img55);

	 glEnable(GL_TEXTURE_2D);
	 	glBegin(GL_QUADS);

	//Left Face
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	 glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	 glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

	//Top Face
	glNormal3f(0, 1, 0);
				 //glTexCoord2f(0.0f, 0.0f);

	glVertex3f(-0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 0.0f);

	glVertex3f(0.5, 0.5, -0.5);
				 //glTexCoord2f(1.0f, 1.0f);

	glVertex3f(0.5, 0.5, 0.5);
				 //glTexCoord2f(0.0f, 1.0f);

	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);

	//Bottom Face
	glNormal3f(0, -1, 0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}


void drawMyCube(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, hajar);
	drawUnitCube();

	glPopMatrix();

}
void drawMyCube2(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, img);
	drawUnitCube2();

	glPopMatrix();

}
void drawMyCube1(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, img);
	drawUnitCube1();

	glPopMatrix();

}
void drawMyCube3(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, image3);
	drawUnitCube3();

	glPopMatrix();

}void drawMyCube4(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, image3);
	drawUnitCube4();

	glPopMatrix();

}void drawMyCube5(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, image3);
	drawUnitCube5();

	glPopMatrix();

}
void drawMyCube6(float xPos, float yPos, float zPos,
	float xSize, float ySize, float zSize,
	float xRot, float yRot, float zRot) {

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);
	glRotatef(xRot, 1, 0, 0);
	glRotatef(yRot, 0, 1, 0);
	glRotatef(zRot, 0, 0, 1);
	glScalef(xSize, ySize, zSize);
	glBindTexture(GL_TEXTURE_2D, img55);
	drawUnitCube6();

	glPopMatrix();

}




void drawCone(float baseRadius, float height, int sides, GLuint texture) {
    glBindTexture(GL_TEXTURE_2D, texture);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5, 0.5);
    glVertex3f(0.0, 0.0, 0.0); 
    for (int i = 0; i <= sides; ++i) {
        float angle = (2 * M_PI / sides) * i;
        float x = baseRadius * cos(angle);
        float y = baseRadius * sin(angle);
        glTexCoord2f((x / baseRadius + 1.0) / 2.0, (y / baseRadius + 1.0) / 2.0);
        glVertex3f(x, y, 0.0);
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5, 0.5);
    glVertex3f(0.0, 0.0, height); 
    for (int i = 0; i <= sides; ++i) {
        float angle = (2 * M_PI / sides) * i;
        float x = baseRadius * cos(angle);
        float y = baseRadius * sin(angle);
        glTexCoord2f((x / baseRadius + 1.0) / 2.0, (y / baseRadius + 1.0) / 2.0);
        glVertex3f(x, y, height);
    }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

//void drawCylinder(float radius, float height, int sides) {
//    glBegin(GL_QUAD_STRIP);
//    for (int i = 0; i <= sides; ++i) {
//        float angle = (2 * M_PI / sides) * i;
//        float x = radius * cos(angle);
//        float y = radius * sin(angle);
//
//        glVertex3f(x, y, 0);
//        glVertex3f(x, y, height);
//    }
//    glEnd();
// // Draw the top and bottom circles
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex3f(0.0, 0.0, 0.0); // Center of bottom circle
//    for (int i = 0; i <= sides; ++i) {
//        float angle = (2 * M_PI / sides) * i;
//        float x = radius * cos(angle);
//        float y = radius * sin(angle);
//        glVertex3f(x, y, 0.0);
//    }
//    glEnd();
//
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex3f(0.0, 0.0, height); // Center of top circle
//    for (int i = 0; i <= sides; ++i) {
//        float angle = (2 * M_PI / sides) * i;
//        float x = radius * cos(angle);
//        float y = radius * sin(angle);
//        glVertex3f(x, y, height);
//    }
//    glEnd();
//}


void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width / 2;
	y = y ;
	z = z - length / 2;
	glEnable(GL_TEXTURE_2D);

	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, SKYFRONT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, SKYBACK);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, SKYLEFT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, SKYUP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, SKYDOWN);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); 
	glVertex3f(x, y, z);
	glTexCoord2f(35, 0.0f);
	glVertex3f(x, y, z + length);
	glTexCoord2f(35, 35); 
	glVertex3f(x + width, y, z + length);
	glTexCoord2f(0.0f, 35); 
	glVertex3f(x + width, y, z);
	glEnd();

	glColor3f(1, 1, 1);

}

int image5a , woman , sky;
int curvewall;
int image22,image1,image3a,image4,image5,image7,image8,image9,image10,image11,image12,image13,image14,image15,image16;

void DrawOurMoon()
{
	glLineWidth(3);
double x, y;
 glBegin(GL_LINE_STRIP);

  for (double i = 0.2; i < 1.6 * 3.14; i += 0.001)
  {
  x = cos(i);
  y = sin(i);
  glVertex2d(x * 2, y * 2);
  }
  glEnd();
		glPushMatrix();
	    glTranslated(0.7,-0.4,0);
		glRotated(35,0,0,1);
		glBegin(GL_LINE_STRIP);

  for (double i = 0; i < 1.4* 2.9; i += 0.001)
  {
  x = cos(i);
  y = sin(i);
  glVertex2d(x * 1.5f, y * 1.5f);
  }
  glEnd();
		glPopMatrix();
}

int maroani1,maroani2;
GLfloat LightDir[] = { 0.0f, 1.0f, 0.0f, 0.0f };
GLfloat LightPos[] = { 0.0f, 500, 100, 1.0f };
GLfloat LightDiff[] = { 0.2, 0.2, 0.2, 1.0f };
GLfloat LightSpec[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat MatAmb[] = { 0.1f, 0.1f, 0.1f, 1.0f };
GLfloat MatDif[] = { 0.4, 0.4, 0.4, 1.0f };
GLfloat MatSpec[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat MatShn[] = { 64.0f };
//
GLfloat LightAmb1[] = { 0, 0, 0.2, 0.3 };

GLfloat LightAmb2[] = { 1, 1, 1, 1.0f };

double mouseX, mouseY;
bool isClicked = 0, isRClicked = 0;
float prevMouseX = 0;
float prevMouseY = 0;

void MouseMovement(float mouseX, float mouseY)
{
    float mouseDeltaX = mouseX - prevMouseX;
    float mouseDeltaY = mouseY - prevMouseY;
    
    MyCamera.RotateY(mouseDeltaX * 0.01);
    MyCamera.RotateX(mouseDeltaY * 0.01);
    
    prevMouseX = mouseX;
    prevMouseY = mouseY;
}






int outRightWall,image17;

void Key(bool* keys, float speed)
{
	if(keys['T']){
		Sound.Play(0);
	}
   	if(keys['Y']){
		Sound1.Play(0);
	}
	if(keys['G']){
		Sound.Stop();
	}

			 	if(keys['H']){
		Sound1.Stop();
	}
	if (keys['S'])
		MyCamera.RotateX(-1 * speed);
	if (keys['W'])
		MyCamera.RotateX(1 * speed);
	if (keys['D'])
		MyCamera.RotateY(-1 * speed);
	if (keys['Z'])
		MyCamera.RotateZ(1 * speed);
	if (keys['X'])
		MyCamera.RotateZ(-1 * speed);
	if (keys['A'])
		MyCamera.RotateY(1 * speed);
	if(keys[VK_UP]||keys[VK_DOWN]||keys[VK_LEFT]||keys[VK_RIGHT]){
		Sound2.Play(1);

	}
	else if(!keys[VK_UP]||!keys[VK_DOWN]||!keys[VK_LEFT]||!keys[VK_RIGHT])
		Sound2.Stop();
	if (keys[VK_UP])
		MyCamera.MoveForward(1 * speed);
	if (keys[VK_DOWN])
		MyCamera.MoveForward(-1 * speed);
	if (keys[VK_RIGHT])
		MyCamera.MoveRight(1 * speed);
	if (keys[VK_LEFT])
		MyCamera.MoveRight(-1 * speed);
	if (keys['O'])
		MyCamera.MoveUpward(1 * speed);
	if (keys['L'])
		MyCamera.MoveUpward(-1 * speed);

	 MouseMovement(mouseX*30, mouseY*2);

	if(keys['B'])
	{
		glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb1);
		Sound1.Play(0);
	}
	

	if(keys['N'])
	{
		glLightfv(GL_LIGHT1,GL_AMBIENT,LightAmb2);
		Sound1.Play(0);
	}
}
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
		MyCamera = Camera();
	MyCamera.Position.x = 215;
	MyCamera.Position.y = 1.5;
	MyCamera.Position.z = 0;

	SoundManager.Initialize(hWnd);
	SoundManager.CreateSound("birdchrip.wav", Sound);

	SoundManager1.Initialize(hWnd);
	SoundManager1.CreateSound("azan.wav", Sound1);
	
	SoundManager2.Initialize(hWnd);
	SoundManager2.CreateSound("footsteps.wav", Sound2);

	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	
	glEnable(GL_TEXTURE_2D);
	
		house1 = LoadTexture("outwallright1.bmp",255);
		house2=LoadTexture("images.bmp",255);
		house3=LoadTexture("HouseWooden0006_350.bmp",255);
		house4=LoadTexture("house9.bmp",255);
		house5=LoadTexture("HouseWooden003.bmp",255);
		house6=LoadTexture("house6door.bmp",255);
		house7=LoadTexture("house5block.bmp",255);
		house8=LoadTexture("house4.bmp",255);
		house9 = LoadTexture("imagesss1.bmp");
		img55=LoadTexture("news.bmp",255);
		///////////////////////////////
		alaqsawall = LoadTexture("test2.bmp",255);
    gold = LoadTexture("gold2.bmp",255);
    black = LoadTexture("black.bmp", 255);
    wow = LoadTexture("wow.bmp",255);
	image22 = LoadTexture("mmmm.bmp");
    image6 = LoadTexture("header.bmp",255);
	img=LoadTexture("tile-bro.bmp",255);
	imgm=LoadTexture("Capture2.bmp",255);
	imgm1=LoadTexture("download.bmp",255);
	imgm2=LoadTexture("old_copper_bump.bmp",255);
	imgm3=LoadTexture("bark_loo.bmp",255);
	imgm44=LoadTexture("matern.bmp",255);
	carpet=LoadTexture("carpetmosque.bmp",255);
	       ////////////////////////
	image = LoadTexture("back.bmp", 255);
	//image3a = LoadTexture("building.bmp", 255);
	image4a = LoadTexture("wall.bmp",255);
	image5a = LoadTexture("test3.bmp",255);
	woman = LoadTexture("woman.bmp",255);
	sky = LoadTexture("sky.bmp",255);
	curvewall = LoadTexture("curvewall.bmp",255);
	starimage = LoadTexture("blackrug.bmp",255);
	salsla1 = LoadTexture("salsla1.bmp", 255);
	selver = LoadTexture("selver.bmp",255);
	displays = LoadTexture("display.bmp",255);

	//al masjed
	image1 = LoadTexture("mewa.bmp");
	image2 = LoadTexture("carpet.bmp",255);
	image3a = LoadTexture("rightqibaly1.bmp", 255);
	image4 = LoadTexture("frontq1.bmp", 255);
	image5 = LoadTexture("1.bmp",255);
	image6 = LoadTexture("ut.bmp",255);
	image7 = LoadTexture("out1.bmp");
	image8 = LoadTexture("mewa2.bmp");
	image9 = LoadTexture("frontq1.bmp");
	image10 = LoadTexture("inside1.bmp");
	image11 = LoadTexture("KS2.bmp");
	image12 = LoadTexture("floorcar1.bmp");
	image13 = LoadTexture("under.bmp");
	image14 = LoadTexture("allahmo.bmp");
	image15 = LoadTexture("theoutwall.bmp");
	hajar = LoadTexture("hajar1.bmp");

	image16 = LoadTexture("roofq.bmp", 255);
	image17 = LoadTexture("under.bmp", 255);
	outRightWall=LoadTexture("outwallright1.bmp",255);
	kobaa=LoadTexture("kobaa.bmp",255);
	
	maroani1=LoadTexture("r1212.bmp",255);
	maroani2=LoadTexture("rr1.bmp",255);

	// skybox
	SKYFRONT = LoadTexture("Env4_front.bmp", 255);
	SKYBACK = LoadTexture("Env4_back.bmp", 255);
	SKYLEFT = LoadTexture("Env4_left.bmp", 255);
	SKYRIGHT = LoadTexture("Env4_right.bmp", 255);
	SKYUP = LoadTexture("Env4_up.bmp", 255);
	SKYDOWN = LoadTexture("street.bmp", 255);
	// note if you load a image the opengl while on the GL_Texture_2D himself
	glDisable(GL_TEXTURE_2D);

		glEnable(GL_LIGHTING);
		glEnable(GL_COLOR_MATERIAL);
  		glEnable(GL_LIGHT1);
		glLightfv(GL_LIGHT0, GL_POSITION, LightPos);
        glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmb1);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiff);
       glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpec);
        glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmb);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDif);
       glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpec);
      glMaterialfv(GL_FRONT, GL_SHININESS, MatShn);

	
	glNewList(1,GL_COMPILE);
	tree=new Model_3DS();
    tree->Load("Tree.3ds");
	leaf.LoadBMP("bat.bmp");
	bark.LoadBMP("bark_loo.bmp");
    tree->Materials[0].tex=bark;
    tree->Materials[1].tex=leaf;
    tree->Materials[2].tex=leaf;
    tree->Materials[3].tex=leaf;
    tree->Materials[4].tex=leaf;
	tree->pos.x=100;
	tree->pos.y=0;
	tree->pos.z=+80;
	tree->scale=1;
	tree->Draw();
	glEndList();


	
	return TRUE;										// Initialization Went OK
}
void move_tank(float speed){

	if (keys['Y'])
		tree->pos.z -=speed;
	if (keys['H'])
		tree->pos.z +=speed;
	if (keys['J'])
		tree->pos.x +=speed;
	if (keys['G'])
		tree->pos.x -=speed;

}

float a=0.1;
float radiusa = 2;
float radius1 = 2;
float radius2 = 1; 
float angle;

void displayr()
{
    //glClear(GL_COLOR_BUFFER_BIT);
	/*glColor3f(255,0,0);   */
    for (int i = 0; i < numSegments; i++)
    {
        float theta1 = 2.0f * PI * float(i) / float(numSegments);
        float theta2 = 2.0f * PI * float(i + 1) / float(numSegments);
        float x1 = centerX + radius * cos(theta1);
        float z1 = centerY + radius * sin(theta1);
        float x2 = centerX + radius * cos(theta2);
        float z2 = centerY + radius * sin(theta2);
     glBegin(GL_QUADS);
        glVertex3f(x1, 0.1, z1);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(centerX, 0.1, centerY);
        glVertex3f(x2, 0.1, z2);
    glEnd();
	
	glBegin(GL_QUADS);
        glVertex3f(x1, 0.1, z1);
        glVertex3f(x1, -4, z1);
        glVertex3f(x2, -4, z2);
        glVertex3f(x2, 0.1, z2);
    glEnd();

	glBegin(GL_QUADS);
        glVertex3f(x1, -4, z1);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(centerX, -4, centerY);
        glVertex3f(x2, -4, z2);
    glEnd();


    }
	//glFlush();
}

Pointa interpolatePoint(const Pointa& start, const Pointa& end, float t) {
	
    Pointa result;
    result.x = start.x + t * (end.x - start.x);
    result.y = start.y + t * (end.y - start.y);
    return result;
}
void renderScene(float h , float r , int texture) {
	glPushMatrix();
	glTranslated(0,h,0);
	glEnable(GL_TEXTURE_2D); // Enable 2D texturing

    glBindTexture(GL_TEXTURE_2D, texture); // Bind the texture
    for (int i = 0; i < stacks/2; ++i) {
        float phi1 = M_PI * float(i) / float(stacks);
        float phi2 = M_PI * float(i + 1) / float(stacks);
        glBegin(GL_TRIANGLE_STRIP);
	
        for (int j = 0; j <= slices; ++j) {
            float theta = 2 * M_PI * float(j) / float(slices);
            float x1 = r * sin(phi1) * cos(theta);
            float y1 = r * cos(phi1);
            float z1 = r * sin(phi1) * sin(theta);
            glNormal3f(x1, y1, z1);
			glTexCoord2f(4*(float(j) / float(slices)), 4*(float(i) / float(stacks / 2)));
            glVertex3f(x1, y1, z1);

            float x2 = r * sin(phi2) * cos(theta);
            float y2 = r * cos(phi2);
            float z2 = r * sin(phi2) * sin(theta);
            glNormal3f(x2, y2, z2);
			glTexCoord2f(4*(float(j) / float(slices)), 4*(float(i + 1) / float(stacks / 2)));
            glVertex3f(x2, y2, z2);
        }
		
    }
    glEnd();
	glPopMatrix();
}
class curven{
public:
    void curve(int redues)
        { 
            for (float angle = 180; angle >= 0; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * redues;//3
        	    float y = sin(DEG_TO_RAD) * redues;//3
        		float xx = cos(DEG_TO_RAD) * (redues-1);//2
        	    float yy = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * redues;//3
        	    float y1 = sin(DEG_TO_RAD2) * redues;//3
        		float xx1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float yy1 = sin(DEG_TO_RAD2) * (redues-1);//2
        		glBegin(GL_QUADS);
        	    glVertex3f(x, y, 0);
        	    glVertex3f(x1, y1, 0);
        	    glVertex3f(xx1, yy1, 0);
        	    glVertex3f(xx, yy, 0);
        		glEnd();
        	}
        	glPushMatrix();
        	glTranslated(0 , 0 , 1);
        	for (float angle = 180; angle >= 0; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * redues;//3
        	    float y = sin(DEG_TO_RAD) * redues;//3
        		float xx = cos(DEG_TO_RAD) * (redues-1);//2
        	    float yy = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * redues;//3
        	    float y1 = sin(DEG_TO_RAD2) * redues;//3
        		float xx1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float yy1 = sin(DEG_TO_RAD2) * (redues-1);//2
        		glBegin(GL_QUADS);
        	    glVertex3f(x, y, 0);
        	    glVertex3f(x1, y1, 0);
        	    glVertex3f(xx1, yy1, 0);
        	    glVertex3f(xx, yy, 0);
        		glEnd();
        	}
        	glPopMatrix();
        	for (float angle = 180; angle >= 0; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * (redues-1);//2
        	    float y = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float y1 = sin(DEG_TO_RAD2) * (redues-1);//2
        
        		glBegin(GL_QUADS);
        	    glVertex3f(x, y, 0);
        	    glVertex3f(x1, y1, 0);
        	    glVertex3f(x1, y1, 1);
        	    glVertex3f(x, y, 1);
        		glEnd();
        	   }
        	    glBegin(GL_QUADS);
        	    glVertex3f(-redues, 0, 0);
        	    glVertex3f(-redues, 0, 1);
        	    glVertex3f(-redues, redues, 1);
        	    glVertex3f(-redues, redues, 0);
				glEnd();
        		glPushMatrix();
				glTranslated(2*redues,0,0);
        		glBegin(GL_QUADS);
        	    glVertex3f(-redues, 0, 0);
        	    glVertex3f(-redues, 0, 1);
        	    glVertex3f(-redues, redues, 1);
        	    glVertex3f(-redues, redues, 0);
        		glEnd();
        		glPopMatrix();

        		glBegin(GL_QUADS);
        	    glVertex3f(-redues, redues, 0);
        	    glVertex3f(-redues, redues, 1);
        	    glVertex3f(redues, redues, 1);
        	    glVertex3f(redues, redues, 0);
        		glEnd();
        		////
        		for (float angle = 180; angle >= 0; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * (redues);//3
        	    float y = sin(DEG_TO_RAD) * (redues);//3
        		float x1 = cos(DEG_TO_RAD2) * (redues);//3
        	    float y1 = sin(DEG_TO_RAD2) * (redues);//3
        		glBegin(GL_QUADS);
        	    glVertex3f(x, y, 0);
        	    glVertex3f(x1, y1, 0);
        	    glVertex3f(x1, redues, 0);
        	    glVertex3f(x, redues, 0);
        		glEnd();
        
        		glBegin(GL_QUADS);
        	    glVertex3f(x, y, 1);
        	    glVertex3f(x1, y1, 1);
        	    glVertex3f(x1, redues, 1);
        	    glVertex3f(x, redues, 1);
        		glEnd();
        		///////
        		}
				glPushMatrix();
				glTranslated((redues-3)+2.5,0,0.5);
        	    display();
				glPopMatrix();
        		glPushMatrix();
				glTranslated(-(redues)-2+2.5,0,0.5);
                display();
        		glPopMatrix();
            
        }
};

void drawWall(int x /*50*/ , int y /*100*/, int z /*10*/)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Front face
	glTexCoord2d(0, 0);
    glVertex3f(-x, 0, -y);
	glTexCoord2d(10, 0);
    glVertex3f(x, 0, -y);
	glTexCoord2d(10, 4);
	glVertex3f(x, z, -y);
	glTexCoord2d(0, 4);
	glVertex3f(-x, z, -y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Back face
	glTexCoord2d(0, 0);
    glVertex3f(-(x-316.5), 0, y);
	glTexCoord2d(10, 0);
    glVertex3f(x, 0, y);
	glTexCoord2d(10, 4);
    glVertex3f(x, z, y);
	glTexCoord2d(0, 4);
    glVertex3f(-(x-316.5), z, y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Back face
	glTexCoord2d(0, 0);
    glVertex3f(-x, 0, y);
	glTexCoord2d(10, 0);
    glVertex3f(x-206.5, 0, y);
	glTexCoord2d(10, 4);
    glVertex3f(x-206.5, z, y);
	glTexCoord2d(0, 4);
    glVertex3f(-x, z, y);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
 //   // Left face
	glTexCoord2d(0, 0);
    glVertex3f(-x, -0, y);
	glTexCoord2d(10, 0);
    glVertex3f(-x, -0, -y);
	glTexCoord2d(10, 4);
    glVertex3f(-x, z, -y);
	glTexCoord2d(0, 4);
    glVertex3f(-x, z, +y);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
 //   // Right face
	glTexCoord2d(0, 0);
    glVertex3f(+x, -0, (y));
	glTexCoord2d(10, 0);
    glVertex3f(+x, -0, -(y-259));
	glTexCoord2d(10, 4);
    glVertex3f(+x, z, -(y-259));
	glTexCoord2d(0, 4);
    glVertex3f(+x, z, +(y));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
 //   // Right face
	glTexCoord2d(0, 0);
    glVertex3f(+x, -0, (y-378));
	glTexCoord2d(10, 0);
    glVertex3f(+x, -0, -(y));
	glTexCoord2d(10, 4);
    glVertex3f(+x, z, -(y));
	glTexCoord2d(0, 4);
    glVertex3f(+x, z, +(y-378));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	// Front face2
	glTexCoord2d(0, 0);
    glVertex3f(-(x-7), 0, -(y-7));
	glTexCoord2d(10, 0);
    glVertex3f((x-7), 0, -(y-7));
	glTexCoord2d(10, 4);
    glVertex3f((x-7), z, -(y-7));
	glTexCoord2d(0, 4);
    glVertex3f(-(x-7), z, -(y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Back face2
	glTexCoord2d(0, 0);
    glVertex3f(-(x-7), 0, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f((x-206.5), 0, (y-7));
	glTexCoord2d(10, 4);
    glVertex3f((x-206.5), z, (y-7));
	glTexCoord2d(0,4);
    glVertex3f(-(x-7), z, (y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	////////////////
	  glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Back face2
	glTexCoord2d(0, 0);
    glVertex3f(-(x-316.5), 0, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f((x-7), 0, (y-7));
	glTexCoord2d(10, 4);
    glVertex3f((x-7), z, (y-7));
	glTexCoord2d(0,4);
    glVertex3f(-(x-316.5), z, (y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	/////////////////////


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // Left face2
	glTexCoord2d(0, 0);
    glVertex3f(-(x-7), -0, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(-(x-7), -0, -(y-7));
	glTexCoord2d(10, 4);
    glVertex3f(-(x-7), z, -(y-7));
	glTexCoord2d(0,4);
    glVertex3f(-(x-7), z, +(y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // right face2
	glTexCoord2d(0, 0);
	glVertex3f(+(x-7), -0, (y-378));
	glTexCoord2d(10, 0);
	glVertex3f(+(x-7), -0, -(y-7));
	glTexCoord2d(10, 4);
	glVertex3f(+(x-7), z, -(y));
	glTexCoord2d(0,4);
	glVertex3f(+(x-7), z, +(y-378));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
    // right face2
	glTexCoord2d(0, 0);
	glVertex3f(+(x-7), -0, (y));
	glTexCoord2d(10, 0);
	glVertex3f(+(x-7), -0, -(y-259));
	glTexCoord2d(10, 4);
	glVertex3f(+(x-7), z, -(y-259));
	glTexCoord2d(0,4);
	glVertex3f(+(x-7), z, +(y));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//deep front
	glTexCoord2d(0, 0);
	glVertex3f(-(x), 0, -(y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x), 0, -(y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x), 0, -(y));
	glTexCoord2d(0,1);
    glVertex3f(-(x), 0, -(y));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//deep back
	glTexCoord2d(0, 0);
	glVertex3f(-(x-316.5), 0, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x), 0, (y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x), 0, (y));
	glTexCoord2d(0,1);
    glVertex3f(-(x-316.5), 0, (y));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	////////////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//deep back
	glTexCoord2d(0, 0);
	glVertex3f(-(x), 0, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x-206.5), 0, (y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x-206.5), 0, (y));
	glTexCoord2d(0,1);
    glVertex3f(-(x), 0, (y));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	///////////////////

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//deep right
	glTexCoord2d(0, 0);
	glVertex3f((x-7), -0, (y-7));
	glTexCoord2d(1, 0);
    glVertex3f((x), -0, (y-7));
	glTexCoord2d(1, 10);
    glVertex3f((x), 0, -(y-259));
	glTexCoord2d(0, 10);
    glVertex3f((x-7), 0, -(y-259));

	glEnd();
	glDisable(GL_TEXTURE_2D);
	///////////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//deep right
	glTexCoord2d(0, 0);
	glVertex3f((x-7), -0, (y-378));
	glTexCoord2d(1, 0);
    glVertex3f((x), -0, (y-378));
	glTexCoord2d(1, 10);
    glVertex3f((x), 0, -(y));
	glTexCoord2d(0, 10);
    glVertex3f((x-7), 0, -(y));

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	////deep left
	glTexCoord2d(0, 0);
	glVertex3f(-(x), -0, (y-7));
	glTexCoord2d(1, 0);
    glVertex3f(-(x-7), -0, (y-7));
	glTexCoord2d(1, 10);
    glVertex3f(-(x-7), 0, -(y-7));
	glTexCoord2d(0,10);
    glVertex3f(-(x), 0, -(y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//hieght front

	glTexCoord2d(0, 0);
	glVertex3f(-(x), z, -(y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x), z, -(y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x), z, -(y));
	glTexCoord2d(0,1);
    glVertex3f(-(x), z, -(y));

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	////hieght left

	glTexCoord2d(0, 0);
	glVertex3f(-(x), z, (y-7));
	glTexCoord2d(1, 0);
    glVertex3f(-(x-7), z, (y-7));
	glTexCoord2d(1, 10);
    glVertex3f(-(x-7), z, -(y-7));
	glTexCoord2d(0,10);
    glVertex3f(-(x), z, -(y-7));

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	//hieght right
	glTexCoord2d(0, 0);
	glVertex3f((x-7), z, (y));
	glTexCoord2d(1, 0);
    glVertex3f((x), z, (y));
	glTexCoord2d(1, 10);
    glVertex3f((x), z, -(y-260));
	glTexCoord2d(0, 10);
    glVertex3f((x-7), z, -(y-260));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	/*hieght right2*/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	
	glTexCoord2d(0, 0);
	glVertex3f((x-7), z, (y-360));
	glTexCoord2d(1, 0);
    glVertex3f((x), z, (y-360));
	glTexCoord2d(1, 10);
    glVertex3f((x), z, -(y));
	glTexCoord2d(0, 10);
    glVertex3f((x-7), z, -(y));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//hieght back
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x), z, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x-206.5), z, (y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x-206.5), z, (y));
	glTexCoord2d(0,1);
    glVertex3f(-(x), z, y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image4a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x-316.5), z, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(+(x), z, (y-7));
	glTexCoord2d(10, 1);
    glVertex3f((x), z, (y));
	glTexCoord2d(0,1);
    glVertex3f(-(x-316.5), z, y);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	

}
void drawCube(float size) {
    float halfSize = size / 2.0;

    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, -halfSize, halfSize);
    glVertex3f(halfSize, halfSize, halfSize);
    glVertex3f(-halfSize, halfSize, halfSize);

    // Back face
    glVertex3f(-halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, -halfSize, -halfSize);
    glVertex3f(halfSize, halfSize, -halfSize);
    glVertex3f(-halfSize, halfSize, -halfSize);

    // Remaining faces...
    // Define vertices for the other faces similarly

    glEnd();
}
void drawdrawar(int width )
{
	glPushMatrix();
	for(int i=0 ; i<10 ; i++)
	{
		glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, image5a);
		if(i!=0){
	    glBegin(GL_QUADS);
        // Front face
	    glTexCoord2d(0, 0);
        glVertex3f(-0, 0, 0);
	    glTexCoord2d(1, 0);
        glVertex3f(+width, 0, 0);
	    glTexCoord2d(1, 1);
	    glVertex3f(+width, -0.5, 0);
	    glTexCoord2d(0, 1);
	    glVertex3f(-0, -0.5, 0);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
		}
	    glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, image5a);
	    glBegin(GL_QUADS);
        // Front face
	    glTexCoord2d(0, 0);
        glVertex3f(0, -0.5, 1.25);
	    glTexCoord2d(1, 0);
        glVertex3f(+width, -0.5, 1.25);
	    glTexCoord2d(1, 1);
	    glVertex3f(+width,-0.5, 0);
	    glTexCoord2d(0, 1);
	    glVertex3f(0, -0.5, 0);
	    glEnd();

		glBegin(GL_QUADS);
        // Front face
	    glTexCoord2d(1-(0.1*(i)), 1-(0.1*(i)));
		glVertex3f(width, -0.5, 0);

	    glTexCoord2d(1-(0.1*(i+1)), 1-(0.1*(i)));
        glVertex3f(+width, -0.5, 1.25);

	    glTexCoord2d(1-(0.1*(i+1)), 0);
	    glVertex3f(+width,-((10-i)*0.5), 1.25);

	    glTexCoord2d(1-(0.1*(i)), 0);
	    glVertex3f(width, -((10-i)*0.5), 0);
	    glEnd();

		glBegin(GL_QUADS);
        // Front face
		glTexCoord2d(1-(0.1*(i)), 1-(0.1*(i)));
        glVertex3f(0, -0.5, 0);

	    glTexCoord2d(1-(0.1*(i+1)), 1-(0.1*(i)));
        glVertex3f(+0, -0.5, 1.25);

	    glTexCoord2d(1-(0.1*(i+1)), 0);
	    glVertex3f(+0,-((10-i)*0.5), 1.25);

	    glTexCoord2d(1-(0.1*(i)), 0);
	    glVertex3f(0, -((10-i)*0.5), 0);
	    glEnd();


	    glDisable(GL_TEXTURE_2D);
	    glTranslated(0,-0.5,1.25);
	}
	glPopMatrix();
}
void drawmastaba()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image5a);

	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2f, 7*0.4);
	glVertex3f(-30, 5, 0);//5
	glTexCoord2f(6*0.0f, 7*0.4);
	glVertex3f(-50, 5, 0);//4
	glTexCoord2f(6*0.0f, 7*1.0f);
	glVertex3f(-50, 5, -75);//3

	glEnd();
	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2f, 7*0.4);
	glVertex3f(-30, 5, 0);//5
	glTexCoord2f(6*0.0f, 7*1.0f);
	glVertex3f(-50, 5, -75);//3
	glTexCoord2f(6*1.0f, 7*1.0f);
	glVertex3f(50, 5, -75);//2
	glEnd();
	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2f,7* 0.4);
	glVertex3f(-30, 5, 0);//5
	glTexCoord2f(6*1.0f,7* 1.0f);
	glVertex3f(50, 5, -75);//2
	glTexCoord2f(6*1.0f,7* 0.0f);
	glVertex3f(50, 5, 50);//1
	glEnd();
	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2f,7* 0.4);
	glVertex3f(-30, 5, 0);//5
	glTexCoord2f(6*1.0f,7* 0.0f);
	glVertex3f(50, 5, 50);//1
	glTexCoord2f(6*0.2,7* 0.0);
	glVertex3f(-30, 5, 50);//6a
	glEnd();
	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2, 7*0.216);
	glVertex3f(-30, 5, 23);//6
	glTexCoord2f(6*0.2, 7*0.0);
	glVertex3f(-30, 5, 50);//6a
	glTexCoord2f(6*0.0,7* 0.0);
	glVertex3f(-50, 5, 50);//8
	glEnd();
	glBegin(GL_TRIANGLES);
	glTexCoord2f(6*0.2,7* 0.216);
	glVertex3f(-30, 5, 23);//6
	glTexCoord2f(6*0.0, 7*0.0);
	glVertex3f(-50, 5, 50);//8
	glTexCoord2f(6*0.0, 7*0.216);
	glVertex3f(-50, 5, 23);//7
	glEnd();
	glDisable(GL_TEXTURE_2D);

	curven d;
	///
	glPushMatrix();
	glTranslated(-5,5,50);
	drawdrawar(10);
	
	glPushMatrix();
	glTranslated(4.5,4,0);
	d.curve(5);
	glPopMatrix();

	glPopMatrix();
	////
	glPushMatrix();
	glTranslated(40,5,50);
	drawdrawar(6);
	glPushMatrix();
	glTranslated(2.5,4,0);
	d.curve(3);
	glPopMatrix();
	glPopMatrix();
	////////
	glPushMatrix();
	glTranslated(50,5,20);
	glRotated(90,0,1,0);
	drawdrawar(20);
	glPushMatrix();
	glTranslated(9.5,4,0);
	d.curve(10);
	glPopMatrix();
	glPopMatrix();
	//////
	glPushMatrix();
	glTranslated(-30,5,-0);
	glRotated(-90,0,1,0);
	///////////////////////////
	///////////////////////////
	glPushMatrix();
	for(int i=0 ; i<16 ; i++)
	{
		glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, image5a);
	    glBegin(GL_QUADS);
        // Front face
	    //glTexCoord2d(0, 0);
        glVertex3f(-0, 0, 0);
	   // glTexCoord2d(1, 0);
        glVertex3f(+23, 0, 0);
	    //glTexCoord2d(1, 0.2);
	    glVertex3f(+23, -0.3125, 0);
	    //glTexCoord2d(0, 0.2);
	    glVertex3f(-0, -0.3125, 0);
	    glEnd();
	    glDisable(GL_TEXTURE_2D);
	    
	    glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, image5a);
	    glBegin(GL_QUADS);
        // Front face
	    glTexCoord2d(0, 0);
        glVertex3f(0, -0.3125, 2);
	    glTexCoord2d(1, 0);
        glVertex3f(+23, -0.3125, 2);
	    glTexCoord2d(1, 0.2);
	    glVertex3f(+23,-0.3125, 0);
	    glTexCoord2d(0, 0.2);
	    glVertex3f(0, -0.3125, 0);
	    glEnd();
		if(i>=2)
		{
			glBegin(GL_QUADS);
		// Front face
			glTexCoord2d(1-(0.0625*(i)), 1-(0.0625*(i)));
			glVertex3f(23, -0.3125, 0);

			glTexCoord2d(1-(0.0625*(i+1)), 1-(0.0625*(i)));
			glVertex3f(+23,  -0.3125, 2);

			glTexCoord2d(1-(0.0625*(i+1)), 0);
			glVertex3f(+23,-(0.3125*(16-i)), 2);

	        glTexCoord2d(1-(0.0625*(i)), 0);
			glVertex3f(23, -(0.3125*(16-i)), 0);
			glEnd();

			glBegin(GL_QUADS);
			// Front face
			glTexCoord2d(1-(0.0625*(i)), 1-(0.0625*(i)));
			glVertex3f(0, -0.3125, 0);

			glTexCoord2d(1-(0.0625*(i+1)), 1-(0.0625*(i)));
			glVertex3f(+0,  -0.3125, 2);

			glTexCoord2d(1-(0.0625*(i+1)), 0);
			glVertex3f(+0,-(0.3125*(16-i)), 2);

		    glTexCoord2d(1-(0.0625*(i)), 0);
			glVertex3f(0, -(0.3125*(16-i)), 0);
			glEnd();
		}
		glDisable(GL_TEXTURE_2D);
	    glTranslated(0,-0.3125,2);
	}
	glPushMatrix();
	glTranslated(2,9,-35);
	d.curve(4);
	glTranslated(8,0,-0);
	d.curve(4);
	glTranslated(8,0,-0);
	d.curve(4);
	glPopMatrix();
	glPopMatrix();
	///////////////////////////
	///////////////////////////
	///////////////////////////
	glPopMatrix();
	//////////
	glPushMatrix();
	glTranslated(-50,5,-75);
	glRotated(-90,0,1,0);
	drawdrawar(13);
	glPopMatrix();
	
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image5a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,50);

	glTexCoord2d(4, 1);
	glVertex3d(50,5,50);

	glTexCoord2d(4, 0);
	glVertex3d(50,0,50);

	glTexCoord2d(0, 0);
	glVertex3d(-50,0,50);

	glEnd();

	glDisable(GL_BLEND);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,50);
	glTexCoord2d(1, 1);
	glVertex3d(-50,5,23);
	glTexCoord2d(1, 0);
	glVertex3d(-50,0,23);
	glTexCoord2d(0, 0);
	glVertex3d(-50,0,50);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(3, 1);
	glVertex3d(-50,5,-75);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,0);
	glTexCoord2d(0, 0);
	glVertex3d(-50,0,0);
	glTexCoord2d(3, 0);
	glVertex3d(-50,0,-75);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,23);
	glTexCoord2d(0, 0);
	glVertex3d(-50,0,23);
	glTexCoord2d(1, 0);
	glVertex3d(-30,0,23);
	glTexCoord2d(1, 1);
	glVertex3d(-30,5,23);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,0);
	glTexCoord2d(0, 0);
	glVertex3d(-50,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(-30,0,0);
	glTexCoord2d(1, 1);
	glVertex3d(-30,5,0);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1);
	glVertex3d(-50,5,-75);
	glTexCoord2d(3, 1);
	glVertex3d(50,5,-75);
	glTexCoord2d(3, 0);
	glVertex3d(50,0,-75);
	glTexCoord2d(0, 0);
	glVertex3d(-50,0,-75);
	glEnd();
	glBegin(GL_QUADS);
	glTexCoord2d(3, 1);
	glVertex3d(50,5,-75);
	glTexCoord2d(0, 1);
	glVertex3d(50,5,50);
	glTexCoord2d(0, 0);
	glVertex3d(50,0,50);
	glTexCoord2d(3, 0);
	glVertex3d(50,0,-75);
	glEnd();
}
class CurveWall
{
public:
	void draw()
	{
		/////////////
		/////////////
		/////////////
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // Set blending function

       // Set material properties for a glass-like appearance
       GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 0.8f};  // High specularity with transparency
       GLfloat materialShininess = 100.0f;                     // High shininess
       glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpecular);
       glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
	   glEnable(GL_TEXTURE_2D);
	   glBindTexture(GL_TEXTURE_2D, sky);

	   glColor4f(0.8f, 0.8f, 1.0f, 0.6); 
	   glBegin(GL_POLYGON);
		for(int i=0 ; i<=100 ; i++)
		{
		
				float angle = i * (3.14159 / 200)  + ((0.5)*3.14159);
		        glVertex3f((10) - 2*cos(angle), (7) + 2*sin(angle),-15);
		}
		glVertex3f(11+0.99999999999295846120922478501, 5, -15); 
		glVertex3f(11+0.99999999999295846120922478501, 3, -15);
		glVertex3f(10, 3, -15);
		glVertex3f(10, 0, -15);
		glEnd();
		glDisable(GL_BLEND);
		

		glEnable(GL_BLEND);
		glBegin(GL_POLYGON);
		//glColor4f(0.0f, 0.3f, 0.4, 0.95); 
		for(int i=0 ; i<=100 ; i++)
		{
		
				float angle = i * (3.14159 / 200)  + ((0.5)*3.14159);
		        glVertex3f((10) + 2*cos(angle), (7) + 2*sin(angle),-15);
		}
		glVertex3f(10-1.99999999999295846120922478501, 5, -15); 
		glVertex3f(10-1.99999999999295846120922478501, 3, -15);
		glVertex3f(10, 3, -15);
		glVertex3f(10, 0, -15);
		glEnd();
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
		/////////////
		/////////////
		/////////////
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, curvewall);
		glBegin(GL_POLYGON);

		int x=10 , y=15 , z=9;
		//glTexCoord2d(0, 0);
		glVertex3f(0, 0, -15);
		//glTexCoord2d(0, 1);
		glVertex3f(0, 15, -15);
		//glTexCoord2d(1, 1);
		glVertex3f(10, 15, -15);
		//glTexCoord2d(1, 0.66015625);
		glVertex3f(10, 9, -15);
		for(int i=0 ; i<=100 ; i++)
		{
		
				float angle = i * (3.14159 / 200)  + ((0.5)*3.14159);
				
				//glTexCoord2d(1-(i*(0.001435546875)),0.66015625-(i*(0.00056640625)));
		        glVertex3f((10) + 2*cos(angle), (7) + 2*sin(angle),-15);
		}
		//glTexCoord2d(1-(100*(0.001435546875)),0.66015625-(100*(0.00056640625)));
		glVertex3f(10-1.99999999999295846120922478501, 5, -15); 
		//glTexCoord2d(1-(100*(0.001435546875)),0.333333);
		glVertex3f(10-1.99999999999295846120922478501, 3, -15);
		//glTexCoord2d(1,0.333333);
		glVertex3f(10, 3, -15);
		//glTexCoord2d(1,0);
		glVertex3f(10, 0, -15);
		glEnd();
		glDisable(GL_TEXTURE_2D);



		glPushMatrix();
		glTranslated(15,0,-15);
		glRotated(180,0,1,0);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, curvewall);
		glBegin(GL_POLYGON);
		glVertex3f(-5, 0, 0);
		glVertex3f(-5, 15, 0);
		glVertex3f(5, 15, 0);
		glVertex3f(5, 9, -0);
		for(int i=0 ; i<=100 ; i++)
		{
				float angle = i * (3.14159 / 200)  + ((0.5)*3.14159);
		        glVertex3f((5) + 2*cos(angle), (7) + 2*sin(angle),-0);
		}
		glVertex3f(5-1.99999999999295846120922478501, 5, -0); 
		glVertex3f(5-1.99999999999295846120922478501, 3, -0);
		glVertex3f(5, 3, -0);
		glVertex3f(5, 0, -0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	}
};
void drawboraqwall(){
	curven m;
		drawMyCube1(-160,7,-111.5,0,15,15,0,0,0);
		drawMyCube1(-160,7,178,0,15,15,0,0,0);
			drawMyCube1(-177,13,32,35,5,303,0,0,0);
		glPushMatrix();
	glTranslated(-160,4,-93);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
				//-5
	glPushMatrix();
	glTranslated(-160,4,-83);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
		//-4
	glPushMatrix();
	glTranslated(-160,4,-62);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
		//-3
	glPushMatrix();
	glTranslated(-160,4,-52);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//-2
			glPushMatrix();
	glTranslated(-160,4,-31);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//-1
		glPushMatrix();
	glTranslated(-160,4,-21);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//center
	glPushMatrix();
	glTranslated(-160,4,3);
    glRotated(90,0,1,0);
	m.curve(15);
	glPopMatrix();
	//+1
	glPushMatrix();
	glTranslated(-160,4,27);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+2
	glPushMatrix();
	glTranslated(-160,4,37);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+3
	glPushMatrix();
	glTranslated(-160,4,58);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+4
	glPushMatrix();
	glTranslated(-160,4,68);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+5
		glPushMatrix();
	glTranslated(-160,4,89);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+6
		glPushMatrix();
	glTranslated(-160,4,99);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+7
		glPushMatrix();
	glTranslated(-160,4,120);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+8
		glPushMatrix();
	glTranslated(-160,4,130);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	//+9
		glPushMatrix();
	glTranslated(-160,4,150);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-160,4,160);
    glRotated(90,0,1,0);
	m.curve(11);
	glPopMatrix();
	
	

}
void drawwamn(int x , int y , int z)
{
	CurveWall c;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image5a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x-7), z, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(-20, z, (y-7));
	glTexCoord2d(10, 4);
    glVertex3f(-20, z, (y-7)-30);
	glTexCoord2d(0, 4);
    glVertex3f(-(x-7), z,  (y-7)-30);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	/////////

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image5a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x-7), z, (y-7)-30);
	glTexCoord2d(10, 0);
    glVertex3f(-(x-7)+30, z, (y-7)-30);
	glTexCoord2d(10, 4);
    glVertex3f(-(x-7)+30, z, (y-7)-110);
	glTexCoord2d(0, 4);
    glVertex3f(-(x-7), z,  (y-7)-110);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	/////////

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image5a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-20, z, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(-20, z, (y-7)-30);
	glTexCoord2d(10, 4);
    glVertex3f(-20, 0, (y-7)-30);
	glTexCoord2d(0, 4);
    glVertex3f(-20, 0,  (y-7));
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image5a);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x-7), z, (y-7)-110);
	glTexCoord2d(10, 0);
    glVertex3f(-(x-7), 0, (y-7)-110);
	glTexCoord2d(10, 4);
    glVertex3f(-(x-7)+30,0, (y-7)-110);
	glTexCoord2d(0, 4);
    glVertex3f(-(x-7)+30,z,  (y-7)-110);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(-40,0,+278);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-3,0,-0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, curvewall);
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -15);
	glVertex3f(0, 15, -15);
	glVertex3f(3, 15, -15);
	glVertex3f(3, 0, -15);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glRotated(-90,0,1,0);
	glTranslated(-35,0,+15);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glTranslated(-20,0,0);
	c.draw();
	glPopMatrix();
	///////////////////
		glPushMatrix();
	glTranslated(0,-15,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, carpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3f(-(x-7), z, (y-7));
	glTexCoord2d(10, 0);
    glVertex3f(-20, z, (y-7));
	glTexCoord2d(10, 4);
    glVertex3f(-20, z, (y-7)-30);
	glTexCoord2d(0, 4);
    glVertex3f(-(x-7), z,  (y-7)-30);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,-15,0);
	//glRotated(90,0,1,0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, carpet);
	glBegin(GL_QUADS);
	glTexCoord2d(4, 10);
	glVertex3f(-(x-7), z, (y-7)-30);
	glTexCoord2d(0, 10);
    glVertex3f(-(x-7)+30, z, (y-7)-30);
	glTexCoord2d(0, 0);
    glVertex3f(-(x-7)+30, z, (y-7)-110);
	glTexCoord2d(4, 0);
    glVertex3f(-(x-7), z,  (y-7)-110);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void drawTextureWall(){
	glPushMatrix();
		glTranslated(-107,7.5,291);
		drawMyCube6(0,0,0,174,15,0,0,0,0);
		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, img55);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(-87, -7.5, 0);
		glTexCoord2d(0, 1);
		glVertex3d(87, -7.5, 0);
		glTexCoord2d(1, 1);
		glVertex3d(87, 7.5, 0);
		glTexCoord2d(1, 0);
		glVertex3d(-87, 7.5, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);*/
		glPopMatrix();

	}
void drawTextureWall1(){
			glPushMatrix();
			glTranslated(-191.9,7.5,238);
			glRotated(90,0,1,0);
		   drawMyCube6(0,0,0,109.5,15,0,0,0,0);

			/*glBindTexture(GL_TEXTURE_2D, img55);

		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(0, -7.5, -57);
		glTexCoord2d(0, 1);
		glVertex3d(0, -7.5, 57);
		glTexCoord2d(1, 1);
		glVertex3d(0, 7.5, 57);
		glTexCoord2d(1, 0);
		glVertex3d(0, 7.5, -57);
		glEnd();*/

			glPopMatrix();
			}
void darwtree(){
	glPushMatrix();
			glTranslated(30,0,-20);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,-40);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,-60);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(30,0,-80);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(50,0,-85);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(70,0,-85);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(90,0,-85);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(110,0,-85);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(90,0,-85);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,0);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(30,0,20);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(40,0,40);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(40,0,60);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,95);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,110);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,125);
			tree->Draw();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(55,0,137);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(70,0,137);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(85,0,137);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(100,0,137);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(100,0,30);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(80,0,30);
			tree->Draw();
			glPopMatrix();
			
		//draw trees around the square

			glPushMatrix();
			glTranslated(-20,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-35,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-50,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-65,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-80,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-95,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-110,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-125,0,-35);
			tree->Draw();
			glPopMatrix();
			 for(int i=0;i<160;i+=20)
			{ glPushMatrix();
			 glTranslated(-220,0,-200+i);
			 tree->Draw();
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-200,0,-200+i);
			 tree->Draw();
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-180,0,-200+i);
			 tree->Draw();
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-160,0,-200+i);
			 tree->Draw();
			 glPopMatrix();
			 }
}

void alrahmabab(){
	drawMyCube2(184.5,20,-77.5,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-70,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-63,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-56,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-49,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-42.5,5,4,5,0,0,0);
	glPushMatrix();
	glTranslated(22.5,0,0);
	drawMyCube2(184.5,20,-77.5,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-70,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-63,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-56,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-49,5,4,5,0,0,0);
	drawMyCube2(184.5,20,-42.5,5,4,5,0,0,0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(10,0,0);
		drawMyCube2(184.5,20,-77.5,5,4,5,0,0,0);
		drawMyCube2(184.5,20,-42.5,5,4,5,0,0,0);
		glPopMatrix();



	drawMyCube2(196,16,-60,28,5,40,0,0,0);
	curven mm;
	glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
		////////////////////////left
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	//////////seconde
	glPushMatrix();
	glTranslated(-5,0,0);

		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
		////////////////////////left
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPopMatrix();
		///////therd
		glPushMatrix();
	glTranslated(13,0,0);

		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
		////////////////////////left
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPopMatrix();
	///////////////////fourth
		glPushMatrix();
	glTranslated(18,0,0);

		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-50);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPushMatrix();
		glTranslated(191,4,-50);
		glRotated(90,0,1,0);
		////////////////////////left
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(6);
	glPopMatrix();
	/////////////
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(7);
	glPopMatrix();
	//////////2
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(8);
	glPopMatrix();
	//////////////////3
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(9);
	glPopMatrix();
	/////////////////4
		glPushMatrix();
		glTranslated(191,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(190,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(189,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(188,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
		glPushMatrix();
		glTranslated(187,4,-70);
		glRotated(90,0,1,0);
	mm.curve(10);
	glPopMatrix();
	glPopMatrix();

}

void drawBall()
{
    const float radius = 20;
	const int numSlices = 50;
	const int numStacks = 50;

    for (int i = 0; i < numStacks; ++i)
    {
        float theta1 = static_cast<float>(i) / numStacks * M_PI;
        float theta2 = static_cast<float>(i + 1) / numStacks * M_PI;

        glBegin(GL_TRIANGLE_STRIP);

        for (int j = 0; j <= numSlices/2; ++j)
        {
            float phi = static_cast<float>(j) / numSlices * 2.0f * M_PI;
	
            // Vertex 1
            float x1 = radius * sin(theta1) * cos(phi);
            float y1 = radius * sin(theta1) * sin(phi);
            float z1 = radius * cos(theta1);

            glVertex3f(x1, y1, z1);

            // Vertex 2
            float x2 = radius * sin(theta2) * cos(phi);
            float y2 = radius * sin(theta2) * sin(phi);
            float z2 = radius * cos(theta2);

            glVertex3f(x2, y2, z2);

        }
        glEnd();
    }
}

void DrawCircle()
{
 double x, y;
  glBegin(GL_POLYGON);

  for (double i = 0; i < 2 * 3.14; i += 0.001)
  {
  x = cos(i);
  y = sin(i);
  glVertex2d(x * 23, y * 23);
  }
  glEnd();
}

void DrwaCircle2(){
double x, y;
		glRotated(90,0,1,0);
	glBegin(GL_POLYGON);
	//glColor3d(0, 1, 0);
	for (double i = 0; i < 2 * 3.14; i += 0.001)
	{
	x = cos(i);
	y = sin(i);
	glVertex2d(x * 1, y * 1);
	}
	glEnd();
}

void DrawCrescentMoon1()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image); 
	glLineWidth(3);
    glBegin(GL_LINE_STRIP);
 
    for (int i = 0; i <= 360; i++)
    {
        angle = i * M_PI / 360;
        glVertex3d(radius1 * cos(angle), radius1 * sin(angle), 0);
    }
    glEnd();
		glDisable(GL_TEXTURE_2D);

    // Draw the main circle
  //  glBegin(GL_POLYGON);
  //  for (int i = 0; i < 360; i++)
  //  {
  //      float theta = 2.0 * 3.1415926 * float(i) / float(360);
  //      float x = 0.6 * cosf(theta);
  //      float y = 0.6 * sinf(theta);
  //      glVertex2f(x, y);
  //  }
  //  glEnd();

		//			glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image2);    
  //  // Draw the overlapping circle
  //  glBegin(GL_POLYGON);
  //  for (int i = 180; i < 540; i++)
  //  {
  //      float theta = 2.0 * 3.1415926 * float(i) / float(360);
  //      float x = 0.4 * cosf(theta);
  //      float y = 0.4 * sinf(theta);
  //      glVertex2f(x, y);
  //  }
  //  glEnd();
		//	glDisable(GL_TEXTURE_2D);


}

void DrawCrescentMoon2()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image); 
	glLineWidth(3);
    glBegin(GL_LINE_STRIP);
 
    for (int i = 0; i <= 320; i++)
    {
        angle = i * M_PI / 320;
        glVertex3d(radius2 * cos(angle), radius2 * sin(angle), 0);
    }
    glEnd();
		glDisable(GL_TEXTURE_2D);

    // Draw the main circle
  //  glBegin(GL_POLYGON);
  //  for (int i = 0; i < 360; i++)
  //  {
  //      float theta = 2.0 * 3.1415926 * float(i) / float(360);
  //      float x = 0.6 * cosf(theta);
  //      float y = 0.6 * sinf(theta);
  //      glVertex2f(x, y);
  //  }
  //  glEnd();

		//			glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image2);    
  //  // Draw the overlapping circle
  //  glBegin(GL_POLYGON);
  //  for (int i = 180; i < 540; i++)
  //  {
  //      float theta = 2.0 * 3.1415926 * float(i) / float(360);
  //      float x = 0.4 * cosf(theta);
  //      float y = 0.4 * sinf(theta);
  //      glVertex2f(x, y);
  //  }
  //  glEnd();
		//	glDisable(GL_TEXTURE_2D);


}

void DrawRoof(){
		glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image15);    
glBegin(GL_TRIANGLES);
	//front face
		glTexCoord2f(0, 0);   

	glVertex3d(-1,0,0);
			glTexCoord2f(0.5, 0.5);    

	glVertex3d(51,0,0);
			glTexCoord2f(0, 1);    

	glVertex3d(25,15,0);
	//////////////////
	//back face
		glTexCoord2f(0, 1);   

	glVertex3d(-1,0,-51);
			glTexCoord2f(0.5, 0.5);    

	glVertex3d(51,0,-51);
			glTexCoord2f(0, 0);    

	glVertex3d(25,15,-51);
	glEnd();
		glDisable(GL_TEXTURE_2D);



	/*
		glTexCoord2f(1, 0);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(1, 1);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 1);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 0);     
			glVertex3f(v4.x, v4.y, v4.z);
	*/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, image15);    
	////between
	glBegin(GL_QUADS);
	//bottom face
		glTexCoord2f(1, 0);   

	glVertex3d(-1,0,0);
			glTexCoord2f(1, 1);    

	glVertex3d(51,0,0);
			glTexCoord2f(0, 1);    

	glVertex3d(51,0,-51);
			glTexCoord2f(0, 0);     

	glVertex3d(-1,0,-51);



	//left face
		glTexCoord2f(1, 0);   

	glVertex3d(-1,0,0);
			glTexCoord2f(1, 1);    

	glVertex3d(25,15,0);
			glTexCoord2f(0, 1);    

	glVertex3d(25,15,-51);
			glTexCoord2f(0, 0);     

	glVertex3d(-1,0,-51);





	//right face
		glTexCoord2f(1, 0);   

	glVertex3d(51,0,0);
			glTexCoord2f(1, 1);    

	glVertex3d(25,15,0);
			glTexCoord2f(0, 1);    

	glVertex3d(25,15,-51);
			glTexCoord2f(0, 0);     

	glVertex3d(51,0,-51);

	glEnd(); 
		glDisable(GL_TEXTURE_2D);

	
}

void DrawArch()
{
	glLineWidth(5);

    glBegin(GL_LINE_STRIP);
 
    for (int i = 0; i <= 180; i++)
    {
        angle = i * M_PI / 180;
        glVertex3d(radiusa * cos(angle), radiusa * sin(angle), 0);
    }
    glEnd();

		//glPolygonMode(GL_BACK, GL_LINE);

	glBegin(GL_LINE_LOOP);
	glVertex3d(-2,0,0);
	glVertex3d(-2,-5,0);
	glVertex3d(2,0,0);
	glVertex3d(2,-5,0);

	glEnd();

}

void DrawArch1()
{
	glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image3a);
	  glLineWidth(9);
		glBegin(GL_LINE_STRIP);
 
		for (int i = 0; i <= 180; i++)
		{
			angle = i * 3.14159f / 180.0f;
			glVertex3f(radiusa *2* cos(angle), radiusa*2 * sin(angle), 0.0f);
		}
		glEnd();
	  glBegin(GL_LINES);
	  glVertex3d(-4,0,0);
	  glVertex3d(-4,-5,0);
	  glVertex3d(4,0,0);
	  glVertex3d(4,-5,0);
	  glEnd();
	  glDisable(GL_TEXTURE_2D);

}

void drawWindow(){

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image3a);
	    glLineWidth(3);
		glBegin(GL_LINE_STRIP);
 
		for (int i = 0; i <= 180; i++)
		{
			angle = i * 3.14159f / 180.0f;
			glVertex3f(radiusa * cos(angle)/4, radiusa * sin(angle)/4, 0.0f);
		}
		glEnd();
	  glBegin(GL_LINES);
	  glVertex3d(-0.5,0,0);
	  glVertex3d(-0.5,-1,0);
	  glVertex3d(0.5,0,0);
	  glVertex3d(0.5,-1,0);
	  glVertex3d(-0.5,-1,0);
	  glVertex3d(0.5,-1,0);
	  glEnd();
	  glDisable(GL_TEXTURE_2D);
}
  
void drawRectangle(){ 
		  PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		  glEnable(GL_TEXTURE_2D);
		  glBindTexture(GL_TEXTURE_2D, image3a);
		  glLineWidth(3);
		  glBegin(GL_LINE_LOOP);
		  glVertex3d(0,0,0);
		  glVertex3d(1,0,0);
		  glVertex3d(1,1,0);
		  glVertex3d(0,1,0);
		  glEnd();
		  glDisable(GL_TEXTURE_2D);


  }
  
void drawRectangleForWall(){
	  	PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		Point A5=Point(0,0,0);
		Point B5=Point(0.5,0,0);
		Point C5=Point(0.5,2,0);
		Point D5=Point(0,2,0);
		Point E5=Point(0,0,3);
		Point F5=Point(0.5,0,3);
		Point G5=Point(0.5,2,3);
		Point H5=Point(0,2,3);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B5,C5,D5,A5);
		primitiveDrawer.DrawQuad(F5,G5,H5,E5);
		primitiveDrawer.DrawQuad(E5,H5,D5,A5);
		primitiveDrawer.DrawQuad(F5,G5,C5,B5);
		primitiveDrawer.DrawQuad(B5,F5,E5,A5);
		primitiveDrawer.DrawQuad(C5,G5,H5,D5);
		glDisable(GL_TEXTURE_2D);


  }
  
void drawTallRectangleForWall(){
    	PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		Point A5=Point(0,0,0);
		Point B5=Point(0.5,0,0);
		Point C5=Point(0.5,4,0);
		Point D5=Point(0,4,0);
		Point E5=Point(0,0,0.5);
		Point F5=Point(0.5,0,0.5);
		Point G5=Point(0.5,4,0.5);
		Point H5=Point(0,4,0.5);
		glEnable(GL_TEXTURE_2D);
		//	glBindTexture(GL_TEXTURE_2D, image);    
		primitiveDrawer.DrawQuad(B5,C5,D5,A5);
		primitiveDrawer.DrawQuad(F5,G5,H5,E5);
		primitiveDrawer.DrawQuad(E5,H5,D5,A5);
		primitiveDrawer.DrawQuad(F5,G5,C5,B5);
		primitiveDrawer.DrawQuad(B5,F5,E5,A5);
		primitiveDrawer.DrawQuad(C5,G5,H5,D5);
		glDisable(GL_TEXTURE_2D);  
  }

void DrawWall()
{
	// draw wall 
	  glPushMatrix();
		//glRotated(180,0,1,0);
	  glTranslated(120,0,-26.9);
	  glScalef(4.1, 4.1, 4.1);
		glPushMatrix();
		glTranslated(-2,0,5);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle for the wall
		glPushMatrix();
		glTranslated(-2,0,8);
		drawTallRectangleForWall();
		glPopMatrix();
		//
		glPushMatrix();
		glTranslated(-2,0,8.5);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle2 for the wall
		glPushMatrix();
		glTranslated(-2,0,11.5);
		drawTallRectangleForWall();
		glPopMatrix();
		//
		glPushMatrix();
		glTranslated(-2,0,12);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle2 for the wall
		glPushMatrix();
		glTranslated(-2,0,15);
		drawTallRectangleForWall();
		glPopMatrix();
		//	//
		glPushMatrix();
		glTranslated(-2,0,15.5);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle2 for the wall
		glPushMatrix();
		glTranslated(-2,0,18.5);
		drawTallRectangleForWall();
		glPopMatrix();
			//
		glPushMatrix();
		glTranslated(-2,0,19);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle2 for the wall
		glPushMatrix();
		glTranslated(-2,0,22);
		drawTallRectangleForWall();
		glPopMatrix();
		//	//
		glPushMatrix();
		glTranslated(-2,0,22.5);
		drawRectangleForWall();
		glPopMatrix();
		//draw the tall Rectangle2 for the wall
		glPushMatrix();
		glTranslated(-2,0,25.5);
		drawTallRectangleForWall();
		glPopMatrix();
		
	glPopMatrix();
}

void DrawWindows()
{
	//Draw thw windows behind the wall
   glPushMatrix();
  glTranslated(0,5.5,10);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
   glPushMatrix();
  glTranslated(0,5.5,23);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();

 // draw windows up

  //
  //glPushMatrix();
  //glTranslated(0,9,8);
  //glRotated(90,0,1,0);
  //drawWindow();
  //glPopMatrix();
  
  /*  glPushMatrix();
	glScaled(0.5,0.5,0.5);
  glTranslated(0,9,10);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,12);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,14);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,16);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();

  
    glPushMatrix();
  glTranslated(0,9,18);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,20);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,22);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  
    glPushMatrix();
  glTranslated(0,9,24);
  glRotated(90,0,1,0);
  drawWindow();
  glPopMatrix();
  */

}

void transformNormals(GLfloat& normalX, GLfloat& normalY, GLfloat& normalZ) {
    // Get the model-view matrix
    GLfloat modelViewMatrix[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMatrix);

    // Calculate the normal matrix (inverse transpose of the upper-left 3x3 submatrix)
    GLfloat normalMatrix[9];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            normalMatrix[i * 3 + j] = modelViewMatrix[j * 4 + i];
        }
    }

    // Invert the normal matrix
    GLfloat determinant = normalMatrix[0] * (normalMatrix[4] * normalMatrix[8] - normalMatrix[5] * normalMatrix[7]) -
                         normalMatrix[1] * (normalMatrix[3] * normalMatrix[8] - normalMatrix[5] * normalMatrix[6]) +
                         normalMatrix[2] * (normalMatrix[3] * normalMatrix[7] - normalMatrix[4] * normalMatrix[6]);

    if (determinant != 0) {
        GLfloat invDeterminant = 1 / determinant;
        GLfloat invTransposeNormalMatrix[9];
        invTransposeNormalMatrix[0] = (normalMatrix[4] * normalMatrix[8] - normalMatrix[5] * normalMatrix[7]) * invDeterminant;
        invTransposeNormalMatrix[1] = (normalMatrix[2] * normalMatrix[7] - normalMatrix[1] * normalMatrix[8]) * invDeterminant;
        invTransposeNormalMatrix[2] = (normalMatrix[1] * normalMatrix[5] - normalMatrix[2] * normalMatrix[4]) * invDeterminant;
        invTransposeNormalMatrix[3] = (normalMatrix[5] * normalMatrix[6] - normalMatrix[3] * normalMatrix[8]) * invDeterminant;
        invTransposeNormalMatrix[4] = (normalMatrix[0] * normalMatrix[8] - normalMatrix[2] * normalMatrix[6]) * invDeterminant;
        invTransposeNormalMatrix[5] = (normalMatrix[2] * normalMatrix[3] - normalMatrix[0] * normalMatrix[5]) * invDeterminant;
        invTransposeNormalMatrix[6] = (normalMatrix[3] * normalMatrix[7] - normalMatrix[4] * normalMatrix[6]) * invDeterminant;
        invTransposeNormalMatrix[7] = (normalMatrix[1] * normalMatrix[6] - normalMatrix[0] * normalMatrix[7]) * invDeterminant;
        invTransposeNormalMatrix[8] = (normalMatrix[0] * normalMatrix[4] - normalMatrix[1] * normalMatrix[3]) * invDeterminant;

        // Use the transformed normal matrix to transform the normals
        GLfloat transformedNormalX = invTransposeNormalMatrix[0] * normalX + invTransposeNormalMatrix[1] * normalY + invTransposeNormalMatrix[2] * normalZ;
        GLfloat transformedNormalY = invTransposeNormalMatrix[3] * normalX + invTransposeNormalMatrix[4] * normalY + invTransposeNormalMatrix[5] * normalZ;
        GLfloat transformedNormalZ = invTransposeNormalMatrix[6] * normalX + invTransposeNormalMatrix[7] * normalY + invTransposeNormalMatrix[8] * normalZ;

        // Update the original normals with the transformed normals
        normalX = transformedNormalX;
        normalY = transformedNormalY;
        normalZ = transformedNormalZ;
    }
}

void drawDome(GLfloat radius, Point* center, GLuint texture) {
    // Save the current OpenGL state
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Implement dome drawing logic using triangles
    const int stacks = 180;  // Vertical stacks for hemisphere
    const int slices = 360;  // Horizontal slices for hemisphere

    const float pi = 3.1415926f;
    const float invSlices = 1.0f / slices;
    const float invStacks = 1.0f / stacks;

    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= stacks / 2; i++) {
        const float phi1 = pi * static_cast<float>(i) * invStacks;
        const float sinPhi1 = sinf(phi1);
        const float cosPhi1 = cosf(phi1);

        const float texCoordY1 = static_cast<float>(i) * invStacks;

        for (int j = 0; j <= slices; j++) {
            const float theta = 2.0f * pi * static_cast<float>(j) * invSlices;
            const float sinTheta = sinf(theta);
            const float cosTheta = cosf(theta);

            // Calculate Cartesian coordinates
            const float x = radius * sinPhi1 * cosTheta;
            const float y = radius * sinPhi1 * sinTheta;
            const float z = radius * cosPhi1;

            // Calculate normals
             GLfloat normalX = x / radius;
             GLfloat normalY = y / radius;
             GLfloat normalZ = z / radius;

            // Apply transformations to normals using the normal matrix
            transformNormals(normalX, normalY, normalZ);

            // Calculate and draw the texture coordinates
            const GLfloat texCoordX = static_cast<float>(j) * invSlices;

            // Draw the vertex
            glNormal3f(normalX, normalY, normalZ);
            glTexCoord2f(texCoordX, texCoordY1);
            glVertex3f(center->getX() + x, center->getY() + y, center->getZ() + z);

            // Calculate the coordinates for the next stack
            if (i < stacks / 2) {
                const float phi2 = pi * static_cast<float>(i + 1) * invStacks;
                const float sinPhi2 = sinf(phi2);
                const float cosPhi2 = cosf(phi2);

                const float texCoordY2 = static_cast<float>(i + 1) * invStacks;

                // Calculate Cartesian coordinates for the next stack
                const float xNext = radius * sinPhi2 * cosTheta;
                const float yNext = radius * sinPhi2 * sinTheta;
                const float zNext = radius * cosPhi2;

                // Calculate normals for the next stack
                 GLfloat normalXNext = xNext / radius;
                 GLfloat normalYNext = yNext / radius;
                 GLfloat normalZNext = zNext / radius;

                // Apply transformations to normals using the normal matrix
                transformNormals(normalXNext, normalYNext, normalZNext);

                // Draw the next vertex
                glNormal3f(normalXNext, normalYNext, normalZNext);
                glTexCoord2f(texCoordX, texCoordY2);
                glVertex3f(center->getX() + xNext, center->getY() + yNext, center->getZ() + zNext);
            }
        }
    }
    glEnd();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);

    // Restore the previous OpenGL state
    glPopAttrib();
}

void drawCylinder(GLfloat radius, GLfloat height, Point* center, GLuint texture) {
    // Save the current OpenGL state
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Implement cylinder drawing logic using quads
    const int segments = 360;
    glBegin(GL_QUADS);

    for (int i = 0; i < segments; i++) {
        float angle1 = 2.0f * 3.1415926f * float(i) / segments;
        float x1 = radius * cosf(angle1);
        float y1 = radius * sinf(angle1);
        float angle2 = 2.0f * 3.1415926f * float(i + 1) / segments;
        float x2 = radius * cosf(angle2);
        float y2 = radius * sinf(angle2);

        // Calculate normals
        GLfloat normalX1 = x1 / radius;
        GLfloat normalY1 = y1 / radius;
        GLfloat normalZ1 = 0.0f;

        GLfloat normalX2 = x2 / radius;
        GLfloat normalY2 = y2 / radius;
        GLfloat normalZ2 = 0.0f;

        // Apply transformations to normals using the normal matrix
        transformNormals(normalX1, normalY1, normalZ1);
        transformNormals(normalX2, normalY2, normalZ2);

        // Calculate and draw the texture coordinates and vertices
        GLfloat texCoordX1 = static_cast<float>(i) / segments;
        GLfloat texCoordY1 = 0.0f;
        GLfloat texCoordX2 = static_cast<float>(i + 1) / segments;
        GLfloat texCoordY2 = 0.0f;

        // Bottom-left vertex
        glNormal3f(normalX1, normalY1, normalZ1);
        glTexCoord2f(texCoordX1, texCoordY1);
        glVertex3f(center->getX() + x1, center->getY() + y1, center->getZ());
        
        // Bottom-right vertex
        glNormal3f(normalX2, normalY2, normalZ2);
        glTexCoord2f(texCoordX2, texCoordY2);
        glVertex3f(center->getX() + x2, center->getY() + y2, center->getZ());

        // Top-right vertex
        glNormal3f(normalX2, normalY2, normalZ2);
        glTexCoord2f(texCoordX2, 1.0f);
        glVertex3f(center->getX() + x2, center->getY() + y2, center->getZ() + height);
        
        // Top-left vertex
        glNormal3f(normalX1, normalY1, normalZ1);
        glTexCoord2f(texCoordX1, 1.0f);
        glVertex3f(center->getX() + x1, center->getY() + y1, center->getZ() + height);
    }
    glEnd();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);

    // Restore the previous OpenGL state
    glPopAttrib();
}

void DrawCilinders() 
{
//draw cylinders 
	glPushMatrix();
	glTranslated(15,25,75);
	glRotated(90,1,0,0);
	//	drawCylinder(2,25,new Point(0,0,0),image15);

	/*glEnable(GL_TEXTURE_2D);
	//// drawMyCylinder(GLUquadric *quadric, float x, float y, float z, float baseRadius,
	//// float topRadius,float height, float xRotate, float yRotate, float zRotate)
    glBindTexture(GL_TEXTURE_2D, image);
    drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
	glDisable(GL_TEXTURE_2D);*/
		glPushMatrix();
		 glTranslated(20,0,0);
		drawCylinder(2,25,new Point(0,0,0),hajar);

	/*	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image);
		 drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
		 glDisable(GL_TEXTURE_2D);*/
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(15,25,50);
	glRotated(90,1,0,0);
		drawCylinder(2,25,new Point(0,0,0),hajar);
	/*glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image);
    drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
	glDisable(GL_TEXTURE_2D);*/
		glPushMatrix();
		 glTranslated(20,0,0);
		//drawCylinder(2,25,new Point(0,0,0),image15);

		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image);
		 drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
		 glDisable(GL_TEXTURE_2D);*/
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslated(15,25,25);
	glRotated(90,1,0,0);
		drawCylinder(2,25,new Point(0,0,0),hajar);
	/*glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image);
    drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
	glDisable(GL_TEXTURE_2D);*/
		glPushMatrix();
		 glTranslated(20,0,0);
		//drawCylinder(2,25,new Point(0,0,0),image15);

		/*glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image);
		 drawMyCylinder(quadric, 0, 0, 0, 1, 1, 25, 90, 0, 0);
		 glDisable(GL_TEXTURE_2D);*/
		glPopMatrix();

	glPopMatrix();

}

void drawdrawar1(int width )
{
  glPushMatrix();
  for(int i=0 ; i<6 ; i++)
  {
    glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, image15);
      glBegin(GL_QUADS);
        // Front face
      glTexCoord2d(0, 0);
        glVertex3f(-0, 0, 0);
      glTexCoord2d(3, 0);
        glVertex3f(+width, 0, 0);
      glTexCoord2d(3, 1);
      glVertex3f(+width, -2, 0);//
      glTexCoord2d(0, 1);
      glVertex3f(-0, -2, 0);//
      glEnd();
      glDisable(GL_TEXTURE_2D);
      
      glEnable(GL_TEXTURE_2D);
      glBindTexture(GL_TEXTURE_2D, image15);
      glBegin(GL_QUADS);
        // Front face
      glTexCoord2d(0, 0);
        glVertex3f(0, -2, 5);//
      glTexCoord2d(3, 0);
        glVertex3f(+width, -2, 5);//
      glTexCoord2d(3, 1);
      glVertex3f(+width,-2, 0);
      glTexCoord2d(0, 1);
      glVertex3f(0, -2, 0);
      glEnd();
      glDisable(GL_TEXTURE_2D);
      glTranslated(0,-2,5);
  }
  //glBegin(GL_QUADS);
  //glTexCoord2d(0, 0);
  //      glVertex3f(-0, 12, 30);
  //    glTexCoord2d(3, 0);
  //      glVertex3f(+width, 12, 30);
  //    glTexCoord2d(3, 1);
  //    glVertex3f(+width, 12, 30);//
  //    glTexCoord2d(0, 1);
  //    glVertex3f(-0, 12, 30);//
  // glEnd();
  glPopMatrix();
}

void DrawQantara()
{
	for (float angle = 179; angle > 0; angle -=1) {
      float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
      float DEG_TO_RAD2 = (angle+1) * (3.14159265358979323846 / 180.0);
      float x = cos(DEG_TO_RAD) * 3;
      float y = sin(DEG_TO_RAD) * 3;
    float xx = cos(DEG_TO_RAD) * 2;
      float yy = sin(DEG_TO_RAD) * 2;
    float x1 = cos(DEG_TO_RAD2) * 3;
      float y1 = sin(DEG_TO_RAD2) * 3;
    float xx1 = cos(DEG_TO_RAD2) * 2;
      float yy1 = sin(DEG_TO_RAD2) * 2;
    glBegin(GL_QUADS);
      glVertex3f(x, y, 0);
      glVertex3f(x1, y1, 0);
      glVertex3f(xx1, yy1, 0);
      glVertex3f(xx, yy, 0);
    glEnd();
  }
  glPushMatrix();
  glTranslated(0 , 0 , 1);
  for (float angle = 179; angle > 0; angle -=1) {
      float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
      float DEG_TO_RAD2 = (angle+1) * (3.14159265358979323846 / 180.0);
      float x = cos(DEG_TO_RAD) * 3;
      float y = sin(DEG_TO_RAD) * 3;
    float xx = cos(DEG_TO_RAD) * 2;
      float yy = sin(DEG_TO_RAD) * 2;
    float x1 = cos(DEG_TO_RAD2) * 3;
      float y1 = sin(DEG_TO_RAD2) * 3;
    float xx1 = cos(DEG_TO_RAD2) * 2;
      float yy1 = sin(DEG_TO_RAD2) * 2;
    glBegin(GL_QUADS);
      glVertex3f(x, y, 0);
      glVertex3f(x1, y1, 0);
      glVertex3f(xx1, yy1, 0);
      glVertex3f(xx, yy, 0);
    glEnd();
  }
  glPopMatrix();
  for (float angle = 179; angle > 0; angle -=1) {
      float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
      float DEG_TO_RAD2 = (angle+1) * (3.14159265358979323846 / 180.0);
      float x = cos(DEG_TO_RAD) * 2;
      float y = sin(DEG_TO_RAD) * 2;
    float x1 = cos(DEG_TO_RAD2) * 2;
      float y1 = sin(DEG_TO_RAD2) * 2;

    glBegin(GL_QUADS);
      glVertex3f(x, y, 0);
      glVertex3f(x1, y1, 0);
      glVertex3f(x1, y1, 1);
      glVertex3f(x, y, 1);
    glEnd();
  }
      glBegin(GL_QUADS);
      glVertex3f(-3, 0, 0);
      glVertex3f(-3, 0, 1);
      glVertex3f(-3, 3, 1);
      glVertex3f(-3, 3, 0);
    glEnd();

    glPushMatrix();
    glTranslated(6,0,0);
    glBegin(GL_QUADS);
      glVertex3f(-3, 0, 0);
      glVertex3f(-3, 0, 1);
      glVertex3f(-3, 3, 1);
      glVertex3f(-3, 3, 0);
    glEnd();
    glPopMatrix();
    glBegin(GL_QUADS);
      glVertex3f(-3, 3, 0);
      glVertex3f(-3, 3, 1);
      glVertex3f(3, 3, 1);
      glVertex3f(3, 3, 0);
    glEnd();
    //////
    for (float angle = 179; angle > 0; angle -=1) {
      float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
      float DEG_TO_RAD2 = (angle+1) * (3.14159265358979323846 / 180.0);
      float x = cos(DEG_TO_RAD) * 3;
      float y = sin(DEG_TO_RAD) * 3;
    float x1 = cos(DEG_TO_RAD2) * 3;
      float y1 = sin(DEG_TO_RAD2) * 3;
    glBegin(GL_QUADS);
      glVertex3f(x, y, 0);
      glVertex3f(x1, y1, 0);
      glVertex3f(x1, 3, 0);
      glVertex3f(x, 3, 0);
    glEnd();

    glBegin(GL_QUADS);
      glVertex3f(x, y, 1);
      glVertex3f(x1, y1, 1);
      glVertex3f(x1, 3, 1);
      glVertex3f(x, 3, 1);
    glEnd();
    ///////
    }
}

 void MyDrawQantara(int redues)
        { 
            for (float angle = 180; angle >= -5; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * redues;//3
        	    float y = sin(DEG_TO_RAD) * redues;//3
        		float xx = cos(DEG_TO_RAD) * (redues-1);//2
        	    float yy = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * redues;//3
        	    float y1 = sin(DEG_TO_RAD2) * redues;//3
        		float xx1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float yy1 = sin(DEG_TO_RAD2) * (redues-1);//2
        		glBegin(GL_QUADS);
			   glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(x, y, 0);
				glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(x1, y1, 0);
				glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(xx1, yy1, 0);
				glTexCoord2f(0.0f, 0.1f);
        	    glVertex3f(xx, yy, 0);
        		glEnd();
        	}
        	glPushMatrix();
        	glTranslated(0 , 0 , 1);
        	for (float angle = 180; angle >= -5; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * redues;//3
        	    float y = sin(DEG_TO_RAD) * redues;//3
        		float xx = cos(DEG_TO_RAD) * (redues-1);//2
        	    float yy = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * redues;//3
        	    float y1 = sin(DEG_TO_RAD2) * redues;//3
        		float xx1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float yy1 = sin(DEG_TO_RAD2) * (redues-1);//2
        		glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(x, y, 0);
				glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(x1, y1, 0);
				glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(xx1, yy1, 0);
				glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(xx, yy, 0);
        		glEnd();
        	}
        	glPopMatrix();
        	for (float angle = 180; angle >= -5; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * (redues-1);//2
        	    float y = sin(DEG_TO_RAD) * (redues-1);//2
        		float x1 = cos(DEG_TO_RAD2) * (redues-1);//2
        	    float y1 = sin(DEG_TO_RAD2) * (redues-1);//2
        
        		glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(x, y, 0);
				glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(x1, y1, 0);
				glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(x1, y1, 1);
				glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(x, y, 1);
        		glEnd();
        	   }
        	    glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(-redues, 0, 0);
				glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(-redues, 0, 1);
				glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(-redues, redues, 1);
				 glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(-redues, redues, 0);
				glEnd();
        		glPushMatrix();
				glTranslated(2*redues,0,0);
        		glBegin(GL_QUADS);
			    glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(-redues, 0, 0);
				 glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(-redues, 0, 1);
				 glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(-redues, redues, 1);
				 glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(-redues, redues, 0);
        		glEnd();
        		glPopMatrix();

        		glBegin(GL_QUADS);
				 glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(-redues, redues, 0);
				 glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(-redues, redues, 1);
				 glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(redues, redues, 1);
				 glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(redues, redues, 0);
        		glEnd();
        		////
        		for (float angle = 180; angle >= -5; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x = cos(DEG_TO_RAD) * (redues);//3
        	    float y = sin(DEG_TO_RAD) * (redues);//3
        		float x1 = cos(DEG_TO_RAD2) * (redues);//3
        	    float y1 = sin(DEG_TO_RAD2) * (redues);//3
        		glBegin(GL_QUADS);
				 glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(x, y, 0);
				 glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(x1, y1, 0);
				 glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(x1, redues, 0);
				 glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(x, redues, 0);
        		glEnd();
        
        		glBegin(GL_QUADS);
				 glTexCoord2f(0.0f, 0.0f);
        	    glVertex3f(x, y, 1);
				 glTexCoord2f(1.0f, 0.0f);
        	    glVertex3f(x1, y1, 1);
				 glTexCoord2f(1.0f, 1.0f);
        	    glVertex3f(x1, redues, 1);
				 glTexCoord2f(0.0f, 1.0f);
        	    glVertex3f(x, redues, 1);
        		glEnd();
        		///////
        		}
			
            
        }
		
void DrawAlQibaly()
{
	glPushMatrix();
	glScaled(1.3,1.2,1);
	glTranslated(7.8,-11.5,-51);
	glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		MyDrawQantara(16);
		MyDrawQantara(15);
		MyDrawQantara(14);
		MyDrawQantara(13);
		MyDrawQantara(12);
		MyDrawQantara(11);
		MyDrawQantara(10);


		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
		glTranslated(-10,-15,-50);

	glPushMatrix();
	glScaled(0.8,0.75,1.2);
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();
	glPushMatrix();

		//drawCylinder(20,20,new Point(0,0,0),image);
		PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		Point A1=Point(0,0,0);
		Point B1=Point(50,0,0);
		Point C1=Point(50,25,0);
		Point D1=Point(0,25,0);
		Point E1=Point(0,0,100);
		Point F1=Point(50,0,100);
		Point G1=Point(50,25,100);
		Point H1=Point(0,25,100);

		Point A2=Point(-1,-1,-1);
		Point B2=Point(51,-1,-1);
		Point C2=Point(51,26,-1); 
		Point D2=Point(-1,26,-1);
		Point E2=Point(-1,-1,101);
		Point F2=Point(51,-1,101);
		Point G2=Point(51,26,101);
		Point H2=Point(-1,26,101);
		
		Point AW2=Point(0.2,0,0);
		Point BW2=Point(29.8,0,0);
		Point CW2=Point(29.8,3,0);
		Point DW2=Point(0.2,3,0);
		Point EW2=Point(0.2,0,5);
		Point FW2=Point(29.8,0,5);
		Point GW2=Point(29.8,3,5);
		Point HW2=Point(0.2,3,5);

  	
		Point A12=Point(-2,0,5);
		Point B12=Point(0,0,5);
		Point C12=Point(0,10,5);
		Point D12=Point(-2,10,5);
		Point E12=Point(-2,0,3);
		Point F12=Point(0,0,3);
		Point G12=Point(0,10,3);
		Point H12=Point(-2,10,3);
	
		Point A3=Point(-2,0,3);
		Point B3=Point(0,0,3);
		Point C3=Point(0,8,3);
		Point D3=Point(-2,8,3);
		Point E3=Point(-2,0,1);
		Point F3=Point(0,0,1);
		Point G3=Point(0,8,1);
		Point H3=Point(-2,8,1);

		//the outer 
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image8);    
		//primitiveDrawer.DrawQuad(B2,C2,D2,A2);
		//glDisable(GL_TEXTURE_2D);


		/*curven d;
		d.curve(15);*/


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(F2,G2,H2,E2);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
	//	primitiveDrawer.DrawQuad(E2,H2,D2,A2);
		//primitiveDrawer.DrawQuad(F2,G2,C2,B2);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    		
		primitiveDrawer.DrawQuad(B2,F2,E2,A2);
		primitiveDrawer.DrawQuad(C2,G2,H2,D2);
		glDisable(GL_TEXTURE_2D);
	 
		
		//the inner
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image5);
		//primitiveDrawer.DrawQuad(B1,C1,D1,A1);
		//glDisable(GL_TEXTURE_2D);

		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image3a);    
		////primitiveDrawer.DrawQuad(E1,H1,D1,A1);
		////primitiveDrawer.DrawQuad(F1,G1,C1,B1);
		//glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image4);    
		primitiveDrawer.DrawTheSidesOfTheQibaly(F1,G1,H1,E1);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image16);    
		primitiveDrawer.DrawTheRoof(C1,G1,H1,D1);
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		primitiveDrawer.DrawTheFloor(B1,F1,E1,A1);
		glDisable(GL_TEXTURE_2D);
		
		//Draw_Skybox(0, 0, 0, 600, 600, 600);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		glPushMatrix();
		glTranslated(18,33,-1.5);
		//DrawArch();	
		glPushMatrix();
		glTranslated(14,0,0);
		//DrawArch();	
			glPushMatrix();
			glTranslated(-7,0,0);
			//DrawArch();	
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, kobaa);
   glPushMatrix();
   glTranslated(25,33,75);
   glRotated(90,1,0,0);
   DrawCircle();
   glPopMatrix();
   glDisable(GL_TEXTURE_2D);
   
	//draw cylinder & ball
	glPushMatrix();
	glTranslated(25,30,75);
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, image);   
	//drawBall();
	//glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(0,0,25);
	glRotated(-90,1,0,0);
	drawDome(20,new Point(0,25,0),kobaa);
	glPopMatrix();
	////drawMyCylinder(GLUquadric *quadric, float x, float y, float z, float baseRadius, float topRadius, float height, float xRotate, float yRotate, float zRotate)
	//drawCylinder(GLfloat radius, GLfloat height, Point* center, GLuint texture)
	/*glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image3);*/

	glPushMatrix();
	glRotated(90,1,0,0);
    //drawMyCylinder(quadric, 0, -0.01, 0, 20, 20, 5, 90, 0, 0);
	drawCylinder(20,5,new Point(0,0,0),hajar);
	//glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0,26,50); 
	DrawRoof();
 
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(25,55,75);
	glPushMatrix();
	glRotated(90,1,0,0);
	//glEnable(GL_TEXTURE_2D);
 //   glBindTexture(GL_TEXTURE_2D, image);
   // drawMyCylinder(quadric, 0, -0.01, 0, 0.5, 0.5, 5, 90, 0, 0);
	drawCylinder(0.5,5,new Point(0,0,0),image15);
	glPopMatrix();
	//glDisable(GL_TEXTURE_2D);
	
	    glPushMatrix();
	    glTranslated(0,2.2,0);
	    glRotated(-300,0,0,1);
		
	DrawOurMoon();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	 DrawCilinders();


	 ///////الدرج الي بقلب القبلي 



	 glPushMatrix();
	 glTranslated(30,0,90);




			glPushMatrix();
			glTranslated(-25.2,0,0);
			glScaled(0.5,1,0.5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(B12,C12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,H12,E12);
			primitiveDrawer.DrawQuad(E12,H12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,C12,B12);
			primitiveDrawer.DrawQuad(B12,F12,E12,A12);
			primitiveDrawer.DrawQuad(C12,G12,H12,D12);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-30,0,0);
			glScaled(0.5,1,0.5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(B12,C12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,H12,E12);
			primitiveDrawer.DrawQuad(E12,H12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,C12,B12);
			primitiveDrawer.DrawQuad(B12,F12,E12,A12);
			primitiveDrawer.DrawQuad(C12,G12,H12,D12);
			glDisable(GL_TEXTURE_2D);

			glPushMatrix();
			//glTranslated(-2,8.5,3.1);
			glTranslated(-2.1,10,3.1);
			glScaled(0.395,0.3,0.36);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			//primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			//primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			//primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			//primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			//primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			//primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-25.1,4,6);
			glRotated(180,0,1,0);
			glScaled(0.395,0.3,0.15);
			drawdrawar1(15);
			glPopMatrix();
		


			glPushMatrix();
			glTranslated(0,3,4.42);
			glPushMatrix();
			glTranslated(-25.2,0,0);
			glScaled(0.5,1,0.5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(B12,C12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,H12,E12);
			primitiveDrawer.DrawQuad(E12,H12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,C12,B12);
			primitiveDrawer.DrawQuad(B12,F12,E12,A12);
			primitiveDrawer.DrawQuad(C12,G12,H12,D12);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-30,0,0);
			glScaled(0.5,1,0.5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(B12,C12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,H12,E12);
			primitiveDrawer.DrawQuad(E12,H12,D12,A12);
			primitiveDrawer.DrawQuad(F12,G12,C12,B12);
			primitiveDrawer.DrawQuad(B12,F12,E12,A12);
			primitiveDrawer.DrawQuad(C12,G12,H12,D12);
			glDisable(GL_TEXTURE_2D);

			glPushMatrix();
			glTranslated(-2.1,10,3.1);
			glScaled(0.395,0.3,0.36);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);

			
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();


			glPushMatrix();
			glTranslated(-1,0,97.1);
			glRotated(90,0,1,0);
		
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawTriangle(Point(0,0,0),Point(5.5,0,0),Point(0,5,0));
			glPushMatrix();
			glTranslated(0,0,5.89);
			primitiveDrawer.DrawTriangle(Point(0,0,0),Point(5.5,0,0),Point(0,5,0));
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-1.1,9.5,97.1);
			glRotated(90,0,1,0);
			primitiveDrawer.DrawTriangle(Point(0,0,0),Point(5.5,0,0),Point(0,5,0));
			glPushMatrix();
			glTranslated(0,0,6);
			primitiveDrawer.DrawTriangle(Point(0,0,0),Point(5.5,0,0),Point(0,5,0));
			glPopMatrix();
			glPopMatrix(); 
			glDisable(GL_TEXTURE_2D);



			glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15); 
			glTranslated(1.9,10,91.5);
			glScaled(0.955,1.2,0.8);
			MyDrawQantara(3.5);
			glDisable(GL_TEXTURE_2D);

			glPopMatrix();




	 ////////////////////////////////////////////////////////////////////

	/*
	//dont un comment here
		Point A2=Point(-1,-1,-1);
		Point B2=Point(51,-1,-1);
		Point C2=Point(51,26,-1);
		Point D2=Point(-1,26,-1);
		Point E2=Point(-1,-1,101);
		Point F2=Point(51,0,101);
		Point G2=Point(51,26,101);
		Point H2=Point(-1,26,101);
	*/
		
		//inner checked
		Point AM1=Point(0,0,0);
		Point BM1=Point(50,0,0);
		Point CM1=Point(50,25,0);
		Point DM1=Point(0,25,0);
		Point EM1=Point(0,0,100);
		Point FM1=Point(50,0,100);
		Point GM1=Point(50,25,100);
		Point HM1=Point(0,25,100);
		
		glPushMatrix();
		glTranslated(50,0 ,0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image4);
		primitiveDrawer.DrawTheSidesOfTheQibaly(BM1,CM1,DM1,AM1);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image9);
		//primitiveDrawer.DrawQuad(EM1,HM1,DM1,AM1);
		primitiveDrawer.DrawQuad(FM1,GM1,HM1,EM1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image3a);
		primitiveDrawer.DrawTheSidesOfTheQibaly(FM1,GM1,CM1,BM1);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image17);    
		primitiveDrawer.DrawTheRoof(CM1,GM1,HM1,DM1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		primitiveDrawer.DrawTheFloor(B1,F1,E1,A1);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();	

		//the end of the inner

		//the outer masjed
		Point AM2=Point(-1,-1,-1);
		Point BM2=Point(51,-1,-1);
		Point CM2=Point(51,26,-1);
		Point DM2=Point(-1,26,-1);
		Point EM2=Point(-1,-1,101);
		Point FM2=Point(51,-1,101);
		Point GM2=Point(51,26,101);
		Point HM2=Point(-1,26,101);

		glPushMatrix();
		glTranslated(51,0,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);
		primitiveDrawer.DrawQuad(FM2,GM2,HM2,EM2);
		//primitiveDrawer.DrawQuad(EM2,HM2,DM2,AM2);
		primitiveDrawer.DrawQuad(BM2,FM2,EM2,AM2);
		primitiveDrawer.DrawQuad(CM2,GM2,HM2,DM2);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, outRightWall);

		primitiveDrawer.DrawQuad(BM2,CM2,DM2,AM2);
		glDisable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, outRightWall );
		primitiveDrawer.DrawQuad(FM2,GM2,CM2,BM2);
		glDisable(GL_TEXTURE_2D);


		glPopMatrix();

		
		////the back wall
		//Point AM4=Point(0,0,0);
		//Point BM4=Point(25,0,0);
		//Point CM4=Point(25,45,0);
		//Point DM4=Point(0,45,0);
		//Point EM4=Point(0,0,250);
		//Point FM4=Point(25,0,250);
		//Point GM4=Point(25,45,250);
		//Point HM4=Point(0,45,250); 
		//glPushMatrix();
		//glTranslated(-120,0,-2);
		//glRotated(90,0,1,0);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, image15);
		//primitiveDrawer.DrawQuad(BM4,CM4,DM4,AM4);
		//primitiveDrawer.DrawQuad(FM4,GM4,HM4,EM4);
		//primitiveDrawer.DrawQuad(EM4,HM4,DM4,AM4);
		//primitiveDrawer.DrawQuad(FM4,GM4,CM4,BM4);
		//primitiveDrawer.DrawQuad(BM4,FM4,EM4,AM4);
		//primitiveDrawer.DrawQuad(CM4,GM4,HM4,DM4);
		//glDisable(GL_TEXTURE_2D);

		//glPopMatrix();

		glPushMatrix();
		glTranslated(52,0,0);
		DrawCilinders();
		glPopMatrix();


	//	///////////////

		glPushMatrix();
		glTranslated(-50,0 ,0);

		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image4);
		primitiveDrawer.DrawTheSidesOfTheQibaly(BM1,CM1,DM1,AM1);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image9);
		//primitiveDrawer.DrawQuad(FM1,GM1,CM1,BM1);
		primitiveDrawer.DrawQuad(FM1,GM1,HM1,EM1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image3a);
		primitiveDrawer.DrawTheSidesOfTheQibaly(EM1,HM1,DM1,AM1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image17);    
		primitiveDrawer.DrawTheRoof(CM1,GM1,HM1,DM1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		primitiveDrawer.DrawTheFloor(B1,F1,E1,A1);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();	

		glPushMatrix();
		glTranslated(-51,0,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, outRightWall);
		primitiveDrawer.DrawQuad(BM2,CM2,DM2,AM2);

		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);
		primitiveDrawer.DrawQuad(FM2,GM2,HM2,EM2);

		//primitiveDrawer.DrawQuad(FM2,GM2,CM2,BM2);
		primitiveDrawer.DrawQuad(CM2,GM2,HM2,DM2);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, outRightWall );
		primitiveDrawer.DrawQuad(EM2,HM2,DM2,AM2);

		primitiveDrawer.DrawQuad(BM2,FM2,EM2,AM2);
		glDisable(GL_TEXTURE_2D);


		glPopMatrix();

			glPushMatrix();
		glTranslated(-52,0,0);
		DrawCilinders();
		glPopMatrix();
	/// end Ali



		//the 2 on the side
		glPushMatrix();

		glTranslated(107,0,70);

		glScaled(2,2,2);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B3,C3,D3,A3);
		primitiveDrawer.DrawQuad(F3,G3,H3,E3);
		primitiveDrawer.DrawQuad(E3,H3,D3,A3);
		primitiveDrawer.DrawQuad(F3,G3,C3,B3);
		primitiveDrawer.DrawQuad(B3,F3,E3,A3);
		primitiveDrawer.DrawQuad(C3,G3,H3,D3);
		glDisable(GL_TEXTURE_2D);
	
		glPopMatrix();




	/////don't un comment here
	//glPushMatrix();	
	//	glTranslated(-2,7,4);
	//	DrwaCircle2();
	//glPopMatrix();
	//Second Rectangle	
	//glPushMatrix();
	//glTranslated(1,0,26);
	//glRotated(90,0,1,0);
	////glColor3d(1,1,0);

	///// un comment them
	//Point A4=Point(-1,-1,-1);
	//Point B4=Point(6,-1,-1);
	//Point C4=Point(6,11,-1);
	//Point D4=Point(-1,11,-1);
	//Point E4=Point(-1,-1,30);
	//Point F4=Point(6,0,30);
	//Point G4=Point(6,11,30);
	//Point H4=Point(-1,11,30);
	////the outer 
	//	primitiveDrawer.DrawQuad(B4,C4,D4,A4);
	//	primitiveDrawer.DrawQuad(F4,G4,H4,E4);
	//	primitiveDrawer.DrawQuad(E4,H4,D4,A4);
	//	primitiveDrawer.DrawQuad(F4,G4,C4,B4);
	//	primitiveDrawer.DrawQuad(B4,F4,E4,A4);
	//	primitiveDrawer.DrawQuad(C4,G4,H4,D4);
	//	glPopMatrix();
	//	///the inner
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, image3a);    
	//	primitiveDrawer.DrawQuad(B3,C3,D3,A3);
	//	primitiveDrawer.DrawQuad(F3,G3,H3,E3);
	//	primitiveDrawer.DrawQuad(E3,H3,D3,A3);
	//	primitiveDrawer.DrawQuad(F3,G3,C3,B3);
	//	primitiveDrawer.DrawQuad(B3,F3,E3,A3);
	//	primitiveDrawer.DrawQuad(C3,G3,H3,D3);
	//	glDisable(GL_TEXTURE_2D);

		/*
	Point A6=Point(-1,-1,-1);
	Point B6=Point(6,-1,-1);
	Point C6=Point(6,11,-1);
	Point D6=Point(-1,11,-1);
	Point E6=Point(-1,-1,21);
	Point F6=Point(6,0,21);
	Point G6=Point(6,11,21);
	Point H6=Point(-1,11,21);
	//the outer 
		primitiveDrawer.DrawQuad(B6,C6,D6,A6);
		primitiveDrawer.DrawQuad(F6,G6,H6,E6);
		primitiveDrawer.DrawQuad(E6,H6,D6,A6);
		primitiveDrawer.DrawQuad(F6,G6,C6,B6);
		primitiveDrawer.DrawQuad(B6,F6,E6,A6);
		primitiveDrawer.DrawQuad(C6,G6,H6,D6);
	*/

	
	//the inner
	/*
	////un comment
//Draw the arch
    glPushMatrix();
    glTranslated(-0.01,5,8);
	glRotated(90,0,4,0);
	DrawArch();
  glPopMatrix();	
	//second arch
  glPushMatrix();
    glTranslated(-0.01,5,13);
	glRotated(90,0,4,0);
	DrawArch();
  glPopMatrix();
	//third arch
  glPushMatrix();
    glTranslated(-0.01,5,18);
	glRotated(90,0,4,0);
	DrawArch();
  glPopMatrix();
  //fourth
    glPushMatrix();
    glTranslated(-0.01,5,23);
	glRotated(90,0,4,0);
	DrawArch();
  glPopMatrix();
  //front arch 
   glPushMatrix();
    glTranslated(3,5,27);
	DrawArch();
  glPopMatrix();	
	//second arch
   glPushMatrix();
    glTranslated(8,5,27);
	DrawArch();
  glPopMatrix();
  //fourht arch
   glPushMatrix();
    glTranslated(22,5,27);
	DrawArch();
  glPopMatrix();
  //fifth arch
   glPushMatrix();
    glTranslated(27,5,27);
	DrawArch();
  glPopMatrix();

   //fifth arch
   glPushMatrix();
    glTranslated(15,5,27);
	DrawArch1();
  glPopMatrix();

  
 //   glPushMatrix();
 //   glTranslated(0,5,23);
  //glRotated(90,0,4,0);
	//DrawArch();
 // glPopMatrix();

  /*
  
  /*
  draw rectangle windows
   glPushMatrix();
  glTranslated(0,1.5,7.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
	glPushMatrix();
  glTranslated(0,1.5,9.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,12.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,14.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,17.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,19.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,22.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	
		glPushMatrix();
  glTranslated(0,1.5,24.5);
  glRotated(90,0,1,0);
	drawRectangle();
	glPopMatrix();
	*/
 /* glPushMatrix();
  glTranslated(103,-5,0);
  glScaled(2,2,2);
	DrawWindows();
	glPopMatrix();*/

  //////end of the un comment 

		DrawWall();
		
		/*glPushMatrix();
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);
		glTranslated(68,0,95);
		glScaled(2,2.6,2);

		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPushMatrix();
		glTranslated(10,0,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-8,0,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-30,0,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-42,0,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-51,0,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPushMatrix();
		glTranslated(-60,-0.4,0);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glScaled(1.5,1.5,1.5);
		glTranslated(1.5,0,64);
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();*/

		////dont un comment here
	//glPushMatrix();
 // glTranslated(4,9,27.1);
 // //glRotated(90,0,1,0);
 // //drawWindow();
 // glPopMatrix();
		

		glPopMatrix();
		glPopMatrix();
		glPopMatrix();


		glPopMatrix();



}

void drawHonoraryMinaret()
{
	glPushMatrix();
			drawMyCube(-190,30,290,10,60,10,0,0,0);
			drawMyCube(-190,60,290,20,1,20,0,0,0);
			glPushMatrix();
			glTranslated(0,-10,0);
			drawMyCube(-190,60,290,20,1,20,0,0,0);
			glPopMatrix();
			glPopMatrix();
			

			glPushMatrix();
			glTranslated(9.5,-4.375,9.5);
			drawMyCube(-190,60,290,0.5,9.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-9.5,-4.375,9.5);
			drawMyCube(-190,60,290,0.5,9.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-9.5,-4.375,-9.5);
			drawMyCube(-190,60,290,0.5,9.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(9.5,-4.375,-9.5);
			drawMyCube(-190,60,290,0.5,9.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,-8.5,10);
			drawMyCube(-190,60,290,20,2.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,-8.5,-10);
			//glRotated(90,0,1,0);
			
			drawMyCube(-190,60,290,20,2.5,0.5,0,0,0);
			glPopMatrix();


			glPushMatrix();
			glTranslated(10,-8.5,0);
			//drawMyCube(-190,60,290,20,2.5,0.5,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-0.5,0,0);
			glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(-100,-8.5,-489.5);
			drawMyCube(-190,60,290,20,2.5,0.5,0,0,0);
			glPopMatrix();
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(19.5,0,0);
			glPushMatrix();
			glRotated(90,0,1,0);
			glTranslated(-100,-8.5,-489.5);
			drawMyCube(-190,60,290,20,2.5,0.5,0,0,0);
			glPopMatrix();
			glPopMatrix();


			glPushMatrix();
			glTranslated(-190,65,290);
			glRotated(90,1,0,0);
			drawCylinder(4,6,new Point(0,0,0),img);
		    glPopMatrix();

			glPushMatrix();
			glTranslated(-190,65,290);
			glPushMatrix();
			glRotated(-90,1,0,0);
			drawDome(4, new Point(0,0,0), black);
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();
}

void DrawAlMaroani()
{

 //////////////////////////////////////////المصلى المرواني 
		glPushMatrix();


		glScaled(1,1,1);
	
glPushMatrix();
glPushMatrix();
glPushMatrix();
glPushMatrix();
	PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
		Point A1=Point(0,0,0);
		Point B1=Point(50,0,0);
		Point C1=Point(50,25,0);
		Point D1=Point(0,25,0);
		Point E1=Point(0,0,100);
		Point F1=Point(50,0,100);
		Point G1=Point(50,25,100);
		Point H1=Point(0,25,100);

		Point A2=Point(-1,-1,-1);
		Point B2=Point(51,-1,-1);
		Point C2=Point(51,26,-1); 
		Point D2=Point(-1,26,-1);
		Point E2=Point(-1,-1,101);
		Point F2=Point(51,-1,101);
		Point G2=Point(51,26,101);
		Point H2=Point(-1,26,101);
		
		Point AW2=Point(0.2,0,0);
		Point BW2=Point(29.8,0,0);
		Point CW2=Point(29.8,3,0);
		Point DW2=Point(0.2,3,0);
		Point EW2=Point(0.2,0,5);
		Point FW2=Point(29.8,0,5);
		Point GW2=Point(29.8,3,5);
		Point HW2=Point(0.2,3,5);

  	
		Point A12=Point(-2,0,5);
		Point B12=Point(0,0,5);
		Point C12=Point(0,10,5);
		Point D12=Point(-2,10,5);
		Point E12=Point(-2,0,3);
		Point F12=Point(0,0,3);
		Point G12=Point(0,10,3);
		Point H12=Point(-2,10,3);
	
		Point A3=Point(-2,0,3);
		Point B3=Point(0,0,3);
		Point C3=Point(0,8,3);
		Point D3=Point(-2,8,3);
		Point E3=Point(-2,0,1);
		Point F3=Point(0,0,1);
		Point G3=Point(0,8,1);
		Point H3=Point(-2,8,1);
		Point Am1=Point(100,-102,100);
		Point Bm1=Point(250,-102,100);
		Point Cm1=Point(250,-2,100);
		Point Dm1=Point(100,-2,100);
		Point Em1=Point(100,-102,-200);
		Point Fm1=Point(250,-102,-200);
		Point Gm1=Point(250,-2,-200);
		Point Hm1=Point(100,-2,-200);


		Point Em11(100,-95,-35);
		Point Hm11=Point(100,-69,-35);
		Point Dm11=Point(100,-69,90);
		Point Am11=Point(100,-95,90);

		Point Em12(100,-90,-35);
		Point Hm12=Point(100,-64,-35);
		Point Dm12=Point(100,-64,70);
		Point Am12=Point(100,-90,70);
		
			//inner things

		//Point Am2=Point();





		glPushMatrix();
		//glTranslated(0 ,-28,101);
		//glRotated(90,0,1,0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);
		primitiveDrawer.DrawQuad(Bm1,Cm1,Dm1,Am1);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);
		primitiveDrawer.DrawQuad(Fm1,Gm1,Cm1,Bm1);

		glDisable(GL_TEXTURE_2D);

glPushMatrix();
	glTranslated(-0.2,0,1);

		//// البواط
		//glPushMatrix();
//		glTranslated(0,-5,0);
		//glPushMatrix();
		//glTranslated(0,-70.9,35);
		//glScaled(1,0.17,0.35);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, maroani1);    
		//primitiveDrawer.DrawRightWall(Fm1,Gm1,Cm1,Bm1);
		//glDisable(GL_TEXTURE_2D);
		//glPopMatrix();
		////البواب  
		glPushMatrix();
		glTranslated(120.2,2,0);
		//glScaled(1,1,0.70);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, maroani2);    
		primitiveDrawer.DrawLeftWall(Em11,Hm11,Dm11,Am11);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		//glPopMatrix();

		glPushMatrix();
		glTranslated(150,2,0);
		//glScaled(1,1,0.70);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, maroani1);    
		primitiveDrawer.DrawLeftWall(Em11,Hm11,Dm11,Am11);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(Em1,Hm1,Dm1,Am1);
		glDisable(GL_TEXTURE_2D);


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(Fm1,Gm1,Hm1,Em1);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(Cm1,Gm1,Hm1,Dm1);
		glDisable(GL_TEXTURE_2D);
		
		glPushMatrix();
		glRotated(180,0,1,0);
		glTranslated(-350,0,100);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image2);
		primitiveDrawer.DrawTheFloor(Bm1,Fm1,Em1,Am1);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPopMatrix();




		glPushMatrix();
		glTranslated(220,-101.9,-40);
		glScaled(1,3,1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
		primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
		primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

			glPushMatrix();
			glTranslated(220,-98.9,-40);
			glTranslated(0,-3,-5);


			glScaled(1,2,1);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			glPushMatrix();
			glTranslated(220,-95.9,-40);

			glTranslated(0,-6,-10);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			
		glPopMatrix();

			glPushMatrix();
			//glTranslated(-0.1,-6,0);
			glTranslated(220,-101.9,-35);
			glScaled(1.001,3,27);
			//glTranslated(0,-3,-5);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			glDisable(GL_TEXTURE_2D);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image12);    
			primitiveDrawer.DrawTheFloorForCaredor(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();



		glPushMatrix();
		glTranslated(300,-92.9,79);
		glScaled(2,2.6,2);
		glPushMatrix();
		glTranslated(-25.2,0,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
		glPushMatrix();
		glTranslated(-37.8,0,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);
		
		glPopMatrix();
		glPopMatrix();


		//glTranslated(250,-65,83);
		//glRotated(90,0,0,1);
		//glScaled(2,2.7,2);

		////glScaled(0.9,1,1);
		///*primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
		//primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
		//primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		//primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
		//primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
		//primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);*/
		//primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		//primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		//primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		//primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		//primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		//primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		
			glPushMatrix();
			glTranslated(220,-67,85);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
				glPushMatrix();
				glTranslated(5,3,0);
				glScaled(0.7,1,1);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, image15);    
				primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
				primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
				primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
				primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
				primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
				primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();

				glPushMatrix();
				glTranslated(11,6,0);
				glScaled(0.3,1,1);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, image15);    
				primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
				primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
				primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
				primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
				primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
				primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
			glPopMatrix();



		///////////////////////////////////////////////////////////////////////////////////////////////////
		glPushMatrix();
		glTranslated(220,-92.9,80);
		glScaled(1,3,1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
		primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
		primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
			glPushMatrix();
			glTranslated(220,-92.9,75);
			//glTranslated(0,-3,0);
			glScaled(1,2,1);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
			glPushMatrix();
			glTranslated(220,-92.9,70);
			//glTranslated(0,-6,0);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glTranslated(220,-92.9,85);
		glScaled(1,3,3);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
		primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
		primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

glPopMatrix();




		
		//for delete
		glPushMatrix();
		//glTranslated(219.8,-85,50);
		//glScaled(1,3,3);
		glTranslated(220,-85,-35);
		glScaled(1.001,6,24.2);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);  
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		////// كمالة البواط
		//glPushMatrix();
		//glTranslated(0,-5,0);
		//glPushMatrix();
		//glTranslated(0,-70.9,35);
		//glScaled(1,0.17,0.35);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, maroani1);    
		//primitiveDrawer.DrawRightWall(Fm1,Gm1,Cm1,Bm1);
		//glDisable(GL_TEXTURE_2D);
		//glPopMatrix();
		//////كمالة البواب
		//glPushMatrix();
		//glTranslated(120,2,0);
		////glScaled(1,1,0.70);
		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, maroani2);    
		//primitiveDrawer.DrawLeftWall(Em11,Hm11,Dm11,Am11);
		//glDisable(GL_TEXTURE_2D);
		//glPopMatrix();
		//glPopMatrix();

		glPushMatrix();
		glTranslated(195.9,-100,-150);
		glScaled(1.8,11,20);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image14);    
		primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();
		glScaled(0.45,1.08,1);
		glTranslated(0,-0.2,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glScaled(1,1,0.7);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glTranslated(13.1,-0.3,5);
		glScaled(1,1.1,0.166);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glTranslated(29.6,-0.3,5);
		glScaled(1,1.1,0.16);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);	
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image12);    
		primitiveDrawer.DrawTheFloorForCaredor(BW2,FW2,EW2,AW2);
		glDisable(GL_TEXTURE_2D);
		glPushMatrix();
		//glTranslated(0,);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glTranslated(12.9,0,5);
		glScaled(0.57,1,0.15);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		
		glPopMatrix();



		glPushMatrix();
		glTranslated(190,-102,-130);
		glScaled(2,3.4,2);
		glRotated(90,0,1,0);

		glPushMatrix();
		glTranslated(-25.2,0,0);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);

		glPopMatrix();
		glPushMatrix();
		glTranslated(-37.8,0,0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, image15);    
		primitiveDrawer.DrawQuad(B12,C12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,H12,E12);
		primitiveDrawer.DrawQuad(E12,H12,D12,A12);
		primitiveDrawer.DrawQuad(F12,G12,C12,B12);
		primitiveDrawer.DrawQuad(B12,F12,E12,A12);
		primitiveDrawer.DrawQuad(C12,G12,H12,D12);
		glDisable(GL_TEXTURE_2D);
			glPushMatrix();
			glTranslated(0,8.5,3);
			glScaled(0.35,0.5,0.3);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, image15);    
			primitiveDrawer.DrawQuad(BW2,CW2,DW2,AW2);   
			primitiveDrawer.DrawQuad(FW2,GW2,HW2,EW2);
			primitiveDrawer.DrawQuad(EW2,HW2,DW2,AW2);
			primitiveDrawer.DrawQuad(FW2,GW2,CW2,BW2);		
			primitiveDrawer.DrawQuad(BW2,FW2,EW2,AW2);
			primitiveDrawer.DrawQuad(CW2,GW2,HW2,DW2);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(209,-2,-39);
		glRotated(90,1,0,0);
		drawCylinder(10,100,new Point(0,0,0),image15);
			glPushMatrix();
			glTranslated(18,-137,0);
			drawCylinder(20,100,new Point(0,0,0),image15);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(120,-2,50);
		glRotated(90,1,0,0);
		drawCylinder(5,100,new Point(0,0,0),image15);
		glTranslated(50,0,0);
		drawCylinder(5,100,new Point(0,0,0),image15);
		glPopMatrix();
			glPushMatrix();
			glTranslated(25,-135,0);
			//drawCylinder(5,100,new Point(0,0,0),image15);
			glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
		//////////////////////////انتهاء المصلى المرواني 









		//glBegin(GL_POLYGON);
		//glVertex3d(0,0,0);//1
		//glVertex3d(40,0,0);//2
		//glVertex3d(40,30,0);//3
		//glVertex3d(0,30,0);//4
		//glVertex3d(0,20,0);//5
		//glVertex3d(10,20,0);//6
		//glVertex3d(10,20,0);//7
		////glVertex3d(0,10,0);//8
		//
		//glEnd();


		//glBegin(GL_POLYGON);
		//glVertex3d(40,0,0);//2

		//glVertex3d(0,0,0);//1
		//glVertex3d(0,10,0);//8
		//glVertex3d(10,10,0);//7
		//glVertex3d(10,20,0);//6
		//glVertex3d(0,20,0);//5
		//glVertex3d(0,30,0);//4
		//glVertex3d(40,30,0);//3
		//glEnd();


	//glBegin(GL_POLYGON);
 //   glVertex2f(-0.8f, -0.8f);
 //   glVertex2f(0.8f, -0.8f);
 //   glVertex2f(0.8f, 0.8f);
 //   glVertex2f(0.4f, 0.8f);
 //   glVertex2f(0.2f, 0.4f); // Hall vertex 1
 //   glVertex2f(-0.2f, 0.4f); // Hall vertex 2
 //   glVertex2f(-0.4f, 0.8f);
 //   glVertex2f(-0.8f, 0.8f);
 //   glEnd();








glPopMatrix();
}
void mghanmeh(){
 //// Draw the base of the minaret (cube)
 //   glColor3f(0.5f, 0.5f, 0.5f);
 //   drawCube(2.0);

 //   // Draw the body of the minaret (cylinder)
 //   glColor3f(0.7f, 0.7f, 0.7f);
 //   glTranslatef(0.0f, 1.5f, 0.0f);
 //   drawCylinder(1.0f, 6.0f, 50);
    // Draw the top section of the minaret (cone)
	glPushMatrix();
	glTranslated(-70,-11,-70);
	glPushMatrix();
    glTranslatef(0, 100, -200);
	glRotated(90,1,0,0);
	drawCylinder(11,90,new Point(0,0,0),image22);
    drawCone(20, 20, 40,imgm3);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,115,-200);
	glRotated(270,1,0,0);
	drawCylinder(7,-15,new Point(0,0,0),imgm2);
	drawDome(7,new Point(0,0,0),imgm1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,78,-200);
	glRotated(90,1,0,0);
	drawCylinder(20,-8,new Point(0,0,0),imgm3);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,97,-200);
	glRotated(90,1,0,0);
	drawCylinder(20,-3,new Point(0,0,0),imgm3);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,130,-200);
	glRotated(90,1,0,0);
	drawCylinder(0.5,8,new Point(0,0,0),image15);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,132,-200);
	glRotated(180,1,0,0);
	DrawOurMoon();
	glPopMatrix();
	glPopMatrix();
		

	

}
void drawWallForSabeel(){
	glPushMatrix();
			glTranslated(0,10,0);
			drawMyCube1(0,0,0,20,8,1,0,0,0);
			glPopMatrix();	

			glPushMatrix();
			glTranslated(7.5,19,0);
			glRotated(90,0,0,1);
			drawMyCube1(0,0,0,10,5,1,0,0,0);
			glPopMatrix();

			glPushMatrix();
			glTranslated(-7.5,19,0);
			glRotated(90,0,0,1);
			drawMyCube1(0,0,0,10,5,1,0,0,0);
			glPopMatrix();


			glPushMatrix();
			glTranslated(0,27,0);
			drawMyCube1(0,0,0,20,8,1,0,0,0);
			glPopMatrix();












}
void drawSabeel(){

	glPushMatrix();
			drawWallForSabeel();
			glPopMatrix();

			glPushMatrix();
			glTranslated(10,0,9.5);
			glRotated(90,0,1,0);
			drawWallForSabeel();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-10,0,9.5);
			glRotated(90,0,1,0);
			drawWallForSabeel();
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,0,19);
			drawWallForSabeel();
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,31,10);
			drawMyCube1(0,0,0,20,1,20,0,0,0);

			glPopMatrix();
			///////////////

			glPushMatrix();
			glTranslated(0,37,10);
			glRotated(90,1,0,0);
			drawCylinder(8,10,new Point(0,0,0),imgm44);
			glPopMatrix();

			glPushMatrix();
			glTranslated(0,37,10);
			glRotated(-90,1,0,0);
			drawDome(8,new Point(0,0,0),imgm44);
			glPopMatrix();

}
void drawBuildings(){
	drawMyCube3(130,7.5,60,20,15,40,0,0,0);
		drawMyCube5(160,5,60,25,10,30,0,0,0);
		drawMyCube5(130,7.5,0,30,15,35,0,0,0);
		drawMyCube4(170,6,5,20,12,40,0,0,0);

		drawMyCube3(120,10,-70,25,20,60,0,0,0);
		glPushMatrix();
		glTranslated(192,0,7.5);
		glRotated(90,0,1,0);
		drawMyCube3(120,7.5,-50,25,15,70,0,0,0);
		glPopMatrix();
		drawMyCube5(150,6,-250,45,12,80,0,0,0);

			drawMyCube3(145,7.5,-170,35,15,30,0,0,0);

			drawMyCube4(80,6.5,-200,40,13,80,0,0,0);

			drawMyCube5(80,5.5,-270,40,11,25,0,0,0);

			 drawMyCube5(10,10,-150,45,20,70,0,0,0);

			 drawMyCube3(10,15,-250,50,30,60,0,0,0);

			 glPushMatrix();
			 glTranslated(100,0,250);
			 drawMyCube3(150,6,-250,45,12,80,0,0,0);
			drawMyCube3(145,7.5,-170,45,15,30,0,0,0);
			 glPopMatrix();

			 glPushMatrix();
			glTranslated(170,0,100);
			drawMyCube(80,6.5,-200,40,13,80,0,0,0);
			drawMyCube(80,5.5,-270,40,11,25,0,0,0);
			 glPopMatrix();





}
void drawAllTrees()
{
	glPushMatrix();
	glTranslated(-40,0,-131);
	glPushMatrix();
			glTranslated(30,0,-20);
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,-40);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,-60);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(30,0,-80);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(50,0,-85);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(70,0,-85);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(90,0,-85);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(110,0,-85);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(90,0,-85);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(30,0,0);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(30,0,20);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(40,0,40);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(40,0,60);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,95);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,110);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(45,0,125);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			
			glPushMatrix();
			glTranslated(55,0,137);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(70,0,137);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(85,0,137);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(100,0,137);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(100,0,30);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();

			glPushMatrix();
			glTranslated(80,0,30);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			glPopMatrix();
			
		//draw trees around the square

			/*glPushMatrix();
			glTranslated(-20,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-35,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-50,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-65,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-80,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-95,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-110,0,-35);
			tree->Draw();
			glPopMatrix();

			glPushMatrix();
			glTranslated(-125,0,-35);
			tree->Draw();
			glPopMatrix();*/
			 //draw trees around the womenMosque11
			 
			 for(int i=0;i<160;i+=20)

			 {   
				glPushMatrix();
			 glTranslated(-235,0,-330+i);
			 //tree->Draw();
			glCallList(1);
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-215,0,-330+i);
			 //tree->Draw();
			glCallList(1);
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-195,0,-330+i);
			 //tree->Draw();
			glCallList(1);
			 glPopMatrix();

			 glPushMatrix();
			 glTranslated(-175,0,-330+i);
			 //tree->Draw();
			glCallList(1);
			 glPopMatrix();
			 }

			 //draw the trees around the wall 
			 
			 for(int i=0;i<=600;i+=20){
			 glPushMatrix();
			glTranslated(120,0,-380+i);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();}
			





			 /////////////////
			 ///////// خلي مايكل يساويها 

			 //draw the trees between the qibily and the alqba 
			  for(int i=0;i<=120;i+=20){
			 glPushMatrix();
			glTranslated(-150+i,0,0);
			//tree->Draw();
			glCallList(1);
			glPopMatrix();
			  }
			//  glPushMatrix();
			//glTranslated(-20,0,15);
			////tree->Draw();
			//glCallList(1);
			//glPopMatrix();
			//
			//  glPushMatrix();
			//glTranslated(-40,0,15);
			////tree->Draw();
			//glCallList(1);
			//glPopMatrix();

			//  glPushMatrix();
			//glTranslated(-60,0,15);
			////tree->Draw();
			//glCallList(1);
			//glPopMatrix();
	//glPopMatrix();

	 //for(int i=0;i<=60;i+=20){
		//	 glPushMatrix();
		//	glTranslated(-80,0,+i);
		//	//tree->Draw();
		//	glCallList(1);
		//	glPopMatrix();
	 //}



}

double k = 0 , l=0 , h=0;
//int mouseY=l,mouseX=k;
int mousex1=-100,mousey1=-100;
int x = 0;

void mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
	glTranslated(0,-10,0);
       if (mouseX){
        k = float((mouseX-520)*1000)/640;
      l = float((mouseY)*150)/640;
      //glTranslated(-k,l,0);
	  //glRotated(k*0.5,0,1,0);
	  MyCamera.RotateY(-k*0.001);
	  //glRotated(-l*0.5,1,0,0);

     }
}

//void mouse(int mousex,int mousey,bool isClicked,bool isRClicked){
//
//  if( mousex1 != -100){
//
//    float dx = mousex - mousex1;
//    float dy = mousey - mousey1;
//
//    MyCamera.RotateY(dx / 4);
//    MyCamera.RotateX(dy / 4);
//  }
//
//  mousex1 = mousex;
//  mousey1 = mousey;
//}
//void mouse(bool* key ,float speed){
//  if (keys[MOUSEEVENTF_XDOWN])
//    MyCamera.RotateX(-1 * speed);
//  if (keys[GLUT_LEFT])
//    MyCamera.RotateX(1 * speed);
//  if (keys['D'])
//    MyCamera.RotateY(-1 * speed);
//  if (keys['A'])
//    MyCamera.RotateY(1 * speed);
//
//}

//void mousex(int mouseX)
//{  
//	for(int i=0;i<=600;i++)
//	{
//	// Calculate rotation angles based on the mouse position
//    float rotationX = float((mouseX - 480) * 0.001);  // Adjust the scale factor as needed
//  
//    // Rotate the scene based on the calculated angles
//    glRotatef(rotationX, 0.0f, 1.0f, 0.0f);  // Rotate around the Y-axis
//
//
//	}
//
//
//}
//
//void mousey(int mouseY)
//{  
//	for(int i=-50;i<=10;i++)
//	{
//	// Calculate rotation angles based on the mouse position
//    float rotationY = float((mouseY - 520) * 0.001);
//
//    // Rotate the scene based on the calculated angles
//    glRotatef(rotationY, 1.0f, 0.0f, 0.0f);  // Rotate around the X-axis
//
//
//	}
//
//
//}
	void drawquba()
{
	const int ee = 8 ; // Number of line segments to approximate the circle
	const float r = 40;    // Radius of the circle
	const int ee1 = 8 ; // Number of line segments to approximate the circle
	const float r1 = 15;    // Radius of the circle
	const float x = 0;   // X-coordinate of the center
	const float y = 0;   // Y-coordinate of the center
	const float hieght =20;

	//////////////////////
	std::vector< Pointa> vx;
	std::vector<Pointa> vy;
	//////////////////////
	//////////////////////
	glDisable(GL_TEXTURE_2D);
	for (int i = 0; i < ee; i++)
    {
        float theta1 = 2 * PI * float(i) / float(ee);
        float theta2 = 2 * PI * float(i + 1) / float(ee);
        float x1 = x + r * cos(theta1);
        float z1 = y + r * sin(theta1);
        float x2 = x + r * cos(theta2);
        float z2 = y + r * sin(theta2);
		Pointa d={x1,z1};
		Pointa d2={x2,z2};
		vx.push_back(d);
		vy.push_back(d2);
		if(i!=2){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, alaqsawall);
		glBegin(GL_QUADS);
		glTexCoord2f(1,0);
        glVertex3f(x1, 0, z1);
		glTexCoord2f(1,1);
        glVertex3f(x1, hieght, z1);
		glTexCoord2f(0,1);
        glVertex3f(x2, hieght, z2);
		glTexCoord2f(0,0);
        glVertex3f(x2, 0, z2);
	    glEnd();
		glDisable(GL_TEXTURE_2D);
		}
		else
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, alaqsawall);
			Pointa interpolatedPoint1 = interpolatePoint(vx[2], vy[2], 0.4);
			glBegin(GL_QUADS);
			glTexCoord2f(1,0);
			glVertex3f(x1, 0, z1);
			glTexCoord2f(1,1);
			glVertex3f(x1, hieght, z1);
			glTexCoord2f(0.6,1);
			glVertex3f(interpolatedPoint1.x, hieght, interpolatedPoint1.y);
			glTexCoord2f(0.6,0);
			glVertex3f(interpolatedPoint1.x, 0, interpolatedPoint1.y);
			
			glEnd();
			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, alaqsawall);
			Pointa interpolatedPoint2 = interpolatePoint(vx[2], vy[2], 0.6);
			glBegin(GL_QUADS);
		    glTexCoord2f(0.6,0.5);
            glVertex3f(interpolatedPoint2.x, hieght/2, interpolatedPoint2.y);
		    glTexCoord2f(0.6,1);
            glVertex3f(interpolatedPoint2.x, hieght, interpolatedPoint2.y);
		    glTexCoord2f(0.4,1);
			glVertex3f(interpolatedPoint1.x, hieght, interpolatedPoint1.y);
			glTexCoord2f(0.4,0.5);
			glVertex3f(interpolatedPoint1.x, hieght/2, interpolatedPoint1.y);
			glDisable(GL_TEXTURE_2D);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, alaqsawall);
			
			glBegin(GL_QUADS);
		    glTexCoord2f(0.4,0);
            glVertex3f(interpolatedPoint2.x, 0, interpolatedPoint2.y);
		    glTexCoord2f(0.4,1);
            glVertex3f(interpolatedPoint2.x, hieght, interpolatedPoint2.y);
		    glTexCoord2f(0,1);
            glVertex3f(x2, hieght, z2);
		    glTexCoord2f(0,0);
            glVertex3f(x2, 0, z2);
	        glEnd();
			glDisable(GL_TEXTURE_2D);
		    Pointa interpolatedPoint3 = interpolatePoint(vx[2], vy[2], 0.5);
		    glPushMatrix();
			glRotated(-22.5,0,1,0);
			glTranslated(0,hieght/2,interpolatedPoint3.y+2.8);

			

		    float cx =interpolatedPoint3.x, cy=interpolatedPoint3.y;
			Pointa interpolatedPointt = interpolatePoint(vx[2], vy[2], 0.16);
			Pointa interpolatedPointt2 = interpolatePoint(vx[2], vy[2], -0.16);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, wow);
			glBegin(GL_QUADS);
			         glTexCoord2d(0,0);
			         glVertex3f(interpolatedPointt2.x,0, 0);
					 glTexCoord2d(0,1);
        	         glVertex3f(interpolatedPointt2.x, 0, 6);
					 glTexCoord2d(1,1);
        	         glVertex3f(10, 0, 6);
					 glTexCoord2d(1,0);
        	         glVertex3f(10,0, 0);
		   glEnd();

		   glBegin(GL_QUADS);
		             glTexCoord2d(0,0);
			         glVertex3f(interpolatedPointt.x,0, 0);
					 glTexCoord2d(0,1);
        	         glVertex3f(interpolatedPointt.x, 0, 6);
					 glTexCoord2d(1,1);
        	         glVertex3f(-10, 0, 6);
					 glTexCoord2d(1,0);
        	         glVertex3f(-10,0, 0);
		   glEnd();
		   glDisable(GL_TEXTURE_2D);
			///////////////////////////////////
			///////////////////////////////////
			///////////////////////////////////
			
        	    float x1x ;//2
        	    float y1y ;//2
        		float x2x ;//2
        	    float y2y ;//2
				float x1x180 ;//2
				float y1y180 ;//2
			int ccd=0;
		    for (float angle = 180; angle >= 0; angle -=2) {
				ccd++;
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle-2) * (3.14159265358979323846 / 180.0);
        	     x1x = cos(DEG_TO_RAD) * (3);//2
        	     y1y = sin(DEG_TO_RAD) * (3);//2
        		 x2x = cos(DEG_TO_RAD2) * (3);//2
        	     y2y = sin(DEG_TO_RAD2) * (3);//2
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, wow);
        		glBegin(GL_QUADS);
				glTexCoord2d((ccd-1)*(0.00555555555555555555555555555556)*2,0);
        	    glVertex3f(x1x, y1y, 0);
				glTexCoord2d((ccd)*(0.00555555555555555555555555555556)*2,0);
        	    glVertex3f(x2x, y2y, 0);
				glTexCoord2d((ccd)*(0.00555555555555555555555555555556)*2,1);
        	    glVertex3f(x2x, y2y, 6);
				glTexCoord2d((ccd-1)*(0.00555555555555555555555555555556)*2,1);
        	    glVertex3f(x1x, y1y, 6);
        		glEnd();
				
				//
				if(angle==180)
				{
					glBegin(GL_QUADS);
					    glTexCoord2d(0,0);
        	            glVertex3f(x1x, y1y, 0);
						glTexCoord2d(1,0);
        	            glVertex3f(interpolatedPointt.x, y1y, 0);
						glTexCoord2d(1,1);
        	            glVertex3f(interpolatedPointt.x, y1y, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(x1x, y1y, 6);
        	    	glEnd();
					x1x180=x1x;
					y1y180=y1y;
				}
				if(angle==0)
				{
					glBegin(GL_QUADS);
					    glTexCoord2d(0,0);
        	            glVertex3f(x2x, y2y, 0);
						glTexCoord2d(1,0);
        	            glVertex3f(interpolatedPointt2.x, y1y, 0);
						glTexCoord2d(1,1);
        	            glVertex3f(interpolatedPointt2.x, y1y, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(x2x, y2y, 6);
        	    	glEnd();
				}
				glDisable(GL_TEXTURE_2D);
        	   }
			////////////////////////////
			////////////////////////////
			////////////////////////////
			////////////////////////////
			
			int cdd=0;
			   for (float angle = 140; angle >= 40; angle -=2) {
				   cdd++;
				    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	        float DEG_TO_RAD2 = (angle-2) * (3.14159265358979323846 / 180.0);
        	        float x = cos(DEG_TO_RAD) * (3.5);//2
        	        float y = sin(DEG_TO_RAD) * (3.5);//2
        	    	float x1 = cos(DEG_TO_RAD2) * (3.5);//2
        	        float y1 = sin(DEG_TO_RAD2) * (3.5);//2
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, wow);
				    if(angle==140)
					{
						glBegin(GL_QUADS);
						glTexCoord2d(0,0);
        	            glVertex3f(x, y, 0);
						glTexCoord2d(0.5,0);
        	            glVertex3f(interpolatedPointt.x, y1-0.3, 0);
						glTexCoord2d(0.5,1);
        	            glVertex3f(interpolatedPointt.x, y1-0.3, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(x, y, 6);
        	    	    glEnd();

						glBegin(GL_QUADS);
						glTexCoord2d(0,0);
        	            glVertex3f(interpolatedPointt.x, y1-0.3, 0);
						glTexCoord2d(0.5,0);
						glVertex3f(interpolatedPointt.x,0, 0);
						glTexCoord2d(0.5,1);
        	            glVertex3f(interpolatedPointt.x, 0, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(interpolatedPointt.x, y1-0.3, 6);
        	    	    glEnd();

						glBegin(GL_POLYGON);
						glTexCoord2d(0,0);
        	            glVertex3f(interpolatedPointt.x, y1-0.3, 6);
						glTexCoord2d(0.5,0);
        	            glVertex3f(x, y, 6);
						glTexCoord2d(0.5,1);
						glVertex3f(x1x180, y1y180, 6);
                        glTexCoord2d(0,1); 
						glVertex3f(interpolatedPointt.x, y1y180, 6);
        	    	    glEnd();
					}
					if(angle==40)
					{
						glBegin(GL_QUADS);
						glTexCoord2d(0,0);
        	            glVertex3f(x1, y1, 0);
						glTexCoord2d(0.5,0);
        	            glVertex3f(interpolatedPointt2.x, y1-0.3, 0);
						glTexCoord2d(0.5,1);
        	            glVertex3f(interpolatedPointt2.x, y1-0.3, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(x1, y1, 6);
        	    	    glEnd();

						glBegin(GL_QUADS);
						glTexCoord2d(0,0);
        	            glVertex3f(interpolatedPointt2.x, y1-0.3, 0);
						glTexCoord2d(0.5,0);
						glVertex3f(interpolatedPointt2.x,0, 0);
						glTexCoord2d(0.5,1);
        	            glVertex3f(interpolatedPointt2.x, 0, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(interpolatedPointt2.x, y1-0.3, 6);
        	    	    glEnd();

						glBegin(GL_POLYGON);
						glTexCoord2d(0,0);
        	            glVertex3f(interpolatedPointt2.x, y1-0.3, 6);
						glTexCoord2d(0.5,0);
        	            glVertex3f(x, y, 6);
						glTexCoord2d(0.5,1);
        	            glVertex3f(x2x, y2y, 6);
						glTexCoord2d(0,1);
        	            glVertex3f(interpolatedPointt2.x, y2y, 6);
        	    	    glEnd();
					}
        	    	glBegin(GL_QUADS);
					glTexCoord2d((cdd-1)*(0.01)*2,0);
        	        glVertex3f(x, y, 0);
					glTexCoord2d((cdd)*(0.01)*2,0);
        	        glVertex3f(x1, y1, 0);
					glTexCoord2d((cdd)*(0.01)*2,1);
        	        glVertex3f(x1, y1, 6);
					glTexCoord2d((cdd-1)*(0.01)*2,1);
        	        glVertex3f(x, y, 6);	
        	    	glEnd();
					
					std::cout<<cdd;
        	       }
			   int counts=0;
			   cdd=0;
			   for (float angle = 140; angle >= 40; angle -=2) {
				   cdd++;
				    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	        float DEG_TO_RAD2 = (angle-2) * (3.14159265358979323846 / 180.0);
        	        float DEG_TO_RAD1 = (180-(counts*(2*1.76470588))) * (3.14159265358979323846 / 180.0);
        	        float DEG_TO_RAD12 = (180-((counts+1)*(2*1.76470588))) * (3.14159265358979323846 / 180.0);
        	        counts++;
					float x = cos(DEG_TO_RAD) * (3.5);//2
        	        float y = sin(DEG_TO_RAD) * (3.5);//2
        	    	float x1 = cos(DEG_TO_RAD2) * (3.5);//2
        	        float y1 = sin(DEG_TO_RAD2) * (3.5);//2

					float x18 = cos(DEG_TO_RAD1) * (3);//2
        	        float y18 = sin(DEG_TO_RAD1) * (3);//2
        	    	float x118 = cos(DEG_TO_RAD12) * (3);//2
        	        float y118 = sin(DEG_TO_RAD12) * (3);//2
					glBegin(GL_QUADS);
					 glTexCoord2d((cdd-1)*(0.01)*2,0);
					 glVertex3f(x, y, 6);
					 glTexCoord2d((cdd)*(0.01)*2,0);
        	         glVertex3f(x1, y1, 6);
					 glTexCoord2d((cdd)*(0.01)*2,0.2);
        	         glVertex3f(x118, y118, 6);
					 glTexCoord2d((cdd-1)*(0.01)*2,0.2);
        	         glVertex3f(x18, y18, 6);
					glEnd();
			   }
			   glDisable(GL_TEXTURE_2D);

			   glPushMatrix();
			   glTranslated(0,-1.2,4);
			   glPushMatrix();
			   glScaled(0.7,2,2);
			   glTranslated(5,0,0);
			   displaya(displays);
			   glTranslated(-10,0,0);
			   displaya(displays);
			   glPopMatrix();
			   glScaled(1,2,1);
			   glTranslated(-8.5,0,1);
			   displaya(displays);
			   glTranslated(17,0,0);
			   displaya(displays);
			  
			   glPopMatrix();


		    glPopMatrix();
		    }





		//if(i==0 ||i==7)
		glEnable(GL_TEXTURE_2D);
	    glBindTexture(GL_TEXTURE_2D, starimage);
		glBegin(GL_TRIANGLES);
        glTexCoord2f(6*0.5f,6* 0.5f);  
        glVertex3f(x, 0, y);
        glTexCoord2f(6*(cos(theta1) + 1.0f) * 0.5f,6*(sin(theta1) + 1.0f) * 0.5f);
        glVertex3f(x1, 0, z1);
        glTexCoord2f(6*(cos(theta2) + 1.0f) * 0.5f, 6*(sin(theta2) + 1.0f) * 0.5f);
        glVertex3f(x2, 0, z2);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	}
	//////////////////
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, black);
	int count=0 , j=0;
	for (int i = 0; i < 240; i++)
		{
			float theta1 = 2 * PI * float(i) / float(240);
			float theta2 = 2 * PI * float(i + 1) / float(240);
			float x1f = x + r1 * cos(theta1);
			float z1f = y + r1 * sin(theta1);
			float x2f = x + r1 * cos(theta2);
			float z2f = y + r1 * sin(theta2);
			Pointa interpolatedPoint1 = interpolatePoint(vx[j], vy[j], (count*0.03333333333333333333333333333333));
			Pointa interpolatedPoint2 = interpolatePoint(vx[j], vy[j], ((count+1)*0.03333333333333333333333333333333));
			glBegin(GL_QUADS);
			glTexCoord2f(0,0);
            glVertex3f(x1f, hieght+5, z1f);
			glTexCoord2f(1,0);
            glVertex3f(x2f, hieght+5, z2f);
			glTexCoord2f(1,1);
			glVertex3f(interpolatedPoint2.x, hieght, interpolatedPoint2.y);
			glTexCoord2f(0,1);
			glVertex3f(interpolatedPoint1.x, hieght, interpolatedPoint1.y);
			glEnd();
			
			glBegin(GL_QUADS);
            glVertex3f(x1f, hieght+5, z1f);
			glVertex3f(x1f, hieght+6.5, z1f);
            glVertex3f(x2f, hieght+6.5, z2f);
            glVertex3f(x2f, hieght+5, z2f);
			
			glEnd();
			count ++;
			if(count==30){count=0;j++;}
			}
	/////////////
	//drawquba2();
	glDisable(GL_TEXTURE_2D);
	renderScene(hieght+6.5 , r1 , gold);
}
void drawquba3()
{
	const int ee = 6 ; // Number of line segments to approximate the circle
	const float r = 6;    // Radius of the circle
	const int ee1 = 8 ; // Number of line segments to approximate the circle
	const float r1 = 15;    // Radius of the circle
	const float x = 0;   // X-coordinate of the center
	const float y = 0;   // Y-coordinate of the center
	const float hieght =5.6;

	//////////////////////
	std::vector< Pointa> vx;
	std::vector<Pointa> vy;
	//////////////////////
	//////////////////////
	glDisable(GL_TEXTURE_2D);
	int count6=1;
	for (int i = 0; i < ee; i++)
    {
		
        float theta1 = 2 * PI * float(i) / float(ee);
        float theta2 = 2 * PI * float(i + 1) / float(ee);
        float x1 = x + r * cos(theta1);
        float z1 = y + r * sin(theta1);
        float x2 = x + r * cos(theta2);
        float z2 = y + r * sin(theta2);
		float x11 = x + (r-1) * cos(theta1);
        float z11 = y + (r-1) * sin(theta1);
        float x22 = x + (r-1) * cos(theta2);
        float z22 = y + (r-1) * sin(theta2);
		float x3 = x + (r-3) * cos(theta1);
        float z3 = y + (r-3) * sin(theta1);
        float x33 = x + (r-3) * cos(theta2);
        float z33 = y + (r-3) * sin(theta2);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, salsla1);
		glBegin(GL_TRIANGLES);
        glTexCoord2f(6*0.5f,6* 0.5f);  
        glVertex3f(x, hieght+0.5+2+2, y);
        glTexCoord2f(6*(cos(theta1) + 1.0f) * 0.5f,6*(sin(theta1) + 1.0f) * 0.5f);
        glVertex3f(x3, hieght+0.5+2+2, z3);
        glTexCoord2f(6*(cos(theta2) + 1.0f) * 0.5f, 6*(sin(theta2) + 1.0f) * 0.5f);
        glVertex3f(x33, hieght+0.5+2+2, z33);
		glEnd();
		Pointa f={x1,z1};
		Pointa s={x2,z2};
		Pointa interpolatedPoint = interpolatePoint(f,s, 0.26666666666666666666666666666667);
		Pointa f2={x11,z11};
		Pointa s2={x22,z22};
		Pointa interpolatedPoint2 = interpolatePoint(f2,s2, 0.22);
		
		glBegin(GL_QUADS);
		glTexCoord2f(0,0.3);
        glVertex3f(x1, hieght, z1);
		glTexCoord2f(1,0.3);
        glVertex3f(x2, hieght, z2);
		glTexCoord2f(1,1*0.7);
        glVertex3f(x2, hieght+0.5, z2);
		glTexCoord2f(0,1*0.7);
        glVertex3f(x1, hieght+0.5, z1);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0,0.3);
        glVertex3f(x11, hieght, z11);
		glTexCoord2f(1,0.3);
        glVertex3f(x22, hieght, z22);
		glTexCoord2f(1,1*0.7);
        glVertex3f(x22, hieght+0.5, z22);
		glTexCoord2f(0,1*0.7);
        glVertex3f(x11, hieght+0.5, z11);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0,0.3);
        glVertex3f(x1, hieght, z1);
		glTexCoord2f(1,0.3);
        glVertex3f(x2, hieght, z2);
		glTexCoord2f(1,1*0.7);
        glVertex3f(x22, hieght, z22);
		glTexCoord2f(0,1*0.7);
        glVertex3f(x11, hieght, z11);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(1,0);
        glVertex3f(x1, hieght+0.5, z1);
		glTexCoord2f(1,0);
        glVertex3f(x11, hieght+0.5, z11);
		glTexCoord2f(1,1);
        glVertex3f(x22, hieght+0.5, z22);
		glTexCoord2f(0,1);
        glVertex3f(x2, hieght+0.5, z2);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(1,0);
        glVertex3f(x1, hieght+0.5, z1);
		glTexCoord2f(1,0);
        glVertex3f(x11, hieght+0.5, z11);
		glTexCoord2f(1,1);
        glVertex3f(x11, hieght+0.5+2, z11);
		glTexCoord2f(0,1);
        glVertex3f(x1, hieght+0.5+2, z1);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(1,0);
        glVertex3f(x2, hieght+0.5, z2);
		glTexCoord2f(1,0);
        glVertex3f(x22, hieght+0.5, z22);
		glTexCoord2f(1,1);
        glVertex3f(x22, hieght+0.5+2, z22);
		glTexCoord2f(0,1);
        glVertex3f(x2, hieght+0.5+2, z2);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
        glVertex3f(x1, hieght+0.5, z1);
		glTexCoord2f(0,1);
        glVertex3f(x1, hieght+0.5+2, z1);
		glTexCoord2f(1*0.26666666666666666666666666666667,1);
        glVertex3f(interpolatedPoint.x, hieght+0.5+2, interpolatedPoint.y);
		glTexCoord2f(1*0.26666666666666666666666666666667,0);
        glVertex3f(interpolatedPoint.x, hieght+0.5, interpolatedPoint.y);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
        glVertex3f(x11, hieght+0.5, z11);
		glTexCoord2f(0,1);
        glVertex3f(x11, hieght+0.5+2, z11);
		glTexCoord2f(1*0.22,1);
        glVertex3f(interpolatedPoint2.x, hieght+0.5+2, interpolatedPoint2.y);
		glTexCoord2f(1*0.22,0);
        glVertex3f(interpolatedPoint2.x, hieght+0.5, interpolatedPoint2.y);
	    glEnd();
		interpolatedPoint =interpolatePoint(f,s,0.73333333333333333333333333333333);
		interpolatedPoint2 = interpolatePoint(f2,s2, 0.78);
		glBegin(GL_QUADS);
		glTexCoord2f(0.73333333333333333333333333333333,0);
        glVertex3f(x2, hieght+0.5, z2);
		glTexCoord2f(0.73333333333333333333333333333333,1);
        glVertex3f(x2, hieght+0.5+2, z2);
		glTexCoord2f(1,1);
        glVertex3f(interpolatedPoint.x, hieght+0.5+2, interpolatedPoint.y);
		glTexCoord2f(1,0);
        glVertex3f(interpolatedPoint.x, hieght+0.5, interpolatedPoint.y);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0.78,0);
        glVertex3f(x22, hieght+0.5, z22);
		glTexCoord2f(0.78,1);
        glVertex3f(x22, hieght+0.5+2, z22);
		glTexCoord2f(1,1);
        glVertex3f(interpolatedPoint2.x, hieght+0.5+2, interpolatedPoint2.y);
		glTexCoord2f(1,0);
        glVertex3f(interpolatedPoint2.x, hieght+0.5, interpolatedPoint2.y);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0.2,1);
        glVertex3f(x3, hieght+0.5+2, z3);
		glTexCoord2f(1-0.2,1);
        glVertex3f(x33, hieght+0.5+2,z33);
		glTexCoord2f(1,0);
        glVertex3f(x2, hieght+0.5+2, z2);
		glTexCoord2f(0,0);
        glVertex3f(x1, hieght+0.5+2,z1);
	    glEnd();
		glBegin(GL_QUADS);
		glTexCoord2f(0,0);
        glVertex3f(x3, hieght+0.5+2, z3);
		glTexCoord2f(1,0);
        glVertex3f(x33, hieght+0.5+2, z33);
		glTexCoord2f(1,1);
        glVertex3f(x33, hieght+0.5+2+2,z33);
		glTexCoord2f(0,1);
        glVertex3f(x3, hieght+0.5+2+2,z3);
	    glEnd();
		renderScene(hieght+0.5+2+2,2 , selver);
		interpolatedPoint = interpolatePoint(f,s, 0.5);
		glPushMatrix();
		glTranslated(interpolatedPoint.x,hieght+0.5,interpolatedPoint.y);
		glRotated(60*count6,0,1,0);
		glDisable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, salsla1);
		int count =1;
		for (float angle = 180; angle >= 0; angle -=5) {
        	    float DEG_TO_RAD = angle * (3.14159265358979323846 / 180.0);
        	    float DEG_TO_RAD2 = (angle+5) * (3.14159265358979323846 / 180.0);
        	    float x81 = cos(DEG_TO_RAD) * 1.4;//3
        	    float y81 = sin(DEG_TO_RAD) * 1.4;//3
        		float xx81 = cos(DEG_TO_RAD2) * (1.4);//2
        	    float yy81 = sin(DEG_TO_RAD2) * (1.4);//2
				
				glBegin(GL_QUADS);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),0);
        	    glVertex3f(x81, y81, -0);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),1);
        	    glVertex3f(x81, y81, -1);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),1);
        	    glVertex3f(xx81, yy81, -1);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),0);
        	    glVertex3f(xx81, yy81, -0);
        		glEnd();
				glBegin(GL_QUADS);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),y81/2);
        	    glVertex3f(x81, y81, 0);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),yy81/2);
        	    glVertex3f(xx81, yy81, 0);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),1);
        	    glVertex3f(xx81, 2, 0);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),1);
        	    glVertex3f(x81, 2, 0);
        		glEnd();
				glBegin(GL_QUADS);
        	    glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),y81/2);
        	    glVertex3f(x81, y81, -1);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),yy81/2);
        	    glVertex3f(xx81, yy81, -1);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*(count+1)),1);
        	    glVertex3f(xx81, 2, -1);
				glTexCoord2f((0.26666666666666666666666666666667)+(0.01296296296296296296296296296296*count),1);
        	    glVertex3f(x81, 2, -1);
        		glEnd();
				count ++;
        	}
		glPopMatrix();


		glDisable(GL_TEXTURE_2D);



		glPushMatrix();
	    glTranslated(0,5,0);
      	glScaled(0.8,1.2,0.8);
		glTranslated(x1,0,z1);
		displaya(displays);
		glPopMatrix();
		count6--;
	}
}
int DrawGLScene(GLvoid)                    // Here's Where We Do All The Drawing
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  
  float c=MyCamera.Render();
  Draw_Skybox(0,0,0,800,800,800);
  Key(keys, 3); 
  
  //glTranslated(2,0,0);
  //glCallList(index);
  /*glTranslated(2,0,0);
  glCallList(index);
  glTranslated(2,0,0);

  glCallList(index);*/
  //drawquba2();
  //drawWall(200,300,15);
  //glScaled(1.4,1,1);
  drawmastaba();
  //drawdrawar(69);-0lo6543
  //drawwamn(200,300,15);
  //glTranslated(0.1,0,0);
  glPushMatrix();
  glTranslated(3,5.2,7.0);
    glRotated(22.5,0,1,0);
  glScaled(0.5,0.5,0.5);
  drawquba();
  glTranslated(0,0,+60);
  drawquba3();
  glScaled(0.7,0.7,0.7);
  drawquba3();
  glPopMatrix();
  		drawTextureWall();

	drawTextureWall1();
	glPushMatrix();
	glTranslated(3,5.2,7.0);
	glRotated(22.5,0,1,0);
	glScaled(0.5,0.5,0.5);
	drawquba();
	glPopMatrix();


	drawBuildings();
	//drawAllTrees();	
	glPushMatrix();	
    mghanmeh();
	glPopMatrix();
	glPushMatrix();
	//glTranslated(10,5,-5);
		//glTranslated(0,20,0);
		

			 glPushMatrix();
			 glTranslated(100,0,-100);
			 
			 glRotated(-90,0,1,0);
			 drawwamn(200,300,15);
			 glPopMatrix();
			 //draw trees around the womenMosque11
			
			


	glPopMatrix();
	//GLuint displayListIndex = glGenLists(1);

	//glRasterPos3f(0, 6 ,0);
 //   
 //   // Display the text
 //   const char* text = "Hello, World!";
 //   for (int i = 0; text[i] != '\0'; i++) {
 //       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
 //   }
	/////////
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glPushMatrix();
	glTranslated(0,15,0);
			drawHonoraryMinaret();
			glPopMatrix();
			
	drawWall(200,300,15);
	drawmastaba();
	//drawdrawar(69);
	drawwamn(200,300,15);
	
	drawboraqwall();
	alrahmabab();

	//glTranslated(0.1,0,0);
     glPushMatrix();
	//glRotated(90,0,1,0);
	glTranslated(45,17,230);
	//glNormal3f(0.0f,0.0f,1.0f);
    DrawAlQibaly();
	glPopMatrix();

	glPushMatrix();
	glTranslated(200,-10,-75);

	glRotated(270,0,1,0);
	DrawAlMaroani();
	glPopMatrix();
	glTranslated(-120,-10,-90);
	glPushMatrix();
	drawWallForSabeel();
	drawSabeel();
	glPopMatrix();
  return TRUE;
}
//void
//int DrawGLScene(GLvoid)  									// Here's Where We Do All The Drawing
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glLoadIdentity();
//
//	//glPushMatrix();
//	//glTranslated(3,5.2,7.0);
//	//glRotated(22.5,0,1,0);
//	//glScaled(0.5,0.5,0.5);
//	//drawquba();
// //   glPopMatrix();
//
//	float c=MyCamera.Render();
//	Key(keys, 3);
//	Draw_Skybox(0,0,0,800,800,800);
//	glPushMatrix();
//	glTranslated(3,5.2,7.0);
//	glRotated(22.5,0,1,0);
//	glScaled(0.5,0.5,0.5);
//	//drawquba();
//	glTranslated(0,0,+60);
//	drawquba3();
//	glScaled(0.7,0.7,0.7);
//	drawquba3();
//    glPopMatrix();
//	//	drawTextureWall();
//
//	//drawTextureWall1();
//	//glPushMatrix();
//	//glTranslated(3,5.2,7.0);
//	//glRotated(22.5,0,1,0);
//	//glScaled(0.5,0.5,0.5);
//	//drawquba();
//	//glPopMatrix();
//
//
//	//drawBuildings();
//	////drawAllTrees();	
//	//glPushMatrix();	
// //   mghanmeh();
//	//glPopMatrix();
//	//glPushMatrix();
//	////glTranslated(10,5,-5);
//	//	//glTranslated(0,20,0);
//	//	
//
//	//		 glPushMatrix();
//	//		 glTranslated(100,0,-100);
//	//		 
//	//		 glRotated(-90,0,1,0);
//	//		 drawwamn(200,300,15);
//	//		 glPopMatrix();
//	//		 //draw trees around the womenMosque11
//	//		
//	//		
//
//
//	//glPopMatrix();
//	////GLuint displayListIndex = glGenLists(1);
//
//	////glRasterPos3f(0, 6 ,0);
// ////   
// ////   // Display the text
// ////   const char* text = "Hello, World!";
// ////   for (int i = 0; text[i] != '\0'; i++) {
// ////       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
// ////   }
//	///////////
//	////glMatrixMode(GL_MODELVIEW);
//	////glLoadIdentity();
//	//glPushMatrix();
//	//glTranslated(0,15,0);
//	//		drawHonoraryMinaret();
//	//		glPopMatrix();
//	//		
//	//drawWall(200,300,15);
//	//drawmastaba();
//	////drawdrawar(69);
//	//drawwamn(200,300,15);
//	//
//	//drawboraqwall();
//	//alrahmabab();
//
//	////glTranslated(0.1,0,0);
// //    glPushMatrix();
//	////glRotated(90,0,1,0);
//	//glTranslated(45,17,230);
//	////glNormal3f(0.0f,0.0f,1.0f);
// //   DrawAlQibaly();
//	//glPopMatrix();
//
//	//glPushMatrix();
//	//glTranslated(200,-10,-75);
//
//	//glRotated(270,0,1,0);
//	//DrawAlMaroani();
//	//glPopMatrix();
//	//glTranslated(-120,-10,-90);
//	//glPushMatrix();
//	//drawWallForSabeel();
//	//drawSabeel();
//	//glPopMatrix();
//	return TRUE;
//}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}
/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
  static PAINTSTRUCT ps;

  switch (uMsg)                  // Check For Windows Messages
  {
 
  case WM_ACTIVATE:              // Watch For Window Activate Message
  {
    if (!HIWORD(wParam))          // Check Minimization State
    {
      active = TRUE;            // Program Is Active
    }
    else
    {
      active = FALSE;            // Program Is No Longer Active
    }

    return 0;                // Return To The Message Loop
  }

  case WM_SYSCOMMAND:              // Intercept System Commands
  {
    switch (wParam)              // Check System Calls
    {
    case SC_SCREENSAVE:          // Screensaver Trying To Start?
    case SC_MONITORPOWER:        // Monitor Trying To Enter Powersave?
      return 0;              // Prevent From Happening
    }
    break;                  // Exit
  }

  case WM_CLOSE:                // Did We Receive A Close Message?
  {
    PostQuitMessage(0);            // Send A Quit Message
    return 0;                // Jump Back
  }

  case WM_KEYDOWN:              // Is A Key Being Held Down?
  {
    keys[wParam] = TRUE;          // If So, Mark It As TRUE
    return 0;                // Jump Back
  }

  case WM_KEYUP:                // Has A Key Been Released?
  {
    keys[wParam] = FALSE;          // If So, Mark It As FALSE
    return 0;                // Jump Back
  }

  case WM_SIZE:                // Resize The OpenGL Window
  {
    ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
    return 0;                // Jump Back
  }
  case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
		isClicked = false; 	 break;
	case WM_RBUTTONUP:
		isRClicked = false;   break;
	case WM_LBUTTONDOWN:
		isClicked = true; 	break;
	case WM_RBUTTONDOWN:
		isRClicked = true;	break;
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;
  }
  return DefWindowProc(hWnd,uMsg,wParam,lParam);

  }
int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	 int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("Example", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
				// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}