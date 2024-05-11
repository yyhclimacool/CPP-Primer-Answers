aux_source_directory(. chap9_srcs)
# set(target_list)
# foreach(file IN LISTS chap9_srcs)
#     string(REPLACE ".cc" "" target_name_temp ${file})
#     string(REPLACE "./" "" target_name ${target_name_temp})
#     add_executable(${target_name} ${file})
#     list(APPEND target_list ${target_name})
# endforeach()

# install(TARGETS ${target_list}
#     RUNTIME DESTINATION bin/chapter09
# )

# 查找gtest库
find_package(GTest REQUIRED)

# 如果需要，在MSVC上强制使用静态运行时库
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# 添加测试目标
add_executable(chap9_unittest ${chap9_srcs})

# 包含gtest的头文件
target_include_directories(chap9_unittest PRIVATE ${GTEST_INCLUDE_DIRS})

# # 链接gtest到测试目标
target_link_libraries(chap9_unittest ${GTEST_BOTH_LIBRARIES})
# # 链接Google Test的静态库，假设静态库名为 gtest_main.a 和 gtest.a
# target_link_libraries(chap9_unittest -Wl,-Bstatic ${GTEST_MAIN_LIBRARIES} ${GTEST_LIBRARIES} -Wl,-Bdynamic pthread)

# 启用测试
enable_testing()

# 添加测试
include(GoogleTest)
gtest_discover_tests(chap9_unittest)
install(TARGETS chap9_unittest
    RUNTIME DESTINATION bin/chapter09)