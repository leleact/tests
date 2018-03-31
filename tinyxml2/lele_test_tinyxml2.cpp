#include <iostream>
#include <string>
#include <map>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;
struct st_server
{
	std::string name;
	int msgtype;
	std::string msgcd;
	std::string type;
	std::string note;
};

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "please input the xml file!" << endl;
		return -1;
	}

	map<int, struct st_server> ServerMap;
	XMLDocument doc;
	XMLError nErrId = doc.LoadFile(argv[1]);
	if (nErrId)
	{
		cerr << "LoadFile Error, RetCode: "	 << nErrId;
		return nErrId;
	}

	XMLElement *pRoot = doc.FirstChildElement();
	if (pRoot == nullptr)
	{
		std::cerr << "none RootElement"	 << std::endl;
		return -1;
	}

	struct st_server stServer;
	XMLElement *pServer = pRoot->FirstChildElement("IngoreMsgType");
	while (pServer != nullptr)
	{
		XMLElement *lpItem = pServer->FirstChildElement("item");
		while (lpItem != nullptr)
		{
			std::cout << "[" << lpItem->Attribute("name") << "]";
			lpItem = lpItem->NextSiblingElement();
		}
	}
	return 0;
}
