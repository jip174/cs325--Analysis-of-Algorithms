#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <cstdlib>

/*Code citation: https://www.sanfoundry.com/cpp-program-implement-merge-sort/ */

void merge(int *array, int low, int high, int mid)
{
	int i;
	int	j;
	int k;
	int temp[high - low + 1]; 

	i = low; //start 
	k = 0; //first spot in temp
	j = mid + 1; //start of second 

	// Merge 
	while (i <= mid && j <= high) //check if valid
	{
		if (array[i] < array[j]) {
			temp[k] = array[i]; 
			k++;
			i++;
		}
		else {
			temp[k] = array[j]; 
			k++;
			j++;
		}
	}
		
	while (i <= mid)// Insert all the remaining values 
	{
		temp[k] = array[i];
		k++;
		i++;
	}

	
	while (j <= high) // insert the rest
	{
		temp[k] = array[j];
		k++;
		j++;
	}
	
	for (i = low; i <= high; i++)//Transfer the data from temp 
	{
		array[i] = temp[i - low];
	}
}

void mergeSort(int *array, int low, int high){
	if (low < high)	{
		int mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}
void arrayFill(int myArray[], int size) {
	
	for (int i = 0; i <= size; i++) {
		myArray[i] = rand() % 10000 + 1;
		std::cout << myArray[i] << std::endl;
	}
}
void printArr(std::ostream &stream, int arr[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		stream << arr[i] << " ";
	}
	stream << arr[n - 1];
	stream << std::endl;

}
int main() {
	std::ofstream timeFile;
	timeFile.open("mergetimes.txt");
	srand(time(NULL));
	clock_t t1, t2;

	for (int i = 0; i < 10; i++) {
		int n = rand() % 100000 + 1; //size of array
		float timer = 0;
		float diff = 0;
		float seconds = 0;
		int myArray[n];
		arrayFill(myArray, n);
		t1 = clock();
		mergeSort(myArray, 0, n - 1);
		t2 = clock();
		diff = t2 - t1;
		std::cout << "Array Size " << n << std::endl;
		std::cout << "difference " << diff << std::endl;
		seconds = diff / CLOCKS_PER_SEC;
		std::cout << "Seconds " << seconds << std::endl;
		timeFile << n << "size " << seconds << "seconds. " << std::endl;
	}
	timeFile.close();
	return 0;
}