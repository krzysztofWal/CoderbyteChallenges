project(DummyInputLib)

set(input_lib_name_ ${PROJECT_NAME} PARENT_SCOPE)
set(lib_header_name_ dummy_in.h PARENT_SCOPE)

add_library(${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME}
        PUBLIC ./include/dummy_in.h
        PRIVATE ./src/dummy_in.cpp
)
target_include_directories(
    ${PROJECT_NAME} 
        PUBLIC ./include/
)