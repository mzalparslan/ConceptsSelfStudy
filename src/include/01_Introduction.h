#pragma once

void testAdd();
void testAddWithConcept();
void testAddWithShortConcept();

// This is a simple add function that adds a value to a collection.
// It uses push_back method to add value to collection.
template <typename CollT, typename T>
void add(CollT& coll, const T& value) {
	coll.push_back(value);
}

#ifdef SHOW_COMPILE_ERRORS
// COMPILE ERROR: redefinition of add().
// Same signature as the overload above (CollT&, const T&) - templates
// can't be overloaded on return type or body alone, so the compiler
// rejects this as a duplicate definition of same function template.
template <typename CollT, typename T>
void add(CollT& coll, const T& value) {
	coll.insert(value);
}
#endif

// Concept: HasPushBack
// Requirements:
// This concept checks if collection has a push_back method.
// It forces data type of value to be sane with collection type.
template <typename CollT>
concept HasPushBack = requires(CollT coll, CollT::value_type value) {
	coll.push_back(value);
};

// Constraint based function template force Collection to have 
// push_back method and value type to be sane with collection type.
template <typename CollT, typename T>
	requires HasPushBack<CollT>
void addWithConcept(CollT& coll, const T& value)  {
	coll.push_back(value);
}

// Now we can use same function name for different 
// collection type where collection  has insert 
// but no push_back method.
template <typename CollT, typename T>
void addWithConcept(CollT& coll, const T& value) {
	coll.insert(value);
}

// Instead of using Type Constraints, 
// we can use short concept syntax to achieve same result.
template <HasPushBack CollT, typename T>
void addWithShortConcept(CollT& coll, const T& value) {
	coll.push_back(value);
}

// Defined same method even its name not fitting into what it does,
// to show that we can use same function name for different collection type
// where collection has insert but no push_back method.
template <typename CollT, typename T>
void addWithShortConcept(CollT& coll, const T& value) {
	coll.insert(value);
}