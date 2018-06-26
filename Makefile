# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 20:06:29 by abiestro          #+#    #+#              #
#    Updated: 2018/06/26 20:11:52 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME            = fdf
CC              = gcc
CFLAGS          = -Wall -Wextra -Werror
DEBUG_FLAGS		= -fsanitize=address

PATH_INCLUDES   = ./includes
PATH_SOURCES    = ./srcs
PATH_OBJS       = ./objs
PATH_LIBFT		= ./tools/libft/
PATH_MLX		= ./tools/minilibx/

FRAMEWORK		= -framework OpenGL -framework AppKit

ITEMS			= main \
				  get_next_line \
				  parse \
				  draw \
				  bresenham \
				  key \
				  info

OBJS            = $(addprefix $(PATH_OBJS)/, $(ITEMS:=.o))

all:$(NAME)

$(NAME):$(OBJS)
	@echo "objects builded..."
	@echo "\033[32mCreating libft...!\033[0m"
	@make -C $(PATH_LIBFT)
	@echo "\033[32mCreating minilibx...!\033[0m"
	@make -C $(PATH_MLX)
	@gcc $(CFLAGS) -pedantic -o $(NAME) $(OBJS) $(PATH_LIBFT)libft.a -I $(PATH_INCLUDES) -I $(PATH_MLX) -L tools/ -L $(PATH_MLX) -lmlx $(FRAMEWORK)
	@echo "\033[32mfdf is ready!\033[0m"


$(OBJS) : |$(PATH_OBJS)

$(PATH_OBJS) :
	@mkdir objs

$(PATH_OBJS)/%.o : $(PATH_SOURCES)/%.c
	@$(CC) -c $(CFLAGS)  $<  -o $@ -I $(PATH_INCLUDES) -I $(PATH_LIBFT) -I $(PATH_MLX)
	@echo "builded -->" $@

clean:
	@rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)
	make clean -C $(PATH_MLX)
	@echo "objects --->removed 😇 "

fclean: clean
	make fclean -C $(PATH_LIBFT)
	@rm -f $(NAME)
	@echo $(NAME) "    --->removed 😇 "

re: fclean all
