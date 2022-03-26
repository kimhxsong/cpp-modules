NAME = tests

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

INCLUDES = -I include/INCLUDE_PATH

BASENAMES = tests Account

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASENAMES)))

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
		sh test.sh

$(OBJDIR)/%.o: %.cpp
		@$(CC) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
		@mkdir $(OBJDIR)

.PHONY:	clean
clean:
		@$(RM) -r $(OBJDIR) result.txt

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
