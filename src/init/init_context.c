#include "visu.h"

# ifdef __APPLE__

static void	compat(void)
{
	return ;
}

# else

static void	compat(void)
{
	glewInit();
}

# endif

static void	init_sdl(t_env *e)
{
	int	ret;

	ret = 0;
	if (SDL_Init(SDL_INIT_GAMECONTROLLER | SDL_INIT_VIDEO))
		error_exit(SDL_GetError());
	ret |= SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	ret |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	ret |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	ret |= SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
			SDL_GL_CONTEXT_PROFILE_CORE);
	if (ret)
		error_exit(SDL_GetError());
	if (!(e->win = SDL_CreateWindow("lem-in", SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED, 0, 0,
					SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL)))
		error_exit("");
	SDL_GetWindowSize(e->win, &e->x_win, &e->y_win);
	e->ratio = (float)e->x_win / (float)e->y_win;
	if (!(e->ogl.context = SDL_GL_CreateContext(e->win)))
		error_exit(SDL_GetError());
}

void	init_env(t_env *e)
{
	init_sdl(e);
	compat();
	glClearColor(0., 0., 0., 1.);
	glViewport(0, 0, e->x_win, e->y_win);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
}
