NAME = recipe
CC = g++
AR = ar rcs
RM = rm -f

SRCS_DIR = SRCS
OBJS_DIR = OBJS
HEADER_DIR = HEADERS

RBSOURSES = RedBlackNode.cpp RedBlackTree.cpp RBrecipe.cpp RBmain.cpp

HTSOURSES = Hashmain.cpp HashRecipe.cpp
HTHEADERS = Hashmain.h   HashRecipe.h

SOURSES = Hashmain.cpp Reader.cpp Ingredient.cpp Recipe.cpp RedBlackNode.cpp RedBlackTree.cpp utils.cpp RBrecipe.cpp HashRecipe.cpp
HEADERS = Hashmain.h   Reader.h   Ingredient.h   Recipe.h   RedBlackNode.h   RedBlackTree.h   utils.h   RBrecipe.h   HashRecipe.h

SRCS = $(addprefix $(SRCS_DIR)/, $(SOURSES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURSES:.cpp=.o))
HDRS = $(addprefix $(HEADER_DIR)/, $(HEADERS))

all: $(NAME)

$(NAME) : $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME) -I $(HEADER_DIR)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp $(HEADER_DIR)/%.h
	$(CC) -o $@ -c $< -I $(HEADER_DIR)

HEDAERS/Reader.h : HEADERS/Recipe.h
HEADERS/Recipe.h : HEADERS/Ingredient.h
HEADERS/RedBlackTree.h : HEADERS/RedBlackNode.h
HEADERS/RedBlackNode.h : HEADERS/Ingredient.h

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

test:
	./recipe.exe

debug: $(SRCS)
	$(CC) -Wall -Wextra -Werror -g $(OBJS) -o $@
direct: $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

.PHONY: all clena fclean re test
