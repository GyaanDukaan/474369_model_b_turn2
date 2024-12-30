#include <optional>

int main() {
    std::optional<int> x = 42;

    if (x.has_value()) {
        std::cout << "x has value: " << *x << std::endl;
    }
    else {
        std::cout << "x does not have a value" << std::endl;
    }

    return 0;
}


