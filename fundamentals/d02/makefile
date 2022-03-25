NAME = TARGET_NAME

CC = COMPILER
CXXFLAGS = -Wall -Wextra -Werror

#ifdef TEST
		$(CXXFLAGS) += -g3
#endif

INCLUDES = -I include/INCLUDE_PATH

LIBS = -L lib/LIB_PATH

EXTERNAL_LIB = EXITERNAL_LIB_PATH

BASENAMES = BASE_FILE_NAME_LIST

SRCS = $(addsuffix .SUFFIX, $(BASENAMES))

OBJDIR := ./obj
OBJS = $(addsuffix .o, $(BASENAMES))

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
		@$(RM) $(OBJS)

.PHONY:	fclean
fclean: clean
		@$(RM) $(NAME)

.PHONY:	re
re:		fclean all
