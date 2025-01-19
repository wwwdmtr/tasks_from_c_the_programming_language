#include <stdio.h>

int binsearch(int x, int arr[], int n){
	int low = 0, high = n - 1, mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (x > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (low < n && arr[low] == x)
		return low;
	return -1;
}

int main(){
	int n = 20, x = 4;
	int arr[n];
	for(int i = 0; i <  n; ++i){
		arr[i] = i;
		printf("%d  ", arr[i]);
	}
	putchar('\n');
	printf("Результат: %d\n",  binsearch(x, arr, n));

}
