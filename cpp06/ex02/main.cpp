/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:32:34 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 13:04:15 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#include <iostream>

Base* generate(void) {
    int r = std::rand() % 3; // Génère 0, 1, ou 2
    switch (r) {
    case 0:
        return new A;
    case 1:
        return new B;
    case 2:
        return new C;
    default:
        return NULL; // Juste au cas ou
    }
}
void identify(Base* p) {
    if (p == NULL)
    {
        std::cout << "Unknown type" << std::endl;
        return ;
    }
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
    else std::cout << "Unknown type" << std::endl;
}
void identify(Base& p) {
    try {
        // Tentative de cast vers A&
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {
        // Le cast a échoué, on continue donc avec le prochain
    }

    try {
        // Tentative de cast vers B&
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {
        // Continue avec le prochain
    }

    try {
        // Tentative de cast vers C&
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (...) {
        // Si tous les casts ont échoué, le type est inconnu
        std::cout << "Unknown type" << std::endl;
    }
}

int main()
{
    std::srand(std::time(0)); // Initialisation du générateur de nombres aléatoires

    // Generer et identifier 5 objets aleatoires
    for (int i = 0; i < 5; ++i) {
        Base* obj = generate();
        std::cout << "Objet " << i + 1 << " est de type: ";
        identify(obj); // Identifier par pointeur
        identify(*obj); // Identifier par reference
        delete obj;
        std::cout << std::endl;
    }

    return 0;
}