#include "matrices.h"
#include "scene.h"

void	update_camera(t_scene scene, t_matrices mat)
{
	glBindBuffer(GL_UNIFORM_BUFFER, scene.ubo);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(t_mat4), &mat.final_mat);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}
