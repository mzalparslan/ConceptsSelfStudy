#pragma once

#include <ranges>
#include <type_traits>

// Test methods used to verify current concepts 
// defined in this header file.
void testAddConceptsOfMultipleReqs();
void testAddForLessThanComparisionRequirement();

/* 
SEMANTIC/RUNTIME Requirements: 
Cannot be checked by compilers; documentation only.
T models range only if 
- std::ranges::begin(t), std::ranges::end(t) denotes a range.
- std::ranges::begin(t), std::ranges::end(t) are amortized constant time
and non-modifying
- if type of std::ranges:begin(t) models forward_iterator,
std::ranges::begin(t) is equality preserving.

template<typename T>
concept range = requires(T & t) {
	std::ranges::begin(t);
	std::ranges::end(t);
};
*/

// Combine multiple requirements into general-purpose concepts.
template <typename CollT>
// Standart concept to iterate over elements: std::ranges::range
// Can combine multiple Concepts from standart and self-defined.
concept SequenceCont = std::ranges::range<CollT> &&
	requires (std::remove_cvref_t<CollT> coll, 
			  std::ranges::range_value_t<CollT> value) {
	coll.push_back(value);
	coll.pop_back();
	// coll.begin() is just an iterator in these statements.
	// Statements confirm if insert and erase possible with any iterator.
	// They donot questionare if it is possible to insert at begin().
	// This is a compile-time feature and donot involve at that detail.
	coll.insert(coll.begin(), value);
	coll.erase(coll.begin());
	coll.clear();
	// Constructor with Initialization list support
	std::remove_cvref_t<CollT>{value, value, value};
	// Assignment operator exists.
	coll = { value, value, value };
	// Container should provide comparision operator.
	{ coll < coll } -> std::convertible_to<bool>;
};

// CollT should provide all related requirements.
template <typename CollT, typename T>
requires SequenceCont<CollT>
void addConceptsOfMultipleReqs(CollT& coll, const T& value) {
	coll.push_back(value);
}

