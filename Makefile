NAME 		= cub3D
CFLAGS		= -Wall -Wextra -Werror -g
LIBMLX 		= ./libs/MLX42
MY_LIBRARY	= ./libs/My_library
LIBS		= $(LIBMLX)/build/libmlx42.a $(MY_LIBRARY)/my_library.a

UNAME = $(shell uname -s)
BREW_PATH = $(shell brew --prefix)

ifeq ($(UNAME), Linux)
	LDFLAGS = -lglfw -lm -ldl -lX11
endif
ifeq ($(UNAME), Darwin)
	CFLAGS += -I$(BREW_PATH)/include
	LDFLAGS = -L$(BREW_PATH)/lib -framework Cocoa -framework OpenGL -framework IOKit -lglfw
endif

GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
YELLOW = \033[0;33m
CYAN = \033[0;36m
RED = \033[0;31m
RESET = \033[0m


SRCS =	$(shell ls ./parsing/*.c) \
		$(shell ls ./error_handling/*.c) \
		$(shell ls ./game_mechanics/*.c) \
		$(shell ls ./ray_casting_engine/*.c) \
		./main.c ./update_game.c \

OFILES = $(SRCS:.c=.o)

all: libmlx libft $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build >/dev/null
	@cmake --build $(LIBMLX)/build -j4 >/dev/null

libft:
	@make --no-print-directory -C libs/My_library

$(NAME): $(LIBS) $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) $(LIBS) $(LDFLAGS) -o $(NAME)
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
