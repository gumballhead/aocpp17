project(day6)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day6part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day6part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day6part1test COMMAND sh -c "$<TARGET_FILE:day6part1> < input")
set_tests_properties(day6part1test PROPERTIES PASS_REGULAR_EXPRESSION "11137")

# Part 2

add_executable(day6part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day6part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day6part2test COMMAND sh -c "$<TARGET_FILE:day6part2> < input")
set_tests_properties(day6part2test PROPERTIES PASS_REGULAR_EXPRESSION "1037")
