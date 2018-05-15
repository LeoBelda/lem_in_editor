#include "scene.h"

#define MOD_NB_VTX 9
#define MOD_NB_IND 10

static t_glfloat3	*gen_coords(void)
{
	t_glfloat3	*coords;

	m_pro_null(coords = ft_memalloc(MOD_NB_VTX * sizeof(t_glfloat3)));
	coords[0] = (t_glfloat3){0.0, 0.0, 1.0};
	coords[1] = (t_glfloat3){1.0, 0.4, 0.0};
	coords[2] = (t_glfloat3){1.0, -0.4, 0.0};
	coords[3] = (t_glfloat3){0.4, -1.00, 0.0};
	coords[4] = (t_glfloat3){-0.4, -1.00, 0.0};
	coords[5] = (t_glfloat3){-1.0, -0.40, 0.0};
	coords[6] = (t_glfloat3){-1.0, 0.40, 0.0};
	coords[7] = (t_glfloat3){-0.4, 1.00, 0.0};
	coords[8] = (t_glfloat3){0.4, 1.00, 0.0};
	return (coords);
}

static GLuint		*gen_indices(void)
{
	GLuint	*indices;
	int		i;

	i = -1;
	m_pro_null(indices = ft_memalloc(MOD_NB_IND * sizeof(GLuint)));
	while (++i < MOD_NB_IND)
		indices[i] = i;
	indices[--i] = 1;
	return (indices);
}

t_mesh				create_room_model(void)
{
	t_mesh	model;

	model.coords = gen_coords();
	model.nb_coords = MOD_NB_VTX;
	model.indices = gen_indices();
	model.nb_indices = MOD_NB_IND;
	return (model);
}
