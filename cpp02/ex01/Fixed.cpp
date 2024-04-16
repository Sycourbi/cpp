/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:10:19 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/31 15:25:41 by sycourbi         ###   ########.fr       */
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
/*
    Constructeur qui prend un entier et le convertit en virgule fixe.
    Décale la valeur entière de 'fractionalBits' vers la gauche pour
    représenter la partie fractionnaire.
*/
Fixed::Fixed(const int intValue) {
    std::cout << "Int constructor called" << std::endl;
    value = intValue << fractionalBits;
}
// Convertit un float en virgule fixe, en arrondissant à l'entier le plus proche après
// avoir multiplié par 2^fractionalBits.
/*
    Par exemple, si vous avez un nombre flottant 3.75 et fractionalBits est 8
    multiplier 3.75 par 256 (qui est 2 8) vous donne 960.
    C'est la représentation en virgule fixe.
*/
Fixed::Fixed(const float floatValue) {
    /*Si fractionalBits = 8, 1 << 8 transforme ...00000001 en 
    0000000100000000 (en binaire), ce qui équivaut à 256 en décimal.*/
    std::cout << "Float constructor called" << std::endl;
    value = roundf(floatValue * (1 << fractionalBits));
}


//retour valeur
int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}
//initialise la valeur
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}
float Fixed::toFloat() const {
    return static_cast<float>(value) / (1 << fractionalBits);
}
int Fixed::toInt() const {
    return value >> fractionalBits;
}
// Implementation de la surcharge de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}