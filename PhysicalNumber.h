#ifndef PhysicalNumber_H
#define PhysicalNumber_H

#include <iostream>
#include <string>
#include "Unit.h"
using namespace std;

namespace ariel {
    class PhysicalNumber{
        private:
            Unit unit;
            double data;

        public:
            PhysicalNumber(double, Unit);
            double getData();
            Unit getUnit();
            void setData(double);
            void setUnit(Unit);
            
            const PhysicalNumber operator+();
            const PhysicalNumber& operator++();       //prefix
            const PhysicalNumber& operator++(int);    //postfix
            const PhysicalNumber operator+=(const PhysicalNumber&);
            friend const PhysicalNumber operator+(PhysicalNumber&, const PhysicalNumber&);
            const PhysicalNumber operator-();
            const PhysicalNumber& operator--();        //prefix
            const PhysicalNumber& operator--(int);     //postfix
            const PhysicalNumber operator-=(const PhysicalNumber&);
            friend const PhysicalNumber operator-(const PhysicalNumber&, const PhysicalNumber&);

            bool operator==(const PhysicalNumber&);
            bool operator!=(const PhysicalNumber&);
            bool operator>(const PhysicalNumber&);
            bool operator<(const PhysicalNumber&);
            bool operator<=(const PhysicalNumber&);
            bool operator>=(const PhysicalNumber&);
        
            friend ostream& operator<<(ostream&, const PhysicalNumber&);
            friend istream& operator>>(istream&, PhysicalNumber&);    
    };
}

#endif
