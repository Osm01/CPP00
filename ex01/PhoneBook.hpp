#ifndef CPP00_PHONEBOOK_H
# define CPP00_PHONEBOOK_H

#include "Contact.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define WHITE "\033[37m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"

class PhoneBook
{
private:
	Contact	contacts[8];

public:
	Contact		*get_contacts(void);
	void		set_contacts(int index, Contact &contact);
};

int	ft_stoi(std::string str);

#endif //CPP00_PHONEBOOK_H
