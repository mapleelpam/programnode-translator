/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements. See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership. The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License. You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

// ProgrameNode Translator
// Copyright 2011 mapleellpam@gmail.com.  All rights reserved.
// https://github.com/mapleelpam/programnode-translator

// Author: mapleelpam at gmail.com - Kai-Feng Chou - maple


#ifndef __TW_MAPLE_BACKEDN_TEMPLATE_PRINTER_H__
#define __TW_MAPLE_BACKEDN_TEMPLATE_PRINTER_H__

#include <fstream>
#include <list>
#include <tr1/memory>

namespace tw { namespace maple { namespace backend { namespace cpp {


struct Pattern
{
	Pattern( std::string p, std::string c) : pattern(p), content(c) {}
	std::string pattern;
	std::string content;
};
typedef std::tr1::shared_ptr<Pattern>    PatternPtr;


class TemplatePrinter
{
public:
	std::string substitutePatterns( std::string& in, std::list<PatternPtr>& patterns)
	{
		std::string out = in;
		for( std::list<PatternPtr>::iterator itr = patterns.begin() ; itr != patterns.end() ; itr ++)
		{

			_replace_string( out, "%"+(*itr)->pattern+"%", (*itr)->content );
		}
		return out;
	}

protected:
	static void _replace_string(
	    std::string &s, const std::string &SearchString, const std::string &ReplaceString
	    )
	{
	    std::string::size_type p = 0;
	    while((p = s.find(SearchString, p)) != std::string::npos)
	    {
	        s.replace(p, SearchString.size(), ReplaceString);
	        p++;
	    }
	}
};

} } } }

#endif 
