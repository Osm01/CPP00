NAME = megaphone
CPP_ERROR = -Wall -Wextra -Werror
CPP_FLAG_COMPI = c++ -std=c++98

SRC = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CPP_FLAG_COMPI) $(CPP_ERROR) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : fclean all
