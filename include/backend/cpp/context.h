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


#ifndef __BACKEDN_CONTEXT_H__
#define __BACKEDN_CONTEXT_H__

#include <fstream>

namespace tw { namespace maple { namespace backend { namespace cpp {

struct Context
{
	struct IndentContext
	{
		IndentContext() : indent(0){}
		int operator++(int) // Postfix
		{
			return indent++;
		}
		int operator++() // Prefix
		{
			return ++indent;
		}
		int operator--(int) // Postfix
		{
			return indent--;
		}
		int operator--() // Prefix
		{
			return --indent;
		}
		int toInt()
        {
            return indent;
        }
		std::string toString()
		{
			std::string ans = "";
			for( int idx = 0 ; idx < indent ; idx ++)
				ans += "\t";//TODO: replace by indent scape
            return ans;
		}
		private:
		int		indent;
	};

    std::string indent()
    {
        return tree_depth.toString();
    }

    std::string endl()
    {
        return "\n";
    }


	std::ofstream	ofs_stream;

	IndentContext	tree_depth;
};

} } } }

#endif 
