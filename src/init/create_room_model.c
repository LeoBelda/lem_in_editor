#include "scene.h"

#define MOD_NB_VTX 9
#define MOD_NB_IND 10

static t_glfloat2	*gen_coords(void)
{
	t_glfloat2	*coords;

	m_pro_null(coords = ft_memalloc(MOD_NB_VTX * sizeof(t_glfloat2)));
	coords[0] = (t_glfloat2){0.0, 0.0};
	coords[1] = (t_glfloat2){1.0, 0.4};
	coords[2] = (t_glfloat2){1.0, -0.4};
	coords[3] = (t_glfloat2){0.4, -1.00};
	coords[4] = (t_glfloat2){-0.4, -1.00};
	coords[5] = (t_glfloat2){-1.0, -0.40};
	coords[6] = (t_glfloat2){-1.0, 0.40};
	coords[7] = (t_glfloat2){-0.4, 1.00};
	coords[8] = (t_glfloat2){0.4, 1.00};
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
