
#include <iostream>
#include <map>
#include <string>
#include "../src/gerdabServer.hpp"
#include "../success/Gerdabify_logic.h"
#include "../success/User.h"
#include "../success/artist.h"
//#include "../success/api.hpp"
#include "../success/rated.h"
#include "../success/music.h"
#include "../success/album.h"
#include "../success/exception.h"
#include "login.h"


	void LoginHandler::callback(Request* req, Response* res)
	{
		std::string username,password;
		username=req->getParam("username");
		password=req->getParam("password");
		try
		{
			offline_api->login(username,password);
			//function
			res->body <<"<body>"<<
			"<form action="<<'"'<< "http:"<<"//www.google.com"<<'"'<<
			">User name:<br><input type="<<'"'<<"text"<<'"'<< "name="<<'"'<<"userid"<<'"'<<"><br>User password:<br><input type="<<'"'<<"password"<<'"'<< "name="<<'"'<<"psw"<<'"'<<
			">"<< "<input type="<<'"'<<"submit"<<'"'<< "value="<<'"'<<"Submit"<<'"'<<">" << "</form>"
			<<"<input type= r name=g value=' you' />har che mikhahad delet tangat bego <br /> "<<
			"<table border='2'><tr><td bgcolor='red'>salam</td><td bgcolor='blue'>barto</td><td bgcolor='green'>ey user</td></tr><tr><td>your token is </td><td colspan='2'>" <<
			username <<
			"</td></tr></table>> </body>";
		}
		catch(InvalidCredentials e)
		{
			res->body << "<body><h1>Wrong password</h1><p>your have entered a wrong password</p><h2>try again </h2></body>";
		}

		catch(ItemDoesNotExists e)
		{
			res->code = 404;/////////////////////////// gftm ino  haa
			res->body << "<body><h1>User do not exist</h1><p>check your given username</p><h2>try again </h2></body>";

		}
	}