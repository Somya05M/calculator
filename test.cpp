#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>

#include "calculator.h"

using namespace std;

class CalculatorTest : public CppUnit::TestCase {
public:
    void testSquareRoot() {
        Calculator calc;
        CPPUNIT_ASSERT_EQUAL(2.0, calc.squareRoot(4.0));
        CPPUNIT_ASSERT_EQUAL(3.0, calc.squareRoot(9.0));
        CPPUNIT_ASSERT_EQUAL(0.0, calc.squareRoot(0.0)); // Additional test case
    }

    void testFactorial() {
        Calculator calc;
        CPPUNIT_ASSERT_EQUAL(1, calc.factorial(0));
        CPPUNIT_ASSERT_EQUAL(1, calc.factorial(1));
        CPPUNIT_ASSERT_EQUAL(6, calc.factorial(3));
        CPPUNIT_ASSERT_EQUAL(24, calc.factorial(4)); // Additional test case
    }

    void testNaturalLog() {
        Calculator calc;
        CPPUNIT_ASSERT_EQUAL(0.0, calc.naturalLog(1.0));
        CPPUNIT_ASSERT_DOUBLES_EQUAL(0.693147, calc.naturalLog(2.0), 0.000001);
        CPPUNIT_ASSERT_DOUBLES_EQUAL(1.609438, calc.naturalLog(5.0), 0.000001); // Additional test case
    }

    void testPower() {
        Calculator calc;
        CPPUNIT_ASSERT_EQUAL(4, calc.power(2, 2));
        CPPUNIT_ASSERT_EQUAL(8, calc.power(2, 3));
        CPPUNIT_ASSERT_EQUAL(16, calc.power(2, 4)); // Additional test case
    }

    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testSquareRoot);
    CPPUNIT_TEST(testFactorial);
    CPPUNIT_TEST(testNaturalLog);
    CPPUNIT_TEST(testPower);
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTest);

int main() {
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());
    bool wasSuccessful = runner.run("", false);
    if (wasSuccessful)
    {
        cout<<"All test cases passed!!"<<endl;
    }
    else{
        cout<<"Some test cases failed"<<endl;
    }
    
    return wasSuccessful ? 0 : 1;
}
// g++ -o test test.cpp calculator_impl.cpp -lcppunit