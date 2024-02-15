
NAME := fractol

OBJS := main.o math.o event.o

MINILIBX_PATH = ./minilibx_opengl_20191021
LIBMLX = $(MINILIBX_PATH)/libmlx.a

FLAGS := -Wall -Werror -Wextra -I/opt/X11/include
LDFLAGS := -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

RED = \033[1;31m
LIGHT_BLUE = \033[1;94m
PURPLE = \033[1;35m
ORANGE = \033[0;33m
DEFAULT = \033[0m

all: $(LIBMLX) $(NAME)

$(LIBMLX):
	$(MAKE) -C $(MINILIBX_PATH)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(LIBMLX)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)
	@echo "$(PURPLE)$(NAME) created!$(DEFAULT)"

clean:
	@rm -f $(OBJS)
	$(MAKE) -C $(MINILIBX_PATH) clean
	@echo "$(RED)object files deleted!$(DEFAULT)"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_PATH) fclean
	@echo "$(ORANGE) all deleted!$(DEFAULT)"

re: fclean all
