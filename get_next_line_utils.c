/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnascime <mnascime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:18:24 by mnascime          #+#    #+#             */
/*   Updated: 2022/10/23 13:35:06 by mnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	f;

	i = 0;
	f = 0;
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[f] != '\0')
	{
		ptr[i++] = s2[f];
		if (s2[f] == '\n')
			break ;
		f++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

int	clean_buf(char *buffer)
{
	int	i;
	int	f;

	i = 0;
	f = -1;
	while (buffer[i] != '\0')
	{
		if (f != -1)
			buffer[f++] = buffer[i];
		if (buffer[i] == '\n' && f == -1)
			f++;
		buffer[i++] = 0;
	}
	return (f == -1);
}
