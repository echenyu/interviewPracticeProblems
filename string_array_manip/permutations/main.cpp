#include <string>
#include <iostream>
#include <cassert>
#include "Permutation.h"
#include <ctime>
#include <vector>
#include "PermClass.h"

using namespace std; 

//string1: cats string2: cat
//string1: "" string2: "" 
//string1: "c" string2: "c"
//string1: "c" string2: "d"
//string1: "taco" string2: "cato"

int main() {
	// Permutation newPermutation("hahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahas"); 
	// assert(!newPermutation.checkPermutationSort("hahahahahahahsahahahahsahahahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahas"));
	// assert(!newPermutation.checkPermutationHash("hahahahahahahahahadhahahsshahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahashahahahahahahahahadhahahas")); 

	// Permutation newPermutation2;
	// assert(newPermutation2.checkPermutationSort("")); 
	// assert(newPermutation2.checkPermutationHash("")); 

	// Permutation newPermutation3("c"); 
	// assert(newPermutation3.checkPermutationSort("c"));
	// assert(newPermutation3.checkPermutationHash("c"));  

	// Permutation newPermutation4("c"); 
	// assert(!newPermutation4.checkPermutationSort("d")); 
	// assert(!newPermutation4.checkPermutationHash("d")); 

	// Permutation newPermutation5("taco"); 
	// assert(newPermutation5.checkPermutationSort("cato")); 
	// assert(newPermutation5.checkPermutationHash("cato")); 
	// newPermutation5.printPermutations(); 

	vector<int> nums = {1, 2, 3, 4, 5}; 
	PermClass newNums(nums, 1); 
	int start_s = clock(); 
	for(int i = 0; i < 1000000; i++) {
		newNums.shuffle(1); 
	}
	int stop_s = clock(); 
	std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << " execution time for O(n)" << std::endl;

	PermClass newNums2(nums, 0); 
	start_s = clock(); 
	for(int i = 0; i < 1000000; i++) {
		newNums2.shuffle(0); 
	}
	stop_s = clock(); 
	std::cout << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << " execution time for O(n!)" << std::endl;
	int x = 2147483649; 
	cout << x << " is this." << endl;
}