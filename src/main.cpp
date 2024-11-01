#include <iostream>
#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Rectangle.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

int main()
{
    Point points_trapezoid[4] = { Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2) };
    Point points_rectangle[4] = { Point(0, 0), Point(2, 0), Point(0, 2), Point(2, 2) };
    Point points_rhombus[4] = { Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1) };

    Trapezoid trapezoid(points_trapezoid);
    Rectangle rectangle(points_rectangle);
    Rhombus rhombus(points_rhombus);

    std::cout << "Trapezoid Information: " << std::endl;
    std::cout << trapezoid << std::endl;
    std::cout << "Area: " << static_cast<double>(trapezoid) << std::endl;
    std::cout << "Geometric Center: " << trapezoid.geometricCenter() << std::endl;
    
    std::cout << "\nRectangle Information: " << std::endl;
    std::cout << rectangle << std::endl;
    std::cout << "Area: " << static_cast<double>(rectangle) << std::endl;
    std::cout << "Geometric Center: " << rectangle.geometricCenter() << std::endl;
    
    std::cout << "\nRhombus Information: " << std::endl;
    std::cout << rhombus << std::endl;
    std::cout << "Area: " << static_cast<double>(rhombus) << std::endl;
    std::cout << "Geometric Center: " << rhombus.geometricCenter() << std::endl;

    return 0;
}
