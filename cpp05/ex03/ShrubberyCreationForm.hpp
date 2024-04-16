/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:51:24 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/20 12:21:07 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

//std::ofstream
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

    class FileNoCreat : public std::exception {
    public:
        // Retourne un message d'erreur lorsque l'exception est lancée
        const char* what() const throw() {
            return "Error creat file";
        }
    };
    
private:
    std::string target;
};

# endif