/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:05:06 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/16 12:22:59 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip> // pour std::setprecision

PmergeMe::PmergeMe() {
}
PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
    {
        sequence_vector = other.sequence_vector;
        sequence_deque = other.sequence_deque;
    }
    return *this;
    
}
PmergeMe::~PmergeMe() {
    std::cout << "Destructor default" << std::endl;
}
PmergeMe::PmergeMe(const std::vector<int>& input_sequence) : sequence_vector(input_sequence.begin(), input_sequence.end()), sequence_deque(input_sequence.begin(), input_sequence.end()) {
}
void PmergeMe::mergeInsertSort() {
    std::cout << "Before: ";
    printSequence();
    // Enregistrer le temps de début
    clock_t start_time_vector = clock();
    // Tri du vecteur
    FordJohnsonSort(sequence_vector);
    // Enregistrer le temps de fin
    clock_t end_time_vector = clock();
    std::cout << "After: ";
    printSequence();
    // Calculer le temps écoulé pour le vecteur
    double time_vector = (end_time_vector - start_time_vector) /static_cast<double>(CLOCKS_PER_SEC / 1000);
    // Affichez le temps écoulé pour le vecteur
    std::cout << "Time to process a range of " << sequence_vector.size() << " elements with Ford-Johnson sort (vector): "
              << time_vector << " microseconds\n";
    
    // Enregistrer le temps de début
    clock_t start_time_deque = clock();
    // Tri du deque
    FordJohnsonSort(sequence_deque);
    // Enregistrer le temps de fin
    clock_t end_time_deque = clock();
    // Calculer le temps écoulé pour le vecteur
    double time_deque = static_cast<double>(end_time_deque - start_time_deque) / (CLOCKS_PER_SEC / 1000);
    // Affichez le temps écoulé pour le vecteur
    std::cout << "Time to process a range of " << sequence_deque.size() << " elements with Ford-Johnson sort (deque): "
              << time_deque << " microseconds\n";
}

// Fonction récursive principale pour Ford-Johnson
void fordJohnson(std::vector<int>& arr, int left, int right) {
    if (right - left + 1 > 1)
    { // Assure qu'il y a plus d'un élément dans le sous-tableau
        // Divise la séquence en paires d'éléments et trie chaque paire
        for (int i = left; i <= right - 1; i += 2) {
            // Trie chaque paire en mettant le plus grand élément en deuxième
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }

        // Fusionne les paires triées pour former des sous-séquences
        int middle = left + (right - left) / 2;
        fordJohnson(arr, left, middle);
        fordJohnson(arr, middle + 1, right);
        //print ARR
        // std::cout << "print Arr" << std::endl; 
        // for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        // Fusionne les sous-séquences triées
        std::vector<int> merged(right - left + 1); // Crée un vecteur pour stocker la séquence fusionnée
        int i = left, j = middle + 1, k = 0; // Indices pour les sous-séquences gauche et droite
        while (i <= middle && j <= right) { // Tant que les deux sous-séquences n'ont pas été entièrement parcourues
            if (arr[i] <= arr[j]) { // Si l'élément de la sous-séquence gauche est plus petit ou égal à celui de la sous-séquence droite
                merged[k++] = arr[i++]; // Sélectionne et ajoute l'élément de la sous-séquence gauche à la séquence fusionnée
            } else { // Sinon, l'élément de la sous-séquence droite est plus petit
                merged[k++] = arr[j++]; // Sélectionne et ajoute l'élément de la sous-séquence droite à la séquence fusionnée
            }
        }
        while (i <= middle) { // Ajoute les éléments restants de la sous-séquence gauche
            merged[k++] = arr[i++];
        }
        while (j <= right) { // Ajoute les éléments restants de la sous-séquence droite
            merged[k++] = arr[j++];
        }
        //print MERGED
        // std::cout << "print merged" << std::endl;
        // for (std::vector<int>::iterator it = merged.begin(); it != merged.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        // std::cout << "copy" << std::endl;
        // Copie les éléments fusionnés dans le tableau d'origine
        std::copy(merged.begin(), merged.end(), arr.begin() + left);
    }
}

void PmergeMe::FordJohnsonSort(std::vector<int>& arr) {
    int size = arr.size();
    fordJohnson(arr, 0, size - 1);
}
// Fonction récursive principale pour Ford-Johnson
void fordJohnson(std::deque<int>& arr, int left, int right) {
    if (right - left + 1 > 1)
    { // Assure qu'il y a plus d'un élément dans le sous-tableau
        // Divise la séquence en paires d'éléments et trie chaque paire
        for (int i = left; i <= right - 1; i += 2) {
            // Trie chaque paire en mettant le plus grand élément en deuxième
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
            }
        }

        // Fusionne les paires triées pour former des sous-séquences
        int middle = left + (right - left) / 2;
        fordJohnson(arr, left, middle);
        fordJohnson(arr, middle + 1, right);
        //print ARR
        // std::cout << "print Arr" << std::endl; 
        // for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        // Fusionne les sous-séquences triées
        std::deque<int> merged(right - left + 1); // Crée un vecteur pour stocker la séquence fusionnée
        int i = left, j = middle + 1, k = 0; // Indices pour les sous-séquences gauche et droite
        while (i <= middle && j <= right) { // Tant que les deux sous-séquences n'ont pas été entièrement parcourues
            if (arr[i] <= arr[j]) { // Si l'élément de la sous-séquence gauche est plus petit ou égal à celui de la sous-séquence droite
                merged[k++] = arr[i++]; // Sélectionne et ajoute l'élément de la sous-séquence gauche à la séquence fusionnée
            } else { // Sinon, l'élément de la sous-séquence droite est plus petit
                merged[k++] = arr[j++]; // Sélectionne et ajoute l'élément de la sous-séquence droite à la séquence fusionnée
            }
        }
        while (i <= middle) { // Ajoute les éléments restants de la sous-séquence gauche
            merged[k++] = arr[i++];
        }
        while (j <= right) { // Ajoute les éléments restants de la sous-séquence droite
            merged[k++] = arr[j++];
        }
        //print MERGED
        // std::cout << "print merged" << std::endl;
        // for (std::vector<int>::iterator it = merged.begin(); it != merged.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
        // std::cout << "copy" << std::endl;
        // Copie les éléments fusionnés dans le tableau d'origine
        std::copy(merged.begin(), merged.end(), arr.begin() + left);
    }
}
void PmergeMe::FordJohnsonSort(std::deque<int>& arr) {
    // Implémentation de l'algorithme de tri Ford-Johnson pour std::deque<int>
    // Vous devez implémenter l'algorithme de tri Ford-Johnson pour std::deque<int> ici
    //std::sort(arr.begin(), arr.end());
    int size = arr.size();
    fordJohnson(arr, 0, size - 1);
}
void PmergeMe::printSequence() const {
    for (std::vector<int>::const_iterator it = sequence_vector.begin(); it != sequence_vector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void PmergeMe::printSequencedeque() const {
    for (std::deque<int>::const_iterator it = sequence_deque.begin(); it != sequence_deque.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}