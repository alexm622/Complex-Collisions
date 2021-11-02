#include "math.h"

#include <stdlib.h>
#include <string.h>

float distance_p(Point *p1, Point *p2) {
  // construct a right triangle using p1 & p2
}

Triangle *newTriangle_2p(Point *p1, Point *p2) {
  Triangle *t = malloc(sizeof(Triangle));
  if (pointsEqual(p1, p2)) {
    t->numPoints = 0;
    return t;
  }
  t->numPoints = 2;
  t->points = calloc(2, sizeof(Point *));
  t->points[0] = memcpy(t->points[0], p1, sizeof(Point));
  t->points[1] = memcpy(t->points[1], p2, sizeof(Point));
}
Triangle *newTriangle_oa(double o, double a) {
  Triangle *t = malloc(sizeof(Triangle));
  t->a = a;
  t->o = o;
  // calculate the hypotenuse
}
