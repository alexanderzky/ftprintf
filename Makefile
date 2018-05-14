# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 13:57:40 by ozalisky          #+#    #+#              #
#    Updated: 2018/05/13 21:34:28 by ozalisky         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

SRC = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c \
		libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c \
		libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c \
		libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c \
		libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c \
		libft/ft_putstr_fd.c libft/ft_strcat.c \
		libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c \
		libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c \
		libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c \
		libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c \
		libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c \
		libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c \
		libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strsplit.c libft/ft_strstr.c \
		libft/ft_strsub.c libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_memcpy_bkw.c libft/ft_iscntrlspace.c \
		libft/ft_islower.c libft/ft_issign.c libft/ft_isupper.c libft/ft_iscntrlch.c libft/ft_isspace.c libft/ft_nbr_lngth.c libft/ft_lstnew.c \
		libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_arrdel.c libft/ft_has_ch.c libft/ft_words.c \
		srcs/ft_printf.c srcs/ft_itoa_base.c srcs/ft_uformat.c srcs/ft_xformat.c srcs/ft_diformat.c srcs/ft_influences.c \
	    srcs/ft_checkers.c srcs/ft_adders.c srcs/ft_lists.c srcs/ft_pformat.c srcs/ft_cformat.c srcs/ft_sformat.c srcs/ft_oformat.c srcs/ft_buffer_add_wrong.c srcs/ft_o_additional.c srcs/ft_influence_chars.c \
	    srcs/ft_wcformat.c srcs/ft_u_additional.c srcs/ft_p_additional.c srcs/ft_additional.c srcs/ft_di_minus.c srcs/ft_di_additional.c srcs/ft_swformat.c srcs/ft_ws_minus.c srcs/ft_ws_plus.c srcs/ft_s_plus.c \
	    srcs/ft_length_funcs.c srcs/ft_x_additional.c srcs/ft_x_minus.c srcs/ft_itoa_base_dec.c

OFILES = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $@ $^
	ranlib $@

clean:
	rm -f $(OFILES)
	rm -f *~

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re