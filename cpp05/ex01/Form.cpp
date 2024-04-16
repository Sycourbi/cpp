/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:49 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/15 13:36:12 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeexec, int gradesign) :name(name), isSigned(false), gradeexec(gradeexec), gradesigned(gradesign) {
    if (gradesigned < 1 || gradeexec < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradesigned > 150 || gradeexec > 150) {
        throw Form::GradeTooLowException();
    }
    std::cout << "Constructor default Form" << std::endl;
}
Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeexec(other.gradeexec), gradesigned(other.gradesigned) {
    std::cout << "Copy constructor called for Form" << std::endl;
}
Form& Form::operator=(const Form& other) {
    if (this != &other)
    {
       this->isSigned = other.isSigned;
    }
    std::cout << "Operator assignement called Form" << std::endl;
    return *this;
}
Form::~Form() {
    std::cout << "Destructor Form" << std::endl;
}
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradesigned) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

std::string Form::Getname() const {
    return name;
}
bool Form::GetisSigned() const {
    return isSigned;
}
int Form::Getgradeexec() const {
    return gradeexec;
}
int Form::Getgradesigned() const {
    return gradesigned;
}
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form: " << form.Getname() << ", Is signed: " << (form.GetisSigned() ? "Yes" : "No")
    << ", Grade required to sign: " << form.Getgradesigned()
    << ", Grade required to execute: " << form.Getgradeexec();
    return os;
}