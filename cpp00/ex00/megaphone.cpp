/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:10:09 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/18 15:00:43 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*cout*/
#include <iostream>

//std =  librairie standard namespace
//:: = operateur de resolution de portee
//cout = sortie standard = (stdout);
//<< = redirection d'un flux
//endl = retour ligne
//cin = entree standard = (stdin);

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				argv[i][j] = toupper(argv[i][j]);
				std::cout << argv[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}