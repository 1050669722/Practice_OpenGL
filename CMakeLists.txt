# 设置cmake版本
cmake_minimum_required(VERSION 3.15)

# 项目名字
project(Practice_OpenGL)

# 设置编译版本
set(CMAKE_CXX_STANDARD 14)

# ---设置头文件路径---------------------------------
set(GLFW_INC_DIR ./_deps/glfw/include) #相对于CMakeLists.txt文件而言的
set(GLAD_INC_DIR glad/include)
set(TOOLS_INC_DIR ./tools/include)
set(EXAMPLES_INC_DIR ./examples/include)
set(SHADERS_INC_DIR ./shaders/include)
# ------------------------------------------------

# ---设置源文件路径---------------------------------
# 设置源文件路径
set(GLAD_SRC_DIR glad/src)
set(TOOLS_SRC_DIR ./tools/src)
set(EXAMPLES_SRC_DIR ./examples/src)
set(SHADERS_SRC_DIR ./shaders/src)
# ------------------------------------------------

# ---设置链接库路径---------------------------------
set(GLFW_LINK_DIR ../_deps/glfw/lib) #相对于可执行文件而言的
# ------------------------------------------------

# ---引入头文件------------------------------------
include_directories(${GLFW_INC_DIR})
include_directories(${GLAD_INC_DIR})
include_directories(${TOOLS_INC_DIR})
include_directories(${EXAMPLES_INC_DIR})
include_directories(${SHADERS_INC_DIR})
# ------------------------------------------------

# ---引入源文件------------------------------------
# glad中的所有源文件
aux_source_directory(${GLAD_SRC_DIR} GLAD_SOURCE)
# tools中的所有源文件
aux_source_directory(${TOOLS_SRC_DIR} TOOLS_SOURCE)
# examples中的所有源文件
aux_source_directory(${EXAMPLES_SRC_DIR} EXAMPLES_SOURCE)
# shaders中的所有源文件
aux_source_directory(${SHADERS_SRC_DIR} SHADERS_SOURCE)
# ------------------------------------------------

# ---引入库文件------------------------------------
link_directories(${GLFW_LINK_DIR})
# ------------------------------------------------

# 编译文件
add_executable(
        ${PROJECT_NAME}
        ${GLAD_SOURCE}
        ${TOOLS_SOURCE}
        ${EXAMPLES_SOURCE}
        ${SHADERS_SOURCE}
        main.cpp
)

# 将第三方库链接到一起
target_link_libraries(
        ${PROJECT_NAME}
        ${GLFW_LINK_DIR}/glfw3
)
#set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"MSVCRT.lib")
#set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"libcmt.lib;libcmtd.lib;msvcrtd.lib")
#/NODEFAULTLIB:libcmt.lib /NODEFAULTLIB:libcmtd.lib /NODEFAULTLIB:msvcrtd.lib