#ifndef BRAIN_H
#define BRAIN_H

typedef char				int8;
typedef short				int16;
typedef int					int32;
typedef long long			int64;
typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef unsigned long long	uint64;
typedef float				float32;
typedef double				float64;

typedef struct Neuron Neuron;
typedef struct NeuronList NeuronList;
typedef struct NeuronListList NeuronListList;
typedef struct Brain Brain;

struct Neuron {
	float64 charge;
	Neuron* next;
};

struct NeuronList {
	Neuron* head;
	Neuron* tail;
	NeuronList* next;
};

struct NeuronListList {
	NeuronList* head;
	NeuronList* tail;
};

struct Brain {
	NeuronListList* neurons;
};

Brain*	Brain_new(uint32, uint32, uint32, uint32);
void	Brain_print(Brain*);

#endif
