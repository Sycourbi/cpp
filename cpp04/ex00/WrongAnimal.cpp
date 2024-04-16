/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:20 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/08 13:41:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    type = "WrongAnimal";
    std::cout << "Construtor WrongAnimal default" << std::endl;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor WrongAnimal" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    *this = other;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
    {
        type = other.type;
        std::cout << "WrongAnimal Operator called" << std::endl;
    }
    else
         std::cout << "WrongAnimal Operator called - Self-assignment detected." << std::endl;
    return (*this);
}
std::string WrongAnimal::getType() const {
    return type;
}
void WrongAnimal::makeSound() const {
    std::cout << "Some wronganimal sound" << std::endl;
}