
#include "ft_ls.h"

t_opts	g_opts[] =
{
	{'A', OPTS_UA, 0},
	{'F', OPTS_UF, OPTS_LP},
	{'G', OPTS_UG, 0},
	{'R', OPTS_UR, 0},
	{'S', OPTS_US, 0},
	{'T', OPTS_UT, 0},
	{'U', OPTS_UU, TIME_MASK},
	{'a', OPTS_LA, 0},
	{'c', OPTS_LC, TIME_MASK},
	{'d', OPTS_LD, 0},
	{'f', OPTS_LF, 0},
	{'g', OPTS_LG, 0},
	{'l', OPTS_LL, 0},
	{'o', OPTS_LO, 0},
	{'p', OPTS_LP, OPTS_UF},
	{'r', OPTS_LR, 0},
	{'t', OPTS_LT, 0},
	{'u', OPTS_LU, TIME_MASK},
	{'1', OPTS_ONE, (OPTS_LL | OPTS_LG | OPTS_LO)},
	{0, 0, 0},
};

static void	ft_ls_parse_files(char **av, int opts, t_list **dir, t_list **ent)
{
	t_lsdata	data;
	int			i;

	data.dirent = NULL;
	i = -1;
	while (av[++i])
	{
		if (stat(av[i], &data.stat) < 0)
			if (lstat(av[i], &data.stat) < 0)
			{
				ft_error_dir(av[i]);
				continue ;
			}
		if (opts & OPTS_LL || !S_ISDIR(data.stat.st_mode))
			if (lstat(av[i], &data.stat) < 0)
			{
				ft_error_dir(av[i]);
				continue ;
			}
		data.path = ft_strdup(av[i]);
		if (opts & OPTS_LD || !S_ISDIR(data.stat.st_mode))
			ft_lstadd(ent, ft_lstnew(&data, sizeof(data)));
		else
			ft_lstadd(dir, ft_lstnew(&data, sizeof(data)));
	}
}

static int	ft_getopts(char *str)
{
	int	i;
	int	j;
	int	opts;

	i = 0;
	opts = 0;
	while (str[i])
	{
		j = -1;
		while (g_opts[++j].id)
			if (g_opts[j].id == str[i])
			{
				opts &= ~g_opts[j].off;
				opts |= g_opts[j].on;
				break ;
			}
		if (!ft_strchr(LS_LEGAL_OPTS, str[i]))
		{
			ft_error_option(str[i]);
			exit(1);
		}
		i++;
	}
	return (opts);
}

static int	ft_ls_parse_options(int ac, char **av, int *opts)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-')
		{
			if (!av[i][1])
				break ;
			if (av[i][1] == '-' && !av[i][2])
			{
				i++;
				break ;
			}
			*opts |= ft_getopts(av[i] + 1);
		}
		else
			break ;
	}
	return (i);
}

/*
**	COMMENTAIRE 1
**
**	ft_ls_parse est la premiere fonction utilisée par le main
**	elle sert a sonder les options en input et trier les fichiers des dossiers
**	comme le ferait ls qui s'applique d'abors à tous les fichiers passés en arguments
**	avant d'aller sur les dossiers et sous dossiers si la fonction -R est passée.
**
**	-Pour cela ft_ls_parse_options qui parcours les argvs sera utilisée, "active les options"
**	puis renvoie l'index a partir duquel on commence a lire des fichiers/dossiers.
**
**	-Elle passe en suite l'adresse de cet argv a l'index en question dans la fonction ft_sstrsort
**	qui aura pour job de separer tous les fichiers/dossiers.
**
**	-Ensuite si il se trouve que l'index a partir duquel on commence a lire du fichier est egale au nombre
**	d'arguments, et qu'il n'y a donc aucun fichier specifié a traité, on passera dans le fonction suivante
**	avec l'arguments "." d'origine
**
**	-La fonction suivante est en realité la fonction principale du ft_ls, c'est ft_ls_parse_files qui,
**	comme son nom l'indique fait le parsing des files a partir du l'adresse renvoyeé par le parseur d'options
**	elle prendra en parametres les strings des noms des fichiers a passer en arguments, la structure conteant
**	les options et les structures t_list (le type de la libft) dir et ent... 
**	pour plus d'informations sur ces dernieres consulter la fonction ft_ls_parse_files se trouvant
** au dessus de ce commentaire
*/


int			ft_ls_parse(int ac, char **av, t_list **dir, t_list **ent)
{
	int		i;
	int		opts;

	opts = 0;
	i = ft_ls_parse_options(ac, av, &opts);
	opts |= (ac - i > 1) ? OPTS_HEAD : 0;
	ft_sstrsort(av + i, &ft_strcmp);
	if (i == ac)
		ft_ls_parse_files((char *[2]){"."}, opts, dir, ent);
	else
		ft_ls_parse_files(av + i, opts, dir, ent);
	return (opts);
}
