cmake_minimum_required(VERSION 3.10)

# set the project name
project(Projet1 VERSION 1.0)

# add the executable
add_executable(Exe1 src/main.cpp)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)




file(GLOB testFiles "test/tests/*.cpp")
foreach(fileNameWithPath ${testFiles})
    get_filename_component(fileNameNoExtention ${fileNameWithPath} NAME_WE)
    message( "--> Test found: " ${fileNameNoExtention}.cpp )
    add_executable(${fileNameNoExtention} ${fileNameWithPath})
    message( "\t- executable of test added" )
    target_link_libraries(${fileNameNoExtention} Catch2::Catch2)
    message( "\t- library linked" )
endforeach()



