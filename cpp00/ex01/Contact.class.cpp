/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:28:22 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/22 16:45:35 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

Contact::Contact(void) {
    //std::cout << "Construtor class Contact" << std::endl;
}

Contact::~Contact(void) {
    //std::cout << "Destructor class Contact" <<std::endl;
}

void    Contact::setfirstname(const std::string &name)
{
    if (!name.empty())
        this->firstname = name;
    else
        std::cerr << "Error: First name cannot be empty." << std::endl;

}
void    Contact::setlastname(const std::string &name)
{
    if (!name.empty())
        this->lastname = name;
    else
        std::cerr << "Error: Last name cannot be empty." << std::endl;
}
void    Contact::setnickname(const std::string &name)
{
    if (!name.empty())
        this->nickname = name;
    else
        std::cerr << "Error: Nickname cannot be empty." << std::endl;
}
void    Contact::setdarksecret(const std::string &name)
{
    if (!name.empty())
        this->darkestsecret = name;
    else
        std::cerr << "Error: Nickname cannot be empty." << std::endl;
}
void    Contact::setphonenumber(const int number)
{
    this->phonenumber = number;
}
std::string Contact::getfirstname() const 
{
    return firstname;
}
std::string Contact::getlastname() const
{
    return lastname;
}
std::string Contact::getnickname() const
{
    return nickname;
}
