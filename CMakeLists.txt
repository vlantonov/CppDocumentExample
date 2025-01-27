cmake_minimum_required(VERSION 3.20)

project(CppProjectSample LANGUAGES CXX)

find_package(Doxygen REQUIRED dot)

set(DOXYGEN_PROJECT_NAME          "C++ Document Example")
set(DOXYGEN_PROJECT_BRIEF         "Simple example about how to create C++ project documentation with Doxygen")
set(DOXYGEN_OUTPUT_DIRECTORY      ${PROJECT_BINARY_DIR}/cmake_generated)
set(DOXYGEN_DISTRIBUTE_GROUP_DOC  YES)
set(DOXYGEN_EXTRACT_PRIVATE       YES)
set(DOXYGEN_EXTRACT_PRIV_VIRTUAL  YES)
set(DOXYGEN_EXTRACT_STATIC        YES)
set(DOXYGEN_GENERATE_HTML         YES)
set(DOXYGEN_GENERATE_LATEX        NO)
set(DOXYGEN_RECURSIVE             YES)
set(DOXYGEN_GENERATE_LATEX        NO)

doxygen_add_docs(docs_target
  ${PROJECT_SOURCE_DIR}
  COMMENT "Generate documentation"
)

add_executable(
    ${PROJECT_NAME}
    include/element.hpp
    include/command.hpp
    include/invoker.hpp
    include/receiver.hpp
    include/single_receiver.hpp
    include/container_receiver.hpp
    include/create_command.hpp
    include/read_command.hpp
    include/update_command.hpp
    include/delete_command.hpp
    src/element.cpp
    src/invoker.cpp
    src/single_receiver.cpp
    src/container_receiver.cpp
    src/create_command.cpp
    src/read_command.cpp
    src/update_command.cpp
    src/delete_command.cpp
    main.cpp
)

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        include
)

