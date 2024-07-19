# Find the GTest package. REQUIRED means CMake will report an error if GTest is not found
find_package(GTest REQUIRED)

# Add the GTest include directories to the include path
# This allows your test files to include GTest headers with #include <gtest/gtest.h>
include_directories(${GTEST_INCLUDE_DIRS})

# Create an executable named 'postfix_calculator_test' from the source file 'PostfixCalculatorTest.cpp'
add_executable(postfix_calculator_test PostfixCalculatorTest.cpp)

# Link the 'postfix_calculator_test' executable with:
# 1. The 'postfix_calculator_lib' library (your main project library)
# 2. The GTest libraries (for the testing framework)
# 3. pthread (POSIX threads library, often required by GTest)
target_link_libraries(postfix_calculator_test postfix_calculator_lib ${GTEST_LIBRARIES} pthread)

# Add a test to the project to be run by CTest
# NAME specifies a name for the test
# COMMAND specifies the command to run the test (in this case, just run the executable)
add_test(NAME postfix_calculator_test COMMAND postfix_calculator_test)