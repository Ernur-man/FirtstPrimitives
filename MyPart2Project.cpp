#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location=0) in vec3 aPos;\n"
"layout (location=1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main(){\n"
"    gl_Position = vec4(aPos, 1.0);\n"
"    ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";

int main() {
	if (!glfwInit()) {
		cout << "Error!";
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1000, 1000, "Head", NULL, NULL);
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	float vertices[] = {
	
	0.6f, -0.6, 0.0f,   0.0f, 0.0f, 1.0f,
	0.6f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,
	1.0f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,

	-0.6f, -0.6, 0.0f,   0.0f, 0.0f, 1.0f,
	 0.6f, -0.6, 0.0f,   0.0f, 0.0f, 1.0f,
	0.6f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,


	-0.6f, -0.6, 0.0f,   0.0f, 0.0f, 1.0f,
	 0.6f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,
	-0.6f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,

	-1.0f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,
	-0.6f, -1.0, 0.0f,   0.0f, 0.0f, 1.0f,
	-0.6f, -0.6, 0.0f,   0.0f, 0.0f, 1.0f,

	 -0.6f, 0.6f, 0.0f,   0.0f, 1.0f, 0.0f,
	 0.6f, 0.6f, 0.0f,	  0.0f, 1.0f, 0.0f,
	 0.0f, 0.9f, 0.0f,  0.0f, 1.0f, 0.0f,

	 -0.6f, 0.6f, 0.0f,   1.0f, 0.0f, 0.0f,
	 0.6f, -0.6f, 0.0f,	  1.0f, 0.0f, 0.0f,
	 -0.6f, -0.6f, 0.0f,  1.0f, 0.0f, 0.0f,

	 -0.6f, 0.6f, 0.0f,   1.0f, 0.0f, 0.0f,
	 0.6f, -0.6f, 0.0f,   1.0f, 0.0f, 0.0f,
	 0.6f,  0.6f, 0.0f,   1.0f, 0.0f, 0.0f,

	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * (sizeof(float)), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window)) {
		glClearColor(1.0f, 1.0f, 0.0f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 21);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glfwTerminate();
}