/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 00:11:07 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/06 01:24:54 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class	Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		~Zombie();
		void set_name(int num, std::string name);
		void announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
