#pragma once
#include<stdio.h>
#include<glew.h>
#include<glfw3.h>

class Window
{
public:
	Window();
	Window(GLint windowWidth, GLint windowHeight);
	int Initialise();
	GLfloat getBufferWidth() { return bufferWidth; }
	GLfloat getBufferHeight() { return bufferHeight; }
	bool getShouldClose() {
		return  glfwWindowShouldClose(mainWindow);
	}
	bool* getsKeys() { return keys; }
	void swapBuffers() { return glfwSwapBuffers(mainWindow); }
	GLfloat getcodo() { return codo; }
	GLfloat gethombro() { return hombro; }
	GLfloat getmuneca() { return muneca; }
	GLfloat getfalange_indice() { return falange_indice; }
	GLfloat getfalangina_indice() { return falangina_indice; }
	GLfloat getfalangeta_indice() { return falangeta_indice; }
	//*******************************************************
	GLfloat getmedio1() { return medio1; }
	GLfloat getmedio2() { return medio2; }
	GLfloat getmedio3() { return medio3; }
	GLfloat getangular1() { return angular1; }
	GLfloat getangular2() { return angular2; }
	GLfloat getangular3() { return angular3; }
	GLfloat getmenique1() { return menique1; }
	GLfloat getmenique2() { return menique2; }
	GLfloat getmenique3() { return menique3; }
	GLfloat getpulgar1() { return pulgar1; }
	GLfloat getpulgar2() { return pulgar2; }
	GLfloat getpulgar3() { return pulgar3; }


	~Window();
private:
	GLFWwindow *mainWindow;
	GLint width, height;
	GLfloat codo, hombro, muneca, falange_indice, falangina_indice, falangeta_indice;
	GLfloat medio1, medio2, medio3, angular1, angular2, angular3, menique1, menique2, menique3, pulgar1, pulgar2, pulgar3;
	bool keys[1024];
	GLint bufferWidth, bufferHeight;

	void createCallbacks();
	static void ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode);
};


