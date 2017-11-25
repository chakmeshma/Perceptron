
#include "Neuron.h"

static float sigmoid(float x) {
    return 1.0f / (1.0f + pow(M_E, -x));
}

static bool activation(float x) {
    return (x >= 0.5f);
}

int main() {
    srand(time(NULL));

    Spike x0, x1;
    while (true) {
        Neuron *koontaqal = new Neuron(2, sigmoid, activation);

        std::cout << "X0?" << std::endl;
        std::cin >> x0;
        std::cout << "X1?" << std::endl;
        std::cin >> x1;

        Spike *inputs = new Spike[2]{x0, x1};

        std::cout << "Neuron Output: " << ((koontaqal->compute(inputs, 2)) ? ("True") : ("False"))
                  << std::endl;

        delete[] inputs;

        delete koontaqal;
    }


    return 0;
}