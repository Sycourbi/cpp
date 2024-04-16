/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:35:08 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/14 14:31:40 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"

#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    //creation des personnage
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
    //creation et equipement de materia pour me
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    // Utilisation des materia sur 'bob'
    me->use(0, *bob);
    me->use(1, *bob);

    //Demonstration de la copie et de l'assignation de Character
    ICharacter* copy = new Character(*dynamic_cast<Character*>(me));


    // Utilisation des materia par les personnages copiees et assignees
    std::cout << "use copy" << std::endl;
    copy->use(0, *bob);
    copy->use(1, *bob);

    
    delete bob;
    delete me;
    delete src;
    delete copy;
    
    return 0;
}

