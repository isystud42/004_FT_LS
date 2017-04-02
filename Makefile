NAME	=	ft_ls
CC		=	gcc

D_SRC	=	src
F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")
F_SRC	:=	ft_dir_get_ents.c ft_ent_free.c ft_ent_get_dirs.c ft_ent_has_dir.c ft_ls.c ft_ls_color.c ft_ls_long.c ft_ls_postname.c ft_ls_short.c lib_ent.c lib_error.c lib_ls_long.c lib_ls_long2.c lib_lsdata.c lib_parse.c lib_time.c main.c
DF_SRC	:=	$(addprefix $(D_SRC)/, $(F_SRC))

D_OBJ	=	obj
F_OBJ	=	$(F_SRC:.c=.o)
DF_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

D_INC	=	includes libft/includes
O_INC	=	$(addprefix -I, $(D_INC))

W_FLAGS	=	-Wall -Wextra -Werror
D_FLAGS	=

MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

libft/libft.a:
	@$(MAKE) -C libft/ 2>/dev/null

$(NAME): libft/libft.a $(DF_OBJ)
	$(CC) $(O_INC) -Llibft -lft $(W_FLAGS) $(DF_OBJ) -o $@ $(D_FLAGS)

clean:
	$(RM) $(D_OBJ)
	@$(MAKE) -C libft clean 2>/dev/null

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean 2>/dev/null

re: fclean all
