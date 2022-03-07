NAME = megaphone
CC = c++
RM = rm -rf
INCLUDES = -I./includes/
CFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN_FILES = megaphone

SRCS = $(addsuffix .cpp, $(MAIN_FILES))
OBJS = $(addsuffix .o, $(MAIN_FILES))

CR_LIB := -L ${shell brew --prefix criterion}/lib -lcriterion
CR_INCLUDE := -I ${shell brew --prefix criterion}/include/

GREEN = \033[0;32m
RED = \033[0;31m
ORANGE = \033[0;33m
RESET = \033[0m

all: $(NAME)

${NAME}: ${OBJS}
	@echo "$(GREEN)$(NAME) START$(RESET)"
	@echo "$(RESET)Compiling ${NAME} to root."
	@${CC} ${CFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}
	@echo "$(GREEN)DONE$(RESET)"

${OBJS}: ${SRCS}
	@${CC} ${CFLAGS} ${INCLUDES} -c ${SRCS}

clean:
	@echo "$(RESET)Cleaning your .o files$(RESET)"
	@${RM} $(OBJS)
	@echo "$(RED)clean DONE$(RESET)"

fclean: clean
	@echo "$(RESET)Removing $(NAME)"
	@${RM} $(NAME)
	@${RM} test
	@echo "$(RED)fclean DONE$(RESET)"

test: ${NAME}
	@echo "\n$(ORANGE)$(NAME) RUN TEST$(RESET)"
	@c++ -o test *.cpp ${CR_LIB} ${CR_INCLUDE} -std=c++11 -D TEST
	@./test
	@make fclean > /dev/null
	@echo "$(ORANGE)DONE$(RESET)"

re: fclean all

.PHONY:	all clean fclean re
