/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yijin <yijin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:07:25 by yijin             #+#    #+#             */
/*   Updated: 2022/07/24 22:07:27 by yijin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

#define HASHSIZE 101
static struct s_nlist *hashtab[HASHSIZE]; 

unsigned	hash(char *s)
{
	unsigned hashval;

	hashval = 0;
	while(*s != '\0')
	{
		hashval = *s + 31 * hashval;
		s++;
	}
	return hashval % HASHSIZE;
}

struct s_nlist *lookup(char *s)
{
	struct s_nlist *np;

	np = hashtab[hash(s)];
	while(np != NULL)
	{
		if (strcmp(s, np->name) == 0)
			return np; 
		np = np->next;
	}
	return NULL;	   
}

char *ft_strdup(char *);
struct s_nlist *install(char *name, char *defn)
{
	struct s_nlist *np;
	unsigned hashval;
	if ((np = lookup(name)) == NULL)
	{ 
		np = (struct s_nlist *)malloc(sizeof(*np));
		if (np == NULL || (np->name = ft_strdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else						
		free((void *)np->defn); 
	if ((np->defn = ft_strdup(defn)) == NULL)
		return NULL;
	return np;
}

char *ft_strdup(char *s) 
{
	char *p;
	p = (char *)malloc(strlen(s) + 1); 
	if (p != NULL)
		strcpy(p, s);
	return p;
}
