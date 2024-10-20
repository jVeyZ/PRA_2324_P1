#include "Rectangle.h"
#include "Point2D.h"
#include <iostream>
#include <ostream>
#include <stdexcept>

bool Rectangle::check(Point2D* vertices){
    return vertices->distance(vertices[0], vertices[1]) == vertices->distance(vertices[2], vertices[3]) && vertices->distance(vertices[1], vertices[2]) == vertices->distance(vertices[3], vertices[0]);
}
Rectangle::Rectangle(){
    vs = new Point2D[N_VERTICES]();
    vs[0]=Point2D(-1,0.5);
    vs[1]=Point2D(1,0.5);
    vs[2]=Point2D(1,-0.5);
    vs[3]=Point2D(-1,-0.5);
    set_color(get_color());
}
Rectangle::Rectangle(std::string color, Point2D* vertices){
    set_vertices(vertices);
    set_color(color);

}
Rectangle::Rectangle(const Rectangle &r) {
    vs = new Point2D[N_VERTICES]();
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = r.vs[i];
    }
    set_color(r.get_color());
}
Rectangle::~Rectangle(){
    delete[] vs;
}
Point2D Rectangle::get_vertex(int ind) const{
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Invalid Index");
    }
    return vs[ind];
}
Point2D Rectangle::operator[](int ind) const{
    return get_vertex(ind);
}
void Rectangle::set_vertices(Point2D* vertices){
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid rectangle");
    }
    vs = new Point2D[N_VERTICES]();
    vs[0]= vertices[0];
    vs[1]= vertices[1];
    vs[2]= vertices[2];
    vs[3]= vertices[3];

}
Rectangle& Rectangle::operator=(const Rectangle &r){
    if (this == &r) {
        return *this; 
    }
    delete[] vs; 
    new (this) Rectangle(r); 
    return *this;
}
std::ostream& operator<<(std::ostream &out, const Rectangle &r){
    out << "Rectangle vertices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << r.get_vertex(i) << " ";
    }
    out << "\nColor: " << r.get_color();
    return out;
}
double Rectangle::area() const{
    double width = vs[0].distance(vs[0], vs[1]);
    double height = vs[1].distance(vs[1], vs[2]);
    return width * height;
}
double Rectangle::perimeter() const{
    double width = vs[0].distance(vs[0], vs[1]);
    double height = vs[1].distance(vs[1], vs[2]);
    return 2 * (width + height);
}
void Rectangle::translate(double incX, double incY){
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}
void Rectangle::print() {
    std::ostream& out = std::cout;
    out << *this;
}