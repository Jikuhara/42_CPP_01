/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kei2003730 <kei2003730@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:36:25 by kei2003730        #+#    #+#             */
/*   Updated: 2025/07/08 15:02:56 by kei2003730       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace_string(std::string old_str, std::string src, std::string dst)
{
	int old_pos = 0;
	int new_pos = old_str.find(src, old_pos);
	int length = old_str.length();
	int src_length = src.length();
	std::string new_str;
	while (new_pos != std::string::npos)
	{
		new_str.append(old_str, old_pos, new_pos - old_pos);
		new_str.append(dst);
		old_pos = new_pos + src_length;
		new_pos = old_str.find(src, old_pos);
	}
	new_str.append(old_str, old_pos, length - old_pos);
	return (new_str);
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
	std::string new_line;
	/* 改行が一つ多くなってしまう。。 */
	while(getline(old_file, line))
	{
		new_line = replace_string(line, argv[2], argv[3]);
		old_string += new_line + '\n';
	}
	old_string.pop_back();
	new_file << old_string << std::endl;
	return 0;
}

