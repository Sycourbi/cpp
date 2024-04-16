/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:56:55 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/08 14:25:04 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Constructor Brain default" << std::endl;
}
Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << "Constructor copy Brain" << std::endl;
}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain() {
    std::cout << "Destructor Brain" << std::endl;
}