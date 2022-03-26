NAME = brain

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

BASENAMES = main

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASENAMES)))

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(EXTERNAL_LIB):
		@make -C lib/LIB_PATH

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
