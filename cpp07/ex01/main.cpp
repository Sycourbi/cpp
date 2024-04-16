/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:29:47 by sycourbi          #+#    #+#             */
/*   Updated: 2024/02/27 16:34:24 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int tabInt[] = {1, 2, 3, 4, 5};
    std::string tabString[] = {"un", "deux", "trois", "quatre", "cinq"};

    // Test avec un tableau d'entiers
    std::cout << "Tableau d'entiers:" << std::endl;
    iter(tabInt, 5, print);

    // Test avec un tableau de chaînes de caractères
    std::cout << "Tableau de chaînes:" << std::endl;
    iter(tabString, 5, print);

    return 0;
}