#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "brain.h"

static int randomized = 0;

Brain* 
Brain_new(uint32 inputs, uint32 outputs, uint32 hidden, uint32 nperh) {
	if (!randomized) {
		srand(time(NULL));
		randomized = 1;
	}
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

		num_neurons = (i == 0) ? (i == hidden + 1) ? inputs : outputs : nperh;

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

			if (i > 0) {
				int last_neurons = (i == 1) ? inputs : nperh;
				neuron->axons = (float64 *)malloc(sizeof(float64) * last_neurons);
				for (int k = 0; k < last_neurons; k++) {
					neuron->axons[k] = ((float64)(rand() % 100 - 50))/50;
				}
			}
		}

		if (last_col) {
			last_col->next = col;
		}
		last_col = col;

	}
	return B;
}

void
Brain_feedForward(Brain* B, const float64* data) {
	for (Neuron* i = B->neurons->head->head; i; i = i->next) {
		i->charge = *data++;
	}
	NeuronList* last = B->neurons->head;
	for (NeuronList* i = B->neurons->head->next; i; i = i->next) {
		for (Neuron* j = i->head; j; j = j->next) {
			float64 sum = 0;
			int index = 0;
			for (Neuron* k = last->head; k; k = k->next, index++) {
				sum += k->charge * j->axons[index];
			}
			sum = 1 / (1 + exp(-sum));
			j->charge = sum > 0.3 ? sum : 0;
		}
		last = i;
	}
}

void
Brain_print(Brain* B) {
	if (!B->neurons->head) return;
	for (NeuronList* i = B->neurons->head; i; i = i->next) {
		for (Neuron* j = i->head; j; j = j->next) {
			printf("%f ", j->charge);
		}
		printf("\n");
	}
}
