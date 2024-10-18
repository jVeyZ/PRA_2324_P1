#include "Shape.h"

Shape::Shape(): color("red"){}
Shape::Shape(std::string color){
    set_color(color);
}
std::string Shape::get_color() const{
    return color;
}
void Shape::set_color(std::string c){
    if (c != "red" || c != "green" || c != "blue") {
        throw std::invalid_argument("Color out of range");
    }
    color = c;
}
