#include <iostream>
#include <string>
#include <map>

int main()
{
	typedef std::map<int, std::string> I_str_map_t;
	I_str_map_t ds;
	ds.insert(std::make_pair(1, "1"));
	ds.insert(std::make_pair(2, "2"));
	ds.insert(std::make_pair(3, "3"));

	I_str_map_t::const_reverse_iterator it = ds.rbegin() ;
	for (;it != ds.rend(); ++it)
	{
		std::cout << it->first << ", " << it->second << std::endl;	
	}
	return 0;
}
