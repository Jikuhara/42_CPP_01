/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:02:55 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 12:22:39 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, const Weapon& newWeapon) : weapon(newWeapon)
{
	this->name = humanName;
}

void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}
