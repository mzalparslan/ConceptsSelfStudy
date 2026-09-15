#pragma once

// Test methods used to verify current concepts 
// defined in this header file.
void testAddRequiresRequires();

// Requires expression defines requirements.
// Requires clause defines constraints.
void addRequiresRequires(auto& coll, const auto& value) 
	requires requires { coll.push_back(value); } {
	coll.push_back(value);
}

void addRequiresRequires(auto& coll, const auto& value) {
	coll.insert(value);
}