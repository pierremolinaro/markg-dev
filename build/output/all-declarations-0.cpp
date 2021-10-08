#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-0.h"

//----------------------------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//----------------------------------------------------------------------------------------------------------------------

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//----------------------------------------------------------------------------------------------------------------------

cTokenFor_spec_5F_scanner::cTokenFor_spec_5F_scanner (void) :
mLexicalAttribute_theString (),
mLexicalAttribute_ulongValue () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_spec_5F_scanner::C_Lexique_spec_5F_scanner (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceFileName
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_spec_5F_scanner::C_Lexique_spec_5F_scanner (C_Compiler * inCallerCompiler,
                                                      const C_String & inSourceString,
                                                      const C_String & inStringForError
                                                      COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------
//                 I N D E X I N G    D I R E C T O R Y                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_spec_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_spec_5F_scanner_incorrectStringEnd = "string does not end with '\"'" ;

static const char * gLexicalMessage_spec_5F_scanner_internalError = "internal error" ;

//----------------------------------------------------------------------------------------------------------------------
//          Syntax error messages, for every terminal symbol                                     
//----------------------------------------------------------------------------------------------------------------------

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_identifier = "an identifier" ;

//--- Syntax error message for terminal '$literal_string$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_literal_5F_string = "a character string constant \"...\"" ;

//--- Syntax error message for terminal '$literal_integer$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_literal_5F_integer = "a decimal number" ;

//--- Syntax error message for terminal '$system$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_system = "the 'system' key word" ;

//--- Syntax error message for terminal '$var$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_var = "the 'var' key word" ;

//--- Syntax error message for terminal '$rule$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_rule = "the 'rule' key word" ;

//--- Syntax error message for terminal '$init$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_init = "the 'init' key word" ;

//--- Syntax error message for terminal '$end$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_end = "the 'end' key word" ;

//--- Syntax error message for terminal '$true$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_true = "the 'true' key word" ;

//--- Syntax error message for terminal '$false$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_false = "the 'false' key word" ;

//--- Syntax error message for terminal '$const$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_const = "the 'const' key word" ;

//--- Syntax error message for terminal '$count$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_count = "the 'count' key word" ;

//--- Syntax error message for terminal '$infinity$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_infinity = "the 'infinity' key word" ;

//--- Syntax error message for terminal '$hashmapsize$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_hashmapsize = "the 'hashmapsize' key word" ;

//--- Syntax error message for terminal '$garbageperiod$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner_garbageperiod = "the 'garbageperiod' key word" ;

//--- Syntax error message for terminal '$>=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3E__3D_ = "the '>=' delimitor" ;

//--- Syntax error message for terminal '$>$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3E_ = "the '>' delimitor" ;

//--- Syntax error message for terminal '$<$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3C_ = "the '<' delimitor" ;

//--- Syntax error message for terminal '$<=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3C__3D_ = "the '<=' delimitor" ;

//--- Syntax error message for terminal '$==$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3D__3D_ = "the '==' delimitor" ;

//--- Syntax error message for terminal '$!=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__21__3D_ = "the '!=' delimitor" ;

//--- Syntax error message for terminal '$&$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__26_ = "the '&' delimitor" ;

//--- Syntax error message for terminal '$|$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__7C_ = "the '|' delimitor" ;

//--- Syntax error message for terminal '$~$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__7E_ = "the '~' delimitor" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2C_ = "the ',' delimitor" ;

//--- Syntax error message for terminal '$;$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3B_ = "the ';' delimitor" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__28_ = "the '(' delimitor" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__29_ = "the ')' delimitor" ;

//--- Syntax error message for terminal '$++$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2B__2B_ = "the '++' delimitor" ;

//--- Syntax error message for terminal '$--$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2D__2D_ = "the '--' delimitor" ;

//--- Syntax error message for terminal '$+=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2B__3D_ = "the '+=' delimitor" ;

//--- Syntax error message for terminal '$-=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2D__3D_ = "the '-=' delimitor" ;

//--- Syntax error message for terminal '$:=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3A__3D_ = "the ':=' delimitor" ;

//--- Syntax error message for terminal '${$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__7B_ = "the '{' delimitor" ;

//--- Syntax error message for terminal '$}$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__7D_ = "the '}' delimitor" ;

//--- Syntax error message for terminal '$:$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3A_ = "the ':' delimitor" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__2D_ = "the '-' delimitor" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__3D_ = "the '=' delimitor" ;

//--- Syntax error message for terminal '$[$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__5B_ = "the '[' delimitor" ;

//--- Syntax error message for terminal '$]$' :
static const char * gSyntaxErrorMessage_spec_5F_scanner__5D_ = "the ']' delimitor" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_spec_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 41)) {
    static const char * syntaxErrorMessageArray [41] = {kEndOfSourceLexicalErrorMessage,
        gSyntaxErrorMessage_spec_5F_scanner_identifier,
        gSyntaxErrorMessage_spec_5F_scanner_literal_5F_string,
        gSyntaxErrorMessage_spec_5F_scanner_literal_5F_integer,
        gSyntaxErrorMessage_spec_5F_scanner_system,
        gSyntaxErrorMessage_spec_5F_scanner_var,
        gSyntaxErrorMessage_spec_5F_scanner_rule,
        gSyntaxErrorMessage_spec_5F_scanner_init,
        gSyntaxErrorMessage_spec_5F_scanner_end,
        gSyntaxErrorMessage_spec_5F_scanner_true,
        gSyntaxErrorMessage_spec_5F_scanner_false,
        gSyntaxErrorMessage_spec_5F_scanner_const,
        gSyntaxErrorMessage_spec_5F_scanner_count,
        gSyntaxErrorMessage_spec_5F_scanner_infinity,
        gSyntaxErrorMessage_spec_5F_scanner_hashmapsize,
        gSyntaxErrorMessage_spec_5F_scanner_garbageperiod,
        gSyntaxErrorMessage_spec_5F_scanner__3E__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__3E_,
        gSyntaxErrorMessage_spec_5F_scanner__3C_,
        gSyntaxErrorMessage_spec_5F_scanner__3C__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__3D__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__21__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__26_,
        gSyntaxErrorMessage_spec_5F_scanner__7C_,
        gSyntaxErrorMessage_spec_5F_scanner__7E_,
        gSyntaxErrorMessage_spec_5F_scanner__2C_,
        gSyntaxErrorMessage_spec_5F_scanner__3B_,
        gSyntaxErrorMessage_spec_5F_scanner__28_,
        gSyntaxErrorMessage_spec_5F_scanner__29_,
        gSyntaxErrorMessage_spec_5F_scanner__2B__2B_,
        gSyntaxErrorMessage_spec_5F_scanner__2D__2D_,
        gSyntaxErrorMessage_spec_5F_scanner__2B__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__2D__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__3A__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__7B_,
        gSyntaxErrorMessage_spec_5F_scanner__7D_,
        gSyntaxErrorMessage_spec_5F_scanner__3A_,
        gSyntaxErrorMessage_spec_5F_scanner__2D_,
        gSyntaxErrorMessage_spec_5F_scanner__3D_,
        gSyntaxErrorMessage_spec_5F_scanner__5B_,
        gSyntaxErrorMessage_spec_5F_scanner__5D_
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_21__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__21__3D_ [] = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_spec_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_spec_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_spec_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__2B_$'
static const utf32 kUnicodeString_spec_5F_scanner__2B__2B_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('+'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2B__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__2B__3D_ [] = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_spec_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D_$'
static const utf32 kUnicodeString_spec_5F_scanner__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__2D_$'
static const utf32 kUnicodeString_spec_5F_scanner__2D__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__2D__3D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A_$'
static const utf32 kUnicodeString_spec_5F_scanner__3A_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3A__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__3A__3D_ [] = {
  TO_UNICODE (':'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_spec_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_spec_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__3C__3D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__3D__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_spec_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E__3D_$'
static const utf32 kUnicodeString_spec_5F_scanner__3E__3D_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5B_$'
static const utf32 kUnicodeString_spec_5F_scanner__5B_ [] = {
  TO_UNICODE ('['),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_5D_$'
static const utf32 kUnicodeString_spec_5F_scanner__5D_ [] = {
  TO_UNICODE (']'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$const$'
static const utf32 kUnicodeString_spec_5F_scanner_const [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$count$'
static const utf32 kUnicodeString_spec_5F_scanner_count [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$end$'
static const utf32 kUnicodeString_spec_5F_scanner_end [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$false$'
static const utf32 kUnicodeString_spec_5F_scanner_false [] = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$garbageperiod$'
static const utf32 kUnicodeString_spec_5F_scanner_garbageperiod [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('b'),
  TO_UNICODE ('a'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$hashmapsize$'
static const utf32 kUnicodeString_spec_5F_scanner_hashmapsize [] = {
  TO_UNICODE ('h'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('h'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('z'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$infinity$'
static const utf32 kUnicodeString_spec_5F_scanner_infinity [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$init$'
static const utf32 kUnicodeString_spec_5F_scanner_init [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$rule$'
static const utf32 kUnicodeString_spec_5F_scanner_rule [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$system$'
static const utf32 kUnicodeString_spec_5F_scanner_system [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('y'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$true$'
static const utf32 kUnicodeString_spec_5F_scanner_true [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$var$'
static const utf32 kUnicodeString_spec_5F_scanner_var [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7B_$'
static const utf32 kUnicodeString_spec_5F_scanner__7B_ [] = {
  TO_UNICODE ('{'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7C_$'
static const utf32 kUnicodeString_spec_5F_scanner__7C_ [] = {
  TO_UNICODE ('|'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7D_$'
static const utf32 kUnicodeString_spec_5F_scanner__7D_ [] = {
  TO_UNICODE ('}'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_7E_$'
static const utf32 kUnicodeString_spec_5F_scanner__7E_ [] = {
  TO_UNICODE ('~'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'delimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_spec_5F_scanner_delimitorsList = 25 ;

static const C_unicode_lexique_table_entry ktable_for_spec_5F_scanner_delimitorsList [ktable_size_spec_5F_scanner_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__26_, 1, C_Lexique_spec_5F_scanner::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__28_, 1, C_Lexique_spec_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__29_, 1, C_Lexique_spec_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2C_, 1, C_Lexique_spec_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D_, 1, C_Lexique_spec_5F_scanner::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3A_, 1, C_Lexique_spec_5F_scanner::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3B_, 1, C_Lexique_spec_5F_scanner::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3C_, 1, C_Lexique_spec_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3D_, 1, C_Lexique_spec_5F_scanner::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3E_, 1, C_Lexique_spec_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__5B_, 1, C_Lexique_spec_5F_scanner::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__5D_, 1, C_Lexique_spec_5F_scanner::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7B_, 1, C_Lexique_spec_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7C_, 1, C_Lexique_spec_5F_scanner::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7D_, 1, C_Lexique_spec_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7E_, 1, C_Lexique_spec_5F_scanner::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__21__3D_, 2, C_Lexique_spec_5F_scanner::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2B__2B_, 2, C_Lexique_spec_5F_scanner::kToken__2B__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2B__3D_, 2, C_Lexique_spec_5F_scanner::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D__2D_, 2, C_Lexique_spec_5F_scanner::kToken__2D__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D__3D_, 2, C_Lexique_spec_5F_scanner::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3A__3D_, 2, C_Lexique_spec_5F_scanner::kToken__3A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3C__3D_, 2, C_Lexique_spec_5F_scanner::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3D__3D_, 2, C_Lexique_spec_5F_scanner::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3E__3D_, 2, C_Lexique_spec_5F_scanner::kToken__3E__3D_)
} ;

int16_t C_Lexique_spec_5F_scanner::search_into_delimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_spec_5F_scanner_delimitorsList, ktable_size_spec_5F_scanner_delimitorsList) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'galgasKeyWordList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_spec_5F_scanner_galgasKeyWordList = 12 ;

static const C_unicode_lexique_table_entry ktable_for_spec_5F_scanner_galgasKeyWordList [ktable_size_spec_5F_scanner_galgasKeyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_end, 3, C_Lexique_spec_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_var, 3, C_Lexique_spec_5F_scanner::kToken_var),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_init, 4, C_Lexique_spec_5F_scanner::kToken_init),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_rule, 4, C_Lexique_spec_5F_scanner::kToken_rule),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_true, 4, C_Lexique_spec_5F_scanner::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_const, 5, C_Lexique_spec_5F_scanner::kToken_const),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_count, 5, C_Lexique_spec_5F_scanner::kToken_count),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_false, 5, C_Lexique_spec_5F_scanner::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_system, 6, C_Lexique_spec_5F_scanner::kToken_system),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_infinity, 8, C_Lexique_spec_5F_scanner::kToken_infinity),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_hashmapsize, 11, C_Lexique_spec_5F_scanner::kToken_hashmapsize),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_garbageperiod, 13, C_Lexique_spec_5F_scanner::kToken_garbageperiod)
} ;

int16_t C_Lexique_spec_5F_scanner::search_into_galgasKeyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_spec_5F_scanner_galgasKeyWordList, ktable_size_spec_5F_scanner_galgasKeyWordList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_spec_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_spec_5F_scanner * ptr = (const cTokenFor_spec_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_theString) ;
      break ;
    case kToken_literal_5F_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_theString) ;
      break ;
    case kToken_literal_5F_integer:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("literal_integer") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_ulongValue) ;
      break ;
    case kToken_system:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("system") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_var:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("var") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_rule:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("rule") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_init:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("init") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_end:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("end") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_true:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("true") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_false:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("false") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_const:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("const") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_count:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("count") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_infinity:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("infinity") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_hashmapsize:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("hashmapsize") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_garbageperiod:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("garbageperiod") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("==") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__21__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("!=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__26_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("&") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("|") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("~") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (";") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__2B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("++") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("--") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2B__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("+=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("{") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__7D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("}") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (":") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5B_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("[") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__5D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("]") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//            Unicode test functions                                                             
//----------------------------------------------------------------------------------------------------------------------
 
//----------------------------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique_spec_5F_scanner::parseLexicalToken (void) {
  cTokenFor_spec_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_theString.setLengthToZero () ;
    token.mLexicalAttribute_ulongValue = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    try{
      if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_theString, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (token.mTokenCode == -1) {
          token.mTokenCode = search_into_galgasKeyWordList (token.mLexicalAttribute_theString) ;
        }
        if (token.mTokenCode == -1) {
          token.mTokenCode = kToken_identifier ;
        }
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        do {
          if (testForInputUTF32Char (TO_UNICODE (' ')) || testForInputUTF32Char (TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE ('~'))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_theString, previousChar ()) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
          token.mTokenCode = kToken_literal_5F_string ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_spec_5F_scanner_incorrectStringEnd COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3E__3D_, 2, true)) {
        token.mTokenCode = kToken__3E__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3D__3D_, 2, true)) {
        token.mTokenCode = kToken__3D__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3C__3D_, 2, true)) {
        token.mTokenCode = kToken__3C__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3A__3D_, 2, true)) {
        token.mTokenCode = kToken__3A__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D__3D_, 2, true)) {
        token.mTokenCode = kToken__2D__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D__2D_, 2, true)) {
        token.mTokenCode = kToken__2D__2D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2B__3D_, 2, true)) {
        token.mTokenCode = kToken__2B__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2B__2B_, 2, true)) {
        token.mTokenCode = kToken__2B__2B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__21__3D_, 2, true)) {
        token.mTokenCode = kToken__21__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7E_, 1, true)) {
        token.mTokenCode = kToken__7E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7D_, 1, true)) {
        token.mTokenCode = kToken__7D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7C_, 1, true)) {
        token.mTokenCode = kToken__7C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7B_, 1, true)) {
        token.mTokenCode = kToken__7B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__5D_, 1, true)) {
        token.mTokenCode = kToken__5D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__5B_, 1, true)) {
        token.mTokenCode = kToken__5B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3E_, 1, true)) {
        token.mTokenCode = kToken__3E_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3D_, 1, true)) {
        token.mTokenCode = kToken__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3C_, 1, true)) {
        token.mTokenCode = kToken__3C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3B_, 1, true)) {
        token.mTokenCode = kToken__3B_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3A_, 1, true)) {
        token.mTokenCode = kToken__3A_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D_, 1, true)) {
        token.mTokenCode = kToken__2D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2C_, 1, true)) {
        token.mTokenCode = kToken__2C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__29_, 1, true)) {
        token.mTokenCode = kToken__29_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__28_, 1, true)) {
        token.mTokenCode = kToken__28_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__26_, 1, true)) {
        token.mTokenCode = kToken__26_ ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge, gLexicalMessage_spec_5F_scanner_internalError) ;
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge, gLexicalMessage_spec_5F_scanner_internalError) ;
          }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_literal_5F_integer ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
        token.mTokenCode = -1 ; // No token
        advance () ; // ... go throught unknown character
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_spec_5F_scanner::enterToken (cTokenFor_spec_5F_scanner & ioToken) {
  cTokenFor_spec_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_spec_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_theString = ioToken.mLexicalAttribute_theString ;
  ptr->mLexicalAttribute_ulongValue = ioToken.mLexicalAttribute_ulongValue ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_spec_5F_scanner::attributeValue_theString (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_theString ;
}

//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_spec_5F_scanner::attributeValue_ulongValue (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_ulongValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_spec_5F_scanner::synthetizedAttribute_theString (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_theString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint C_Lexique_spec_5F_scanner::synthetizedAttribute_ulongValue (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_ulongValue) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_spec_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("literal_integer") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("system") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("var") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("rule") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("init") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("const") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("count") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("infinity") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("hashmapsize") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("garbageperiod") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("==") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("!=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("&") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("|") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("~") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("++") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("--") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("+=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_spec_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("spec_scanner:delimitorsList") ;
  ioList.appendObject ("spec_scanner:galgasKeyWordList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_spec_5F_scanner (const C_String & inIdentifier,
                                                      bool & ioFound,
                                                      TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "spec_scanner:delimitorsList") {
    ioFound = true ;
    ioList.appendObject ("&") ;
    ioList.appendObject ("(") ;
    ioList.appendObject (")") ;
    ioList.appendObject (",") ;
    ioList.appendObject ("-") ;
    ioList.appendObject (":") ;
    ioList.appendObject (";") ;
    ioList.appendObject ("<") ;
    ioList.appendObject ("=") ;
    ioList.appendObject (">") ;
    ioList.appendObject ("[") ;
    ioList.appendObject ("]") ;
    ioList.appendObject ("{") ;
    ioList.appendObject ("|") ;
    ioList.appendObject ("}") ;
    ioList.appendObject ("~") ;
    ioList.appendObject ("!=") ;
    ioList.appendObject ("++") ;
    ioList.appendObject ("+=") ;
    ioList.appendObject ("--") ;
    ioList.appendObject ("-=") ;
    ioList.appendObject (":=") ;
    ioList.appendObject ("<=") ;
    ioList.appendObject ("==") ;
    ioList.appendObject (">=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "spec_scanner:galgasKeyWordList") {
    ioFound = true ;
    ioList.appendObject ("end") ;
    ioList.appendObject ("var") ;
    ioList.appendObject ("init") ;
    ioList.appendObject ("rule") ;
    ioList.appendObject ("true") ;
    ioList.appendObject ("const") ;
    ioList.appendObject ("count") ;
    ioList.appendObject ("false") ;
    ioList.appendObject ("system") ;
    ioList.appendObject ("infinity") ;
    ioList.appendObject ("hashmapsize") ;
    ioList.appendObject ("garbageperiod") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_spec_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_spec_5F_scanner, getKeywordsForIdentifier_spec_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_spec_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [41] = {0,
    1 /* spec_scanner_1_identifier */,
    5 /* spec_scanner_1_literal_5F_string */,
    4 /* spec_scanner_1_literal_5F_integer */,
    2 /* spec_scanner_1_system */,
    2 /* spec_scanner_1_var */,
    2 /* spec_scanner_1_rule */,
    2 /* spec_scanner_1_init */,
    2 /* spec_scanner_1_end */,
    2 /* spec_scanner_1_true */,
    2 /* spec_scanner_1_false */,
    2 /* spec_scanner_1_const */,
    2 /* spec_scanner_1_count */,
    2 /* spec_scanner_1_infinity */,
    2 /* spec_scanner_1_hashmapsize */,
    2 /* spec_scanner_1_garbageperiod */,
    3 /* spec_scanner_1__3E__3D_ */,
    3 /* spec_scanner_1__3E_ */,
    3 /* spec_scanner_1__3C_ */,
    3 /* spec_scanner_1__3C__3D_ */,
    3 /* spec_scanner_1__3D__3D_ */,
    3 /* spec_scanner_1__21__3D_ */,
    3 /* spec_scanner_1__26_ */,
    3 /* spec_scanner_1__7C_ */,
    3 /* spec_scanner_1__7E_ */,
    3 /* spec_scanner_1__2C_ */,
    3 /* spec_scanner_1__3B_ */,
    3 /* spec_scanner_1__28_ */,
    3 /* spec_scanner_1__29_ */,
    3 /* spec_scanner_1__2B__2B_ */,
    3 /* spec_scanner_1__2D__2D_ */,
    3 /* spec_scanner_1__2B__3D_ */,
    3 /* spec_scanner_1__2D__3D_ */,
    3 /* spec_scanner_1__3A__3D_ */,
    3 /* spec_scanner_1__7B_ */,
    3 /* spec_scanner_1__7D_ */,
    3 /* spec_scanner_1__3A_ */,
    3 /* spec_scanner_1__2D_ */,
    3 /* spec_scanner_1__3D_ */,
    3 /* spec_scanner_1__5B_ */,
    3 /* spec_scanner_1__5D_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_spec_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 6) {
    static const char * kStyleArray [6] = {
      "",
      "identifier",
      "keyWords",
      "delimitors",
      "integerStyle",
      "stringStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_typeVarMap::cMapElement_typeVarMap (const GALGAS_lstring & inKey,
                                                const GALGAS_uint & in_mIndex
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_typeVarMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_typeVarMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_typeVarMap (mProperty_lkey, mProperty_mIndex COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_typeVarMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mIndex" ":" ;
  mProperty_mIndex.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_typeVarMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_typeVarMap * operand = (cMapElement_typeVarMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap::GALGAS_typeVarMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap::GALGAS_typeVarMap (const GALGAS_typeVarMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap & GALGAS_typeVarMap::operator = (const GALGAS_typeVarMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::constructor_mapWithMapToOverride (const GALGAS_typeVarMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_typeVarMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_uint & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * p = NULL ;
  macroMyNew (p, cMapElement_typeVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_uint inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * p = NULL ;
  macroMyNew (p, cMapElement_typeVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' place is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_typeVarMap_searchKey = "the '%K' place is not declared" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_uint & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_typeVarMap_searchKey
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    outArgument0 = p->mProperty_mIndex ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeVarMap::getter_mIndexForKey (const GALGAS_string & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) attributes ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                GALGAS_string inKey,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeVarMap * p = (cMapElement_typeVarMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_typeVarMap * GALGAS_typeVarMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * result = (cMapElement_typeVarMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_typeVarMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typeVarMap::cEnumerator_typeVarMap (const GALGAS_typeVarMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element cEnumerator_typeVarMap::current (LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeVarMap) ;
  return GALGAS_typeVarMap_2D_element (p->mProperty_lkey, p->mProperty_mIndex) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeVarMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeVarMap::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeVarMap) ;
  return p->mProperty_mIndex ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeVarMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_uint & outArgument0) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) searchForKey (inKey) ;
  const bool result = NULL != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    outArgument0 = p->mProperty_mIndex ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@typeVarMap type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeVarMap ("typeVarMap",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeVarMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  const GALGAS_typeVarMap * p = (const GALGAS_typeVarMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_typeCstMap::cMapElement_typeCstMap (const GALGAS_lstring & inKey,
                                                const GALGAS_bool & in_mSign,
                                                const GALGAS_luint & in_mValue
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mSign (in_mSign),
mProperty_mValue (in_mValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_typeCstMap::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mSign.isValid () && mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_typeCstMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_typeCstMap (mProperty_lkey, mProperty_mSign, mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_typeCstMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mSign" ":" ;
  mProperty_mSign.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mValue" ":" ;
  mProperty_mValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_typeCstMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_typeCstMap * operand = (cMapElement_typeCstMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mSign.objectCompare (operand->mProperty_mSign) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mValue.objectCompare (operand->mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap::GALGAS_typeCstMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap::GALGAS_typeCstMap (const GALGAS_typeCstMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap & GALGAS_typeCstMap::operator = (const GALGAS_typeCstMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::constructor_mapWithMapToOverride (const GALGAS_typeCstMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_typeCstMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_bool & inArgument0,
                                             const GALGAS_luint & inArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * p = NULL ;
  macroMyNew (p, cMapElement_typeCstMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeCstMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_bool inArgument0,
                                          GALGAS_luint inArgument1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * p = NULL ;
  macroMyNew (p, cMapElement_typeCstMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' constant is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_typeCstMap_searchKey = "there '%K' constant is not defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_bool & outArgument0,
                                          GALGAS_luint & outArgument1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_typeCstMap_searchKey
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    outArgument0 = p->mProperty_mSign ;
    outArgument1 = p->mProperty_mValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeCstMap::getter_mSignForKey (const GALGAS_string & inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) attributes ;
  GALGAS_bool result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    result = p->mProperty_mSign ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeCstMap::getter_mValueForKey (const GALGAS_string & inKey,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) attributes ;
  GALGAS_luint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    result = p->mProperty_mValue ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_setMSignForKey (GALGAS_bool inAttributeValue,
                                               GALGAS_string inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeCstMap * p = (cMapElement_typeCstMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    p->mProperty_mSign = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_setMValueForKey (GALGAS_luint inAttributeValue,
                                                GALGAS_string inKey,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeCstMap * p = (cMapElement_typeCstMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    p->mProperty_mValue = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_typeCstMap * GALGAS_typeCstMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * result = (cMapElement_typeCstMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_typeCstMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typeCstMap::cEnumerator_typeCstMap (const GALGAS_typeCstMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element cEnumerator_typeCstMap::current (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return GALGAS_typeCstMap_2D_element (p->mProperty_lkey, p->mProperty_mSign, p->mProperty_mValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeCstMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cEnumerator_typeCstMap::current_mSign (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return p->mProperty_mSign ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cEnumerator_typeCstMap::current_mValue (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return p->mProperty_mValue ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeCstMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_bool & outArgument0,
                                            GALGAS_luint & outArgument1) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) searchForKey (inKey) ;
  const bool result = NULL != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    outArgument0 = p->mProperty_mSign ;
    outArgument1 = p->mProperty_mValue ;
  }else{
    outArgument0.drop () ;
    outArgument1.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@typeCstMap type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeCstMap ("typeCstMap",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeCstMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeCstMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeCstMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  const GALGAS_typeCstMap * p = (const GALGAS_typeCstMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeCstMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_typePreconditionExpression::objectCompare (const GALGAS_typePreconditionExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression::GALGAS_typePreconditionExpression (void) :
AC_GALGAS_class (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression::GALGAS_typePreconditionExpression (const cPtr_typePreconditionExpression * inSourcePtr) :
AC_GALGAS_class (inSourcePtr, true) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePreconditionExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typePreconditionExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typePreconditionExpression::cPtr_typePreconditionExpression (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typePreconditionExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePreconditionExpression ("typePreconditionExpression",
                                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePreconditionExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePreconditionExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePreconditionExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePreconditionExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typePreconditionExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typePreconditionExpression result ;
  const GALGAS_typePreconditionExpression * p = (const GALGAS_typePreconditionExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePreconditionExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePreconditionExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeTrueExpression::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeTrueExpression::objectCompare (const GALGAS_typeTrueExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression::GALGAS_typeTrueExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeTrueExpression::constructor_new (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression::GALGAS_typeTrueExpression (const cPtr_typeTrueExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeTrueExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::constructor_new (LOCATION_ARGS) {
  GALGAS_typeTrueExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeTrueExpression (THERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeTrueExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeTrueExpression::cPtr_typeTrueExpression (LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeTrueExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

void cPtr_typeTrueExpression::description (C_String & ioString,
                                           const int32_t /* inIndentation */) const {
  ioString << "[@typeTrueExpression]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeTrueExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeTrueExpression (THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeTrueExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeTrueExpression ("typeTrueExpression",
                                           & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTrueExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTrueExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTrueExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeTrueExpression result ;
  const GALGAS_typeTrueExpression * p = (const GALGAS_typeTrueExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeTrueExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTrueExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeFalseExpression::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return kOperandEqual ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeFalseExpression::objectCompare (const GALGAS_typeFalseExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression::GALGAS_typeFalseExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeFalseExpression::constructor_new (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression::GALGAS_typeFalseExpression (const cPtr_typeFalseExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeFalseExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::constructor_new (LOCATION_ARGS) {
  GALGAS_typeFalseExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeFalseExpression (THERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeFalseExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeFalseExpression::cPtr_typeFalseExpression (LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeFalseExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

void cPtr_typeFalseExpression::description (C_String & ioString,
                                            const int32_t /* inIndentation */) const {
  ioString << "[@typeFalseExpression]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeFalseExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeFalseExpression (THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeFalseExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeFalseExpression ("typeFalseExpression",
                                            & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeFalseExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeFalseExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeFalseExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeFalseExpression result ;
  const GALGAS_typeFalseExpression * p = (const GALGAS_typeFalseExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeFalseExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeFalseExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeComplementExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeComplementExpression * p = (const cPtr_typeComplementExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeComplementExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mExpression.objectCompare (p->mProperty_mExpression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeComplementExpression::objectCompare (const GALGAS_typeComplementExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression::GALGAS_typeComplementExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression::GALGAS_typeComplementExpression (const cPtr_typeComplementExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeComplementExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression::constructor_new (const GALGAS_typePreconditionExpression & inAttribute_mExpression
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeComplementExpression result ;
  if (inAttribute_mExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeComplementExpression (inAttribute_mExpression COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeComplementExpression::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeComplementExpression * p = (const cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    result = p->mProperty_mExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cPtr_typeComplementExpression::getter_mExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeComplementExpression::setter_setMExpression (GALGAS_typePreconditionExpression inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    p->mProperty_mExpression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeComplementExpression::setter_setMExpression (GALGAS_typePreconditionExpression inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mExpression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeComplementExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeComplementExpression::cPtr_typeComplementExpression (const GALGAS_typePreconditionExpression & in_mExpression
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mExpression (in_mExpression) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeComplementExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

void cPtr_typeComplementExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@typeComplementExpression:" ;
  mProperty_mExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeComplementExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeComplementExpression (mProperty_mExpression COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeComplementExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeComplementExpression ("typeComplementExpression",
                                                 & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeComplementExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeComplementExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeComplementExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeComplementExpression result ;
  const GALGAS_typeComplementExpression * p = (const GALGAS_typeComplementExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeComplementExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeComplementExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeAndExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeAndExpression * p = (const cPtr_typeAndExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAndExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mLeftExpression.objectCompare (p->mProperty_mLeftExpression) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRightExpression.objectCompare (p->mProperty_mRightExpression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeAndExpression::objectCompare (const GALGAS_typeAndExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression::GALGAS_typeAndExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression::GALGAS_typeAndExpression (const cPtr_typeAndExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAndExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression::constructor_new (const GALGAS_typePreconditionExpression & inAttribute_mLeftExpression,
                                                                    const GALGAS_typePreconditionExpression & inAttribute_mRightExpression
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAndExpression result ;
  if (inAttribute_mLeftExpression.isValid () && inAttribute_mRightExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeAndExpression (inAttribute_mLeftExpression, inAttribute_mRightExpression COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeAndExpression::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAndExpression * p = (const cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    result = p->mProperty_mLeftExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cPtr_typeAndExpression::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLeftExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeAndExpression::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAndExpression * p = (const cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    result = p->mProperty_mRightExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cPtr_typeAndExpression::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRightExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAndExpression::setter_setMLeftExpression (GALGAS_typePreconditionExpression inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAndExpression::setter_setMLeftExpression (GALGAS_typePreconditionExpression inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mLeftExpression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAndExpression::setter_setMRightExpression (GALGAS_typePreconditionExpression inValue
                                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAndExpression::setter_setMRightExpression (GALGAS_typePreconditionExpression inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mRightExpression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeAndExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeAndExpression::cPtr_typeAndExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                                const GALGAS_typePreconditionExpression & in_mRightExpression
                                                COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mLeftExpression (in_mLeftExpression),
mProperty_mRightExpression (in_mRightExpression) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAndExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression ;
}

void cPtr_typeAndExpression::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@typeAndExpression:" ;
  mProperty_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRightExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAndExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeAndExpression (mProperty_mLeftExpression, mProperty_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeAndExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeAndExpression ("typeAndExpression",
                                          & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAndExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAndExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAndExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeAndExpression result ;
  const GALGAS_typeAndExpression * p = (const GALGAS_typeAndExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeAndExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAndExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeOrExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeOrExpression * p = (const cPtr_typeOrExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeOrExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mLeftExpression.objectCompare (p->mProperty_mLeftExpression) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mRightExpression.objectCompare (p->mProperty_mRightExpression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeOrExpression::objectCompare (const GALGAS_typeOrExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression::GALGAS_typeOrExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression::GALGAS_typeOrExpression (const cPtr_typeOrExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeOrExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression::constructor_new (const GALGAS_typePreconditionExpression & inAttribute_mLeftExpression,
                                                                  const GALGAS_typePreconditionExpression & inAttribute_mRightExpression
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeOrExpression result ;
  if (inAttribute_mLeftExpression.isValid () && inAttribute_mRightExpression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeOrExpression (inAttribute_mLeftExpression, inAttribute_mRightExpression COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeOrExpression::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeOrExpression * p = (const cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    result = p->mProperty_mLeftExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cPtr_typeOrExpression::getter_mLeftExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLeftExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeOrExpression::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeOrExpression * p = (const cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    result = p->mProperty_mRightExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cPtr_typeOrExpression::getter_mRightExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mRightExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeOrExpression::setter_setMLeftExpression (GALGAS_typePreconditionExpression inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeOrExpression::setter_setMLeftExpression (GALGAS_typePreconditionExpression inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mLeftExpression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeOrExpression::setter_setMRightExpression (GALGAS_typePreconditionExpression inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeOrExpression::setter_setMRightExpression (GALGAS_typePreconditionExpression inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mRightExpression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeOrExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeOrExpression::cPtr_typeOrExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                              const GALGAS_typePreconditionExpression & in_mRightExpression
                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mLeftExpression (in_mLeftExpression),
mProperty_mRightExpression (in_mRightExpression) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeOrExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression ;
}

void cPtr_typeOrExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@typeOrExpression:" ;
  mProperty_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mRightExpression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeOrExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeOrExpression (mProperty_mLeftExpression, mProperty_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeOrExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeOrExpression ("typeOrExpression",
                                         & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeOrExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeOrExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeOrExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeOrExpression result ;
  const GALGAS_typeOrExpression * p = (const GALGAS_typeOrExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeOrExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeOrExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_typePostcondition::objectCompare (const GALGAS_typePostcondition & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition::GALGAS_typePostcondition (void) :
AC_GALGAS_class (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition::GALGAS_typePostcondition (const cPtr_typePostcondition * inSourcePtr) :
AC_GALGAS_class (inSourcePtr, true) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostcondition) ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typePostcondition class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typePostcondition::cPtr_typePostcondition (LOCATION_ARGS) :
acPtr_class (THERE) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typePostcondition type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePostcondition ("typePostcondition",
                                          NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostcondition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostcondition ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostcondition::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostcondition (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostcondition::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostcondition result ;
  const GALGAS_typePostcondition * p = (const GALGAS_typePostcondition *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePostcondition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostcondition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@typePostconditionList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_typePostconditionList : public cCollectionElement {
  public : GALGAS_typePostconditionList_2D_element mObject ;

//--- Constructors
  public : cCollectionElement_typePostconditionList (const GALGAS_typePostcondition & in_mPostcondition
                                                     COMMA_LOCATION_ARGS) ;
  public : cCollectionElement_typePostconditionList (const GALGAS_typePostconditionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GALGAS_typePostcondition & in_mPostcondition
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mPostcondition) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GALGAS_typePostconditionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mPostcondition) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_typePostconditionList::isValid (void) const {
  return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typePostconditionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_typePostconditionList (mObject.mProperty_mPostcondition COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_typePostconditionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPostcondition" ":" ;
  mObject.mProperty_mPostcondition.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_typePostconditionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typePostconditionList * operand = (cCollectionElement_typePostconditionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typePostconditionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList::GALGAS_typePostconditionList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList::GALGAS_typePostconditionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typePostconditionList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::constructor_listWithValue (const GALGAS_typePostcondition & inOperand0
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typePostconditionList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typePostconditionList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_typePostconditionList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                              const GALGAS_typePostcondition & in_mPostcondition
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_typePostconditionList * p = NULL ;
  macroMyNew (p, cCollectionElement_typePostconditionList (in_mPostcondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::addAssign_operation (const GALGAS_typePostcondition & inOperand0
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typePostconditionList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_append (GALGAS_typePostconditionList_2D_element inElement,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typePostconditionList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_insertAtIndex (const GALGAS_typePostcondition inOperand0,
                                                         const GALGAS_uint inInsertionIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typePostconditionList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_removeAtIndex (GALGAS_typePostcondition & outOperand0,
                                                         const GALGAS_uint inRemoveIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
        outOperand0 = p->mObject.mProperty_mPostcondition ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_popFirst (GALGAS_typePostcondition & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_popLast (GALGAS_typePostcondition & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::method_first (GALGAS_typePostcondition & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::method_last (GALGAS_typePostcondition & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::add_operation (const GALGAS_typePostconditionList & inOperand,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::plusAssign_operation (const GALGAS_typePostconditionList inOperand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_setMPostconditionAtIndex (GALGAS_typePostcondition inOperand,
                                                                    GALGAS_uint inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPostcondition = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostconditionList::getter_mPostconditionAtIndex (const GALGAS_uint & inIndex,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  GALGAS_typePostcondition result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    result = p->mObject.mProperty_mPostcondition ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typePostconditionList::cEnumerator_typePostconditionList (const GALGAS_typePostconditionList & inEnumeratedObject,
                                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element cEnumerator_typePostconditionList::current (LOCATION_ARGS) const {
  const cCollectionElement_typePostconditionList * p = (const cCollectionElement_typePostconditionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition cEnumerator_typePostconditionList::current_mPostcondition (LOCATION_ARGS) const {
  const cCollectionElement_typePostconditionList * p = (const cCollectionElement_typePostconditionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
  return p->mObject.mProperty_mPostcondition ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//@typePostconditionList type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePostconditionList ("typePostconditionList",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostconditionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostconditionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostconditionList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typePostconditionList result ;
  const GALGAS_typePostconditionList * p = (const GALGAS_typePostconditionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePostconditionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@typeTransitionList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_typeTransitionList : public cCollectionElement {
  public : GALGAS_typeTransitionList_2D_element mObject ;

//--- Constructors
  public : cCollectionElement_typeTransitionList (const GALGAS_lstring & in_mTransitionName,
                                                  const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                  const GALGAS_typePostconditionList & in_mPostconditionList,
                                                  const GALGAS_uint & in_mLowTemporalBound,
                                                  const GALGAS_uint & in_mHighTemporalBound
                                                  COMMA_LOCATION_ARGS) ;
  public : cCollectionElement_typeTransitionList (const GALGAS_typeTransitionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GALGAS_lstring & in_mTransitionName,
                                                                              const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                                              const GALGAS_typePostconditionList & in_mPostconditionList,
                                                                              const GALGAS_uint & in_mLowTemporalBound,
                                                                              const GALGAS_uint & in_mHighTemporalBound
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTransitionName, in_mPreconditionExpression, in_mPostconditionList, in_mLowTemporalBound, in_mHighTemporalBound) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GALGAS_typeTransitionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mTransitionName, inElement.mProperty_mPreconditionExpression, inElement.mProperty_mPostconditionList, inElement.mProperty_mLowTemporalBound, inElement.mProperty_mHighTemporalBound) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_typeTransitionList::isValid (void) const {
  return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typeTransitionList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_typeTransitionList (mObject.mProperty_mTransitionName, mObject.mProperty_mPreconditionExpression, mObject.mProperty_mPostconditionList, mObject.mProperty_mLowTemporalBound, mObject.mProperty_mHighTemporalBound COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_typeTransitionList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mTransitionName" ":" ;
  mObject.mProperty_mTransitionName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPreconditionExpression" ":" ;
  mObject.mProperty_mPreconditionExpression.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mPostconditionList" ":" ;
  mObject.mProperty_mPostconditionList.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mLowTemporalBound" ":" ;
  mObject.mProperty_mLowTemporalBound.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mHighTemporalBound" ":" ;
  mObject.mProperty_mHighTemporalBound.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_typeTransitionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typeTransitionList * operand = (cCollectionElement_typeTransitionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typeTransitionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList::GALGAS_typeTransitionList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList::GALGAS_typeTransitionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeTransitionList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_typePreconditionExpression & inOperand1,
                                                                                const GALGAS_typePostconditionList & inOperand2,
                                                                                const GALGAS_uint & inOperand3,
                                                                                const GALGAS_uint & inOperand4
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeTransitionList result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_typeTransitionList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_typeTransitionList::makeAttributesFromObjects (attributes, inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_lstring & in_mTransitionName,
                                                           const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                           const GALGAS_typePostconditionList & in_mPostconditionList,
                                                           const GALGAS_uint & in_mLowTemporalBound,
                                                           const GALGAS_uint & in_mHighTemporalBound
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = NULL ;
  macroMyNew (p, cCollectionElement_typeTransitionList (in_mTransitionName,
                                                        in_mPreconditionExpression,
                                                        in_mPostconditionList,
                                                        in_mLowTemporalBound,
                                                        in_mHighTemporalBound COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                     const GALGAS_typePreconditionExpression & inOperand1,
                                                     const GALGAS_typePostconditionList & inOperand2,
                                                     const GALGAS_uint & inOperand3,
                                                     const GALGAS_uint & inOperand4
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeTransitionList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_append (GALGAS_typeTransitionList_2D_element inElement,
                                               C_Compiler * /* inCompiler */
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeTransitionList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                      const GALGAS_typePreconditionExpression inOperand1,
                                                      const GALGAS_typePostconditionList inOperand2,
                                                      const GALGAS_uint inOperand3,
                                                      const GALGAS_uint inOperand4,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeTransitionList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                      GALGAS_typePreconditionExpression & outOperand1,
                                                      GALGAS_typePostconditionList & outOperand2,
                                                      GALGAS_uint & outOperand3,
                                                      GALGAS_uint & outOperand4,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        outOperand2.drop () ;
        outOperand3.drop () ;
        outOperand4.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
        outOperand0 = p->mObject.mProperty_mTransitionName ;
        outOperand1 = p->mObject.mProperty_mPreconditionExpression ;
        outOperand2 = p->mObject.mProperty_mPostconditionList ;
        outOperand3 = p->mObject.mProperty_mLowTemporalBound ;
        outOperand4 = p->mObject.mProperty_mHighTemporalBound ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      outOperand2.drop () ;
      outOperand3.drop () ;
      outOperand4.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_popFirst (GALGAS_lstring & outOperand0,
                                                 GALGAS_typePreconditionExpression & outOperand1,
                                                 GALGAS_typePostconditionList & outOperand2,
                                                 GALGAS_uint & outOperand3,
                                                 GALGAS_uint & outOperand4,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    outOperand0 = p->mObject.mProperty_mTransitionName ;
    outOperand1 = p->mObject.mProperty_mPreconditionExpression ;
    outOperand2 = p->mObject.mProperty_mPostconditionList ;
    outOperand3 = p->mObject.mProperty_mLowTemporalBound ;
    outOperand4 = p->mObject.mProperty_mHighTemporalBound ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_popLast (GALGAS_lstring & outOperand0,
                                                GALGAS_typePreconditionExpression & outOperand1,
                                                GALGAS_typePostconditionList & outOperand2,
                                                GALGAS_uint & outOperand3,
                                                GALGAS_uint & outOperand4,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    outOperand0 = p->mObject.mProperty_mTransitionName ;
    outOperand1 = p->mObject.mProperty_mPreconditionExpression ;
    outOperand2 = p->mObject.mProperty_mPostconditionList ;
    outOperand3 = p->mObject.mProperty_mLowTemporalBound ;
    outOperand4 = p->mObject.mProperty_mHighTemporalBound ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::method_first (GALGAS_lstring & outOperand0,
                                              GALGAS_typePreconditionExpression & outOperand1,
                                              GALGAS_typePostconditionList & outOperand2,
                                              GALGAS_uint & outOperand3,
                                              GALGAS_uint & outOperand4,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    outOperand0 = p->mObject.mProperty_mTransitionName ;
    outOperand1 = p->mObject.mProperty_mPreconditionExpression ;
    outOperand2 = p->mObject.mProperty_mPostconditionList ;
    outOperand3 = p->mObject.mProperty_mLowTemporalBound ;
    outOperand4 = p->mObject.mProperty_mHighTemporalBound ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::method_last (GALGAS_lstring & outOperand0,
                                             GALGAS_typePreconditionExpression & outOperand1,
                                             GALGAS_typePostconditionList & outOperand2,
                                             GALGAS_uint & outOperand3,
                                             GALGAS_uint & outOperand4,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    outOperand0 = p->mObject.mProperty_mTransitionName ;
    outOperand1 = p->mObject.mProperty_mPreconditionExpression ;
    outOperand2 = p->mObject.mProperty_mPostconditionList ;
    outOperand3 = p->mObject.mProperty_mLowTemporalBound ;
    outOperand4 = p->mObject.mProperty_mHighTemporalBound ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::add_operation (const GALGAS_typeTransitionList & inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::plusAssign_operation (const GALGAS_typeTransitionList inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMTransitionNameAtIndex (GALGAS_lstring inOperand,
                                                                  GALGAS_uint inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mTransitionName = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeTransitionList::getter_mTransitionNameAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mTransitionName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMPreconditionExpressionAtIndex (GALGAS_typePreconditionExpression inOperand,
                                                                          GALGAS_uint inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPreconditionExpression = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeTransitionList::getter_mPreconditionExpressionAtIndex (const GALGAS_uint & inIndex,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_typePreconditionExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mPreconditionExpression ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMPostconditionListAtIndex (GALGAS_typePostconditionList inOperand,
                                                                     GALGAS_uint inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPostconditionList = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typeTransitionList::getter_mPostconditionListAtIndex (const GALGAS_uint & inIndex,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_typePostconditionList result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mPostconditionList ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMLowTemporalBoundAtIndex (GALGAS_uint inOperand,
                                                                    GALGAS_uint inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mLowTemporalBound = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList::getter_mLowTemporalBoundAtIndex (const GALGAS_uint & inIndex,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mLowTemporalBound ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMHighTemporalBoundAtIndex (GALGAS_uint inOperand,
                                                                     GALGAS_uint inIndex,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mHighTemporalBound = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList::getter_mHighTemporalBoundAtIndex (const GALGAS_uint & inIndex,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_uint result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mHighTemporalBound ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typeTransitionList::cEnumerator_typeTransitionList (const GALGAS_typeTransitionList & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element cEnumerator_typeTransitionList::current (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeTransitionList::current_mTransitionName (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mTransitionName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cEnumerator_typeTransitionList::current_mPreconditionExpression (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mPreconditionExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList cEnumerator_typeTransitionList::current_mPostconditionList (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mPostconditionList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeTransitionList::current_mLowTemporalBound (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mLowTemporalBound ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeTransitionList::current_mHighTemporalBound (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mHighTemporalBound ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//@typeTransitionList type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeTransitionList ("typeTransitionList",
                                           NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTransitionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTransitionList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTransitionList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeTransitionList result ;
  const GALGAS_typeTransitionList * p = (const GALGAS_typeTransitionList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeTransitionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@typeInitialMarkingList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_typeInitialMarkingList : public cCollectionElement {
  public : GALGAS_typeInitialMarkingList_2D_element mObject ;

//--- Constructors
  public : cCollectionElement_typeInitialMarkingList (const GALGAS_typePostcondition & in_mInitValue
                                                      COMMA_LOCATION_ARGS) ;
  public : cCollectionElement_typeInitialMarkingList (const GALGAS_typeInitialMarkingList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GALGAS_typePostcondition & in_mInitValue
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mInitValue) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GALGAS_typeInitialMarkingList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mInitValue) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_typeInitialMarkingList::isValid (void) const {
  return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typeInitialMarkingList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_typeInitialMarkingList (mObject.mProperty_mInitValue COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_typeInitialMarkingList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mInitValue" ":" ;
  mObject.mProperty_mInitValue.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_typeInitialMarkingList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typeInitialMarkingList * operand = (cCollectionElement_typeInitialMarkingList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typeInitialMarkingList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList::GALGAS_typeInitialMarkingList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList::GALGAS_typeInitialMarkingList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeInitialMarkingList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::constructor_listWithValue (const GALGAS_typePostcondition & inOperand0
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typeInitialMarkingList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_typeInitialMarkingList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                               const GALGAS_typePostcondition & in_mInitValue
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_typeInitialMarkingList * p = NULL ;
  macroMyNew (p, cCollectionElement_typeInitialMarkingList (in_mInitValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::addAssign_operation (const GALGAS_typePostcondition & inOperand0
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeInitialMarkingList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_append (GALGAS_typeInitialMarkingList_2D_element inElement,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeInitialMarkingList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_insertAtIndex (const GALGAS_typePostcondition inOperand0,
                                                          const GALGAS_uint inInsertionIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_typeInitialMarkingList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_removeAtIndex (GALGAS_typePostcondition & outOperand0,
                                                          const GALGAS_uint inRemoveIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
        outOperand0 = p->mObject.mProperty_mInitValue ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_popFirst (GALGAS_typePostcondition & outOperand0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_popLast (GALGAS_typePostcondition & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::method_first (GALGAS_typePostcondition & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::method_last (GALGAS_typePostcondition & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::add_operation (const GALGAS_typeInitialMarkingList & inOperand,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::plusAssign_operation (const GALGAS_typeInitialMarkingList inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_setMInitValueAtIndex (GALGAS_typePostcondition inOperand,
                                                                 GALGAS_uint inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mInitValue = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typeInitialMarkingList::getter_mInitValueAtIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  GALGAS_typePostcondition result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    result = p->mObject.mProperty_mInitValue ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_typeInitialMarkingList::cEnumerator_typeInitialMarkingList (const GALGAS_typeInitialMarkingList & inEnumeratedObject,
                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element cEnumerator_typeInitialMarkingList::current (LOCATION_ARGS) const {
  const cCollectionElement_typeInitialMarkingList * p = (const cCollectionElement_typeInitialMarkingList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition cEnumerator_typeInitialMarkingList::current_mInitValue (LOCATION_ARGS) const {
  const cCollectionElement_typeInitialMarkingList * p = (const cCollectionElement_typeInitialMarkingList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
  return p->mObject.mProperty_mInitValue ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//@typeInitialMarkingList type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeInitialMarkingList ("typeInitialMarkingList",
                                               NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInitialMarkingList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInitialMarkingList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInitialMarkingList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList result ;
  const GALGAS_typeInitialMarkingList * p = (const GALGAS_typeInitialMarkingList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeInitialMarkingList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@countList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_countList : public cCollectionElement {
  public : GALGAS_countList_2D_element mObject ;

//--- Constructors
  public : cCollectionElement_countList (const GALGAS_lstring & in_mName,
                                         const GALGAS_typePreconditionExpression & in_mCondition
                                         COMMA_LOCATION_ARGS) ;
  public : cCollectionElement_countList (const GALGAS_countList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GALGAS_lstring & in_mName,
                                                            const GALGAS_typePreconditionExpression & in_mCondition
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mName, in_mCondition) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GALGAS_countList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mName, inElement.mProperty_mCondition) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_countList::isValid (void) const {
  return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_countList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_countList (mObject.mProperty_mName, mObject.mProperty_mCondition COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_countList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mName" ":" ;
  mObject.mProperty_mName.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mCondition" ":" ;
  mObject.mProperty_mCondition.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_countList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_countList * operand = (cCollectionElement_countList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_countList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList::GALGAS_countList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList::GALGAS_countList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_countList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::constructor_listWithValue (const GALGAS_lstring & inOperand0,
                                                              const GALGAS_typePreconditionExpression & inOperand1
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_countList result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_countList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_countList::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const GALGAS_lstring & in_mName,
                                                  const GALGAS_typePreconditionExpression & in_mCondition
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = NULL ;
  macroMyNew (p, cCollectionElement_countList (in_mName,
                                               in_mCondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                            const GALGAS_typePreconditionExpression & inOperand1
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_countList (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_append (GALGAS_countList_2D_element inElement,
                                      C_Compiler * /* inCompiler */
                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_countList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                             const GALGAS_typePreconditionExpression inOperand1,
                                             const GALGAS_uint inInsertionIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_countList (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                             GALGAS_typePreconditionExpression & outOperand1,
                                             const GALGAS_uint inRemoveIndex,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_countList) ;
        outOperand0 = p->mObject.mProperty_mName ;
        outOperand1 = p->mObject.mProperty_mCondition ;
      }
    }else{
      outOperand0.drop () ;
      outOperand1.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_popFirst (GALGAS_lstring & outOperand0,
                                        GALGAS_typePreconditionExpression & outOperand1,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_popLast (GALGAS_lstring & outOperand0,
                                       GALGAS_typePreconditionExpression & outOperand1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::method_first (GALGAS_lstring & outOperand0,
                                     GALGAS_typePreconditionExpression & outOperand1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::method_last (GALGAS_lstring & outOperand0,
                                    GALGAS_typePreconditionExpression & outOperand1,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::add_operation (const GALGAS_countList & inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_countList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListWithRange (const GALGAS_range & inRange,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::plusAssign_operation (const GALGAS_countList inOperand,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_setMNameAtIndex (GALGAS_lstring inOperand,
                                               GALGAS_uint inIndex,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = (cCollectionElement_countList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mName = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_countList::getter_mNameAtIndex (const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    result = p->mObject.mProperty_mName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_setMConditionAtIndex (GALGAS_typePreconditionExpression inOperand,
                                                    GALGAS_uint inIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = (cCollectionElement_countList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mCondition = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_countList::getter_mConditionAtIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  GALGAS_typePreconditionExpression result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    result = p->mObject.mProperty_mCondition ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_countList::cEnumerator_countList (const GALGAS_countList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element cEnumerator_countList::current (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_countList::current_mName (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject.mProperty_mName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cEnumerator_countList::current_mCondition (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject.mProperty_mCondition ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//@countList type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_countList ("countList",
                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_countList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_countList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_countList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_countList result ;
  const GALGAS_countList * p = (const GALGAS_countList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_countList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                                            GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                            GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                                            C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 60)) ;
      GALGAS_typePreconditionExpression var_right_1763 ;
      nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_1763, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeOrExpression::constructor_new (outArgument_outPreConditions, var_right_1763  COMMA_SOURCE_FILE ("spec_parser.galgas", 63)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  nt_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 60)) ;
      nt_term_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                           GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                           GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                           C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.galgas", 76)) ;
      GALGAS_typePreconditionExpression var_right_2215 ;
      nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_2215, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeAndExpression::constructor_new (outArgument_outPreConditions, var_right_2215  COMMA_SOURCE_FILE ("spec_parser.galgas", 79)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  nt_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_1 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.galgas", 76)) ;
      nt_factor_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                             GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                             GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                             C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.galgas", 90)) ;
    nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
    outArgument_outPreConditions = GALGAS_typeComplementExpression::constructor_new (outArgument_outPreConditions  COMMA_SOURCE_FILE ("spec_parser.galgas", 92)) ;
  } break ;
  case 2: {
    nt_primary_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.galgas", 90)) ;
    nt_factor_parse (inCompiler) ;
  } break ;
  case 2: {
    nt_primary_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                              GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                              GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                              C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("spec_parser.galgas", 105)) ;
    nt_parse_5F_precondition_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("spec_parser.galgas", 107)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_true COMMA_SOURCE_FILE ("spec_parser.galgas", 109)) ;
    outArgument_outPreConditions = GALGAS_typeTrueExpression::constructor_new (SOURCE_FILE ("spec_parser.galgas", 110)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.galgas", 112)) ;
    outArgument_outPreConditions = GALGAS_typeFalseExpression::constructor_new (SOURCE_FILE ("spec_parser.galgas", 113)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 115)) ;
    GALGAS_lstring var_name_3235 ;
    var_name_3235 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 117)) ;
    GALGAS_uint var_idx_3272 ;
    ioArgument_inPlacesMap.method_searchKey (var_name_3235, var_idx_3272, inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 119)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 121)) ;
      GALGAS_bool var_sign_3350 ;
      GALGAS_luint var_cst_3361 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3350, var_cst_3361, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeEqualExpression::constructor_new (var_idx_3272, var_sign_3350, var_cst_3361  COMMA_SOURCE_FILE ("spec_parser.galgas", 124)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 126)) ;
      GALGAS_bool var_sign_3516 ;
      GALGAS_luint var_cst_3527 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3516, var_cst_3527, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeNonEqualExpression::constructor_new (var_idx_3272, var_sign_3516, var_cst_3527  COMMA_SOURCE_FILE ("spec_parser.galgas", 129)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 131)) ;
      GALGAS_bool var_sign_3685 ;
      GALGAS_luint var_cst_3696 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3685, var_cst_3696, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeInfOrEqualExpression::constructor_new (var_idx_3272, var_sign_3685, var_cst_3696  COMMA_SOURCE_FILE ("spec_parser.galgas", 134)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 136)) ;
      GALGAS_bool var_sign_3856 ;
      GALGAS_luint var_cst_3867 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3856, var_cst_3867, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeSupOrEqualExpression::constructor_new (var_idx_3272, var_sign_3856, var_cst_3867  COMMA_SOURCE_FILE ("spec_parser.galgas", 139)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 141)) ;
      GALGAS_bool var_sign_4026 ;
      GALGAS_luint var_cst_4037 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_4026, var_cst_4037, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeStrictInfExpression::constructor_new (var_idx_3272, var_sign_4026, var_cst_4037  COMMA_SOURCE_FILE ("spec_parser.galgas", 144)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.galgas", 146)) ;
      GALGAS_bool var_sign_4195 ;
      GALGAS_luint var_cst_4206 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_4195, var_cst_4206, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeStrictSupExpression::constructor_new (var_idx_3272, var_sign_4195, var_cst_4206  COMMA_SOURCE_FILE ("spec_parser.galgas", 149)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 151)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("spec_parser.galgas", 105)) ;
    nt_parse_5F_precondition_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("spec_parser.galgas", 107)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_true COMMA_SOURCE_FILE ("spec_parser.galgas", 109)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.galgas", 112)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 115)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 117)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 121)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 126)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 131)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 136)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 141)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.galgas", 146)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 151)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_ (GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                        GALGAS_bool & outArgument_outSign,
                                                                        GALGAS_luint & outArgument_outValue,
                                                                        C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outSign.drop () ; // Release 'out' argument
  outArgument_outValue.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_constantName_4559 ;
    var_constantName_4559 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 163)) ;
    ioArgument_ioConstantMap.method_searchKey (var_constantName_4559, outArgument_outSign, outArgument_outValue, inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 164)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 166)) ;
    outArgument_outSign = GALGAS_bool (true) ;
    outArgument_outValue = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 168)) ;
  } break ;
  case 3: {
    outArgument_outSign = GALGAS_bool (false) ;
    outArgument_outValue = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 171)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 163)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 166)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 168)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 171)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_ (GALGAS_typeVarMap & ioArgument_outPlacesMap,
                                                                             GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                             GALGAS_typePostconditionList & outArgument_outPostConditionsList,
                                                                             C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPostConditionsList.drop () ; // Release 'out' argument
  outArgument_outPostConditionsList = GALGAS_typePostconditionList::constructor_emptyList (SOURCE_FILE ("spec_parser.galgas", 181)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_lstring var_name_5088 ;
    var_name_5088 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 184)) ;
    GALGAS_uint var_idx_5125 ;
    ioArgument_outPlacesMap.method_searchKey (var_name_5088, var_idx_5125, inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 186)) ;
    GALGAS_typePostcondition var_p_5190 ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 189)) ;
      var_p_5190 = GALGAS_typePostDecrement::constructor_new (var_name_5088, var_idx_5125  COMMA_SOURCE_FILE ("spec_parser.galgas", 190)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 192)) ;
      var_p_5190 = GALGAS_typePostIncrement::constructor_new (var_name_5088, var_idx_5125  COMMA_SOURCE_FILE ("spec_parser.galgas", 193)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 195)) ;
      GALGAS_bool var_sign_5361 ;
      GALGAS_luint var_cst_5372 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5361, var_cst_5372, inCompiler) ;
      var_p_5190 = GALGAS_typeAddConstant::constructor_new (var_name_5088, var_idx_5125, var_sign_5361, var_cst_5372  COMMA_SOURCE_FILE ("spec_parser.galgas", 198)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 200)) ;
      GALGAS_bool var_sign_5514 ;
      GALGAS_luint var_cst_5525 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5514, var_cst_5525, inCompiler) ;
      var_p_5190 = GALGAS_typeSubConstant::constructor_new (var_name_5088, var_idx_5125, var_sign_5514, var_cst_5525  COMMA_SOURCE_FILE ("spec_parser.galgas", 203)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 205)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        GALGAS_bool var_sign_5682 ;
        GALGAS_luint var_cst_5693 ;
        nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5682, var_cst_5693, inCompiler) ;
        var_p_5190 = GALGAS_typeAssignConstant::constructor_new (var_name_5088, var_idx_5125, var_sign_5682, var_cst_5693  COMMA_SOURCE_FILE ("spec_parser.galgas", 209)) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.galgas", 211)) ;
        var_p_5190 = GALGAS_typeAssignInfinity::constructor_new (var_name_5088, var_idx_5125  COMMA_SOURCE_FILE ("spec_parser.galgas", 212)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    outArgument_outPostConditionsList.addAssign_operation (var_p_5190  COMMA_SOURCE_FILE ("spec_parser.galgas", 215)) ;
    switch (select_spec_5F_parser_6 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 217)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 184)) ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 189)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 192)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 195)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 200)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 205)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        nt_parse_5F_constant_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.galgas", 211)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    switch (select_spec_5F_parser_6 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 217)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_ (GALGAS_uint & outArgument_lowTemporalBound,
                                                                     GALGAS_uint & outArgument_highTemporalBound,
                                                                     C_Lexique_spec_5F_scanner * /* inCompiler */) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  outArgument_lowTemporalBound = GALGAS_uint ((uint32_t) 0U) ;
  outArgument_highTemporalBound = GALGAS_uint ((uint32_t) 0U) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_ (GALGAS_uint & outArgument_lowTemporalBound,
                                                                     GALGAS_uint & outArgument_highTemporalBound,
                                                                     C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 235)) ;
  GALGAS_luint var_low_6332 ;
  var_low_6332 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 237)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 238)) ;
  GALGAS_luint var_high_6378 ;
  var_high_6378 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 240)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 241)) ;
  outArgument_lowTemporalBound = var_low_6332.getter_uint (SOURCE_FILE ("spec_parser.galgas", 242)) ;
  outArgument_highTemporalBound = var_high_6378.getter_uint (SOURCE_FILE ("spec_parser.galgas", 243)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, outArgument_lowTemporalBound.objectCompare (outArgument_highTemporalBound)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (var_high_6378.getter_location (SOURCE_FILE ("spec_parser.galgas", 245)), GALGAS_string ("High bound must be greater than or equal to low bound"), fixItArray1  COMMA_SOURCE_FILE ("spec_parser.galgas", 245)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 235)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 237)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 238)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 240)) ;
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 241)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_ (GALGAS_uint & outArgument_outHashMapSize,
                                                             GALGAS_uint & outArgument_outGarbagePeriod,
                                                             GALGAS_typeVarMap & outArgument_outPlacesMap,
                                                             GALGAS_typeTransitionList & outArgument_outTransitionList,
                                                             GALGAS_typeInitialMarkingList & outArgument_outInitialMarkingList,
                                                             GALGAS_countList & outArgument_outCountList,
                                                             C_Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outHashMapSize.drop () ; // Release 'out' argument
  outArgument_outGarbagePeriod.drop () ; // Release 'out' argument
  outArgument_outPlacesMap.drop () ; // Release 'out' argument
  outArgument_outTransitionList.drop () ; // Release 'out' argument
  outArgument_outInitialMarkingList.drop () ; // Release 'out' argument
  outArgument_outCountList.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.galgas", 270)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.galgas", 273)) ;
    GALGAS_luint var_n_7300 ;
    var_n_7300 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 275)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 276)) ;
    outArgument_outHashMapSize = var_n_7300.getter_uint (SOURCE_FILE ("spec_parser.galgas", 277)) ;
  } break ;
  case 2: {
    outArgument_outHashMapSize = GALGAS_uint ((uint32_t) 16U) ;
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.galgas", 282)) ;
    GALGAS_luint var_n_7440 ;
    var_n_7440 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 284)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 285)) ;
    outArgument_outGarbagePeriod = var_n_7440.getter_uint (SOURCE_FILE ("spec_parser.galgas", 286)) ;
  } break ;
  case 2: {
    outArgument_outGarbagePeriod = GALGAS_uint ((uint32_t) 16U) ;
  } break ;
  default:
    break ;
  }
  outArgument_outTransitionList = GALGAS_typeTransitionList::constructor_emptyList (SOURCE_FILE ("spec_parser.galgas", 290)) ;
  outArgument_outPlacesMap = GALGAS_typeVarMap::constructor_emptyMap (SOURCE_FILE ("spec_parser.galgas", 291)) ;
  GALGAS_typeCstMap var_constantMap_7652 = GALGAS_typeCstMap::constructor_emptyMap (SOURCE_FILE ("spec_parser.galgas", 292)) ;
  outArgument_outCountList = GALGAS_countList::constructor_emptyList (SOURCE_FILE ("spec_parser.galgas", 293)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_11 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.galgas", 297)) ;
      GALGAS_lstring var_constantName_7784 ;
      var_constantName_7784 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 299)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 300)) ;
      GALGAS_bool var_sign_7839 ;
      GALGAS_luint var_value_7856 ;
      nt_parse_5F_constant_ (var_constantMap_7652, var_sign_7839, var_value_7856, inCompiler) ;
      {
      var_constantMap_7652.setter_insertKey (var_constantName_7784, var_sign_7839, var_value_7856, inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 304)) ;
      }
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 305)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.galgas", 308)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        GALGAS_lstring var_placeName_8038 ;
        var_placeName_8038 = inCompiler->synthetizedAttribute_theString () ;
        inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 311)) ;
        {
        outArgument_outPlacesMap.setter_insertKey (var_placeName_8038, outArgument_outPlacesMap.getter_count (SOURCE_FILE ("spec_parser.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 312)) ;
        }
        switch (select_spec_5F_parser_12 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 314)) ;
        } break ;
        default:
          repeatFlag_1 = false ;
          break ;
        }
      }
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 316)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.galgas", 319)) ;
      GALGAS_lstring var_transitionName_8228 ;
      var_transitionName_8228 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.galgas", 321)) ;
      GALGAS_typePreconditionExpression var_preConditions_8311 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7652, var_preConditions_8311, inCompiler) ;
      GALGAS_uint var_lowTemporalBound_8407 ;
      GALGAS_uint var_highTemporalBound_8435 ;
      nt_parse_5F_bound_ (var_lowTemporalBound_8407, var_highTemporalBound_8435, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.galgas", 327)) ;
      GALGAS_typePostconditionList var_postConditions_8540 ;
      nt_parse_5F_postcondition_ (outArgument_outPlacesMap, var_constantMap_7652, var_postConditions_8540, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 330)) ;
      outArgument_outTransitionList.addAssign_operation (var_transitionName_8228, var_preConditions_8311, var_postConditions_8540, var_lowTemporalBound_8407, var_highTemporalBound_8435  COMMA_SOURCE_FILE ("spec_parser.galgas", 331)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.galgas", 334)) ;
  outArgument_outInitialMarkingList = GALGAS_typeInitialMarkingList::constructor_emptyList (SOURCE_FILE ("spec_parser.galgas", 335)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_lstring var_placeName_8846 ;
    var_placeName_8846 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 338)) ;
    GALGAS_uint var_placeID_8893 ;
    outArgument_outPlacesMap.method_searchKey (var_placeName_8846, var_placeID_8893, inCompiler COMMA_SOURCE_FILE ("spec_parser.galgas", 340)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 341)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      GALGAS_luint var_cst_8979 ;
      GALGAS_bool var_sign_8996 ;
      nt_parse_5F_constant_ (var_constantMap_7652, var_sign_8996, var_cst_8979, inCompiler) ;
      GALGAS_typePostcondition var_init_9074 = GALGAS_typeAssignConstant::constructor_new (var_placeName_8846, var_placeID_8893, var_sign_8996, var_cst_8979  COMMA_SOURCE_FILE ("spec_parser.galgas", 346)) ;
      outArgument_outInitialMarkingList.addAssign_operation (var_init_9074  COMMA_SOURCE_FILE ("spec_parser.galgas", 347)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.galgas", 349)) ;
      GALGAS_typePostcondition var_init_9226 = GALGAS_typeAssignInfinity::constructor_new (var_placeName_8846, var_placeID_8893  COMMA_SOURCE_FILE ("spec_parser.galgas", 350)) ;
      outArgument_outInitialMarkingList.addAssign_operation (var_init_9226  COMMA_SOURCE_FILE ("spec_parser.galgas", 351)) ;
    } break ;
    default:
      break ;
    }
    switch (select_spec_5F_parser_13 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 354)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 356)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    switch (select_spec_5F_parser_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.galgas", 360)) ;
      GALGAS_lstring var_name_9412 ;
      var_name_9412 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.galgas", 362)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.galgas", 363)) ;
      GALGAS_typePreconditionExpression var_conditions_9491 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7652, var_conditions_9491, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 366)) ;
      outArgument_outCountList.addAssign_operation (var_name_9412, var_conditions_9491  COMMA_SOURCE_FILE ("spec_parser.galgas", 367)) ;
    } break ;
    default:
      repeatFlag_3 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.galgas", 369)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_parse (C_Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.galgas", 270)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.galgas", 273)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 275)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 276)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.galgas", 282)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.galgas", 284)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 285)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_11 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.galgas", 297)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 299)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 300)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 305)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.galgas", 308)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 311)) ;
        switch (select_spec_5F_parser_12 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 314)) ;
        } break ;
        default:
          repeatFlag_1 = false ;
          break ;
        }
      }
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 316)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.galgas", 319)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.galgas", 321)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      nt_parse_5F_bound_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.galgas", 327)) ;
      nt_parse_5F_postcondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 330)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.galgas", 334)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.galgas", 338)) ;
    inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.galgas", 341)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.galgas", 349)) ;
    } break ;
    default:
      break ;
    }
    switch (select_spec_5F_parser_13 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.galgas", 354)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 356)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    switch (select_spec_5F_parser_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.galgas", 360)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.galgas", 362)) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.galgas", 363)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.galgas", 366)) ;
    } break ;
    default:
      repeatFlag_3 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.galgas", 369)) ;
  inCompiler->resetTemplateString () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::GALGAS_typePostconditionList_2D_element (void) :
mProperty_mPostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::~ GALGAS_typePostconditionList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::GALGAS_typePostconditionList_2D_element (const GALGAS_typePostcondition & inOperand0) :
mProperty_mPostcondition (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element GALGAS_typePostconditionList_2D_element::constructor_new (const GALGAS_typePostcondition & inOperand0 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typePostconditionList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typePostconditionList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typePostconditionList_2D_element::objectCompare (const GALGAS_typePostconditionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mPostcondition.objectCompare (inOperand.mProperty_mPostcondition) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typePostconditionList_2D_element::isValid (void) const {
  return mProperty_mPostcondition.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList_2D_element::drop (void) {
  mProperty_mPostcondition.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @typePostconditionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mPostcondition.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostconditionList_2D_element::getter_mPostcondition (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPostcondition ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@typePostconditionList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePostconditionList_2D_element ("typePostconditionList-element",
                                                         NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostconditionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostconditionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostconditionList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element GALGAS_typePostconditionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typePostconditionList_2D_element result ;
  const GALGAS_typePostconditionList_2D_element * p = (const GALGAS_typePostconditionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePostconditionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::GALGAS_typeInitialMarkingList_2D_element (void) :
mProperty_mInitValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::~ GALGAS_typeInitialMarkingList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::GALGAS_typeInitialMarkingList_2D_element (const GALGAS_typePostcondition & inOperand0) :
mProperty_mInitValue (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element GALGAS_typeInitialMarkingList_2D_element::constructor_new (const GALGAS_typePostcondition & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_typeInitialMarkingList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typeInitialMarkingList_2D_element::objectCompare (const GALGAS_typeInitialMarkingList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mInitValue.objectCompare (inOperand.mProperty_mInitValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeInitialMarkingList_2D_element::isValid (void) const {
  return mProperty_mInitValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList_2D_element::drop (void) {
  mProperty_mInitValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @typeInitialMarkingList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mInitValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typeInitialMarkingList_2D_element::getter_mInitValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_mInitValue ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@typeInitialMarkingList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ("typeInitialMarkingList-element",
                                                          NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInitialMarkingList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInitialMarkingList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInitialMarkingList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element GALGAS_typeInitialMarkingList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList_2D_element result ;
  const GALGAS_typeInitialMarkingList_2D_element * p = (const GALGAS_typeInitialMarkingList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeInitialMarkingList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeEqualExpression * p = (const cPtr_typeEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeEqualExpression::objectCompare (const GALGAS_typeEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression::GALGAS_typeEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeEqualExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                      GALGAS_bool::constructor_default (HERE),
                                                      GALGAS_luint::constructor_default (HERE)
                                                      COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression::GALGAS_typeEqualExpression (const cPtr_typeEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeEqualExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                        const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                        const GALGAS_luint & inAttribute_mConstant
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_typeEqualExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeEqualExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeEqualExpression * p = (const cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeEqualExpression * p = (const cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeEqualExpression * p = (const cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeEqualExpression::setter_setMVar (GALGAS_uint inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeEqualExpression::cPtr_typeEqualExpression (const GALGAS_uint & in_mVar,
                                                    const GALGAS_bool & in_mNegativeConstant,
                                                    const GALGAS_luint & in_mConstant
                                                    COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression ;
}

void cPtr_typeEqualExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@typeEqualExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeEqualExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeEqualExpression ("typeEqualExpression",
                                            & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeEqualExpression result ;
  const GALGAS_typeEqualExpression * p = (const GALGAS_typeEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeNonEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeNonEqualExpression * p = (const cPtr_typeNonEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeNonEqualExpression::objectCompare (const GALGAS_typeNonEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression::GALGAS_typeNonEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeNonEqualExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                         GALGAS_bool::constructor_default (HERE),
                                                         GALGAS_luint::constructor_default (HERE)
                                                         COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression::GALGAS_typeNonEqualExpression (const cPtr_typeNonEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeNonEqualExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                              const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                              const GALGAS_luint & inAttribute_mConstant
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeNonEqualExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeNonEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeNonEqualExpression * p = (const cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeNonEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeNonEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeNonEqualExpression * p = (const cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeNonEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeNonEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeNonEqualExpression * p = (const cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeNonEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeNonEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeNonEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeNonEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeNonEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeNonEqualExpression::cPtr_typeNonEqualExpression (const GALGAS_uint & in_mVar,
                                                          const GALGAS_bool & in_mNegativeConstant,
                                                          const GALGAS_luint & in_mConstant
                                                          COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeNonEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression ;
}

void cPtr_typeNonEqualExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@typeNonEqualExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeNonEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeNonEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeNonEqualExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeNonEqualExpression ("typeNonEqualExpression",
                                               & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeNonEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeNonEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeNonEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression result ;
  const GALGAS_typeNonEqualExpression * p = (const GALGAS_typeNonEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeNonEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeNonEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeInfOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeInfOrEqualExpression * p = (const cPtr_typeInfOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeInfOrEqualExpression::objectCompare (const GALGAS_typeInfOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression::GALGAS_typeInfOrEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeInfOrEqualExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                           GALGAS_bool::constructor_default (HERE),
                                                           GALGAS_luint::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression::GALGAS_typeInfOrEqualExpression (const cPtr_typeInfOrEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeInfOrEqualExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                                  const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                                  const GALGAS_luint & inAttribute_mConstant
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeInfOrEqualExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeInfOrEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeInfOrEqualExpression * p = (const cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeInfOrEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeInfOrEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeInfOrEqualExpression * p = (const cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeInfOrEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeInfOrEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeInfOrEqualExpression * p = (const cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeInfOrEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeInfOrEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeInfOrEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeInfOrEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeInfOrEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeInfOrEqualExpression::cPtr_typeInfOrEqualExpression (const GALGAS_uint & in_mVar,
                                                              const GALGAS_bool & in_mNegativeConstant,
                                                              const GALGAS_luint & in_mConstant
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeInfOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;
}

void cPtr_typeInfOrEqualExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@typeInfOrEqualExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeInfOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeInfOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeInfOrEqualExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeInfOrEqualExpression ("typeInfOrEqualExpression",
                                                 & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInfOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInfOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInfOrEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression result ;
  const GALGAS_typeInfOrEqualExpression * p = (const GALGAS_typeInfOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeInfOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInfOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeSupOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeSupOrEqualExpression * p = (const cPtr_typeSupOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeSupOrEqualExpression::objectCompare (const GALGAS_typeSupOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression::GALGAS_typeSupOrEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeSupOrEqualExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                           GALGAS_bool::constructor_default (HERE),
                                                           GALGAS_luint::constructor_default (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression::GALGAS_typeSupOrEqualExpression (const cPtr_typeSupOrEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSupOrEqualExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                                  const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                                  const GALGAS_luint & inAttribute_mConstant
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeSupOrEqualExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeSupOrEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSupOrEqualExpression * p = (const cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeSupOrEqualExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeSupOrEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSupOrEqualExpression * p = (const cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeSupOrEqualExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeSupOrEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSupOrEqualExpression * p = (const cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeSupOrEqualExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSupOrEqualExpression::setter_setMVar (GALGAS_uint inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSupOrEqualExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSupOrEqualExpression::setter_setMConstant (GALGAS_luint inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeSupOrEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeSupOrEqualExpression::cPtr_typeSupOrEqualExpression (const GALGAS_uint & in_mVar,
                                                              const GALGAS_bool & in_mNegativeConstant,
                                                              const GALGAS_luint & in_mConstant
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeSupOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;
}

void cPtr_typeSupOrEqualExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@typeSupOrEqualExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeSupOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeSupOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeSupOrEqualExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeSupOrEqualExpression ("typeSupOrEqualExpression",
                                                 & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSupOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSupOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSupOrEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression result ;
  const GALGAS_typeSupOrEqualExpression * p = (const GALGAS_typeSupOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeSupOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSupOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeStrictInfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeStrictInfExpression * p = (const cPtr_typeStrictInfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeStrictInfExpression::objectCompare (const GALGAS_typeStrictInfExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression::GALGAS_typeStrictInfExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeStrictInfExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                          GALGAS_bool::constructor_default (HERE),
                                                          GALGAS_luint::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression::GALGAS_typeStrictInfExpression (const cPtr_typeStrictInfExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictInfExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                                const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                                const GALGAS_luint & inAttribute_mConstant
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeStrictInfExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeStrictInfExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictInfExpression * p = (const cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeStrictInfExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeStrictInfExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictInfExpression * p = (const cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeStrictInfExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeStrictInfExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictInfExpression * p = (const cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeStrictInfExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setter_setMVar (GALGAS_uint inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictInfExpression::setter_setMVar (GALGAS_uint inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictInfExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setter_setMConstant (GALGAS_luint inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictInfExpression::setter_setMConstant (GALGAS_luint inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictInfExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeStrictInfExpression::cPtr_typeStrictInfExpression (const GALGAS_uint & in_mVar,
                                                            const GALGAS_bool & in_mNegativeConstant,
                                                            const GALGAS_luint & in_mConstant
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeStrictInfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression ;
}

void cPtr_typeStrictInfExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@typeStrictInfExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeStrictInfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeStrictInfExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeStrictInfExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeStrictInfExpression ("typeStrictInfExpression",
                                                & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictInfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictInfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictInfExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression result ;
  const GALGAS_typeStrictInfExpression * p = (const GALGAS_typeStrictInfExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeStrictInfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictInfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeStrictSupExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeStrictSupExpression * p = (const cPtr_typeStrictSupExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeStrictSupExpression::objectCompare (const GALGAS_typeStrictSupExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression::GALGAS_typeStrictSupExpression (void) :
GALGAS_typePreconditionExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeStrictSupExpression::constructor_new (GALGAS_uint::constructor_default (HERE),
                                                          GALGAS_bool::constructor_default (HERE),
                                                          GALGAS_luint::constructor_default (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression::GALGAS_typeStrictSupExpression (const cPtr_typeStrictSupExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictSupExpression) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::constructor_new (const GALGAS_uint & inAttribute_mVar,
                                                                                const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                                const GALGAS_luint & inAttribute_mConstant
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression result ;
  if (inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeStrictSupExpression (inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeStrictSupExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictSupExpression * p = (const cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeStrictSupExpression::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeStrictSupExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictSupExpression * p = (const cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeStrictSupExpression::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeStrictSupExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeStrictSupExpression * p = (const cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeStrictSupExpression::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setter_setMVar (GALGAS_uint inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictSupExpression::setter_setMVar (GALGAS_uint inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictSupExpression::setter_setMNegativeConstant (GALGAS_bool inValue
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setter_setMConstant (GALGAS_luint inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeStrictSupExpression::setter_setMConstant (GALGAS_luint inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictSupExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeStrictSupExpression::cPtr_typeStrictSupExpression (const GALGAS_uint & in_mVar,
                                                            const GALGAS_bool & in_mNegativeConstant,
                                                            const GALGAS_luint & in_mConstant
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeStrictSupExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression ;
}

void cPtr_typeStrictSupExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@typeStrictSupExpression:" ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeStrictSupExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeStrictSupExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeStrictSupExpression type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeStrictSupExpression ("typeStrictSupExpression",
                                                & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictSupExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictSupExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictSupExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression result ;
  const GALGAS_typeStrictSupExpression * p = (const GALGAS_typeStrictSupExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeStrictSupExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictSupExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typePostDecrement::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typePostDecrement * p = (const cPtr_typePostDecrement *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typePostDecrement) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typePostDecrement::objectCompare (const GALGAS_typePostDecrement & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement::GALGAS_typePostDecrement (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::constructor_default (LOCATION_ARGS) {
  return GALGAS_typePostDecrement::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_uint::constructor_default (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement::GALGAS_typePostDecrement (const cPtr_typePostDecrement * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostDecrement) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                    const GALGAS_uint & inAttribute_mVar
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typePostDecrement result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typePostDecrement (inAttribute_mVarName, inAttribute_mVar COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typePostDecrement::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typePostDecrement * p = (const cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typePostDecrement::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typePostDecrement::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typePostDecrement * p = (const cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typePostDecrement::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostDecrement::setter_setMVarName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typePostDecrement::setter_setMVarName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostDecrement::setter_setMVar (GALGAS_uint inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typePostDecrement::setter_setMVar (GALGAS_uint inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typePostDecrement class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typePostDecrement::cPtr_typePostDecrement (const GALGAS_lstring & in_mVarName,
                                                const GALGAS_uint & in_mVar
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typePostDecrement::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement ;
}

void cPtr_typePostDecrement::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@typePostDecrement:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typePostDecrement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typePostDecrement (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typePostDecrement type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePostDecrement ("typePostDecrement",
                                          & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostDecrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostDecrement::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostDecrement (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostDecrement result ;
  const GALGAS_typePostDecrement * p = (const GALGAS_typePostDecrement *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePostDecrement *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostDecrement", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeAddConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAddConstant) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeAddConstant::objectCompare (const GALGAS_typeAddConstant & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant::GALGAS_typeAddConstant (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeAddConstant::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_luint::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant::GALGAS_typeAddConstant (const cPtr_typeAddConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAddConstant) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                const GALGAS_uint & inAttribute_mVar,
                                                                const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                const GALGAS_luint & inAttribute_mConstant
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeAddConstant result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeAddConstant (inAttribute_mVarName, inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAddConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typeAddConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAddConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeAddConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeAddConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeAddConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeAddConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeAddConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setter_setMVarName (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::setter_setMVarName (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setter_setMVar (GALGAS_uint inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::setter_setMVar (GALGAS_uint inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setter_setMConstant (GALGAS_luint inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::setter_setMConstant (GALGAS_luint inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeAddConstant class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeAddConstant::cPtr_typeAddConstant (const GALGAS_lstring & in_mVarName,
                                            const GALGAS_uint & in_mVar,
                                            const GALGAS_bool & in_mNegativeConstant,
                                            const GALGAS_luint & in_mConstant
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAddConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant ;
}

void cPtr_typeAddConstant::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@typeAddConstant:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAddConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeAddConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeAddConstant type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeAddConstant ("typeAddConstant",
                                        & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAddConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAddConstant::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAddConstant (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeAddConstant result ;
  const GALGAS_typeAddConstant * p = (const GALGAS_typeAddConstant *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeAddConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAddConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeSubConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeSubConstant) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeSubConstant::objectCompare (const GALGAS_typeSubConstant & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant::GALGAS_typeSubConstant (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeSubConstant::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_luint::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant::GALGAS_typeSubConstant (const cPtr_typeSubConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSubConstant) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                const GALGAS_uint & inAttribute_mVar,
                                                                const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                const GALGAS_luint & inAttribute_mConstant
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeSubConstant result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeSubConstant (inAttribute_mVarName, inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeSubConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typeSubConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeSubConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeSubConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeSubConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeSubConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeSubConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeSubConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setter_setMVarName (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::setter_setMVarName (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setter_setMVar (GALGAS_uint inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::setter_setMVar (GALGAS_uint inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setter_setMConstant (GALGAS_luint inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::setter_setMConstant (GALGAS_luint inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeSubConstant class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeSubConstant::cPtr_typeSubConstant (const GALGAS_lstring & in_mVarName,
                                            const GALGAS_uint & in_mVar,
                                            const GALGAS_bool & in_mNegativeConstant,
                                            const GALGAS_luint & in_mConstant
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeSubConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant ;
}

void cPtr_typeSubConstant::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@typeSubConstant:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeSubConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeSubConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeSubConstant type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeSubConstant ("typeSubConstant",
                                        & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSubConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSubConstant::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSubConstant (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeSubConstant result ;
  const GALGAS_typeSubConstant * p = (const GALGAS_typeSubConstant *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeSubConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSubConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeAssignConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAssignConstant) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeAssignConstant::objectCompare (const GALGAS_typeAssignConstant & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant::GALGAS_typeAssignConstant (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeAssignConstant::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_uint::constructor_default (HERE),
                                                     GALGAS_bool::constructor_default (HERE),
                                                     GALGAS_luint::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant::GALGAS_typeAssignConstant (const cPtr_typeAssignConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignConstant) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                      const GALGAS_uint & inAttribute_mVar,
                                                                      const GALGAS_bool & inAttribute_mNegativeConstant,
                                                                      const GALGAS_luint & inAttribute_mConstant
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignConstant result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid () && inAttribute_mNegativeConstant.isValid () && inAttribute_mConstant.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeAssignConstant (inAttribute_mVarName, inAttribute_mVar, inAttribute_mNegativeConstant, inAttribute_mConstant COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAssignConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typeAssignConstant::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAssignConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeAssignConstant::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeAssignConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    result = p->mProperty_mNegativeConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_typeAssignConstant::getter_mNegativeConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mNegativeConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeAssignConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  GALGAS_luint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    result = p->mProperty_mConstant ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint cPtr_typeAssignConstant::getter_mConstant (UNUSED_LOCATION_ARGS) const {
  return mProperty_mConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setter_setMVarName (GALGAS_lstring inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::setter_setMVarName (GALGAS_lstring inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setter_setMVar (GALGAS_uint inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::setter_setMVar (GALGAS_uint inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::setter_setMNegativeConstant (GALGAS_bool inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mNegativeConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setter_setMConstant (GALGAS_luint inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::setter_setMConstant (GALGAS_luint inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mConstant = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignConstant class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeAssignConstant::cPtr_typeAssignConstant (const GALGAS_lstring & in_mVarName,
                                                  const GALGAS_uint & in_mVar,
                                                  const GALGAS_bool & in_mNegativeConstant,
                                                  const GALGAS_luint & in_mConstant
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar),
mProperty_mNegativeConstant (in_mNegativeConstant),
mProperty_mConstant (in_mConstant) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAssignConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant ;
}

void cPtr_typeAssignConstant::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@typeAssignConstant:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAssignConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeAssignConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeAssignConstant type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeAssignConstant ("typeAssignConstant",
                                           & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignConstant::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignConstant (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignConstant result ;
  const GALGAS_typeAssignConstant * p = (const GALGAS_typeAssignConstant *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeAssignConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typeAssignInfinity::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typeAssignInfinity * p = (const cPtr_typeAssignInfinity *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typeAssignInfinity::objectCompare (const GALGAS_typeAssignInfinity & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity::GALGAS_typeAssignInfinity (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::constructor_default (LOCATION_ARGS) {
  return GALGAS_typeAssignInfinity::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_uint::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity::GALGAS_typeAssignInfinity (const cPtr_typeAssignInfinity * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignInfinity) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                      const GALGAS_uint & inAttribute_mVar
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignInfinity result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typeAssignInfinity (inAttribute_mVarName, inAttribute_mVar COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAssignInfinity::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignInfinity * p = (const cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typeAssignInfinity::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAssignInfinity::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typeAssignInfinity * p = (const cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typeAssignInfinity::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignInfinity::setter_setMVarName (GALGAS_lstring inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignInfinity::setter_setMVarName (GALGAS_lstring inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeAssignInfinity::setter_setMVar (GALGAS_uint inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typeAssignInfinity::setter_setMVar (GALGAS_uint inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignInfinity class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typeAssignInfinity::cPtr_typeAssignInfinity (const GALGAS_lstring & in_mVarName,
                                                  const GALGAS_uint & in_mVar
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAssignInfinity::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity ;
}

void cPtr_typeAssignInfinity::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@typeAssignInfinity:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAssignInfinity::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typeAssignInfinity (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typeAssignInfinity type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeAssignInfinity ("typeAssignInfinity",
                                           & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignInfinity::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignInfinity::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignInfinity (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignInfinity result ;
  const GALGAS_typeAssignInfinity * p = (const GALGAS_typeAssignInfinity *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeAssignInfinity *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignInfinity", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_spec_grammar [] = {
// At index 0 : <axiome>, in file 'spec_parser.ggs', line 263
  TERMINAL (C_Lexique_spec_5F_scanner::kToken_system) // $system$
, NONTERMINAL (17) // <select_spec_5F_parser_9>
, NONTERMINAL (18) // <select_spec_5F_parser_10>
, NONTERMINAL (19) // <select_spec_5F_parser_11>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_init) // $init$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (22) // <select_spec_5F_parser_14>
, NONTERMINAL (21) // <select_spec_5F_parser_13>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (23) // <select_spec_5F_parser_15>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 13 : <parse_precondition>, in file 'spec_parser.ggs', line 53
, NONTERMINAL (2) // <term>
, NONTERMINAL (8) // <select_spec_5F_parser_0>
, END_PRODUCTION
// At index 16 : <term>, in file 'spec_parser.ggs', line 69
, NONTERMINAL (3) // <factor>
, NONTERMINAL (9) // <select_spec_5F_parser_1>
, END_PRODUCTION
// At index 19 : <factor>, in file 'spec_parser.ggs', line 85
, NONTERMINAL (10) // <select_spec_5F_parser_2>
, END_PRODUCTION
// At index 21 : <primary>, in file 'spec_parser.ggs', line 100
, NONTERMINAL (11) // <select_spec_5F_parser_3>
, END_PRODUCTION
// At index 23 : <parse_postcondition>, in file 'spec_parser.ggs', line 177
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <select_spec_5F_parser_7>
, NONTERMINAL (14) // <select_spec_5F_parser_6>
, END_PRODUCTION
// At index 27 : <parse_constant>, in file 'spec_parser.ggs', line 157
, NONTERMINAL (13) // <select_spec_5F_parser_5>
, END_PRODUCTION
// At index 29 : <parse_bound>, in file 'spec_parser.ggs', line 223
, END_PRODUCTION
// At index 30 : <parse_bound>, in file 'spec_parser.ggs', line 232
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__5B_) // $[$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 36 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
, END_PRODUCTION
// At index 37 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__7C_) // $|$
, NONTERMINAL (2) // <term>
, NONTERMINAL (8) // <select_spec_5F_parser_0>
, END_PRODUCTION
// At index 41 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 74
, END_PRODUCTION
// At index 42 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 74
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__26_) // $&$
, NONTERMINAL (3) // <factor>
, NONTERMINAL (9) // <select_spec_5F_parser_1>
, END_PRODUCTION
// At index 46 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 89
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__7E_) // $~$
, NONTERMINAL (3) // <factor>
, END_PRODUCTION
// At index 49 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 89
, NONTERMINAL (4) // <primary>
, END_PRODUCTION
// At index 51 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__28_) // $($
, NONTERMINAL (1) // <parse_precondition>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 55 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_true) // $true$
, END_PRODUCTION
// At index 57 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_false) // $false$
, END_PRODUCTION
// At index 59 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__7B_) // ${$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (12) // <select_spec_5F_parser_4>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__7D_) // $}$
, END_PRODUCTION
// At index 64 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3D__3D_) // $==$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 67 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__21__3D_) // $!=$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 70 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3C__3D_) // $<=$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 73 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3E__3D_) // $>=$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 76 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3C_) // $<$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 79 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 82 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 84 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2D_) // $-$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 87 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, END_PRODUCTION
// At index 89 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 182
, END_PRODUCTION
// At index 90 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 182
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <select_spec_5F_parser_7>
, NONTERMINAL (14) // <select_spec_5F_parser_6>
, END_PRODUCTION
// At index 95 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2D__2D_) // $--$
, END_PRODUCTION
// At index 97 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2B__2B_) // $++$
, END_PRODUCTION
// At index 99 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2B__3D_) // $+=$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 102 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2D__3D_) // $-=$
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 105 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (16) // <select_spec_5F_parser_8>
, END_PRODUCTION
// At index 108 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 206
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 110 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 206
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_infinity) // $infinity$
, END_PRODUCTION
// At index 112 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 272
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_hashmapsize) // $hashmapsize$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, END_PRODUCTION
// At index 116 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 272
, END_PRODUCTION
// At index 117 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 281
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_garbageperiod) // $garbageperiod$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, END_PRODUCTION
// At index 121 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 281
, END_PRODUCTION
// At index 122 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
, END_PRODUCTION
// At index 123 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_const) // $const$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3D_) // $=$
, NONTERMINAL (6) // <parse_constant>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (19) // <select_spec_5F_parser_11>
, END_PRODUCTION
// At index 130 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_var) // $var$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (20) // <select_spec_5F_parser_12>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (19) // <select_spec_5F_parser_11>
, END_PRODUCTION
// At index 136 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_rule) // $rule$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_string) // $literal_string$
, NONTERMINAL (1) // <parse_precondition>
, NONTERMINAL (7) // <parse_bound>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (5) // <parse_postcondition>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (19) // <select_spec_5F_parser_11>
, END_PRODUCTION
// At index 145 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 309
, END_PRODUCTION
// At index 146 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 309
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (20) // <select_spec_5F_parser_12>
, END_PRODUCTION
// At index 150 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 336
, END_PRODUCTION
// At index 151 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 336
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (22) // <select_spec_5F_parser_14>
, NONTERMINAL (21) // <select_spec_5F_parser_13>
, END_PRODUCTION
// At index 157 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 342
, NONTERMINAL (6) // <parse_constant>
, END_PRODUCTION
// At index 159 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 342
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_infinity) // $infinity$
, END_PRODUCTION
// At index 161 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 358
, END_PRODUCTION
// At index 162 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 358
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_count) // $count$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken_literal_5F_string) // $literal_string$
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (1) // <parse_precondition>
, TERMINAL (C_Lexique_spec_5F_scanner::kToken__3B_) // $;$
, NONTERMINAL (23) // <select_spec_5F_parser_15>
, END_PRODUCTION
// At index 169 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <axiome>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_spec_grammar [54] = {
 {"<axiome>", "spec_parser", 0}, // at index 0
 {"<parse_precondition>", "spec_parser", 13}, // at index 1
 {"<term>", "spec_parser", 16}, // at index 2
 {"<factor>", "spec_parser", 19}, // at index 3
 {"<primary>", "spec_parser", 21}, // at index 4
 {"<parse_postcondition>", "spec_parser", 23}, // at index 5
 {"<parse_constant>", "spec_parser", 27}, // at index 6
 {"<parse_bound>", "spec_parser", 29}, // at index 7
 {"<parse_bound>", "spec_parser", 30}, // at index 8
 {"<select_spec_5F_parser_0>", "spec_parser", 36}, // at index 9
 {"<select_spec_5F_parser_0>", "spec_parser", 37}, // at index 10
 {"<select_spec_5F_parser_1>", "spec_parser", 41}, // at index 11
 {"<select_spec_5F_parser_1>", "spec_parser", 42}, // at index 12
 {"<select_spec_5F_parser_2>", "spec_parser", 46}, // at index 13
 {"<select_spec_5F_parser_2>", "spec_parser", 49}, // at index 14
 {"<select_spec_5F_parser_3>", "spec_parser", 51}, // at index 15
 {"<select_spec_5F_parser_3>", "spec_parser", 55}, // at index 16
 {"<select_spec_5F_parser_3>", "spec_parser", 57}, // at index 17
 {"<select_spec_5F_parser_3>", "spec_parser", 59}, // at index 18
 {"<select_spec_5F_parser_4>", "spec_parser", 64}, // at index 19
 {"<select_spec_5F_parser_4>", "spec_parser", 67}, // at index 20
 {"<select_spec_5F_parser_4>", "spec_parser", 70}, // at index 21
 {"<select_spec_5F_parser_4>", "spec_parser", 73}, // at index 22
 {"<select_spec_5F_parser_4>", "spec_parser", 76}, // at index 23
 {"<select_spec_5F_parser_4>", "spec_parser", 79}, // at index 24
 {"<select_spec_5F_parser_5>", "spec_parser", 82}, // at index 25
 {"<select_spec_5F_parser_5>", "spec_parser", 84}, // at index 26
 {"<select_spec_5F_parser_5>", "spec_parser", 87}, // at index 27
 {"<select_spec_5F_parser_6>", "spec_parser", 89}, // at index 28
 {"<select_spec_5F_parser_6>", "spec_parser", 90}, // at index 29
 {"<select_spec_5F_parser_7>", "spec_parser", 95}, // at index 30
 {"<select_spec_5F_parser_7>", "spec_parser", 97}, // at index 31
 {"<select_spec_5F_parser_7>", "spec_parser", 99}, // at index 32
 {"<select_spec_5F_parser_7>", "spec_parser", 102}, // at index 33
 {"<select_spec_5F_parser_7>", "spec_parser", 105}, // at index 34
 {"<select_spec_5F_parser_8>", "spec_parser", 108}, // at index 35
 {"<select_spec_5F_parser_8>", "spec_parser", 110}, // at index 36
 {"<select_spec_5F_parser_9>", "spec_parser", 112}, // at index 37
 {"<select_spec_5F_parser_9>", "spec_parser", 116}, // at index 38
 {"<select_spec_5F_parser_10>", "spec_parser", 117}, // at index 39
 {"<select_spec_5F_parser_10>", "spec_parser", 121}, // at index 40
 {"<select_spec_5F_parser_11>", "spec_parser", 122}, // at index 41
 {"<select_spec_5F_parser_11>", "spec_parser", 123}, // at index 42
 {"<select_spec_5F_parser_11>", "spec_parser", 130}, // at index 43
 {"<select_spec_5F_parser_11>", "spec_parser", 136}, // at index 44
 {"<select_spec_5F_parser_12>", "spec_parser", 145}, // at index 45
 {"<select_spec_5F_parser_12>", "spec_parser", 146}, // at index 46
 {"<select_spec_5F_parser_13>", "spec_parser", 150}, // at index 47
 {"<select_spec_5F_parser_13>", "spec_parser", 151}, // at index 48
 {"<select_spec_5F_parser_14>", "spec_parser", 157}, // at index 49
 {"<select_spec_5F_parser_14>", "spec_parser", 159}, // at index 50
 {"<select_spec_5F_parser_15>", "spec_parser", 161}, // at index 51
 {"<select_spec_5F_parser_15>", "spec_parser", 162}, // at index 52
 {"<>", "", 169} // at index 53
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_spec_grammar [54] = {
0, // index 0 : <axiome>, in file 'spec_parser.ggs', line 263
13, // index 1 : <parse_precondition>, in file 'spec_parser.ggs', line 53
16, // index 2 : <term>, in file 'spec_parser.ggs', line 69
19, // index 3 : <factor>, in file 'spec_parser.ggs', line 85
21, // index 4 : <primary>, in file 'spec_parser.ggs', line 100
23, // index 5 : <parse_postcondition>, in file 'spec_parser.ggs', line 177
27, // index 6 : <parse_constant>, in file 'spec_parser.ggs', line 157
29, // index 7 : <parse_bound>, in file 'spec_parser.ggs', line 223
30, // index 8 : <parse_bound>, in file 'spec_parser.ggs', line 232
36, // index 9 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
37, // index 10 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
41, // index 11 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 74
42, // index 12 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 74
46, // index 13 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 89
49, // index 14 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 89
51, // index 15 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
55, // index 16 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
57, // index 17 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
59, // index 18 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 104
64, // index 19 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
67, // index 20 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
70, // index 21 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
73, // index 22 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
76, // index 23 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
79, // index 24 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 120
82, // index 25 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
84, // index 26 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
87, // index 27 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 161
89, // index 28 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 182
90, // index 29 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 182
95, // index 30 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
97, // index 31 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
99, // index 32 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
102, // index 33 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
105, // index 34 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 188
108, // index 35 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 206
110, // index 36 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 206
112, // index 37 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 272
116, // index 38 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 272
117, // index 39 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 281
121, // index 40 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 281
122, // index 41 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
123, // index 42 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
130, // index 43 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
136, // index 44 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 294
145, // index 45 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 309
146, // index 46 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 309
150, // index 47 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 336
151, // index 48 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 336
157, // index 49 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 342
159, // index 50 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 342
161, // index 51 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 358
162, // index 52 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 358
169 // index 53 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_spec_grammar [26] = {
0, // at 0 : <axiome>
1, // at 1 : <parse_precondition>
2, // at 2 : <term>
3, // at 3 : <factor>
4, // at 4 : <primary>
5, // at 5 : <parse_postcondition>
6, // at 6 : <parse_constant>
7, // at 7 : <parse_bound>
9, // at 8 : <select_spec_5F_parser_0>
11, // at 9 : <select_spec_5F_parser_1>
13, // at 10 : <select_spec_5F_parser_2>
15, // at 11 : <select_spec_5F_parser_3>
19, // at 12 : <select_spec_5F_parser_4>
25, // at 13 : <select_spec_5F_parser_5>
28, // at 14 : <select_spec_5F_parser_6>
30, // at 15 : <select_spec_5F_parser_7>
35, // at 16 : <select_spec_5F_parser_8>
37, // at 17 : <select_spec_5F_parser_9>
39, // at 18 : <select_spec_5F_parser_10>
41, // at 19 : <select_spec_5F_parser_11>
45, // at 20 : <select_spec_5F_parser_12>
47, // at 21 : <select_spec_5F_parser_13>
49, // at 22 : <select_spec_5F_parser_14>
51, // at 23 : <select_spec_5F_parser_15>
53, // at 24 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_spec_grammar [] = {
// At index 0 : <axiome> only one production, no choice
  -1,
// At index 1 : <parse_precondition> only one production, no choice
  -1,
// At index 2 : <term> only one production, no choice
  -1,
// At index 3 : <factor> only one production, no choice
  -1,
// At index 4 : <primary> only one production, no choice
  -1,
// At index 5 : <parse_postcondition> only one production, no choice
  -1,
// At index 6 : <parse_constant> only one production, no choice
  -1,
// At index 7 : <parse_bound>
C_Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 12 : <select_spec_5F_parser_0>
C_Lexique_spec_5F_scanner::kToken__29_, C_Lexique_spec_5F_scanner::kToken__5B_, C_Lexique_spec_5F_scanner::kToken__3B_, C_Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__7C_, -1, // Choice 2
  -1,
// At index 20 : <select_spec_5F_parser_1>
C_Lexique_spec_5F_scanner::kToken__7C_, C_Lexique_spec_5F_scanner::kToken__29_, C_Lexique_spec_5F_scanner::kToken__5B_, C_Lexique_spec_5F_scanner::kToken__3B_, C_Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 29 : <select_spec_5F_parser_2>
C_Lexique_spec_5F_scanner::kToken__7E_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__28_, C_Lexique_spec_5F_scanner::kToken_true, C_Lexique_spec_5F_scanner::kToken_false, C_Lexique_spec_5F_scanner::kToken__7B_, -1, // Choice 2
  -1,
// At index 37 : <select_spec_5F_parser_3>
C_Lexique_spec_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_true, -1, // Choice 2
C_Lexique_spec_5F_scanner::kToken_false, -1, // Choice 3
C_Lexique_spec_5F_scanner::kToken__7B_, -1, // Choice 4
  -1,
// At index 46 : <select_spec_5F_parser_4>
C_Lexique_spec_5F_scanner::kToken__3D__3D_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__21__3D_, -1, // Choice 2
C_Lexique_spec_5F_scanner::kToken__3C__3D_, -1, // Choice 3
C_Lexique_spec_5F_scanner::kToken__3E__3D_, -1, // Choice 4
C_Lexique_spec_5F_scanner::kToken__3C_, -1, // Choice 5
C_Lexique_spec_5F_scanner::kToken__3E_, -1, // Choice 6
  -1,
// At index 59 : <select_spec_5F_parser_5>
C_Lexique_spec_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__2D_, -1, // Choice 2
C_Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 3
  -1,
// At index 66 : <select_spec_5F_parser_6>
C_Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 71 : <select_spec_5F_parser_7>
C_Lexique_spec_5F_scanner::kToken__2D__2D_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__2B__2B_, -1, // Choice 2
C_Lexique_spec_5F_scanner::kToken__2B__3D_, -1, // Choice 3
C_Lexique_spec_5F_scanner::kToken__2D__3D_, -1, // Choice 4
C_Lexique_spec_5F_scanner::kToken__3A__3D_, -1, // Choice 5
  -1,
// At index 82 : <select_spec_5F_parser_8>
C_Lexique_spec_5F_scanner::kToken_identifier, C_Lexique_spec_5F_scanner::kToken__2D_, C_Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_infinity, -1, // Choice 2
  -1,
// At index 89 : <select_spec_5F_parser_9>
C_Lexique_spec_5F_scanner::kToken_hashmapsize, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_garbageperiod, C_Lexique_spec_5F_scanner::kToken_const, C_Lexique_spec_5F_scanner::kToken_var, C_Lexique_spec_5F_scanner::kToken_rule, C_Lexique_spec_5F_scanner::kToken_init, -1, // Choice 2
  -1,
// At index 98 : <select_spec_5F_parser_10>
C_Lexique_spec_5F_scanner::kToken_garbageperiod, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_const, C_Lexique_spec_5F_scanner::kToken_var, C_Lexique_spec_5F_scanner::kToken_rule, C_Lexique_spec_5F_scanner::kToken_init, -1, // Choice 2
  -1,
// At index 106 : <select_spec_5F_parser_11>
C_Lexique_spec_5F_scanner::kToken_init, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_const, -1, // Choice 2
C_Lexique_spec_5F_scanner::kToken_var, -1, // Choice 3
C_Lexique_spec_5F_scanner::kToken_rule, -1, // Choice 4
  -1,
// At index 115 : <select_spec_5F_parser_12>
C_Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 120 : <select_spec_5F_parser_13>
C_Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 125 : <select_spec_5F_parser_14>
C_Lexique_spec_5F_scanner::kToken_identifier, C_Lexique_spec_5F_scanner::kToken__2D_, C_Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_infinity, -1, // Choice 2
  -1,
// At index 132 : <select_spec_5F_parser_15>
C_Lexique_spec_5F_scanner::kToken_end, -1, // Choice 1
C_Lexique_spec_5F_scanner::kToken_count, -1, // Choice 2
  -1,
// At index 137 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_spec_grammar [26] = {
0, // at 0 : <axiome>
1, // at 1 : <parse_precondition>
2, // at 2 : <term>
3, // at 3 : <factor>
4, // at 4 : <primary>
5, // at 5 : <parse_postcondition>
6, // at 6 : <parse_constant>
7, // at 7 : <parse_bound>
12, // at 8 : <select_spec_5F_parser_0>
20, // at 9 : <select_spec_5F_parser_1>
29, // at 10 : <select_spec_5F_parser_2>
37, // at 11 : <select_spec_5F_parser_3>
46, // at 12 : <select_spec_5F_parser_4>
59, // at 13 : <select_spec_5F_parser_5>
66, // at 14 : <select_spec_5F_parser_6>
71, // at 15 : <select_spec_5F_parser_7>
82, // at 16 : <select_spec_5F_parser_8>
89, // at 17 : <select_spec_5F_parser_9>
98, // at 18 : <select_spec_5F_parser_10>
106, // at 19 : <select_spec_5F_parser_11>
115, // at 20 : <select_spec_5F_parser_12>
120, // at 21 : <select_spec_5F_parser_13>
125, // at 22 : <select_spec_5F_parser_14>
132, // at 23 : <select_spec_5F_parser_15>
137, // at 24 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'axiome' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_axiome_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_axiome_i8_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_axiome_ (GALGAS_uint & parameter_1,
                                GALGAS_uint & parameter_2,
                                GALGAS_typeVarMap & parameter_3,
                                GALGAS_typeTransitionList & parameter_4,
                                GALGAS_typeInitialMarkingList & parameter_5,
                                GALGAS_countList & parameter_6,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_axiome_i8_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

void cGrammar_spec_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_spec_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_spec_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_spec_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_spec_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_spec_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_spec_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                    gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_uint &  parameter_1,
                                GALGAS_uint &  parameter_2,
                                GALGAS_typeVarMap &  parameter_3,
                                GALGAS_typeTransitionList &  parameter_4,
                                GALGAS_typeInitialMarkingList &  parameter_5,
                                GALGAS_countList &  parameter_6
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_spec_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_spec_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                                      gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_spec_5F_grammar grammar ;
        grammar.nt_axiome_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_uint &  parameter_1,
                                GALGAS_uint &  parameter_2,
                                GALGAS_typeVarMap &  parameter_3,
                                GALGAS_typeTransitionList &  parameter_4,
                                GALGAS_typeInitialMarkingList &  parameter_5,
                                GALGAS_countList &  parameter_6
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_spec_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_spec_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                                    gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_spec_5F_grammar grammar ;
      grammar.nt_axiome_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'parse_precondition' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_precondition_i0_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_precondition_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'term' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_term_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_term_i1_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_term_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_term_i1_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'factor' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_factor_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_factor_i2_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_factor_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_factor_i2_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'primary' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_primary_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_primary_i3_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_primary_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_primary_i3_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'parse_postcondition' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_postcondition_i5_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePostconditionList & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_postcondition_i5_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'parse_constant' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_parse (C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_constant_i4_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_ (GALGAS_typeCstMap & parameter_1,
                                GALGAS_bool & parameter_2,
                                GALGAS_luint & parameter_3,
                                C_Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_constant_i4_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'parse_bound' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_parse (C_Lexique_spec_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_spec_5F_parser_parse_5F_bound_i6_parse(inLexique) ;
    break ;
  case 2 :
    rule_spec_5F_parser_parse_5F_bound_i7_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_ (GALGAS_uint & parameter_1,
                                GALGAS_uint & parameter_2,
                                C_Lexique_spec_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_spec_5F_parser_parse_5F_bound_i6_(parameter_1, parameter_2, inLexique) ;
    break ;
  case 2 :
    rule_spec_5F_parser_parse_5F_bound_i7_(parameter_1, parameter_2, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_0 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_1 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_2 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_3 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_4 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_5 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_6 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_7 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_8 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_9 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_10 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_11 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_12 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_13 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_14 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_spec_5F_parser_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_15 (C_Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::GALGAS_typeVarMap_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::~ GALGAS_typeVarMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::GALGAS_typeVarMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_uint & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeVarMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_uint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_uint & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeVarMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_typeVarMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typeVarMap_2D_element::objectCompare (const GALGAS_typeVarMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeVarMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @typeVarMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeVarMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeVarMap_2D_element::getter_mIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_mIndex ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@typeVarMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeVarMap_2D_element ("typeVarMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeVarMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeVarMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeVarMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap_2D_element result ;
  const GALGAS_typeVarMap_2D_element * p = (const GALGAS_typeVarMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeVarMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::GALGAS_typeCstMap_2D_element (void) :
mProperty_lkey (),
mProperty_mSign (),
mProperty_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::~ GALGAS_typeCstMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::GALGAS_typeCstMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_bool & inOperand1,
                                                            const GALGAS_luint & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_mSign (inOperand1),
mProperty_mValue (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeCstMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_bool::constructor_default (HERE),
                                       GALGAS_luint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_bool & inOperand1,
                                                                            const GALGAS_luint & inOperand2 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeCstMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_typeCstMap_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typeCstMap_2D_element::objectCompare (const GALGAS_typeCstMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mSign.objectCompare (inOperand.mProperty_mSign) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeCstMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mSign.isValid () && mProperty_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mSign.drop () ;
  mProperty_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @typeCstMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mSign.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeCstMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeCstMap_2D_element::getter_mSign (UNUSED_LOCATION_ARGS) const {
  return mProperty_mSign ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeCstMap_2D_element::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_mValue ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@typeCstMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeCstMap_2D_element ("typeCstMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeCstMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeCstMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeCstMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap_2D_element result ;
  const GALGAS_typeCstMap_2D_element * p = (const GALGAS_typeCstMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeCstMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element::GALGAS_typeTransitionList_2D_element (void) :
mProperty_mTransitionName (),
mProperty_mPreconditionExpression (),
mProperty_mPostconditionList (),
mProperty_mLowTemporalBound (),
mProperty_mHighTemporalBound () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element::~ GALGAS_typeTransitionList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element::GALGAS_typeTransitionList_2D_element (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_typePreconditionExpression & inOperand1,
                                                                            const GALGAS_typePostconditionList & inOperand2,
                                                                            const GALGAS_uint & inOperand3,
                                                                            const GALGAS_uint & inOperand4) :
mProperty_mTransitionName (inOperand0),
mProperty_mPreconditionExpression (inOperand1),
mProperty_mPostconditionList (inOperand2),
mProperty_mLowTemporalBound (inOperand3),
mProperty_mHighTemporalBound (inOperand4) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element GALGAS_typeTransitionList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                            const GALGAS_typePreconditionExpression & inOperand1,
                                                                                            const GALGAS_typePostconditionList & inOperand2,
                                                                                            const GALGAS_uint & inOperand3,
                                                                                            const GALGAS_uint & inOperand4 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeTransitionList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
    result = GALGAS_typeTransitionList_2D_element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_typeTransitionList_2D_element::objectCompare (const GALGAS_typeTransitionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mTransitionName.objectCompare (inOperand.mProperty_mTransitionName) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPreconditionExpression.objectCompare (inOperand.mProperty_mPreconditionExpression) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mPostconditionList.objectCompare (inOperand.mProperty_mPostconditionList) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mLowTemporalBound.objectCompare (inOperand.mProperty_mLowTemporalBound) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mHighTemporalBound.objectCompare (inOperand.mProperty_mHighTemporalBound) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_typeTransitionList_2D_element::isValid (void) const {
  return mProperty_mTransitionName.isValid () && mProperty_mPreconditionExpression.isValid () && mProperty_mPostconditionList.isValid () && mProperty_mLowTemporalBound.isValid () && mProperty_mHighTemporalBound.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList_2D_element::drop (void) {
  mProperty_mTransitionName.drop () ;
  mProperty_mPreconditionExpression.drop () ;
  mProperty_mPostconditionList.drop () ;
  mProperty_mLowTemporalBound.drop () ;
  mProperty_mHighTemporalBound.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @typeTransitionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mTransitionName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPreconditionExpression.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mPostconditionList.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mLowTemporalBound.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mHighTemporalBound.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeTransitionList_2D_element::getter_mTransitionName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mTransitionName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeTransitionList_2D_element::getter_mPreconditionExpression (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPreconditionExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typeTransitionList_2D_element::getter_mPostconditionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_mPostconditionList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList_2D_element::getter_mLowTemporalBound (UNUSED_LOCATION_ARGS) const {
  return mProperty_mLowTemporalBound ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList_2D_element::getter_mHighTemporalBound (UNUSED_LOCATION_ARGS) const {
  return mProperty_mHighTemporalBound ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@typeTransitionList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typeTransitionList_2D_element ("typeTransitionList-element",
                                                      NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTransitionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTransitionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTransitionList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element GALGAS_typeTransitionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeTransitionList_2D_element result ;
  const GALGAS_typeTransitionList_2D_element * p = (const GALGAS_typeTransitionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typeTransitionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::GALGAS_countList_2D_element (void) :
mProperty_mName (),
mProperty_mCondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::~ GALGAS_countList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::GALGAS_countList_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_typePreconditionExpression & inOperand1) :
mProperty_mName (inOperand0),
mProperty_mCondition (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element GALGAS_countList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_typePreconditionExpression & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_countList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_countList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_countList_2D_element::objectCompare (const GALGAS_countList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_mName.objectCompare (inOperand.mProperty_mName) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mCondition.objectCompare (inOperand.mProperty_mCondition) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_countList_2D_element::isValid (void) const {
  return mProperty_mName.isValid () && mProperty_mCondition.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList_2D_element::drop (void) {
  mProperty_mName.drop () ;
  mProperty_mCondition.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_countList_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @countList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_mName.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mCondition.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_countList_2D_element::getter_mName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_countList_2D_element::getter_mCondition (UNUSED_LOCATION_ARGS) const {
  return mProperty_mCondition ;
}



//----------------------------------------------------------------------------------------------------------------------
//
//@countList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_countList_2D_element ("countList-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_countList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_countList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_countList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element GALGAS_countList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_countList_2D_element result ;
  const GALGAS_countList_2D_element * p = (const GALGAS_countList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_countList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_typePostIncrement::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_typePostIncrement * p = (const cPtr_typePostIncrement *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typePostIncrement) ;
  if (kOperandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_typePostIncrement::objectCompare (const GALGAS_typePostIncrement & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement::GALGAS_typePostIncrement (void) :
GALGAS_typePostcondition () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::constructor_default (LOCATION_ARGS) {
  return GALGAS_typePostIncrement::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_uint::constructor_default (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement::GALGAS_typePostIncrement (const cPtr_typePostIncrement * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostIncrement) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::constructor_new (const GALGAS_lstring & inAttribute_mVarName,
                                                                    const GALGAS_uint & inAttribute_mVar
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typePostIncrement result ;
  if (inAttribute_mVarName.isValid () && inAttribute_mVar.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_typePostIncrement (inAttribute_mVarName, inAttribute_mVar COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typePostIncrement::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_typePostIncrement * p = (const cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    result = p->mProperty_mVarName ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_typePostIncrement::getter_mVarName (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVarName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typePostIncrement::getter_mVar (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_typePostIncrement * p = (const cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    result = p->mProperty_mVar ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_typePostIncrement::getter_mVar (UNUSED_LOCATION_ARGS) const {
  return mProperty_mVar ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostIncrement::setter_setMVarName (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typePostIncrement::setter_setMVarName (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVarName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_typePostIncrement::setter_setMVar (GALGAS_uint inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_typePostIncrement::setter_setMVar (GALGAS_uint inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_mVar = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @typePostIncrement class
//----------------------------------------------------------------------------------------------------------------------

cPtr_typePostIncrement::cPtr_typePostIncrement (const GALGAS_lstring & in_mVarName,
                                                const GALGAS_uint & in_mVar
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (in_mVarName),
mProperty_mVar (in_mVar) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typePostIncrement::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement ;
}

void cPtr_typePostIncrement::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@typePostIncrement:" ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typePostIncrement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_typePostIncrement (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@typePostIncrement type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_typePostIncrement ("typePostIncrement",
                                          & kTypeDescriptor_GALGAS_typePostcondition) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostIncrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostIncrement::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostIncrement (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostIncrement result ;
  const GALGAS_typePostIncrement * p = (const GALGAS_typePostIncrement *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_typePostIncrement *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostIncrement", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

C_BoolCommandLineOption gOption_spec_5F_options_computeSimultaneousFiring ("spec_options",
                                         "computeSimultaneousFiring",
                                         0,
                                         "simultaneous-firing",
                                         "perform simultaneous firing") ;

C_BoolCommandLineOption gOption_spec_5F_options_doNotPrintIteration ("spec_options",
                                         "doNotPrintIteration",
                                         68,
                                         "do-not-print-iterations-message",
                                         "do not print a message for every iteration") ;

C_BoolCommandLineOption gOption_spec_5F_options_printFiring ("spec_options",
                                         "printFiring",
                                         102,
                                         "print-transitions-firing-count",
                                         "print transitions firing count") ;

C_BoolCommandLineOption gOption_spec_5F_options_printInference ("spec_options",
                                         "printInference",
                                         0,
                                         "print-inference",
                                         "print inference expression for each transition") ;

C_BoolCommandLineOption gOption_spec_5F_options_printIterationStates ("spec_options",
                                         "printIterationStates",
                                         105,
                                         "print-iterations-states",
                                         "print source and target states for each transition of every iteration") ;

C_BoolCommandLineOption gOption_spec_5F_options_printMinMax ("spec_options",
                                         "printMinMax",
                                         112,
                                         "print-min-maxs",
                                         "print min and max value for each variable") ;

C_BoolCommandLineOption gOption_spec_5F_options_printNodes ("spec_options",
                                         "printNodes",
                                         78,
                                         "print-nodes",
                                         "print accessibility set nodes") ;

C_BoolCommandLineOption gOption_spec_5F_options_printPreConditions ("spec_options",
                                         "printPreConditions",
                                         80,
                                         "print-preconditions",
                                         "print precondition expression for each transition") ;

C_BoolCommandLineOption gOption_spec_5F_options_printStates ("spec_options",
                                         "printStates",
                                         83,
                                         "print-states",
                                         "print accessibility states") ;

C_BoolCommandLineOption gOption_spec_5F_options_printTemporalBounds ("spec_options",
                                         "printTemporalBounds",
                                         116,
                                         "print-temporal-bounds",
                                         "print temporal bounds for each transition") ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

C_UIntCommandLineOption gOption_spec_5F_options_stopAfterIteration ("spec_options",
                                         "stopAfterIteration",
                                         115,
                                         "stop-after-iteration",
                                         "stop after performing given iterations (0 means never stop)",
                                         0) ;

//----------------------------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//----------------------------------------------------------------------------------------------------------------------
//
//                      print_tool_help_message                                                  
//
//----------------------------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "mg",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.mg' source file",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "0.0.1" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_hashMapSize_513 ;
  GALGAS_uint var_garbagePeriod_535 ;
  GALGAS_typeVarMap var_placesMap_559 ;
  GALGAS_typeTransitionList var_transitionList_596 ;
  GALGAS_typeInitialMarkingList var_initialMarkingList_641 ;
  GALGAS_countList var_countList_664 ;
  var_hashMapSize_513.drop () ;
  var_garbagePeriod_535.drop () ;
  var_placesMap_559.drop () ;
  var_transitionList_596.drop () ;
  var_initialMarkingList_641.drop () ;
  var_countList_664.drop () ;
  cGrammar_spec_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_hashMapSize_513, var_garbagePeriod_535, var_placesMap_559, var_transitionList_596, var_initialMarkingList_641, var_countList_664  COMMA_SOURCE_FILE ("spec_main.galgas", 17)) ;
  {
  routine_generate_5F_code (var_hashMapSize_513, var_garbagePeriod_535, var_placesMap_559, var_transitionList_596, var_initialMarkingList_641, var_countList_664, inCompiler  COMMA_SOURCE_FILE ("spec_main.galgas", 24)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//----------------------------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonCompiler = NULL ;
    macroMyNew (commonCompiler, C_Compiler (NULL COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonCompiler->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "mg") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            cGrammar_spec_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            cGrammar_spec_5F_grammar::performOnlySyntaxAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeIndexing :
            cGrammar_spec_5F_grammar::performIndexing (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          case kExecutionModeLatex :
            cGrammar_spec_5F_grammar::performOnlyLexicalAnalysis (commonCompiler, sourceFilesArray (i COMMA_HERE)) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}

