#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Figure.hpp"
#include "Point.hpp"

class Rectangle : public Figure
{
public:
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
    Point points_[4];
    
    bool isValidRectangle() const;
};

#endif // Rectangle_HPP
