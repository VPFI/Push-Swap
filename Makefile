# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vperez-f <vperez-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 13:59:42 by vperez-f          #+#    #+#              #
#    Updated: 2024/03/01 16:02:19 by vperez-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES = push_swap.c stack_utils.c push_swap_utils.c push_swap_utils2.c sorting_m.c

OFILES = $(CFILES:%.c=%.o)

OBJ = $(OFILES)

PATH_LFT = libft/libft.a

CFLAGS = -Wall -Wextra 

CC = cc

ARLIB = ar rc

RM = rm -f

NAME = push_swap

%.o: %.c  Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OFILES) 
	make -C libft/
	$(CC) $(CFLAGS) $(OFILES) $(PATH_LFT) -o $(NAME)

debug: $(OFILES) 
	make -C libft/
	$(CC) -g $(CFLAGS) $(OFILES) $(PATH_LFT) -o $(NAME)

clean:
	make clean -C libft 
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C libft
	$(RM) $(NAME)

re:	fclean all
	make re -C libft

.PHONY = all clean fclean re