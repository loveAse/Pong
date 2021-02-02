#version 330 core

layout ( location=0 ) in vec2 inPosition;

uniform vec2 uPosition;

void main ( void )
{
	gl_Position = vec4(inPosition + uPosition, 0.0, 1.0);
}