NAME = megaphone
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

BASENAME = megaphone

SRCS = $(addsuffix .cpp, $(BASENAME))
OBJS = $(addsuffix .o, $(BASENAME))

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
	@${CC} ${CXXFLAGS} ${INCLUDES} ${OBJS} -o ${NAME}
	@echo "$(GREEN)DONE$(RESET)"

${OBJS}: ${SRCS}
	@${CC} ${CXXFLAGS} ${INCLUDES} -c ${SRCS}

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

.PHONY:	all clean fclean re test
