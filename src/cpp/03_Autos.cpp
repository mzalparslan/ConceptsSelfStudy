
#include "03_Autos.h"
#include <iostream>
#include <vector>
#include <set>

// Compiler error:
// static_assert(PushBackable<std::vector<int>&>);
static_assert(PushBackableFixedReferenceType<std::vector<int>&>);

void testAddByAutoKeyword() {
	std::cout << "Testing auto keyword:\n";

	std::vector<int> vec;
	addByAutoKeyword(vec, 42);
	addByAutoKeyword(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
#ifdef SHOW_COMPILE_ERRORS
	// COMPILE ERROR: addByAutoKeyword will try to call push_back
	// method on std::set, which does not have a push_back method.
	std::set<int> mySet;
	addByAutoKeyword(mySet, 42);
	addByAutoKeyword(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
#endif
}

void testAddAutoWithConcept() {
	std::cout << "Testing auto that has related "
		"Concept name before auto keyword:\n";

	std::vector<int> vec;
	addAutoWithConcept(vec, 42);
	addAutoWithConcept(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addAutoWithConcept(mySet, 42);
	addAutoWithConcept(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void testAddAutoWithRequiresClause() {
	std::cout << "Testing auto that has requires clause:\n";

	std::vector<int> vec;
	addAutoWithRequiresClause(vec, 42);
	addAutoWithRequiresClause(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addAutoWithRequiresClause(mySet, 42);
	addAutoWithRequiresClause(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

void testAddAutoWithRequiresClauseFixed() {
	std::cout << "Testing auto that has requires "
		"clause and Concept is fixing type:\n";

	std::vector<int> vec;
	addAutoWithRequiresClauseFixed(vec, 42);
	addAutoWithRequiresClauseFixed(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& val : vec) {
		std::cout << val << " ";
	}
	std::cout << std::endl;

	std::set<int> mySet;
	addAutoWithRequiresClauseFixed(mySet, 42);
	addAutoWithRequiresClauseFixed(mySet, 7);
	std::cout << "Set contents: ";
	for (const auto& val : mySet) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}