cmake_minimum_required(VERSION 3.5)

project(det_matrix)

add_executable(matrix matrix.cpp)

set_target_properties(
	matrix PROPERTIES
	CXX_STANDART 20
	CXX_STANDART_REQUIRED ON
)

add_executable(tests_matrix tests/tests_matrix.cpp)

set_target_properties(
	tests_matrix PROPERTIES
	CXX_STANDART 20
	CXX_STANDART_REQUIRED ON
)

