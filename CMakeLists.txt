cmake_minimum_required(VERSION 3.10)
project(MyCalculator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add main executable
add_executable(calculator_main main.cpp calculator_impl.cpp)

# Add test executable
add_executable(calculator_test test.cpp calculator_impl.cpp)

# Include directory for header files
target_include_directories(calculator_main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(calculator_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link libraries for test executable
target_link_libraries(calculator_test PRIVATE cppunit)

# If you have additional libraries to link for the main executable, you can add them here
# target_link_libraries(calculator_main <library_name>)

# Optionally, you may want to enable testing in CMake
enable_testing()
add_test(NAME calculator_test COMMAND calculator_test)
