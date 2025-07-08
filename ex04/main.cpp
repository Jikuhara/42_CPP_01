/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:36:25 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 14:25:15 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int replace_string(std::string str, std::string src, std::string dst)
{
	int search_pos = 0;
	search_pos = str.find(src, search_pos);
	char* ahead_chars;
	str.copy(ahead_chars, search_pos);
	std::string ahead_str(ahead_chars);
	/* もうちょいきれいに実装できそう */
	ahead_str.append(str, );
}

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

	std::string old_string;
	std::string line;
	/* 改行が一つ多くなってしまう。。 */
	while(getline(old_file, line))
	{
		old_string += line + '\n';
	}
	new_file << old_string << std::endl;
	return 0;
}

