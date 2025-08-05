#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main()
{
	// Initialize the GLFW library
	glfwInit();

	//A hint to tell opengl which version we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Tell OPENGL we are using the CORE profile -> modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a windowed mode window of 800 by 800 pixels and name it "OpenGl Lesson 1"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGl Lesson 1", NULL, NULL);

	//Error handling in case the window fails to open/create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window to the current context so that we can use OpenGL functions on it
	glfwMakeContextCurrent(window);

	// Load GLAD so it configures OpenGL function pointers
	gladLoadGL();

	// Specify the viewport of OpenGL in the window - in this case the view port goes from x=0, y-0, to x=800, y=800
	glViewport(0, 0, 800, 800);

	// Tell OpenGL to clear the color buffer and give it another color 
	// Alpha value is for transparency = 1.0f means no transparency and 0.0f means fully transparent
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f); // Color of the background
	// Clear the color buffer to apply the color we just set
	glClear(GL_COLOR_BUFFER_BIT);
	// Swap the front and back buffers to display the cleared color
	glfwSwapBuffers(window);

	// This while loops keeps the window open until the user closes it (MAIN while loop)
	while (!glfwWindowShouldClose(window))
	{
		// Take care of all GLFW events (like keyboard input, mouse movement, etc.)
		glfwPollEvents();
	}


	// This closes the window 
	glfwDestroyWindow(window);
	// Terminate GLFW to free resources and close the application
	glfwTerminate();
	return 0;
}
