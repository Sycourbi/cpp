/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:54:52 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/19 16:56:12 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {   
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    AForm::operator=(other);
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() { 
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    // Vérifier si le formulaire est signé
    if (!this->GetisSigned()) {
        throw FormNotSigned();
    }
    // Vérifier si le grade du bureaucrate est suffisamment élevé
    if (executor.getGrade() > this->Getgradeexec()) {
        throw GradeTooLowException();
    }
    // Nom du fichier à créer
    std::string fileName = this->target + "_shrubbery";
    std::ofstream fileOut(fileName.c_str());
    if (!fileOut) {
        throw FileNoCreat();
    }
    // Écrire deux arbres ASCII plus simples dans le fichier
    fileOut << "  ^" << std::endl;
    fileOut << " ^^^" << std::endl;
    fileOut << "^^^^^" << std::endl;
    fileOut << "  |" << std::endl;
    fileOut << std::endl; // Espacer les arbres
    fileOut << "   ^" << std::endl;
    fileOut << "  ^^^" << std::endl;
    fileOut << " ^^^^^" << std::endl;
    fileOut << "   |" << std::endl;

    fileOut.close();

    std::cout << "Le fichier " << fileName << " a ete cree avec succes." << std::endl;

}