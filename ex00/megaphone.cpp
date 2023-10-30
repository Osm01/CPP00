# include <iostream>

# define RED "\033[31m"
# define RESET "\033[0m"

int main(int argc, char const *argv[])
{
	int		i;
	int		y;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			y = 0;
			while (argv[i][y])
				std::cout <<  (char)toupper(argv[i][y ++]);
			i ++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << RED << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << RESET << std::endl;
	return (0);
}