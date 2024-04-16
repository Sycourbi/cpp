/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:55:55 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/26 12:34:04 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
    
}
Harl::~Harl() {
    
}
void Harl::debug(void) {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}
void Harl::info(void) {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}
void Harl::warning(void) {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void) {
    std::cout << "ERROR: This is unacceptable ! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level) 
{
    //declaration de la structure
    struct LevelFunctionsPair
    {
        std::string level;
        void (Harl::*functionPtr)();// pointeur sur les fonctions membres de la class Harl
    };
    //Tableau de structure contenant les level et les fonction associees
    LevelFunctionsPair levelFunctions[] = {{"DEBUG", &Harl::debug}, {"INFO", &Harl::info}, {"WARNING", &Harl::warning}, {"ERROR", &Harl::error}};
    
    for (size_t i = 0; i < 4; ++i)
    {
        if (levelFunctions[i].level == level)
        {
            (this->*(levelFunctions[i].functionPtr))();
            return;
        }
    }
    //aucun level exacte n'a ete trouve
    std::cerr << "Invalid complaint level: " << level << std::endl;
}