/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:35:08 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/08 17:42:49 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int numAnimals = 2;
    Animal* animals[numAnimals];

    // Remplir le tableau avec des Dog et des Cat
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Afficher le type et le son de chaque animal
    for (int i = 0; i < numAnimals; ++i) {
        std::cout << "Animal #" << i << " is a " << animals[i]->getType() << " and it says ";
        animals[i]->makeSound();
    }

    // Nettoyer: supprimer chaque Animal du tableau
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }
    
    //test pour creer une instance de animal
    std::cout << "---------------------------" << std::endl;
    // Animal a;
    // a->makeSound();
    
    
    return 0;
}
