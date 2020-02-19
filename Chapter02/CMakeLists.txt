add_executable(exercise_2_04 exercise_2_04.cc)
add_executable(exercise_2_06 exercise_2_06.cc)
add_executable(exercise_2_08 exercise_2_08.cc)
add_executable(exercise_2_09 exercise_2_09.cc)
add_executable(exercise_2_10 exercise_2_10.cc)
add_executable(exercise_2_13 exercise_2_13.cc)
add_executable(exercise_2_14 exercise_2_14.cc)
add_executable(exercise_2_16 exercise_2_16.cc)
add_executable(exercise_2_17 exercise_2_17.cc)
add_executable(exercise_2_18 exercise_2_18.cc)
add_executable(exercise_2_20 exercise_2_20.cc)

install(TARGETS exercise_2_04 exercise_2_06 exercise_2_08
    exercise_2_09 exercise_2_10 exercise_2_13 exercise_2_14
    exercise_2_16 exercise_2_17 exercise_2_18 exercise_2_20
    DESTINATION bin/chapter02 COMPONENT binaries)
