/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:48:02 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/24 17:27:32 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// funcion para busca el /n //pero tiene que decir en que posicion esta o algo
char	*ft_searchchar(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != '\0' && (s[count] != (unsigned char)c))
		count++;
	if ((unsigned char)c == s[count])
		return ((char *)&s[count]);
	else if (c == '\0')
		return ((char *)&s[count]);
	return (NULL);
}
// la funcion que corta 
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	count2;
	char	*result;

	count = 0;
	count2 = 0;
	while (s[count] != '\0')
		count++;
	if (len > count - start)
		result = malloc(sizeof(char) * (count - start + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start <= count && s[start] != '\0' && count2 < len)
	{
		result[count2] = s[start];
		start++;
		count2++;
	}
	result[count2] = '\0';
	return (result);
}
//Hay que copiar la info del buffer a la statica, pa eso esta.
 char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	size_t	count;
	size_t	size_s1;
	size_t	size_s2;

	count = 0;
	if (!s1)
		s1 = "";
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	snew = (char *)malloc (sizeof(char) * (size_s1 + size_s2 + 1));
	if (snew == NULL)
		return (NULL);
	while (count++ <= size_s1)
		snew[count - 1] = s1[count - 1];
	count = 0;
	while (count <= size_s2)
	{
		count++;
		snew[size_s1 + count - 1] = s2[count - 1];
	}
	return (snew);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
//funcion que muestre una linea, quizas no es necesario pero aqui se queda 
//char *show_line()
//{
//	ññ
//}
