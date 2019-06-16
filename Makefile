NAME = players/fmerding.filler

NAME2 = visual

SRC_PATH = src

SRC_NAME = main.c read.c init.c algo.c

SRC2_NAME = visual/visual.c

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft  -L /usr/local/include/

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

SDLFLAGS =  $(SDLINCL) -L/Users/fmerding/.brew/Cellar/sdl2/2.0.9_1/lib -lSDL2

SDLINCL = -I /Users/fmerding/.brew/Cellar/sdl2/2.0.9_1/include

HEADER_PATH = includes/

HEADER_NAME = filler.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean
	$(MAKE) all

visu:
	gcc $(SRC2_NAME) $(SDLFLAGS) $(CPPFLAGS) $(LDFLAGS) -o visual/$(NAME2)

revisu:
	rm -f $(SRC2_NAME:.c=.o)
	rm -f $(SRC2_NAME:.c=.d)
	make visu

norme:
	norminette $(SRC)
	norminette $(INCLUDES)

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
