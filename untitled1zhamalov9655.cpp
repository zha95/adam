#include <stdio.h>

int main() {
	int n, i = 1;
	long long fact = 1;
	printf("Enter N: ");
	scanf("%d", &n);
	
	while (i <= n) {
		fact = fact * i;
		i++;
	}
	printf("%d! = %lld\n", n, fact);
	
	return 0;
}

