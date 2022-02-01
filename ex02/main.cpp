/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgicquel <hgicquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:58:12 by hgicquel          #+#    #+#             */
/*   Updated: 2022/02/01 19:17:31 by hgicquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << "\n";
	if (dynamic_cast<B*>(p))
		std::cout << "B" << "\n";
	if (dynamic_cast<C*>(p))
		std::cout << "C" << "\n";
}

void	identify(Base& p)
{
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << "\n";
	} catch (std::exception& e) {}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << "\n";
	} catch (std::exception& e) {}
	
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << "\n";
	} catch (std::exception& e) {}
}

int	main(void)
{
	srand(time(NULL));

	Base* p = generate();
	if (!p) return (1);

	identify(p);
	identify(*p);
	delete p;
}