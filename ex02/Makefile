NAME = Account

CPP_COMPI = g++ -std=c++98
ERRORS = -Wall -Wextra -Werror

SRC = tests.cpp Account.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CPP_COMPI) $(ERRORS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : clean all