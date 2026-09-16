
#include "02_InvalidConcept.h"
#include "TestCounter.h"
#include <iostream>
#include <vector>
#include <set>

// Neither container satisfies this concept - it looks for a "pushback"
// member (no underscore), which no standard container has. That's the
// whole point: the concept itself is broken, not any particular type.
static_assert(!MispelledPushBack<std::vector<int>>,
	"std::vector<int> has push_back, not pushback");
static_assert(!MispelledPushBack<std::set<int>>,
	"std::set<int> should not satisfy MispelledPushBack concept");

void testAddWithMisspelledConcept() {
	std::cout << testCount++ << "# " << "Testing mispelled concept:\n";

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

	std::cout << " - Vector contents: ";
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
	
	std::cout << " - Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}
