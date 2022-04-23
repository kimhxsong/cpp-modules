NAME = convert

CC = c++
CXXFLAGS = -g -Wall -Wextra -Werror -pedantic -std=c++98

BASENAMES = main Convert

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(BASENAMES)))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJS): | $(OBJDIR)
$(OBJDIR):
	@mkdir $(OBJDIR)

.PHONY: clean
clean:
	@$(RM) -r $(OBJDIR) test

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)

.PHONY: re
re: fclean all
