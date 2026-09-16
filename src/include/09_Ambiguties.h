#pragma once

#include <type_traits>
#include <iostream>

// Test methods.
void testAmbiguties();
void testAmbigutiesAfterFix();

// Concept has size requirement.
template <typename CollT>
concept HasSize = requires (CollT coll) { 
	{ coll.size() } -> std::convertible_to<int>;
};

// Concept has index operator.
template <typename CollT>
concept HasIndexOp = requires (CollT coll) { 
	coll[0]; 
};

// Method requires HasSize concept.
template <typename CollT>
requires HasSize<CollT>
void foo(CollT& coll) {
	std::cout << " - foo() has container with size()\n";
}

#ifdef SHOW_COMPILE_ERRORS
// COMPILE ERROR: When foo called for std::vector
// Method requires HasIndexOp concept.
template <typename CollT>
requires HasIndexOp<CollT>
void foo(CollT& coll) {
	std::cout << " - foo() for container {}\n";
}
#else
// Adding both HasSize and HasIndexOp will fix ambiguty.
template <typename CollT>
// Has to support size() AND index of operator.
requires HasSize<CollT> && HasIndexOp<CollT>
void foo(CollT& coll) {
	std::cout << " - foo() for container with size() and []\n";
}
#endif
