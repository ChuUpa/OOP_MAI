#ifndef TRAPEZOID_HPP
#define TRAPEZOID_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Trapezoid : public Figure
{
public:
    Trapezoid() = default;
    Trapezoid(const Point (&points)[4]);
    Trapezoid(const Trapezoid &other);

    Trapezoid& operator=(const Trapezoid &other);
    Trapezoid& operator=(Trapezoid &&other) noexcept;
    
    Point geometricCenter() const override;
    operator double() const override;
    bool operator==(const Figure &other) const override;

    virtual Figure* clone() const override {
        return new Trapezoid(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    Point points_[4];

    bool isValidTrapezoid() const;
};

#endif // TRAPEZOID_HPP
