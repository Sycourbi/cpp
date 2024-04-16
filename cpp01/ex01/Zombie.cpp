/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:27:10 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 15:27:25 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	//std::cout << "Constructor Zombie" << name << std::endl;
}
Zombie::Zombie(std::string name) : name(name) {

}
Zombie::~Zombie(void) {
	//std::cout << "Destructor Zombie: " << name << std::endl;
}
void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}