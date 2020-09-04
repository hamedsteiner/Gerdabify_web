

#include <iostream>
#include <map>
#include <string>
#include "src/gerdabServer.hpp"
#include "success/Gerdabify_logic.h"
#include "success/User.h"
#include "success/artist.h"
//#include "../success/api.hpp"
#include "success/rated.h"
#include "success/music.h"
#include "success/album.h"
#include "success/exception.h"
#include "signup.h"









	void SignupHandler::set_conncetion(Gerdabify_logic* client_user)
	{
		offline_api =client_user;
	}

	void SignupHandler::callback(Request* req, Response* res)
	{
		std::string _username,_password,_firstname,_lastname,_userType;
		try
		{
			_username=req->getParam("username");
			_password=req->getParam("password");
			_firstname=req->getParam("firstname");
			_lastname=req->getParam("lastname");
			_userType=req->getParam("userType");

			if(_username=="")
				throw UsernameNotGiven();
			if(_firstname=="")
				throw FirstnameNotGiven();
			if(_lastname=="")
				throw LastnameNotGiven();
			if(_userType=="")
				throw UsertypeNotGiven();
			if(_password=="")
				throw PasswordNotGiven();
			if(_password=="artist"&& _password=="admin"&& _password=="editor")
				throw YouAreNotNormal();

			UserData newPerson ;

			if(_userType=="artist")
				newPerson.userType=Artist;
			else if(_userType=="editor")
				newPerson.userType=Editor;
			else if(_userType=="admin")
				newPerson.userType=Admin;
			else 
				newPerson.userType=Normal;

			
			newPerson.firstname=_firstname;
			newPerson.lastname=_lastname;		
			newPerson.username=_username;

			if(offline_api!=NULL)
			{
				offline_api->signup(newPerson,_password);

			}
			res->body <<"<body><input type= r name=g value=' welcome to Gerdabify' />created by hamed rahmani <br /> "<<
			//"<frameset><frame src=a.htm' /><frame src='b.htm' /><frame src='c.htm' /><noframes>Frames not supported!</noframes></frameset>"<<
			"<canvas id='canvas1' width='200' height='100'></canvas> </body>";
		}
		catch(AlreadyExists e)
		{
			res->body << "<body><h1>User already exist</h1><p>change your username</p><h2>try again </h2></body>";
		}
		catch(UsernameNotGiven e)
		{
			res->body << "<body><h1>Username not given</h1><p> required username</p><h2>try again </h2></body>";
		}
		catch(FirstnameNotGiven e)
		{
			res->body << "<body><h1>Firstname not given</h1><p>required Firstname</p><h2>try again </h2></body>";
		}
		catch(LastnameNotGiven e)
		{
			res->body << "<body><h1>Lastname not given</h1><p>required Lastname</p><h2>try again </h2></body>";
		}
		catch(UsertypeNotGiven e)
		{
			res->body << "<body><h1>Usertype not given</h1><p>required Usertype</p><h2>try again </h2></body>";
		}
		catch(PasswordNotGiven e)
		{
			res->body << "<body><h1>Password not given</h1><p>required Password</p><h2>try again </h2></body>";
		}
		catch(YouAreNotNormal e)
		{
			res->body << "<body><h1>Invalid user type</h1><p>required valid user type</p><h2>try again </h2></body>";
		}



	}
	//cout<<req->getParam("username")<<endl;
