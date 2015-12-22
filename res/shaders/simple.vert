#version 400
layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 MVP;

void main()
{
	gl_position = MVP * vec4(vertexPosition_modelspace, 1);
} 