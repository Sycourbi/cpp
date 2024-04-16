/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:54:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 11:52:00 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& initType) : type(initType) {

}
Weapon::~Weapon() {
    
}
const std::string& Weapon::getType() const {
    return (type);
}
void Weapon::setType(const std::string& newType) {
    type = newType;
}