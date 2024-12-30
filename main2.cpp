#include <boost/hana.hpp>
#include <iostream>
#include <vector>
#include <chrono>

namespace hana = boost::hana;

template <typename T>
auto sum_with_hana(const std::vector<T>& arr) {
    return hana::reduce(arr, hana::zero, hana::plus);
}

template <typename T>
auto sum_with_loop(const std::vector<T>& arr) {
    T sum = 0;
    for (const auto& x : arr) {
        sum += x;
    }
    return sum;
}

int main() {
    const size_t size = 1'000'000;
    std::vector<int> arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = i;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = sum_with_hana(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Boost.Hana sum: " << result << std::endl;
        std::cout << "Boost.Hana time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    }

    {
        auto start = std::chrono::high_resolution_clock::now();
        auto result = sum_with_loop(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Loop sum: " << result << std::endl;
        std::cout << "Loop time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
    }

    return 0;
}

