project(day4)
include_directories("${PROJECT_SOURCE_DIR}/include")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day4part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day4part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day4part1test COMMAND sh -c "$<TARGET_FILE:day4part1> < input")
set_tests_properties(day4part1test PROPERTIES PASS_REGULAR_EXPRESSION "477")

# Part 2

add_executable(day4part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day4part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day4part2test COMMAND sh -c "$<TARGET_FILE:day4part2> < input")
set_tests_properties(day4part2test PROPERTIES PASS_REGULAR_EXPRESSION "167")
