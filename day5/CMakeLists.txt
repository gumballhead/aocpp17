project(day5)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day5part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day5part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day5part1test COMMAND sh -c "$<TARGET_FILE:day5part1> < input")
set_tests_properties(day5part1test PROPERTIES PASS_REGULAR_EXPRESSION "372671")

# Part 2

add_executable(day5part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day5part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day5part2test COMMAND sh -c "$<TARGET_FILE:day5part2> < input")
set_tests_properties(day5part2test PROPERTIES PASS_REGULAR_EXPRESSION "25608480")
