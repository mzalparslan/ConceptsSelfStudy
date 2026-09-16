#pragma once

#include <type_traits>
#include <iostream>

void testMemberWithNoConstraint();
void testConstraintsForMemberZero();
void testConstraintsForMemberEmpty();

template <typename T>
class MyType {
public:
	T value;

	void print() const {
		std::cout << " - MyType.value: " << value << std::endl;
	}

	bool isZero() const
		// If member T value is integral type or floating point data type.
		requires std::integral<T> || std::floating_point<T> {
		return value == 0;
	}

	bool isEmpty() const
		// If member has a member method empty()
		requires requires { value.empty(); } {
		return value.empty();
	}
};