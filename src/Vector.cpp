#include "../include/Vector.hpp"
#include <memory>
#include <cstdlib>

const int TEN = 10;

Vector::Vector() : arr_(nullptr), size_(0), capacity_(0) {}

Vector::Vector(unsigned char value) : size_(1), capacity_(1) {
    arr_ = reinterpret_cast<unsigned char*>(new int8_t[sizeof(unsigned char)]);
    new (arr_) unsigned char(value);
}

Vector::Vector(size_t count, unsigned char value) : size_(count), capacity_(count) {
    count = (count > TEN) ? count : TEN;
    arr_ = reinterpret_cast<unsigned char*>(new int8_t[count * sizeof(unsigned char)]);
    for (size_t i = 0; i < count; ++i) {
        new (arr_ + i) unsigned char(value);
    }
}

Vector::Vector(const Vector& other) {
    size_ = other.size_;
    capacity_ = (size_ > TEN) ? size_ : TEN;
    arr_ = reinterpret_cast<unsigned char*>(new int8_t[capacity_ * sizeof(unsigned char)]);
    std::uninitialized_copy(other.arr_, other.arr_ + size_, arr_);
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }
    Clear();
    Reserve(other.capacity_);
    size_ = other.size_;
    std::uninitialized_copy(other.arr_, other.arr_ + size_, arr_);
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    if (this == &other) {
        return *this;
    }
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = other.arr_;
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
    return *this;
}

Vector::Vector(Vector&& other) noexcept {
    size_ = other.size_;
    capacity_ = other.capacity_;
    arr_ = other.arr_;
    other.arr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

Vector::Vector(std::initializer_list<unsigned char> init) {
    size_ = init.size();
    capacity_ = (init.size() > TEN) ? init.size() : TEN;
    arr_ = reinterpret_cast<unsigned char*>(new int8_t[capacity_ * sizeof(unsigned char)]);
    std::uninitialized_copy(init.begin(), init.end(), arr_);
}

unsigned char& Vector::operator[](size_t pos) {
    return arr_[pos];
}

const unsigned char& Vector::operator[](size_t pos) const {
    return arr_[pos];
}

size_t Vector::Size() const noexcept {
    return size_;
}

void Vector::Reserve(size_t new_cap) {
    if (new_cap <= capacity_) {
        return;
    }
    unsigned char* new_arr = reinterpret_cast<unsigned char*>(new int8_t[new_cap * sizeof(unsigned char)]);
    for (size_t i = 0; i < size_; ++i) {
        new (new_arr + i) unsigned char(std::move(arr_[i]));
    }
    delete[] arr_;
    arr_ = new_arr;
    capacity_ = new_cap;
}

unsigned char& Vector::Back() const noexcept {
    return arr_[size_ - 1];
}

void Vector::Clear() noexcept {
    size_ = 0;  // Просто обнуляем размер, так как unsigned char не требует явного вызова деструктора.
}

void Vector::PushBack(unsigned char value) {
    if (capacity_ == 0) {
        Reserve(TEN);
    }
    if (size_ == capacity_) {
        Reserve(capacity_ * 2);
    }
    new (arr_ + size_) unsigned char(value);
    size_++;
}

void Vector::PopBack() {
    if (size_ > 0) {
        size_--;
    }
}

Vector::~Vector() {
    delete[] reinterpret_cast<int8_t*>(arr_);
}

bool operator==(const Vector& lhs, const Vector& rhs) {
    if (lhs.Size() != rhs.Size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.Size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}
