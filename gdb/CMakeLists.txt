cmake_minimum_required(VERSION 3.1)

project(gdb_test
	LANGUAGES C CXX
	VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


add_library(foo SHARED ${CMAKE_SOURCE_DIR}/src/func.cpp)
target_include_directories(foo PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(a.out ${CMAKE_SOURCE_DIR}/main.cpp)
target_include_directories(a.out PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(a.out PUBLIC foo)
