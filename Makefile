SRCS 		= 	./main.c \

SRC			= 	$(addprefix $(DIR), $(SRCS))

DIR			= 	src/

OBJS 		= 	${SRC:.c=.o}

NAME 		= 	push_swap

AR 			= 	ar rcs

GCC			= 	gcc

RM 			= 	rm -f

CFLAGS 		= 	-g -fsanitize=address -Wall -Wextra -Werror

LBFT_PATH	= 	./libft/

FRAMLIBS	= 	-L ${LBFT_PATH} -lft

all: 		$(NAME)
			
.c.o:
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME): 	$(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
			${RM} ${OBJS}
			@$(MAKE) -C $(LBFT_PATH) clean

fclean: 	clean
			${RM} ${NAME}
			@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY: 	all clean fclean re