#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fp.h"

int
computeFP(float val) {
// input: float value to be represented
// output: integer version in our representation
//
// Perform this the same way we did in class -
//    either dividing or multiplying the value by 2
//    until it is in the correct range (between 1 and 2).
//    Your exponent is the number of times this operation
//    was performed.   
// Deal with rounding by simply truncating the number.
// Check for overflow and underflow - 
//    with 4 exponent bits, we have overflow if the number to be 
//       stored is > 14
//    for overflow (E > 14), return -1
//    For underflow (E < 1), return 0 


  // if zero just return here were done.
  if (val == 0)
  {
    return 0;
  }

  int e = 0;
  int retVal = 0;
  
  // calculate the e.
  if (val >= 2)
  {
    // if the value is greater than two justify
    while (val >= 2)
    {
      // justify by dividing
      val = val / 2;
      ++e;
    }
  }
  else if (val < 1)
  {
    // if the val is less than one
    while (val < 1)
    {
      // justify by multiplication
      val = val * 2;
      ++e;
    }
    e *= -1;
  }

  // we just want the decimal points to store.
  val -= 1;

  int biasedExponent = e + 15;
   
  int mantissa = 0;
  // get the mantissa.
  float sevenBits = val * (pow(2, 7));
  mantissa = (int)sevenBits;

  // because biased expnents largest number
  if (biasedExponent > 30)
  {
    return -1;
  }

  if (biasedExponent < 1)
  {
    return 0;
  }

  // pack the number
  retVal |= biasedExponent;
  retVal <<= 7;
  retVal |= mantissa;
  return retVal;
}

float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values (including 0), simply return 0.
// For special values, return -1;

  float fraction = ((val & 0x7F) / (float)pow(2, 7)) + 1;
  int exponent = ((val >> 7) & 0x1F);

  // denormalized or zero
  if (exponent == 0)
  {
    return 0;
  }

  // special number
  if (exponent == 0x1F)
  {
    return -1;
  }

  // get e
  int e = exponent - 15;
  
  // check to see if negative
  if (e < 0)
  {
    int i;
    for (i = e; i < 0; ++i)
    {
      // normalize
      fraction = fraction / 2;
    }
  }
  else // e > 0
  {
    int i;
    for (i = 0; i < e; ++i)
    {
      fraction = fraction * 2;
    }

  } 
  return fraction;
}

int
multVals(int source1, int source2) {
// You must implement this by using the algorithm
//    described in class:
//    Add the exponents:  E = E1+E2 
//    multiply the fractional values: M = M1*M2
//    if M too large, divide it by 2 and increment E
//    save the result
// Be sure to check for overflow - return -1 in this case
// Be sure to check for underflow - return 0 in this case

  int exponent1 = ((source1 >> 7) & 0x1F);
  int exponent2 = ((source2 >> 7) & 0x1F);

  int e1 = exponent1 - 15;
  int e2 = exponent2 - 15;
  int e3 = e1 + e2;

 
  float frac1 = ((float) (source1 & 0x7f));
  float frac2 = ((float) (source2 & 0x7f));

  // + one since that is the point to the left
  frac1 = (frac1 / ((float)pow(2, 7))) + 1;
  frac2 = (frac2 / ((float)pow(2, 7))) + 1;

  // check for overflow
  if ((e3 + 15) > 30)
  {
    return -1;
  } 

  if ((e3 + 15) < 1)
  {
    return 0;
  }

  // is the multiplication of the mantissa
  float frac = frac1 * frac2;

  // if bigger than two must rejustify
  if (frac >= 2)
  {
    frac /= 2;
    ++e3;
  }

  // rebuild the biased exponent
  int new_exp = 15 + e3;

  // get rid of the leading point since it is assumed
  frac -= 1;
  frac *= (float)pow(2, 7);

  // truncate the float
  int newFrac = (int) frac;

  // build the new number
  int retVal = 0;
  retVal |= new_exp;
  retVal <<=  7;
  retVal |= newFrac; 
  return retVal;;
}

int
addVals(int source1, int source2) {
// Do this function last - it is the most difficult!
// You must implement this as described in class:
//     If needed, adjust one of the two number so that 
//        they have the same exponent E
//     Add the two fractional parts:  F1' + F2 = F
//              (assumes F1' is the adjusted F1)
//     Adjust the sum F and E so that F is in the correct range
//     
// As described in the handout, you only need to implement this for
//    positive, normalized numbers
// Also, return -1 if the sum overflows
  int exponent1 = ((source1 >> 7) & 0x1F);
  int exponent2 = ((source2 >> 7) & 0x1F);

  int e1 = exponent1 - 15;
  int e2 = exponent2 - 15;
    
  float frac1 = ((float) (source1 & 0x7f));
  float frac2 = ((float) (source2 & 0x7f));
  
  // the fractions with the leading 1
  frac1 = (frac1 / ((float)pow(2, 7))) + 1;
  frac2 = (frac2 / ((float)pow(2, 7))) + 1;

  // check to see which exponent is better
  if (e1 > e2)
  {
    int i;
    int delta = e1 - e2;
    for (i = 0; i < delta; ++i)
    {
      // justify frac 2
      frac2 = frac2 / 2;
      ++e2;
    }
  }
  else if (e1 < e2)
  {
    int i;
    int delta = e2 - e1;
    for ( i = 0; i < delta; ++i)
    {
      // justify frac1
      frac1 = frac1 / 2;
      ++e1;
    }
  }

  // add the mantissas
  float frac = frac2 + frac1;

  // if the fraction is greater than 2 justify frac down
  // and increment the exponent.
  while (frac >= 2)
  {
    frac = frac / 2;
    ++e1;
  }

  // if the fraction is less than 1 justify up
  // decrement the exponent. 
  while (frac < 1)
  {
    frac = frac * 2;
    --e1;
  }

  // check for overflow
  if ((e1 + 15) > 30)
  {
    return -1;
  }
 
  // build the new number
  int new_exp = (15 + e1) * (pow(2, 7));
  frac -= 1;
  frac *= (float)pow(2, 7);

  int newFrac = (int) frac;
  return new_exp + newFrac;
}

