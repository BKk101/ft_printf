/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:24:34 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 17:15:08 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_format
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			precision;
	int			length;
	int			printlen;
	char		type;
	const char	*address;
}				t_format;

int				ft_printf(const char *format, ...);
t_format		check_format(const char *arg, va_list ap, t_format f_info);
int				classify_type(char c, va_list ap, t_format f_info);
int				write_fc(va_list ap, t_format f_info);
int				write_fs(va_list ap, t_format f_info);
int				write_fp(va_list ap, t_format f_info);
int				write_fdi(va_list ap, t_format f_info);
int				write_fu(va_list ap, t_format f_info);
int				write_fxx(va_list ap, t_format f_info, char c);
int				write_felse(char c, t_format f_info);
char			*apply_precision_num(char *str1, t_format f_info);
char			*apply_precision_str(char *str1, t_format f_info);
char			*apply_plus_space_negative(long long num,
char *str, t_format f_info);
char			*apply_minus_zero_width(int size, char *str, t_format f_info);
int				ft_strlen(const char *s);
int				ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_ischarset(char str, char *charset);
int				ft_atoi(const char *str);
int				ft_numlen(int num);
void			*ftt_memset(void *s, int c, size_t n);
void			ft_multifree(int args, ...);
char			*ft_strjoin(t_format f_info, char const *s1, char const *s2);
char			*ftt_itoa(int n);
char			*ftt_uitoa(unsigned int n);

#endif
