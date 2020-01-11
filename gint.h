// ----------------------------------------------------------------------------
//
// G Library
//
// http://www.gilgil.net
//
// Copyright (c) Gilbert Lee All rights reserved
//
// ----------------------------------------------------------------------------

// http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B

#pragma once

#include <stdio.h>   // for vsprintf
#include <stdarg.h>  // for va_list
#include <stdlib.h>  // for malloc

// ----------------------------------------------------------------------------
// GInt
// ----------------------------------------------------------------------------
class GInt
{
protected:
  int _i;

public:
  // --------------------------------------------------------------------------
  // Constructor and destructor
  // --------------------------------------------------------------------------
  GInt()                                 { D("%p GInt::GInt()\n",              this);               _i = 0;                                  } // A a      : Default constructor
  GInt(const GInt& b)                    { D("%p GInt::GInt(GInt& %d) %p\n",   this, b._i, &b);     _i = b._i;                               } // A a(b)   : Copy constructor
  GInt(const int i)                      { D("%p GInt::GInt(int %d)\n",        this, i);            _i = i;                                  } // A a(i)   : Conversion constructor
  ~GInt()                                { D("%p GInt::~GInt() %d\n",          this, _i);                                                    } // delete a : Destrutor

  // --------------------------------------------------------------------------
  // Arithmetic operators
  // --------------------------------------------------------------------------
  GInt& operator = (const GInt& b)       { D("%p GInt(%d)::= (GInt& %d) %p\n", this, _i, b._i, &b); _i = b._i;            return *this;      } // a = b : Basic assignment
  GInt  operator + (const GInt& b) const { D("%p GInt(%d)::+ (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i + b._i);  return res;        } // a + b : Addition
  GInt  operator - (const GInt& b) const { D("%p GInt(%d)::- (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i - b._i);  return res;        } // a - b : Subtraction
  GInt  operator + () const              { D("%p GInt(%d)::+ ()\n",            this, _i);           GInt res(_i);         return res;        } // +a    : Unary plus
  GInt  operator - () const              { D("%p GInt(%d)::- ()\n",            this, _i);           GInt res(-_i);        return res;        } // -a    : Unary minus
  GInt  operator * (const GInt& b) const { D("%p GInt(%d)::* (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i * b._i);  return res;        } // a * b : Multiplication
  GInt  operator / (const GInt& b) const { D("%p GInt(%d)::/ (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i / b._i);  return res;        } // a / b : Division
  GInt  operator % (const GInt& b) const { D("%p GInt(%d)::% (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i % b._i);  return res;        } // a % b : Modulo
  GInt& operator ++()                    { D("%p GInt(%d)::++()\n",            this, _i);           _i++;                 return *this;      } // ++a   : Prefix increment
  GInt  operator ++(int)                 { D("%p GInt(%d)::++(int)\n",         this, _i);           GInt res(_i); _i++;   return res;        } // a++   : Suffix increment
  GInt& operator --()                    { D("%p GInt(%d)::--()\n",            this, _i);           _i--;                 return *this;      } // --a   : Prefix decrement
  GInt  operator --(int)                 { D("%p GInt(%d)::--(int)\n",         this, _i);           GInt res(_i); _i--;   return res;        } // a--   : Suffix decrement

  // --------------------------------------------------------------------------
  // Comparison operators/relational operators
  // --------------------------------------------------------------------------
  bool  operator ==(const GInt& b) const { D("%p GInt(%d)::==(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i == b._i; } // a == b : Equal to
  bool  operator !=(const GInt& b) const { D("%p GInt(%d)::!=(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i != b._i; } // a != b : Not equal to
  bool  operator > (const GInt& b) const { D("%p GInt(%d)::> (GInt& %d) %p\n", this, _i, b._i, &b);                       return _i >  b._i; } // a > b  : Greater than
  bool  operator < (const GInt& b) const { D("%p GInt(%d)::< (GInt& %d) %p\n", this, _i, b._i, &b);                       return _i <  b._i; } // a < b  : Less than
  bool  operator >=(const GInt& b) const { D("%p GInt(%d)::>=(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i >= b._i; } // a >= b : Greater than or equal to
  bool  operator <=(const GInt& b) const { D("%p GInt(%d)::<=(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i <= b._i; } // a <= b : Less than or equal to

  // --------------------------------------------------------------------------
  // Logical operators
  // --------------------------------------------------------------------------
  bool  operator ! () const              { D("%p GInt(%d)::! ()\n",            this, _i);                                 return !_i;        } // !a     : Logical NOT
  bool  operator &&(const GInt& b) const { D("%p GInt(%d)::&&(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i && b._i; } // a && b : Logical AND
  bool  operator ||(const GInt& b) const { D("%p GInt(%d)::||(GInt& %d) %p\n", this, _i, b._i, &b);                       return _i || b._i; } // a || b : Logical OR

  // --------------------------------------------------------------------------
  // Bitwise operators
  // --------------------------------------------------------------------------
  GInt  operator ~ ()              const { D("%p GInt(%d)::~ ()\n",            this, _i);           GInt res(~_i);        return res;        } // ~a     : Bitwise NOT
  GInt  operator & (const GInt& b) const { D("%p GInt(%d)::& (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i & b._i);  return res;        } // a & b  : Bitwise AND
  GInt  operator | (const GInt& b) const { D("%p GInt(%d)::| (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i | b._i);  return res;        } // a | b  : Bitwise OR
  GInt  operator ^ (const GInt& b) const { D("%p GInt(%d)::^ (GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i ^ b._i);  return res;        } // a ^ b  : Bitwise XOR
  GInt  operator <<(const GInt& b) const { D("%p GInt(%d)::<<(GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i << b._i); return res;        } // a << b : Bitwise left shift
  GInt  operator >>(const GInt& b) const { D("%p GInt(%d)::>>(GInt& %d) %p\n", this, _i, b._i, &b); GInt res(_i >> b._i); return res;        } // a >> b : Bitwise right shift

  // --------------------------------------------------------------------------
  // Compound assignment operators
  // --------------------------------------------------------------------------
  GInt& operator +=(const GInt& b)       { D("%p GInt(%d)::+=(GInt& %d) %p\n", this, _i, b._i, &b); _i += b._i;           return *this;      } // a += b  : Addition assignmentf
  GInt& operator -=(const GInt& b)       { D("%p GInt(%d)::-=(GInt& %d) %p\n", this, _i, b._i, &b); _i -= b._i;           return *this;      } // a -= b  : Subtraction assignment
  GInt& operator *=(const GInt& b)       { D("%p GInt(%d)::*=(GInt& %d) %p\n", this, _i, b._i, &b); _i *= b._i;           return *this;      } // a *= b  : Multiplication assignment
  GInt& operator /=(const GInt& b)       { D("%p GInt(%d)::/=(GInt& %d) %p\n", this, _i, b._i, &b); _i /= b._i;           return *this;      } // a /= b  : Division assignment
  GInt& operator %=(const GInt& b)       { D("%p GInt(%d)::%=(GInt& %d) %p\n", this, _i, b._i, &b); _i %= b._i;           return *this;      } // a %= b  : Modulo assignment
  GInt& operator &=(const GInt& b)       { D("%p GInt(%d)::&=(GInt& %d) %p\n", this, _i, b._i, &b); _i &= b._i;           return *this;      } // a &= b  : Bitwise AND assignment
  GInt& operator |=(const GInt& b)       { D("%p GInt(%d)::|=(GInt& %d) %p\n", this, _i, b._i, &b); _i |= b._i;           return *this;      } // a |= b  : Bitwise OR assignment
  GInt& operator ^=(const GInt& b)       { D("%p GInt(%d)::^=(GInt& %d) %p\n", this, _i, b._i, &b); _i ^= b._i;           return *this;      } // a ^= b  : Bitwise XOR assignment
  GInt& operator <<=(const GInt& b)      { D("%p GInt(%d)::<<=(GInt& %d) %p\n", this, _i, b._i, &b); _i <<= b._i;         return *this;      } // a <<= b : Bitwise left shift assignment
  GInt& operator >>=(const GInt& b)      { D("%p GInt(%d)::>>=(GInt& %d) %p\n", this, _i, b._i, &b); _i >>= b._i;         return *this;      } // a >>= b : Bitwise right shift assignment

  // --------------------------------------------------------------------------
  // Member and pointer operators
  // --------------------------------------------------------------------------
  // R&   operator [](const T2& b)                                                                                                             // a[b]  : Array subscript
  // R&   operator *()                                                                                                                         // *a    : Indirection ("object pointed to by a")
  // GInt* operator & ()                    { D("%p GInt(%d)::& ()\n",            this, _i);                                 return this;    } // &a    : Reference ("address of a")
  // R*   operator ->()                                                                                                                        // a->b  : Structure dereference ("member b of object pointed to by a")
  // N/A                                                                                                                                       // a.b   : Structure reference ("member b of object a")
  // R    operator->*(R)                                                                                                                       // a->*b : Member pointed to by b of object pointed to by a
  // N/A                                                                                                                                       // a.*b  : Member pointed to by b of object a


  // --------------------------------------------------------------------------
  // Other operators
  // --------------------------------------------------------------------------
  // R    operator ()(Arg1 a1, Arg2 a2)                                                                                                        // a(a1, a2)               : Function call
  // R&   operator ,(R& b) const                                                                                                               // a, b                    : Comma
  // N/A                                                                                                                                       // a ? b : c               : Ternary conditional
  // N/A                                                                                                                                       // a::b                    : Scope resolution
  // N/A                                                                                                                                       // sizeof(a), sizeof(A)    : Size-of
  // N/A                                                                                                                                       // alignof(A), _Alignof(A) : Align-of
  // N/A                                                                                                                                       // typeid(a), typeid(A)    : Type identification
  operator int() const                   { D("%p GInt::int(%d)\n",             this, _i);                                 return _i;         } // (type)a                 : Cast
  void* operator new(size_t x)           { void* res = malloc(x); D("%p GInt::new(%d)\n", res, x);                        return res;        } // new A                   : Allocate storage
  void* operator new[](size_t x)         { void* res = malloc(x); D("%p GInt::new[](%d)\n", res, x);                      return res;        } // new A[n]                : Allocate storage (array)
  void  operator delete(void* p)         { D("%p GInt::delete\n",              p);                  free(p);                                 } // delete a                : Deallocate storage
  void  operator delete[](void* p)       { D("%p GInt::delete[]\n",            p);                  free(p);                                 } // delete[] a              : Deallocate storage (array)

public:
#ifdef _DEBUG
  static void D(const char* fmt, ...)
  {
    static const int BUF_SIZE = 4096;
    char  buf[BUF_SIZE];
    va_list args;
    va_start(args, fmt);
    #ifdef __STDC_WANT_SECURE_LIB__
      int len = vsprintf_s(buf, BUF_SIZE, fmt, args);
    #else
      int len = vsnprintf(buf, BUF_SIZE, fmt, args);
    #endif // __STDC_WANT_SECURE_LIB__
    if (len != -1) printf("%s", buf);
    va_end(args);
  }
  #else // _DEBUG
  static void D(const char* fmt, ...)
  {
    (void)fmt;
  }
  #endif // _DEBUG
};
