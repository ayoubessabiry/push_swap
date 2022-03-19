SRCS = main.c inst.c ft_atoi.c check.c sort.c sim.c help_sim.c\
	sort2.c sort_min.c ft_split.c

SRCS_B = ./bonus/checker_bonus.c\
		./bonus/checker_utils_bonus.c\
		./bonus/get_next_line.c\
		./bonus/get_next_line_utils.c\
		check.c ft_atoi.c inst.c ft_split.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRCS:.c=.o}
OBJ_B = ${SRCS_B:.c=.o}
NAME = push_swap
NAME_B = checker

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B)

clean : 
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean : clean 
	rm -f $(NAME)
	rm -f $(NAME_B)

re : fclean all