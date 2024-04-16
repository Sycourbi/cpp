/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:43:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/06 14:24:12 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "Constructor Dog Default" << std::endl;
}
Dog::Dog(const Dog& other) {
    *this = other;
    std::cout << "Constructor copy Dog" << std::endl;
}
Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}
Dog::~Dog() {
    std::cout << "Destructor Dog" << std::endl; 
}

void Dog::makeSound() const{
    std::cout << "Woof" << std::endl;
}