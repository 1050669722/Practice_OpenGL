#设置cmake版本
cmake_minimum_required(VERSION 3.15)

#项目名字
project(Practice_OpenGL)

#设置编译版本
set(CMAKE_CXX_STANDARD 14)

#设置头文件路径
set(GLFW_INC_DIR ./_deps/glfw/include) #相对于CMakeLists.txt文件而言的
set(GLAD_INC_DIR glad/include)
set(EXAMPLES_INC_DIR ./examples)
set(TOOLS_INC_DIR ./tools)

#设置链接库路径
set(GLFW_LINK_DIR ../_deps/glfw/lib) #相对于可执行文件而言的

#引入头文件
include_directories(${GLFW_INC_DIR})
include_directories(${GLAD_INC_DIR})
include_directories(${EXAMPLES_INC_DIR})
include_directories(${TOOLS_INC_DIR})

#引入库文件
link_directories(${GLFW_LINK_DIR})

#编译文件
add_executable(
        ${PROJECT_NAME}
        glad/src/glad.c
        tools/tools.cpp
        examples/example_0.cpp
        examples/example_1.cpp
        main.cpp
)

#将第三方库连接在一起
target_link_libraries(
        ${PROJECT_NAME}
        ${GLFW_LINK_DIR}/glfw3
)
#set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"MSVCRT.lib")
#set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"libcmt.lib;libcmtd.lib;msvcrtd.lib")
#/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib