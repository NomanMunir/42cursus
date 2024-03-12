/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:24:46 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/08 19:40:39 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string inFile)
{
	_fileName = inFile;
	_outFileName = inFile + ".replace";
}

File::~File()
{
}

const std::string File::getFileName(void)
{
	return (this->_fileName);
}

const std::string File::getOutFileName(void)
{
	return (this->_outFileName);
}

int readContent(std::string &content, File &_file)
{
	std::ifstream inputFile(_file.getFileName().c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Could not open the file - '" << _file.getFileName() << "'" << std::endl;
		return 1;
	}
	if(!(std::getline(inputFile, content, '\0')))
	{
		std::cerr << "Empty file - '" << _file.getFileName() << "'" << std::endl;
		inputFile.close();
		return (1);
	}
	inputFile.close();
	return (0);
}

int writeOutFile(std::string &content, char **av, File &_file)
{
	std::string toFind = av[2];
	std::string toReplace = av[3];
	std::ofstream outFile(_file.getOutFileName().c_str(), std::ios::out);
	size_t pos = 0;
	if (!outFile.is_open())
	{
		std::cerr << "Could not open the file - '" << _file.getOutFileName() << "'" << std::endl;
		return 1;
	}
	if (toFind == "")
		return (outFile << content, 1);
	std::string modifiedContent;
	while ((pos = content.find(toFind, pos)) != std::string::npos)
	{
		modifiedContent.append(content, 0, pos);
		modifiedContent.append(toReplace);
		pos += toFind.length();
		content.erase(0, pos);
		pos = 0;
	}
	modifiedContent.append(content);
	outFile << modifiedContent;
	return (outFile.close(), 0);
}
