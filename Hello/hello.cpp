#include <stdio.h>
#include <cstdint>
#include <iostream>
#include <deque>

using namespace std;

std::ostream& operator<<( std::ostream& dest, __int128_t value );
////////////////////////////////////////////////////////////////////////////////


int main()
{
  printf("Hello World!\n");

  __int128 sum = 1, nMinus1 = 1, nMinus2 = 0;

  auto printSeries = [&sum](int index) { cout << index << ":  " << sum << endl; };

  printSeries(1);

  for (int i = 2; i <= 184; i++) //unsigned 128 bit int overflows after 184
  {
    sum = nMinus1 + nMinus2;
    nMinus2 = nMinus1;
    nMinus1 = sum;
    printSeries(i);
  }

}////////////////////////////////////////////////////////////////////////////////


//from StackOverflow to print __int128_t
std::ostream& operator<<( std::ostream& dest, __int128_t value )
{
  std::ostream::sentry s( dest );
  if ( s ) 
  {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[ 128 ];
    char* d = std::end( buffer );
    do
    {
      -- d;
      *d = "0123456789"[ tmp % 10 ];
      tmp /= 10;
    } while ( tmp != 0 );
    if ( value < 0 ) 
    {
      -- d;
      *d = '-';
    }
    int len = std::end( buffer ) - d;
    if ( dest.rdbuf()->sputn( d, len ) != len ) 
    {
      dest.setstate( std::ios_base::badbit );
    }
  }
  return dest;
}
////////////////////////////////////////////////////////////////////////////////
