#include "Rectangle.hpp"
#include <cmath>
#include <iostream>

Rectangle::Rectangle(const Point (&points)[4])
{
    for (int i = 0; i < 4; ++i) {
        points_[i] = points[i];
    }
}

Rectangle::Rectangle(const Rectangle &other)
{
    for (int i = 0; i < 4; ++i) {
        points_[i] = other.points_[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points_[i] = other.points_[i];
        }
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points_[i] = std::move(other.points_[i]);
        }
    }
    return *this;
}

Point Rectangle::geometricCenter() const
{
    double centerX = 0, centerY = 0;
    for (const auto &point : points_)
    {
        centerX += point.x_;
        centerY += point.y_;
    }
    return Point{centerX / 4, centerY / 4};
}

Rectangle::operator double() const
{
    double area = 0;
    for (int i = 0; i < 4; ++i)
    {
        int j = (i + 1) % 4;
        area += points_[i].x_ * points_[j].y_ - points_[j].x_ * points_[i].y_;
    }
    return std::abs(area) / 2;
}

bool Rectangle::operator==(const Figure &other) const
{
    const Rectangle *otherRectangle = dynamic_cast<const Rectangle *>(&other);
    if (!otherRectangle)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        if (points_[i] != otherRectangle->points_[i])
        {
            return false;
        }
    }
    return true;
}

void Rectangle::print(std::ostream& os) const
{
    os << "Rectangle: points = ";
    for (const auto &point : points_)
    {
        os << point << " ";
    }
}

void Rectangle::read(std::istream& is)
{
    Point points[4];
    for (int i = 0; i < 4; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        points_[i] = points[i];
    }
}

bool Rectangle::isValidRectangle() const
{
    const double epsilon = 1e-3;

    double side1 = std::sqrt(std::pow(points_[1].x_ - points_[0].x_, 2) + std::pow(points_[1].y_ - points_[0].y_, 2));
    double side2 = std::sqrt(std::pow(points_[2].x_ - points_[1].x_, 2) + std::pow(points_[2].y_ - points_[1].y_, 2));
    double side3 = std::sqrt(std::pow(points_[3].x_ - points_[2].x_, 2) + std::pow(points_[3].y_ - points_[2].y_, 2));
    double side4 = std::sqrt(std::pow(points_[0].x_ - points_[3].x_, 2) + std::pow(points_[0].y_ - points_[3].y_, 2));

    if (std::abs(side1 - side3) > epsilon || std::abs(side2 - side4) > epsilon) {
        throw std::invalid_argument("Opposite sides are not equal.");
    }

    double dotProduct1 = (points_[1].x_ - points_[0].x_) * (points_[2].x_ - points_[1].x_) + (points_[1].y_ - points_[0].y_) * (points_[2].y_ - points_[1].y_);
    double dotProduct2 = (points_[2].x_ - points_[1].x_) * (points_[3].x_ - points_[2].x_) + (points_[2].y_ - points_[1].y_) * (points_[3].y_ - points_[2].y_);
    double dotProduct3 = (points_[3].x_ - points_[2].x_) * (points_[0].x_ - points_[3].x_) + (points_[3].y_ - points_[2].y_) * (points_[0].y_ - points_[3].y_);
    double dotProduct4 = (points_[0].x_ - points_[3].x_) * (points_[1].x_ - points_[0].x_) + (points_[0].y_ - points_[3].y_) * (points_[1].y_ - points_[0].y_);

    if (std::abs(dotProduct1) > epsilon || std::abs(dotProduct2) > epsilon || std::abs(dotProduct3) > epsilon || std::abs(dotProduct4) > epsilon) {
        throw std::invalid_argument("Not all angles are 90 degrees.");
    }

    return true;
}
