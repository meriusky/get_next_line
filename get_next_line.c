/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/23 13:10:54 by mehernan         ###   ########.fr       */
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
int	 *readandsave(int fd, BUFFER_SIZE)//ns que meter aqui la verdad, y ni siquiera estoy seguira de lo otro
{
	static char	*line;
	char		*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	buffer = \0 // si no ponems esto da segmentation fault
	read_bytes = read(fd, buffer, BUFFER_SIZE) // el archivo, la variable (que almacena el texto), el tamano
	if (read_bytes == 0)
		return (NULL);
	if (read_bytes == -1)
		return (NULL);
	while (read_bytes != '\n' || read_bytes != 0 || read_bytes != -1)
	{
		line = ft_strjoin(buffer, line);
		return (line);
	}
	line = delete_line(line) // no estoy segura de si igualalrlo o no
// Otra funcion que muestre la primera linia cuando lo ejecutes 1a vez
char *get_next_Line(int fd)
{
	static int line; //aqui tiene que haber las lineas
	char buffer[] //a ver, por ahora se que el tamano me lo dan (BUFFER_SIZE) asi que ns que hacer con eso

	line = get_next_line_utils(line, buffer)  //ns muy bien que pasar aqui
	printf("%c",line) 
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
