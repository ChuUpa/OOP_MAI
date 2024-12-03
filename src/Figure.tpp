#ifndef FIGURE_TPP
#define FIGURE_TPP

#include "../include/Figure.hpp"

template <Numeric T>
std::ostream& operator<<(std::ostream& os, const Figure<T> &fig)
{
    fig.print(os);
    return os;
}

template <Numeric T>
std::istream& operator>>(std::istream& is, Figure<T> &fig)
{
    fig.read(is);
    return is;
}

#endif // FIGURE_TPP
