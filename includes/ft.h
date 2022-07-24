/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijin <yijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:13:24 by yijin             #+#    #+#             */
/*   Updated: 2022/07/24 23:13:26 by yijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <string.h>
# include <errno.h>
# include <libgen.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define BUFSIZE (1024)

struct s_nlist
<<<<<<< HEAD
{
	struct s_nlist	*next;
	char			*name;
	char			*defn;
=======
{                       /* table entry: */
    struct s_nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
>>>>>>> f23a40beda0676dd484ae3f00efcf4ae73962765
};

typedef struct s_datalist
{
<<<<<<< HEAD
	struct s_datalist	*next;
	struct s_datalist	*pre;
	char				data[BUFFSIZE + 1];
}	*t_dl;
=======
    struct s_datalist *next;
    struct s_datalist *pre;
    char data[BUFFSIZE + 1];
}* t_dl;
>>>>>>> f23a40beda0676dd484ae3f00efcf4ae73962765

/*struct	s_number
{
	char			*key;
	char			*value;
	struct s_number	*next;
};*/

<<<<<<< HEAD
char	*ft_read_data(int fd);
char	*ft_strcat(char *dest, char *src);
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_str_is_printable(char *str);
int		ft_str_is_numeric(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_strjoin(int size, char **strs, char *sep);
=======
char *ft_read_data(int fd); // using s_datalist to store read data and finally add to a str malloced
char *ft_strcat(char *dest, char *src);
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
>>>>>>> f23a40beda0676dd484ae3f00efcf4ae73962765

#endif
