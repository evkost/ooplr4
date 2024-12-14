#ifndef SCALARTYPE_H
#define SCALARTYPE_H

#include <type_traits>

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

#endif // SCALARTYPE_H
