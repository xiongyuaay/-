# 设置CMake的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject VERSION 1.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置生成的二进制文件目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 设置中间目标文件目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 如果有第三方库，可以指定库路径
# link_directories(${CMAKE_SOURCE_DIR}/lib)

# 定义源文件
set(SOURCE_FILES
    src/main.cpp
    src/BFS.cpp
    src/Node.cpp
    src/Astar.cpp
)

set(HEADERS
    include/BFS.h
    include/Node.h
    include/Astar.h
)

# 定义可执行文件
add_executable(MyProject ${SOURCE_FILES} ${HEADERS})



