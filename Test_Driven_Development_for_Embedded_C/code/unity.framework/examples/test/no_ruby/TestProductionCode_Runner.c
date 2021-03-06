/***
 * Excerpted from "Test-Driven Development for Embedded C",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
***/
/* AUTOGENERATED FILE. DO NOT EDIT. */
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

char MessageBuffer[50];

extern void setUp(void);
extern void tearDown(void);

extern void test_FindFunction_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList_WhichWorksEvenInOurBrokenCode(void);
extern void test_FindFunction_WhichIsBroken_ShouldReturnTheIndexForItemsInList_WhichWillFailBecauseOurFunctionUnderTestIsBroken(void);
extern void test_FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValue(void);
extern void test_FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValueAgain(void);
extern void test_FunctionWhichReturnsLocalVariable_ShouldReturnCurrentCounter_ButFailsBecauseThisTestIsActuallyFlawed(void);

static void runTest(UnityTestFunction test)
{
  if (TEST_PROTECT())
  {
      setUp();
      test();
  }
  if (TEST_PROTECT() && !TEST_IS_IGNORED)
  {
    tearDown();
  }
}
void resetTest()
{
  tearDown();
  setUp();
}


int main(void)
{
  Unity.TestFile = "test/TestProductionCode.c";
  UnityBegin();

  // RUN_TEST calls runTest
  RUN_TEST(test_FindFunction_WhichIsBroken_ShouldReturnZeroIfItemIsNotInList_WhichWorksEvenInOurBrokenCode, 20);
  RUN_TEST(test_FindFunction_WhichIsBroken_ShouldReturnTheIndexForItemsInList_WhichWillFailBecauseOurFunctionUnderTestIsBroken, 30);
  RUN_TEST(test_FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValue, 41);
  RUN_TEST(test_FunctionWhichReturnsLocalVariable_ShouldReturnTheCurrentCounterValueAgain, 51);
  RUN_TEST(test_FunctionWhichReturnsLocalVariable_ShouldReturnCurrentCounter_ButFailsBecauseThisTestIsActuallyFlawed, 57);

  UnityEnd();
  return 0;
}
