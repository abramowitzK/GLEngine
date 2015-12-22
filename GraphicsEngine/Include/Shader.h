#pragma once
#include <GL\glew.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
class Shader
{
public:
	Shader();
	~Shader();
	void LoadVertexShader(std::string shaderFileName);
	void LoadFragmentShader(std::string shaderFileName);
	void Bind();
	GLuint GetProgram() const
	{
		return m_program;
	}
private:
	void AddVertexShader(const GLchar* text);
	void AddFragmentShader(const GLchar* text);
	void AddProgram(const GLchar* text, GLuint type);
	void CompileShader();
	std::vector<GLint> m_shaders;
	static std::string SHADER_DIR;
	GLuint m_program;
};

