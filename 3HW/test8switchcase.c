#include <stdio.h>

int main () {
	
	int res;
	scanf ("%d", &res);	

	switch (res) {
		case 1:
			printf ("O\n");
			break;
		case 2:
			printf ("T\n");
			break;
		case 3:
			printf ("T\n");
			break;
		case 4:
			printf ("F\n");
			break;
		case 5:
			printf ("F\n");
			break;
		case 6:
			printf ("S\n");
			break;
		case 7:
			printf ("S\n");
			break;
		case 8:
			printf ("E\n");
			break;
		case 9:
			printf ("N\n");
			break;
		case 10:
			printf ("T\n");
			break;
		default:
			printf ("Other letter\n");


	}

	return 0;
}
