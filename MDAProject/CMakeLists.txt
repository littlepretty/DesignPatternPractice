cmake_minimum_required (VERSION 2.6)
project (MDABankAccount)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# the version number
set (MDABankAccount_VERSION_MAJOR 1)
set (MDABankAccount_VERSION_MINOR 0)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/MDABankAccountConfig.h.in"
        "${PROJECT_BINARY_DIR}/MDABankAccountConfig.h"
        )
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")
 

add_executable(main ${SOURCES})


