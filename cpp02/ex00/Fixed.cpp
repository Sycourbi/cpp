/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:19 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/31 14:53:44 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructeur par defaut
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;  
}
//constructeur de recopie
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
//operateur d'affectation
Fixed&  Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value = other.getRawBits();
    return *this;
}
//destructeur
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//retour valeur
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}
//initialise la valeur
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}