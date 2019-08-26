#pragma once
#include <string>
using namespace std;
class cConjunto {


private:
	double* m_Elements;
	int m_Dimension;
	string xstr = "hola";
	void Copy(double* p_FromArray, int p_startPos, int p_Count);


public:
	//constructores
	cConjunto(void);
	cConjunto(double* p_values, int p_cants);

	//Metodos especiales
	int getDimension();
	double getElement(int p_posicion);

	//Metodos de alta y baja
	
	void  Alta(double  p_value);
	void  Vaciar();
	//  todos  los  elementos
	double  Baja(int  p_posicion);

	cConjunto unir(cConjunto p_objConEste, bool p_Distinct);
	cConjunto unir(cConjunto p_objConEste);

	cConjunto  operator+(cConjunto  p_newSet);
	void interset();

};