#include <cmath>

struct Shape
{
    virtual float area() = 0;
    virtual float perimeter() = 0;
};

struct Circle : public Shape
{
    float x;
    float y;
    float radius;

    Circle();

    Circle(float x, float y, float radius);

    float area();
    float perimeter();
};

struct Rectangle : public Shape
{
    float width;
    float height;

    Rectangle();
    Rectangle(float width, float heigth);

    float area();
    float perimeter();
};

struct Triangle : public Shape
{
    float a;
    float b;
    float c;

    Triangle();
    Triangle(float a, float b, float c);

    float area();
    float perimeter();
};