NAME = ClapTrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

INCLUDES = -I include/

BASENAMES = main ClapTrap

SRCS = $(addsuffix .cPP, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addsuffix .o, $(BASENAMES))

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
		@mkdir $(OBJDIR)

.PHONY:	clean
clean:
		@$(RM) $(OBJS)

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
