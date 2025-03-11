project(DummyInputLib)

# parent scope variables describing the compiled libraries
set(input_lib_name_ ${PROJECT_NAME} PARENT_SCOPE)
set(lib_header_name_ dummy_in.h PARENT_SCOPE)

# c/cpp compile flag switch
set(c_cpp_flag_ CODERBYTE_CHALLENGES_SRC_CPP_FLAG)

# c free flag - freeing allocating memory flag in .c files
# (using custom input function):
# 
# #ifdef CMAKE_CODERBYTE_SOLUTIONS_BUILD
#   free(str)
# #endif // CMAKE_CODERBYTE_SOLUTIONS_BUILD
# 

# HOW DOES FREE KNOWS HOW MUCH TO FREE? (by Gary McGill, edited by inspector-g, 
# at https://stackoverflow.com/a/1518718):

# When you call malloc(), you specify the amount of memory to allocate. The amount of memory actually used
# is slightly more than this, and includes extra information that records (at least) how big the block
# is. You can't (reliably) access that other information - and nor should you :-).
# 
# When you call free(), it simply looks at the extra information to find out how big the block is.

set(c_free_flag_ CMAKE_CODERBYTE_SOLUTIONS_BUILD)

# cpp lib
add_library(${PROJECT_NAME}Cpp)
target_sources(
    ${PROJECT_NAME}Cpp
        PUBLIC ./include/dummy_in.h
        PRIVATE ./src/dummy_in.cpp
)
target_include_directories(
    ${PROJECT_NAME}Cpp
        PUBLIC ./include/
)
target_compile_definitions(
    ${PROJECT_NAME}Cpp
        PUBLIC ${c_cpp_flag_}
)

# c lib
add_library(${PROJECT_NAME}C)
target_sources(
    ${PROJECT_NAME}C
        PUBLIC ./include/dummy_in.h
        PRIVATE ./src/dummy_in.c
)
target_include_directories(
    ${PROJECT_NAME}C
        PUBLIC ./include/
)
target_compile_definitions(
    ${PROJECT_NAME}C
        PUBLIC ${c_free_flag_}
)