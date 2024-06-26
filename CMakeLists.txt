cmake_minimum_required(VERSION 3.25.2)
project(ozone LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 20)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_ARCHITECTURES 89)

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

# UTILS-LIB #
file(GLOB_RECURSE utils_src "src/utils/utils.cpp")
add_library(utils_lib STATIC ${utils_src})

# CPU-TESTS-LIB #
file(GLOB_RECURSE cpu_tests_src "src/cpu_tests/*.cpp")
add_library(cpu_tests_lib STATIC ${cpu_tests_src})
target_link_libraries(cpu_tests_lib PRIVATE cephes_lib utils_lib)

# CUDA-TESTS-LIB #
file(GLOB_RECURSE cuda_tests_src "src/cuda_tests/*.cu")
add_library(cuda_tests_lib STATIC ${cuda_tests_src})
set_target_properties(cuda_tests_lib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
target_compile_options(cuda_tests_lib PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:--expt-relaxed-constexpr>)

file(GLOB main_src "src/main.cu")
add_executable(sts ${main_src})
target_link_libraries(sts PRIVATE cpu_tests_lib)
target_link_libraries(sts PRIVATE cuda_tests_lib)
