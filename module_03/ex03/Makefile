NAME = ClapTrap

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

INCLUDES = -I include/

BASENAMES = main ClapTrap ScavTrap FragTrap DiamondTrap

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addsuffix .o, $(BASENAMES))

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
		@$(RM) $(OBJS)

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
