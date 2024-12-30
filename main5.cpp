#include <ctre/ctre.hpp>

int main() {
    constexpr auto regex = ctre::detail::regex<"^[a-zA-Z]+$">{};
    const std::string str = "Hello";

    if (ctre::match<decltype(regex), std::string_view>(str)) {
        std::cout << "Matches" << std::endl;
    }
    else {
        std::cout << "Does not match" << std::endl;
    }

    return 0;
}