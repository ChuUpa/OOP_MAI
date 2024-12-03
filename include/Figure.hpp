#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "Point.hpp"
#include <iostream>

template <Numeric T>
class Figure
{
public:
    virtual ~Figure() noexcept = default;

    virtual Point geometricCenter() const = 0;
    virtual operator double() const = 0;
    virtual bool operator==(const Figure &other) const = 0;

    virtual Figure* clone() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    
};

template <Numeric T>
std::ostream& operator<<(std::ostream& os, const Figure<T> &fig);

template <Numeric T>
std::istream& operator>>(std::istream& is, Figure<T> &fig);

#include "../src/Figure.tpp"

#endif // FIGURE_HPP
