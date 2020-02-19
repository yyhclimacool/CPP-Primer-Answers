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
add_executable(exercise_1_16 exercise_1_16.cc)
add_executable(exercise_1_18 exercise_1_18.cc)
add_executable(exercise_1_19 exercise_1_19.cc)
add_executable(exercise_1_20 exercise_1_20.cc)
add_executable(exercise_1_21 exercise_1_21.cc)
add_executable(exercise_1_22 exercise_1_22.cc)
add_executable(exercise_1_23 exercise_1_23.cc)
add_executable(exercise_1_25 exercise_1_25.cc)

install(TARGETS exercise_1_02 exercise_1_03 exercise_1_04
    exercise_1_05 exercise_1_06 exercise_1_07 exercise_1_08
    exercise_1_09 exercise_1_10 exercise_1_11 exercise_1_12
    exercise_1_16 exercise_1_18 exercise_1_19 exercise_1_20
    exercise_1_21 exercise_1_22 exercise_1_23 exercise_1_25
    RUNTIME DESTINATION bin/chapter01)

install(PROGRAMS exercise_1_18.sh DESTINATION bin/chapter01)
