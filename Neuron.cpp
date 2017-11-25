//
// Created by chakmeshma on 25.11.2017.
//

#include "Neuron.h"

Neuron::Neuron(Weight weights[], uint32_t weightCount, NeuronFunction neuronFunction,
               NeuronActivationFunction neuronActivationFunction) : inputCount(weightCount),
                                                                    _neuronFunction(neuronFunction),
                                                                    _neuronActivationFunction(
                                                                            neuronActivationFunction) {
    for (uint32_t i = 0; i < weightCount; i++)
        this->weights.push_back(weights[i]);
}

Neuron::Neuron(uint32_t weightCount, NeuronFunction neuronFunction, NeuronActivationFunction neuronActivationFunction)
        : inputCount(weightCount), _neuronFunction(neuronFunction),
          _neuronActivationFunction(neuronActivationFunction) {
    for (uint32_t i = 0; i < weightCount; i++)
        this->weights.push_back(float((std::rand() % 2001) - 1000) / 1000.0f); // [-1000, 1000] / 1000
}

Spike Neuron::compute(Spike *inputs, uint32_t inputCount) {
    float sum = 0.0f;

    for (uint32_t i = 0; i < inputCount; i++) {
        sum += ((inputs[i]) ? (1.0f) : (0.0f)) * weights[i];
    }

    return _neuronActivationFunction(_neuronFunction(sum));
}