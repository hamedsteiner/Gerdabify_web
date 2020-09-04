#include <iostream>
#include <map>
#include <string>
class Gerdabify_logic;



class LoginHandler: public RequestHandler
{
public:
	void set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}
	void callback(Request* req, Response* res);
	
private:
	Gerdabify_logic* offline_api;
};
