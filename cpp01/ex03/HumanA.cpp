/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 12:09:38 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon) : name(name), weapon(weapon) {
    
}
HumanA::~HumanA() {
}
void HumanA::attack() const{
    std::cout << name << " attacks with their " << weapon.getType() <<std::endl;
}