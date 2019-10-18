cmake_minimum_required(VERSION 3.15)
project(parser_proj)

set(CMAKE_CXX_STANDARD 14)

find_program(REFLEX_BIN NAMES reflex)
message("RE/Flex found at: ${REFLEX_BIN}")
set(REFLEX_FLAGS)

find_program(BISON_BIN NAMES bison)
message("GNU Bison found at: ${BISON_BIN}")
set(BISON_FLAGS )

find_library(REFLEX_LIB NAMES reflex)
message("RE/Flex library found at: ${REFLEX_LIB}")

set(NAMESPACE Zlang)
set(PARSER_CLASS ZlangParser)
set(PARSER_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${PARSER_CLASS}.yy.cpp)
set(PARSER_HEADER ${CMAKE_CURRENT_BINARY_DIR}/${PARSER_CLASS}.yy.hpp)
set(PARSER_LOCATIONS ${CMAKE_CURRENT_BINARY_DIR}/location.yy.hpp)
set(PARSER_SOURCE zlang.y)

set(LEXER_CLASS ZlangScanner)
set(LEXER_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${LEXER_CLASS}.yy.cpp)
set(LEXER_HEADER ${CMAKE_CURRENT_BINARY_DIR}/${LEXER_CLASS}.yy.hpp)
set(LEXER_SOURCE zlang.l)

add_custom_command(
        OUTPUT ${PARSER_OUTPUT} ${PARSER_HEADER} ${PARSER_LOCATIONS}
        DEPENDS ${PARSER_SOURCE}
        COMMAND ${BISON_BIN}
        ${BISON_FLAGS}
        --defines=${PARSER_HEADER}
        --output=${PARSER_OUTPUT}
        --locations
        -Dapi.location.file='"${PARSER_LOCATIONS}"'
        -Dapi.namespace={${NAMESPACE}}
        -Dapi.parser.class={${PARSER_CLASS}}
        ${PARSER_SOURCE}
        COMMENT "Generating ${PARSER_CLASS}..."
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

add_custom_command(
        OUTPUT ${LEXER_OUTPUT} ${LEXER_HEADER}
        DEPENDS ${LEXER_SOURCE}
        COMMAND ${REFLEX_BIN}
        ARGS ${REFLEX_FLAGS}
        --bison-complete
        --bison-cc-namespace=${NAMESPACE}
        --bison-cc-parser=${PARSER_CLASS}
        --bison-locations
        --namespace=${NAMESPACE}
        --lexer=${LEXER_CLASS}
        --outfile=${LEXER_OUTPUT}
        --header-file=${LEXER_HEADER}
        ${LEXER_SOURCE}
        COMMENT "Generating ${LEXER_CLASS}..."
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
)

#set(CMAKE_DEBUG_TARGET_PROPERTIES
#        INCLUDE_DIRECTORIES
#        COMPILE_DEFINITIONS
#        POSITION_INDEPENDENT_CODE
#        CONTAINER_SIZE_REQUIRED
#        LIB_VERSION
#        )

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Build target
add_library(zlang_parser OBJECT ${PARSER_OUTPUT} ${PARSER_HEADER} ${PARSER_LOCATIONS} ${LEXER_OUTPUT} ${LEXER_HEADER})
target_include_directories(zlang_parser PRIVATE /usr/local/include ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(zlang_parser ${REFLEX_LIB})
