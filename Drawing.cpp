#include "Drawing.h"
#include "ListLinked.h" 

Drawing::Drawing() {
    shapes = new ListLinked<Shape*>(); 

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->insert(shapes->size(), shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* circle = dynamic_cast<Circle*>(shapes->get(i));
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));
        if (square) {
            square->translate(incX, incY);
        }
    }
}
