cmake_minimum_required(VERSION 3.22)
project(STS LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wpedantic -Wconversion")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories("src")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CEPHES-LIB #
file(GLOB_RECURSE cephes_src "src/cephes/cephes.cpp")
add_library(cephes_lib STATIC ${cephes_src})

# CPU-TESTS-LIB #
file(GLOB_RECURSE cpu_tests_src "src/cpu_tests/*.cpp")
add_library(cpu_tests_lib STATIC ${cpu_tests_src})
target_link_libraries(cpu_tests_lib PRIVATE cephes_lib)

file(GLOB main_src "src/main.cpp")
add_executable(sts ${main_src})
target_link_libraries(sts PRIVATE cpu_tests_lib)

# # STS-UT.EXE #
# file(GLOB_RECURSE ut_src "src/tests/*_ut.cpp")
# add_executable(sts_ut ${ut_src})
# target_link_libraries(sts_ut PRIVATE sts_lib)
# target_link_libraries(sts_ut PRIVATE Catch2::Catch2WithMain)
#
# # STS.EXE #
# file(GLOB main_src "src/main.cpp")
# add_executable(sts ${main_src})
# target_link_libraries(sts PRIVATE sts_lib)
