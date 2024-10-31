/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:10:40 by nmunir            #+#    #+#             */
/*   Updated: 2024/04/03 11:17:03 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

typedef unsigned long uintptr_t;

#include <iostream>

struct Data {
	int a;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const  Serializer& other);
		Serializer& operator=(const  Serializer& rhs);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif // !SERIALIZER_HPP
