NAME = recipe
CC = g++
RM = rm -f

SRCS_DIR = SRCS
OBJS_DIR = OBJS
HEADER_DIR = HEADERS

RBSOURSES = RedBlackNode.cpp RedBlackTree.cpp RBrecipe.cpp RBmain.cpp


ifeq ($(MAKECMDGOALS), )
	MAIN = Arraymain.cpp
	MAIN_H = Arraymain.h
endif

ifeq ($(MAKECMDGOALS), all)
	MAIN = Arraymain.cpp
	MAIN_H = Arraymain.h
endif

ifeq ($(MAKECMDGOALS), rb)
	MAIN = RBmain.cpp
	MAIN_H = RBmain.h
endif

ifeq ($(MAKECMDGOALS), hs)
	MAIN = Hashmain.cpp
	MAIN_H = Hashmain.h
endif

SOURSES = $(MAIN)   Reader.cpp Ingredient.cpp Recipe.cpp RedBlackNode.cpp RedBlackTree.cpp utils.cpp RBrecipe.cpp HashRecipe.cpp timer.cpp RecipeArray.cpp Service.cpp
HEADERS = $(MAIN_H) Reader.h   Ingredient.h   Recipe.h   RedBlackNode.h   RedBlackTree.h   utils.h   RBrecipe.h   HashRecipe.h   timer.h   RecipeArray.h   Service.h

SRCS = $(addprefix $(SRCS_DIR)/, $(SOURSES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SOURSES:.cpp=.o))
HDRS = $(addprefix $(HEADER_DIR)/, $(HEADERS))

all: $(NAME)

rb : $(OBJS) $(HDRS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME) -I $(HEADER_DIR)
hs : $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME) -I $(HEADER_DIR)

$(NAME) : $(OBJS) $(HDRS)
	$(CC) $(OBJS) -o $(NAME) -I $(HEADER_DIR)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.cpp $(HEADER_DIR)/%.h
	$(CC) -o $@ -c $< -I $(HEADER_DIR)

HEDAERS/Reader.h : HEADERS/Recipe.h
HEADERS/Recipe.h : HEADERS/Ingredient.h
HEADERS/RedBlackTree.h : HEADERS/RedBlackNode.h
HEADERS/RedBlackNode.h : HEADERS/Ingredient.h
HEADERS/RBrecipe.h : HEADERS/Recipe.h
HEADERS/HashRecipe.h : HEADERS/Recipe.h

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
