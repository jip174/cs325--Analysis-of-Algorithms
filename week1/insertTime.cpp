#include <iostream>
#include <fstream>
#include <ctime>
#include <time.h>
#include <cstdlib>


/****Reference: https://www.geeksforgeeks.org/insertion-sort/ ****/
void insertSort(int myArray[], int size)
{
	
	for (int i = 1; i < (size - 1); i++)
	{
		int key = myArray[i]; //key is the value we are trying to find
		int j = i - 1; //j is the value we are comparing key 

		while (j >= 0 && myArray[j] > key) 
		{
			myArray[j + 1] = myArray[j];      //move it one position ahead 
			j = j - 1; //decreemnt it to look at the one below
		}
		myArray[j + 1] = key;
	}
}
void arrayFill(int myArray[], int size) {
	//int newArr[10];
	//int n = 5000;

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
	timeFile.open("times.txt");
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
		insertSort(myArray, n);
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