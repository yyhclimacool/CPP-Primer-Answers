cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(CPPPrimer_answers LANGUAGES C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

message(STATUS "*** CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})

message(STATUS "*** CMAKE_C_FLAGS_DEBUG: " ${CMAKE_C_FLAGS_DEBUG})
message(STATUS "*** CMAKE_C_FLAGS_RELEASE: " ${CMAKE_C_FLAGS_RELEASE})
message(STATUS "*** CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "*** CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE})

set(CXXFLAGS
  -g
  -Wall
  -Wextra
  -O3
  -fno-omit-frame-pointer
)
string(REPLACE ";" " " CXXFLAGS "${CXXFLAGS}")
string(APPEND CMAKE_CXX_FLAGS " ")
string(APPEND CMAKE_CXX_FLAGS ${CXXFLAGS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# include(FetchContent)
# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(src)

install(FILES README.md DESTINATION doc COMPONENT document RENAME "README.md")
