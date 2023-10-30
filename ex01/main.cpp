#include "PhoneBook.hpp"

void	printMenu()
{
	std::cout << BLUE <<"+----------------------------------+" << std::endl;
	std::cout << "|            MAIN MENU             |" << std::endl;
	std::cout << "+----------------------------------+" << std::endl;
	std::cout << "|" << RED <<"    *    ADD          *           "<< BLUE << "|" << std::endl;
	std::cout << "|" << RED <<"    *    SEARCH       *           "<< BLUE << "|" << std::endl;
	std::cout << "|" << RED <<"    *    EXIT         *           "<< BLUE << "|" << std::endl;
	std::cout << "+----------------------------------+" << RESET <<std::endl;
}

bool	containsOnlyTabsOrSpaces(std::string &str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ')
			return (false);
		i ++;
	}
	return (true);
}

void	user_prompt(std::string &user_input)
{
	std::cout << BLUE << "+----------------------------------+" << std::endl;
	std::cout << "| OPERATION: " << RED;
	getline(std::cin, user_input);
	std::cout << BLUE <<"+----------------------------------+" << RESET <<std::endl;
}

void	user_fill_prompt(std::string &filled, std::string filled_name)
{
	std::cout << PURPLE << "+----------------------------------+" << std::endl;
	std::cout << "| "<<filled_name << ": " << GREEN;
	getline(std::cin, filled);
	std::cout << PURPLE <<"+----------------------------------+" << RESET <<std::endl;
}


int	add_contact(PhoneBook &phoneBook, int current_index)
{
	Contact		contact;
	std::string	phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	dark_s;


	std::cout << "Adding contact" << std::endl;
	user_fill_prompt(phone_number, "Phone number");
	user_fill_prompt(first_name, "First name");
	user_fill_prompt(last_name, "last name");
	user_fill_prompt(nick_name, "Nickname");
	user_fill_prompt(dark_s, "dark secret");
	if (phone_number.empty() || first_name.empty() || last_name.empty() || nick_name.empty() || dark_s.empty())
	{
		std::cout << RED << "Empty output not accepted !!" << RESET << std::endl;
		return (0);
	}
	if (containsOnlyTabsOrSpaces(phone_number) || containsOnlyTabsOrSpaces(first_name) || containsOnlyTabsOrSpaces(last_name) \
	|| containsOnlyTabsOrSpaces(nick_name) || containsOnlyTabsOrSpaces(dark_s))
	{
		std::cout << RED << "Only tabs or space are not accepted !!" << RESET << std::endl;
		return (0);
	}
	contact = Contact(phone_number, first_name, last_name, nick_name, dark_s);
	phoneBook.set_contacts(current_index, contact);
	std::cout << GREEN << "The contact was added to phone Book" << "\033[0m" << std::endl;
	return (1);
}

void	display_contacts(PhoneBook phoneBook, int nb_contact)
{
	Contact	*contact;
	int		i;

	i = 0;

	while (i < nb_contact)
	{
		contact = phoneBook.get_contacts();
		std::cout << PURPLE << std::setw(10) << i << " | ";
		if (contact[i].get_first_name().size() > 10)
			std::cout << std::setw(10) << contact[i].get_first_name().substr(0, 10) << ".| ";
		else
			std::cout << std::setw(10) << contact[i].get_first_name() << " | ";
		if (contact[i].get_last_name().size() > 10)
			std::cout << std::setw(10) << contact[i].get_last_name().substr(0, 10) << ".| ";
		else
			std::cout << std::setw(10) << contact[i].get_last_name() << " | ";
		if (contact[i].get_nickname().size() > 10)
			std::cout << std::setw(10) <<  contact[i].get_nickname().substr(0, 10) << ".| " << RESET;
		else
			std::cout << std::setw(10) << contact[i].get_nickname() << " | " << RESET;
		std::cout << std::endl;
		i ++;
	}
}

