cmake_minimum_required(VERSION 3.17)

project(CoderbyteChallenges)

# 'exports' exes_ list
# takes in list of nonrelative file paths
# suffix_len with dot
function(prepare_exe_list suffix_len_)
    # get pwd path length
    string(LENGTH ${CMAKE_CURRENT_LIST_DIR} prefix_len_)
    math(EXPR prefix_len_no_dir_ "${prefix_len_} + 5")
    # initialize empty lists
    set(exes_tmp_ "")
    # for each passed arguments into the function
    foreach(exe_ ${ARGN})
        # message(${exe_})
        string(LENGTH ${exe_} path_len_)
        # message(${path_len_})
        math(EXPR file_len_ "${path_len_} - ${prefix_len_no_dir_} - ${suffix_len_}")
        # message(${file_len_})
        string(SUBSTRING ${exe_} ${prefix_len_no_dir_} ${file_len_} exe_name_)
        # message(STATUS "Config: " ${exe_name_})
        list(APPEND exes_tmp_ ${exe_name_})
    endforeach()
    set(exes_ ${exes_tmp_} PARENT_SCOPE)
endfunction()

# checks if the lists of given names have the same number of elements
# throws error if not
function(check_length name_one name_two)
    list(LENGTH ${name_one} len_1_)
    list(LENGTH ${name_two} len_2_)
    if(NOT ${len_1_} EQUAL ${len_2_})
        message(FATAL_ERROR
            "    check_length(): error ${len_1_} is not equal to ${len_2_}")
    endif()
    message(DEBUG "    check_length(): len(${name_one}) = ${len_1_}")
    message(DEBUG "                  : len(${name_two}) = ${len_2_}")
endfunction()

# DummyInputLib
add_subdirectory(tools/DummyInputLib)

# ============= Cpp files globing ==========================
FILE(GLOB_RECURSE cpp_exe_paths_ "src/*.cpp")

prepare_exe_list(4 ${cpp_exe_paths_})
set(cpp_exes_ ${exes_})
set(exes_ "") # clear variable just in case
check_length(cpp_exe_paths_ cpp_exes_)

# message(DEBUG "    cpp_exes_: ${cpp_exes_}")
# message(DEBUG "    cpp_exe_paths_: ${cpp_exe_paths_}")

# ============== C files globing ===========================
FILE(GLOB_RECURSE c_exe_paths_ "src/*.c")

prepare_exe_list(2 ${c_exe_paths_})
set(c_exes_ ${exes_})
set(exes_ "") # clear variable just in case
check_length(c_exe_paths_ c_exes_)

# message(DEBUG "    c_exes_: ${c_exes_}")
# message(DEBUG "    c_exe_paths_: ${c_exe_paths_}")

# ====== add executables and set linking properties =======

# concatenate lists with executable names and source files' paths
# (append to empty lists)
list(APPEND concat_exe_paths_ ${cpp_exe_paths_} ${c_exe_paths_})
list(APPEND concat_exes_ ${cpp_exes_} ${c_exes_})
check_length(concat_exes_ concat_exe_paths_)
list(LENGTH concat_exes_ iter_max_)

message(DEBUG "    number of targets in src dir: ${iter_max_}")

# iterate over all targets (c and cpp)
set(iter_ 0)
while(iter_ LESS iter_max_)
    # get exe name and source file path
    list(GET concat_exes_ ${iter_} exe_name_)
    list(GET concat_exe_paths_ ${iter_} src_path_)

    # ==================== executables =========================
    add_executable(${exe_name_} ${src_path_})
    message(STATUS "    ${exe_name_}: ${src_path_}")
    # ==================== executables =========================

    if(${src_path_} MATCHES "^.*\.(c)$")
    # ======================.c linking =========================
        target_link_libraries( ${exe_name_} PRIVATE ${input_lib_name_}C)
    # ============= .c files compiler options ==================
        target_compile_options( ${exe_name_} PRIVATE -include ${lib_header_name_})
        message(STATUS "        Including: ${lib_header_name_}")
    # ==========================================================
    else()
    # =====================.cpp linking ========================
        target_link_libraries( ${exe_name_} PRIVATE ${input_lib_name_}Cpp)
    # ============ .cpp files compiler options =================
        target_compile_options( ${exe_name_} PRIVATE -include ${lib_header_name_})
        message(STATUS "        Including: ${lib_header_name_}")
    # ==========================================================
    endif()
    
    math(EXPR iter_ ${iter_}+1)
endwhile()

# foreach(exe_ ${cpp_exe_paths_})

#     add_executable(${exe_name_} {exe_})

#     # automatically add include for library header
#     target_compile_options( ${exe_name_} PRIVATE -include ${lib_header_name_})

#     target_link_libraries( ${exe_name_} PRIVATE ${input_lib_name_})
# endforeach()
