add_executable(exercise_3_01 exercise_3_01.cc)
add_executable(exercise_3_02 exercise_3_02.cc)
add_executable(exercise_3_04 exercise_3_04.cc)
add_executable(exercise_3_05 exercise_3_05.cc)
add_executable(exercise_3_06 exercise_3_06.cc)
add_executable(exercise_3_07 exercise_3_07.cc)
add_executable(exercise_3_08 exercise_3_08.cc)
add_executable(exercise_3_09 exercise_3_09.cc)
add_executable(exercise_3_10 exercise_3_10.cc)
add_executable(exercise_3_11 exercise_3_11.cc)

install(TARGETS exercise_3_01 exercise_3_02 exercise_3_04
    exercise_3_05 exercise_3_06 exercise_3_07 exercise_3_08
    exercise_3_09 exercise_3_10 exercise_3_11
    RUNTIME DESTINATION bin/chapter03)
