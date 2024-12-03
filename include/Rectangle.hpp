#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Figure.hpp"
#include "Point.hpp"
#include <memory>
#include <iostream>
#include <stdexcept>

template <Numeric T>
class Rectangle : public Figure<T>
{
public:
    using figure_base_type = T;
    
    Rectangle() = default;
    Rectangle(const Point (&points)[4]);
    Rectangle(const Rectangle &other);

    Rectangle& operator=(const Rectangle &other);
    Rectangle& operator=(Rectangle &&other) noexcept;

    Point geometricCenter() const override;
    operator double() const override;
    bool operator==(const Figure &other) const override;

    virtual Figure* clone() const override {
        return new Rectangle(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    std::unique_ptr<Point<T>> points_[4];
    
    bool isValidRectangle() const;
};

#include "../src/Pentagon.tpp"

#endif // Rectangle_HPP
