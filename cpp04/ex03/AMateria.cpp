/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:55:21 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 14:11:35 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("") {
    
}
AMateria::AMateria(std::string const& type) : type(type){

}
AMateria::AMateria(const AMateria& other) : type(other.type) {
    
}
AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}
AMateria::~AMateria() {

}
std::string const& AMateria::getType() const {
    return (type);
}
