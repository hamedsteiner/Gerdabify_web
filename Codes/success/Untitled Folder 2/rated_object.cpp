#include "rated_object.h"
#include "static_declare.h"

using namespace std;


void Rated_object::rate(int rate,UserData user )
{
	rates.push_back(rate);
	users.push_back(user);
}
int Rated_object::getRate(UserData user)
{
	int location=-1;
	for(int i=0;i<users.size();i++)
		if(users[i].username == user.username && 
           users[i].firstname == user.firstname &&
           users[i].lastname == user.lastname
          )
		{
			location=i;
			break;
		}
	if(location!=-1)
		return rates[location];
	else
		throw ItemDoesNotExists();
	
}


int Rated_object::getUserRate()
{
	int sum=0;
	int num=0;
	for(int i=0;i<users.size();i++)
		if(users[i].userType != Admin || 
           users[i].userType != Editor
          )
		{
			num++;
			sum+=rates[i];
		}

	return (sum/num);




}
int Rated_object::get_CriticRate()
{
	int sum=0;
	int num=0;
	for(int i=0;i<users.size();i++)
		if(users[i].userType== Editor)
		{
			num++;
			sum+=rates[i];
		}

	return (sum/num);
}



///////////////bayad befahmim har ki cheghad dade 
	 

	
	//map<string, int> user_rate;
	//	user_rate.insert(pair <string, int> ("ali", 16));



