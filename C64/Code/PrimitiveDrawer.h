#ifndef PRIMITIVEDRAWER_H
#define PRIMITIVEDRAWER_H

class PrimitiveDrawer {
public:
	PrimitiveDrawer();
	void DrawPoint(Point point);
	void DrawLine(Point start, Point end);
	void DrawTriangle(Point v1, Point v2, Point v3);
	void DrawQuad(Point v1, Point v2, Point v3, Point v4);
	void PrimitiveDrawer::DrawTheFloor(Point v1, Point v2, Point v3, Point v4);
	 void PrimitiveDrawer::DrawRightWall(Point v1, Point v2, Point v3, Point v4);
	 void PrimitiveDrawer::DrawLeftWall(Point v1, Point v2, Point v3, Point v4);
	 void PrimitiveDrawer::DrawTheFloorForCaredor(Point v1, Point v2, Point v3, Point v4);
	 void PrimitiveDrawer::DrawTheRoof(Point v1, Point v2, Point v3, Point v4);
	 void PrimitiveDrawer::DrawTheSidesOfTheQibaly(Point v1, Point v2, Point v3, Point v4);


};

#endif
