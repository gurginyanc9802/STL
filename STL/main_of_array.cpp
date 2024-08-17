
#include "std::array.cpp"

#include <iostream>

int main() {
    array<int, 3> arr = {1, 2, 3};
    std::cout << "Array size: " << arr.size() << std::endl;

    std::cout << "Array elements: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "First element (front): " << arr.front() << std::endl;
    std::cout << "Last element (back): " << arr.back() << std::endl;

    std::cout << "Is the array empty? " << (arr.empty() ? "Yes" : "No") << std::endl;

    std::cout << "Element at index 1: " << arr.at(1) << std::endl;
    std::cout << "Element at index 10: " << arr.at(2) << std::endl; // This will cause std::out_of_range exception

    std::cout << "Array elements using iterator: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Array elements in reverse order using reverse iterator: ";
    for (auto it = arr.rbegin(); it != arr.rend(); --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    array<int, 3> arr2 = {1, 2, 3};
    array<int, 3> arr3 = {3, 2, 1};

    std::cout << "arr == arr2: " << (arr == arr2 ? "True" : "False") << std::endl;
    std::cout << "arr != arr3: " << (arr != arr3 ? "True" : "False") << std::endl;
    std::cout << "arr < arr3: " << (arr < arr3 ? "True" : "False") << std::endl;

    return 0;
}
