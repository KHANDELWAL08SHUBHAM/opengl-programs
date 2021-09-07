// Code to draw a Rectangle


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800

int main(void)
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Rectangle Drawn by Shubham Khandelwal", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    int scwth = SCREEN_WIDTH;
    int schei = SCREEN_HEIGHT;

    float vertices[] =
    {
        scwth / 2 + 300, schei / 2 + 200, 0.0, // top right corner
        scwth / 2 - 300, schei / 2 + 200, 0.0, // top left corner
        scwth / 2 - 300, schei / 2 - 200, 0.0, // bottom left corner
        scwth / 2 + 300, schei / 2 - 200, 0.0 // bottom right corner
    };

    GLfloat colour[] =
    {
        240, 0, 0,
        240, 0, 0,
        240, 0, 0,
        240, 0, 0
    };

    // specifies the part of the window to which OpenGL will 
    //draw (in pixels), convert from normalised to pixels
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); 

    // projection matrix defines the properties of the camera that views 
    //the objects in the world coordinate frame. Here you typically set the
    //zoom factor, aspect ratio and the near and far clipping planes
    glMatrixMode(GL_PROJECTION); 

    // replace the current matrix with the identity matrix and starts 
    //us a fresh because matrix transforms such as glOrpho and glRotate 
    //cumulate, basically puts us at (0, 0, 0)
    glLoadIdentity(); 

    // essentially set coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1); 

    // (default matrix mode) modelview matrix defines how your objects 
    //are transformed(meaning translation, rotation and scaling) in your world
    glMatrixMode(GL_MODELVIEW); 

    glLoadIdentity(); // same as above comment
    

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here

        // tell OpenGL that you're using a vertex array for fixed-function attribute
        glEnableClientState(GL_VERTEX_ARRAY); 
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices); // point to the vertices to be used
        glColorPointer(3, GL_FLOAT, 0, colour);
        glDrawArrays(GL_QUADS, 0, 4); // draw the vertixes
        glDisableClientState(GL_COLOR_ARRAY);

        // tell OpenGL that you're finished using the vertex arrayattribute
        glDisableClientState(GL_VERTEX_ARRAY); 


        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
