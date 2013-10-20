#ifndef PROTOCOL_V1
#define PROTOCOL_V1

#include <map>

void pin_init();
void update_pinMask( std::pair<std::map<int,char>::iterator,bool> pr);

#endif // PROTOCOL_V1