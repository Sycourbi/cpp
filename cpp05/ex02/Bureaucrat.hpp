/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:10:03 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/19 16:32:36 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include "AForm.hpp"

class Form;

class Bureaucrat {

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    void executeForm(AForm const & form);

    int getGrade() const;
    std::string getName() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);

    // Exception pour un grade trop élevé
    class GradeTooHighException : public std::exception {
    public:
        // Retourne un message d'erreur lorsque l'exception est lancée
        const char* what() const throw() {
            return "Bureaucrat grade too high";
        }
    };

    // Exception pour un grade trop bas
    class GradeTooLowException : public std::exception {
    public:
        // Retourne un message d'erreur lorsque l'exception est lancée
        const char* what() const throw() {
            return "Bureaucrat grade too low";
        }
    };


private:
    std::string const name;
    int grade;
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


# endif