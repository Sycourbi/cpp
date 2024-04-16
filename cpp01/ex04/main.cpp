/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:18:07 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 13:50:50 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Filereplace.hpp"

int main (int argc, char** argv)
{
    if (argc != 4)
    {
           std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    std::string filename(argv[1]);
    std::string s1(argv[2]);
    std::string s2(argv[3]);

    //ouvre un fichier en lecture
    std::ifstream file(filename);
    // Vérifier si le fichier existe et n'est pas vide
    if (!file.is_open() || file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Error: Unable to open or empty file." << std::endl;
        return 1;
    }
    file.close();
    // Vérifier si s1 et s2 ne sont pas des chaînes vides
    if (s1.empty() || s2.empty()) 
    {
        std::cerr << "Error: s1 and s2 must not be empty." << std::endl;
        return 1;
    }
    Filereplace filereplace(filename, s1, s2);
    filereplace.replace_occurrence();
    
    std::cout << "Replacement completed. Check " << filename << ".replace" << std::endl;
    return 0;
    
}