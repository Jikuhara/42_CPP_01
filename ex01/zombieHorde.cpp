/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 00:51:58 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 01:19:32 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::set_name(int num, std::string name)
{
	std::string	digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	std::string	result;
	int			digit;

	digit = num % 10;
	result = digits[digit];
	num /= 10;
	while (num > 0)
	{
		digit = num % 10;
		result = digits[digit] + "-" + result;
		num /= 10;
	}
	result = name + "-" + result;
	this->name = result;
}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].set_name(i, name);
	}
	return horde;
}
