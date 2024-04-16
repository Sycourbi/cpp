/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:03:56 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/15 15:32:56 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream> //istringstream
#include <vector>
#include <limits>
#include <set>

bool verif_sequence(std::vector<int>& sequence)
{
    std::set<int> seen_numbers;
    const int max_int = std::numeric_limits<int>::max();

    // Parcours de chaque élément de la séquence à l'aide d'une boucle traditionnelle
    for (size_t i = 0; i < sequence.size(); ++i) {
        long int num = sequence[i];

        // Vérification si le nombre est négatif ou dépasse INT_MAX
        if (num < 0 || num > max_int) {
            std::cerr << "Error: Integer value out of range." << std::endl;
            return false;
        }

        // Vérification s'il y a déjà ce nombre dans la séquence
        if (seen_numbers.find(num) != seen_numbers.end()) {
            std::cerr << "Error: Duplicate integer found." << std::endl;
            return false;
        }

        // Ajout du nombre à l'ensemble des nombres déjà rencontrés
        seen_numbers.insert(num);
    }

    return true;
}

int main(int argc, char **argv) 
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sequence of integers>" << std::endl;
        return 1;
    }

    std::vector<int> input_sequence;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        long int num;
        while (iss >> num) {
            if (num < 0) {
                std::cerr << "Error: Negative integer found." << std::endl;
                return 1;
            }
            input_sequence.push_back(num);
        }
    }
    if (!verif_sequence(input_sequence))
        return 1;
    PmergeMe pmerge_me(input_sequence);
    pmerge_me.mergeInsertSort();
    return 0;
}