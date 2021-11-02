#include "collision.h"

#include <math.h>
#include <stdlib.h>

bool isOnLine(Line *l, Point *p1) {
  double dist_p1 = distance_p(l->p1, p1);
  double dist_p2 = distance_p(l->p2, p1);
  if (dist_p1 == dist_p2) {
    return true;
  }
  return false;
}
bool linesIntersect(Line *l1, Line *l2) {
  if ((isOnLine(l1, l2->p1) || isOnLine(l1, l2->p2)) ||
      (isOnLine(l2, l1->p1) || isOnLine(l2, l1->p2))) {
    return true;
  }

  // test for a verticle line to avoid a divide by zero error
  if (l1->p1->x == l1->p2->x) {
    // verticle line
    if (l2->p1->x > l1->p1->x && l2->p2->x > l1->p1->x) {
      return false;
    } else {
      return true;
    }
  }

  double slope =
      (double)(l1->p2->y - l1->p1->y) / (double)(l1->p2->x - l1->p2->x);
  int offset_y = l1->p1->y;
  int offset_x = l1->p1->x;
  bool slope_direction = slope > 0;
  if (slope_direction) {
    if (l1->p2->y < l2->p1->y && l1->p2->y < l2->p2->y) {
      return 0;
    }
  }

  return false;
}

double distance_p(Point *p1, Point *p2) {
  // construct a triangle using the two points, use pythagoream theorem
  int o = abs(p1->x - p2->x);
  int a = abs(p1->y - p2->y);
  double dist = sqrt(pow(o, 2) + pow(a, 2));
  return dist;
}
