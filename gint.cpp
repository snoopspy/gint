#include "gint.h"

#ifdef GTEST
#include <gtest/gtest.h>

TEST ( Int, intTest )
{
  //
  // default ctor
  //
  {
    GInt i;
  }

  //
  // conversion ctor
  //
  {
    GInt i(1);
  }

  {
    GInt i(1);
    GInt j(2);
  }

  //
  // conversion ctor
  //
  {
    GInt i = 1;
    GInt j = 2;

    EXPECT_TRUE( i <  j );
    EXPECT_TRUE( i <= j );
    EXPECT_TRUE( i != j );
  }

  //
  // copy ctor
  //
  {
    GInt i = 1; // argument ctor
    GInt j = j; // copy ctor
  }
}

#endif // GTEST
