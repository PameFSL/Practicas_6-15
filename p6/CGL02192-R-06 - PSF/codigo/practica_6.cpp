#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al còdigo
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
#include"Sphere.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<Shader>shaderList;

Sphere sp = Sphere(0.03, 20, 20);
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";

void CreateObject()
{
	unsigned int indices[] = { 
		0,3,1,
		1,3,2,
		2,3,0,
		0,1,2,
	};
	//segunda fila
	GLfloat vertices[] = {
		0.0f, 0.8f,0.0f,  //A
		-0.15f, 0.6f,0.0f,  //
		0.15f, 0.6f,0.0f,  //
		-0.0f, 0.6f,0.01f,  //A
	};
	// cintas
	GLfloat cinta[] = {
		-0.29f, 0.28f,0.0f,  //D
		0.29f, 0.28f,0.0f,  // E
		-0.32f,0.24f,0.0f,  // F
		-0.32f,0.24f,0.0f,  // F
	};
	GLfloat cinta1[] = {
		0.32f,0.24f,0.0f,  // F
		-0.32f,0.24f,0.0f,  // F
		0.29f, 0.28f,0.0f,  //D
		-0.32f,0.24f,0.0f,  // F
	};
	GLfloat vertices1[] = {
		0.0f, 0.7f,0.0f,  //A
		-0.25f, 0.4f,0.0f,  //
		0.25f, 0.4f,0.0f,  //
		-0.0f, 0.4f,0.1f,  //A 
	};  GLfloat vertices3[] = {
		0.0f, 0.5f,0.0f,  //A
		-0.5f, -0.1f,0.0f,  //
		0.5f,-0.1f,0.0f,  //
		-0.0f,-0.1f,0.1f,  //A 
	};

	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);
	Mesh *obj2 = new Mesh();

	obj2->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj2);
	Mesh *obj3 = new Mesh();
	obj3->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj3);
	Mesh *obj4 = new Mesh();

	//parte inferior
	obj4->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj4);

	Mesh *obj5 = new Mesh();
	obj5->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj5);

	Mesh *obj6 = new Mesh();
	obj6->CreateMesh(vertices3, indices, 12, 12);
	meshList.push_back(obj6);


	//*****copia cintas******
	Mesh *obj7 = new Mesh();
	obj7->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj7);
	Mesh *obj8 = new Mesh();
	obj8->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj8);

	Mesh *obj9 = new Mesh();
	obj9->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj9);
	Mesh *obj10 = new Mesh();
	obj10->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj10);

	Mesh *obj11 = new Mesh();
	obj11->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj11);
	Mesh *obj12 = new Mesh();
	obj12->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj12);

	Mesh *obj13 = new Mesh();
	obj13->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj13);
	Mesh *obj14 = new Mesh();
	obj14->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj14);
	/*//************
	Mesh *obj6 = new Mesh();
	obj6->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj6);

	//*****copia cintas******
	Mesh *obj7 = new Mesh();
	obj7->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj7);
	Mesh *obj8 = new Mesh();
	obj8->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj8);
	Mesh *obj9 = new Mesh();
	obj9->CreateMesh(vertices3, indices, 12, 12);
	meshList.push_back(obj9);
	
	Mesh *obj10 = new Mesh();
	obj10->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj10);
	Mesh *obj11 = new Mesh();
	obj11->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj11);
	Mesh *obj12 = new Mesh();
	obj12->CreateMesh(cinta, indices, 12, 12);
	meshList.push_back(obj12);
	Mesh *obj13 = new Mesh();
	obj13->CreateMesh(cinta1, indices, 12, 12);
	meshList.push_back(obj13);*/
}

void CrearCubo(){
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 2,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	// front
	-0.5f, -0.5f,  0.5f,
	0.5f, -0.5f,  0.5f,
	0.5f,  0.5f,  0.5f,
	-0.5f,  0.5f,  0.5f,
	// back
	-0.5f, -0.5f, -0.5f,
	0.5f, -0.5f, -0.5f,
	0.5f,  0.5f, -0.5f,
	-0.5f,  0.5f, -0.5f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);

}

