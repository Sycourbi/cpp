/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

class Form {

public:
    Form(const std::string& name, int gradeexec, int gradesign);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    
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
    
private:
    const std::string name;
    bool isSigned;
    const int gradeexec;
    const int gradesigned;

};
std::ostream& operator<<(std::ostream& os, const Form& b);

# endif