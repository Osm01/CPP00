#include <iostream>

int main(int argc, char const *argv[])
{
	char	c;
	int		i;
	int		y;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			y = 0;
			while (argv[i][y])
			{
				c = argv[i][y];
				if (c >= 'a' && c <= 'z')
					c = c - 32;
				std::cout << c;
				y ++;
			}
			i ++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}