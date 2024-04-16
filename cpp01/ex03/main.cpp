/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:54:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 16:02:03 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		//creation d'une arme
		Weapon club = Weapon("crude spiked club");
		//creation d'un humain avec un nom(bob) avec une arme
		HumanA bob("Bob", club);
		//bob attaque avec l'arme
		bob.attack();
		//modification du type d'arme general
		club.setType("some other type of club");
		//bob attaque mais avec le nouveau type d'arme
		bob.attack();
	}
	{
		//creation d'une arme
		Weapon club = Weapon("crude spiked club");
		//creation d'un humain avec un nom(Jim) sans arme
		HumanB jim("Jim");
		//assigne le pointeur weapon sur l'adresse du type d'arme de la class Weapon
		jim.setWeapon(club);
		//jim attaque avec son arme aatribuer dessus
		jim.attack();
		//modification du type d'arme
		club.setType("some other type of club");
		//jim attaque avec la nouvelle arme
		jim.attack();
	}
	return(0);
}