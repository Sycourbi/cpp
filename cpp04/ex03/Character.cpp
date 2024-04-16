/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:11:19 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 14:33:19 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string& name) : name(name) {
        for (int i = 0; i < 4; ++i)
            inventory[i] = NULL;
}
Character::Character(const Character& other) : name(other.name) {
        for (int i = 0; i < 4; ++i)
        {
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
}
Character& Character::operator=(const Character& other) {
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
     return *this;
}
Character::~Character() {
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}
std::string const& Character::getName() const {
    return name;
}
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            break;
        }
    }
}
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
        inventory[idx]->use(target);
}