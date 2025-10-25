cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

include(GenerateExportHeader)
include(ExecuteReflection)

ExecuteReflection("Scripts" "Intermediate")

file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SUBDIRECTORIES})

file(GLOB_RECURSE INTERMEDIATE "${CMAKE_SOURCE_DIR}/Intermediate/Scripts/*.cpp")
source_group(TREE "${CMAKE_SOURCE_DIR}/Intermediate/Scripts" FILES ${INTERMEDIATE})

add_library(TestGame SHARED ${INTERMEDIATE} ${SUBDIRECTORIES})

# -------------- EXPORT HEADER GENERATION --------------------
generate_export_header(TestGame 
    BASE_NAME GAME_RUNTIME
    EXPORT_FILE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/GameLibraryAPI.h"
    EXPORT_MACRO_NAME GAME_API
)
target_include_directories(TestGame PUBLIC "${STRAND_INCLUDE}" "${CMAKE_SOURCE_DIR}")

set_target_properties(TestGame PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Bin")
# ------------------------------------------------------------

target_include_directories(TestGame PRIVATE "${CMAKE_SOURCE_DIR}/Scripts")
target_link_libraries(TestGame PUBLIC ${STRAND_DLL}/libRuntime.so ${STRAND_DLL}/libEngine.so)