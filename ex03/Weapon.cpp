/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:40 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 12:17:47 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& newType)
{
	type = newType;
}

const	std::string&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(const std::string& newType)
{
	this->type = newType;
}
