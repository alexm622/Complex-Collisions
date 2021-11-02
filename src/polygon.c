#include "polygon.h"

#include <stdlib.h>
#include <string.h>

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
    if (i > index || i < index + size) {
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

Polygon *subPolygon(Polygon *p, int index_start, int index_end) {
  Polygon *ply = newPolygon();
  if (index_start > p->numPoints || index_end > p->numPoints ||
      index_end > index_start) {
    return ply;
  }
  for (int i = 0; i < index_end - index_start; i++) {
    addPoint(ply, p->points[index_start + i]);
  }
  return ply;
}
Polygon *combinePolygons(Polygon *p1, Polygon p2) {
  // TODO this function will be more fleshed out when collision detection is
  // implemented so the shapes are polygons
  return newPolygon();
}

Polygon *newPolygon() {
  Polygon *ply = calloc(1, sizeof(Polygon));
  ply->numPoints = 0;
  return ply;
}
Point *newPoint(int x, int y) {
  Point *p = malloc(sizeof(Point));
  p->x = x;
  p->y = y;
  return p;
}

bool freePolygon(Polygon *p) {
  for (int i = 0; i < p->numPoints; i++) {
    freePoint(p->points[i]);
  }
  free(p);
  return true;
}
bool freePoint(Point *p) {
  free(p);
  return true;
}

bool pointsEqual(Point *pt1, Point *pt2) {
  return (pt1->x == pt2->x) && (pt1->y == pt2->y);
}
bool shapesEqual(Polygon *p1, Polygon *p2) {
  if (p1->numPoints != p2->numPoints) {
    return false;
  }
  for (int indexOffset = 0; indexOffset < p1->numPoints; indexOffset++) {
    int numMatches = 0;
    for (int i = 0; i < p1->numPoints; i++) {
      if (pointsEqual(p1->points[i],
                      p2->points[(i + indexOffset) % p2->numPoints])) {
        numMatches++;
      } else {
        break;
      }
    }
    if (numMatches == p1->numPoints) {
      return true;
    }
  }
  return false;
}

Line *pointsToLine(Point *p1, Point *p2) {
  Line *l = malloc(sizeof(Line));
  l->p1 = malloc(sizeof(Point));
  l->p2 = malloc(sizeof(Point));
  l->p1 = memcpy(l->p1, p1, sizeof(Point));
  l->p2 = memcpy(l->p2, p2, sizeof(Point));
  l->exists = true;
  return l;
}
