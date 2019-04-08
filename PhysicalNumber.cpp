#include "PhysicalNumber.h"
#include <iostream>
using namespace ariel;

PhysicalNumber::PhysicalNumber(double x, Unit u) : data(x), unit(u) {}

double PhysicalNumber::getData() {
    return data;
}

Unit PhysicalNumber::getUnit() {
    return unit;
}

void PhysicalNumber::setData(double d) {
    data = d;
}

void PhysicalNumber::setUnit(Unit u) {
    unit = u;
}

const PhysicalNumber PhysicalNumber::operator+() {
    return PhysicalNumber(data, unit);
}

const PhysicalNumber& PhysicalNumber::operator++() {
    return *this;
}

const PhysicalNumber& PhysicalNumber::operator++(int unused) {
    return *this;
}

const PhysicalNumber PhysicalNumber::operator+=(const PhysicalNumber& other) {
    return PhysicalNumber(0.0,unit);
}

const PhysicalNumber ariel::operator+(PhysicalNumber& left, const PhysicalNumber& right) {
    return PhysicalNumber(0.0, Unit::KM);
}

const PhysicalNumber PhysicalNumber::operator-() {
    return PhysicalNumber(-data, unit);
}

const PhysicalNumber& PhysicalNumber::operator--() {
    return *this;
}

const PhysicalNumber& PhysicalNumber::operator--(int unused) {
    return *this;
}

const PhysicalNumber PhysicalNumber::operator-=(const PhysicalNumber& other) {
    return PhysicalNumber(0.0,unit);
}

const PhysicalNumber ariel::operator-(const PhysicalNumber& left, const PhysicalNumber& right) { 
    return PhysicalNumber(0.0, left.unit);
}

bool PhysicalNumber::operator==(const PhysicalNumber& other) {
    return false;
}

bool PhysicalNumber::operator!=(const PhysicalNumber& other) {
    return false;
}

bool PhysicalNumber::operator>(const PhysicalNumber& other) {
    return false;
} 

bool PhysicalNumber::operator<(const PhysicalNumber& other) {
    return false;
}

bool PhysicalNumber::operator<=(const PhysicalNumber& other) {
    return false;
}

bool PhysicalNumber::operator>=(const PhysicalNumber& other) {
    return false;
}

ostream& ariel::operator<<(ostream& os, const PhysicalNumber& pn) {
    string str;
    switch (pn.unit) {
        case Unit::KM :
            str = "km";
            break;
        case Unit::M :
            str = "m";
            break;
        case Unit::CM :
            str = "cm";
            break;
        case Unit::HOUR :
            str = "hour";
            break;
        case Unit::MIN :
            str = "min";
            break;
        case Unit::SEC :
            str = "sec";
            break;
        case Unit::TON :
            str = "ton";
            break;
        case Unit::KG :
            str = "kg";
            break;
        case Unit::G :
            str = "g";
            break;
    }
    return os << pn.data << "[" << str << "]";
}

istream& ariel::operator>>(istream& is, PhysicalNumber& pn) {
    is >> pn.data;
    return is;
}
