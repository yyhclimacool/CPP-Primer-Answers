set(list_of_targets)
aux_source_directory(. chap2_srcs)
foreach(file IN LISTS chap2_srcs)
    string(REPLACE ".cc" "" file_name_without_cc ${file})
    string(REPLACE "./" "" target_name ${file_name_without_cc})
    string(FIND ${target_name} "2_42" find_index)
    if(NOT ${find_index} EQUAL -1)
        message(CONTINUE)
        continue()
    endif()
    add_executable(${target_name} ${file})
    list(APPEND list_of_targets ${target_name})
endforeach()

install(TARGETS ${list_of_targets}
    RUNTIME DESTINATION bin/chapter02
)
