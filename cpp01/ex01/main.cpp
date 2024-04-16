/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:19:54 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 16:26:02 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	int N = 5;
	std::string nom = "ZombieHorde";
	Zombie* horde = zombieHorde(N, nom);
	unsigned int i = 0;
	while(i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	
	return (0);
}