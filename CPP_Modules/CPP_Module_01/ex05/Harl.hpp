/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:11:17 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/10 10:38:25 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	void (Harl::*array[4])(void);

	public:
		void complain( std::string level );
		Harl();
		~Harl();
};
#endif