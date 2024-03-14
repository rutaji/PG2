#pragma once
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


void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void fbsize_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_callback(GLFWwindow* window, double xpos, double ypos);
void scrool_callback(GLFWwindow* window, double xoffset, double yoffset);
