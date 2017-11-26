//
// Created by chakmeshma on 25.11.2017.
//

//TODO make learning generic

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H


#include <cstdint>
#include <vector>
#include <random>
#include <iostream>
#include <ctime>

typedef bool Spike;
typedef float Weight; //TODO make it normalized variable
typedef Weight (*NeuronFunction)(Weight inputSum);

typedef Spike (*NeuronActivationFunction)(Weight inputSum);

class Neuron {
public:
    Neuron(Weight weights[], uint32_t weightCount, NeuronFunction neuronFunction,
           NeuronActivationFunction neuronActivationFunction);

    Neuron(uint32_t weightCount, NeuronFunction neuronFunction, NeuronActivationFunction neuronActivationFunction);

    Spike compute(Spike inputs[], uint32_t inputCount);

    void train(Spike inputs[], Spike answer,float learningRate);

private:
    std::vector<Weight> weights;
    uint32_t inputCount;
    NeuronActivationFunction _neuronActivationFunction;
    NeuronFunction _neuronFunction;
};


#endif //PERCEPTRON_PERCEPTRON_H
