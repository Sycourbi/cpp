/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:56:17 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 12:47:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {


    Data myData; // Initialisation de Data
    myData.number = -42;
    myData.next =  NULL;
    Data* originalPtr = &myData; // Pointeur original vers l'objet Data

    uintptr_t serializedData = Serializer::serialize(originalPtr); // Serialisation
    Data* deserializedPtr = Serializer::deserialize(serializedData); // Deserialisation

    // Vérification que les pointeurs sont égaux
    if (deserializedPtr == originalPtr) {
        std::cout << "La désérialisation a réussi !" << std::endl;
    } else {
        std::cout << "La désérialisation a échoué." << std::endl;
    }
    // Modification de la donnee serialisee pour simuler une erreur.
    uintptr_t modifiedSerializedData = serializedData + 1;
    // Tentative de désérialisation avec la donnée modifiée.
    deserializedPtr = Serializer::deserialize(modifiedSerializedData);

    if (deserializedPtr == originalPtr) {
        std::cout << "La désérialisation a réussi !" << std::endl;
    } else {
        std::cout << "La désérialisation a échoué." << std::endl;
    }

    return 0;
}