#include "matrices.h"
#include "scene.h"

void	update_uniforms(t_scene scene, t_matrices mat)
{
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubos[UBO_0]);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(t_mat4), &mat.final_mat);
	glBufferSubData(GL_UNIFORM_BUFFER, sizeof(t_mat4),
										sizeof(float), &scene.timeline.ratio);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
