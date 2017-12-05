project(day1)
include_directories("${PROJECT_SOURCE_DIR}/include")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day1part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day1part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day1part1test COMMAND sh -c "$<TARGET_FILE:day1part1> < input")
set_tests_properties(day1part1test PROPERTIES PASS_REGULAR_EXPRESSION "1069")

# Part 2

add_executable(day1part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
set_target_properties(day1part2 PROPERTIES OUTPUT_NAME "part2")

add_test(NAME day1part2test COMMAND sh -c "$<TARGET_FILE:day1part2> < input")
set_tests_properties(day1part2test PROPERTIES PASS_REGULAR_EXPRESSION "1268")
