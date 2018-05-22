#version 410 core

in vec4		vtxColor;
in float f_state;

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
