#pragma once

void testAddWithMisspelledConcept();

// Concept: Invalid HasPushBack
// push_back was intenionally misspelled to see compiler error.
template <typename CollT>
concept MispelledPushBack = requires(CollT coll, CollT::value_type value) {
	// Spelling error is intentional to show that concept will 
	// do different mistakes.
	coll.pushback(value);
};

// Misspelled concept based function template force
// to use push_back method.
template <MispelledPushBack CollT, typename T>
void addWithMisspelledConcept(CollT& coll, const T& value) {
	coll.push_back(value);
}

// Now we can use same function name for different
// collection type where collection has insert.
// INTERESTING: Compiler will show error for this function
// but original error is at above function that has Mispelled concept.
template <typename CollT, typename T>
void addWithMisspelledConcept(CollT& coll, const T& value) {
	coll.insert(value);
}