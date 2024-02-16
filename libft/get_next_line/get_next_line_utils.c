/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:01:19 by cdutel            #+#    #+#             */
/*   Updated: 2023/12/20 09:42:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*Fonction ft_malloc_line : fonction qui permet
de malloc la bonne taille pour la prochiane ligne du
au manque de place dans la fonction précédente.*/
static char	*ft_malloc_line(t_my_list *temp)
{
	char	*new_line;
	int		i;
	int		j;

	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->data[i])
		{
			if (temp->data[i] == '\n')
			{
				j++;
				break ;
			}
			j++;
			i++;
		}
		temp = temp->next;
	}
	new_line = malloc(sizeof(char) * (j + 1));
	return (new_line);
}

/*Fonction ft_new_line : quand un '\n' a été trouvé par la
fonction ft_check_temp, cette fonction permet de récupérer
tous les caractères jusqu'au '\n' pour pouvoir retourner
le contenu de la ligne.*/
char	*ft_new_line(t_my_list *temp)
{
	char	*new_line;
	int		i;
	int		j;

	new_line = ft_malloc_line(temp);
	if (!new_line || !temp)
		return (NULL);
	j = 0;
	while (temp)
	{
		i = 0;
		while (temp->data[i])
		{
			if (temp->data[i] == '\n')
			{
				new_line[j++] = temp->data[i];
				break ;
			}
			new_line[j++] = temp->data[i++];
		}
		temp = temp->next;
	}
	new_line[j] = '\0';
	return (new_line);
}

/*Fonction ft_new_temp : une fois qu'une ligne a été trouvé,
cette fonction permet de mettre à jour la liste chainnée static.
Au prochain appel de get_next_line, la liste temp contiendra
le reste des caractères qui avaient été lu et qui se trouvaient
après le 1er '\n'.*/
void	ft_new_temp(t_my_list **temp)
{
	int			i;
	int			j;
	t_my_list	*new_temp;
	t_my_list	*last;

	new_temp = malloc(sizeof(t_my_list));
	if (!temp || !new_temp)
		return ;
	new_temp->next = NULL;
	last = ft_get_last(*temp);
	i = 0;
	while (last->data[i] && last->data[i] != '\n')
		i++;
	if (last->data[i] && last->data[i] == '\n')
		i++;
	new_temp->data = malloc(sizeof(char) * (ft_stlen(last->data) - i + 1));
	if (!new_temp->data)
		return ;
	j = 0;
	while (last->data[i])
		new_temp->data[j++] = last->data[i++];
	new_temp->data[j] = '\0';
	ft_free_list(*temp);
	*temp = new_temp;
}

t_my_list	*ft_get_last(t_my_list *temp)
{
	t_my_list	*last;

	last = temp;
	while (last && last->next)
		last = last->next;
	return (last);
}

int	ft_stlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
