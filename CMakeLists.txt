cmake_minimum_required(VERSION 3.17)

# for vcpkg int ./tools/vcpkg
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/tools/vcpkg/scripts/buildsystems/vcpkg.cmake)

include(./tools/function_script.cmake)

project(CoderbyteChallenges)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#testing
find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
set(test_flag_ "CODERBYTE_CHALLENGES_TEST_CPP_FLAG")

# DummyInputLib
add_subdirectory(tools/DummyInputLib)

# ================== Cpp files globing ==========================
FILE(GLOB_RECURSE cpp_exe_paths_ "src/*.cpp")

prepare_exe_list(4 3 ${cpp_exe_paths_})
set(cpp_exes_ ${exes_})
set(exes_ "") # clear variable just in case
check_length(cpp_exe_paths_ cpp_exes_)

# message(DEBUG "    cpp_exes_: ${cpp_exes_}")
# message(DEBUG "    cpp_exe_paths_: ${cpp_exe_paths_}")

# ================= C files globing =============================
FILE(GLOB_RECURSE c_exe_paths_ "src/*.c")

prepare_exe_list(2 3 ${c_exe_paths_})
set(c_exes_ ${exes_})
set(exes_ "") # clear variable just in case
check_length(c_exe_paths_ c_exes_)

# message(DEBUG "    c_exes_: ${c_exes_}")
# message(DEBUG "    c_exe_paths_: ${c_exe_paths_}")

# test names should be the same as the name of the file in which the
# tested function exists

# ================ Cpp tests globing ============================
FILE(GLOB_RECURSE cpp_test_paths_ "tests/*_tests.cpp")

prepare_exe_list(4 5 ${cpp_test_paths_})
set(cpp_test_exes_ ${exes_})
set(exes_ "") # clear variable just in case
check_length(cpp_test_paths_ cpp_test_exes_)

message(DEBUG "    cpp_test_exes_: ${cpp_test_exes_}")
message(DEBUG "    cpp_test_paths_: ${cpp_test_paths_}")

# == add executables and set linking properties for c and cpp  ===

# concatenate lists with executable names and source files' paths
# (append to empty lists)
list(APPEND concat_exe_paths_ ${cpp_exe_paths_} ${c_exe_paths_})
list(APPEND concat_exes_ ${cpp_exes_} ${c_exes_})
check_length(concat_exes_ concat_exe_paths_)

message(DEBUG "    number of targets in src dir: ${iter_max_}")

# iterate over c and cpp targets
set(iter_ 0)
list(LENGTH concat_exes_ iter_max_)
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
        target_link_libraries( ${exe_name_} PRIVATE ${input_lib_name_}C )
    # ============= .c files compiler options ==================
        target_compile_options( ${exe_name_} PRIVATE -include ${lib_header_name_})
        # message(STATUS "        Including: ${lib_header_name_}")
    # ==========================================================
    else()
    # =====================.cpp linking ========================
        target_link_libraries( ${exe_name_} PRIVATE ${input_lib_name_}Cpp )
    # ============ .cpp files compiler options =================
        target_compile_options( ${exe_name_} PRIVATE -include ${lib_header_name_})
        # message(STATUS "        Including: ${lib_header_name_}")
    # ==========================================================
    endif()
    
    math(EXPR iter_ ${iter_}+1)
endwhile()

# === add executables and set linking properties for tests  ====
set(iter_ 0)
list(LENGTH cpp_test_paths_ tests_num_)

if (tests_num_ GREATER 0)
    message(STATUS "TESTS:")
endif()

while(iter_ LESS tests_num_)
    list(GET cpp_test_paths_ ${iter_} path_)
    list(GET cpp_test_exes_ ${iter_} exe_)

    # under the assumption that thel ${exe} is program_name_tests.cpp
    # find program_name executable
    string(LENGTH ${exe_} len_)
    math(EXPR len_ ${len_}-6 ) 
    string(SUBSTRING ${exe_} 0 ${len_} program_name_)
    
    # test executable, linking and compiler options
    add_executable(
        ${exe_} 
        ${CMAKE_CURRENT_LIST_DIR}/src/${program_name_}.cpp 
        ${path_}
    )
    message(STATUS "    ${exe_}: ${path_}")

    target_link_libraries(
        ${exe_} 
            PRIVATE GTest::gtest_main
    )

    target_compile_definitions(
        ${exe_}
            PRIVATE ${test_flag_}
    )

    gtest_discover_tests(${exe_})

    math(EXPR iter_ ${iter_}+1)
endwhile()

enable_testing()
