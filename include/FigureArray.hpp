#ifndef FIGUREARRAY_HPP
#define FIGUREARRAY_HPP

#include "Figure.hpp"

template <class T>
concept IsFigure = std::is_base_of<Figure<double>, T>::value;

template <IsFigure T>
class FigureArray 
{
public:
    FigureArray(size_t capacity);
    FigureArray(const FigureArray &other);

    FigureArray& operator=(const FigureArray &other);
    FigureArray& operator=(FigureArray &&other) noexcept;
    FigureArray(FigureArray &&other) noexcept;

    ~FigureArray();

    void add(Figure *figure);
    void remove(size_t index);
    double totalArea() const;
    void printAll() const;
    size_t size() const;

private:
    std::unique_ptr<std::shared_ptr<T>[]> figures_;
    size_t size_;
    size_t capacity_;

    void resize();
};

#include "../src/FigureArray.tpp"

#endif // FIGUREARRAY_HPP
