/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber a2(3, Unit::KM);
    PhysicalNumber b2(400, Unit::M);
    PhysicalNumber c2(3, Unit::CM);

    PhysicalNumber a3(3, Unit::HOUR);
    PhysicalNumber b3(16, Unit::MIN);
    PhysicalNumber c3(30, Unit::SEC);
    
    PhysicalNumber a4(1, Unit::TON);
    PhysicalNumber b4(1, Unit::KG);
    PhysicalNumber c4(1000, Unit::G);

    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
    /*
      * 1 Kilometer == 1000 meter == 100000 centimeter
      * 1 Meter == 100 centimeter
      * 
      * 1 Hour == 60 minute == 3600 second
      * 1 minute == 60 second
      * 
      * 1 Tonne == 1000 kilogram == 1000000 gram
      * 1 kilogram == 1000 gram
      * 
      */

      .setname("Basic output")
      .CHECK_OUTPUT(a2, "3[km]")
      .CHECK_OUTPUT(b2, "400[m]")
      .CHECK_OUTPUT(c2, "3[cm]")
      .CHECK_OUTPUT(a3, "3[hour]")
      .CHECK_OUTPUT(b3, "16[min]")
      .CHECK_OUTPUT(c3, "30[sec]")
      .CHECK_OUTPUT(a4, "1[ton]")
      .CHECK_OUTPUT(b4, "1[kg]")
      .CHECK_OUTPUT(c4, "1000[g]")

      .setname("Compatible dimensions")
      .CHECK_OUTPUT((a2+=b2),"3400[m]")
      .CHECK_OUTPUT(a2, "3.4[km]")
      .CHECK_OUTPUT(a2+a2,"6.8[km]")
      .CHECK_OUTPUT(b2+c2,"403[m]")
      .CHECK_OUTPUT((b2+=c2),"403[m]")
      .CHECK_EQUAL(a2 == b2, false)
      .CHECK_EQUAL(a2 != b2, true)
      .CHECK_EQUAL(a2 > b2, true)
      .CHECK_EQUAL(a2 > c2, true)
      .CHECK_OK(a2 + b2)
      .CHECK_OK(a2 + c2)
      .CHECK_OK(b2 + c2)

      .CHECK_OUTPUT((a3+=b3),"196[min]")
      .CHECK_OUTPUT(a3+a3,"392[min]")
      .CHECK_OUTPUT(b3+c3,"990[sec]")
      .CHECK_OUTPUT((b3+=c3),"16.5[min]")
      .CHECK_OUTPUT(+a3,"196[min]")
      .CHECK_OUTPUT(-c3,"-30[sec]")
      .CHECK_EQUAL(a3 == b3, false)
      .CHECK_EQUAL(a3 != b3, true)
      .CHECK_EQUAL(a3 > b3, true)
      .CHECK_EQUAL(c3 > b3, false)
      .CHECK_OK(c3 + b3)
      .CHECK_OK(a3 + b3)

      .CHECK_OUTPUT(b4+c4,"2[kg]")
      .CHECK_OUTPUT(a4+a4,"2[ton]")
      .CHECK_OUTPUT((b2+=c2),"403[m]")
      .CHECK_EQUAL(a4 == b4, false)
      .CHECK_EQUAL(a4 != c4, true)
      .CHECK_EQUAL(b4 == c4, true)
      .CHECK_EQUAL(a4 > c4, true)
      .CHECK_EQUAL(a4 >= b4, true)
      .CHECK_OK(a4 + b4)
      .CHECK_OK(b4 + c4)
      .CHECK_OK(a4 + c4)


      .setname("Incompatible dimensions")
      .CHECK_THROWS(a2+a3)
      .CHECK_THROWS(a+a3)
      .CHECK_THROWS(a2+a4)
      .CHECK_THROWS(b2+b4)
      .CHECK_THROWS(b3+b3)
      .CHECK_THROWS(a2+a2)
      .CHECK_THROWS(c3+c2)
      .CHECK_THROWS(c3+c3)
      .CHECK_THROWS(c4+c3)
      .CHECK_THROWS(c2+c2)


      .setname("Basic input")
      .CHECK_OUTPUT((a4 += PhysicalNumber(1, Unit::TON)), "2[ton]")
      .CHECK_OK(istringstream("30[sec]") >> c3)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
