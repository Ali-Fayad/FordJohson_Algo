# Compiler and flags
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

# Directories
SRC_DIR  = Srcs
OBJ_DIR  = Obj
INC_DIR  = Include

# Executable name
NAME     = PmergeMe

# Source files
SRCS     =	$(SRC_DIR)/main.cpp \
			$(SRC_DIR)/PmergeMe.cpp

# Object files
OBJS     = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Colors
GREEN    = \033[0;32m
RED      = \033[0;31m
RESET    = \033[0m

# Default rule
all: $(NAME)

# Link object files into executable
$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✔ $(NAME) Compiled!$(RESET)"

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled:$(RESET) $(RED)$@ ✔$(RESET)"

# Ensure object directory exists
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🗑️  Object files removed!$(RESET)"

# Clean all (objects + binary)
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Executable removed!$(RESET)"

# Recompile from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
