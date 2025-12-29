#include<stdio.h>
#include<X11/Xlib.h>
#include<GLFW/glfw3.h>
#include"generics.h"

void ProcessInput(GLFWwindow *window)
{
	if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){
		glfwSetWindowShouldClose(window,1);
	}
}

int main(void)
{
	START_MESSAGE


	Display *display;
	Screen *screen;
	int screen_number;
	int width,height;
	display = XOpenDisplay(NULL);
	if(display==NULL)
	{
		printf("Fail to Open Display\n");
		return -1;
	}
	screen_number = DefaultScreen(display);
	screen = DefaultScreenOfDisplay(display);
	width = screen->width;
	height = screen->height;
	printf("You have screen with %dx%d \n",width,height);
	if(!glfwInit())
	{
		printf("GLFW Initial Error\n");
		return -1;
	}
	GLFWwindow* window = glfwCreateWindow(width,height,"x61 OpenGL Demo",NULL,NULL);
	if(!window)
	{
		printf("fail to make Window\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	while(!glfwWindowShouldClose(window))
	{
		ProcessInput(window);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0f,0.0f,0.0);glVertex2f(-0.6f,-0.4f);
			glColor3f(0.0f,1.0f,0.0);glVertex2f(0.6f,-0.4f);
			glColor3f(0.0f,0.0f,1.0);glVertex2f(0.0f,0.6f);
		glEnd();
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}
