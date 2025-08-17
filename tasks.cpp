#include "typetraits.hpp"

// task 1

template <typename T>
typename my_traits::enable_if<my_traits::is_integral<T>::value, T>::type sum(T a, T b) {
    return a + b;
}

// task 2

template <bool Condition, typename T, typename U>
typename my_traits::conditional<Condition, T, U>::type
choose_type() {
    return {};
}

template <typename T>
using is_integral_check = typename my_traits::conditional<my_traits::is_integral<T>::value, int, double>::type;

// task 3

template <typename T>
struct base_type {
    using type = typename my_traits::remove_const<typename my_traits::remove_reference<T>::type>::type;
};

// task 4 ??

// task 5

template <typename T>
typename my_traits::enable_if<my_traits::is_pointer<T>::value, void>::type
reset_if_pointer(T& value) {
    value = nullptr;
}

template <typename T>
typename my_traits::enable_if<!my_traits::is_pointer<T>::value, void>::type
reset_if_pointer(T&) { }

int main() {

}