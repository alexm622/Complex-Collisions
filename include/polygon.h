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

bool addPointCords(Polygon* p, int x, int y);
bool addPoint(Polygon* p, Point pt);

bool removePointIndex(Polygon* p, int index);
bool removePointP(Polygon* p, Point* pt);
bool removePointCoords(Polygon* p, int x, int y);
bool removePoints(Polygon* p, int index, int count);

Polygon * subPolygon(Polygon* p, int index_start, int index_end); 
Polygon* combinePolygons(Polygon* p1, Polygon p2);

bool freePolygon(Polygon *p);
bool freePoint(Point *p);

Polygon* newPolygon();
Point* newPoint(int x, int y);




#endif