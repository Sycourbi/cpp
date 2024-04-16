/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:39:36 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/05 15:23:17 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
   // Création d'un ClapTrap
    ClapTrap clapTrap("CLAP");
    clapTrap.attack("ennemi 1");
    clapTrap.takeDamage(5);
    clapTrap.beRepaired(5);
    
    // Test des limites de ClapTrap
    clapTrap.takeDamage(100); // Devrait epuiser ses points de vie
    clapTrap.beRepaired(5); // Test de réparation quand les points de vie sont à 0

    std::cout << "-----------------------------------" << std::endl;

    // Création d'un ScavTrap
    ScavTrap scavTrap("SCAV");
    scavTrap.attack("ennemi 2");
    scavTrap.takeDamage(60);
    scavTrap.beRepaired(60);
    scavTrap.guardGate();
    
    // Test des limites de ScavTrap
    scavTrap.takeDamage(100); // Devrait epuiser ses points de vie
    scavTrap.beRepaired(10); // Test de réparation quand les points de vie sont 0;


    return 0;
}