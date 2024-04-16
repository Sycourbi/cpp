/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:17:51 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/26 11:53:45 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    
}
Harl::~Harl() {
    
}

void Harl::debug() {
    std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    std::string strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i(0);
    
    while (i < 4 && level != strs[i])
        i++;
    switch (i)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}