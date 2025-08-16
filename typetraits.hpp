#ifndef TYPETRAITS_HPP
#define TYPETRAITS_HPP
#include <utility>

namespace my_traits {
    template <typename T, T v>
    struct integral_constant {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant<T, v>;
        constexpr operator value_type() const noexcept { 
            return value; 
        }
    };
    template <bool B>
    using bool_constant = integral_constant<bool, B>;
    using true_type  = bool_constant<true>;
    using false_type = bool_constant<false>;

    template<class T> struct is_integral_base : false_type {};
    template<> struct is_integral_base<int> : true_type { };
    template<> struct is_integral_base<unsigned int> : true_type { };
    template<> struct is_integral_base<long> : true_type { };
    template<> struct is_integral_base<unsigned long> : true_type { };
    template<> struct is_integral_base<long long> : true_type { };
    template<> struct is_integral_base<unsigned long long> : true_type { };
    template<> struct is_integral_base<short> : true_type { };
    template<> struct is_integral_base<unsigned short> : true_type { };
    template<> struct is_integral_base<bool> : true_type { };
    template<> struct is_integral_base<char> : true_type { };
    template<> struct is_integral_base<signed char> : true_type { };
    template<> struct is_integral_base<unsigned char> : true_type { };
    template<> struct is_integral_base<wchar_t> : true_type { };

    template<class T> struct is_floating_point_base : false_type { };
    template<> struct is_floating_point_base<double> : true_type { };
    template<> struct is_floating_point_base<float> : true_type { };
    template<> struct is_floating_point_base<long double> : true_type { };

    template<class T> struct is_pointer_base : false_type { };
    template<class U> struct is_pointer_base<U*> : true_type { };

    template<class T> struct remove_const { 
        using type = T; 
    };
    template<class T> struct remove_const<const T> { 
        using type = T; 
    };
    template<class T> struct remove_volatile { 
        using type = T; 
    };
    template<class T> struct remove_volatile<volatile T> { 
        using type = T; 
    };
    template<class T> struct remove_cv {
        using type = typename remove_const<typename remove_volatile<T>::type>::type;
    };

    template<class T> struct remove_reference { 
        using type = T; 
    };
    template<class T> struct remove_reference<T&>  { 
        using type = T; 
    };
    template<class T> struct remove_reference<T&&> { 
        using type = T; 
    };

    template<class T> struct add_const { 
        using type = const T; 
    };

    template<class T, class U> struct is_same : false_type { };
    template<class T> struct is_same<T, T> : true_type { };

    template<bool Cond, class TrueType, class FalseType>
    struct conditional {
        static constexpr bool value = Cond;
        using type = TrueType;
    };
    template<class TrueType, class FalseType>
    struct conditional<false, TrueType, FalseType> {
        static constexpr bool value = false;
        using type = FalseType;
    };

    template<bool Cond, class T = void>
    struct enable_if {
        static constexpr bool value = Cond; 
    };
    template<class T>
    struct enable_if<true, T> {
        static constexpr bool value = true;
        using type = T;
    };


    template<class T>
    struct is_integral : is_integral_base<typename remove_cv<T>::type> { };
    template<class T>
    struct is_floating_point : is_floating_point_base<typename remove_cv<T>::type> { };
    template<class T>
    struct is_pointer : is_pointer_base<typename remove_cv<T>::type> { };

};

#endif