#pragma once

#include <glad/glad.h>
#include <assert.h>
#include <stdio.h>
#include <GLFW/glfw3.h>
#include <string>

struct rt_defines;

class GLWrapper
{
public:
	GLWrapper(int width, int height, bool fullScreen);
	GLWrapper(bool fullScreen);
	~GLWrapper();

	int getWidth();
	int getHeight();

	bool init_window();
	void init_shaders(rt_defines defines);

	void stop();

	GLFWwindow* window;

    void draw();

	//GLuint computeHandle;
	GLuint renderHandle;

private:
    //GLuint texHandle;

	int width;
	int height;

	bool fullScreen = true;
	bool useCustomResolution = false;

    static void print_shader_info_log(GLuint shader);
    static void print_program_info_log(GLuint program);
    static bool check_shader_errors(GLuint shader);
    static bool check_program_errors(GLuint program);

    static void checkErrors(std::string desc);
    static GLuint genRenderProg(rt_defines defines);
};

