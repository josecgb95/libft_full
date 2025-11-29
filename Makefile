# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 08:28:12 by jose              #+#    #+#              #
#    Updated: 2025/11/29 10:20:34 by jose-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --silent -j

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

SRCS_LIBFT		=	ft_str01.c \
					ft_str02.c \
					ft_str03.c \
					ft_isalpha.c \
					ft_isalnum.c \
					ft_isdigit.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_split.c \
					ft_itoa.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c

SRCS_FT_PRINTF	=	ft_printf.c ft_printf_nbr.c ft_printf_str.c

SRCS_GNL		=	get_next_line.c get_next_line_utils.c

SRCS			=	$(SRCS_LIBFT:%=src/%) \
					$(SRCS_FT_PRINTF:%=src/ft_printf/%) \
					$(SRCS_GNL:%=src/get_next_line/%)

OBJDIR			=	objs
OBJS			=	$(SRCS:src/%.c=$(OBJDIR)/%.o)

NAME			=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I .
AR				=	ar rcs
RM				=	rm -f

all:			$(NAME)
				@printf "\033[2K\r"
				@printf "$(GREEN)✅ Compiled libft -> $(NAME)$(NC)\n"

$(OBJDIR)/%.o: src/%.c
				mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) -c $< -o $@ && \
				printf "\033[2K\r$(GREEN)Compiling:$(NC) $<"

$(NAME):		$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)
				@rm -rf $(OBJDIR)
				@printf "$(YELLOW)🧹​ Deleted objects libft$(NC)\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "$(RED)🧹 Deleted library libft$(NC)\n"

re::				fclean
re::				all

.PHONY:			all clean fclean re
