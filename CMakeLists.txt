cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

# ----------------------- PROJECT NAME -----------------------
project("StrandFrameworkGame")
# ------------------------------------------------------------

# ---------------------- MSVC POLICY -------------------------
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
endif()

if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

if(POLICY CMP0175)
    cmake_policy(SET CMP0175 NEW)
endif()
# ------------------------------------------------------------

# -------------------- CXX CODING STANDARD -------------------
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# ------------------------------------------------------------

# ------------------- DEV WARNING FLAGS ----------------------
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w")

set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "Enable Update Fetch" FORCE)
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "CMake Warn Deprecated" FORCE)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS OFF CACHE BOOL "CMake Suppresse Developer Warnings" FORCE)
# ------------------------------------------------------------

# ------------------ ENGINE DLL INTEGRATION ------------------
if(NOT DEFINED STRAND_ENGINE_DIR)
    set(STRAND_ENGINE_DIR "$ENV{STRAND_ENGINE_DIR}")
endif()

set(STRAND_INCLUDE  ${STRAND_ENGINE_DIR}/Source)
set(STRAND_DLL      ${STRAND_ENGINE_DIR}/Bin)

set(CMAKE_BUILD_RPATH "${STRAND_DLL}")
set(CMAKE_INSTALL_RPATH "${STRAND_DLL}")

list(APPEND CMAKE_MODULE_PATH "${STRAND_ENGINE_DIR}/CMake")
# ------------------------------------------------------------

include(SetupConfig)
SetupConfig()

add_subdirectory(Scripts)