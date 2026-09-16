#pragma once

#include <type_traits>
#include <iostream>

// Test methods.
void testConceptSubsumption();
void testConceptSubsumptionAndOrOr();

template <typename T>
concept BigType = sizeof(T) > 8;

// Concept Subsumption: Compiler will create an atomic constraints 
// tree AND thencheck whether "one tree's atomic constrains are superset
// of other's." Critical point is that two atomic constraints
// only count as "the same constraint" if they trace back to
// SAME expression in the concept hiearchy. For BigClassType, 
// even it seems identical, for compiler, sizeof(T) > 8 in BigType 
// is different from sizeof(T) > 8 constraint in BigClassType and 
// there is no superset relation between BigType and BigClassType. 
// For compiler, they are totally different concepts and 
// there is no relationship - neither subsumes the other.
template <typename T>
concept BigClassType = sizeof(T) > 8 && std::is_class_v<T>;

// BigClassTypeFixed reuses BigType<T> && other constraint.
// Compiler is now able to decide that BigClassTypeFixed is 
// strictly more constrained than BigType - subsumption succeeds.

// Rule of Thumb: If there a composite concept that is superset of
// other concept, use Base<T> && ... instead of writing Base<T> 
// constraints again. the compiler will be able to tell these two 
// expressions are related.
template <typename T>
concept BigClassTypeFixed = BigType<T> && std::is_class_v<T>;

void bar(BigType auto x) {
	std::cout << " - Big Type x: " << x << std::endl;
}

#ifdef SHOW_COMPILE_ERRORS
void bar(BigClassType auto x) {
	std::cout << " - Big Class Type x: " << x << std::endl;
}
#else
void bar(BigClassTypeFixed auto x) {
	std::cout << " - Big Class Type fixed x: " << x << std::endl;
}
#endif

template <typename T>
concept ClassType = std::is_class_v<T>;

template <typename T>
concept BigOrClass = BigType<T> || ClassType<T>;

// BigAndClass subsume concept BigOrClass.
// NOTE: As much subsumption depth increases, 
// compile time increases.
template <typename T>
concept BigAndClass = BigType<T> && ClassType<T>;

void fooBar(BigOrClass auto x) {
	std::cout << " - BigOrClass x: " << x << std::endl;
}

void fooBar(BigAndClass auto x) {
	std::cout << " - BigAndClass x: " << x << std::endl;
}