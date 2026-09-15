
#include "02_InvalidConcept.h"
#include <iostream>
#include <vector>
#include <set>

/**
* Test Code: will not compile because push_back method is misspelled.
* This is actually test code for the concepts. 
* Compiler will show error for 2nd function but original error is at 1st function.
static_assert(MispelledPushBack<std::vector<int>>,
	"std::vector<int> should satisfy MispelledPushBack concept");
*/
static_assert(!MispelledPushBack<std::set<int>>,
	"std::set<int> should not satisfy MispelledPushBack concept");

void testAddWithMisspelledConcept() {
#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR:
	// Compiler will check the 1st (MispelledPushBack-constrained) overload
	// and won't find a push_back method (it's misspelled in the concept).
	// It then tries the 2nd (generic, insert-based) overload, which also
	// fails since vector has no insert. The error is reported against the
	// 2nd function, but the actual mistake is in the 1st.
	std::vector<int> vec;
	addWithMisspelledConcept(vec, 42);
	addWithMisspelledConcept(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
#endif

	// This part will compile alone as generic function 
	// will be used for std::set that has insert method.
	std::set<int> mySet;
	addWithMisspelledConcept(mySet, 42);
	addWithMisspelledConcept(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}
