/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:51:15 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 16:45:10 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid argument!" << std::endl;
		return 1;
	}
	File _file = File(av[1]);
	std::string content;
	if (readContent(content, _file))
		return (1);
	if (writeOutFile(content, av, _file))
		return (1);
	return (0);
}