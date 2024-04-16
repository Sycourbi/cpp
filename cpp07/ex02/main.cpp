/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:43:39 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/11 16:01:27 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Array.tpp"
#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 10;
        std::cout << intArray[i] << std::endl;
    }

    try {
        std::cout << intArray[8] << std::endl; // Doit lancer une exception
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (unsigned int i = 0; i < stringArray.size(); ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    // Utilisation de l'opérateur de copie
    Array<int> copiedIntArray = intArray;
    std::cout << "Copied int array:" << std::endl;
    for (unsigned int i = 0; i < copiedIntArray.size(); ++i) {
        std::cout << copiedIntArray[i] << std::endl;
    }

    // Modification de l'original pour voir si la copie reste inchangée
    intArray[0] = 100;
    std::cout << "Original intArray after modification:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << std::endl;
    }

    std::cout << "Copied intArray to check if it remains unchanged:" << std::endl;
    for (unsigned int i = 0; i < copiedIntArray.size(); ++i) {
        std::cout << copiedIntArray[i] << std::endl;
    }
    
    return 0;
}