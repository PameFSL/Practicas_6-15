#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	codo = 0.0f;
	hombro = 0.0f;
	muneca = 0.0f;
	falange_indice = 0.0f;
	falangina_indice = 0.0f;
	falangeta_indice = 0.0f;
	medio1 = 0.0f; medio2 = 0.0f; medio3 = 0.0f; angular1 = 0.0f;
	pulgar1 = 0.0f; pulgar2 = 0.0f; pulgar3 = 0.0f;
	angular2 = 0.0f; angular3 = 0.0f; menique1 = 0.0f; menique2 = 0.0f; menique3 = 0.0f;

	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "Practica 6 Modelado Jerarquico", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas

							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
}

void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key == GLFW_KEY_E)
	{
		theWindow->hombro += 90.0;
	}

	if (key == GLFW_KEY_R)
	{
		theWindow->codo += 90.0;
	}
	if (key == GLFW_KEY_T)
	{
		theWindow->muneca += 90.0;
	}
	if (key == GLFW_KEY_Y)
	{
		theWindow->falange_indice += 90.0;
	}
	if (key == GLFW_KEY_U)
	{
		theWindow->falangina_indice += 90.0;
	}
	if (key == GLFW_KEY_I)
	{
		theWindow->falangeta_indice += 90.0;
	}
	//***************************************


	if (key == GLFW_KEY_W)
	{
		theWindow->medio1 += 90.0;
	}
	if (key == GLFW_KEY_S)
	{
		theWindow->medio2 += 90.0;
	}
	if (key == GLFW_KEY_D)
	{
		theWindow->medio3 += 10.0;
	}
	if (key == GLFW_KEY_F)
	{
		theWindow->angular1 += 10.0;
	}
	if (key == GLFW_KEY_G)
	{
		theWindow->angular2 += 10.0;
	}
	if (key == GLFW_KEY_H)
	{
		theWindow->angular3 += 10.0;
	}
	if (key == GLFW_KEY_J)
	{
		theWindow->menique1 += 10.0;
	}
	if (key == GLFW_KEY_K)
	{
		theWindow->menique2 += 10.0;
	}
	if (key == GLFW_KEY_L)
	{
		theWindow->menique3 += 10.0;
	}
	if (key == GLFW_KEY_Z)
	{
		theWindow->pulgar1 += 10.0;
	}
	if (key == GLFW_KEY_X)
	{
		theWindow->pulgar2 += 10.0;
	}
	if (key == GLFW_KEY_C)
	{
		theWindow->pulgar3 += 10.0;
	}



	/*
		if (key == GLFW_KEY_D && action == GLFW_PRESS)
		{

				theWindow->codo += 10.0;
			printf("Incremento de 10 grados en codo %f\n");
		}
		*/
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			printf("se solto la tecla %d'\n", key);
		}
	}
}

Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}