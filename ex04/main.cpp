/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:36:25 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 13:42:10 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	if (argc != 4)
	{
		std::cout << "Your input is wrong." << std::endl;
		std::cout << "Please enter ./<> <filename> <replace_string> <replace_string>." << std::endl;
	}
	std::string old_filename = argv[1];
	std::string new_filename = old_filename + ".replace";
	std::fstream old_file(old_filename, std::ios_base::in);
	std::fstream new_file(new_filename, std::ios_base::out);

	std::string line;
	getline(old_file, line);
	new_file << line << std::endl;
	return 0;
}

