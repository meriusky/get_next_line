/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/25 21:53:07 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//funcion principal que hara lo ultimo
char	*get_next_line(int fd)
{
	char *line;
	char buffer[11];
	int read_bytes;

	line = ft_strdup("");

	//La funcion read, aparte de escribir en el buffer, devuelve un numero int
	//Ese numero int corresponde a:
	//numero de bits que a leido y escrito en el buffer
	//o 0 en caso de que hayamos llegado ya al final del archivo
	//o -1 en caso de que se haya producido un error, de escritura/lectura
	read_bytes = read(fd, buffer, 10);
	buffer[read_bytes] = '\0';
	line = ft_strjoin(line, buffer);
	return(line);
}

// Una funcion que lea y guarde la info (con una estatica) y que este el buffer tambien (delimitar lineas)
char	 *readandsave(int fd, char *line)
{
	char		*buffer;
	int		read_bytes; //esta variable sirve para guardar el nº de bytes y cosicas

	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	buffer[0] = '\0'; // si no ponems esto da segmentation fault
	while (ft_searchchar(fd, '\n') != NULL)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE) // el archivo, la variable (que almacena el texto), el tamano
		if (read_bytes == 0)
			return (NULL);
		if (read_bytes == -1)
			return (NULL);
		line = ft_strjoin(buffer, line);
	}
	return (line);
	 	
// El get next line lo puedo usar para llamar a otras funciones y puede que para printear las frases pero bueno, esta por ver
char *get_next_Line(int fd)
{
	static char	*line; 

	line = readandsave(fd, BUFFER_SIZE);
	// aqui deberia haber algo que te devuelva la linea que vas a printear, o de alguna manera hacerlo
	printf("%c",line) // que printee hasta la linea , quizas es mejor mandarlo a cortar, pero creo eso viene despues para cuando elimines eso
	delete_line(line);
	
}
// Otra funcion que te limpie la estatica de la linea que acabas de mostrar y devuela la statca sin la linea
char	delete_line(const char *line)
{
	int count;

	count = 0;
	while (line[count] != '\n')
		count++;
	line = ft_substr(line, (count + 1), (line - count);// start es dodne cortas y la longitud es desde el punto donde ha encontrado \n mas uno porque queremos que lo pase
	//aqui hay que hacer que lo elmine
}
// (ns como incorporar la statica con la linia menos y mandarla otra vez a la segunda para que cuando compilen otra vez muestra la segunda linea)
// Hay que hacer algo para que cuando se acaban las lineas el buffer vuelva a coger mas cosas
