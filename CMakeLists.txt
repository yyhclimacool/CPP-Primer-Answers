cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(CPPPrimer_answers LANGUAGES C CXX)
add_subdirectory(Chapter01)
add_subdirectory(Chapter02)
add_subdirectory(Chapter03)
add_subdirectory(Chapter16)

install(FILES README.md DESTINATION doc COMPONENT document RENAME "README.md")
