/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:08:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/11 16:26:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    // Création d'un vecteur d'entiers à partir du tableau arr
    // Le constructeur prend deux itérateurs : le début et la fin de la séquence à copier.
    // `arr` est l'adresse du premier élément du tableau, `arr + sizeof(arr) / sizeof(arr[0])`
    // calcule l'adresse juste après le dernier élément du tableau, ce qui correspond à la fin de la séquence.
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    try {
        std::vector<int>::iterator it = easyfind(vec, 3); // Recherche du nombre 3
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Value not found in the container: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 6); // Recherche du nombre 6
        std::cout << "Found: " << *it << std::endl; // Cette ligne ne devrait pas s'exécuter
    } catch (const std::exception& e) {
        std::cout << "Value not found in the container: " << e.what() << std::endl;
    }

    return 0;
}
/*
    vector : C'est probablement le conteneur le plus utilisé.
Il représente une séquence d'éléments qui peuvent être accédés directement
par leur position (index). Les vectors permettent des insertions et
suppressions rapides à la fin, mais peuvent être coûteux pour des opérations
similaires au début ou au milieu.
    deque (double-ended queue) : Semblable au vector, mais optimisé pour des
insertions et suppressions rapides aux deux extrémités. Les performances pour
accéder à des éléments au milieu sont généralement moins bonnes que celles des
vectors.
    list : Une liste doublement chaînée permettant des insertions et
suppressions efficaces n'importe où dans la liste. Cependant, l'accès direct
par index est lent car il nécessite un parcours séquentiel depuis le début ou
la fin de la liste.
    forward_list : Une liste simplement chaînée, offrant des performances
légèrement meilleures que list pour certaines opérations, mais ne peut être
parcourue que dans un sens.
    array : Conteneur de taille fixe stockant une séquence d'éléments. 
Sa taille doit être connue à la compilation. Offre des performances d'accès
direct similaires à un tableau brut, mais avec les avantages de la STL.
string : Spécialisé pour stocker des séquences de caractères, offre de
nombreuses fonctions pour manipuler des chaînes de texte.
*/