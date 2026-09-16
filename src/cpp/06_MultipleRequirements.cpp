
#include "06_MultipleRequirements.h"	
#include "TestCounter.h"
#include <vector>
#include <set>
#include <iostream>

// A type that provides operator <
class WithLess {
public:
	explicit WithLess(int v) : value(v) {}

	bool operator<(const WithLess& other) const {
		return value < other.value;
	}

	int getValue() const {
		return this->value;
	}
private:
	int value;
};

// A type that does NOT provide operator<
class WithoutLess {
public:
	explicit WithoutLess(int v) : value(v) {}

	int getValue() const {
		return this->value;
	}

private:
	int value;
};

// Test methods
static_assert(SequenceCont<std::vector<int>&>);
static_assert(!SequenceCont<std::set<int>&>);
// SequenceCont concept has < operator requirement.
static_assert(SequenceCont<std::vector<WithLess>&>);
// WIthoutLess cannot handle all requirements for SequenceCont.
static_assert(!SequenceCont<std::vector<WithoutLess>&>);

void testAddConceptsOfMultipleReqs() {
	std::cout << testCount++ << "# " << "Testing concepts with multiple requirements:\n";

	std::vector<int> vec;
	addConceptsOfMultipleReqs(vec, 42);
	addConceptsOfMultipleReqs(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void testAddForLessThanComparisionRequirement() {
	std::cout << testCount++ << "# " << "Testing concepts with comparision:\n";

	std::vector<WithLess> vec;
	addConceptsOfMultipleReqs(vec, WithLess(42));
	addConceptsOfMultipleReqs(vec, WithLess(7));

	std::cout << " - Vector contents: ";
	for (const auto& item : vec) {
		std::cout << item.getValue() << " ";
	}
	std::cout << std::endl;

#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: WithoutLess has no < operator, so it fails the
	// SequenceCont requirement even though std::vector itself is fine.
	std::vector<WithoutLess> errVec;
	addConceptsOfMultipleReqs(errVec, WithoutLess(42));
	addConceptsOfMultipleReqs(errVec, WithoutLess(7));

	std::cout << " - Vector contents: ";
	for (const auto& item : errVec) {
		std::cout << item.getValue() << " ";
	}
	std::cout << std::endl;
#endif
}