#include <stdio.h>

int main () {

	int a = 1, b = 2, res;
	res = a + b;
		
	do {	
		res++;
		printf("res is %d\n", res);
		while (res < 30) {
			res += 4;
			for (; res < 15; res += 3) {
				printf("res is %d\n", res);
			}
			printf("res is %d\n", res);
			
		}
	} while (res < 60);

	return 0;
}
