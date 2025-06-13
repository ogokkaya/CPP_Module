NAME    = AForm
CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98
RM      = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/

SRC_FILES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

f: fclean
c: clean
r: re

.PHONY: all clean fclean re f c r