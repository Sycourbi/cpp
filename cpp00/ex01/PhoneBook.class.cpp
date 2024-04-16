/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:25:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/22 15:07:34 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include <iomanip>
#include <limits>
#include <sstream>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"


PhoneBook::PhoneBook() : index(0) {
    //std::cout << "Constructor class PhoneBook" << std::endl;
}
PhoneBook::~PhoneBook(void) {
    //std::cout << "Destructor class PhoneBook" << std::endl;
}

void PhoneBook::add(void)
{
    std::string reponse;
    bool contactIsValid = false;
    
    if (index == 8)
        index = 0;
    while (!contactIsValid) 
    {
        std::cout << "First name" << std::endl;
        std::getline(std::cin, reponse);
        if (std::cin.eof())
            exit(0);
        if (!reponse.empty()) 
        {
            contact[index].setfirstname(reponse);
            std::cout << "Last name" << std::endl;
            std::getline(std::cin, reponse);
                if (std::cin.eof())
                    exit(0);
            if (!reponse.empty()) 
            {
                contact[index].setlastname(reponse);
                std::cout << "Nickname" << std::endl;
                std::getline(std::cin, reponse);
                if (std::cin.eof())
                    exit(0);
                if (!reponse.empty()) 
                {
                    contact[index].setnickname(reponse);
                    std::cout << "Phone number" << std::endl;
                    std::getline(std::cin, reponse);
                    std::istringstream iss(reponse);
                    int number;
                    if (iss >> number)
                    {
                        contact[index].setphonenumber(number);
                        std::cout << "Darkest secret" << std::endl;
                        std::getline(std::cin, reponse);
                        if (std::cin.eof())
                            exit(0);
                        if (!reponse.empty()) 
                        {
                            contact[index].setdarksecret(reponse);
                            contactIsValid = true;
                        }
                        else
                            std::cerr << "Error: Darkest secret cannot be empty." << std::endl;
                    }
                    else
                        std::cerr << "Error: Phone number invalid." << std::endl;
                }
                else
                    std::cerr << "Error: Nickname cannot be empty." << std::endl;
            }
            else
                std::cerr << "Error: Last name cannot be empty." << std::endl;
        }
        else 
         std::cerr << "Error: First name cannot be empty." << std::endl;
    }
    index++;
}

void PhoneBook::search(void)
{
    std::cout << std::setw(10) << std::right << "Index" << "|"
              << std::setw(10) << std::right << "Fisrt name" << "|"
              << std::setw(10) << std::right << "Last name" << "|"
              << std::setw(10) << std::right << "Nickname" << std::endl;
   for (int i = 0; i < 8; ++i) {
        std::string truncatedFirstname = contact[i].getfirstname().substr(0, 10);
        std::string truncatedLastname = contact[i].getlastname().substr(0, 10);
        std::string truncatedNickname = contact[i].getnickname().substr(0, 10);

        // Tronquer et remplacer le dernier caractère par un point
        if (truncatedFirstname.length() == 10) truncatedFirstname[9] = '.';
        if (truncatedLastname.length() == 10) truncatedLastname[9] = '.';
        if (truncatedNickname.length() == 10) truncatedNickname[9] = '.';

        std::cout << std::setw(10) << std::right << i << "|"
                  << std::setw(10) << std::right << truncatedFirstname << "|"
                  << std::setw(10) << std::right << truncatedLastname << "|"
                  << std::setw(10) << std::right << truncatedNickname << std::endl;
    }
    int indexcontact;
    std::cout << "Entre l'index du contact a afficher" << std::endl;
    while (!(std::cin >> indexcontact)) {
        std::cin.clear();  // Réinitialiser le statut de la saisie
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Vider le tampon d'entrée
        std::cout << "Invalid input. Please enter a valid index: " << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (indexcontact >= 0 && indexcontact < 8)
    {
        std::cout << "Contact Information:" << std::endl;
        std::cout << std::setw(10) << std::right << "Index" << ": " << indexcontact << std::endl;
        std::cout << std::setw(10) << std::right << "First name" << ": " << contact[indexcontact].getfirstname() << std::endl;
        std::cout << std::setw(10) << std::right << "Last name" << ": " << contact[indexcontact].getlastname() << std::endl;
        std::cout << std::setw(10) << std::right << "Nickname" << ": " << contact[indexcontact].getnickname() << std::endl;
    }
    else
        std::cout << "index invalide" << std::endl;
}