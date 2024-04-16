/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:18:05 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/15 13:34:56 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>

class Bureaucrat;

class AForm {

public:
    AForm(const std::string& name, int gradeexec, int gradesign);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    
    //rend la class abstraite
    virtual void execute(Bureaucrat const &executor) const = 0;

    void beSigned(const Bureaucrat& bureaucrat);
    std::string Getname() const;
    int Getgradesigned()const;
    int Getgradeexec() const;
    bool GetisSigned()const;

    // Définition des exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form::Grade too high";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form::Grade too low";
        }
    };

    class FormNotSigned : public std::exception {
    public:
        // Retourne un message d'erreur lorsque l'exception est lancée
        const char* what() const throw() {
            return "the form is not signed";
        }
    };
    
private:
    const std::string name;
    bool isSigned;
    const int gradesigned;
    const int gradeexec;

};
std::ostream& operator<<(std::ostream& os, const AForm& b);

# endif