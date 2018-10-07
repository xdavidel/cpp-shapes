#include "./shapes.h"

// Circle
Circle::Circle() {}
Circle::Circle(float x, float y, float radius) : x(x), y(y), radius(radius) {}
float Circle::area()
{
    return 3.14159 * radius * radius;
}
float Circle::perimeter()
{
    return 3.14159 * 2 * radius;
}

// Rectangle
Rectangle::Rectangle()
{
}
Rectangle::Rectangle(float width, float height) : width(width), height(height) {}
float Rectangle::area()
{
    return width * height;
}
float Rectangle::perimeter()
{
    return 2 * (width + height);
}

// Triangle
Triangle::Triangle() {}
Triangle::Triangle(float a, float b, float c) : a(a), b(b), c(c) {}
float Triangle::area()
{
    float p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
float Triangle::perimeter()
{
    return a + b + c;
}