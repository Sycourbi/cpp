/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:39:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/05 15:17:37 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    name = "";
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "constructor ScavTrap default" << std::endl;
}
ScavTrap::ScavTrap(std::string name){
    this->name = name;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap " << name << " constructor" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other) {
    *this = other;
    std::cout << "Constructor copy ScavTrap terminer" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap operator affectation" << std::endl;
    return (*this);
}
ScavTrap::~ScavTrap() {
    std::cout << "destructor ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (HitPoints > 0 && EnergyPoints > 0)
    {
        std::cout << "ScavTrap " << name << " attaque " << target << ", causant " << AttackDamage << " points de dégâts !" << std::endl; 
        --EnergyPoints;
    }
    else
        std::cout << "ScavTrap " << name << " n'a pas assez d'énergie ou de points de vie pour attaquer." << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}