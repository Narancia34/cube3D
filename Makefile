NAME 		= cub3D
FLAGS		= -Wall -Wextra -Werror -lglfw -lm -ldl -lX11 -g
LIBMLX 		= ./libs/MLX42
MY_LIBRARY	= ./libs/My_library
LIBS		= $(LIBMLX)/build/libmlx42.a $(MY_LIBRARY)/my_library.a

GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
RESET = \033[0m


SRCS = main.c ./parcing/parce_map.c

OFILES = $(SRCS:.c=.o)

all: libmlx libft $(NAME)


libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build >/dev/null && \
	make -C $(LIBMLX)/build -j4 >/dev/null

libft:
	@make --no-print-directory -C libs/My_library

$(NAME): $(LIBS) $(OFILES)
	@$(CC) $(FLAGS) $(OFILES) $(LIBS) -o $(NAME)
	@echo "$(GREEN)cube3D compiled successfully!$(RESET)"

clean:
	@rm -rf $(LIBMLX)/build
	@make --no-print-directory -C $(MY_LIBRARY) fclean
	@rm -f $(OFILES)
	@echo "$(YELLOW)Cleaning librarys and object files$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Removing cube3D$(RESET)"

re: clean all

.PHONY: all, clean, fclean, re, libmlx
