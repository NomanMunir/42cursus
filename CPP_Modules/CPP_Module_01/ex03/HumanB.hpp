/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:03:08 by nmunir            #+#    #+#             */
/*   Updated: 2024/02/10 10:45:12 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *_wp;
	std::string _name;

public:
	void attack();
	void setWeapon(Weapon &wp);
	HumanB(std::string name);
	~HumanB();
};
#endif