void	searching_for(PhoneBook phoneBook, int index_to_search, int nb_contact)
{
	Contact *contact;

	if (index_to_search > 8 || index_to_search > nb_contact - 1)
	{
		std::cout << RED << "The number : " << index_to_search << " is out of range" << RESET << std::endl;
		return ;
	}
	contact = phoneBook.get_contacts();
	std::cout << PURPLE << std::setw(10) << index_to_search << " | ";
	if (contact[index_to_search].get_phone_number().size() > 10)
		std::cout << std::setw(10) << contact[index_to_search].get_phone_number().substr(0, 10) << ". | ";
	else
		std::cout << std::setw(10) << contact[index_to_search].get_phone_number()<< " | ";
	if (contact[index_to_search].get_first_name().size() > 10)
		std::cout << std::setw(10) << contact[index_to_search].get_first_name().substr(0, 10) << ". | ";
	else
		std::cout << std::setw(10) << contact[index_to_search].get_first_name() << " | ";
	if (contact[index_to_search].get_last_name().size() > 10)
		std::cout << std::setw(10) << contact[index_to_search].get_last_name().substr(0, 10) << ". | ";
	else
		std::cout << std::setw(10) << contact[index_to_search].get_last_name() << " | ";
	if (contact[index_to_search].get_nickname().size() > 10)
		std::cout << std::setw(10) << contact[index_to_search].get_nickname().substr(0, 10) << ". | ";
	else
		std::cout << std::setw(10) << contact[index_to_search].get_nickname() << " | ";
	if (contact[index_to_search].get_darkest_secret().size() > 10)
		std::cout << std::setw(10) << contact[index_to_search].get_darkest_secret().substr(0, 10) << ". | " << RESET;
	else
		std::cout << std::setw(10) << contact[index_to_search].get_darkest_secret() << " | " << RESET;
	std::cout << std::endl;
}

void	search_contact(PhoneBook phoneBook, int current_contact)
{
	std::string	user_input;
	int			nb_contact;
	int			index_to_search;

	if (current_contact == 0)
		std::cout << RED <<"No data to Display !!!" << RESET << std::endl;
	else
	{
		if (current_contact > 8)
			nb_contact = 8;
		else
			nb_contact = current_contact;
		display_contacts(phoneBook, nb_contact);
		std::cout << "SEARCHING FOR :";
		getline(std::cin, user_input);
		if (!user_input.empty())
		{
			if (ft_stoi(user_input) >= 0)
				index_to_search = ft_stoi(user_input);
			else
			{
				std::cout << RED << "ACCEPT JUST DIGITAL NUMBER" << RESET << std::endl;
				return;
			}
			searching_for(phoneBook, index_to_search, nb_contact);
		}
		else
			std::cout << RED << "NO EMPTY DATA ACCEPTED !!!" << RESET << std::endl;
	}
}

int	main()
{
	std::string	user_input;
	PhoneBook	phoneBook;
	int 		current_contact;

	current_contact = 0;
	printMenu();
	while (1)
	{
		std::cout << "New Operation : " << GREEN << " ADD , SEARCH , EXIT" << RESET << std::endl;
		user_prompt(user_input);
		if (std::cin.eof())
			break ;
		if (user_input.empty())
			std::cout << RED << "EMPTY PROMPT !!!!!!!!" << RESET << std::endl;
		else if (user_input != "ADD" && user_input != "SEARCH" && user_input != "EXIT")
			std::cout  << BLUE << "THE \"" << RED << user_input << BLUE << "\""<< " IS NOT VALID" << RESET << std::endl;
		else
		{
			std:: cout << "The operation \"" << GREEN <<user_input << RESET << "\" is LOADING ..." << std::endl;
			if (user_input == "ADD")
			{
				if (add_contact(phoneBook, current_contact % 8))
					current_contact ++;
			}
			else if (user_input == "SEARCH")
				search_contact(phoneBook, current_contact);
			else if (user_input == "EXIT")
				return (sleep(1), std::cout << GREEN<< "EXITING\n" << RESET, 0);
		}
	}
	return (0);
}
