/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:55:12 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/26 12:08:59 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#include <iostream>
#include <cstdlib> // Pour std::rand et std::srand
#include <ctime> // Pour std::time

//ajouter une fonction pour ajouter plusieur nombre en meme temp sans faire appel a addnumber 10000 fois

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Initialisation du générateur de nombres aléatoires

    // Test avec quelques nombres
    Span sp = Span(5);
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test de dépassement de capacité
    try {
        sp.addNumber(13); // Cela devrait lever une exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test avec une plage d'itérateurs
    Span largeSpan(15000);
    std::vector<int> largeRange(15000);
    for (int i = 0; i < 15000; ++i) {
        largeRange[i] = std::rand(); // Remplit le vecteur avec des nombres aléatoires.
    }

    try {
        largeSpan.addRange(largeRange.begin(), largeRange.end()); // Ajoute les nombres à largeSpan

        std::cout << "Shortest span in large span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span in large span: " << largeSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught during large span test: " << e.what() << std::endl;
    }

    return 0;
}
/*
    vector : C'est probablement le conteneur le plus utilisé.
Il représente une séquence d'éléments qui peuvent être accédés directement
par leur position (index). Les vectors permettent des insertions et
suppressions rapides à la fin, mais peuvent être coûteux pour des opérations
similaires au début ou au milieu.
*/