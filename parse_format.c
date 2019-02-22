/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/16 16:18:11 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncat_percent(char *restrict s1, const char *restrict s2, size_t n)
{
    size_t		i;
    size_t		len;

    i = 0;
    len = ft_strlen(s1);
    while (s2[i] && i < n)
    {
        while (s2[i] == '%' && i < n)
        {
            s1[len++] = '%';
            i += 2;
        }
        if (i >= n)
            break;
        s1[len] = s2[i];
        i++;
        len++;
    }
    s1[len] = '\0';
    return (s1);
}

size_t     find_percent(const char *str)
{
    size_t i;

    i = 0;
    while (((str[i] != '%') || (str[i] == '%' && str[i + 1] == '%')) && str[i])
    {
        i++;
    }
    return (i);

}
char    *get_str_before_percent(const char *format, char *old_output)
{
    char    *new_str;
    size_t  size_format;

    size_format = find_percent(format);
    new_str = ft_strnew(size_format + ft_strlen(old_output));
    new_str = ft_strcpy(new_str, old_output);
    new_str = ft_strncat_percent(new_str, format, size_format);
    ft_strdel(&old_output);
    return (new_str);
}

void    del_tprint(t_print **node)
{
    free(*node);
    *node = NULL;
}

t_print *init_tprint()
{
    t_print *node;

    if (!(node = (t_print *)malloc(sizeof(t_print))))
        return(NULL);
    node->flag = '1'; // if at the end of function '1', this flag does not exist
    node->width = -1; // -2 is *
    node->precision = -1; //0 - tochka, -2 is *
    node->size = ft_strnew(0);
    node->type = '0'; // if at the end of function '0' it is this flag does not exist

    return node;
}

