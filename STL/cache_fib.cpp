#include <iostream>
#include <unordered_map>

int fib(int n, std::unordered_map<int, long long>& cache) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (cache.find(n) != cache.end()) {
        return cache[n];
    }

    return fib(n - 1, cache) + fib(n - 2, cache);
}

int main() {
    int n = 6;
    std::unordered_map<int, long long> cache;

    std::cout << fib(n, cache) << std::endl;
}