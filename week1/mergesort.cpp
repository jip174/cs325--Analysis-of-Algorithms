
#include <iostream>
#include <fstream>

/*Code citation: https://www.sanfoundry.com/cpp-program-implement-merge-sort/ */

void merge(int *array, int low, int high, int mid){

	int i;
	int	j;
	int k;
	int temp[high - low + 1];

	i = low; //start 
	k = 0; //first spot in temp
	j = mid + 1; //start of second 

	while (i <= mid && j <= high) //check if valid
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
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
void mergeSort(int *array, int low, int high)
{
	if (low < high){
		int mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, high, mid);
	}
}
void printArr(std::ostream &stream, int arr[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		stream << arr[i] << " ";
	}
	stream << arr[n - 1];
	stream << std::endl;

}
int main(){

	std::ifstream inFile;
	std::ofstream mergefile("merge.txt");
	inFile.open("data.txt");
	if (!inFile)
	{
		std::cout << "File not found." << std::endl;
	}
	int x;
	int num = 0;
	while (inFile >> x) //get file size 
	{
		num++;
	}
	inFile.clear(); 
	inFile.seekg(0);
	int *myArray = new int[num]; //dynamically allocate an array based on size of file
	int i = 0;
	while (inFile >> x) {
		myArray[i] = x;
		i++;
	}
	
	mergeSort(myArray, 0, num - 1); 

	std::cout << "After merge sort: " << std::endl;
	for (int i = 0; i < num; i++) {
		std::cout << myArray[i] << " ";
	}

	printArr(mergefile, myArray, num);
	inFile.close();
	std::cout << std::endl;
	
	return 0;
}