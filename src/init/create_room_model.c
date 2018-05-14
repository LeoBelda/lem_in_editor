#include "scene.h"

#define MOD_NB_VTX 3
#define MOD_NB_IND 3

static t_glfloat2	*gen_coords(void)
{
	t_glfloat2	*coords;

	m_pro_null(coords = ft_memalloc(MOD_NB_VTX * sizeof(t_glfloat2)));
	coords[0] = (t_glfloat2){1.0, 0.0};
	coords[1] = (t_glfloat2){-1.0, -1.0};
	coords[2] = (t_glfloat2){-1.0, 1.0};
	return (coords);
}

static GLuint		*gen_indices(void)
{
	GLuint	*indices;

	m_pro_null(indices = ft_memalloc(MOD_NB_IND * sizeof(GLuint)));
	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	return (indices);
}

t_mesh				create_room_model(void)
{
	t_mesh	model;

	model.coords = gen_coords();
	model.nb_coords = MOD_NB_VTX;
	model.indices = gen_indices();
	model.nb_indices = MOD_NB_VTX;
	return (model);
}
