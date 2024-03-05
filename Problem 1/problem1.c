#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

bool isThisISBN(int n){
	int sum = 0, w = 2;
	sum += (n%10);
	n /= 10;
	while (n > 1){
		sum += ((n%10)*w);
		n /= 10;
		w++;
	}
	
	if (sum % 11 == 0) return true;
	return false;
}

int main(int argc, char *argv[]) {
	int ISBN;
	printf("ISBN Validator ===============\n");
	do {
		printf("ISBN (0 to quit): ");
		scanf("%d",&ISBN);
		if (ISBN != 0){
			if (isThisISBN(ISBN))
				printf("This is a valid ISBN.\n");
			else
				printf("This is not a valid ISBN.\n");
		}
		
	}
	while(ISBN != 0);
	printf("Have a Nice Day!");
	return 0;
}
