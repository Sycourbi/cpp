/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:31 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 15:51:58 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {

public:
    HumanB(const std::string& name);
    ~HumanB();

    void attack();
    void setWeapon(const Weapon& newWeapon);
    
private:
    std::string name;
    //pointeur car HumanB n'aura pas forcement une Weapon
    const Weapon* weaponPtr = nullptr;
};

# endif
