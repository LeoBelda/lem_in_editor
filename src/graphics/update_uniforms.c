#include "matrices.h"
#include "scene.h"

void	update_uniforms(t_scene scene, t_matrices mat)
{
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(t_mat4), &mat.final_mat);
	ft_printf("%f  ", scene.ratio);
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(t_mat4),
										sizeof(float), &scene.ratio);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
