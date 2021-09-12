#include <stdio.h>

#define DBG(x, ...) fprintf( stdout, "%s:%s:%s:%s:%d: " x "\n", "DBG", __TIME__,__DATE__,__func__, __LINE__, ##__VA_ARGS__)

int main(int argc, char* argv[])
{
	DBG ("Hello %d", 10);
	return 0;
}
