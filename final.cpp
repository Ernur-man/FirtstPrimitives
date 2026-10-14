#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location=0) in vec3 vPosition;\n"
"layout (location=1) in vec3 vColor;\n"
"out vec3 ourColor;\n"
"void main(){\n"
"    gl_Position = vec4(vPosition, 1.0);\n"
"    ourColor = vColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";

int main() {
    if (!glfwInit()) return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(500, 500, "Head", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
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

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    
    float vertices[] = {
        -0.2f, 0.7f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.2f, 0.7f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        -0.6f, 0.6f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.6f,-0.6f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.6f,-0.6f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.6f, 0.6f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.6f,-0.6f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.6f, 0.6f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f,-0.5f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.4f, 0.4f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.4f,-0.4f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.4f,-0.4f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.4f, 0.4f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.4f,-0.4f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.4f, 0.4f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.3f,-0.3f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.3f,-0.3f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.3f,-0.3f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.3f, 0.3f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.2f, 0.2f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.2f,-0.2f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.2f,-0.2f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.2f, 0.2f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.2f,-0.2f, 0.0f, 1.0f, 1.0f, 1.0f,
         0.2f, 0.2f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.1f,-0.1f, 0.0f, 0.0f, 0.0f, 0.0f,
        -0.1f,-0.1f, 0.0f, 0.0f, 0.0f, 0.0f,

        -0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.1f,-0.1f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.1f, 0.1f, 0.0f, 0.0f, 0.0f, 0.0f,
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    
    float cx = -0.6f, cy = 0.8f; 
    float rx = 0.3f, ry = 0.1f; 
    int segments = 40;
    float pi = 3.1415926f;

    
    float Circlex = 0.6f;
    float Circley = 0.8f;
    float CircleRadius = 0.2f;
   

    vector<float> ellipseVertices;
    vector<float> circleVertices;

    ellipseVertices.push_back(cx);   ellipseVertices.push_back(cy);   ellipseVertices.push_back(0.0f);
    ellipseVertices.push_back(1.0f); ellipseVertices.push_back(0.0f); ellipseVertices.push_back(0.0f);

    circleVertices.push_back(Circlex); circleVertices.push_back(Circley); circleVertices.push_back(0.0f);
    circleVertices.push_back(0.3f);   circleVertices.push_back(0.0f);    circleVertices.push_back(0.0f);

    for (int i = 0; i <= segments; ++i) {
        float angle = i * 2.0f * pi / segments;
        ellipseVertices.push_back(cx + rx * cos(angle));
        ellipseVertices.push_back(cy + ry * sin(angle));
        ellipseVertices.push_back(0.0f);

        ellipseVertices.push_back(1.0f); 
        ellipseVertices.push_back(0.0f);
        ellipseVertices.push_back(0.0f);

        circleVertices.push_back(Circlex + CircleRadius * cos(angle));
        circleVertices.push_back(Circley + CircleRadius * sin(angle));
        circleVertices.push_back(0.0f);

        float redValue = (cos(angle) + 1.0f) / 2.0f;
        circleVertices.push_back(redValue);
        circleVertices.push_back(0.0f);
        circleVertices.push_back(0.0f);
    }

    unsigned int ellipseVAO, ellipseVBO;
    glGenVertexArrays(1, &ellipseVAO);
    glGenBuffers(1, &ellipseVBO);

    glBindVertexArray(ellipseVAO);
    glBindBuffer(GL_ARRAY_BUFFER, ellipseVBO);
    glBufferData(GL_ARRAY_BUFFER, ellipseVertices.size() * sizeof(float), ellipseVertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    unsigned int circleVAO, circleVBO;
    glGenVertexArrays(1, &circleVAO);
    glGenBuffers(1, &circleVBO);

    glBindVertexArray(circleVAO);
    glBindBuffer(GL_ARRAY_BUFFER, circleVBO);
    glBufferData(GL_ARRAY_BUFFER, circleVertices.size() * sizeof(float), circleVertices.data(), GL_STATIC_DRAW);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 39);

        
        glBindVertexArray(ellipseVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);

        glBindVertexArray(circleVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &ellipseVAO);
    glDeleteBuffers(1, &ellipseVBO);
    glDeleteVertexArrays(1, &circleVAO);
    glDeleteBuffers(1, &circleVBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}