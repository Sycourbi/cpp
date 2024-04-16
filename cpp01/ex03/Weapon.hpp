/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:54:30 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 11:52:43 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

public:
    Weapon(const std::string& initType);
    ~Weapon();
    
     // Fonction membre getType() retournant une référence constante sur type.
    const std::string& getType() const;
    // Fonction membre setType() attribuant à type la nouvelle valeur passée en paramètre.
    void setType(const std::string& newType);
    
private:
    std::string type;
};

# endif