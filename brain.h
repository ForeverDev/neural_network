#ifndef BRAIN_H
#define BRAIN_H

#include "types.h"

typedef struct Neuron Neuron;
typedef struct NeuronList NeuronList;
typedef struct NeuronListList NeuronListList;
typedef struct Brain Brain;

struct Neuron {
	float64 charge;
	Neuron* next;
	float64* axons; // incoming axons
};

struct NeuronList {
	Neuron* head;
	Neuron* tail;
	float64 bias;
	NeuronList* next;
};

struct NeuronListList {
	NeuronList* head;
	NeuronList* tail;
};

struct Brain {
	NeuronListList* neurons;
	uint32 inputs;
	uint32 outputs;
	uint32 hiddens;
	uint32 nperh;
};

Brain*		Brain_new(uint32, uint32, uint32, uint32);
float64*	Brain_getOutput(Brain*);
void		Brain_feedForward(Brain*, const float64*);
void		Brain_presentTrainingData(Brain*, const float64*, float64);
void		Brain_print(Brain*);

#endif
