/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:25:13 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/09 17:21:03 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {

}
Cure::~Cure() {

}
Cure::Cure(const Cure& other) :AMateria(other) {

}
Cure& Cure::operator=(const Cure& other) {
    AMateria::operator=(other);
    return (*this);
}
AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}