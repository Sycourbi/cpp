/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:40:06 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/05 15:17:58 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
        : name(""), HitPoints(100), EnergyPoints(10), AttackDamage(0) {
    std::cout << "Constructor default ClapTrap" << std::endl; 
}
ClapTrap::~ClapTrap(){
    std::cout << "Destructor ClapTrap" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name) 
        : name(name), HitPoints(100), EnergyPoints(10), AttackDamage(0) {
    std::cout << "Contructor with name ClapTrap" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "Constructor copy ClapTrap" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other)
    {
        name = other.name;
        HitPoints = other.HitPoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
        std::cout << "ClapTrap assignation operator called - Object has been assigned." << std::endl;
    }
    else
        std::cout << "ClapTrap assignation operator called - Self-assignment detected." << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target) {
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
        std::cout << "ClapTrap " << name << " cannot attack due to low energy or hit points." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount) {
    if (HitPoints > amount)
    {
        HitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
    } 
    else
    {
        HitPoints = 0;
        std::cout << "ClapTrap " << name << " is out of hit points and can't take more damage!" << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount) {
    if (EnergyPoints > 0 && HitPoints > 0)
    {
        HitPoints += amount;
        std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << ", hit points " << std::endl;
        EnergyPoints--; 
    }
    else
        std::cout << "ClapTrap " << name << " cannot repair due to low energy or hit points." << std::endl;
    
}