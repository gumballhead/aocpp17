project(day3)
include_directories("${PROJECT_SOURCE_DIR}/include")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Part 1

add_executable(day3part1 ${PROJECT_SOURCE_DIR}/src/part1.cpp)
set_target_properties(day3part1 PROPERTIES OUTPUT_NAME "part1")

add_test(NAME day3part1test COMMAND day3part1 347991)
set_tests_properties(day3part1test PROPERTIES PASS_REGULAR_EXPRESSION "480")

# Part 2

#add_executable(day3part2 ${PROJECT_SOURCE_DIR}/src/part2.cpp)
#set_target_properties(day3part2 PROPERTIES OUTPUT_NAME "part2")

#add_test(NAME day3part2test COMMAND sh -c "$<TARGET_FILE:day3part2> < input")
#set_tests_properties(day3part2test PROPERTIES PASS_REGULAR_EXPRESSION "25608480")
