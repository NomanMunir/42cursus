/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:00:45 by nmunir            #+#    #+#             */
/*   Updated: 2024/03/12 14:43:02 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap{
		protected:
			std::string _name;
			int _hitPoints;
			int _energyPoints;
			int _attackDamage;

		public:
			ClapTrap();
			~ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& other);
			ClapTrap& operator=(const ClapTrap& rhs);
			
			void attack(const std::string& target);
			void takeDamage(unsigned int amount);
			void beRepaired(unsigned int amount);
};
