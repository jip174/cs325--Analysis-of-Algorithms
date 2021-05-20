
#include <iostream>
#include <fstream>


/****Reference: https://www.geeksforgeeks.org/insertion-sort/ ****/
void insertSort(int myArray[], int size){

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


void printArr(std::ostream &stream, int arr[], int n) {
	for (int i = 0; i < (n - 1); i++) {
		stream << arr[i] << " ";
	}
	stream << arr[n - 1];
	stream << std::endl;
}
int main()
{
	//std::size_t size;
	std::ifstream inFile;
	std::ofstream insertfile("insert.txt");
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
	std::cout << num << std::endl;
	inFile.clear(); 
	inFile.seekg(0);
	int *myArray = new int[num]; //dynamically allocate an array 
	int i = 0;
	while (inFile >> x) //store in array
	{
		myArray[i] = x;
		
		i++;
	}

	inFile.close();
	std::cout << "Before sort: " << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << myArray[i] << " ";
	}

	std::cout << std::endl;
	insertSort(myArray, num);
	std::cout << "After sort: " << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << myArray[i] << " ";
	}
	printArr(insertfile, myArray, num);
	inFile.close();
	std::cout << std::endl;
	return 0;
}