/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:35:08 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 15:27:57 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int size = 2; // Taille totale du tableau
    Animal* animals[size];

    // Remplissage du tableau: la moitié avec des Dogs et l'autre moitié avec des Cats
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }

    // Affichage du type et du son de chaque animal
    for (int i = 0; i < size; ++i) {
        std::cout << "Animal #" << i << " is a " << animals[i]->getType() << " and it says ";
        animals[i]->makeSound();
    }
    Dog test;
    std::cout <<" creation de test" << std::endl;
    Dog copy;
    std::cout << " creation de copy" << std::endl;
    copy = test;
    std::cout << " fin de copy = test" << std::endl;

    std::cout << "delete le tableau" << std::endl;
    // Libération de la mémoire allouée pour chaque Animal dans le tableau
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }
    return 0;
}

