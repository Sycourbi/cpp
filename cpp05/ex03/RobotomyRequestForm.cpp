/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:55:39 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/19 16:51:33 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib> // Pour srand et rand
#include <ctime>   // Pour time

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45), target(target) {   
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    // Vérification si le formulaire est signé et si le grade du bureaucrate est suffisant
    if (!this->GetisSigned())
    {
        throw FormNotSigned();
    }
    if (executor.getGrade() > this->Getgradeexec())
    {
        throw GradeTooLowException();
    }

    // Affichage des bruits de perçage
    std::cout << "* Drilling noises... Brrrrrrr... *\n";

    // Initialisation du générateur de nombres aléatoires
  
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Tentative de robotomisation avec un résultat aléatoire
    if (std::rand() % 2 == 0) {
        std::cout << this->target << " has been robotomized successfully.\n";
    } else {
        std::cout << "The robotomy on " << this->target << " failed.\n";
    }
}