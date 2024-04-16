/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:49 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/15 18:09:14 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradesign, int gradeexec) : name(name), isSigned(false), gradesigned(gradesign), gradeexec(gradeexec) {
    if (gradesigned < 1 || gradeexec < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradesigned > 150 || gradeexec > 150) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Constructor default AForm" << std::endl;
}
AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradesigned(other.gradesigned), gradeexec(other.gradeexec) {
    std::cout << "Copy constructor called for AForm" << std::endl;
}
AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
    {
       this->isSigned = other.isSigned;
    }
    std::cout << "Operator assignement called AForm" << std::endl;
    return *this;
}
AForm::~AForm() {
    std::cout << "Destructor AForm" << std::endl;
}
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradesigned) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

std::string AForm::Getname() const {
    return name;
}
bool AForm::GetisSigned() const {
    return isSigned;
}
int AForm::Getgradeexec() const {
    return gradeexec;
}
int AForm::Getgradesigned() const {
    return gradesigned;
}
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "AForm: " << form.Getname() << ", Is signed: " << (form.GetisSigned() ? "Yes" : "No")
    << ", Grade required to sign: " << form.Getgradesigned()
    << ", Grade required to execute: " << form.Getgradeexec();
    return os;
}