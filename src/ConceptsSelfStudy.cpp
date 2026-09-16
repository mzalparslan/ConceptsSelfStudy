
#include "01_Introduction.h"
#include "02_InvalidConcept.h"
#include "03_Autos.h"
#include "04_Ranges.h"
#include "05_MultipleParameters.h"
#include "06_MultipleRequirements.h"
#include "07_RequiresRequires.h"
#include "08_Conditional.h"
#include "09_Ambiguties.h"
#include "10_Subsumption.h"
#include "11_SubsumeNotAutomatic.h"
#include "12_ConstraintsForMembers.h"
#include "13_ConstraintsForNonTypes.h"
#include "TestCounter.h"

// Counter for tests.
int testCount = 1;

int main()
{
	// --- Basic concepts for Concepts ---
	testAdd();
	testAddWithConcept();
	testAddWithShortConcept();
	testAddWithMisspelledConcept();
	// --- Auto Keyword with Concepts ---
	testAddByAutoKeyword();
	testAddAutoWithConcept();
	testAddAutoWithRequiresClause();
	testAddAutoWithRequiresClauseFixed();
	testAddAutoByRanges();
	// --- Multiple Parameters in Concepts ---
	testAddConceptsOfMultipleParams();
	testAddAutoConceptsOfMultipleParams();
	// --- Multiple Requirements within Concepts ---
	testAddConceptsOfMultipleReqs();
	testAddForLessThanComparisionRequirement();
	// --- Requires requirement using Requires constraint ---
	testAddRequiresRequires();
	// --- Conditional Concepts ---
	testAddConditionalConcepts();
	testAddConditionalWithErrors();
	testAddConditionalTypeChecking();
	testAddConditionalTypeCheckingParam();

	// --- Ambiguties ---
	testAmbiguties();
	testAmbigutiesAfterFix();
	// -- Concept Subsumption ---
	testConceptSubsumption();
	testConceptSubsumptionAndOrOr();
	
	// --- Subsume Not Automatic ---
	testSubsumeForCowboy();
	testGeoObjectAndCowboyTogether();

	// --- Constraints for Members ---
	testMemberWithNoConstraint();
	testConstraintsForMemberZero();
	testConstraintsForMemberEmpty();

	// --- Constraints for Non-Type Templates ---
	testConstraintsForNonTypes();
	testConceptsWithNonTypeParams();

    return 0;
}
