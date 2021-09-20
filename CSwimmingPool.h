#pragma once
class CSwimmingPool
{
public:
	//constructors
	CSwimmingPool(double new_width, double new_length, double new_depth, double new_volume, double new_fill_rate, double new_drain_rate);
	CSwimmingPool();
	
	//destructors
	~CSwimmingPool();
	
	//accessors
	double getWidth() const;
	double getLength() const;
	double getDepth() const;
	double getVolume() const;
	double getFillRate() const;
	double getDrainRate() const;

	//mutators
	void setWidth(double new_width);
	void setDepth(double new_depth);
	void setLength(double new_length);
	void setFillRate(double new_fill_rate);
	void setDrainRate(double new_drain_rate);

	//custom methods
	double getFillVolume() const;
	double getFillTime(double fill_fraction) const;
	double getDrainTime(double drain_fraction) const;
	void addWater(double add_time);
	void drainWater(double drain_time);
	
private:
	static constexpr double default_width = 10;
	static constexpr double default_length = 10;
	static constexpr double default_depth = 10;
	static constexpr double default_volume = 500;
	static constexpr double default_fill_rate = 1.0;
	static constexpr double default_drain_rate = 1.0;

	double _width;
	double _depth;
	double _length;
	double _volume;
	double _fill_rate;
	double _drain_rate;
};