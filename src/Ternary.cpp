#include <iostream>
#include <stdexcept>
#include "../include/Ternary.hpp"
#include "../include/Vector.hpp"

void Ternary::setNumber(const Vector& digitsToSet) {
    digits.Clear();
    for (size_t i = digitsToSet.Size(); i > 0; i--)
        digits.PushBack(digitsToSet[i - 1]);
    validateDigits();
}

Vector Ternary::getNumber() const {
    return digits;
}

Vector Ternary::add(const Ternary& other) const {
    Vector otherDigits = other.getNumber();
    Vector result;

    int sum = 0;
    size_t i = 0, j = 0;

    while (i < digits.Size() || j < otherDigits.Size() || sum) {
        if (i < digits.Size()) sum += digits[i++];
        if (j < otherDigits.Size()) sum += otherDigits[j++];

        result.PushBack(static_cast<unsigned char>(sum % 3));
        sum /= 3;
    }

    return result;
}

Vector Ternary::subtract(const Ternary& other) const {
    if (other > *this)
        throw std::invalid_argument("Subtraction result would be negative");

    Vector otherDigits = other.getNumber();
    Vector result;

    int diff = 0;
    size_t i = 0, j = 0;

    while (i < digits.Size() || j < otherDigits.Size()) {
        if (i < digits.Size()) diff += digits[i++];
        if (j < otherDigits.Size()) diff -= otherDigits[j++];

        if (diff < 0) {
            diff += 3;
            result.PushBack(static_cast<unsigned char>(diff));
            diff = -1;  // Borrow from the next digit
        } else {
            result.PushBack(static_cast<unsigned char>(diff));
            diff = 0;
        }
    }

    while (result.Size() > 1 && result.Back() == 0) {
        result.PopBack();
    }

    return result;
}

void Ternary::validateDigits() {
    for (size_t i = 0; i < digits.Size(); i++) {
        if (digits[i] > 2) {
            throw std::invalid_argument("Invalid digit in base-3 number");
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Ternary& ternary) {
    Vector digits = ternary.getNumber();
    for (size_t i = digits.Size(); i > 0; --i) {
        os << static_cast<int>(digits[i - 1]);
    }
    return os;
}
