# Makefile for the libftprintf library
# This Makefile compiles the library from the source files
# and creates an archive file named libftprintf.a
# It also includes rules for cleaning up object files and the library
# and for rebuilding everything from scratch.
# Usage:
# - `make` to compile the library
# - `make clean` to remove object files
# - `make fclean` to remove object files and the library
# - `make re` to clean and then compile everything again

# Name of the library
NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

# Directories paths
SRCS_DIR = srcs
UTILS_DIR = srcs/utils
FORMAT_DIR = srcs/formats

# Source files
SRCS =	$(SRCS_DIR)/ft_printf.c			\
		$(FORMAT_DIR)/char_format.c		\
		$(FORMAT_DIR)/number_format.c	\
		$(FORMAT_DIR)/unknown_format.c	\
		$(UTILS_DIR)/utils.c			

# Object files
OBJS = $(SRCS:.c=.o)

# ====== Rules to compile the library ======
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re