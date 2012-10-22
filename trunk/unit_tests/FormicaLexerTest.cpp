#include <iostream>
#include <string>

#include <boost/test/unit_test.hpp>

#include "FormicaLexer.h"

BOOST_AUTO_TEST_SUITE(FORMICA_TOKEN_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	typedef lex::lexertl::token<char const*, lex::omit, boost::mpl::false_> token_type;
	typedef lex::lexertl::actor_lexer<token_type> lexer_type;

	FormicaLexer<lexer_type> lexer;

  	std::string str = "?=   ?<   ?>   ?=";

    char const* first = str.c_str();
    char const* last = &first[str.size()];

	lexer_type::iterator_type iter = lexer.begin(first, last);

    lexer_type::iterator_type end = lexer.end();
}


BOOST_AUTO_TEST_SUITE_END();
