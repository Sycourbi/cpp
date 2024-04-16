/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filereplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:24:24 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/27 12:10:57 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filereplace.hpp"

Filereplace::Filereplace(std::string& filename, std::string& s1, std::string& s2) : filename(filename), s1(s1), s2(s2) {
    
}
Filereplace::~Filereplace() {
    
}
void Filereplace::replace_occurrence() {
    
    //Crée un objet inputFile de la classe std::ifstream et ouvre le fichier 
    //dont le nom est spécifié dans la variable filename pour la lecture.
    std::ifstream inputFile(filename);
    //is_open return :true ou false
    if (!inputFile.is_open())
    {
            std::cerr << "Error: open filename." << std::endl;
            return;
    }
    //Crée un objet outputFile de la classe std::ofstream et ouvre (ou crée) un fichier avec le nom construit
    //en ajoutant l'extension '.replace' au nom du fichier d'entrée pour l'écriture.
    std::ofstream outputFile(filename + ".replace");
    if (!outputFile.is_open())
    {
        inputFile.close();
        std::cerr << "Error: create outputfile." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        replaceinstring(line, s1, s2);
        outputFile << line << std::endl;
    }
    inputFile.close();
    outputFile.close();
}

void Filereplace::replaceinstring(std::string& str, std::string& s1, std::string& s2) {
    size_t pos = 0;
    size_t foundpos;

    /*
        trouver toutes les occurrences de la sous-chaîne s1 dans la chaîne str.
        La fonction find retourne la position de la première occurrence de
        s1 dans str, ou std::string::npos si aucune occurrence n'est trouvée
    */
    while ((foundpos = str.find(s1, pos)) != std::string::npos)
    {
        // Construire une nouvelle chaîne en concaténant la partie avant, la nouvelle partie et la partie après
        str = str.substr(0, foundpos) + s2 + str.substr(foundpos + s1.length());
        // Mettre à jour la position pour éviter une boucle infinie
        pos = foundpos + s2.length();
    }
}