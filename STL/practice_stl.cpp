#include <iostream>
//task 1
template<unsigned long long N>
struct foo{
    static const size_t x = 2 * foo<N - 1>::x - 2 * foo<N - 2>::x - 3 * foo<N - 3>::x + 4; 
};

template<>
struct foo<0> {
    static const size_t x = 0;
};

template<>
struct foo<1>{
    static const size_t x = 1;
};

template<>
struct foo<2> {
    static const size_t x = 2;
};


//task 2
class A {};
class B {};
class C {};
class D : public A{};

template<typename T>
typename std::enable_if<(std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                        || (!std::is_base_of<A,T>::value && std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                        || (!std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && std::is_base_of<C, T>::value)>::type
chlp1(T ob) {}

//task 3
template<typename T>
concept one_base = (std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                    || (!std::is_base_of<A,T>::value && std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                    || (!std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && std::is_base_of<C, T>::value);

template <one_base T>
void chlp2(T ob) {};

//task 4
template<typename T>
requires (std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                    || (!std::is_base_of<A,T>::value && std::is_base_of<B, T>::value && !std::is_base_of<C, T>::value)
                    || (!std::is_base_of<A,T>::value && !std::is_base_of<B, T>::value && std::is_base_of<C, T>::value)
void chlp3(T ob) {}



//task 7
template<size_t N, typename T, typename... Ts>
struct tupple_element {
    using type = tupple_element<N - 1, Ts...>;
};

template<typename T, typename... Ts>
struct tupple_element<0, T, Ts...> {
    using type = T;
};

//task 9
constexpr int func(int N) {
    if  (std::is_constant_evaluated()) {
        return N * N;
    }else {
        return N + N;
    }
}

class k {
    virtual void foo() {}
};


int main() {
    //std::cout << foo<60>::x << std::endl;
    //static const int k = func(5);
    //std::cout << k << std::endl;
    //int n = 0;
    //std::cin >> n;
    //std::cout << func(n) << std::endl;
}

