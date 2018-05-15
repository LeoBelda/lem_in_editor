#version 410 core

in vec4		vtxColor;
in vec2		state;
out vec4	fragColor;

uniform matrixBlock
{
	mat4 projView;
	float ratio;
}matrices;

void	main()
{
	fragColor = vtxColor;
}
