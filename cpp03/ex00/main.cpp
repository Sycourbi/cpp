/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:39:36 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/02 17:29:32 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // Création d'une instance de ClapTrap
    ClapTrap claptrap("CLAP-1");
    ClapTrap claptrap2("CLAP");

    claptrap2 = claptrap;
    // Affichage des messages de début
    std::cout << "Le jeu commence!" << std::endl;

    // ClapTrap attaque
    claptrap.attack("Target 1");
    claptrap.attack("Target 2");

    // ClapTrap subit des dégâts
    claptrap.takeDamage(2);
    claptrap.takeDamage(3);

    // ClapTrap se répare
    claptrap.beRepaired(5);

    // ClapTrap essaie d'effectuer des actions sans points d'énergie
    claptrap.attack("Target 3");

    claptrap.beRepaired(2);

    // Fin du jeu
    std::cout << "Fin du jeu!" << std::endl;
    
    return 0;
}