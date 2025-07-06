/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:02:55 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 12:20:15 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string humanName)
{
	this->name = humanName;
}

void	HumanB::setWeapon(Weapon newWeapon)
{
	this->weapon = newWeapon;
}

void	HumanB::attack()
{
	std::cout << name << "attacks with their " << this->weapon.getType() << std::endl;
}