//*******estrella**************
void CrearEsr() {
	unsigned int est_indices[] = {
		// front
		0, 1, 2,
		4, 3, 2,
		4,2,0,
		4,6,0,
		6,5,4,
		//10,6,0,
		//*****
		//9,0,11,
	};
	unsigned int est_indices2[] = {
		0,1,2,
		1,3,2,
		1,3,0,
		0,2,3,

		2,4,5,
		4,6,5,
		4,2,6,
		2,6,5,

		2,0,4,
		0,2,7,
		0,4,7,
		2,7,0,
		/*
		0,1,4,
		7,0,1,
		1,4,7,
		0,4,7,*/

	};
	unsigned int est_indices3[] = {
		0,1,2,
		1,3,2,
		1,3,0,
		0,2,3,
	};

	GLfloat estr_vertices[] = {
		// front
		-0.02f, 0.85f,  0.0f,  //K		0
		 0.0f, 0.88f,  0.0f, //J		1	
		0.02f, 0.85f,  0.0f, //S		2	
		// back
		//0.01f, 0.82f,  0.0f, //T
		0.07f, 0.84f, 0.0f,   //R		3
		0.04f,  0.82f, 0.0f,  //Q		4

		//0.3f,  0.81f, 0.0f,  //U		
		0.04f, 0.77f, 0.0f, //P 		5
		 -0.0f, 0.795f, 0.0f, //o  		6

		-0.04f, 0.77f, 0.0f, //N		7
		-0.04f,  0.82f, 0.0f, //M		8

		-0.07f, 0.84f, 0.0f, //L  		9
		-0.07f, 0.84f, 0.0f, //L  		10
		-0.04f,0.81f,0.0f	//			11

	}; GLfloat estr_vertices2[] = {
		-0.02f, 0.85f, 0.0f, //k  		0
		-0.07f, 0.84f, 0.0f, //L  		1
		-0.05f,0.81f,0.0f,	//	m		2
		 -0.04f, 0.83f,0.3f,  //A		3


		- 0.04f, 0.77f, 0.0f, //n  		4
		  -0.0f, 0.795f, 0.0f, //o  	5
		-0.03f, 0.79f, 0.3f, //n  	    6
		-0.05f,0.81f,0.5f,	//	m		7

	}; GLfloat estr_vertices3[] = {
		-0.02f, 0.85f, 0.0f, //k  		0
		-0.05f,0.81f,0.0f,	//	m		1
		 -0.0f, 0.795f, 0.0f, //o  	2
		0.01f,0.8f,0.5f,	//	m		3

	};

	Mesh *estrella = new Mesh();
	estrella->CreateMesh(estr_vertices, est_indices, 24, 36);
	meshList.push_back(estrella);

	Mesh *estrella2 = new Mesh();
	estrella2->CreateMesh(estr_vertices2, est_indices2, 24, 36);
	meshList.push_back(estrella2);

	Mesh *estrella3 = new Mesh();
	estrella3->CreateMesh(estr_vertices3, est_indices3, 12, 24);
	meshList.push_back(estrella3);

	//****copia estrella******

	Mesh *estrella11 = new Mesh();
	estrella11->CreateMesh(estr_vertices, est_indices, 24, 36);
	meshList.push_back(estrella11);

	Mesh *estrella112 = new Mesh();
	estrella112->CreateMesh(estr_vertices2, est_indices2, 24, 36);
	meshList.push_back(estrella112);

	Mesh *estrella113 = new Mesh();
	estrella113->CreateMesh(estr_vertices3, est_indices3, 12, 24);
	meshList.push_back(estrella113);

	//****copia 2 estrella******

	Mesh *estrella21 = new Mesh();
	estrella21->CreateMesh(estr_vertices, est_indices, 24, 36);
	meshList.push_back(estrella21);

	Mesh *estrella212 = new Mesh();
	estrella212->CreateMesh(estr_vertices2, est_indices2, 24, 36);
	meshList.push_back(estrella212);

	Mesh *estrella213 = new Mesh();
	estrella213->CreateMesh(estr_vertices3, est_indices3, 12, 24);
	meshList.push_back(estrella213);
}
//*******************************
void CreateShaders(){
	Shader *shaderEst = new Shader();
	shaderEst->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shaderEst);
}


