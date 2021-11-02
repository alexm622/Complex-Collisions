#ifndef POLYGON_H
#define POLYGON_H

#include <stdbool.h>

typedef struct {
    int x;
    int y;
}Point;

typedef struct {
    int numPoints;
    Point **points;
}Polygon;

typedef struct {
    bool exists;
    Point * p1;
    Point * p2;
}Line;

bool addPointCords(Polygon* p, int x, int y);
bool addPoint(Polygon* p, Point *pt);

bool removePointIndex(Polygon* p, int index);
bool removePointP(Polygon* p, Point* pt);
bool removePointCoords(Polygon* p, int x, int y);
bool removePoints(Polygon* p, int index, int count);

Polygon * subPolygon(Polygon* p, int index_start, int index_end); 
Polygon * combinePolygons(Polygon* p1, Polygon p2);

Polygon * newPolygon();
Point * newPoint(int x, int y);

bool freePolygon(Polygon *p);
bool freePoint(Point *p);

bool pointsEqual(Point *pt1, Point *pt2);
bool shapesEqual(Polygon *p1, Polygon *p2);

Line * pointsToLine(Point *p1, Point *p2);

#endif
