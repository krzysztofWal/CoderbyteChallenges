cmake_minimum_required(VERSION 3.17)

project(CoderbyteChallenges)

add_subdirectory(tools/DummyInputLib)

FILE(GLOB_RECURSE cpp_executables_ "src/*.cpp")

# message(STATUS ${CMAKE_CURRENT_LIST_DIR})
string(LENGTH ${CMAKE_CURRENT_LIST_DIR} prefix_len_)
math(EXPR prefix_len_no_dir_ "${prefix_len_} + 5")

foreach(exe_ ${cpp_executables_})
    # message(${exe_})
    string(LENGTH ${exe_} path_len_)
    # message(${path_len_})
    math(EXPR file_len_ "${path_len_} - ${prefix_len_no_dir_} - 4")
    # message(${file_len_})
    string(SUBSTRING ${exe_} ${prefix_len_no_dir_} ${file_len_} exe_name_)
    message(STATUS "Config: " ${exe_name_})

    add_executable(
        ${exe_name_}
            ${exe_}
    )

    # automatically add include for library header
    target_compile_options(
        ${exe_name_} PRIVATE -include ${lib_header_name_}
    )

    target_link_libraries(
        ${exe_name_} PRIVATE ${input_lib_name_}
    )

endforeach()
