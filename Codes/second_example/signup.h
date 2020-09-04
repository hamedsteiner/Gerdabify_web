

#include <iostream>
#include <map>
#include <string>
class Gerdabify_logic;


class SignupHandler: public RequestHandler
{
public:
	void set_conncetion(Gerdabify_logic* client_user);


	void callback(Request* req, Response* res);
	
private:
	Gerdabify_logic* offline_api;
};
