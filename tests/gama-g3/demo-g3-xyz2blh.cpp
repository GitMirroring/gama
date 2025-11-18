#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <gnu_gama/ellipsoid.h>
#include <gnu_gama/latlong.h>


using std::string;
using std::cout;
using std::endl;

int error = 0;

double s2d(char* str)
{
  std::stringstream ss(str);
  double result;
  if (ss >> result)
    {
      return result;
    }
  else
    {
      std::cerr << "Conversion from '" << str << "' to double failed\n";
      error++;

      return 0;
    }
}

int main(int argc, char* argv[])
{
  if (argc != 4)
    {
      std::cerr << "\nUsage: demo-g3-xml2blh  X Y Z \n\n";
      return 1;
    }

  double X = s2d(argv[1]);
  double Y = s2d(argv[2]);
  double Z = s2d(argv[3]);

  double B, L, H;

  cout.precision(3);
  cout << "\nXYZ  " << std::fixed << X << "  " << Y << "  " << Z << "\n\n";

  GNU_gama::Ellipsoid ellipsoid;
  ellipsoid.xyz2blh(X, Y, Z, B, L, H);

  using namespace GNU_gama;
  cout.precision(16);
  cout << "BLH  " << GNU_gama::latitude(B,16)  << "\n"
       << "     " << GNU_gama::longitude(L,16) << "\n"
       << "     " << std::setw(10+1+16) << H << endl;

  return 0;
}
