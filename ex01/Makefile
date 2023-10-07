NAME = phonebook

CPP_ERROR = #-Wall -Wextra -Werror
CPP_FLAG_COMPI = -std=c++98

SRC = main.cpp ft_stoi.cpp Contact.cpp PhoneBook.cpp

all : $(NAME)

$(NAME) : $(SRC)
	c++ $(CPP_FLAG_COMPI) $(CPP_ERROR) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)
fclean : clean

re : fclean $(NAME)
