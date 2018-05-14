#version 410 core

in vec4		vtxColor;
out vec4	fragColor;

uniform matrixBlock
{
	mat4 projView;
}matrices;

void	main()
{
	fragColor = vtxColor;
}
