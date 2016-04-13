#include <stdlib.h>
#include "brain.h"

Brain* 
Brain_new(uint32 inputs, uint32 outputs, uint32 hidden, uint32 nperh) {
	Brain* B = (Brain *)malloc(sizeof(Brain));	
	B->neurons = (NeuronListList *)malloc(sizeof(NeuronListList));
	B->neurons->head = NULL;
	B->neurons->tail = NULL;
	NeuronList* last_col = NULL;
	for (int i = 0; i < hidden + 2; i++) {

		int num_neurons;
		NeuronList* col = (NeuronList *)malloc(sizeof(NeuronList));
		col->head = NULL;
		col->tail = NULL;
		col->next = NULL;
		
		if (!B->neurons->head) {
			B->neurons->head = col;
		}
		B->neurons->tail = col;

		if (i == 0) {
			num_neurons = inputs;
		} else if (i == hidden + 1) {
			num_neurons = outputs;
		} else {
			num_neurons = nperh;
		}

		Neuron* last_neuron = NULL;
		for (int j = 0; j < num_neurons; j++) {
			Neuron* neuron = (Neuron *)malloc(sizeof(Neuron));	
			neuron->charge = 0;
			neuron->next = NULL;

			if (last_neuron) {
				last_neuron->next = neuron;
			}
			last_neuron = neuron;

			if (!col->head) {
				col->head = neuron;
			}
			col->tail = neuron;
		}

		if (last_col) {
			last_col->next = col;
		}
		last_col = col;

	}
	return B;
}

void
Brain_print(Brain* B) {
	if (!B->neurons->head) return;
	for (NeuronList* i = B->neurons->head; i 
}
