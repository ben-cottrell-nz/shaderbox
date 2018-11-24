#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <shader.hpp>

GLuint g_texID;
const char g_window_title[] = "shaderbox";

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void run_application(const char *vspath, const char *fspath)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    window = glfwCreateWindow(640, 480, "Shader Test", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwSetKeyCallback(window, key_callback);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);
    Shader shader(vspath,fspath);
    shader.use();
    int windowWidth, windowHeight;
    const GLenum buffers[] = {GL_COLOR_ATTACHMENT4, GL_COLOR_ATTACHMENT2, GL_NONE, GL_COLOR_ATTACHMENT0};
    glDrawBuffers(4, buffers);
    glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
    while (!glfwWindowShouldClose(window)) {
        glfwGetFramebufferSize(window, &windowWidth, &windowHeight);
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0,0,windowWidth,windowHeight);
        glBegin (GL_QUADS);
        glVertex2f(-1, -1);
        glVertex2f(1, -1);
        glVertex2f(1, 1);
        glVertex2f(-1, 1);
        glUseProgram(0);
        glColor3f(0, 0, 0);
        glEnd();
        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: shaderbox [vspath] [fspath]\n");
        return 1;
    }
    run_application(argv[1], argv[2]);
    return 0;
}
