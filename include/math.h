#ifndef MATH_H
#define MATH_H

#include <polygon.h>

typedef struct {
    Point ** points;

    int numPoints;
    
    double o;/**opposite*/
    double a;/**adjacent*/
    double h;/**hypotenuse*/

    float a1, a2, a3; /** angle one two three*/
}Triangle;


float distance_p(Point *p1, Point *p2);

Triangle * newTriangle_2p(Point* p1, Point* p2);
Triangle * newTriangle_oa(double o, double a);

#endif
