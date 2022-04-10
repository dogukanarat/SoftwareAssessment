[![CMake](https://github.com/dogukanarat/SoftwareAssessment/actions/workflows/cmake.yml/badge.svg)](https://github.com/dogukanarat/SoftwareAssessment/actions/workflows/cmake.yml)

# Software Assessment
Software development company assessment. Project includes 2 libraries which were tested with GoogleTest framework.

The output of the GoogleTest is below.

```
[ctest]       Start  1: TestLargeExponent.CheckIsDigitMethod
[ctest]  1/19 Test  #1: TestLargeExponent.CheckIsDigitMethod ........................   Passed    0.00 sec
[ctest]       Start  2: TestLargeExponent.CheckInputMethod
[ctest]  2/19 Test  #2: TestLargeExponent.CheckInputMethod ..........................   Passed    0.00 sec
[ctest]       Start  3: TestLargeExponent.CheckReverseMethod
[ctest]  3/19 Test  #3: TestLargeExponent.CheckReverseMethod ........................   Passed    0.00 sec
[ctest]       Start  4: TestLargeExponent.CheckInitialiseBufferMethod
[ctest]  4/19 Test  #4: TestLargeExponent.CheckInitialiseBufferMethod ...............   Passed    0.00 sec
[ctest]       Start  5: TestLargeExponent.CheckFinaliseBufferMethod
[ctest]  5/19 Test  #5: TestLargeExponent.CheckFinaliseBufferMethod .................   Passed    0.00 sec
[ctest]       Start  6: TestLargeExponent.CheckBufferTransition
[ctest]  6/19 Test  #6: TestLargeExponent.CheckBufferTransition .....................   Passed    0.00 sec
[ctest]       Start  7: TestLargeExponent.CheckMultiplyMethodDifferentSize
[ctest]  7/19 Test  #7: TestLargeExponent.CheckMultiplyMethodDifferentSize ..........   Passed    0.00 sec
[ctest]       Start  8: TestLargeExponent.CheckMultiplyMethodBasic
[ctest]  8/19 Test  #8: TestLargeExponent.CheckMultiplyMethodBasic ..................   Passed    0.00 sec
[ctest]       Start  9: TestLargeExponent.CheckCalculateBufferMethodSameSize
[ctest]  9/19 Test  #9: TestLargeExponent.CheckCalculateBufferMethodSameSize ........   Passed    0.00 sec
[ctest]       Start 10: TestLargeExponent.CheckCalculateBufferMethodDifferentSize
[ctest] 10/19 Test #10: TestLargeExponent.CheckCalculateBufferMethodDifferentSize ...   Passed    0.00 sec
[ctest]       Start 11: TestLargeExponent.CheckCalculationMethod1
[ctest] 11/19 Test #11: TestLargeExponent.CheckCalculationMethod1 ...................   Passed    0.00 sec
[ctest]       Start 12: TestLargeExponent.CheckCalculationMethod2
[ctest] 12/19 Test #12: TestLargeExponent.CheckCalculationMethod2 ...................   Passed    0.00 sec
[ctest]       Start 13: TestLargeExponent.CheckCalculationMethod3
[ctest] 13/19 Test #13: TestLargeExponent.CheckCalculationMethod3 ...................   Passed    0.00 sec
[ctest]       Start 14: TestLargeExponent.CheckClass
[ctest] 14/19 Test #14: TestLargeExponent.CheckClass ................................   Passed    0.00 sec
[ctest]       Start 15: TestLargeExponent.CheckClassFinal
[ctest] 15/19 Test #15: TestLargeExponent.CheckClassFinal ...........................   Passed    0.01 sec
[ctest]       Start 16: TestConversion.CheckSearchBoundaries
[ctest] 16/19 Test #16: TestConversion.CheckSearchBoundaries ........................   Passed    0.00 sec
[ctest]       Start 17: TestConversion.CheckSearchResult
[ctest] 17/19 Test #17: TestConversion.CheckSearchResult ............................   Passed    0.00 sec
[ctest]       Start 18: TestConversion.CheckNormalize
[ctest] 18/19 Test #18: TestConversion.CheckNormalize ...............................   Passed    0.00 sec
[ctest]       Start 19: TestConversion.CheckGetPressure
[ctest] 19/19 Test #19: TestConversion.CheckGetPressure .............................   Passed    0.00 sec
[ctest] 
[ctest] 100% tests passed, 0 tests failed out of 19
```
# Coverage Report
[Report Link](https://rawcdn.githack.com/dogukanarat/SoftwareAssessment/0f8c3ab990323d1642d8a3ab6b0fc9274dbbddc6/Coverage/report/index.html)

| SubModule     | Line Percentage|
| ------------- |:--------------:|
| Conversion    | %95            |
| LargeExponent | %95.4          |
