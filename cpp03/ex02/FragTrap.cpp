/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:55:23 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/05 15:24:55 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
    name = "";
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "Constructor FragTrap default" << std::endl; 
}
FragTrap::FragTrap(std::string name){
    this->name = name;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap " << name << " constructor" << std::endl;
}
FragTrap::FragTrap(const FragTrap& other) {
    *this = other;
    std::cout << "Constructor copy FragTrap" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap operator affectation" << std::endl;
    return (*this);
}
FragTrap::~FragTrap() {
    std::cout << "Destructor FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}