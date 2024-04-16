/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:11:06 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/20 12:22:09 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {
}
Intern::Intern(const Intern& other) {
    *this = other;
}
Intern& Intern::operator=(const Intern& /*other*/) {
    
    return *this;
}
Intern::~Intern() {
}
AForm* Intern::makeForm(const std::string formName, const std::string target) {
    AForm* form = NULL;

    form = formName == "presidential pardon" ? new PresidentialPardonForm(target) : form;
    form = formName == "robotomy request" ? new RobotomyRequestForm(target) : form;
    form = formName == "shrubbery creation" ? new ShrubberyCreationForm(target) : form;

    if (form) {
        std::cout << "Intern creates " << formName << std::endl;
    } else {
        throw Intern::InvalidString();
    }
    return form;
}