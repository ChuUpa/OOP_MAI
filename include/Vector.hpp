#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <memory>
#include <utility>

class Vector {
public:
    Vector();

    Vector(unsigned char value);

    Vector(size_t count, unsigned char value);

    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    Vector(Vector&& other) noexcept;

    Vector& operator=(Vector&& other);

    Vector(std::initializer_list<unsigned char> init);

    unsigned char& operator[](size_t pos);

    const unsigned char& operator[](size_t pos) const;

    unsigned char& Back() const noexcept;

    size_t Size() const noexcept;

    void Reserve(size_t new_cap);

    void Clear() noexcept;

    void PushBack(unsigned char value);

    void PopBack();

    ~Vector();

private:
    unsigned char* arr_;
    size_t size_;
    size_t capacity_;
};

bool operator==(const Vector& lhs, const Vector& rhs);

#endif
