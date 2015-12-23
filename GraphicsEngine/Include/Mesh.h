#pragma once
#include <GL\glew.h>
#include <vector>
#include <string>
#include "Vertex3D.h"
#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>
#include <Windows.h>
#define BUFFER_OFFSET(i) ((char *)NULL + (i))
class Mesh
{
public:
	Mesh(std::string modelFileName);
	~Mesh();
	void Draw();
	void InitMesh(const std::vector<Vertex3D> &vertices, const std::vector<unsigned int> &indices);
private:
	const std::string MESH_PATH = ".\\res\\models\\";//"..\\..\\res\\models";
	GLuint m_vbo;
	GLuint m_ibo;
	GLuint m_indices;
	std::vector<Vertex3D> m_vertices;
	std::string m_fileName;
};

