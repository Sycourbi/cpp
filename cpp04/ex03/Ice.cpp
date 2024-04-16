/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:27:59 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/09 17:20:57 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}
Ice::~Ice() {
}
Ice::Ice(const Ice& other) : AMateria(other) {
}
Ice& Ice::operator=(const Ice& other) {
    AMateria::operator=(other);
    return (*this);

}
AMateria* Ice::clone() const {
    return new Ice();
}
void Ice::use(ICharacter& target){
     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}