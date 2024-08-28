#include <iostream>

template<int N>
struct foo{
    static const size_t val =  N * foo<N - 1>::val;
};

template<>
struct foo<0> {
    static const size_t val = 1;
};

int main() {
    int const n = 5;
    std::cout << foo<n>::val <<std::endl;
}