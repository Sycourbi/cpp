/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:26:19 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:48 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

/*
Le tas(HEAP) est une zone de mémoire plus grande et moins structurée,
où l'allocation et la libération de mémoire sont gérées manuellement.
*/

int	main(void)
{
	/*
		L'objet est créé sur la pile car il
		est nécessaire uniquement dans la portée de la fonction main.
	*/
	Zombie zombieStack = Zombie("ZOMBIE Heap");
	zombieStack.announce();
	

	/*
		L'objet Zombie est créé sur le tas car le pointeur zombieHeap
		pourrait être utilisé en dehors de la fonction, et il nécessite
		une durée de vie plus longue
	*/
	Zombie* zombieHeap = newZombie("ZOMBIE STACK");
	zombieHeap->announce();
	delete zombieHeap;

	/*
		L'objet Zombie est créé sur la pile car il est temporaire et n'a
		pas besoin d'être utilisé en dehors de la fonction.
	*/
	randomChump("Ramdom chump zombie");
	return (0);
}
//Pile(Stask) : Utilisez la pile pour les variables locales, les données temporaires
//et lorsque la durée de vie des données est limitée à la portée d'une fonction
//ou d'un bloc.
//Tas(Heap) : Utilisez le tas pour les objets dynamiques lorsque la durée de vie
//des données doit être prolongée au-delà de la portée de la fonction actuelle,
//ou lorsque vous avez besoin de gérer explicitement l'allocation et la libération de mémoire.