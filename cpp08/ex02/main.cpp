/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:44:45 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/26 12:17:38 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list> // Remplacez <MutantStack.hpp> par <list>

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Affiche 17, le dernier élément ajouté" << std::endl;
    std::cout << mstack.top() << std::endl;
    std::cout << "Retire le dernier élément (17)" << std::endl;
    mstack.pop();
    std::cout << "Affiche le nombre d'éléments restants dans la pile (1 élément)" << std::endl;
    std::cout << mstack.size() << std::endl;
    // Ajoute plusieurs autres éléments à la pile
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "La pile contient maintenant {5, 3, 5, 737, 0}" << std::endl;

    // Obtient un itérateur pointant sur le début et la fin de la MutantStack
    MutantStack<int>::iterator it = mstack.begin(); // Pointe sur le premier élément (5)
    MutantStack<int>::iterator ite = mstack.end(); // Pointe "après" le dernier élément

    // Incrémente puis décrémente l'itérateur it, il pointe toujours sur le premier élément
    ++it; // Avance l'itérateur (pointe maintenant sur 3)
    --it; // Recule l'itérateur (pointe à nouveau sur 5, le premier élément)

    std::cout << "Parcourt la MutantStack à l'aide des itérateurs et affiche chaque élément" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl; // Affiche la valeur pointée par l'itérateur
        ++it; // Avance à l'élément suivant
    }

    // Crée une copie de la MutantStack dans une instance de std::stack
    std::stack<int> s(mstack);

    std::cout << "Affichez le contenu de s en le vidant" << std::endl;
    std::cout << "s contains (from top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << ' ';
        s.pop();
    }
    std::cout << std::endl;
    return 0;
}

// int main()
// {
//     std::list<int> mlist; // Utilisez std::list au lieu de MutantStack
//     mlist.push_back(5); // push devient push_back
//     mlist.push_back(17);
//     std::cout << mlist.back() << std::endl; // Utilisez back() pour obtenir le dernier élément
//     mlist.pop_back(); // pop devient pop_back
//     std::cout << mlist.size() << std::endl;
//     mlist.push_back(3);
//     mlist.push_back(5);
//     mlist.push_back(737);
//     mlist.push_back(0);
    
//     // Pour itérer à travers std::list, utilisez directement ses itérateurs
//     std::list<int>::iterator it = mlist.begin();
//     std::list<int>::iterator ite = mlist.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     // La conversion en std::stack n'est pas directement pertinente ici

//     return 0;
// }