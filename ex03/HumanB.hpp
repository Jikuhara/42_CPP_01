/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:00:32 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 12:09:44 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
	private:
		const Weapon*		weapon;
		std::string			name;
	public:
		HumanB(const std::string& humanName);
		void		setWeapon(const Weapon& newWeapon);
		void		attack();
};
#endif
