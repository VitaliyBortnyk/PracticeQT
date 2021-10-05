#include "rectangle.h"

Rectangle::Rectangle()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}
Rectangle::~Rectangle(){}

void Rectangle::SetData(double x, double y, double width, double height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

double Rectangle::Square()
{
    return width*height;
}

void Rectangle::Resize(double width, double height)
{
    this->width = width;
    this->height = height;
}

void Rectangle::Move(char direction, double distance)
{
    switch (direction)
    {
        case 'u':{ this->y -= distance; break;}
        case 'd':{ this->y += distance; break;}
        case 'l':{ this->x -= distance; break;}
        case 'r':{ this->x += distance; break;}
        default: break;
    }
}

bool Rectangle::Intersection(Rectangle rectA, Rectangle rectB)
{
    if(((rectA.x + rectA.width) > rectB.x) && ((rectB.x + rectB.width)> rectA.x)
            && ((rectA.y + rectA.height) > rectB.y) && ((rectB.y + rectB.height)> rectA.y))
            return true;

    return false;
}

Rectangle Rectangle::MinRectangle(Rectangle rectA, Rectangle rectB)
{
    Rectangle rect;

    double xMin = 0, xMax = 0, yMin = 0,
           yMax = 0, width = 0, height = 0,
            xMaxWidth = 0, yMaxHeight = 0,
            xEnd = 0, yEnd = 0;

    if((rectA.width && rectB.width && rectA.height && rectB.height) !=0)
    {
        rectA.x < rectB.x ? xMin = rectA.x : xMin = rectB.x;
        rectA.y < rectB.y ? yMin = rectA.y : yMin = rectB.y;

        if(rectA.x + rectA.width < rectB.x + rectB.width)
            {xMax = rectB.x; xMaxWidth = rectB.width;}
        else {xMax = rectA.x; xMaxWidth = rectA.width;}

        if(rectA.y + rectA.height < rectB.y + rectB.height)
            {yMax = rectB.y; yMaxHeight = rectB.height;}
        else {yMax = rectA.y; yMaxHeight = rectA.height;}

        xEnd = xMax + xMaxWidth;
        yEnd = yMax + yMaxHeight;

        width = xEnd - xMin;
        height = yEnd - yMin;

        rect.SetData(xMin, yMin, width, height);
    }
    return rect;
}

Rectangle Rectangle::IntersectionRectangle(Rectangle rectA, Rectangle rectB)
{
    Rectangle rect;

    double xMin = 0, xMax = 0, yMin = 0,
           yMax = 0, width = 0, height = 0,
            xMinWidth = 0, yMinHeight = 0,
            xEnd = 0, yEnd = 0;

    if((rectA.width && rectB.width && rectA.height && rectB.height) !=0
            && Rectangle::Intersection(rectA, rectB) == true)
    {
        rectA.x < rectB.x ? xMax = rectB.x : xMax = rectA.x;
        rectA.y < rectB.y ? yMax = rectB.y : yMax = rectA.y;

        if(rectA.x + rectA.width < rectB.x + rectB.width)
            {xMin = rectA.x; xMinWidth = rectA.width;}
        else {xMin = rectB.x; xMinWidth = rectB.width;}

        if(rectA.y + rectA.height < rectB.y + rectB.height)
            {yMin = rectA.y; yMinHeight = rectA.height;}
        else {yMin = rectB.y; yMinHeight = rectB.height;}

        xEnd = xMin + xMinWidth;
        yEnd = yMin + yMinHeight;

        width = xEnd - xMax;
        height = yEnd - yMax;

        rect.SetData(xMax, yMax, width, height);
    }
    return rect;
}
















