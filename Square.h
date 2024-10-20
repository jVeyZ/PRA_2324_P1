#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square();
    Square(std::string color, Point2D* vertices);
    Square(const Square &s);
    void set_vertices(Point2D* vertices);
    Square& operator=(const Square &s);
    static bool check(Point2D* vertices); // Move check function here
};

#endif // SQUARE_H