/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:55:03 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/15 10:38:37 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    // Create an empty array
        
        Array<int> emptyArray;
        
        Array<int> initializedArray(5);
        Array<int> copiedArray(initializedArray);
        
        Array<int> assignedArray;
        assignedArray = initializedArray;
        assignedArray[0] = 100;
        assignedArray[1] = 200;
        assignedArray[3] = 400;
        
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        std::cout << "Initialized array size: " << initializedArray.size() << std::endl;
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "Assigned array[0] value: " << assignedArray[0] << std::endl;
        std::cout << "Assigned array[1] value: " << assignedArray[1] << std::endl;
        std::cout << "Assigned array[3] value: " << assignedArray[3] << std::endl;
    try
    {
        Array<int> initializedArray(5);
        initializedArray[-5];
        std::cout << "-------------\n";
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
