#pragma once

#include <ranges>

// Test methods used to verify current concepts 
// defined in this header file.
void testAddAutoByRanges();

// Using ranges::range_value_t in constraint will push
// compiler to verify Collection and T have same data type.
template <typename CollT>
concept HasPushbackWithRanges =
	requires(CollT coll, std::ranges::range_value_t<CollT> value) {
	coll.push_back(value);
};

// decltype will declare Collection type while 
// Concept constraint will check Collection and T 
// have same type.
void addAutoByRanges(auto& coll, const auto& value)
	requires HasPushbackWithRanges<decltype(coll)> {
	coll.push_back(value);
}

// Method added to verify current Concept is working.
void addAutoByRanges(auto& coll, const auto& value) {
	coll.insert(value);
}
