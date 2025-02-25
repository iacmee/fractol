LIBFT_S = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
       ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
       ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
       ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
       ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIBFT_SB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

PRINTF_S = ft_printf.c ft_putnbr_base.c
GET_NEXT_LINE_S = get_next_line_bonus.c get_next_line_utils_bonus.c


LIBFT_S := $(addprefix libft/, $(LIBFT_S))
LIBFT_SB := $(addprefix libft/, $(LIBFT_SB))
PRINTF_S := $(addprefix ft_printf/, $(PRINTF_S))
GET_NEXT_LINE_S := $(addprefix get_next_line/, $(GET_NEXT_LINE_S))

LIBFT_O = ${LIBFT_S:.c=.o}
LIBFT_OB = ${LIBFT_SB:.c=.o}
PRINTF_O = ${PRINTF_S:.c=.o}
GET_NEXT_LINE_O = ${GET_NEXT_LINE_S:.c=.o}

NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -O2 -Wall -Wextra -Werror

BBLK = \e[1;30m
BRED = \e[1;31m
BGRN = \e[1;92m
BYEL = \e[1;33m
BBLU = \e[1;34m
BMAG = \e[1;35m
BCYN = \e[1;36m
BWHT = \e[1;37m
CRESET = \e[0m

%.o: %.c
	@tput sc
	@printf "$(BGRN)Compiling: $< $(CRESET)"
	@${CC} ${CFLAGS} -c $< -o $@ -I.
	@tput rc
	@tput el

${NAME}: ${LIBFT_O} ${LIBFT_OB} $(PRINTF_O) $(GET_NEXT_LINE_O)
	@echo "$(BBLU)making all libft archive...$(CRESET)"
	@${LIBC} ${NAME} ${LIBFT_O} ${LIBFT_OB} $(PRINTF_O) $(GET_NEXT_LINE_O)
	@echo "$(BBLU)libft archives done!$(CRESET)"
	@echo "$(BBLU)libft.a ready to be used$(CRESET)"

all: ${NAME}

bonus: all

clean:
	@${RM} ${LIBFT_O} ${LIBFT_OB} $(PRINTF_O) $(GET_NEXT_LINE_O)
	@echo "$(BRED)libft object files cleaned!$(CRESET)"

fclean: clean
	@${RM} ${NAME} ${bonus} 
	@echo "$(BRED)libft.a archive cleaned!$(CRESET)"

re: fclean all

.PHONY : all bonus clean fclean re