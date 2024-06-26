cmake_minimum_required(VERSION 3.5)
project(tic-tac-toe)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define sources
set(SOURCES
    src/gameui.cpp
    src/gamelogic.cpp
    src/main.cpp
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Enable compiler warnings
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()