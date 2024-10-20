#include <stdexcept>
#include "Point2D.h"
#include "Square.h"


bool Square::check(Point2D* vertices) {
    double d1 = Point2D::distance(vertices[0], vertices[1]);
    double d2 = Point2D::distance(vertices[1], vertices[2]);
    double d3 = Point2D::distance(vertices[2], vertices[3]);
    double d4 = Point2D::distance(vertices[3], vertices[0]);

    return (d1 == d2 && d2 == d3 && d3 == d4 && d1 > 0);
}

Square::Square() {
    vs = new Point2D[N_VERTICES]();
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

Square::Square(std::string color, Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid Square");
    }
    vs = new Point2D[N_VERTICES]();
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
    set_color(color);
}

Square::Square(const Square &s) {
    vs = new Point2D[N_VERTICES]();
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = s.vs[i];
    }
    set_color(s.get_color());
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Invalid Square");
    }
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i] = vertices[i];
    }
}

Square& Square::operator=(const Square &s) {
    if (this != &s) {
        delete[] vs;
        vs = new Point2D[N_VERTICES]();
        for (int i = 0; i < N_VERTICES; ++i) {
            vs[i] = s.vs[i];
        }
        set_color(s.get_color());
    }
    return *this;
}