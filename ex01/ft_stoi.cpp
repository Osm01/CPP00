#include <string>

int	ft_stoi(std::string str)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = (value * 10) + (str[i] - '0');
		else
			return (-1);
		i ++;
	}
	return (value);
}


