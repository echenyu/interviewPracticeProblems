#include <iostream>
#include <cmath>

using namespace std; 

//Potential binary search
//1 2 4 8 16 32...
//We'll run a for loop
//Loop through indicies of 2^power
//	Once we find a index that returns -1, 
//	Start binary search 
// Talk about the complexity off the bat/why it's better

//1 2 4 8 
//0 1 3 7 15 : 
// 1 2 4 8 16 
//Indexer = 2*Indexer + 1; 
int indexOfValue(Listy list, int value) {
	int indexer = 0; 
	int count = 0; 
	while(list[indexer] != -1) {
		//Will come back to this to clean up generating sequence
		indexer += pow(2, count); //Indexer 0 + 1; Count = 1; 
		count++; 				
	}

	return binary_search(list, 0, indexer, value); 
}

//1 2 3 4 5 6 7 8
//0 3 7 10 11 12 -1 -1 -1 
int binary_search(Listy list, int left, int right, int value) {
	if(right < left) {
		return -1; 
	}
	int middleIndex = (left + right) / 2; 

	if(list[middleIndex] > value || list[middleIndex] == -1) {
		return binary_search(list, left, middleIndex - 1, value); 
	}  else if (list[middleIndex] < value) {
		return binary_search(list, middleIndex+1, right, value); 
	} else {
		return middleIndex; 
	}

	return -1; 
}