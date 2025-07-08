/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:02:55 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 12:11:32 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& humanName)
{
	this->name = humanName;
	this->weapon = NULL;
}

void	HumanB::setWeapon(const Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack()
{
	if (this->weapon)
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with" << std::endl;
}
