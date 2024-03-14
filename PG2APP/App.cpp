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


//user headers
#include "App.h"
#include "Callbacks.h"

App::App()
{
    // default constructor
    // nothing to do here (so far...)
    std::cout << "Constructed...\n";
}


bool App::init()
{
    try {
        if (GLEW_ARB_debug_output)
        {
            glDebugMessageCallback(MessageCallback, 0);
            glEnable(GL_DEBUG_OUTPUT);

            //default is asynchronous debug output, use this to simulate glGetError() functionality
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);

            std::cout << "GL_DEBUG enabled." << std::endl;
        }
        // init glfw
        // https://www.glfw.org/documentation.html
        glfwInit();

        // open window (GL canvas) with no special properties
        // https://www.glfw.org/docs/latest/quick.html#quick_create_window
        window = glfwCreateWindow(800, 600, "OpenGL context", NULL, NULL);
        glfwMakeContextCurrent(window);
        //set callbacks
        glfwSetKeyCallback(window, key_callback);
        glfwSetFramebufferSizeCallback(window, fbsize_callback);
        glfwSetMouseButtonCallback(window, mouse_callback);
        glfwSetCursorPosCallback(window, cursor_callback);
        glfwSetScrollCallback(window, scrool_callback);


        // init glew
        // http://glew.sourceforge.net/basic.html
        glewInit();
        wglewInit();

        printf("version %s \n", glGetString(GL_VERSION));
        printf("vendor %s \n", glGetString(GL_VENDOR));
        printf("renderer %s \n", glGetString(GL_RENDERER));
        printf("shading language %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));
        int mask;
        int profile_bit;
        glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &mask);
        glGetIntegerv(GL_CONTEXT_CORE_PROFILE_BIT, &profile_bit);
        printf("profile mask %i \n", mask);
        printf("profile bit %i \n", profile_bit);


    }
    catch (std::exception const& e) {
        std::cerr << "Init failed : " << e.what() << std::endl;
        throw;
    }
    std::cout << "Initialized...\n";
    return true;
}

clock_t deltaTime = 0;
unsigned int frames = 0;

int App::run(void)
{
    try {
        while (!glfwWindowShouldClose(window))
        {
            clock_t start = clock();
            // ... do_something();
            // 
            // if (condition)
            //   glfwSetWindowShouldClose(window, GLFW_TRUE);
            // 

            // Clear OpenGL canvas, both color buffer and Z-buffer
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            // Swap front and back buffers
            glfwSwapBuffers(window);

            // Poll for and process events
            glfwPollEvents();

            clock_t end = clock();
            deltaTime += end - start;
            frames++;
            if (deltaTime > CLOCKS_PER_SEC)
            {
                deltaTime = deltaTime % CLOCKS_PER_SEC;
                int fps = frames;
                frames = 0;
                printf("FPS: %i \n",fps);
            }
        }
    }
    catch (std::exception const& e) {
        std::cerr << "App failed : " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Finished OK...\n";
    return EXIT_SUCCESS;
}


App::~App()
{
    if (window)
        glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "Bye...\n";
    exit(EXIT_SUCCESS);   
}

