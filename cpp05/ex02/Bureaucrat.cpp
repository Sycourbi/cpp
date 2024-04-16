/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:10:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/19 13:30:55 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Constructor default Bureaucrat" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
    std::cout << "Constructor copy Bureaucrat" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
    {
        grade = other.grade;
    }
    std::cout << "Bureaucrat assignement called" << std::endl;
    return (*this);
}
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor default Bureaucrat" << std::endl;
}
int Bureaucrat::getGrade() const {
    return grade;
}
std::string Bureaucrat::getName() const {
    return name;
}
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.Getname() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->name << " couldn’t sign " << form.Getname() << " because " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form) {
    try {
        form.execute(*this); // Tente d'executer le formulaire avec le bureaucrate actuel
        std::cout << this->name << " executed " << form.Getname() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn t execute " << form.Getname() << " because: " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}