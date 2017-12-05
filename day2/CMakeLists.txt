project(day2)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day2part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day2part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day2part1test COMMAND sh -c "$<TARGET_FILE:day2part1> < input")
set_tests_properties(day2part1test PROPERTIES PASS_REGULAR_EXPRESSION "44216")

# Part 2

add_executable(day2part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day2part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day2part2test COMMAND sh -c "$<TARGET_FILE:day2part2> < input")
set_tests_properties(day2part2test PROPERTIES PASS_REGULAR_EXPRESSION "320")
