/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:10:34 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/13 17:14:11 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
		virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif // !BASE_HPP