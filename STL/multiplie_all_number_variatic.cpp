#include <iostream>
/*template<int arg>
int foo() {
    return arg;
}

template<int arg, int... args>
int foo() {
    return arg * foo<args...>();  
}


int main() {
    std::cout << foo<1, 2, 3, 4, 5, 6, 7>() << std::endl;  
}
*/

/*
template<int arg, int... args>
int foo() {
    if ((sizeof...(args)) == 0) {
        return arg;
    }
    return  arg * foo<args...>();
}

int main() {
    std::cout << foo<1,2,3,4,5,6,7>() << std::endl;
}
*/

int mul(int val) {
    static int res = 1;
    res *= val;
    return res;
}

template<typename... Ts>
int foo(Ts... args) {
    int result = (mul(args),...);
    return result;
}

int main() {
    std::cout << foo(1,2,3,4,5,6,7) << std::endl;
}

/*
template<int arg, int... args>
struct foo {
    static const int val = arg * foo<args...>::val;
};

template<int arg>
struct foo() {
    static const int val = arg;
};

int main() {
    std::cout << foo<1,2,3,4,5,6,7>::val << std::endl;
}
*/