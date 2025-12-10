# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-car <jose-car@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 08:28:12 by jose              #+#    #+#              #
#    Updated: 2025/12/10 16:45:44 by jose-car         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --silent -j

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m

SRCS_LIBFT		=	ft_str_01.c \
					ft_str_02.c \
					ft_str_03.c \
					ft_is.c \
					ft_mem_01.c \
					ft_mem_02.c \
					ft_put.c \
					ft_parse.c \
					ft_alloc.c \
					ft_to_low_upe.c \
					ft_split.c \
					ft_lst_01.c \
					ft_lst_02.c

SRCS_FT_PRINTF	=	ft_printf.c ft_printf_nbr.c ft_printf_str.c

SRCS_GNL		=	get_next_line.c get_next_line_utils.c

SRCS			=	$(SRCS_LIBFT:%=src/%) \
					$(SRCS_FT_PRINTF:%=src/ft_printf/%) \
					$(SRCS_GNL:%=src/get_next_line/%)

OBJDIR			=	objs
OBJS			=	$(SRCS:src/%.c=$(OBJDIR)/%.o)

NAME			=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
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
				@printf "$(YELLOW)🧹​ Removed objects libft$(NC)\n"

fclean:			clean
				@$(RM) $(NAME)
				@printf "$(RED)🧹 Removed library libft.a$(NC)\n"

re::				fclean
re::				all

.PHONY:			all clean fclean re
