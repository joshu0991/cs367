/* 
 * CS:APP Data Lab 
 * 
 * Joshua Lilly : jlilly3
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
/*
FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
*/
/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) 
{
  /*
   * Extracts the sign bit and negates and flips the sign
   * bit if the sign bit extracted is 1 otherwise does nothing
   * in the case we have a nan or infinity representation we check
   * to see if the NAN and if it is we just return otherwise if
   * it's infinity we just resume the normal flipping or not of the upper
   * most bit.
   */
  // extract the sign bit by dividing by
  // the smallest unsigned value.
  int signBit = uf / 0x80000000;
 
  // we need the orig. number around still
  // so we can't mutate it. But we need to 
  // get rid of the sign bit on this numebr so
  // we can do modular arithmatic when checking for
  // NAN and infinity.
  int temp;
  temp = uf % 0x80000000; 
 
  // if the integer arithmatic with the NAN value 
  // is greater than one.
  if (temp / 0x7F800000)
  {
    // then check to see if this is nan or infinity.
    // if nan just return otherwise just fall through 
    // and resume normal absolute value
    int nan = temp % 0x7F800000;
    if (nan)
      return uf;
  }
 
  // if the value isn't zero or positive then
  // flip the sign bit.  
  if (uf != 0 && signBit)
    uf += 0x80000000;
 
  return uf;
}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) 
{
  /*
   * There is almost certainly a way to do this better I just can't think of it...
   * This works by getting the sign bit from the two numbers entered and then calculates
   * their sum. Then using the fact that if the sign bit is the same in the two numbers
   * entered and different for the sum, overflow has occured. This is checked by packing 
   * the sign bits into an integer and checking to see if it is 6 or 1, which is the only
   * case where this is the case for addition... And all in 18 operations! 
   *
   * Edit: Just found the page in the text book that details how to do this. I am going
   * to leave this implimentation for origionality....
   *
   */ 
  int sign1 = 0, sign2 = 0, c = 0, sign3 = 0, temp = 0, p = 0, q = 0;
  sign1 = (x >> 31) & 1;
  sign2 = (y >> 31) & 1;

  c = x + y;
  sign3 = (c >> 31) & 1;

  // pack the signs in an integer
  temp = 0;
  temp |= sign1;
  temp <<= 1;
  temp |= sign2;
  temp <<= 1;
  temp |= sign3;

  // if the signs packed this way are 1 or six
  // we overflowed...
  p = !(temp ^ 0x06);
  q = !(temp ^ 0x01);

  return !(p | q);
}

/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) 
{
  /* This will shift the bits in x by a power of 2 starting at 2^4 down to 2^0
  *  effectivly moving bits down to the least order bit. When the final shift is
  *  made if the value did have all even bits set then anding it with 1 will return 1
  *  otherwise anding it with 1 will yield 0.
  */
  // where can we find a number with all of the even bits set (if they are in fact set)?
  // The upper bits of this number will have all the even bits set if they are!
  x = x & (x >> 16); // are all the even bits set?
  x = x & (x >> 8);
  x = x & (x >> 4);
  x = x & (x >> 2);
  x = x & 1; // was all the even bits set?
  return x;  
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) 
{
  /*
   * If the nuber is negative the upper most bit is 1 so we
   * right shift it by 31 to check that bit. Due to arethmetic
   * shift this will cause the number to become -1 if the upper
   * most bit was 1 so complimenting all the bits yields 0 !0
   * will then return 1. 
   */ 
  x = ~(x >> 31);
  return !x;
}
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) 
{
  /*
   * And can be obtained by complementing the two numbers
   * doing bitwise OR on the numbers compliments and then
   * complimenting the result of that OR.
   */ 
  return ~(~x | ~y);
}
