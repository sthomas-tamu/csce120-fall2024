#ifndef DEBUG_H
#define DEBUG_H

//using compiler flag -D_DEBUG to toggle debugging prints on/off

#ifdef _DEBUG
#define DEBUG(X) std::cout << "DEBUG (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << "): " << X << std::endl;

#else
#define DEBUG(X) while(0) {};

#endif

#endif
