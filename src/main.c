#include "ft_ls.h"

/*
**	Le main fonctionne en plusieurs parties:
**		-le parsing
**		-ft_ls_files, qui est le ft_ls qui est appliqué aux differents fichiers
**		-le liberation de la liste allouée
**		-ft_ls_dirs, qui est exactement la meme chose mais pour les directories
**		-le return du errno.
*/

int		main(int ac, char **av)
{
	t_list	*dir;
	t_list	*ent;
	int		opts;

	dir = NULL;
	ent = NULL;
	opts = ft_ls_parse(ac, av, &dir, &ent);
	ft_ls_files(&ent, &dir, NULL, &opts);
	ft_lstdel(&ent, &ft_ent_free);
	ft_ls_dirs(dir, opts);
	return (errno);
}
