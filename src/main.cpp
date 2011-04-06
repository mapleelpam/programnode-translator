
#include <iostream>
#include "AstDumper.h"  
#include "pnodehandler.h" 
#include "pnode_reader.h"

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>

namespace po = boost::program_options;

int main(int argc, char **argv)
{

	po::options_description 			m_options_desc;
	po::positional_options_description	m_positional_options_desc;

	m_options_desc.add_options()
	    ("help,h",    "this help message")
	    ("output,o",    po::value<std::string>(), "outputfiles")
	    ("input,i",    po::value<std::vector<std::string> >(), "inputfiles")
    ;
	m_positional_options_desc.add("input", -1);


	po::variables_map args;
	po::store(po::command_line_parser(argc, argv).options(m_options_desc).positional(m_positional_options_desc).run(), args);
	po::notify(args);


	if (args.count("help") > 0)
	{
		std::cout << m_options_desc << "\n";
		return 0;
	}

	std::vector<std::string> m_pnode_files = args["input"].as< std::vector<std::string > >();
	std::string out_file  = args["output"].as<std::string> ();


	// File Open
	for (std::vector<std::string>::iterator fileItr = m_pnode_files.begin()
			; fileItr != m_pnode_files.end(); fileItr++)
	{
		tw::maple::PNodeReader::open( *fileItr );
	}

	// Interpret/Explain - Invoke Backend Stream Out

    return 0;
}
