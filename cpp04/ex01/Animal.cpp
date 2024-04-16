/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:31:44 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 14:59:15 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    type = "Undefined";
    std::cout << "Constructor Animal default" << std::endl;
}
Animal::Animal(const Animal& other) {
    *this = other;
}
Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
    {
        type = other.type;
        std::cout << "Operator = called" << std::endl;
    }
    else
         std::cout << "Operator = called - Self-assignment detected." << std::endl;
    return (*this);
}
Animal::~Animal() {
    std::cout << "Destructor Animal" << std::endl;
}

std::string Animal::getType() const{
    return type;
}
void Animal::makeSound() const{
    std::cout << "Some animal sound" << std::endl;
}