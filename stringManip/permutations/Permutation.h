#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <string>

class Permutation {
public:
	Permutation(std::string stringToPermute_in = "")
		:stringToPermute(stringToPermute_in) {}

	bool checkPermutationSort(std::string comparedString);
	bool checkPermutationHash(std::string comparedString);
	void printPermutations(); 

private:
	std::string stringToPermute; 
	void printPermutationHelper(std::string passedInString, std::string permutedString); 
};

#endif