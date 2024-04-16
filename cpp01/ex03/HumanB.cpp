/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:40 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 18:22:04 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name) {
}
HumanB::~HumanB() {
}
void HumanB::setWeapon(const Weapon& newWeapon) {
    weaponPtr = &newWeapon;
}
void HumanB::attack()
{
    if (weaponPtr)
    {
        std::cout << name << " attacks with their " << weaponPtr->getType() << std::endl;
    }
    else
    {
        std::cout << name << " attacks with bare hands" << std::endl;
    }
}