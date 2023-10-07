#ifndef CPP00_CONTACT_H
# define CPP00_CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <unistd.h>

class Contact
{
private:
	std::string	phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	darkest_secret;

public:
	Contact ();
	Contact(std::string p, std::string f,std::string l,std::string n,std::string d);

	std::string	get_phone_number(void);
	void		set_phone_number(std::string& phone_number);

	std::string	get_first_name(void);
	void		set_fist_name(std::string first_name);

	std::string	get_last_name(void);
	void		set_last_name(std::string last_name);

	std::string	get_nickname(void);
	void		set_nickname(std::string nickname);

	std::string	get_darkest_secret(void);
	void		set_darkest_secret(std::string darkest_secret);
};


#endif //CPP00_CONTACT_H