/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:46:16 by mehernan          #+#    #+#             */
/*   Updated: 2022/11/20 20:39:09 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	 *readandsave(//ns que meter aqui la verdad, y ni siquiera estoy seguira de lo otro
// Otra funcion que muestre la primera linia cuando lo ejecutes 1a vez
int	
// Otra funcion que te limpie la estatica de la linea que acabas de mostrar y devuela la statca sin la linea
// (ns como incorporar la statica con la linia menos y mandarla otra vez a la segunda para que cuando compilen otra vez muestra la segunda linea)
// Hay que hacer algo para que cuando se acaban las lineas el buffer vuelva a coger mas cosas
