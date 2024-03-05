#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printArr(int Arr[], int stt){
// Function in ra cac phan tu trong mang
	int i;
	for (i = 0 ; i <= stt; i++)
		printf("%d ", Arr[i]);
	printf("\n");
	return;
}

void resetArr(int Arr[]){
// Function reset lai mang, gan gia tri cac phan tu trong mang bang 0
	int i;
    for(i = 0 ; i < 100; ++i) Arr[i] = 0;
    return;
}

void sortArr( int Arr[], int stt){
// Function sap xep lai cac phan tu trong mang theo thu tu tang dan
// Lan luot so sanh cac phan tu ben trai Arr[j] va phai Arr[i],
// Neu ben trai lon hon ben phai thi swap Arr[i], Arr[j]
	int i, j;
    for (i = 1; i <= stt; ++i)
        for (j = 0 ; j < i ; ++j)
        	if(Arr[j] > Arr[i]){
        		int temp = Arr[i];
        		Arr[i] = Arr[j];
        		Arr[j] = temp;
			}
	return;
}

int findNumExis(int Arr[], int stt, int n){
// Function tim va dem so lan xuat hien cua phan tu trong mang
	int cnt = 0;
	int i;
	for (i = 0; i <= stt; ++i)
		if(Arr[i] == n) cnt ++;
	return cnt;
}

void setArr(int a[], int b[], int stt){
// Function gan Arr nay bang Arr kia []
    resetArr(a);
    int i;
    for (i = 0 ; i <= stt; ++i)
        a[i] = b[i];
    return;
}

void printBetweenMinMax(int Arr[], int stt, int minn, int maxx){
// Function in cac phan tu trong mang, thoa lon hon minn va nho hon maxx
	int i;
	for (i = 0; i <= stt; ++i){
		if(Arr[i] >= minn && Arr[i] <= maxx)
			printf("%d ", Arr[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	///////////////////////////////////
	/// Khai bao, khoi tao du lieu
	int Arr[100], Arg[100];
	int option, stt = -1, val, cnt, minVal, maxVal, i;
	for (i = 0; i < 100; ++i) Arr[i] = 0;
	do{
		printf("Choose your option!\n");
		printf("1 - Add a value\n");
		printf("2 - Search a value\n");
		printf("3 - Print out the the array\n");
		printf("4 - Print out values in a range\n");
		printf("5 - Print out the array in ascending order\n");
		printf("Others - Quit\n");
		printf("Your option ?: ");
		scanf("%d", &option);
		printf("===========================\n");
	/////////////////////////////////////
	// Main
		switch(option){
			case 1:
			//  When the option 1 is selected,
			//  user will enters a value then it is added to the array
				printf("Your value: ");
				scanf("%d",&val);
				Arr[++stt] = val;
				printf("Your value has added.\n");
				break;
			case 2:
			//  When the option 2 is selected, 
			//  user will enters a value then number of it's existences will be printed out.
				printf("Your value: ");
				scanf("%d",&val);
				printf("%d existences was find out\n", findNumExis(Arr,stt,val));
				break;
			case 3:
			//	When the option 3 is selected, 
			//  values in the array will be printed out.
				printArr(Arr, stt);
				break;
			case 4:
			//  When the option 4 is chosen, 
			//  user will enter 2 values, minVal and maxVal,
			//  the values in array which are between minVal and maxVal are printed out 
			//  (minVal <=value<=maxVal)
				printf("Accept your minVal: ");
				scanf("%d", &minVal);
				printf("Accept your maxVal: ");
				scanf("%d", &maxVal);
				printBetweenMinMax(Arr,stt,minVal,maxVal);
				break;
            case 5:
            //  When the option 5 is chosen, 
			//  values in array will be printed out in ascending order but their position are preserved. 
			//  ( sorting based their pointers only)
                setArr(Arg,Arr,stt);		// Gan mang Arr vao mang Arg
                sortArr(Arg, stt);			// Sap xep mang Arg ( Vi tri duoc van duoc luu o Arr)
                printArr(Arg, stt);			

		}
		printf("\n");
	}
	while(option >= 1  && option <= 5);

	return 0;
}

