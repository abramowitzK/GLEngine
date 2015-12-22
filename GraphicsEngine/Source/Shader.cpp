#include "..\Include\Shader.h"
#include <cassert>

std::string Shader::SHADER_DIR = "..\\..\\res\\shaders";
Shader::Shader()
{
	m_program = glCreateProgram();
	if (0 == m_program)
	{
		//Do error stuff here. For now we're just going to crash horribly
		assert(false);
	}
}

Shader::~Shader()
{
	for (GLint i : m_shaders)
	{
		glDetachShader(m_program, i);
		glDeleteShader(i);
	}
	glDeleteProgram(m_program);
}

void Shader::LoadVertexShader(std::string shaderFileName)
{
	shaderFileName = SHADER_DIR + "\\" + shaderFileName;
	std::ifstream fs(shaderFileName);
	std::stringstream buffer;
	buffer << fs.rdbuf();
	AddVertexShader(buffer.str().c_str());
}

void Shader::LoadFragmentShader(std::string shaderFileName)
{
	shaderFileName = SHADER_DIR + "\\" + shaderFileName;
	std::ifstream fs(shaderFileName);
	std::stringstream buffer;
	buffer << fs.rdbuf();
	AddFragmentShader(buffer.str().c_str());
}

void Shader::Bind()
{
	glUseProgram(m_program);
}

void Shader::AddVertexShader(const GLchar * text)
{
	AddProgram(text, GL_VERTEX_SHADER);
}

void Shader::AddFragmentShader(const GLchar * text)
{
	AddProgram(text, GL_FRAGMENT_SHADER);
}

void Shader::AddProgram(const GLchar * text, GLuint type)
{
	GLint shader = glCreateShader(type);
	if (0 == shader)
	{
		assert(false);
	}
	glShaderSource(shader, 1, &text, nullptr);
	glCompileShader(shader);
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];

		glGetShaderInfoLog(shader, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", shader, InfoLog);

		exit(1);
	}
	glAttachShader(m_program, shader);
	m_shaders.push_back(shader);
	CompileShader();
}

void Shader::CompileShader()
{
	glLinkProgram(m_program);
	glValidateProgram(m_program);
}


