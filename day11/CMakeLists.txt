project(day11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories("${PROJECT_SOURCE_DIR}/include")

# Part 1

add_executable(day11part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day11part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day11part1test COMMAND sh -c "$<TARGET_FILE:day11part1> < input")
set_tests_properties(day11part1test PROPERTIES PASS_REGULAR_EXPRESSION "759")

# Part 2

add_executable(day11part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day11part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day11part2test COMMAND sh -c "$<TARGET_FILE:day11part2> < input")
set_tests_properties(day11part2test PROPERTIES PASS_REGULAR_EXPRESSION "1501")
