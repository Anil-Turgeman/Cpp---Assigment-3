#include <sstream>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using namespace ariel;


PhysicalNumber::PhysicalNumber(double data, Unit u):data(data), unit(u){}

double PhysicalNumber::getData(){   return data;    }

void PhysicalNumber::setData(double other){ data = other;   }

Unit PhysicalNumber::getUnit(){ return unit;    }

void PhysicalNumber::setUnit(Unit u){   unit = u;   }

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const{
    double res = convert(*this, other); 
    return PhysicalNumber(this->data + res, this->unit);
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const{
    double res = convert(*this, other); 
    return PhysicalNumber(this->data - res, this->unit);
}


PhysicalNumber PhysicalNumber::operator-() const { return PhysicalNumber((-1)*data, unit); }//the unary operator

PhysicalNumber PhysicalNumber::operator+() const { return PhysicalNumber(1*data, unit); }//the unary operator


PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &other){
    double res = convert(*this, other); 
    this->data = this->data + res;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &other){
    double res = convert(*this, other); 
    this->data = this->data - res;
    return *this;

}

bool PhysicalNumber::operator==(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data == number;
}

bool PhysicalNumber::operator!=(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data != number;
}


PhysicalNumber &PhysicalNumber::operator++(){
    this->data++;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--(){
    this->data--;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++(int){
    PhysicalNumber temp(*this);
    data++;
    return temp;
}

PhysicalNumber PhysicalNumber::operator--(int){
    PhysicalNumber temp(*this);
    data--;
    return temp;
}


double PhysicalNumber::convert(const PhysicalNumber &first, const PhysicalNumber &second) const{
    Unit first_unit = first.unit;
    Unit r_unit = second.unit;
    
    double l_val = first.data;
    double r_val = second.data;

    double result = 0;

    switch (r_unit){
        case Unit::KM:

            if (first_unit == Unit::M) { result = r_val * 1000; }

            else if (first_unit == Unit::CM) { result = r_val * 100000; }

            else if (first_unit == Unit::KM) { result = r_val * 1; }

            else { cerr << "can't convert" << endl; }

            break;

        case Unit::M:

            if (first_unit == Unit::CM) { result = r_val * 100; }

            else if (first_unit == Unit::KM) { result = r_val / 1000; }

            else if (first_unit == Unit::M) { result = r_val * 1; }

            else { cerr << "can't convert" << endl; }

            break;

        case Unit::CM:

            if (first_unit == Unit::M) { result = r_val / 100; }

            else if (first_unit == Unit::KM) { result = r_val / 100000; }

            else if (first_unit == Unit::CM) { result = r_val * 1; }

            else { cerr << "can't convert" << endl; }

        break;

        case Unit::HOUR:

            if (first_unit == Unit::MIN) { result = r_val * 60; }
            
            else if (first_unit == Unit::SEC) { result = r_val * 3600; }
            
            else if (first_unit == Unit::HOUR) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        case Unit::MIN:

            if (first_unit == Unit::HOUR) { result = r_val / 60; }
            
            else if (first_unit == Unit::SEC) { result = r_val * 60; }
            
            else if (first_unit == Unit::MIN) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        case Unit::SEC:

            if (first_unit == Unit::MIN) { result = r_val / 60; }
            
            else if (first_unit == Unit::HOUR) { result = r_val / 3600; }
            
            else if (first_unit == Unit::SEC) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        case Unit::TON:

            if (first_unit == Unit::KG) { result = r_val * 1000; }
            
            else if (first_unit == Unit::G) { result = r_val * 1000000; }
            
            else if (first_unit == Unit::TON) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        case Unit::KG:

            if (first_unit == Unit::G) { result = r_val * 1000; }
            
            else if (first_unit == Unit::TON) { result = r_val / 1000; }
            
            else if (first_unit == Unit::KG) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        case Unit::G:

            if (first_unit == Unit::TON) { result = r_val / 1000000; }
            
            else if (first_unit == Unit::KG) { result = r_val / 1000; }
            
            else if (first_unit == Unit::G) { result = r_val * 1; }
            
            else { cerr << "can't convert" << endl; }
            
            break;

        default:

            cerr << "can't convert" << endl;
        }
    return result;
}

bool PhysicalNumber::operator<(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data < number;
}

bool PhysicalNumber::operator>(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data > number;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data <= number;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &value) const{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->data >= number;
}


//cin stream operator

istream& ariel::operator>>(istream &is, PhysicalNumber &p){
    return is;
}


//cout stream operator
ostream& ariel::operator<<(ostream &os, const PhysicalNumber &p){
    switch (p.unit){
        case Unit::KM:{
            os << p.data << "[km]";
            break;
        }

        case Unit::M:{
            os << p.data << "[m]";
            break;
        }

        case Unit::CM:{
            os << p.data << "[cm]";
            break;
        }

        case Unit::HOUR:{
            os << p.data << "[hour]";
            break;
        }

        case Unit::MIN:{
            os << p.data << "[min]";
            break;
        }

        case Unit::SEC:{
            os << p.data << "[sec]";
            break;
        }

        case Unit::TON:{
            os << p.data << "[ton]";
            break;
        }

        case Unit::KG:{
            os << p.data << "[kg]";
            break;
        }

        case Unit::G:{
            os << p.data << "[g]";
            break;
        }
    }
    return os;
}
