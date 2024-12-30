#include <Eigen/Dense>

int main() {
    Eigen::Matrix<double, 3, 4> A;
    Eigen::Matrix<double, 4, 2> B;

    // Initialise matrices A and B
    // ...

    Eigen::Matrix<double, 3, 2> C = A * B;

    return 0;
}
