
#include "10_Subsumption.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <string>

static_assert(!BigType<int>);
static_assert(!BigType<double>);   // sizeof(double) == 8, not > 8
static_assert(BigType<std::string>);

static_assert(BigClassType<std::string>);
static_assert(BigClassTypeFixed<std::string>);
static_assert(!BigClassTypeFixed<int>);     // not a class
static_assert(!BigClassTypeFixed<double>);  // not a class, and not big either

static_assert(ClassType<std::string>);
static_assert(!ClassType<int>);

// Test class.
struct SmallClass {};

static_assert(BigOrClass<std::string>);   // big AND a class - either side works
static_assert(BigOrClass<SmallClass>);    // not big, but IS a class - only || allows this
static_assert(!BigOrClass<int>);          // neither big nor a class

static_assert(BigAndClass<std::string>);  // satisfies both
static_assert(!BigAndClass<SmallClass>);  // is a class, but not big - && rejects this
static_assert(!BigAndClass<int>);         // satisfies neither

#ifdef SHOW_COMPILE_ERRORS
void testConceptSubsumption() {
	// COMPILE ERROR: 
	std::string str("apple");
	bar(str);
}
#else
void testConceptSubsumption() {
	std::cout << testCount++ << "# " << "Testing Concept subsumption after fix:\n";

	std::string str("apple");
	bar(str);
}
#endif

void testConceptSubsumptionAndOrOr() {
	std::cout << testCount++ << "# " << "Testing Concept subsumption if || or && selected:\n";

	std::string str("apple");
	fooBar(str);
}