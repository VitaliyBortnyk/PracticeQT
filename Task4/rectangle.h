#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>
#include "math.h"

class Rectangle
{
public:
    double x, y;
    double width, height;
public:
    Rectangle();
    ~Rectangle();
    void SetData(double x, double y, double width, double height);
    double Square();
    void Resize(double width, double height);
    void Move(char direction, double distance);
    static bool Intersection(Rectangle rectA, Rectangle rectB);
    static Rectangle MinRectangle(Rectangle rectA, Rectangle rectB);
    static Rectangle IntersectionRectangle(Rectangle rectA, Rectangle rectB);

};

#endif // RECTANGLE_H
