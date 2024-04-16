/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed_operator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:38:13 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/31 15:49:26 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

bool Fixed::operator>(const Fixed& rhs) const {
    return this->value > rhs.value;
}
bool Fixed::operator<(const Fixed& rhs) const {
    return this->value < rhs.value;
}
bool Fixed::operator>=(const Fixed& rhs) const {
    return this->value >= rhs.value;
}
bool Fixed::operator<=(const Fixed& rhs) const {
    return this->value <= rhs.value;
}
bool Fixed::operator==(const Fixed& rhs) const {
    return this->value == rhs.value;
}
bool Fixed::operator!=(const Fixed& rhs) const {
    return this->value != rhs.value;
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
    if (rhs.toFloat() == 0)
    {
        std::cerr << "Erreur: Tentative de division par zero." << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Pré-incrémentation
Fixed& Fixed::operator++() {
    this->value++;
    return *this;
}
// Post-incrémentation
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}
// Pré-décrémentation
Fixed& Fixed::operator--() {
    this->value--;
    return *this;
}
// Post-décrémentation
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}