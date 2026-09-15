#pragma once

void testAddConceptsOfMultipleParams();
void testAddAutoConceptsOfMultipleParams();

// Concepts for multiple parameters:
// Concept is asking if collection can push_back value or not.
template <typename CollT, typename T>
concept CanPushBack = requires (CollT coll, T value) {
	coll.push_back(value);
};

// Both Collection and Type T are now in concept requirement.
template <typename CollT, typename T>
requires CanPushBack<CollT, T>
void addConceptOfMultipleParams(CollT& coll, const T& value) {
	coll.push_back(value);
}

// Fallback handles collections with insert() but no push_back() 
// Compiler only picks this when constrained overload above 
// isn't suitable for related Collection CollT.
template <typename CollT, typename T>
void addConceptOfMultipleParams(CollT& coll, const T& value) {
	coll.insert(value);
}

// Abbreviated function templates need decltype to inform their type.
// auto multiple parameters.
void addAutoConceptOfMultipleParams(auto& coll, const auto& value) 
requires CanPushBack<decltype(coll), decltype(value)> {
	coll.push_back(value);
}

// Fallback handles collections with insert() but no push_back() 
// Compiler only picks this when constrained overload above 
// isn't suitable for related Collection CollT.
void addAutoConceptOfMultipleParams(auto& coll, const auto& value) {
	coll.insert(value);
}