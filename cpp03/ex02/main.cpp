/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:39:36 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/05 14:38:46 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    // Création d'un ClapTrap
    ClapTrap clap("CLAP");
    clap.attack("ennemi 1");
    clap.takeDamage(9);
    clap.beRepaired(5);

    // Création d'un ScavTrap
    ScavTrap scav("SCAV");
    scav.attack("ennemi 2");
    scav.takeDamage(60);
    scav.beRepaired(10);
    scav.guardGate();

    // Création d'un FragTrap
    FragTrap frag("FRAG");
    frag.attack("ennemi 3");
    frag.takeDamage(99);
    frag.beRepaired(15);
    frag.highFivesGuys();

    return 0;
}