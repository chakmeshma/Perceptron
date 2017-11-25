#include "Neuron.h"

static float sigmoid(float x) {
    return 1.0f / (1.0f + pow(M_E, -x));
}

static bool activation(float x) {
    return (x >= 0.0f);
}

int main() {
    Neuron koontaqal(2, sigmoid, activation);

    Spike x0, x1;

    std::cout << "X0?" << std::endl;
    std::cin >> x0;
    std::cout << "X1?" << std::endl;
    std::cin >> x1;

    std::cout << "Neuron Output: " << ((koontaqal.compute(new Spike[2]{x0, x1}, 2)) ? ("True") : ("False"))
              << std::endl;

    getchar();

    return 0;
}