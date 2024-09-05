/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagarci <clagarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:47:43 by clagarci          #+#    #+#             */
/*   Updated: 2024/03/14 15:14:34 by clagarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (src[length] != '\0')
		length++;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (length);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&ptr[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	const char	*aux;
	size_t		len;

	len = 0;
	if (!s1)
		return (NULL);
	aux = s1;
	while (s1[len] != '\0')
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	while (len-- > 0)
		ptr[len] = aux[len];
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*substr;

	if (!s)
		return (NULL);
	length = 0;
	while (s[length] != '\0')
		length++;
	if (start >= length)
		ft_strdup("");
	length = 0;
	while (s[start + length] != '\0')
		length++;
	if (len > length)
		len = length;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length_s1;
	size_t	length_s2;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length_s1 = 0;
	length_s2 = 0;
	while (s1[length_s1] != '\0')
		length_s1++;
	while (s2[length_s2] != '\0')
		length_s2++;
	concat = (char *)malloc(sizeof(char) * (length_s1 + length_s2 + 1));
	if (concat == NULL)
		return (NULL);
	ft_strlcpy(concat, s1, length_s1 + 1);
	ft_strlcpy(concat + length_s1, s2, length_s1 + length_s2 + 1);
	return (concat);
}
