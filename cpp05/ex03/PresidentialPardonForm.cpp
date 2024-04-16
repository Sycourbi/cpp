/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:39 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/19 16:51:27 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon", 25, 5), target(target) {
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!GetisSigned())
    {
        throw FormNotSigned();
    }
    if (executor.getGrade() > Getgradeexec())
        throw GradeTooLowException();
    
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}