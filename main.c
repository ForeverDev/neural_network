#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

int main(int argc, char** argv) {

	const double data[] = {
		0, 0.2, 0, 0, 0.3
	};

	Brain* brain = Brain_new(5, 4, 2, 4);
	Brain_feedForward(brain, data);
	Brain_print(brain);
	
	return 0;

}
