#include<stdio.h>
#include<iostream>

using namespace std;

int arr[100];
int place = 0;


//insert in min heap
void insertInMinHeap(int value){
	place++;
	int index = place;
	arr[index] = value;
	
	while(index > 1){
		int parent = index / 2;
		
		if(arr[parent] > arr[index]){
			swap(arr[parent], arr[index]);
			index = parent;
		}
		else{
			return;
		}
	}
}


//Delete from min Heap
void deletefromMinHeap(){
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
		
		if(leftIndex < place  && arr[i] > arr[leftIndex]){
			swap(arr[i], arr[leftIndex]);
			i = leftIndex;
		}
		
		else if(rightIndex < place  && arr[i] > arr[rightIndex]){
			swap(arr[i], arr[rightIndex]);
			i = rightIndex;
		}
		
		else{
			return;
		}
	}
	
}


//print heap
void printHeap(){
	for(int i=1; i<=place; i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	
	insertInMinHeap(90);
	insertInMinHeap(80);
	insertInMinHeap(70);
	insertInMinHeap(30);
	
	printHeap();
	
	cout<<"\n\nAfter deletion : ";
	
	deletefromMinHeap();
	
	printHeap();
	
}
