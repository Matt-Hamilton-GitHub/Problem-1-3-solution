// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CSwimmingPool.h"

using std::cout;
using std::endl;

int main()
{
	
	// 	CSwimmingPool(new_width, new_length, new_depth,  new_volume,  new_fill_rate,  new_drain_rate);
	CSwimmingPool pool(10,20,30, 300,5, 3 );
	cout << "The pool's maximum volume is " << pool.getFillVolume() << " cubic feet" << endl;
	cout << "The pool's water volume is   " << pool.getVolume() << " cubic feet" << endl;
    
	//before adding water
	cout << "The pool's water volume is   " << pool.getVolume() << " cubic feet" << endl;
	
	double one_half_full_time = pool.getFillTime(0.5); 
	pool.addWater(one_half_full_time);
	
	//after adding some amount of water
	cout << "The pool's water volume is   " << pool.getVolume() << " cubic feet" << endl;
	
	double full_time = pool.getDrainTime(0.5);
	pool.drainWater(full_time);
	cout << "The pool's water volume is   " << pool.getVolume() << " cubic feet" << endl;
	
	pool.drainWater(pool.getDrainTime(0.5));
	cout << "The pool's water volume is   " << pool.getVolume() << " cubic feet" << endl;
	system("pause");
	return 0;
}
