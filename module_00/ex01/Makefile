NAME = poby
CC = c++
RM = rm -r
CFLAGS = -Wall -Wextra -Werror

ifdef TEST
	CFLAGS += -g3
endif

FILENAMES = main \
			PhoneBook \
			PhoneContact

SRCS = $(addsuffix .cpp, $(FILENAMES))
OBJS = $(addsuffix .o, $(FILENAMES))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY:	all
all:	$(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)$(NAME) START$(RESET)"
	@echo "$(RESET)Compiling ${NAME} to root."
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}
	@echo "$(GREEN)DONE$(RESET)"

%.o: %.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY:	clean
clean:
	@echo "$(RESET)Cleaning your .o files$(RESET)"
	@${RM} $(OBJS)
	@echo "$(RED)clean DONE$(RESET)"

.PHONY:	fclean
fclean:	clean
	@echo "$(RESET)Removing $(NAME)"
	@${RM} $(NAME)
	@echo "$(RED)fclean DONE$(RESET)"

.PHONY:	re
re:		fclean all
