/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filereplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:22:59 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 13:19:06 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_H
# define FILEREPLACE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>


class Filereplace {

public:
    Filereplace(std::string& filename, std::string& s1, std::string& s2);
    ~Filereplace();

    void replace_occurrence();
    

private:
    std::string filename;
    std::string s1;
    std::string s2;
    void replaceinstring(std::string& str, std::string& s1, std::string& s2);

};
# endif