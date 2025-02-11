/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:24:22 by stuna             #+#    #+#             */
/*   Updated: 2025/02/11 16:44:37 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>  // For strlen
#include <cctype>   // For toupper

int main(int argc, char **argv)
{
    if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    size_t totalLength = 0;
    for (int i = 1; i < argc; ++i)
	{
        totalLength += std::strlen(argv[i]) + 1;
    }
    char *input = new char[totalLength];
    input[0] = '\0';
    for (int i = 1; i < argc; ++i)
	{
        std::strcat(input, argv[i]);
        if (i < argc - 1)
			std::strcat(input, "");
    }
    for (size_t i = 0; i < std::strlen(input); ++i)
		input[i] = std::toupper(input[i]);
	std::cout << input << std::endl;
    
	delete[] input;
    return 0;
}

