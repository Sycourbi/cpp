/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:45:11 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 15:34:36 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
/*
    Avantage des reference
    SYNTAXE PROPRE: Pas besoin de l'opérateur de déréférencement (*)
    SECURITE ACCRUE: Une référence ne peut pas être NULL et doit être initialisée
    lors de la déclaration, évitant ainsi certains problèmes liés aux pointeurs.
*/
int	main(void)
{
	// la string
	std::string mystring = "HI THIS IS BRAIN" ;
	// le pointeur sur la string 
	std::string* stringPTR = &mystring;
	// la reference sur la string
	std::string& stringREF = mystring;

	// Affichage des valeurs
    std::cout << "Contenu de la variable myString : " << mystring << std::endl;
    std::cout << "Adresse de la variable myString : " << &mystring << std::endl;
    std::cout << "Valeur pointée par stringPTR : " << *stringPTR << std::endl;
    std::cout << "Adresse pointée par stringPTR : " << stringPTR << std::endl;
    std::cout << "Valeur de la référence stringREF : " << stringREF << std::endl;
    std::cout << "Adresse de la référence stringREF : " << &stringREF << std::endl;

    return 0;
	
}