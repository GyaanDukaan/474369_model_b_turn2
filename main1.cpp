#include <boost/hana.hpp>
namespace hana = boost::hana;

auto factorial = [](auto n) -> decltype(auto) {
    return n == hana::zero ? hana::one : n * factorial(n - hana::one);
};

int main() {
    constexpr auto result = hana::to<int>(factorial(hana::six));
    static_assert(result == 720, "Factorial calculation failed");
    return 0;
}
