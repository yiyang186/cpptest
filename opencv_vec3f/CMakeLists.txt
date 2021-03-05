cmake_minimum_required(VERSION 3.1)

project(demo
	LANGUAGES C CXX
	VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -o3")

find_package(OpenCV REQUIRED)
message(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_LIBS})

add_executable(demo ${CMAKE_SOURCE_DIR}/main.cpp)
target_include_directories(demo PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(demo PUBLIC ${OpenCV_LIBS})
