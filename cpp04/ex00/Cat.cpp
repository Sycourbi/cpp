/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:37:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/06 14:24:03 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Constructor Cat default" << std::endl;
}
Cat::Cat(const Cat& other) {
    *this = other;
    std::cout << "Constructor copy Cat" << std::endl;
}
Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}
Cat::~Cat() {
    std::cout << "Destructor Cat" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Meow" <<std::endl;
}