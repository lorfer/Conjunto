// Conjunto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include "Conjunto.h"


int main()
{
    std::cout << "Hello World!\n";
}


void cConjunto::Copy(double * p_FromArray, int p_startPos, int p_Count)
{
	for (int cont = p_startPos; cont < p_Count && count < m_Dimension; cont++)
	{
		m_Elements[cont] = p_FromArray[cont];
		return;
	}
}

cConjunto::cConjunto(void)
{
	m_Dimension = 0;
}

cConjunto::cConjunto(double* p_values, int p_cants)
{
	if (p_values == NULL)
	{
		return;
	}
	m_Dimension = p_cants;
	m_Elements = new double[m_Dimension];
	Copy(p_values, 0, m_Dimension);

}

int cConjunto::getDimension()
{
	return m_Dimension;
}

double cConjunto::getElement(int p_posicion)
{
	if (p_posicion > -1 && p_posicion == m_Dimension)
	{
		return m_Elements[p_posicion];
	}
	else
	{
		return 0;
	}
	
}

void cConjunto::Alta(double p_value) {
	double* tempElems = m_Elements; // copy RAm
	m_Dimension++;
	m_Elements = new double[m_Dimension];
	Copy(tempElems, 0, m_Dimension - 1);
	m_Elements[m_Dimension - 1] = p_value;
}

void cConjunto::Copy(double* p_FromArray, int p_startPos, int p_Count) {
	for (int i = p_startPos;i < p_Count && i < m_Dimension;i++)
		m_Elements[i] = p_FromArray[i];
	return;
}
void cConjunto::Vaciar() {
	m_Dimension = 0;
	m_Elements = new double(0);
} // todos los elementos

double cConjunto::Baja(int p_posicion) {
	double* tempElems = m_Elements;
	Copy(tempElems, 0, p_posicion);
	m_Dimension--;
	m_Elements = new double(m_Dimension);
	for (int i = p_posicion + 1;i < m_Dimension + 1;i++)
		m_Elements[i - 1] = tempElems[i];
	

}

cConjunto  cConjunto::unir(cConjunto  p_objConEste, bool  p_Distinct) {
	int  intIter = 0;
	cConjunto  objNewConjunto = cConjunto();

	for (intIter = 0; intIter < m_Dimension; intIter++) {
		objNewConjunto.Alta(m_Elements[intIter]);
	}

	for (int I = 0; I < p_objConEste.getDimension(); I++) {
		objNewConjunto.Alta(p_objConEste.getElement(I));
	}

	if (p_Distinct == true)
	{
		return  objNewConjunto;
	}
	else
	{
		return p_objConEste;
	}
	
}
cConjunto cConjunto::unir(cConjunto p_objConEste) {
	double* TodosLosElems = new

		double[m_Dimension + p_objConEste.getDimension()];

	int intIter = 0;
	for (intIter = 0;intIter < m_Dimension;intIter++) {
		TodosLosElems[intIter] = m_Elements[intIter];
	}
	for (int I = 0;I < p_objConEste.getDimension();I++) {
		TodosLosElems[intIter] = p_objConEste.getElement(I);
		intIter++;
	}
	cConjunto objNewConjunto = cConjunto(TodosLosElems,

		m_Dimension + p_objConEste.getDimension());

	return objNewConjunto;
}

cConjunto cConjunto::operator+(cConjunto p_newSet) {
	return this->unir(p_newSet);
}



void::interset()
{
	cConjunto::operator+()

}