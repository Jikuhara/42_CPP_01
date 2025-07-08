/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:41:55 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 13:09:47 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
	// if (argc != 4)
	// {
	// 	std::cout << "Your input is wrong." << std::endl;
	// }
	std::fstream s1;
	s1.open("test.txt", std::ios_base::in | std::ios_base::out);
	return 0;
}

