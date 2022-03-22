NAME = prog01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# INCLUDES = -I include/INCLUDE_PATH

# LIBS = -L lib/LIB_PATH

# EXTERNAL_LIB = EXITERNAL_LIB_PATH

BASENAMES = main Fixed

SRCS = $(addsuffix .cpp, $(BASENAMES))

OBJDIR := obj
OBJS = $(addprefix obj/, $(addsuffix .o, $(BASENAMES)))

.PHONY:	all
all:	$(NAME)

$(NAME): $(OBJDIR) $(OBJS)
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

# $(EXTERNAL_LIB):
# @make -C lib/LIB_PATH

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
