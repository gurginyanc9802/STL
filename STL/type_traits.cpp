#include <iostream>
#include<vector>
#include<string>
#include<array>

template<typename T, T val>
struct integral_constant{
    using type = T;
    static constexpr T value = val;
    operator T(){
        return value;
    }

    T operator ()(){
        return value;
    }
};

template<bool val>
using bool_constant = integral_constant<bool, val>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

template<typename T>
struct is_integral : bool_constant<requires(T ob, T* ptr, void (*fptr)(T obj)){
    ptr + ob;
    fptr(0);
    reinterpert_cast<char>(ob);
}>{};


template<typename T>
struct is_canstructable : bool_constant<requires(T ob){T{};}>{};

template<typename T>
struct is_copy_canstructable : bool_constant<requires(T ob){T{ob};}>{};

template<typename T, typename U>
struct is_same : false_type {};

template<typename T>
struct is_same<T,T> : true_type {};

template<typename T>
struct is_flaoting_point {
    static const bool value = is_same<T,float>::value;
};

template<typename T, typename U, typename... Ts>
struct is_all_same {
    static const bool value = is_same<T,U>::value && is_all_same<U,Ts...>::value;
};

template<typename T, typename U>
struct is_all_same<T,U> {
    static const bool value = is_same<T,U>::value;
};

//template<typename T, typename U>
//using is_same_v = is_same<T,U>::value;

template<typename T>
struct is_nullptr {
    static const bool value = is_same<T,std::nullptr_t>::value;
};

template<typename T>
struct remove_const {
    using type = T;
};

template<typename T>
struct remove_const<const T> {
    using type = T;
};

template<typename T>
struct remove_volatile {
    using type = T;
};

template<typename T>
struct remove_volatile<volatile T> {
    using type = T;
};

template<typename T>
struct remove_cv {
    using type = T;
};

template<typename T>
struct remove_cv<const T> {
    using type = T;
};

template<typename T>
struct remove_cv<volatile T>{
    using type = T;
};

template<typename T>
struct remove_cv<const volatile T> {
    using type = T;
};

template <typename T>
struct is_pointer : false_type {};

template<typename T>
struct is_pointer<T*> : true_type {};

template<typename T>
struct is_pointer<T* const> : true_type {};

template<typename T>
struct is_pointer<T* volatile> : true_type {};

template<typename T>
struct is_pointer<T* const volatile> : true_type {};

template<typename T>
struct is_rvalue_reference : false_type {};

template<typename T>
struct is_rvalue_reference<T&> : true_type {};

template<typename T>
struct is_lvalue_reference : false_type {};

template<typename T>
struct is_lvalue_reference<T&&> : true_type {};

template<typename T>
struct is_member_pointer : false_type {};

template<typename T, typename U>
struct is_member_pointer<T U::*> : true_type {};

template<typename T>
struct is_member_function_pointer : false_type {};

template<typename T, typename U>
struct is_member_function_pointer<T (U::*)> : std::is_function<T> {};

template<typename T>
struct is_member_object_pointer : false_type {};

template<typename T, typename U>
struct is_member_object_pointer<T U::*> : std::is_class<T> {};

template<typename T>
struct add_const {
    using type = const T;
};

template<typename T>
struct add_volatile {
    using type = volatile T;
};

template<typename T>
struct remove_reference {
    using type = T;
};

template<typename T>
struct remove_reference<T&> {
    using type = T;
};

template<typename T>
struct remove_reference<T&&> {
    using type = T;
};

template<bool val, typename T1, typename T2>
struct conditional {
    using type = T1;
};

template<typename T1, typename T2>
struct conditional<false, T1, T2> {
    using type = T2;
};

template <typename T>
struct decay {
    using U = typename remove_reference<T>::type;  

    using type = std::conditional_t<std::is_array_v<U>, typename std::remove_extent<U>::type*,  
        std::conditional_t<std::is_function_v<U>, std::add_pointer_t<U>, typename remove_cv<U>::type>>;
};

template<typename T>
struct add_cv {
    using type = const volatile T;
};

template<bool b, typename T = void>
struct enable_if {};

template<typename T>
struct enable_if<true,T> {
    using type = T;
};

template<typename T>
enable_if<std::is_class<T>::value, void>::type
yay() {}


template<typename T>
requires requires (T ob) {
    {ob.begin()} -> std::same_as<typename T::iterator>;
    {ob.end()} -> std::same_as<typename T::iterator>;
}
std::ostream& operator<<(std::ostream& out, T ob) {
    for (auto it = ob.begin(); it != ob.end(); ++it){
        std::cout << *it;
    }
    std::cout << std::endl;
    return out;
}


template<typename T>
concept iterable = !(std::is_same<T, std::string>::value); 

template<iterable T>
void anything() {std::cout << "this is not a string!!!" << std::endl;}

template<typename T, typename U>
concept same_as = is_same<T,U>::value || is_same<U,T>::value;

template<typename T>
concept integral = is_integral<T>::value;

template<typename... Ts>
struct tuple_size : std::integral_constant<size_t, sizeof...(Ts)> {};

template<size_t N, typename T, typename... Ts>
struct tuple_element {
    using type  = tuple_element<N - 1, Ts...>;
};

template<typename T, typename... Ts>
struct tuple_element<0, T, Ts...> {
    using type = T;
};


template<size_t N, iterable T>
std::array<typename T::value_type, N> bind(T ob) {
    std::array<T::value_type, N> arr;
    for (auto it1 = ob.begin(), it2 = arr.begin(); it1 != arr.end(); ++it1, ++it2) {
        *it2 = *it1;
    }
    return arr;
}


struct A {
    int x = 10;
    int y = 20;
};



int main() {
    A chlp;
    auto& [a,b] = chlp;
    std::cout << a << b << std::endl;
}




