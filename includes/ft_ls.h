/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:10:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 13:09:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LS_LEGAL_OPTS			"AFGRUSTacdfgloprtu1"
# define LS_MSG_ILLEGAL_OPT		"ft_ls: illegal option -- %c\n"
# define LS_MSG_USAGE			"usage: ls [-%s] [file ...]\n"
# define LS_MSG_FILE_ERR		"ls: %s: No such file or directory\n"
# define LS_MSG_ACC_ERR			"ls: %s: Permission denied\n"

# ifndef S_IXUGO
#  define S_IXUGO		(S_IXUSR | S_IXGRP | S_IXOTH)
# endif

# define OPTS_LA		0x00000001
# define OPTS_LC		0x00000002
# define OPTS_LD		0x00000004
# define OPTS_LF		0x00000008
# define OPTS_LG		0x00000010
# define OPTS_LL		0x00000020
# define OPTS_LO		0x00000040
# define OPTS_LP		0x00000080
# define OPTS_LR		0x00000100
# define OPTS_LT		0x00000200
# define OPTS_LU		0x00000400

# define OPTS_UA		0x00000800
# define OPTS_UF		0x00001000
# define OPTS_UG		0x00002000
# define OPTS_UR		0x00004000
# define OPTS_UU		0x00008000
# define OPTS_US		0x00010000
# define OPTS_UT		0x00020000

# define OPTS_ONE		0x00040000
# define OPTS_ERR_A		0x00100000
# define OPTS_HEAD		0x01000000

# define TIME_MASK		(OPTS_LC | OPTS_LU | OPTS_UU)

# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/acl.h>

struct	s_lsdata
{
	struct stat		stat;
	char			*path;
	struct dirent	*dirent;
};

struct	s_pads
{
	int		nlink;
	int		name;
	int		gr_name;
	int		size;
	int		major;
	int		minor;
};

struct	s_opts
{
	char	id;
	int		on;
	int		off;
};

typedef struct s_lsdata		t_lsdata;
typedef struct s_pads		t_pads;
typedef struct s_opts		t_opts;

extern t_opts	g_opts[];

int		ft_ls_parse(int ac, char **av, t_list **dir, t_list **ent);

void	ft_ls_dirs(t_list *dir, int opts);
void	ft_ls_files(t_list **ent, t_list **dir, t_lsdata *topdir, int *opts);

int		ft_cmp_mtime(t_lsdata *dat1, t_lsdata *dat2);
int		ft_cmp_atime(t_lsdata *dat1, t_lsdata *dat2);
int		ft_cmp_ctime(t_lsdata *dat1, t_lsdata *dat2);
int		ft_cmp_btime(t_lsdata *dat1, t_lsdata *dat2);

void	ft_ls_postname(mode_t m, int opts);
void	ft_lsdata_filename(t_lsdata *data, t_lsdata *topdir, int opts);
int		ft_lsdata_cmp_name(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp_size(t_lsdata *dat1, t_lsdata *dat2);
int		ft_lsdata_cmp0(t_lsdata *dat1, char *dataref);
int		ft_lsdata_cmpa(t_lsdata *data, char *dataref);

void	ft_ent_filter(t_list **ent, int opts);
void	ft_ent_sort(t_list **ent, int opts);
void	ft_ent_print(
		t_list *ent, int *opts, t_lsdata *topdir, t_list *nextdir);
int		ft_ent_has_dir(t_list *ent);
t_list	*ft_ent_get_dirs(t_list **ent);
void	ft_ent_free(void *ptr, size_t size);

t_list	*ft_dir_get_ents(t_lsdata *topdir, int *opts);

void	ft_ls_short(t_list *ent, t_lsdata *topdir, int opts);

int		ft_ls_long(t_list *ent, t_lsdata *topdir, int opts);
int		ft_ls_long_print(t_list *ent, t_lsdata *topdir, t_pads pads, int opts);

void	ft_ls_long_total(t_list *ent);
int		ft_ls_long_pads(t_list *ent, t_pads *pads);
void	ft_ls_long_type(mode_t m);
void	ft_ls_long_rights(mode_t m);
int		ft_ls_long_xattr(mode_t m, char *path);
int		ft_ls_long_middle(struct stat *stat, t_pads *pads, int opts);
void	ft_ls_long_date(struct stat *stat, int opts);
int		ft_ls_long_lnk(t_lsdata *data);

void	ft_error_option(char c);
void	ft_error_dir(char *s);
void	ft_error_access(char *s);

void	ft_ls_color(mode_t m);
#endif
