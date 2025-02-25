CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = src/
INCLUDES = includes/
OBJ_DIR = obj/
SRC = $(wildcard $(SRC_DIR)*.c) # da modificare per aggiungere file manualmente
OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
NAME = fractol
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

BBLK = \e[1;30m
BRED = \e[1;31m
BGRN = \e[1;92m
BYEL = \e[1;33m
BBLU = \e[1;34m
BMAG = \e[1;35m
BCYN = \e[1;36m
BWHT = \e[1;37m
CRESET = \e[0m

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ) $(LIBFT) 
	@echo "$(BBLU)Compiling $(NAME)$(CRESET)"
	@$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) -lXext -lX11 -lm
	@echo "$(BBLU)$(NAME) compiled!$(CRESET)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@tput sc
	@printf "$(BGRN)Compiling: $< $(CRESET)"
	@${CC} ${FLAGS} -c $< -o $@ -I$(INCLUDES)
	@tput rc
	@tput el

opt: FLAGS += -DOPT -Ofast
opt: clean all
	@echo "$(BGRN)Optimization enabled!$(CRESET)"

$(LIBFT):
	@echo "$(BCYN)Entering libft directory$(CRESET)"
	@$(MAKE) -C libft/ --no-print-directory
	@echo "$(BCYN)exit libft directory$(CRESET)"

$(MINILIBX):
	@echo "$(BCYN)Entering minilibx-linux directory$(CRESET)"
	@$(MAKE) -C minilibx-linux/ --no-print-directory
	@echo "$(BCYN)exit minilibx-linux directory$(CRESET)"

clean:
	@rm -f $(OBJ)
	@echo "$(BRED)object files cleaned!$(CRESET)"

fclean: clean
	@echo "$(BCYN)Entering libft directory for fclean$(CRESET)"
	@$(MAKE) -C libft/ fclean --no-print-directory
	@echo "$(BCYN)Exiting libft directory$(CRESET)"
	@echo "$(BCYN)Entering minilibx-linux directory for fclean$(CRESET)"
	@$(MAKE) -C minilibx-linux/ clean --no-print-directory
	@echo "$(BCYN)Exiting minilibx-linux directory$(CRESET)"
	@rm -f $(NAME)
	@echo "$(BRED)$(NAME) cleaned!$(CRESET)"
	@echo ""

re: fclean all

run: $(NAME)
	@echo "$(BGRN)Running $(NAME)$(CRESET)"
	@./$(NAME)
	@echo "$(BGRN)$(NAME) done!$(CRESET)"

norma:
	norminette $(SRC)
	norminette $(INCLUDES)*

.PHONY : all clean fclean re run norma