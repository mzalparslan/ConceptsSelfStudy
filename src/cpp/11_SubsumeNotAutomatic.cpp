
#include "11_SubsumeNotAutomatic.h"	
#include "TestCounter.h"
#include <vector>
#include <set>
#include <list>
#include <iostream>
#include <string>

class Circle {
public:
	Circle(std::string name_) : name(name_) {}

	void draw() const{
		std::cout << " - Circle::draw: " << this->name << std::endl;
	}
private:
	std::string name;
};

static_assert(GeoObject<Circle>);
static_assert(Cowboy<Circle>);

#ifdef SHOW_COMPILE_ERRORS
void testSubsumeForCowboy() {
	std::cout << testCount++ << "# " << "Testing Concept Cowboy subsumption:\n"
		" - No Output because of guarded Compile Error!\n";
	
	// COMPILE ERROR: Ambigutious call.
	Circle c("Basic Circle");	
	print(c);
}
#else
void testSubsumeForCowboy() {
	std::cout << testCount++ << "# " << "Testing Concept Cowboy subsumption:\n";

	Circle c("Basic Circle");
	print(c);
}
#endif

void testGeoObjectAndCowboyTogether() {
	std::cout << testCount++ << "# " << "Testing Concept and Cowboy together:\n";

	Circle c("Second Circle");
	printAlternative(c);
}