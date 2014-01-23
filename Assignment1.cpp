/********************************************************************* 
 *  ** Program Filename: Assignment1.cpp 
 *  ** Author: Brian Boly
 *  ** Date: 20 January 2014
 *  ** Description: The 4 exercises of Assignment 1 
 *  ** Input: N/a
 *  ** Output: Solutions to cryptarithmetic puzle, matrix of the product of 1st  *  ** two arguments, sum of all multiples of 3 or 5 below 1000, which suitor 
 *  ** will win
 *  *********************************************************************/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/********************************************************************* 
 *  ** Function: arrs
 *  ** Description: sums the values of array 1 and 2 and stores them in array 3
 *  ** Parameters: 3 10x10 arrays, a1 a2 and a3
 *  ** Pre-Conditions: arrays have been initialized and 1 and 2 given random values
 *  ** Post-Conditions: array 3 contains the sum of 1 and 2
 *  *********************************************************************/

int arrs(int a1[10][10], int a2[10][10], int a3[10][10]) {
	//use two nested for loops to iterate through all of the first 2 arrays
	//and store their products in the 3rd array
	for (int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			a3[i][j] = a1[i][j] * a2[i][j];
}

/********************************************************************* 
 *  ** Function: mult
 *  ** Description: Sums the multiples of 3 and 5 under 1000
 *  ** Parameters: none
 *  ** Pre-Conditions: Sum is unknown
 *  ** Post-Conditions: Sum is calculated and returned
 *  *********************************************************************/ 


int mult(){
	//creat an integer to keep track of the sum
	int sum = 0;

	//use a for loop to iterate from 0 to 1000
	for(int i = 0; i < 1000; i++)
		//if i is a multiple of 3 or 5, increase sum by i
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	return sum;
}

/********************************************************************* 
 *  ** Function: eve
 *  ** Description: Calculates where to stand in line to marry eve
 *  ** Parameters: Number of suitors
 *  ** Pre-Conditions: Number of suitors is known
 *  ** Post-Conditions: Position in line is calculated
 *  *********************************************************************/ 


int eve(int n){
	//initialize and fill the vector with n integers
	vector<int> suitors;
	for(int i = 1; i <= n; i++)
		suitors.push_back (i);
	
	//while the vector isn't empty, continue erasing the 3rd suitor in line
	int count = 1;
	while(suitors.size() > 1)
		suitors.erase(suitors.begin() + count);
		count += 2;
		
	return suitors.front();
}

int main(){
	//initalize 4 integers to corespond with each individual letter
	int t = 0;
	int o = 0;
	int g = 0;
	int d = 0;
	//4 nested for loops, which check to see if the values of the integers
	//are all different and if they are, break the loop, otherwise increase
	//each variable by 1 using the counter of the respective for loop
	for(int a = 0; a <= 9; a++){
		if(t!=o && t!=g && t!=d && o!=g && o!=d && g!=d)
			break;
		for(int b = 0; b <= 9; b++){
			if(t!=o && t!=g && t!=d && o!=g && o!=d && g!=d)
				break;
			for(int c = 0; c <= 9; c++){
				if(t!=o && t!=g && t!=d && o!=g && o!=d && g!=d)
					break;
				for(int i = 0; i <= 9; i++){
					if(t!=o && t!=g && t!=d && o!=g && o!=d && g!=d)
						break;
					d=i;
				}
				g=c;
			}
			o=b;
                }
		t=a;
	}

	//print the final result of each variable
	cout << "The answers to the cryptarithmetic puzzle are: " << endl;
	cout << "T = " << t << endl;
	cout << "O = " << o << endl;
	cout << "G = " << g << endl;
	cout << "D = " << d << endl;
	

	//initialize 3 10x10 arrays
	int a1[10][10];
	int a2[10][10];
	int a3[10][10];
	
	//fill the arrays with random numbers
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++){
			a1[i][j] = rand() % 5;
			a2[i][j] = rand() % 5;
		}
	
	//print the arrays before the operation
	cout << "2d array 1: " << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++)
			cout << a1[i][j] << " ";
		cout << endl;
	}

	cout << "2d array 2: " << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++)
			cout << a2[i][j] << " ";
		cout << endl;
	}

	//run the arrs function on the 3 arrays
	arrs(a1, a2, a3);
	
	//print out the product of the first 2 arrays
	cout << "2d array 3 (product of array 1 and 2)" << endl;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++)
			cout << a3[i][j] << " ";
		cout << endl;
	}
	
	//create an integer m to store the value of the return of mult
	int m = mult();
	
	//print m
	cout << "The sum of all multiples of 3 or 5 under 1000 = " << m << endl;
	
	//run the eve function and print the result
	cout << "The winner of a line of 6 suitors is: " << eve(6) << endl;
	
	return 0;
}
