#include <stdio.h>
#include <math.h>

typedef union {
  float f;
  struct {
    unsigned int fraction : 23;
    unsigned int exp : 8;
    unsigned int sign : 1;
  } p;
} float_converter;

int computeFP(float f) {
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
  float_converter fp;
  fp.f = f;
  printf("sign = %x\n",fp.p.sign);
  printf("exponent = %x\n",fp.p.exp);
  printf("mantisa = %x\n",fp.p.fraction);
  
  int e = fp.p.exp - 127;

  if (e > 14)
  {
    return -1;
  }

  if (e < 1)
  {
    return 0;
  }

  // new exponent is sub bias and we'll only take the lower
  // five bits.
  int new_exp = (e + 15) & 0x1F;
//  printf("E is: %d\n", e);
//  printf("newExp is: %d\n", new_exp);

//  printf("The fractional bits are %d\n", ((fp.p.fraction >> 16)));
  int retVal = 0;
  retVal |= new_exp;
  retVal <<= 7;
  retVal |= (fp.p.fraction >> 16);
  return retVal;
}


float getFP(int val) {
// Using the defined representation, compute the floating point
//    value
// For denormalized values (including 0), simply return 0.
// For special values, return -1;

  unsigned int fraction = val & 0x7F;
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

//  printf("-------\n");
//  printf("fraction is %d\n", fraction);
//  printf("exponent is %d\n", exponent);

  int e = exponent - 15;

  int i = 0;
  printf("e is %d\n", e);
  unsigned int wholeNumber = 1;
  while (i < e)
  {
    // extract the whole number
    wholeNumber <<= 1;
    wholeNumber |= (fraction >> (6 - i)) & 0x01;
    ++i;
  }
//  printf("Whole number %d\n", wholeNumber);

  // build the decimal portion
  // there are 7 minus e bits left in the mantissa to be the decimal portion
  unsigned int upperBound = 7 - e;
  unsigned int decimalNumber = 0;
  float f = 0;
  i = 0;
  while (i < upperBound)
  {
    int digit = ((fraction >> (upperBound - i - 1)) & 0x01);
//    printf("Digit is %d\n", digit);
    float val = digit * (float)(pow(2, -(i + 1)));
    f += val;
//    printf("f after digit %f\n", f);
    ++i;;
  }
  
  f += wholeNumber;
  return f;
}

int main()
{
  int a = computeFP(4.5);
  printf("%d\n", a);

  float f = getFP(a);
  printf("%f\n", f);
}
