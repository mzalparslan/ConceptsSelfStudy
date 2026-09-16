#pragma once

#include <type_traits>
#include <iostream>

void testSubsumeForCowboy();
void testGeoObjectAndCowboyTogether();

template <typename T>
concept GeoObject = requires(T obj) {
	obj.draw();
};

template <GeoObject T>
void print(T obj) {
	std::cout << " - GeoObject: \n";
	obj.draw();
}

#ifdef SHOW_COMPILE_ERRORS
// There is no auto subsumption that Cowbow will
// be subsume GeoObject and will be used. There 
// is no such automatic subsumption.
template <typename T>
concept Cowboy = requires(T obj) {
	obj.draw();
	obj = obj;
};
#else
template <typename T>
// Now Cowboy will subsube GeoObject.
concept Cowboy = GeoObject<T> && requires(T obj) {
	obj = obj;
};
#endif

template <Cowboy T>
void print(T obj) {
	std::cout << " - Cowboy subsumed GeoObject:\n";
	obj.draw();
}

template <GeoObject T>
void printAlternative(T obj) {
	std::cout << " - GeoObject: \n";
	obj.draw();
}
// An alternative is to require both concepts.
template <typename T>
requires GeoObject<T> && Cowboy<T>
void printAlternative(T obj) {
	std::cout << " - GeoObject and Cowboy together:\n";
	obj.draw();
}
