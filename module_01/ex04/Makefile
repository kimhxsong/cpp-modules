NAME = ft_sed

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

BASENAMES = main

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASENAMES)))

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
		@$(RM) -r $(OBJDIR)

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
