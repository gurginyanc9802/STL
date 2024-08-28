#include <iostream>
#include <string>

std::string sep() {
    return "  ";
}

std::string end() {
    return "\n";
}

std::string arrow() {
    std::string val = ">";
    val = "-" + val;
    return val;
}

template<std::string (*Sep)() = sep, std::string (*End)() = end, typename... Ts>
void print(Ts... args) {
    int c = 0;
    ((std::cout << (c++ ? Sep() : "") << args),...) << End();
}


int main() {
    print<arrow>(3.12, 20, "hello");
}