add_executable(exercise_1_02 exercise_1_02.cc)
add_executable(exercise_1_03 exercise_1_03.cc)
add_executable(exercise_1_04 exercise_1_04.cc)
add_executable(exercise_1_05 exercise_1_05.cc)
add_executable(exercise_1_06 exercise_1_06.cc)
add_executable(exercise_1_07 exercise_1_07.cc)
add_executable(exercise_1_08 exercise_1_08.cc)
add_executable(exercise_1_09 exercise_1_09.cc)
add_executable(exercise_1_10 exercise_1_10.cc)
add_executable(exercise_1_11 exercise_1_11.cc)
add_executable(exercise_1_12 exercise_1_12.cc)
install(TARGETS exercise_1_02 exercise_1_03 exercise_1_04
    exercise_1_05 exercise_1_06 exercise_1_07 exercise_1_08
    exercise_1_09 exercise_1_10 exercise_1_11 exercise_1_12
    RUNTIME DESTINATION bin/chapter01)
