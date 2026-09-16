
#include "08_Conditional.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <string>
#include <iostream>

// Same check as the ad-hoc requires-expression inside addConditionalConcepts,
// wrapped in a tiny concept so the negative case can SFINAE to false instead
// of hard-erroring (see 07_RequiresRequires.cpp for why the bare form fails).
template <typename CollT>
concept CanCallPushBack = requires (CollT coll, int x) { coll.push_back(x); };

static_assert(CanCallPushBack<std::vector<int>>);
static_assert(!CanCallPushBack<std::set<std::string>>);

// Same convertible_to constraint used by addConditionalTypeChecking/Param.
static_assert(std::convertible_to<int, std::ranges::range_value_t<std::vector<int>>>);
static_assert(!std::convertible_to<int, std::ranges::range_value_t<std::set<std::string>>>);

void testAddConditionalConcepts() {
	std::cout << testCount++ << "# " << "Testing compile-time if conditional "
		"concepts:\n";

	std::vector<int> vec;
	addConditionalConcepts(vec, 42);
	addConditionalConcepts(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::set<int> iSet;
	addConditionalConcepts(iSet, 42);
	addConditionalConcepts(iSet, 7);

	std::cout << " - Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

void testAddConditionalWithErrors() {
	std::cout << testCount++ << "# " << "Testing compile-time if conditional concepts "
		"with error:\n";

	std::vector<int> vec;
	addConditionalConcepts(vec, 42);
	addConditionalConcepts(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: std::set<std::string> has no push_back, so this
	// falls to coll.insert(value) - but value is int, and there's no
	// int -> std::string conversion for set::insert to use.
	std::set<std::string> iSet;
	addConditionalConcepts(iSet, 42);
	addConditionalConcepts(iSet, 7);

	std::cout << " - Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
#endif
}

void testAddConditionalTypeChecking() {
	std::cout << testCount++ << "# " << "Testing compile-time if condition with "
		"type checking:\n";

	std::vector<int> vec;
	addConditionalTypeChecking(vec, 42);
	addConditionalTypeChecking(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: int (the value's type) is not convertible to
	// std::string (the set's range_value_t), so the requires-clause
	// on addConditionalTypeChecking is not satisfied.
	std::set<std::string> iSet;
	addConditionalTypeChecking(iSet, 42);
	addConditionalTypeChecking(iSet, 7);

	std::cout << " - Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
#endif
}

void testAddConditionalTypeCheckingParam() {
	std::cout << testCount++ << "# " << "Testing compile-time if conditional concepts "
		"with type checking for template parameter:\n";

	std::vector<int> vec;
	addConditionalTypeCheckingParam(vec, 42);
	addConditionalTypeCheckingParam(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR, but with a clearer diagnostic: the constraint lives
	// directly on the template parameter T, so the compiler points at the
	// exact parameter that fails instead of a deep template error log.
	std::set<std::string> iSet;
	addConditionalTypeCheckingParam(iSet, 42);
	addConditionalTypeCheckingParam(iSet, 7);

	std::cout << " - Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
#endif
}