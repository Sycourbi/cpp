/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:07:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/22 16:42:06 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
#include <limits>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

//std =  librairie standard namespace
//:: = operateur de resolution de portee
//std::cout = sortie standard = (stdout);
//<< = redirection d'un flux
//std::endl = retour ligne
//cin = entree standard = (stdin);

int main(int argc, char **argv)
{
	std::string commande;
	PhoneBook contact;
	
	if (argc > 1)
	{
		std::cout <<"aucun argument demander"<< std::endl;
		return (0);
	}
	std::cout <<"*******My Awesome PhoneBook********" << std::endl;
	std::cout <<"ADD = enregistre new contact" << std::endl;
	std::cout <<"SEARCH = affiche contact demander" << std::endl;
	std::cout <<"EXIT = quitte le programme" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << std::endl;
	while (42)
	{
		std::cout<<"Que veux tu faire"<< std::endl;
		getline(std::cin, commande);
		if (std::cin.eof())
			exit(0);
		if (commande == "ADD")
			contact.add();
		else if (commande == "SEARCH")
			contact.search();
		else if (commande == "EXIT")
			return (0);
	}
}