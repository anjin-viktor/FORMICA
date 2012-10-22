#ifndef FORMICA_LEXER_H_
#define FORMICA_LEXER_H_

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_statement.hpp>
#include <boost/spirit/include/phoenix_container.hpp>


using namespace boost::spirit;

template <typename Lexer>
class FormicaLexer: public lex::lexer<Lexer>
{
	public:
		FormicaLexer():
			OP_EQ("[?]="),
			OP_LE("[?]<"),
			OP_GR("[?]>"),
			WS("[ \\t\\n]+")
		{
			this -> self = 
				OP_EQ |
				OP_GR | 
				OP_LE | 
				WS;
		}
 
	private:
		lex::token_def<> OP_EQ;
		lex::token_def<> OP_GR;
		lex::token_def<> OP_LE;
		lex::token_def<> WS;
};



#endif
