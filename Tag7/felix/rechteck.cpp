 #include "rechteck.hpp"
#include <iostream>

Rechteck::Rechteck(
    double x_min,
    double x_max,
    double y_min,
    double y_max)
{
	if (x_min > x_max or y_min > y_max) 
		throw "Fehler: Min größer als Max";	// Werfe String
    _min[x_dim] = x_min;
    _min[y_dim] = y_min;
    _max[x_dim] = x_max;
    _max[y_dim] = y_max;
    compute_flaecheninhalt();
}

void Rechteck::print() const
{
    std::cout 
       << "[" << _min[x_dim] << ", " << _max[x_dim]<< "] "
       << "x [" << _min[y_dim] << ", " << _max[y_dim] << "]" 
       << " mit Flaecheninhalt " << _flaecheninhalt << std::endl;
}

void Rechteck::compute_flaecheninhalt()
{
    _flaecheninhalt = (_max[x_dim] - _min[x_dim]) * (_max[y_dim]- _min[y_dim]);
}

double Rechteck::get_min(Dimension dim) const
{
    return _min[dim];
}

void Rechteck::set_min(double new_min, Dimension dim)
{
	if (new_min >_max[dim])
		throw "Fehler: Min größer als Max in Dimension "+std::to_string(dim);
    _min[dim] = new_min;
    compute_flaecheninhalt();
}

double Rechteck::get_max(Dimension dim) const
{
    return _max[dim];
}

void Rechteck::set_max(double new_max, Dimension dim)
{
	if (new_max <_min[dim]) 
		throw "Fehler: Min größer als Max in Dimension "+std::to_string(dim);
    _max[dim] = new_max;
    compute_flaecheninhalt();
}









