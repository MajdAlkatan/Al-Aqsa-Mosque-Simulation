
#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "texture.h"
#include "Point.h"
#include "PrimitiveDrawer.h"

PrimitiveDrawer::PrimitiveDrawer(){}

// Draw a point at the given position.
void PrimitiveDrawer::DrawPoint(Point point) {
    glBegin(GL_POINTS);
	glVertex3f(point.x,point.y,point.z);
    glEnd();
  }

 // Draw a line between the given two positions.
void PrimitiveDrawer::DrawLine(Point start, Point end) {
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
  }

 // Draw a triangle with the given three vertices.
void PrimitiveDrawer::DrawTriangle(Point v1, Point v2, Point v3) {
   glBegin(GL_TRIANGLES);
		glTexCoord2f(0, 0);   

    glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(0.5, 0.5);    

    glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 1);    

    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
  }

// Draw a quadrilateral with the given four vertices.
  void PrimitiveDrawer::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(1, 0);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(1, 1);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 1);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 0);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

  void PrimitiveDrawer::DrawTheFloor(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(10, 10);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(10, 0);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 0);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 10);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

  void PrimitiveDrawer::DrawRightWall(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(5, 0);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(5, 1);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 1);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 0);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

  void PrimitiveDrawer::DrawLeftWall(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(5, 0);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(5, 1);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 1);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 0);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }
   void PrimitiveDrawer::DrawTheFloorForCaredor(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(1, 4.2);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(1, 0);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 0);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 4.2);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

    void PrimitiveDrawer::DrawTheRoof(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(2, 4);   
			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(2, 0);    
			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(0, 0);    
			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(0, 4);     
			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }

	 void PrimitiveDrawer::DrawTheSidesOfTheQibaly(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
			glTexCoord2f(0, 0);    

			glVertex3f(v1.x, v1.y, v1.z);
			glTexCoord2f(0, 1);     

			glVertex3f(v2.x, v2.y, v2.z);
			glTexCoord2f(2, 1);   


			glVertex3f(v3.x, v3.y, v3.z);
			glTexCoord2f(2, 0);    

			glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
  }