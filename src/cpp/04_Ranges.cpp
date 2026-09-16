
#include "04_Ranges.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <iostream>

// Test method.
static_assert(HasPushbackWithRanges<std::vector<int>&>);
static_assert(!HasPushbackWithRanges<std::set<int>&>);

void testAddAutoByRanges() {
	std::cout << testCount++ << "# " << "Testing auto with ranges:\n";

	std::vector<int> vec;
	addAutoByRanges(vec, 42);
	addAutoByRanges(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addAutoByRanges(mySet, 42);
	addAutoByRanges(mySet, 7);

	std::cout << " - Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}