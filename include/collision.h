#ifndef COLLISION_H
#define COLLISION_H

#include "polygon.h"

bool isOnLine(Line * l, Point * p1);
bool linesIntersect(Line * l1, Line * l2);

double distance_p(Point *p1, Point *p2);

#endif
