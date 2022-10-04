#include "ObserveBase.h"

int main()
{
	FirstProcress* first = new FirstProcress;
	SecondProgress* second = new SecondProgress;
	thirtyProgress* thirty = new thirtyProgress;
	fourthProgress* fourth = new fourthProgress;


	first->registerObserver(second);
	first->registerObserver(fourth);

	second->registerObserver(thirty);

	first->wakeUp();

	return 0;
}