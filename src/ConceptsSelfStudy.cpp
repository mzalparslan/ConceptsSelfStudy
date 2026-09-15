
#include "01_Introduction.h"
#include "02_InvalidConcept.h"
#include "03_Autos.h"
#include "04_Ranges.h"
#include "05_MultipleParameters.h"
#include "06_MultipleRequirements.h"
#include "07_RequiresRequires.h"
#include "08_Conditional.h"

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

    return 0;
}
