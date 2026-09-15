
#include "05_MultipleParameters.h"	
#include <vector>
#include <set>
#include <iostream>

// Test method.
static_assert(CanPushBack<std::vector<int>&, const int &>);

void testAddConceptsOfMultipleParams() {
	std::cout << 
		"Testing Concepts with Multiple Parameters:\n";

	std::vector<int> vec;
	addConceptOfMultipleParams(vec, 42);
	addConceptOfMultipleParams(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addConceptOfMultipleParams(mySet, 42);
	addConceptOfMultipleParams(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void testAddAutoConceptsOfMultipleParams() {
	std::cout <<
		"Testing Concepts with Multiple Auto Parameters:\n";

	std::vector<int> vec;
	addAutoConceptOfMultipleParams(vec, 42);
	addAutoConceptOfMultipleParams(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addAutoConceptOfMultipleParams(mySet, 42);
	addAutoConceptOfMultipleParams(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}