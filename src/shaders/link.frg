#version 410 core

in float f_state;

out vec4	fragColor;

uniform matrixBlock
{
	mat4 projView;
	float ratio;
}matrices;

void	main()
{
	vec4 baseColor = vec4(0.4, 0.4, 0.4, 1.0);
	if (f_state > 0)
	{
		if (abs(f_state - (1. - matrices.ratio)) < 0.1)
			fragColor = vec4(1.0, 0.0, 0.0, 0.0);
		else
			fragColor = baseColor;
	}
	else
	{
		fragColor = baseColor;
	}
}
