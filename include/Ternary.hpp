#ifndef TERNARYCALC_H
#define TERNARYCALC_H

#include "Vector.hpp"
#include <stdexcept>
#include <string>

class Ternary{
public:
    explicit Ternary() : digits(0) {}

    explicit Ternary(const size_t& n, unsigned char a) {
        if (a > 2) throw std::invalid_argument("Digit must be 0, 1, or 2.");
        digits = Vector(n, a);
        validateDigits();
    }

    Ternary(const std::initializer_list<unsigned char>& a) {
        for (size_t i = a.size(); i > 0; i--)
            digits.PushBack(*(a.begin() + (i - 1)));
        validateDigits();
    }

    explicit Ternary(const Vector& a) {
        for (size_t i = 0; i < a.Size(); i++)
            digits.PushBack(a[i]);
        validateDigits();
    }

    explicit Ternary(const std::string& a) {
        for (size_t i = a.size(); i > 0; i--)
            digits.PushBack(a[i - 1] - '0');
        validateDigits();
    }

    ~Ternary() {}

    Ternary(const Ternary& other) : digits(other.digits) {}

    Ternary& operator=(const Ternary& other) {
        if (this != &other) {
            digits = other.getNumber();
        }
        return *this;
    }

    Ternary(Ternary&& other) noexcept : digits(std::move(other.digits)) {}

    Ternary& operator=(Ternary&& other) noexcept {
        if (this != &other) {
            digits = std::move(other.digits);
        }
        return *this;
    }

    Ternary operator+(const Ternary& other) const {
        return Ternary(add(other));
    }

    Ternary operator-(const Ternary& other) const {
        return Ternary(subtract(other));
    }

    bool operator>(const Ternary& other) const {
        Vector otherDigits = other.getNumber();
        if (digits.Size() != otherDigits.Size()) {
            return digits.Size() > otherDigits.Size();
        }
        for (size_t i = digits.Size(); i > 0; --i) {
            if (digits[i - 1] > otherDigits[i - 1]) {
                return true;
            } else if (digits[i - 1] < otherDigits[i - 1]) {
                return false;
            }
        }
        return false;
    }

    bool operator<(const Ternary& other) const {
        return !(*this > other);
    }

    bool operator==(const Ternary& other) const {
        return digits == other.getNumber();
    }

    Ternary& operator+=(const Ternary& other) {
        *this = *this + other;
        return *this;
    }

    Ternary& operator-=(const Ternary& other) {
        *this = *this - other;
        return *this; 
    }

    friend std::ostream& operator<<(std::ostream& os, const Ternary& ternary);

    void setNumber(const Vector& digits);
    Vector getNumber() const;

private:
    Vector add(const Ternary& other) const;
    Vector subtract(const Ternary& other) const;
    void validateDigits();

private:
    Vector digits;
};

#endif
