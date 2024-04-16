/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:10:03 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/15 12:07:25 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    int getGrade() const;
    std::string getName() const;
    void incrementGrade();
    void decrementGrade();

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