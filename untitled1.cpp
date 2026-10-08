#include <stdio.h>

void wait_ms(int ms) {
	volatile long i, j;
	for (i = 0; i < ms; i++)
		for (j = 0; j < 100000; j++);
}

void draw_dino(int offset) {
	int i, j;
	const char *dino[5] = {
		" __",
		" / _)",
		".-^^^-/ /",
		"__/ /",
		"<__.|_|-|_|"
	};
	
	printf("\033[2J\033[H");
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j < offset; j++) printf(" ");
		printf("%s\n", dino[i]);
	}
	
	printf("___________________________________________\n");
}

int main() {
	int pos = 0;
	int dir = 1;
	int max = 30;
	int steps = 0;
	
	while (steps < 200) {
		draw_dino(pos);
		pos += dir;
		if (pos >= max || pos <= 0) dir = -dir;
		wait_ms(30);
		steps++;
	}
	
	printf("\nDino ran away!\n");
	return 0;
}
