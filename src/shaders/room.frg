#version 410 core

in vec4		vtxColor;
out vec4	fragColor;

uniform matrixBlock
{
	mat4 projView;
	float scale;
	float ratio;
}mat;

void	main()
{
	fragColor = vtxColor;
}
