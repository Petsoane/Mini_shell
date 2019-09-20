# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcajee <tcajee@student.wethinkcode.co.za>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 13:11:02 by tcajee            #+#    #+#              #
#    Updated: 2019/09/20 12:22:04 by anben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project file
NAME		= Minishell

# Project builds and dirs
SRCDIR		= ./srcs/
SRCNAMES	= builtins.c \
			  env_functions.c \
			  external_commands.c \
			  helper_functions.c \
			  input.c \
			  memory_functions.c \
			  set_env_functions.c \
			  shell.c \

# Progress bar
LOAD = ./load.sh

# Colors
RED	   = \033[0;31m
GREEN  = \033[0;32m
YELLOW = \033[0;33m
NC     = \033[0m


SRC			= $(addprefix $(SRCDIR), $(SRCNAMES))
BUILDDIR	= ./build/
BUILDOBJS	= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR		= ./libft/
LIBFT		= ./libft/libft.a
LIBINC		= ./libft

# Optimization and Compiler flags and commands
CC			= clang
CFLAGS		= -Wall -Werror -Wextra

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	@echo "$(YELLOW)Compiling: $(NAME)"
	@bash $(LOAD)
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBINC) -o $@ -c $<

# Project file rule
$(NAME): $(BUILDOBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT) -lreadline
	@echo "$(GREEN)Compiled: $(NAME)$(NC)"

# Libft rule
$(LIBFT):
	@make -C $(LIBDIR)

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@make -C $(LIBDIR) clean

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
