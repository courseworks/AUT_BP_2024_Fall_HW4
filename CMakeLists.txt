cmake_minimum_required(VERSION 3.16)
project(AUT_BP_2024_Fall_HW4)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set C standard
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)


find_package(GTest REQUIRED)


include_directories(include/)

add_executable(main
        src/main.cpp
        src/unit_test.cpp
        src/Q1_SwapArrays.c
        src/Q2_TransposeMatrix.c 
        src/Q3_SortArray.c
)

# Set compiler flags for C++ and c.
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic")
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -Wpedantic")


# Link the executable to the Google Test libraries.
target_link_libraries(main
        GTest::GTest
        GTest::Main
)
