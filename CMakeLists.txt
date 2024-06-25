cmake_minimum_required(VERSION 3.5)
project(tic-tac-toe)

# Set C++ standard (change if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define sources
set(SOURCES
    gameui.cpp
    gamelogic.cpp
    main.cpp
)

# Define headers
set(HEADERS
    gameui.h
    gamelogic.h
)

# Add executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Enable compiler warnings
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()