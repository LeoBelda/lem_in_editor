#version 410 core

in vec4		vtxColor;
in float f_state_x;
in float f_state_y;
flat in float t_ratio;

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