int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CreateObject();
  //***************
	CrearCubo();
	CrearEsr();
  //***************
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	GLuint uniformView = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::ortho(-1, 1, -1, 1, 1, 10);
	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.5f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLoaction();
		uniformProjection = shaderList[0].getProjectLocation();
		uniformView = shaderList[0].getViewLocation();
		uniformColor = shaderList[0].getColorLocation();
		glm::mat4 model(1.0);
		glm::mat4 modeltemp(1.0);
		sp.init();
		sp.load();

		glm::vec3 currentColor = glm::vec3(0.0f, 0.92f, 0.1f);
		//***********************************************************
		model = glm::translate(model, glm::vec3(0.0f, -0.14f, 0.0f));
		modeltemp = model = glm::rotate(model, glm::radians(mainWindow.gethombro()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));
		modeltemp = model;
		//************* esfera ****************
		model = glm::scale(model, glm::vec3(.75f, .75, 0.75f));
		currentColor = glm::vec3(1.0f, 0.0f, 0.1f);
		model = glm::translate(model, glm::vec3(0.2f,0.8f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(-0.4f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = modeltemp;
		//******************************************************

		model = glm::rotate(model, glm::radians(mainWindow.getmedio1()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));
			//**estrella**
		currentColor = glm::vec3(1.0f, 1.0f, 0.0f);
		model = glm::translate(model, glm::vec3(0.0f, -0.33f, 0.0f));
		model = glm::scale(model, glm::vec3(1.2f, 1.5f, 0.0f));
		model = glm::translate(model, glm::vec3(0.0f, -0.05f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[15]->RenderMesh();
		//**estrella parte 2**
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[16]->RenderMesh();
		//p3
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[17]->RenderMesh();

		//******************************************************
		//**estrella 2**
		model = glm::mat4(1.0);//reiniciamos modelo con la matriz identidad

		model = glm::rotate(model, glm::radians(mainWindow.getmedio1()*toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::rotate(model, glm::radians(mainWindow.gethombro()*toRadians), glm::vec3(0.0f, 0.0f, 1.0f));
		currentColor = glm::vec3(1.0f, 1.0f, 0.0f);
		model = glm::translate(model, glm::vec3(-0.5f, -0.76f, 0.0f));
		model = glm::scale(model, glm::vec3(1.2f, 1.5f, 1.2f));
		model = glm::translate(model, glm::vec3(0.0f, -0.05f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[18]->RenderMesh();
		//**estrella parte 2**
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[19]->RenderMesh();
		//p3
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[20]->RenderMesh();
		//******************************************************
		//**estrella 3**
		model = glm::translate(model, glm::vec3(0.83f, 0.0f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[21]->RenderMesh();
		//**estrella parte 2**
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[22]->RenderMesh();
		//p3
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[23]->RenderMesh();

		//***********************
		model = modeltemp;
		currentColor = glm::vec3(0.0f, 0.92f, 0.1f);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[0]->RenderMesh();
		model = glm::translate(model, glm::vec3(0.0f, -0.45f, 0.0f));
		model = glm::rotate(model, glm::radians(mainWindow.getcodo()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));
		modeltemp = model;
		//************* esfera ****************
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.728f, 0.731f, 0.0f));
		currentColor = glm::vec3(1.0f, 0.0f, 0.1f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = glm::translate(model, glm::vec3(0.37f, -0.192f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(-0.74f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = modeltemp;
		//*******cinta*********
		currentColor = glm::vec3(1.0f, 0.4f, 0.3f);
		model = glm::translate(model, glm::vec3(0.0f, 0.69f, 0.0f));
		model = glm::scale(model, glm::vec3(0.61f, .95f, 0.61f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[6]->RenderMesh();

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[7]->RenderMesh();
		model = modeltemp;
		//****************
		currentColor = glm::vec3(0.0f, 1.0f, 0.1f);
		modeltemp =model = glm::scale(model, glm::vec3(1.69f, 1.43f, 1.69f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[1]->RenderMesh();

		model = modeltemp;
		model = glm::translate(model, glm::vec3(0.0f, -0.48f, 0.0f));
		model = glm::rotate(model, glm::radians(mainWindow.getmuneca()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));
		modeltemp = model;
	//************* esfera ****************
		model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.56f, 0.56f, 0.0f));
		currentColor = glm::vec3(1.0f, 0.0f, 0.1f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(0.44f, -0.18f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(-0.88f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		//*******cinta**********
		currentColor = glm::vec3(1.0f, 0.4f, 0.3f);
		//modeltemp = model;
		model = modeltemp;
		model = glm::translate(model, glm::vec3(0.0f, 0.74f, 0.0f));
		model = glm::scale(model, glm::vec3(0.65f, .83f, 0.65f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[6]->RenderMesh();

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[7]->RenderMesh();
		model = modeltemp;
		//****************
		currentColor = glm::vec3(0.0f, 0.92f, 0.1f);
		model = glm::scale(model, glm::vec3(1.62f, 1.5f, 1.62f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[2]->RenderMesh();

		model = glm::translate(model, glm::vec3(0.0f, -0.43f, 0.0f));
		modeltemp = model = glm::rotate(model, glm::radians(mainWindow.getfalange_indice()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));

		//************* esfera ****************
		model = glm::translate(model, glm::vec3(-0.07f, 0.967f, 0.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.0f));
		currentColor = glm::vec3(1.0f, 0.0f, 0.1f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = glm::translate(model, glm::vec3(0.34f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(0.349f, -0.18f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(-1.02f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = modeltemp;
		//*******cinta*********
		currentColor = glm::vec3(1.0f, 0.4f, 0.3f);
		model = glm::translate(model, glm::vec3(0.0f, 0.77f, 0.0f));
		model = glm::scale(model, glm::vec3(0.59f, .63f, 0.59f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[8]->RenderMesh();

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[9]->RenderMesh();
		model = modeltemp;
		//****************
		
		currentColor = glm::vec3(0.0f, 1.0f, 0.1f);
		model = glm::scale(model, glm::vec3(1.35f, 1.5f, 1.35f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[3]->RenderMesh();

		model = glm::translate(model, glm::vec3(0.0f, -0.4f, 0.0f));
		modeltemp = model = glm::rotate(model, glm::radians(mainWindow.getfalangina_indice()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));

		//************* esfera ****************
		model = glm::translate(model, glm::vec3(-0.105f, 0.954f, 0.0f));
		model = glm::scale(model, glm::vec3(0.29f, 0.29f, 0.0f));
		currentColor = glm::vec3(1.0f, 0.0f, 0.1f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = glm::translate(model, glm::vec3(0.345f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = glm::translate(model, glm::vec3(0.345f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(0.349f, -0.188f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();

		model = glm::translate(model, glm::vec3(-1.348f, 0.0f, 0.0f));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA		
		sp.render();
		model = modeltemp;
		//*******cinta*********
		currentColor = glm::vec3(1.0f, 0.4f, 0.3f);
		modeltemp = model;
		model = glm::translate(model, glm::vec3(0.0f, 0.82f, 0.0f));
		model = glm::scale(model, glm::vec3(0.59f, .38f, 0.59f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[8]->RenderMesh();

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[9]->RenderMesh();
		model = modeltemp;
		//***
		currentColor = glm::vec3(0.0f, 0.92f, 0.1f);
		model = glm::scale(model, glm::vec3(1.28f, 1.5f, 1.28f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[4]->RenderMesh();

		currentColor = glm::vec3(0.4f, 0.3f, 0.3f);
		modeltemp = model = glm::translate(model, glm::vec3(0.0f, 0.585f, 0.0f));
		model = glm::rotate(model, glm::radians(mainWindow.getfalangeta_indice()*toRadians), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.04f, 0.04f, 0.00f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
		glUniform3fv(uniformColor, 1, glm::value_ptr(currentColor));
		meshList[14]->RenderMesh();


		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}