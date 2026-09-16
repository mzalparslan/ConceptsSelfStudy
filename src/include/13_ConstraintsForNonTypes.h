#pragma once

void testConstraintsForNonTypes();
void testConceptsWithNonTypeParams();

// Constraint defined at compile time.
constexpr bool isPrime(int value) {
	for (int i = 2; i <= value / 2; i++) {
		if (value % i == 0) {
			return false;
		}
	}

	// 2 and 3 are primes, 0 and 1 not.
	return value > 1;
}

// Only prime numbers can be used.
template <auto Value>
// Needs to use paranthesis () when expression is boolean
// for backward compability.
requires (isPrime(Value))
class TestClass {
	int memberValue = Value;
public:
	int getValue() { return memberValue; }
};

// Concept with non-type compile-time methods.
template <auto Value>
concept IsPrime = Value > 0 && isPrime(Value);
// Now it is more clear as IsPrime is a Concept and Constraint.
template <auto Value>
requires IsPrime<Value>
class PrimeClass {
	int memberValue = Value;
public:
	int getValue() { return memberValue; }
};