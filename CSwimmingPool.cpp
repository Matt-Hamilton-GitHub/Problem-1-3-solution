#include <cassert>
#include "CSwimmingPool.h"

//constructors
CSwimmingPool::CSwimmingPool(double new_width, double new_length, double new_depth, double new_volume, double new_fill_rate, double new_drain_rate)
{
	assert(new_width > 0.0);
	assert(new_length > 0.0);
	assert(new_depth > 0.0);
	assert(new_volume <= new_width * new_length * new_depth);
	assert(new_fill_rate > 0.0);
	assert(new_drain_rate > 0.0);
	
	_width = new_width;
	_length = new_length;
	_depth = new_depth;
	_volume = new_volume;
	_fill_rate = new_fill_rate;
	_drain_rate = new_drain_rate;
}
CSwimmingPool::CSwimmingPool()
{
	_width = default_width;
	_length = default_length;
	_depth = default_depth;
	_volume = default_volume;
	_fill_rate = default_fill_rate;
	_drain_rate = default_drain_rate;
}
//destructors
CSwimmingPool::~CSwimmingPool()
{

}
//accessors
double CSwimmingPool::getWidth() const
{
	return _width;
}
double CSwimmingPool::getDepth() const
{
	return _depth;
}
double CSwimmingPool::getLength() const
{
	return _length;
}
double CSwimmingPool::getVolume() const
{
	return _volume;
}
double CSwimmingPool::getFillRate() const
{
	return _fill_rate;
}
double CSwimmingPool::getDrainRate() const
{
	return _drain_rate;
}



//mutators
//Since they are mutators, they should be able to alter the values of the class, so I cnaged the functins' type from bool to void.
void CSwimmingPool::setWidth(double new_width)
{
	_width = new_width;
}
void CSwimmingPool::setDepth(double new_depth)
{
	_depth = new_depth;
}
void CSwimmingPool::setLength(double new_length)
{
	_length = new_length;
}
void CSwimmingPool::setFillRate(double new_fill_rate)
{
	_fill_rate = new_fill_rate;
}
void CSwimmingPool::setDrainRate(double new_drain_rate)
{
	_drain_rate = new_drain_rate;
}

//custom methods
//so the method below tells us the amount of water needed to fill up the pool in cubic foot
double CSwimmingPool::getFillVolume() const
{
	return _length * _width * _depth - _volume;
}
//so the method below tells us the amount of time we need to fill up the pool 
//here we need to consider the current rate at witch the water fills the pool
double CSwimmingPool::getFillTime(double fill_fraction) const
{
	//firs af all lets figure out how much time we need to fill up the empty part of the pool
	// I assume that the fill and drain rates repersent 1 cucib foot per minute (in the book it is 1 gallon per minute, meaning that we would need to convert foot ot gallon)
	// to get gallons, we need to divide multiply by 7.481 to get the volume in gallons
	// then we divide it by the fill rate to get time in minutes 
	//and if we want to get fill fraction, we need to divide the result by fill_fraction passed to the mathod
	float time_to_fill_up = getFillVolume() / _fill_rate;
	return time_to_fill_up * fill_fraction ;
}
double CSwimmingPool::getDrainTime(double drain_fraction) const{

    float time_to_drain = _volume / _drain_rate;
	return time_to_drain * drain_fraction;

}

void CSwimmingPool::addWater(double add_time)
{
	// in order to add some water to the pool by considering the fill rate adn amount of time 
	// we need to multiply fill rate by the time 
	float volume_of_water = _fill_rate * add_time;
	_volume += volume_of_water; 
}

void CSwimmingPool::drainWater(double drain_time)
{
	float volume_of_water =  _drain_rate * drain_time;
	_volume -= volume_of_water; 
}