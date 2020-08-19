cmake_minimum_required(VERSION 3.1)

project(klt_demo
	LANGUAGES C CXX
	VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

file(GLOB SRCS ${CMAKE_SOURCE_DIR}/*.cpp)
add_executable(cvtrack ${SRCS})
target_include_directories(cvtrack PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cvtrack PUBLIC ${OpenCV_LIBS})
