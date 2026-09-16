
#include "07_RequiresRequires.h"
#include "TestCounter.h"
#include <vector>
#include <set>
#include <iostream>

// Same check as addRequiresRequires' requires clause, wrapped in a tiny
// concept so the negative case can SFINAE to false instead of hard-erroring -
// a bare requires-expression only gets that leniency when template
// substitution is actually happening; plain concrete types don't.
template <typename CollT>
concept CanCallPushBack = requires (CollT coll, int x) { coll.push_back(x); };

static_assert(CanCallPushBack<std::vector<int>>);
static_assert(!CanCallPushBack<std::set<int>>);

void testAddRequiresRequires() {
	std::cout << testCount++ << "# " << "Testing Concepts with requires requires:\n";

	std::vector<int> vec;
	addRequiresRequires(vec, 42);
	addRequiresRequires(vec, 7);

	std::cout << " - Vector contents: ";
	for (const auto& value : vec) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	std::set<int> iSet;
	addRequiresRequires(iSet, 42);
	addRequiresRequires(iSet, 7);

	std::cout << " - Set contents: ";
	for (const auto& value : iSet) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}