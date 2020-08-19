cmake_minimum_required(VERSION 3.1)

project(klt_demo
	LANGUAGES C CXX
	VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

find_package(OpenCV REQUIRED)
message(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_LIBS})

add_executable(klt ${CMAKE_SOURCE_DIR}/main.cpp)
target_include_directories(klt PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(klt PUBLIC ${OpenCV_LIBS})
