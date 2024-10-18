#include "Circle.h"
#include "Point2D.h"
#include <cmath>
#include <iostream>


Circle::Circle(): center(0,0), radius(1){
    set_color(color);
}
Circle::Circle(std::string color, Point2D center, double radius){
    set_color(color);
    set_center(center);
    set_radius(radius);
}
Point2D Circle::get_center() const{
    return center;
}
void Circle::set_center(Point2D p){
    center = p;
}
double Circle::get_radius() const{
    return radius;
}
void Circle::set_radius(double r){
    radius = r;
}
std::ostream& operator<<(std::ostream &out, const Circle &c){
    out << "Color: " << c.get_color() << " "
        << "Area: " << c.area() << " "
        << "Center: (" << c.get_center().x << ", " << c.get_center().y << ") "
        << "Radius: " << c.get_radius();
    return out;
}

double Circle::area() const{
    return M_PI*std::pow(radius,2);
}
double Circle::perimeter() const{
    return 2*radius*M_PI;
}
void Circle::translate(double incX, double incY){
    Point2D p(incX+get_center().x,incY+get_center().y);
    set_center(p);
}
void Circle::print(){
    std::ostream& out = std::cout;
    out << *this;
}