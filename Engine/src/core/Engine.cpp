#include "Engine.h"

int Engine::initialise()
/* ===================
 *
 * For now, just to test that OpenGL works
 */
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* To print openGL version
    * std::cout << glGetString(GL_VERSION) << std::endl;
    */
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Modern OpenGL attempt at drawing a triangle */
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        /* Legacy OpenGL for a triangle */
        glBegin(GL_TRIANGLES);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 0.0f,  1.0f);
        glVertex2f( 1.0f, -1.0f);
        glEnd();
    
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
