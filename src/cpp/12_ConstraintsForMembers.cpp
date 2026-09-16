
#include "12_ConstraintsForMembers.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <string>

// Concepts to be used in test methods.
template <typename T>
concept HasIsZero = requires (MyType<T> t) { t.isZero(); };

template <typename T>
concept HasIsEmpty = requires (MyType<T> t) { t.isEmpty(); };

// Static tests.
static_assert(HasIsZero<double>);
static_assert(!HasIsZero<std::string>);
static_assert(HasIsEmpty<std::string>);
static_assert(!HasIsEmpty<double>);

void testMemberWithNoConstraint() {
	std::cout << testCount++ << "# " << "Testing no constraint print() method:\n";

	MyType<double> myDouble;
	myDouble.value = 0;
	myDouble.print();

	MyType<std::string> myStr;
	myStr.value = "apple";
	myStr.print();
}

void testConstraintsForMemberZero() {
	std::cout << testCount++ << "# " << "Testing constraints for isZero() method:\n";

	MyType<double> myDouble;
	myDouble.value = 0;
	std::cout << " - My double is zero?: " 
		<< (myDouble.isZero() ? "true" : "false") << "\n";

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: isZero() requires integral or floating data type.
	// Otherwise MyType<T> will have no isZero() method.
	MyType<std::string> myStr;
	std::cout << " - My string is zero?: "
		<< (myStr.isZero() ? "true" : "false") << "\n";
#endif
}

void testConstraintsForMemberEmpty() {
	std::cout << testCount++ << "# " << "Testing constraints for isEmpty() method:\n";

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: isEmpty() requires T.empty() method
	// but double has no empty() method.
	MyType<double> myDouble;
	myDouble.value = 0;
	std::cout << " - My double is empty?: "
		<< (myDouble.isEmpty() ? "true" : "false") << "\n";
#endif

	MyType<std::string> myStr;
	std::cout << " - My string is empty?: "
		<< (myStr.isEmpty() ? "true" : "false") << "\n";
}

