#ifndef RHOMBUS_HPP
#define RHOMBUS_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Rhombus : public Figure
{
public:
    Rhombus() = default;
    Rhombus(const Point (&points)[4]);
    Rhombus(const Rhombus &other);

    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;

    Point geometricCenter() const override;
    double distance(const Point &p1, const Point &p2) const;
    operator double() const override;
    bool operator==(const Figure &other) const override;

    virtual Figure* clone() const override {
        return new Rhombus(*this);
    }

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    Point points_[4];

    bool isValidRhombus() const;
};

#endif // RHOMBUS_HPP
