/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:14:54 by paescano          #+#    #+#             */
/*   Updated: 2023/09/13 11:52:23 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//Buffer deafult with size 42 bytes
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Get the next line object
 * 
 * @param fd file descriptor
 * @return char* line readed
 */
char	*get_next_line(int fd);
/**
 * @brief Read a file descriptor and return a string with the content
 * 
 * @param fd file descriptor
 * @param buffer_read buffer to save the content
 * @return char* string with the content
 */
char	*ft_read_fd(int fd, char *buffer_read);
/**
 * @brief Get the line object
 * 
 * @param buffer_read string with the content
 * @return char* line readed
 */
char	*ft_get_line(char *buffer_read);
/**
 * @brief Restart the buffer_read
 * 
 * @param buffer_read buffer to restart
 * @return char* buffer restarted
 */
char	*ft_restart(char *buffer_read);

// utils functions for get_next_line

/**
 * @brief find the first occurrence of the character c in the string s
 * 
 * @param s string 
 * @param c character
 * @return char* first occurrence of the character c in the string s
 */
char	*ft_strchr(char *s, int c);
/**
 * @brief Allocates memory and returns a copy of the string given as argument
 * 
 * @param s string
 * @param x size of the string
 * @return char* string duplicated
 */
char	*ft_strndup(char *s, size_t x);
/**
 * @brief join two strings
 * 
 * @param s1 string 1
 * @param s2 string 2
 * @return char* string joined
 */
char	*ft_strjoin(char *s1, char *s2);
/**
 * @brief Return a size of any string
 * 
 * @param s string
 * @return size_t size of the string
 */
size_t	ft_strlen(char *s);
/**
 * @brief copy memory area
 * 
 * @param dest destination area
 * @param src source area
 * @param n bytes to copy
 * @return void* area copied
 */
void	*ft_memcpy(void *dest, void *src, size_t n);

#endif