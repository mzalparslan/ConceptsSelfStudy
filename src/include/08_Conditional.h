#pragma once

#include <type_traits>
#include <ranges>

void testAddConditionalConcepts();
void testAddConditionalWithErrors();
void testAddConditionalTypeChecking();
void testAddConditionalTypeCheckingParam();

// Concepts, requirements and constraints are all 
// Compile-Time Boolean values.
void addConditionalConcepts(auto& coll, const auto& value) {
	// Compile-Time Boolean check.
	if constexpr (requires { coll.push_back(value); }) {
		coll.push_back(value);
	}
	else {
		coll.insert(value);
	}
}

// Concept add constraing to verify if Collection is defined
// with value type of value.
template <std::ranges::range CollT, typename T>
void addConditionalTypeChecking(CollT& coll, const T& value)
requires std::convertible_to<T, std::ranges::range_value_t<CollT>>
{
	if constexpr (requires { coll.push_back(value); }) {
		coll.push_back(value);
	}
	else {
		coll.insert(value);
	}
}

// Same Constraint can be part of T, so T should
// have same type with Collection or 
// it will give compile error.
template <std::ranges::range CollT,
	std::convertible_to<std::ranges::range_value_t<CollT>> T>
void addConditionalTypeCheckingParam(CollT& coll, const T& value) {
	if constexpr (requires { coll.push_back(value); }) {
		coll.push_back(value);
	}
	else {
		coll.insert(value);
	}
}