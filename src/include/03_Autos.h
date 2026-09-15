#pragma once

#include <type_traits>

void testAddByAutoKeyword();
void testAddAutoWithConcept();
void testAddAutoWithRequiresClause();
void testAddAutoWithRequiresClauseFixed();

// Abbreviated function template with auto parameters.
// Equal to:
// template<typename CollT, typename T> 
// void addByAutoKeyword(CollT& coll, const T& value) 
// { coll.push_back(value); }
void addByAutoKeyword(auto& coll, const auto& value) {
	coll.push_back(value);
}

#ifdef SHOW_COMPILE_ERRORS
// COMPILE ERROR: collection has no push_back method.
// Abbreviated function template with auto parameters.
void addByAutoKeyword(auto& coll, const auto& value) {
	coll.insert(value);
}
#endif

// Concept: PushBackable
// Requirements:
// This concept checks if collection has a push_back method.
// It forces data type of value to be sane with collection type.
// Used to show how auto parameters can use concepts.
template <typename CollT>
concept PushBackable = 
// requires defines REQUIREMENTS here.
requires (CollT& coll, CollT::value_type& value) {
	coll.push_back(value);
};

// Concept: PushBackableFixedReferenceType
// Instead of fixing reference types during requires clause,
// remove const and reference types during Concept definition.
// This concept is useful when it is used in requires clause.
template <typename CollT>
concept PushBackableFixedReferenceType =
	requires (CollT coll, std::remove_cvref_t<CollT>::value_type value) {
	coll.push_back(value);
};

// Add for push_back with PushBackable concept.
// Compiler first try this function as it is more specific than next one.
// It is called Type Constraint when concept is used with auto parameters.
void addAutoWithConcept(PushBackable auto& coll, const auto& value) {
	coll.push_back(value);
}

// Generic add to use insert method for collection 
// that has insert but no push_back method.
void addAutoWithConcept(auto& coll, const auto& value) {
	coll.insert(value);
}

#ifdef SHOW_COMPILE_ERRORS
// COMPILE ERROR: decltype will return coll as std::vector<int>&
// and CollT::value will be invalid because std::vector<int>&::value
// is not a valid statement. The requires-clause is simply not satisfied,
// so the compiler falls through to the generic overload below,
// which then fails because vector has no insert method.
void addAutoWithRequiresClause(auto& coll, const auto& value)
	requires PushBackable<decltype(coll)> {
	coll.push_back(value);
}
#else
// This method will compile as decltype will return std::vector<int> after
// remove const reference is called.
void addAutoWithRequiresClause(auto& coll, const auto& value)
// Requires clause defines CONSTRAINTS here.
requires PushBackable<std::remove_cvref_t<decltype(coll)>> {
	coll.push_back(value);
}
#endif

// Generic method to verify compiler knows which one to use.
void addAutoWithRequiresClause(auto& coll, const auto& value) {
	coll.insert(value);
}

// Now reference type removed by Concept itself instead of
// requires statement. So coll will be cast to actual type instead 
// of reference type.
void addAutoWithRequiresClauseFixed(auto& coll, const auto& value) 
requires PushBackableFixedReferenceType<decltype(coll)> {
	coll.push_back(value);
}

// Generic method to verify compiler knows which one to use.
void addAutoWithRequiresClauseFixed(auto& coll, const auto& value) {
	coll.insert(value);
}