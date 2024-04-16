/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:37:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/08 14:30:19 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain){
    type = "Cat";
    std::cout << "Constructor Cat default" << std::endl;
}
Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)){
    std::cout << "Constructor copy Cat" << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        delete brain; // Libérez l'ancien brain avant de le remplacer pour éviter les fuites de mémoire.
        brain = newBrain;       
    }
    return (*this);
}
Cat::~Cat() {
    delete brain;
    std::cout << "Destructor Cat" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow" <<std::endl;
}