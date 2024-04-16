/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:08:34 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/20 12:45:34 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat highLevel("High Level", 1);
        Bureaucrat lowLevel("Low Level", 150);

        PresidentialPardonForm pardonForm("Marvin");
        RobotomyRequestForm robotomyForm("Bender");
        ShrubberyCreationForm shrubberyForm("Home");

        std::cout << highLevel << std::endl;
        std::cout << lowLevel << std::endl;
        std::cout << std::endl;
        std::cout << pardonForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        // Test de signature et d'exécution des formulaires
        highLevel.signForm(pardonForm);
        std::cout << pardonForm << std::endl;
        highLevel.executeForm(pardonForm);
        std::cout << std::endl;
        highLevel.signForm(robotomyForm);
        std::cout << robotomyForm << std::endl;
        highLevel.executeForm(robotomyForm);
        std::cout << std::endl;
        highLevel.signForm(shrubberyForm);
        std::cout << shrubberyForm << std::endl;
        highLevel.executeForm(shrubberyForm);
        std::cout << std::endl;
        // Tentatives avec un bureaucrate de bas niveau
        std::cout << "\nTentatives avec un bureaucrate de bas niveau:" << std::endl;
        lowLevel.signForm(pardonForm);
        lowLevel.executeForm(pardonForm);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
