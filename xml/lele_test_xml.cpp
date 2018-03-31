// libxml真是太难用鸟
#include <iostream>
#include <cstring>
#ifdef __cplusplus
extern "C" {
#endif
#include <libxml/xpath.h>
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#ifdef __cplusplus
}
#endif

int main()
{
    xmlDocPtr doc = NULL;
    xmlNodePtr curNode = NULL;
    xmlKeepBlanksDefault(0);

    doc = xmlParseFile("utf8test.xml");
    if (nullptr == doc)
    {
        std::cout << "xmlReadFile error" << std::endl; 
        return -1;
    }

    curNode = xmlDocGetRootElement(doc);
    if (nullptr == curNode)
    {
        std::cout << "check rootElement failed." << std::endl;
        xmlFreeDoc(doc);
        return -1;
    }

	xmlAttr *attr =	curNode->properties;

    if (xmlStrcmp(curNode->name, (unsigned char *)"document"))
    {
        std::cout << "check rootElement failed" << std::endl; 
        xmlFreeDoc(doc);
        return -1;
    }

    while(curNode != nullptr)
    {
        xmlNodePtr cur = curNode->children;
        while(cur != nullptr)
        {
            if (!xmlStrcmp((unsigned char *)"English", cur->name))
            {
                std::cout << xmlNodeListGetString(doc, cur->children, 1) << std::endl;
            }
            cur = cur->next;
        }
        curNode = curNode->next;
    }

    return 0;
}
