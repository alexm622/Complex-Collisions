#include "polygon.h"

#include <stdlib.h>

bool addPointCords(Polygon *p, int x, int y) {
  Point *pt = newPoint(x, y);
  return addPoint(p, pt);
}
bool addPoint(Polygon *p, Point *pt) {
  int size = p->numPoints;
  if (size < 0) {
    // raise and exception
  }
  size++;
  // expand the size of the array
  p->points = realloc(p->points, size * sizeof(Point));
  p->points[size - 1] = pt;
  p->numPoints++;

  return true;
}

bool removePointIndex(Polygon *p, int index) {
  int size = p->numPoints;
  if (index > size - 1) {
    return false;
  }
  if (index == size - 1) {
    // just realloc
    size--;
    p->points = realloc(p->points, size * sizeof(Point));
    p->numPoints--;
    return true;
  }
  for (int i = 0; i < size; i++) {
    if (i < index) {
      continue;
    }
    if (i == index) {
      continue;
    }
    // shift to the left
    p->points[i - 1] = p->points[i];
  }

  size--;
  p->points = realloc(p->points, size * sizeof(Point));
  p->numPoints--;
  return true;
}
bool removePointP(Polygon *p, Point *pt) {
  bool exists = false;
  int index = 0;
  for (int i = 0; i < p->numPoints; i++) {
    if (pointsEqual(pt, p->points[i])) {
      index = i;
      exists = true;
      break;
    }
  }
  if (!exists) {
    return false;
  }

  return removePointIndex(p, index);
}
bool removePointCoords(Polygon *p, int x, int y) {
  return removePointP(p, newPoint(x, y));
}
bool removePoints(Polygon *p, int index, int count) {
  int size = p->numPoints;
  if (index + count > size - 1) {
    return false;
  }
  if (index + count == size - 1) {
    // just realloc
    size -= count;
    p->points = realloc(p->points, size * sizeof(Point));
    p->numPoints = size;
    return true;
  }
  for (int i = 0; i < size; i++) {
    if (i < index) {
      continue;
    }
    if (i == index) {
      continue;
    }
    if (i > index && i < index + size) {
      continue;
    }
    // shift to the left
    p->points[i - count] = p->points[i];
  }

  size -= count;
  p->points = realloc(p->points, size * sizeof(Point));
  p->numPoints -= count;
  return true;
}

Polygon *subPolygon(Polygon *p, int index_start, int index_end) {}
Polygon *combinePolygons(Polygon *p1, Polygon p2) {}

Polygon *newPolygon() {}
Point *newPoint(int x, int y) {
  Point *p = malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

bool freePolygon(Polygon *p) {}
bool freePoint(Point *p) {}

bool pointsEqual(Point *pt1, Point *pt2) {
  return (pt1->x == pt2->x) && (pt1->y == pt2->y);
}
bool shapesEqual(Polygon *p1, Polygon *p2);