#include "scene.h"
#include "debug.h"

t_glfloat2	*get_room_positions(t_list *rooms, int nb_rooms)
{
	t_glfloat2	*positions;
	int			i;

	m_pro_null(positions = ft_memalloc(nb_rooms * sizeof(t_glfloat2)));
	i = 0;
	while (rooms)
	{
		positions[i++] = (t_glfloat2) {((t_room*)rooms->content)->coords.x,
								((t_room*)rooms->content)->coords.y};
		rooms = rooms->next;
	}
	return (positions);
}

GLuint		*get_link_indices(t_list *links, int nb_links)
{
	GLuint	*indices;
	int		i;

	m_pro_null(indices = ft_memalloc(nb_links * sizeof(GLuint) * 2));
	i = 0;
	while (links)
	{
		indices[i++] = ((t_link*)links->content)->a->id;
		indices[i++] = ((t_link*)links->content)->b->id;
		links = links->next;
	}
	return (indices);
}
