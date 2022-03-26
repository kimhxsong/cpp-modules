NAME = Fixed00

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

BASENAMES = main Fixed

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := obj
OBJS = $(addprefix obj/, $(addsuffix .o, $(BASENAMES)))

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		@$(CC) $(INCLUDES) $(CXXFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
		@mkdir $(OBJDIR)

.PHONY:	clean
clean:
		@$(RM) -r $(OBJDIR)

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
