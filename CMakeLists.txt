cmake_minimum_required(VERSION 3.15)
project(zlang)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(parser)
file(GLOB AST_SOURCES ast/*.cpp)
file(GLOB AST_HEADERS ast/*.hpp)

#set(CMAKE_DEBUG_TARGET_PROPERTIES
#        INCLUDE_DIRECTORIES
#        COMPILE_DEFINITIONS
#        POSITION_INDEPENDENT_CODE
#        CONTAINER_SIZE_REQUIRED
#        LIB_VERSION
#        )

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_executable(zlang
        ${AST_SOURCES} ${AST_HEADERS}
        ${PARSER_SOURCES}
        zlang/main.cpp)
add_dependencies(zlang zlang_parser)
target_include_directories(zlang PRIVATE
        /usr/local/include
        /usr/local/opt/llvm/include
        ${CMAKE_CURRENT_BINARY_DIR}
        )
target_link_libraries(zlang zlang_parser)

