/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:42:17 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/01 18:28:52 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cmath>

bool	ft_error(const std::string& error)
{
	std::cerr << error << "\n";
	return (true);
}

bool	convert_char(const std::string& s)
{
	if (s.length() != 1)
		return (false);
	char c(s[0]);

	if (c < 32 || c > 126)
		std::cout << "char: " << "Non displayable" << "\n";
	else
		std::cout << "char: " << c << "\n";
		
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
	return (true);
}

bool	check_int(const std::string& s)
{
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (i == 0)
		return (false);
	if (s[i])
		return (false);
	return (true);
}

bool	convert_int(const std::string& s)
{
	if (!check_int(s))
		return (false);
	int x = strtol(s.c_str(), NULL, 10);

	if (x < 0 || x > 255)
		std::cout << "char: " << "impossible" << "\n";
	else if (x < 32 || x > 126)
		std::cout << "char: " << "Non displayable" << "\n";
	else
		std::cout << "char: " << static_cast<char>(x) << "\n";
		
	std::cout << "int: " << static_cast<int>(x) << "\n";
	std::cout << "float: " << static_cast<float>(x) << "f\n";
	std::cout << "double: " << static_cast<double>(x) << "\n";
	return (true);
}

bool	check_float(const std::string& s)
{
	if (s == "nanf" || s == "+inff" || s == "-inff")
		return (true);
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (i == 0)
		return (false);
	if (s[i++] != 'f')
		return (false);
	if (s[i])
		return (false);
	return (true);
}

bool	convert_float(const std::string& s)
{
	if (!check_float(s))
		return (false);
	float x = strtod(s.c_str(), NULL);

	if (std::isnan(x) || std::isinf(x) || x < 0 || x > 255)
		std::cout << "char: " << "impossible" << "\n";
	else if (x < 32 || x > 126)
		std::cout << "char: " << "Non displayable" << "\n";
	else
		std::cout << "char: " << static_cast<char>(x) << "\n";

	if (std::isnan(x) || std::isinf(x))
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(x) << "\n";
		
	std::cout << "float: " << x << "f\n";
	std::cout << "double: " << static_cast<double>(x) << "\n";
	return (true);
}

bool	check_double(const std::string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '.' || (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (i == 0)
		return (false);
	if (s[i])
		return (false);
	return (true);
}

bool	convert_double(const std::string& s)
{
	if (!check_double(s))
		return (false);
	double x = strtod(s.c_str(), NULL);

	if (std::isnan(x) || std::isinf(x) || x < 0 || x > 255)
		std::cout << "char: " << "impossible" << "\n";
	else if (x < 32 || x > 126)
		std::cout << "char: " << "Non displayable" << "\n";
	else
		std::cout << "char: " << static_cast<char>(x) << "\n";

	if (std::isnan(x) || std::isinf(x))
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(x) << "\n";
		
	std::cout << "float: " << static_cast<float>(x) << "f\n";
	std::cout << "double: " << x <<"\n";
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (convert_int(argv[1]))
		return (0);
	if (convert_float(argv[1]))
		return (0);
	if (convert_double(argv[1]))
		return (0);
	if (convert_char(argv[1]))
		return (0);
	std::cout << "Can't parse " << argv[1] << "\n";
	return (1);
}