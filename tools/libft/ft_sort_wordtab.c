/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordstab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:29:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/11 11:35:44 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_siz_table(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		ft_sort_wordtab(char **tab)
{
	int		i;
	char	*tmp;
	int		size;

	size = ft_siz_table(tab);
	i = 1;
	while (i < size)
	{
		if (i < 1)
			i++;
		if (ft_strcmp(tab[i], tab[i - 1]) < 0)
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i--;
		}
		else
			i++;
	}
}
