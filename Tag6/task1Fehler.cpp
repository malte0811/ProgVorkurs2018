#include  <iostream>
#include <vector>		// Vectorklasse nicht includiert

enum  Dimension {x_dim , y_dim , z_dim};

class  Punkt_3D {
public:					// Doppelpunkt hinter public fehlte
// Konstruktor
Punkt_3D(double  x_coor , double  y_coor , double  z_coor){
	_coors [0] = x_coor;		// Arraystellen sind 0 bis 2
	_coors [1] = y_coor;
	_coors [2] = z_coor;		
}
double  get_coor(Dimension  dim) const{		// Ermöglicht Aufruf auf const Objekten
	return  _coors[dim];
}

void  set_coor(Dimension  dim , double  coor){
	_coors[dim] = coor;
}
private:				// Doppelpunkt hinter private fehlte
double  _coors [3];
};

void  punkt_ausgeben(const  Punkt_3D & punkt){
	std::cout  << "x: " << punkt.get_coor(x_dim)
	<< " y: " << punkt.get_coor(y_dim)
	<< " z: " << punkt.get_coor(z_dim) << std::endl;
}
int  main(){
	Punkt_3D  p1(37, 42.5,  5.2);
	Punkt_3D  p2(21, 753,  2.3);
	p2.set_coor(x_dim , 12.3);
	p2.set_coor(y_dim , 17);
	p2.set_coor(z_dim , 3.1);

	punkt_ausgeben(p1);
	punkt_ausgeben(p2);
}