/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:08:34 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/15 14:39:10 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat highRank("Alice", 1);
        std::cout << highRank << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat lowRank("Bob", 150);
        std::cout << lowRank << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat tooHigh("Charlie", 0);
        std::cout << tooHigh << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat tooLow("Dave", 151);
        std::cout << tooLow << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Form f1("Form1", 25, 50);
        std::cout << f1 << std::endl;
        Bureaucrat signer("Eve", 49);
        std::cout << signer << std::endl;
        signer.signForm(f1);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Form f2("Form2", 75, 100);
        std::cout << f2 << std::endl;
        Bureaucrat signer("Frank", 101);
        signer.signForm(f2);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Form tooToughForm("ImpossibleForm", 0, 1);
    } catch (std::exception& e) {
        std::cerr << "Error while creating form: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Form tooEasyForm("UselessForm", 151, 150);
    } catch (std::exception& e) {
        std::cerr << "Error while creating form: " << e.what() << std::endl;
    }

    return 0;
}