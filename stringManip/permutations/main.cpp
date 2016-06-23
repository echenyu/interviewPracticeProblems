#include <string>
#include <iostream>
#include <cassert>
#include "Permutation.h"
#include <ctime>

using namespace std; 

//string1: cats string2: cat
//string1: "" string2: "" 
//string1: "c" string2: "c"
//string1: "c" string2: "d"
//string1: "taco" string2: "cato"

int main() {
	Permutation newPermutation("cats"); 
	assert(!newPermutation.checkPermutationSort("cat"));
	assert(!newPermutation.checkPermutationHash("cat")); 

	Permutation newPermutation2;
	assert(newPermutation2.checkPermutationSort("")); 
	assert(newPermutation2.checkPermutationHash("")); 

	Permutation newPermutation3("c"); 
	assert(newPermutation3.checkPermutationSort("c"));
	assert(newPermutation3.checkPermutationHash("c"));  

	Permutation newPermutation4("c"); 
	assert(!newPermutation4.checkPermutationSort("d")); 
	assert(!newPermutation4.checkPermutationHash("d")); 

	Permutation newPermutation5("taco"); 
	assert(newPermutation5.checkPermutationSort("cato")); 
	assert(newPermutation5.checkPermutationHash("cato")); 
	newPermutation5.printPermutations(); 
}