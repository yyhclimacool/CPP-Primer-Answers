aux_source_directory(. chap1_srcs)
set(list_of_target)
foreach(file IN LISTS chap1_srcs)
    string(REPLACE ".cc" "" file_name_without_cc ${file})
    string(REPLACE "./" "" exec_name ${file_name_without_cc})
    add_executable(${exec_name} ${file})
    list(APPEND list_of_target ${exec_name})
endforeach()

install(TARGETS ${list_of_target}
    RUNTIME DESTINATION bin/chapter01
)

install(PROGRAMS exercise_1_18.sh DESTINATION bin/chapter01)
