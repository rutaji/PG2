// C++
// include at the beginning, in any order
#include <iostream>
#include <chrono>
#include <stack>
#include <random>
#include <numeric>

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


#include "callbacks.h"

//---------------------------------------------------------------------

//vertex description
struct vertex {
    glm::vec3 position;
};

std::vector<vertex> vertices =
{
	{{0.0f,  0.5f,  0.0f}},
	{{0.5f, -0.5f,  0.0f}},
	{{-0.5f, -0.5f,  0.0f}}
};

//---------------------------------------------------------------------

class App {
private:
    GLFWwindow * window;
    
    //new stuff
    GLuint shader_prog_ID;
    GLuint VBO_ID;
    GLuint VAO_ID;

}

App::init() {

    //... add at the end, after glfw_init etc.

    //
    // Initialize pipeline: compile, link and use shaders
    //
    
    //compile & link
    const char* vertex_shader =
    "#version 330\n"
    "layout (location = 0) in vec3 aPosition;"
    "void main() {"
    "  gl_Position = vec4(aPosition, 1.0);"
    "}";
 
    const char* fragment_shader =
    "#version 330\n"
    "uniform vec4 uColor;"
    "out vec4 FragColor;"
    "void main() {"
    "  FragColor = uColor;"
    "}";   
    
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);
    
    shader_prog_ID = glCreateProgram();
    glAttachShader(shader_prog_ID, fs);
    glAttachShader(shader_prog_ID, vs);
    glLinkProgram(shader_prog_ID);
    
    //now we can delete shader parts, keep only the final program
    glDeleteShader(vs);
    glDeleteShader(fs);

    // 
    // Create and load data into GPU
    //
    
    // create VAO = data description (envelope, container...)
    glGenVertexArrays(1, &VAO_ID);
    glBindVertexArray(VAO_ID);

    // create vertex buffer and fill with data
    glGenBuffers(1, &VBO_ID);
    glBindBuffer(GL_ARRAY_BUFFER, VBO_ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertex), vertices.data(), GL_STATIC_DRAW);

    //explain GPU the memory layout of the data...
    GLint attrib_location = glGetAttribLocation(shader_prog_ID, "aPosition");
    glVertexAttribPointer(attrib_location, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), reinterpret_cast<void*>(0 + offsetof(vertex, position)));
    glEnableVertexAttribArray(attrib_location);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

App::run() {

    GLfloat r,g,b,a;
    r=g=b=a=1.0f;
    
    while (!glfwWindowShouldClose(window)) {
        // clear canvas
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        //activate shader related to 3D object
        glUseProgram(shader_prog_ID);

        //set uniform parameter for shader
        // (try to change the color in key callback)          
        glUniform4f(glGetUniformLocation(shader_prog_ID, "uColor"), r,g,b,a );
        
        //bind 3d object data
        glBindVertexArray(VAO_ID);

        // draw all VAO data
        glDrawArrays(GL_TRIANGLES, 0, vertices.size());

        // poll events, call callbacks, flip back<->front buffer
        glfwPollEvents();
        glfwSwapBuffers(window);    
    }

}


App::~App() {

    //new stuff: cleanup GL data
    glDeleteProgram(shader_prog_ID);
    glDeleteBuffers(1, &VBO_ID);
    glDeleteVertexArrays(1, &VAO_ID);
    
}

