/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:55:04 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 15:52:27 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"
#include <string>
#include <iostream>


class HumanA {
    
public:
        HumanA(const std::string& name, const Weapon& weapon);
        ~HumanA();

        void attack() const;
        
private:
    std::string name;
    //reference car Human aura forcement une Weapon
    const Weapon& weapon;
};
# endif