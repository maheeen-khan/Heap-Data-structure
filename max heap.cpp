//Max Heap sort

#include<stdio.h>
#include<iostream>

using namespace std;

int arr[100];
int place = 0;

//insert in max heap
void insertInMaxHeap(int value){
	place++;
	int index = place;
	arr[index] = value;
	
	while(index > 1){
		int parent = index / 2;
		
		if(arr[parent] < arr[index]){
			swap(arr[parent], arr[index]);
			index = parent;
		}
		else{
			return;
		}
	}
}


//Deletion in max heap
void deletefromMaxHeap(){
	if(place == 0){
		cout<<"Nothing to delete.\n";
		return;
	}
	//step 1
	arr[1] = arr[place];
	
	//step 2
	place--;
	
	//step 3 Take root to its correct position
	int i = 1;
	while(i < place){
		
		int leftIndex = 2*i;
		int rightIndex = 2*i+1;
		
		if(leftIndex < place  && arr[i] < arr[leftIndex]){
			swap(arr[i], arr[leftIndex]);
			i = leftIndex;
		}
		
		else if(rightIndex < place  && arr[i] < arr[rightIndex]){
			swap(arr[i], arr[rightIndex]);
			i = rightIndex;
		}
		
		else{
			return;
		}
	}
	
}


//Heapify function
void heapify(int arr[], int arr_size, int i){
	
	int largest = i;
	int left = 2*i;
	int right = 2*i + 1;
	
	if(left <= arr_size && arr[largest] < arr[left]){
		largest = left;
	}
	if(right <= arr_size && arr[largest] < arr[right]){
		largest = right;
	}
	
	if(largest != i){
		swap(arr[largest], arr[i]);
		heapify(arr, arr_size, largest);
	}
	
}

//heap sort
void heapSort(int arr[], int arr_size){
	
	int size = arr_size;
	
	while(size > 1){
		//step 1
		swap(arr[size], arr[1]);
		size--;
		
		//step 2
		heapify(arr, size,1);
	}
}

//print heap
void printHeap(){
	for(int i=1; i<=place; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	
	insertInMaxHeap(50);
	insertInMaxHeap(55);
	insertInMaxHeap(53);
	insertInMaxHeap(52);
	insertInMaxHeap(54);

	printHeap();

//Check Delete function 
	cout<<"\n\nAfter deletion : ";
	
	deletefromMaxHeap();
	
	printHeap();
	
	cout<<"\n\n~~~~~~~~~~~~~~~~~~~~";
//check heapify function

	int heapify_list[6] = {-1, 88, 93, 75,98, 50};
	int arr_size = 5;
	
	cout<<"\nAnother array : ";
	for(int i = 1; i <= arr_size; i++){
		cout<<heapify_list[i]<<" ";
	}
	cout<<"\n";
	for(int i = arr_size/2; i > 0; i--){ //arr_size/2: bcoz of leaves nodes are lastNode/2 +1 --> nth
		heapify(heapify_list,arr_size,i);
	}
	
	cout<<"\n\nAfter heapify max array will be : ";
	
	for(int i = 1; i <= arr_size; i++){
		cout<<heapify_list[i]<<" ";
	}
	cout<<"\n\n~~~~~~~~~~~~~~~~~~~";
	
//Heap sort
	
	int sort_heap_arr[6] = {-1,60,55,53,52,54};
	heapSort(sort_heap_arr,arr_size);
	
	cout<<"\nAnother array : ";
	for(int i = 1; i <= arr_size; i++){
		cout<<sort_heap_arr[i]<<" ";
	}
	cout<<"\n\n";
	
	cout<<"After sorting array will be : ";
	
	for(int i = 1; i <= arr_size; i++){
		cout<<sort_heap_arr[i]<<" ";
	}
	

}
