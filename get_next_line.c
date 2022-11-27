/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/27 21:19:30 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//funcio que te devuelve la linea que vas a printear
char	*show_newline(char *line)
{
	int		i;
	int		count;
	char	*newline;

	i = 0;
	count = 0;
	while (line[count] != '\n')// while solo para el malloc, hay que gurdar cuantos char va a haber, pereza :(
		count++;
	newline = malloc(sizeof(char)*(count + 2));// +2 por el \n y \0
	while(i <= count)// que pasa si no hay un \n, no debe hace nada.
	{
		newline[i] = line[i];
		i++;
	}
	newline[i] = '\0';
	return (newline);
}
// Una funcion que lea y guarde la info (con una estatica) y que este el buffer tambien (delimitar lineas)
char	*readandsave(int fd, char *line)
{
	char	*buffer;
	int		read_bytes; //esta variable sirve para guardar el nº de bytes y cosicas

	buffer =  malloc(sizeof(char)*(BUFFER_SIZE + 1));
	buffer[0] = '\0'; // si no ponems esto da segmentation fault
	while (searchchar(buffer, '\n') == NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE); // el archivo, la variable (que almacena el texto), el tamano
		if (read_bytes == 0)
			return (line);
		if (read_bytes == -1)
			return (NULL);
		line = strjoin(line, buffer);
	}
	return (line);
}
// Otra funcion que te limpie la estatica de la linea que acabas de mostrar y devuela la statca sin la linea
char	*delete_line(char *line)
{
	int	count;

	count = 0;
	while (line[count] != '\n')
		count++;
	line = cutstr(line, (count + 1), (ft_strlen(line) - count));// start es dodne cortas y la longitud es desde el punto donde ha encontrado \n mas uno porque queremos que lo pase
	//aqui hay que hacer que lo elmine
	return (line);
}
// El get next line lo puedo usar para llamar a otras funciones y puede que para printear las frases pero bueno, esta por ver
char *get_next_line(int fd)
{
	static char	*line;
	char		*newline;

	line = readandsave(fd, line);
	newline = show_newline(line);
//	printf("%s", newline);//nueva linea que solo contiene hasta el \n
	line = delete_line(line);// con las staticas hay que "="asignar el nuevo valor  cuando las mandas a otra funcion
	return (newline);
}
