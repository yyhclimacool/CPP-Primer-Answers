add_executable(exercise_6_03 exercise_6_03.cc)
add_executable(exercise_6_04 exercise_6_04.cc)
add_executable(exercise_6_05 exercise_6_05.cc)
add_executable(exercise_6_06 exercise_6_06.cc)
add_executable(exercise_6_07 exercise_6_07.cc)
add_executable(exercise_6_09 exercise_6_09.cc)
add_executable(exercise_6_10 exercise_6_10.cc)
add_executable(exercise_6_11 exercise_6_11.cc)
add_executable(exercise_6_12 exercise_6_12.cc)
add_executable(exercise_6_17 exercise_6_17.cc)
add_executable(exercise_6_21 exercise_6_21.cc)
add_executable(exercise_6_23 exercise_6_23.cc)

install(TARGETS exercise_6_03 exercise_6_04
    exercise_6_05 exercise_6_06 exercise_6_07
    exercise_6_09 exercise_6_10 exercise_6_11
    exercise_6_12 exercise_6_17 exercise_6_21
    exercise_6_23
    RUNTIME DESTINATION bin/chapter06)
