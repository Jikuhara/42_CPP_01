/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 00:57:18 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 01:27:24 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// int main(int argc, const char *argv[])
// {
// 	Zombie*		horde;
// 	int			hordeSize;
// 	std::string	hordeName;

// 	(void)argc;
// 	if (argc != 3)
// 	{
// 		hordeSize = 20;
// 		hordeName = "test";
// 	}
// 	else
// 	{
// 		hordeSize = std::atoi(argv[1]);
// 		hordeName = argv[2];
// 	}
// 	horde = zombieHorde(hordeSize, hordeName);
// 	for (int i = 0; i < hordeSize; i++)
// 	{
// 		horde[i].announce();
// 	}
// 	delete[] horde;
// 	return 0;
// }


int main(void)
{
	Zombie*		horde;
	int			hordeSize;
	std::string	hordeName;

	hordeSize = 20;
	hordeName = "test";
	horde = zombieHorde(hordeSize, hordeName);
	for (int i = 0; i < hordeSize; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
