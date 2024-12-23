/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srapaila <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:14:12 by srapaila          #+#    #+#             */
/*   Updated: 2024/11/22 18:14:16 by srapaila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_initiate_vars(size_t *i, int *j, int *start_word)
{
	*i = 0;
	*j = 0;
	*start_word = -1;
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		start_word;

	ft_initiate_vars(&i, &j, &start_word);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start_word < 0)
			start_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start_word >= 0)
		{
			res[j] = fill_word(s, start_word, i);
			if (!(res[j]))
				return (ft_free(res, j));
			start_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

/*
int   main(void)
{
    const char *s1 = "Ciao sono un cane";
    const char *s2 = "   leading and trailing spaces   ";
    const char *s3 = "only_one_word";
    const char *s4 = "";
    const char *s5 = ";;;;;split;by;semicolon;;;;;";
    char **ptr;
    int i;
    
    i = 0;
    ptr = ft_split(s1,' ');
    for (i = 0; ptr[i]; i++)
        printf("Word %d: %s\n", i, ptr[i]);
    printf("\n");
    free(ptr);
    ptr = ft_split(s2,' ');
    for (i = 0; ptr[i]; i++)
        printf("Word %d: %s\n", i, ptr[i]);
    printf("\n");
    free(ptr);
    ptr = ft_split(s3,' ');
    for (i = 0; ptr[i]; i++)
        printf("Word %d: %s\n", i, ptr[i]);
    printf("\n");
    free(ptr);
    ptr = ft_split(s4,' ');
    for (i = 0; ptr[i]; i++)
        printf("Word %d: %s\n", i, ptr[i]);
    printf("\n");
    free(ptr);
    ptr = ft_split(s5,';');
    for (i = 0; ptr[i]; i++)
        printf("Word %d: %s\n", i, ptr[i]);
    printf("\n");
    free(ptr);
    return (0);
}*/
