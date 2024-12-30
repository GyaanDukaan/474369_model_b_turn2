#include <boost/mpl/fold.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/range_c.hpp>
#include <boost/mpl/times.hpp>

namespace mpl = boost::mpl;

template <typename N>
struct factorial : mpl::fold<
    mpl::range_c<mpl::int_, 1, N::value + 1>,
    mpl::int_<1>,
    mpl::times<mpl::_1, mpl::_2>
>::type {};

int main() {
    constexpr auto result = factorial<mpl::int_<6>>::value;
    static_assert(result == 720, "Factorial calculation failed");
    return 0;
}


