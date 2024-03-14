#include <iostream>
#include <iostream>
#include <chrono>
#include <stack>
#include <random>

//#include <opencv2/opencv.hpp>


// OpenGL Extension Wrangler: allow all multiplatform GL functions
#include <GL/glew.h> 
// WGLEW = Windows GL Extension Wrangler (change for different platform) 
// platform specific functions (in this case Windows)
#include <GL/wglew.h> 

// GLFW toolkit
// Uses GL calls to open GL context, i.e. GLEW must be first.
#include <GLFW/glfw3.h>

// OpenGL math
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>



void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    auto const src_str = [source]() {
        switch (source)
        {
            case GL_DEBUG_SOURCE_API: return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM: return "WINDOW SYSTEM";
            case GL_DEBUG_SOURCE_SHADER_COMPILER: return "SHADER COMPILER";
            case GL_DEBUG_SOURCE_THIRD_PARTY: return "THIRD PARTY";
            case GL_DEBUG_SOURCE_APPLICATION: return "APPLICATION";
            case GL_DEBUG_SOURCE_OTHER: return "OTHER";
            default: return "Unknown";
        }
    }();

    auto const type_str = [type]() {
         switch (type)
         {
            case GL_DEBUG_TYPE_ERROR: return "ERROR";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED_BEHAVIOR";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED_BEHAVIOR";
            case GL_DEBUG_TYPE_PORTABILITY: return "PORTABILITY";
            case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
            case GL_DEBUG_TYPE_MARKER: return "MARKER";
            case GL_DEBUG_TYPE_OTHER: return "OTHER";
            default: return "Unknown";
         }
    }();

   auto const severity_str = [severity]() {
         switch (severity) 
         {
            case GL_DEBUG_SEVERITY_NOTIFICATION: return "NOTIFICATION";
            case GL_DEBUG_SEVERITY_LOW: return "LOW";
            case GL_DEBUG_SEVERITY_MEDIUM: return "MEDIUM";
            case GL_DEBUG_SEVERITY_HIGH: return "HIGH";
            default: return "Unknown";
         }
   }();
   std::cout << "[GL CALLBACK]: " <<
                "source = " << src_str <<
                ", type = " << type_str <<
                ", severity = " << severity_str <<
                ", ID = '" << id << '\'' <<
                ", message = '" << message << '\'' << std::endl;
}
static int vsync = 0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        std::cout << "V SYNC";
        if (vsync == 0)
        {
            glfwSwapInterval(1);
            vsync = 1;
        }
        else {
            glfwSwapInterval(0);
            vsync = 0;
        }
    }
}
void fbsize_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "fbsize_callback";
}
void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    std::cout << "mouse_callback";
}
void cursor_callback(GLFWwindow* window, double xpos, double ypos)
{

}
void scrool_callback(GLFWwindow* window, double xoffset, double yoffset) {

}