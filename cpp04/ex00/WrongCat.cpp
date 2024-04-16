/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:01:49 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/08 13:40:09 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "Constructor WrongCat default" << std::endl;
}
WrongCat::~WrongCat() {
    std::cout << "Destructor WrongCat" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other) {
    *this = other;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat operator affectation" << std::endl;
    return (*this);
}
void WrongCat::makeSound() const{
    std::cout << "Meow" <<std::endl;
}
