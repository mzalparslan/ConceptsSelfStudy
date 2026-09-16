
#include "09_Ambiguties.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <string>

static_assert(HasSize<std::vector<int>>);
static_assert(HasIndexOp<std::vector<int>>);
// std::list has size(), but no operator[] - this is exactly why calling
// foo() with a list below is unambiguous: only the HasSize overload applies.
static_assert(HasSize<std::list<int>>);
static_assert(!HasIndexOp<std::list<int>>);

void testAmbiguties() {
	std::cout << testCount++ << "# " << "Testing Concepts with ambiguties:\n";

	// std::list has no index operator so only one foo() 
	// that has HasSize concept will be initialized.
	std::list<int> lst{ 9, 10, 24 };
	foo(lst);
}

void testAmbigutiesAfterFix() {
#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: Ambiguties foo() with 2 different
	// concept which fit for std::vector()
	std::vector<int> vec{ 0, 12, 22 };
	foo(vec);
#else
	std::cout << testCount++ << "# " << "Testing Concepts after ambiguties fixed: \n";

	std::vector<int> vec{ 0, 12, 22 };
	foo(vec);
#endif
}
