/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:08:34 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/20 12:43:53 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form = NULL;

    // Essai de création d'un formulaire valide
    try {
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while creating a valid form: " << e.what() << std::endl;
    }
    
    if (form != NULL) {
        delete form;
        form = NULL;
    }

    AForm* invalidForm = NULL;
    //Essai de création d'un formulaire avec un nom invalide
    try {
        invalidForm = someRandomIntern.makeForm("invalid form name", "Bender");
        std::cout << *invalidForm << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while creating an invalid form: " << e.what() << std::endl;
    }

    if (form != NULL) {
        delete form;
        form = NULL;
    }
    
    // Essai de création d'un formulaire valide
    try {
        form = someRandomIntern.makeForm("shrubbery creation", "Bender");
        std::cout << *form << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught while creating a valid form: " << e.what() << std::endl;
    }

    // Nettoyage si nécessaire
    if (form != NULL) {
        delete form;
        form = NULL;
    }

    return 0;
}
