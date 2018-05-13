#include "common.h"

void	m_pro(int ret)
{
	if (ret == -1)
		error_exit("malloc error");
}

void	m_pro_null(void *ret)
{
	if (!ret)
		error_exit("malloc error");
}

void	free_pro(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
