void App::error_callback(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}


void App::scroll_callback(double xoffset, double yoffset) {
    if (xoffset > 0.0) {
        std::cout << "tocis nahoru...\n";
    }
}

void App::key_callback(int key, int scancode, int action, int mods) {
	if ((action == GLFW_PRESS) || (action == GLFW_REPEAT))
	{
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;
		case GLFW_KEY_V:
            break;	
		default:
			break;
		}
	}
}

