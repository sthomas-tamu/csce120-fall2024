#ifndef DEBUG_H
#define DEBUG_H

//comment out the first DEBUG line to turn debugging prints off
//comment out the second DEBUG line to turn debugging prints on

#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

//#define DEBUG(X) while(0) {};

#endif
