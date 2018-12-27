#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>

#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "gtc/matrix_transform.hpp"
#include "tests/TestClearColor.h"

#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Texture.h"


int main() {

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(960, 540, "OpenGL Tutorial", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Glew loading error!" << std::endl;
    }


    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    Renderer renderer;

    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();


    test::TestClearColor test;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {

        renderer.Clear();

        test.OnUpdate(0.0f);
        test.OnRender();

        ImGui_ImplGlfwGL3_NewFrame();

        test.OnImGuiRender();
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());


        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}