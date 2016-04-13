#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

int main(int argc, char** argv) {

	Brain* brain = Brain_new(3, 4, 2, 4);
	Brain_print(brain);
	
	return 0;

}
