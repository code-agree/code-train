find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(postfix_calculator_test PostfixCalculatorTest.cpp)
target_link_libraries(postfix_calculator_test postfix_calculator_lib ${GTEST_LIBRARIES} pthread)

add_test(NAME postfix_calculator_test COMMAND postfix_calculator_test)