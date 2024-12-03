#include <iostream>
#include "Point.hpp"
#include "Trapezoid.hpp"
#include "Rectangle.hpp"
#include "Rhombus.hpp"
#include "FigureArray.hpp"

int main()
{
    Point<double> points_trapezoid[4] = {
        Point<double>(0, 0), Point<double>(4, 0), Point<double>(3, 2), Point<double>(1, 2) 
    };
    Point<double> points_rectangle[4] = {
        Point<double>(0, 0), Point<double>(2, 0), Point<double>(3, 1), Point<double>(0, 1) 
    };
    Point<double> points_rhombus[4] = {
        Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1) 
    };

    Trapezoid<double> trapezoid(points_trapezoid);
    Rectangle<double> rectangle(points_rectangle);
    Rhombus<double> rhombus(points_rhombus);

    auto trapezoid_ptr = std::make_shared<Trapezoid<double>>(points_trapezoid);
    auto rectangle_ptr = std::make_shared<Rectangle<double>>(points_rectangle);
    auto rhombus_ptr = std::make_shared<Rhombus<double>>(points_rhombus);

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

    FigureArray<Figure<double>> figureArray;
    figureArray.add(trapezoid_ptr);
    figureArray.add(rectangle_ptr);
    figureArray.add(rhombus_ptr);

    std::cout << "\nFigures in Array: " << std::endl;
    for (size_t i = 0; i < figureArray.size(); ++i) {
        std::cout << figureArray[i] << std::endl;
    }

    return 0;
}
