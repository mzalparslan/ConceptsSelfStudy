
#include "07_RequiresRequires.h"
#include <vector>
#include <set>
#include <iostream>

void testAddRequiresRequires() {
	std::cout << "Testing Concepts with requires requires clause:\n";

	std::vector<int> vec;
	addRequiresRequires(vec, 42);
	addRequiresRequires(vec, 7);
	std::cout << "Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::set<int> iSet;
	addRequiresRequires(iSet, 42);
	addRequiresRequires(iSet, 7);
	std::cout << "Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}