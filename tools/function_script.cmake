# 'exports' exes_ list
# takes in list of nonrelative file paths
# suffix_len with dot
function(prepare_exe_list suffix_len_ subdir_name_len_)
    # get pwd path length
    string(LENGTH ${CMAKE_CURRENT_LIST_DIR} prefix_len_)
    math(EXPR prefix_len_no_dir_ "${prefix_len_} + ${subdir_name_len_} + 2")
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
