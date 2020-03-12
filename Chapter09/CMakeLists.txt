add_executable(exercise_9_02 exercise_9_02.cc)
add_executable(exercise_9_04 exercise_9_04.cc)
add_executable(exercise_9_05 exercise_9_05.cc)
add_executable(exercise_9_06 exercise_9_06.cc)
add_executable(exercise_9_07 exercise_9_07.cc)
add_executable(exercise_9_08 exercise_9_08.cc)
add_executable(exercise_9_11 exercise_9_11.cc)
add_executable(exercise_9_13 exercise_9_13.cc)
add_executable(exercise_9_14 exercise_9_14.cc)
add_executable(exercise_9_15 exercise_9_15.cc)
add_executable(exercise_9_16 exercise_9_16.cc)
add_executable(exercise_9_18 exercise_9_18.cc)
add_executable(exercise_9_19 exercise_9_19.cc)
add_executable(exercise_9_20 exercise_9_20.cc)
add_executable(exercise_9_22 exercise_9_22.cc)
add_executable(exercise_9_24 exercise_9_24.cc)
add_executable(exercise_9_26 exercise_9_26.cc)
add_executable(exercise_9_27 exercise_9_27.cc)
add_executable(exercise_9_28 exercise_9_28.cc)
add_executable(exercise_9_29 exercise_9_29.cc)

install(TARGETS exercise_9_02 exercise_9_04 exercise_9_05
    exercise_9_06 exercise_9_07 exercise_9_08 exercise_9_11
    exercise_9_13 exercise_9_14 exercise_9_15 exercise_9_16
    exercise_9_18 exercise_9_19 exercise_9_20 exercise_9_22
    exercise_9_24 exercise_9_26 exercise_9_27 exercise_9_28
    exercise_9_29
    RUNTIME DESTINATION bin/chapter09
)
