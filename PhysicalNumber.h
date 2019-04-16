#ifndef PhysicalNumber_H
#define PhysicalNumber_H

#include <iostream>
#include <string>
#include "Unit.h"
using namespace std;

namespace ariel{
    class PhysicalNumber{
        private:
            Unit unit;
            double data;

       public:
            PhysicalNumber(double, Unit);
            double getData();
            void setData(double);
            Unit getUnit();
            void setUnit(Unit);

            PhysicalNumber operator+() const;
            PhysicalNumber operator-() const;
            PhysicalNumber operator+(const PhysicalNumber&) const;
            PhysicalNumber operator-(const PhysicalNumber&) const;
  
            
            PhysicalNumber& operator+=(const PhysicalNumber&);
            PhysicalNumber& operator-=(const PhysicalNumber&);

            PhysicalNumber& operator++();//prefix operator -> ++i
            PhysicalNumber operator++(int);//postfix operator -> i++ 
            PhysicalNumber& operator--();//prefix operator -> ++i 
            PhysicalNumber operator--(int);//postfix operator -> i++ 

            bool operator ==(const PhysicalNumber&) const;
            bool operator !=(const PhysicalNumber&) const;
            bool operator <=(const PhysicalNumber&) const;
            bool operator >=(const PhysicalNumber&) const;  
            bool operator <(const PhysicalNumber&) const;
            bool operator >(const PhysicalNumber&) const;

            double convert(const PhysicalNumber&, const PhysicalNumber&) const;
            friend ostream& operator<<(ostream& os, const PhysicalNumber&);
            friend istream& operator>>(istream& is, PhysicalNumber&);
   };
};

#endif
