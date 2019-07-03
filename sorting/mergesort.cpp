#include<iostream>
#include<array>

using namespace std;


array<int, 6>& mergeSort(array<int, 6>& arr, int p, int q, int r){
	int key;
	for(int i{1}; i<arr.size();i++){
		key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>key){
			// sort them
			arr[j+1] = arr[j];
			j = j - 1;
		}
		arr[j+1] =  key;
	}

	return arr;

}


void printArray(array<int, 6>& arr){
	for(int i{0}; i<arr.size();i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){


	array<int, 6> arr{5,2,4,6,1,3};
	array<int, 6> sorted = insertionSort(arr);
	printArray(sorted);
	
	return EXIT_SUCCESS;
}
