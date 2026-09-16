
#include "13_ConstraintsForNonTypes.h"
#include "TestCounter.h"
#include <iostream>

// Static tests
static_assert(!isPrime(6));
static_assert(isPrime(7));

static_assert(!IsPrime<6>);
static_assert(IsPrime<7>);

// Actual tests to show progress in details.
void testConstraintsForNonTypes() {
	std::cout << testCount++ << "# " << "Testing constraints for non-types:\n";

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: Constraint isPrime not satisfied.
	TestClass<6> c6;
#endif
	TestClass<7> c7;
	std::cout << " - Init TestClass<" 
		<< c7.getValue() << "> success.\n";
}

void testConceptsWithNonTypeParams() {
	std::cout << testCount++ << "# " << "Testing constraints for non-types with concepts:\n";

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: Concept IsPrime not satisfied.
	// Error message will change as IsPrime now is concept.
	PrimeClass<6> errCase;
#endif

	PrimeClass<7> c7;
	std::cout << " - Init PrimeClass<"
		<< c7.getValue() << "> success.\n";
}