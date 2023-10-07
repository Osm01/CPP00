#include "PhoneBook.hpp"

Contact	*PhoneBook::get_contacts(void)
{
	return (this->contacts);
}

void		PhoneBook::set_contacts(int index, Contact& contact)
{
	this->contacts[index] = contact;
}