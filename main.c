#include "config.h"
#include "io.h"

bool allGood(void);

int main(void)
{
	//initialization
	currentInit();
	tempInit();
	voltInit();
	contactorInit();

	//initial check before activating
	if (allGood()) setContactor(true);
	else return -1;
	while(1)
	{
		//monitor constantly
		if (!allGood()) 
		{
			setContactor(false);
			return -1;
		}
	}
	return 0;
}

bool allGood(void)
{
	if (currentRead() > MAX_CURRENT) return false;
	else if (tempRead() > MAX_TEMP) return false;
	else if (voltRead() < MIN_VOLTAGE || voltRead() > MAX_VOLTAGE) return false;
	else return true;
}

