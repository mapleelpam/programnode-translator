

#include <service/ConfigService.h>

namespace tw { namespace maple { namespace service {



ConfigRequest::ConfigRequest( std::string n )
	: _name(n)
{
	SVC_CONFIG->registerElement(this);
}

void ConfigService::loadConfig( const std::string& filename )
{
	boost::property_tree::ptree _ptree;
	read_info( filename, _ptree );

	for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
			citr != m_config_elements.end() ; citr ++ )	{
		std::cerr << " ---> read config "<< (*citr)->getName() << std::endl;
		(*citr)->readConfig( _ptree );
	}
}

void ConfigService::saveConfig( const std::string& filename )
{
	boost::property_tree::ptree _ptree;
	for( std::list<ConfigRequest*>::iterator citr = m_config_elements.begin();
			citr != m_config_elements.end() ; citr ++ )	{
		std::cerr << " ---> write config "<< (*citr)->getName() << std::endl;
		(*citr)->writeConfig( _ptree );
	}
	//write_xml( filename, _ptree);
	write_info( filename, _ptree);
}

} /*service*/ } /*maple*/ } /*tw*/
