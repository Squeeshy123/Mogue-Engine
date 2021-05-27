#pragma once
#include <stdio.h>

static int debug_count = 0;
static void debug() {
	printf("Checkpoint: %i\n", debug_count);
	debug_count++;
}
