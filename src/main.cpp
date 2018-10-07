#include <cstdio>

#include "../include/shapes.h"

int main()
{
    Circle c(10.0, 2.0, 5.0);
    Rectangle r(10.0, 3.0);
    Triangle t(18, 30, 24);

    printf("Circle {x : %f, y : %f, radius : %f}, Area : %f, perimeter : %f\n", c.x, c.y, c.radius, c.area(), c.perimeter());
    printf("Rectangle {Width : %f, Height : %f}, Area : %f, perimeter : %f\n", r.width, r.height, r.area(), r.perimeter());
    printf("Triangle {a : %f, b : %f, c : %f}, Area : %f, perimeter : %f\n", t.a, t.b, t.c, t.area(), t.perimeter());

    return 0;
}