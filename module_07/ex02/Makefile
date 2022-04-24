NAME = test

CC = c++
CXXFLAGS = -g -Wall -Wextra -Werror -pedantic -std=c++98

BASENAMES = main

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

test2: $(SRCS)
		@$(CC) $(SRCS) -D DEBUG -o test

.PHONY: clean
clean:
	@$(RM) -r $(OBJDIR)

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME) result.txt

.PHONY: re
re: fclean all
