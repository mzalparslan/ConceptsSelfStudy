
#include "01_Introduction.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>

void testAdd() {
	std::vector<int> vec;
	add(vec, 42);
	add(vec, 7);
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: no matching function for call to 'add'
	// (std::set has no push_back member).
	// Note: this shares the SHOW_COMPILE_ERRORS flag with 01_Introduction.h's
	// extra add(CollT&, T&&) overload. If that overload is also visible,
	// it actually rescues this specific call (set has insert) - but the
	// add(vec, 42) call above then fails instead, for the same reason.
	std::set<int> mySet;
	add(mySet, 42);
	add(mySet, 7);
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
#endif
}

// Test function for addWithConcept will compile and run.
void testAddWithConcept() {
	std::vector<int> vec;
	addWithConcept(vec, 42);
	addWithConcept(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addWithConcept(mySet, 42);
	addWithConcept(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void testAddWithShortConcept() {
	std::vector<int> vec;
	addWithShortConcept(vec, 42);
	addWithShortConcept(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addWithShortConcept(mySet, 42);
	addWithShortConcept(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}