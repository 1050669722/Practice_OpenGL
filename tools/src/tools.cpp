//
// Created by liu on 2024/6/3.
//

#include "tools.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    // 处理过的OpenGL坐标范围只为-1到1，glViewport将OpenGL中的坐标映射为了屏幕坐标
    glViewport(0, 0, width, height); //指定了视口的左下角（在第一象限内，以（0，0）为原点的）位置；width 和 height 表示这个视口矩形的宽度和高度，会根据窗口的实时变化重绘窗口。
}

