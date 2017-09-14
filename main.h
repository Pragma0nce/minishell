#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef	struct	s_env t_env;

struct				s_env
{
	char			*str;
	struct s_env	*next;
};

// vaughan environment functions
t_env	*ft_unset_env(char *key, t_env *list);
t_env	*ft_load_list(char **env);
t_env	*ft_set_env(char *key, char *value, t_env *list);
int	get_next_line(const int fd, char **line);
int     launch_program(char **args, char **envp);
char	*ft_addchar(char *str, char c);
char	**list_to_arr(t_env *list);

// builtin programs
void    run_builtin_echo(char **args, char **envp);
void    run_builtin_cd(char **args, char **envp);
void    run_builtin_setenv(char **args, char **envp);
void    run_builtin_unsetenv(char **args, char **envp);
void    run_builtin_env(char **args, char **envp);
void    run_builtin_exit(char **args, char **envp);

// printing-utility functions
void    debug(char *str);
void	debug_print_env(char **envp);
#endif
