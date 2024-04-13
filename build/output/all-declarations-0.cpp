#include "Compiler.h"
#include "galgas-input-output.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-0.h"

//--------------------------------------------------------------------------------------------------
//
//Class for element of '@_32_lstringlist' list
//
//--------------------------------------------------------------------------------------------------

class cCollectionElement__32_lstringlist : public cCollectionElement {
  public: GALGAS__32_lstringlist_2D_element mObject ;

//--- Class functions
  public: cCollectionElement__32_lstringlist (const GALGAS_lstring & in_mValue_30_,
                                              const GALGAS_lstring & in_mValue_31_
                                              COMMA_LOCATION_ARGS) ;
  public: cCollectionElement__32_lstringlist (const GALGAS__32_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual ComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GALGAS_lstring & in_mValue_30_,
                                                                        const GALGAS_lstring & in_mValue_31_
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue_30_, in_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GALGAS__32_lstringlist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mValue_30_, inElement.mProperty_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement__32_lstringlist::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement__32_lstringlist::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement__32_lstringlist (mObject.mProperty_mValue_30_, mObject.mProperty_mValue_31_ COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement__32_lstringlist::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mValue0" ":") ;
  mObject.mProperty_mValue_30_.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mValue1" ":") ;
  mObject.mProperty_mValue_31_.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cCollectionElement__32_lstringlist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement__32_lstringlist * operand = (cCollectionElement__32_lstringlist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement__32_lstringlist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist::GALGAS__32_lstringlist (void) :
AC_GALGAS_list () {
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist::GALGAS__32_lstringlist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS__32_lstringlist (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS__32_lstringlist (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::enterElement (const GALGAS__32_lstringlist_2D_element & inValue,
                                           Compiler * /* inCompiler */
                                           COMMA_LOCATION_ARGS) {
  cCollectionElement * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_lstringlist (inValue COMMA_THERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  appendObject (attributes) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::class_func_listWithValue (const GALGAS_lstring & inOperand0,
                                                                         const GALGAS_lstring & inOperand1
                                                                         COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS__32_lstringlist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS__32_lstringlist::makeAttributesFromObjects (attributes, inOperand0, inOperand1 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GALGAS_lstring & in_mValue_30_,
                                                        const GALGAS_lstring & in_mValue_31_
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_lstringlist (in_mValue_30_,
                                                     in_mValue_31_ COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                  const GALGAS_lstring & inOperand1
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_append (const GALGAS_lstring inOperand0,
                                            const GALGAS_lstring inOperand1,
                                            Compiler * /* inCompiler */
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                   const GALGAS_lstring inOperand1,
                                                   const GALGAS_uint inInsertionIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
      macroMyNew (p, cCollectionElement__32_lstringlist (inOperand0, inOperand1 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                   GALGAS_lstring & outOperand1,
                                                   const GALGAS_uint inRemoveIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
      if (nullptr == p) {
        outOperand0.drop () ;
        outOperand1.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
        outOperand0 = p->mObject.mProperty_mValue_30_ ;
        outOperand1 = p->mObject.mProperty_mValue_31_ ;
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

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_popFirst (GALGAS_lstring & outOperand0,
                                              GALGAS_lstring & outOperand1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_popLast (GALGAS_lstring & outOperand0,
                                             GALGAS_lstring & outOperand1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::method_first (GALGAS_lstring & outOperand0,
                                           GALGAS_lstring & outOperand1,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::method_last (GALGAS_lstring & outOperand0,
                                          GALGAS_lstring & outOperand1,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    outOperand0 = p->mObject.mProperty_mValue_30_ ;
    outOperand1 = p->mObject.mProperty_mValue_31_ ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::add_operation (const GALGAS__32_lstringlist & inOperand,
                                                              Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::class_func_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::class_func_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS__32_lstringlist result = GALGAS__32_lstringlist::class_func_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::plusAssign_operation (const GALGAS__32_lstringlist inOperand,
                                                   Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_setMValue_30_AtIndex (GALGAS_lstring inOperand,
                                                          GALGAS_uint inIndex,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_30_ = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS__32_lstringlist::getter_mValue_30_AtIndex (const GALGAS_uint & inIndex,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    result = p->mObject.mProperty_mValue_30_ ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist::setter_setMValue_31_AtIndex (GALGAS_lstring inOperand,
                                                          GALGAS_uint inIndex,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mValue_31_ = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS__32_lstringlist::getter_mValue_31_AtIndex (const GALGAS_uint & inIndex,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    result = p->mObject.mProperty_mValue_31_ ;
  }
  return result ;
}



//--------------------------------------------------------------------------------------------------

cEnumerator__32_lstringlist::cEnumerator__32_lstringlist (const GALGAS__32_lstringlist & inEnumeratedObject,
                                                          const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element cEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject.mProperty_mValue_30_ ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  const cCollectionElement__32_lstringlist * p = (const cCollectionElement__32_lstringlist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
  return p->mObject.mProperty_mValue_31_ ;
}




//--------------------------------------------------------------------------------------------------
//
//     @2lstringlist generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist ("2lstringlist",
                                                                       nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_lstringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_lstringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_lstringlist (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist GALGAS__32_lstringlist::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist result ;
  const GALGAS__32_lstringlist * p = (const GALGAS__32_lstringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_lstringlist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//--------------------------------------------------------------------------------------------------

#include "unicode_character_cpp.h"
#include "scanner_actions.h"
#include "cLexiqueIntrospection.h"

//--------------------------------------------------------------------------------------------------

cTokenFor_spec_5F_scanner::cTokenFor_spec_5F_scanner (void) :
mLexicalAttribute_theString (),
mLexicalAttribute_ulongValue () {
}

//--------------------------------------------------------------------------------------------------

Lexique_spec_5F_scanner::Lexique_spec_5F_scanner (Compiler * inCallerCompiler,
                                                  const String & inSourceFileName
                                                  COMMA_LOCATION_ARGS) :
Lexique (inCallerCompiler, inSourceFileName COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

Lexique_spec_5F_scanner::Lexique_spec_5F_scanner (Compiler * inCallerCompiler,
                                                  const String & inSourceString,
                                                  const String & inStringForError
                                                  COMMA_LOCATION_ARGS) :
Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//--------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_spec_5F_scanner_incorrectStringEnd = "string does not end with '\"'" ;

static const char * gLexicalMessage_spec_5F_scanner_internalError = "internal error" ;

//--------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//--------------------------------------------------------------------------------------------------

String Lexique_spec_5F_scanner::getMessageForTerminal (const int32_t inTerminalIndex) const {
  String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 41)) {
    static const char * syntaxErrorMessageArray [41] = {kEndOfSourceLexicalErrorMessage,
        "an identifier",
        "a character string constant \"...\"",
        "a decimal number",
        "the 'system' key word",
        "the 'var' key word",
        "the 'rule' key word",
        "the 'init' key word",
        "the 'end' key word",
        "the 'true' key word",
        "the 'false' key word",
        "the 'const' key word",
        "the 'count' key word",
        "the 'infinity' key word",
        "the 'hashmapsize' key word",
        "the 'garbageperiod' key word",
        "the '>=' delimitor",
        "the '>' delimitor",
        "the '<' delimitor",
        "the '<=' delimitor",
        "the '==' delimitor",
        "the '!=' delimitor",
        "the '&' delimitor",
        "the '|' delimitor",
        "the '~' delimitor",
        "the ',' delimitor",
        "the ';' delimitor",
        "the '(' delimitor",
        "the ')' delimitor",
        "the '++' delimitor",
        "the '--' delimitor",
        "the '+=' delimitor",
        "the '-=' delimitor",
        "the ':=' delimitor",
        "the '{' delimitor",
        "the '}' delimitor",
        "the ':' delimitor",
        "the '-' delimitor",
        "the '=' delimitor",
        "the '[' delimitor",
        "the ']' delimitor"
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//--------------------------------------------------------------------------------------------------

//--- Unicode string for '$!=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__21__3D_ = {
  TO_UNICODE ('!'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$&$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__26_ = {
  TO_UNICODE ('&'),
} ;

//--- Unicode string for '$($'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__28_ = {
  TO_UNICODE ('('),
} ;

//--- Unicode string for '$)$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__29_ = {
  TO_UNICODE (')'),
} ;

//--- Unicode string for '$++$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2B__2B_ = {
  TO_UNICODE ('+'),
  TO_UNICODE ('+'),
} ;

//--- Unicode string for '$+=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2B__3D_ = {
  TO_UNICODE ('+'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$,$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2C_ = {
  TO_UNICODE (','),
} ;

//--- Unicode string for '$-$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2D_ = {
  TO_UNICODE ('-'),
} ;

//--- Unicode string for '$--$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2D__2D_ = {
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
} ;

//--- Unicode string for '$-=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__2D__3D_ = {
  TO_UNICODE ('-'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$:$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3A_ = {
  TO_UNICODE (':'),
} ;

//--- Unicode string for '$:=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3A__3D_ = {
  TO_UNICODE (':'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$;$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3B_ = {
  TO_UNICODE (';'),
} ;

//--- Unicode string for '$<$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3C_ = {
  TO_UNICODE ('<'),
} ;

//--- Unicode string for '$<=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3C__3D_ = {
  TO_UNICODE ('<'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3D_ = {
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$==$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3D__3D_ = {
  TO_UNICODE ('='),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$>$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3E_ = {
  TO_UNICODE ('>'),
} ;

//--- Unicode string for '$>=$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__3E__3D_ = {
  TO_UNICODE ('>'),
  TO_UNICODE ('='),
} ;

//--- Unicode string for '$[$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__5B_ = {
  TO_UNICODE ('['),
} ;

//--- Unicode string for '$]$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__5D_ = {
  TO_UNICODE (']'),
} ;

//--- Unicode string for '$const$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_const = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
} ;

//--- Unicode string for '$count$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_count = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
} ;

//--- Unicode string for '$end$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_end = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
} ;

//--- Unicode string for '$false$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_false = {
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
} ;

//--- Unicode string for '$garbageperiod$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_garbageperiod = {
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
} ;

//--- Unicode string for '$hashmapsize$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_hashmapsize = {
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
} ;

//--- Unicode string for '$infinity$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_infinity = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
} ;

//--- Unicode string for '$init$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_init = {
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
} ;

//--- Unicode string for '$rule$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_rule = {
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
} ;

//--- Unicode string for '$system$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_system = {
  TO_UNICODE ('s'),
  TO_UNICODE ('y'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
} ;

//--- Unicode string for '$true$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_true = {
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
} ;

//--- Unicode string for '$var$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner_var = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
} ;

//--- Unicode string for '${$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__7B_ = {
  TO_UNICODE ('{'),
} ;

//--- Unicode string for '$|$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__7C_ = {
  TO_UNICODE ('|'),
} ;

//--- Unicode string for '$}$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__7D_ = {
  TO_UNICODE ('}'),
} ;

//--- Unicode string for '$~$'
static const std::initializer_list <utf32> kUnicodeString_spec_5F_scanner__7E_ = {
  TO_UNICODE ('~'),
} ;

//--------------------------------------------------------------------------------------------------
//             Key words table 'delimitorsList'      
//--------------------------------------------------------------------------------------------------

static const int32_t ktable_size_spec_5F_scanner_delimitorsList = 25 ;

static const C_unicode_lexique_table_entry ktable_for_spec_5F_scanner_delimitorsList [ktable_size_spec_5F_scanner_delimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__26_, Lexique_spec_5F_scanner::kToken__26_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__28_, Lexique_spec_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__29_, Lexique_spec_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2C_, Lexique_spec_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D_, Lexique_spec_5F_scanner::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3A_, Lexique_spec_5F_scanner::kToken__3A_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3B_, Lexique_spec_5F_scanner::kToken__3B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3C_, Lexique_spec_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3D_, Lexique_spec_5F_scanner::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3E_, Lexique_spec_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__5B_, Lexique_spec_5F_scanner::kToken__5B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__5D_, Lexique_spec_5F_scanner::kToken__5D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7B_, Lexique_spec_5F_scanner::kToken__7B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7C_, Lexique_spec_5F_scanner::kToken__7C_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7D_, Lexique_spec_5F_scanner::kToken__7D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__7E_, Lexique_spec_5F_scanner::kToken__7E_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__21__3D_, Lexique_spec_5F_scanner::kToken__21__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2B__2B_, Lexique_spec_5F_scanner::kToken__2B__2B_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2B__3D_, Lexique_spec_5F_scanner::kToken__2B__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D__2D_, Lexique_spec_5F_scanner::kToken__2D__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__2D__3D_, Lexique_spec_5F_scanner::kToken__2D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3A__3D_, Lexique_spec_5F_scanner::kToken__3A__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3C__3D_, Lexique_spec_5F_scanner::kToken__3C__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3D__3D_, Lexique_spec_5F_scanner::kToken__3D__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner__3E__3D_, Lexique_spec_5F_scanner::kToken__3E__3D_)
} ;

int32_t Lexique_spec_5F_scanner::search_into_delimitorsList (const String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_spec_5F_scanner_delimitorsList, ktable_size_spec_5F_scanner_delimitorsList) ;
}

//--------------------------------------------------------------------------------------------------
//             Key words table 'galgasKeyWordList'      
//--------------------------------------------------------------------------------------------------

static const int32_t ktable_size_spec_5F_scanner_galgasKeyWordList = 12 ;

static const C_unicode_lexique_table_entry ktable_for_spec_5F_scanner_galgasKeyWordList [ktable_size_spec_5F_scanner_galgasKeyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_end, Lexique_spec_5F_scanner::kToken_end),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_var, Lexique_spec_5F_scanner::kToken_var),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_init, Lexique_spec_5F_scanner::kToken_init),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_rule, Lexique_spec_5F_scanner::kToken_rule),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_true, Lexique_spec_5F_scanner::kToken_true),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_const, Lexique_spec_5F_scanner::kToken_const),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_count, Lexique_spec_5F_scanner::kToken_count),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_false, Lexique_spec_5F_scanner::kToken_false),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_system, Lexique_spec_5F_scanner::kToken_system),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_infinity, Lexique_spec_5F_scanner::kToken_infinity),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_hashmapsize, Lexique_spec_5F_scanner::kToken_hashmapsize),
  C_unicode_lexique_table_entry (kUnicodeString_spec_5F_scanner_garbageperiod, Lexique_spec_5F_scanner::kToken_garbageperiod)
} ;

int32_t Lexique_spec_5F_scanner::search_into_galgasKeyWordList (const String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_spec_5F_scanner_galgasKeyWordList, ktable_size_spec_5F_scanner_galgasKeyWordList) ;
}


//--------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//--------------------------------------------------------------------------------------------------

String Lexique_spec_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_spec_5F_scanner * ptr = (const cTokenFor_spec_5F_scanner *) inTokenPtr ;
  String s ;
  if (ptr == nullptr) {
    s.appendCString ("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString ("$$") ;
      break ;
    case kToken_identifier:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("identifier") ;
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendChar (TO_UNICODE (' ')) ;
      s.appendStringAsCLiteralStringConstant (ptr->mLexicalAttribute_theString) ;
      break ;
    case kToken_literal_5F_string:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("literal_string") ;
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendChar (TO_UNICODE (' ')) ;
      s.appendStringAsCLiteralStringConstant (ptr->mLexicalAttribute_theString) ;
      break ;
    case kToken_literal_5F_integer:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("literal_integer") ;
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendChar (TO_UNICODE (' ')) ;
      s.appendUnsigned (ptr->mLexicalAttribute_ulongValue) ;
      break ;
    case kToken_system:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("system") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_var:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("var") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_rule:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("rule") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_init:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("init") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_end:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("end") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_true:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("true") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_false:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("false") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_const:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("const") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_count:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("count") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_infinity:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("infinity") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_hashmapsize:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("hashmapsize") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken_garbageperiod:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("garbageperiod") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3E__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (">=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3E_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (">") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3C_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("<") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3C__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("<=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3D__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("==") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__21__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("!=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__26_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("&") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__7C_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("|") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__7E_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("~") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2C_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (",") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3B_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (";") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__28_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("(") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__29_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (")") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2B__2B_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("++") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2D__2D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("--") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2B__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("+=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2D__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("-=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3A__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (":=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__7B_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("{") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__7D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("}") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3A_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString (":") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__2D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("-") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__3D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("=") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__5B_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("[") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    case kToken__5D_:
      s.appendChar (TO_UNICODE ('$')) ;
      s.appendCString ("]") ;
      s.appendChar (TO_UNICODE ('$')) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//--------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//--------------------------------------------------------------------------------------------------

void Lexique_spec_5F_scanner::internalParseLexicalToken (cTokenFor_spec_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_theString.removeAllKeepingCapacity () ;
  token.mLexicalAttribute_ulongValue = 0 ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_theString, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
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
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        token.mTokenCode = kToken_literal_5F_string ;
        enterToken (token) ;
      }else{
        lexicalError (gLexicalMessage_spec_5F_scanner_incorrectStringEnd COMMA_LINE_AND_SOURCE_FILE) ;
      }
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3E__3D_, true)) {
      token.mTokenCode = kToken__3E__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3D__3D_, true)) {
      token.mTokenCode = kToken__3D__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3C__3D_, true)) {
      token.mTokenCode = kToken__3C__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3A__3D_, true)) {
      token.mTokenCode = kToken__3A__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D__3D_, true)) {
      token.mTokenCode = kToken__2D__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D__2D_, true)) {
      token.mTokenCode = kToken__2D__2D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2B__3D_, true)) {
      token.mTokenCode = kToken__2B__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2B__2B_, true)) {
      token.mTokenCode = kToken__2B__2B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__21__3D_, true)) {
      token.mTokenCode = kToken__21__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7E_, true)) {
      token.mTokenCode = kToken__7E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7D_, true)) {
      token.mTokenCode = kToken__7D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7C_, true)) {
      token.mTokenCode = kToken__7C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__7B_, true)) {
      token.mTokenCode = kToken__7B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__5D_, true)) {
      token.mTokenCode = kToken__5D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__5B_, true)) {
      token.mTokenCode = kToken__5B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3E_, true)) {
      token.mTokenCode = kToken__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3D_, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3C_, true)) {
      token.mTokenCode = kToken__3C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3B_, true)) {
      token.mTokenCode = kToken__3B_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__3A_, true)) {
      token.mTokenCode = kToken__3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2D_, true)) {
      token.mTokenCode = kToken__2D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__2C_, true)) {
      token.mTokenCode = kToken__2C_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__29_, true)) {
      token.mTokenCode = kToken__29_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__28_, true)) {
      token.mTokenCode = kToken__28_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_spec_5F_scanner__26_, true)) {
      token.mTokenCode = kToken__26_ ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
      ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge, gLexicalMessage_spec_5F_scanner_internalError) ;
      do {
        if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          ::scanner_routine_enterDigitIntoUInt (*this, previousChar (), token.mLexicalAttribute_ulongValue, gLexicalMessage_spec_5F_scanner_decimalNumberTooLarge, gLexicalMessage_spec_5F_scanner_internalError) ;
        }else if (testForInputUTF32Char (TO_UNICODE ('_'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_literal_5F_integer ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('#'))) {
      do {
        if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE ('\t')) || testForInputUTF32Char (TO_UNICODE ('\v')) || testForInputUTF32Char (TO_UNICODE ('\f')) || testForInputUTF32CharRange (TO_UNICODE (14), TO_UNICODE (65533))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
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

//--------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//--------------------------------------------------------------------------------------------------

bool Lexique_spec_5F_scanner::parseLexicalToken (void) {
  cTokenFor_spec_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    internalParseLexicalToken (token) ;
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//--------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//--------------------------------------------------------------------------------------------------

void Lexique_spec_5F_scanner::enterToken (cTokenFor_spec_5F_scanner & ioToken) {
  cTokenFor_spec_5F_scanner * ptr = nullptr ;
  macroMyNew (ptr, cTokenFor_spec_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_theString = ioToken.mLexicalAttribute_theString ;
  ptr->mLexicalAttribute_ulongValue = ioToken.mLexicalAttribute_ulongValue ;
  enterTokenFromPointer (ptr) ;
}

//--------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//--------------------------------------------------------------------------------------------------

String Lexique_spec_5F_scanner::attributeValue_theString (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_theString ;
}

//--------------------------------------------------------------------------------------------------

uint32_t Lexique_spec_5F_scanner::attributeValue_ulongValue (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_ulongValue ;
}

//--------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//--------------------------------------------------------------------------------------------------

GALGAS_lstring Lexique_spec_5F_scanner::synthetizedAttribute_theString (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_theString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint Lexique_spec_5F_scanner::synthetizedAttribute_ulongValue (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint value (ptr->mLexicalAttribute_ulongValue) ;
  GALGAS_luint result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//--------------------------------------------------------------------------------------------------

GALGAS_stringlist Lexique_spec_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::class_func_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("literal_string") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("literal_integer") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("system") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("var") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("rule") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("init") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("end") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("true") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("false") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("const") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("count") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("infinity") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("hashmapsize") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("garbageperiod") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (">=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("<=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("==") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("!=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("&") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("|") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("~") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (";") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("++") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("--") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("+=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("-=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (":=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("{") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("}") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string (":") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("[") COMMA_HERE) ;
  result.addAssign_operation (GALGAS_string ("]") COMMA_HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordLists_spec_5F_scanner (TC_UniqueArray <String> & ioList) {
  ioList.appendObject ("spec_scanner:delimitorsList") ;
  ioList.appendObject ("spec_scanner:galgasKeyWordList") ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_spec_5F_scanner (const String & inIdentifier,
                                                      bool & ioFound,
                                                      TC_UniqueArray <String> & ioList) {
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

//--------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_spec_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_spec_5F_scanner, getKeywordsForIdentifier_spec_5F_scanner) ;

//--------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//--------------------------------------------------------------------------------------------------

uint32_t Lexique_spec_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
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

//--------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//--------------------------------------------------------------------------------------------------

String Lexique_spec_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  String result ;
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

//--------------------------------------------------------------------------------------------------

cMapElement_typeVarMap::cMapElement_typeVarMap (const GALGAS_typeVarMap_2D_element & inValue
                                                COMMA_LOCATION_ARGS) :
cMapElement (inValue.mProperty_lkey COMMA_THERE),
mProperty_mIndex (inValue.mProperty_mIndex) {
}

//--------------------------------------------------------------------------------------------------

cMapElement_typeVarMap::cMapElement_typeVarMap (const GALGAS_lstring & inKey,
                                                const GALGAS_uint & in_mIndex
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mIndex (in_mIndex) {
}

//--------------------------------------------------------------------------------------------------

bool cMapElement_typeVarMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//--------------------------------------------------------------------------------------------------

cMapElement * cMapElement_typeVarMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_typeVarMap (mProperty_lkey, mProperty_mIndex COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cMapElement_typeVarMap::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mIndex" ":") ;
  mProperty_mIndex.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cMapElement_typeVarMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_typeVarMap * operand = (cMapElement_typeVarMap *) inOperand ;
  ComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mIndex.objectCompare (operand->mProperty_mIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap::GALGAS_typeVarMap (void) :
AC_GALGAS_map () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap::GALGAS_typeVarMap (const GALGAS_typeVarMap & inSource) :
AC_GALGAS_map (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap & GALGAS_typeVarMap::operator = (const GALGAS_typeVarMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::init (Compiler * COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::class_func_emptyMap (LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::class_func_mapWithMapToOverride (const GALGAS_typeVarMap & inMapToOverride
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::getter_overriddenMap (Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_typeVarMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::enterElement (const GALGAS_typeVarMap_2D_element & inValue,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeVarMap (inValue COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_uint & inArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeVarMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::add_operation (const GALGAS_typeVarMap & inOperand,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typeVarMap result = *this ;
  cEnumerator_typeVarMap enumerator (inOperand, EnumerationOrder::up) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_mIndex (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_uint inArgument0,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeVarMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' place is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_typeVarMap_searchKey = "the '%K' place is not declared" ;

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_uint & outArgument0,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_typeVarMap_searchKey
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    outArgument0 = p->mProperty_mIndex ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeVarMap::getter_mIndexForKey (const GALGAS_string & inKey,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) attributes ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    result = p->mProperty_mIndex ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap::setter_setMIndexForKey (GALGAS_uint inAttributeValue,
                                                GALGAS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeVarMap * p = (cMapElement_typeVarMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    p->mProperty_mIndex = inAttributeValue ;
  }
}

//--------------------------------------------------------------------------------------------------

cMapElement_typeVarMap * GALGAS_typeVarMap::readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_typeVarMap * result = (cMapElement_typeVarMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_typeVarMap) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

cEnumerator_typeVarMap::cEnumerator_typeVarMap (const GALGAS_typeVarMap & inEnumeratedObject,
                                                const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element cEnumerator_typeVarMap::current (LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeVarMap) ;
  return GALGAS_typeVarMap_2D_element (p->mProperty_lkey, p->mProperty_mIndex) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeVarMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeVarMap::current_mIndex (LOCATION_ARGS) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeVarMap) ;
  return p->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeVarMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_uint & outArgument0) const {
  const cMapElement_typeVarMap * p = (const cMapElement_typeVarMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_typeVarMap) ;
    outArgument0 = p->mProperty_mIndex ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeVarMap generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap ("typeVarMap",
                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeVarMap (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap GALGAS_typeVarMap::extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap result ;
  const GALGAS_typeVarMap * p = (const GALGAS_typeVarMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

cMapElement_typeCstMap::cMapElement_typeCstMap (const GALGAS_typeCstMap_2D_element & inValue
                                                COMMA_LOCATION_ARGS) :
cMapElement (inValue.mProperty_lkey COMMA_THERE),
mProperty_mSign (inValue.mProperty_mSign),
mProperty_mValue (inValue.mProperty_mValue) {
}

//--------------------------------------------------------------------------------------------------

cMapElement_typeCstMap::cMapElement_typeCstMap (const GALGAS_lstring & inKey,
                                                const GALGAS_bool & in_mSign,
                                                const GALGAS_luint & in_mValue
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mSign (in_mSign),
mProperty_mValue (in_mValue) {
}

//--------------------------------------------------------------------------------------------------

bool cMapElement_typeCstMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//--------------------------------------------------------------------------------------------------

cMapElement * cMapElement_typeCstMap::copy (void) {
  cMapElement * result = nullptr ;
  macroMyNew (result, cMapElement_typeCstMap (mProperty_lkey, mProperty_mSign, mProperty_mValue COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cMapElement_typeCstMap::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mSign" ":") ;
  mProperty_mSign.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mValue" ":") ;
  mProperty_mValue.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cMapElement_typeCstMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_typeCstMap * operand = (cMapElement_typeCstMap *) inOperand ;
  ComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mSign.objectCompare (operand->mProperty_mSign) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mValue.objectCompare (operand->mProperty_mValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap::GALGAS_typeCstMap (void) :
AC_GALGAS_map () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap::GALGAS_typeCstMap (const GALGAS_typeCstMap & inSource) :
AC_GALGAS_map (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap & GALGAS_typeCstMap::operator = (const GALGAS_typeCstMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::init (Compiler * COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::class_func_emptyMap (LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::class_func_mapWithMapToOverride (const GALGAS_typeCstMap & inMapToOverride
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::getter_overriddenMap (Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_typeCstMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::enterElement (const GALGAS_typeCstMap_2D_element & inValue,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeCstMap (inValue COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeCstMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_bool & inArgument0,
                                             const GALGAS_luint & inArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeCstMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@typeCstMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::add_operation (const GALGAS_typeCstMap & inOperand,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typeCstMap result = *this ;
  cEnumerator_typeCstMap enumerator (inOperand, EnumerationOrder::up) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_mSign (HERE), enumerator.current_mValue (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_insertKey (GALGAS_lstring inKey,
                                          GALGAS_bool inArgument0,
                                          GALGAS_luint inArgument1,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * p = nullptr ;
  macroMyNew (p, cMapElement_typeCstMap (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the '%K' constant is already declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_typeCstMap_searchKey = "there '%K' constant is not defined" ;

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::method_searchKey (GALGAS_lstring inKey,
                                          GALGAS_bool & outArgument0,
                                          GALGAS_luint & outArgument1,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_typeCstMap_searchKey
                                                                                     COMMA_THERE) ;
  if (nullptr == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    outArgument0 = p->mProperty_mSign ;
    outArgument1 = p->mProperty_mValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeCstMap::getter_mSignForKey (const GALGAS_string & inKey,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) attributes ;
  GALGAS_bool result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    result = p->mProperty_mSign ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeCstMap::getter_mValueForKey (const GALGAS_string & inKey,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) attributes ;
  GALGAS_luint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    result = p->mProperty_mValue ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_setMSignForKey (GALGAS_bool inAttributeValue,
                                               GALGAS_string inKey,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeCstMap * p = (cMapElement_typeCstMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    p->mProperty_mSign = inAttributeValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap::setter_setMValueForKey (GALGAS_luint inAttributeValue,
                                                GALGAS_string inKey,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_typeCstMap * p = (cMapElement_typeCstMap *) attributes ;
  if (nullptr != p) {
    macroValidSharedObject (p, cMapElement_typeCstMap) ;
    p->mProperty_mValue = inAttributeValue ;
  }
}

//--------------------------------------------------------------------------------------------------

cMapElement_typeCstMap * GALGAS_typeCstMap::readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_typeCstMap * result = (cMapElement_typeCstMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_typeCstMap) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

cEnumerator_typeCstMap::cEnumerator_typeCstMap (const GALGAS_typeCstMap & inEnumeratedObject,
                                                const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element cEnumerator_typeCstMap::current (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return GALGAS_typeCstMap_2D_element (p->mProperty_lkey, p->mProperty_mSign, p->mProperty_mValue) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeCstMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool cEnumerator_typeCstMap::current_mSign (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return p->mProperty_mSign ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint cEnumerator_typeCstMap::current_mValue (LOCATION_ARGS) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_typeCstMap) ;
  return p->mProperty_mValue ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeCstMap::optional_searchKey (const GALGAS_string & inKey,
                                            GALGAS_bool & outArgument0,
                                            GALGAS_luint & outArgument1) const {
  const cMapElement_typeCstMap * p = (const cMapElement_typeCstMap *) searchForKey (inKey) ;
  const bool result = nullptr != p ;
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

//--------------------------------------------------------------------------------------------------
//
//     @typeCstMap generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap ("typeCstMap",
                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeCstMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeCstMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeCstMap (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap GALGAS_typeCstMap::extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap result ;
  const GALGAS_typeCstMap * p = (const GALGAS_typeCstMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeCstMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typePreconditionExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typePreconditionExpression::cPtr_typePreconditionExpression (Compiler * /* inCompiler */ COMMA_LOCATION_ARGS) :
acStrongPtr_class (THERE) {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePreconditionExpression::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------



ComparisonResult GALGAS_typePreconditionExpression::objectCompare (const GALGAS_typePreconditionExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression::GALGAS_typePreconditionExpression (void) :
AC_GALGAS_reference_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression::GALGAS_typePreconditionExpression (const cPtr_typePreconditionExpression * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePreconditionExpression) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @typePreconditionExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typePreconditionExpression::cPtr_typePreconditionExpression (LOCATION_ARGS) :
acStrongPtr_class (THERE) {
}


//--------------------------------------------------------------------------------------------------
//
//     @typePreconditionExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression ("typePreconditionExpression",
                                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePreconditionExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePreconditionExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePreconditionExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePreconditionExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typePreconditionExpression::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typePreconditionExpression result ;
  const GALGAS_typePreconditionExpression * p = (const GALGAS_typePreconditionExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePreconditionExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePreconditionExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typePreconditionExpression_2D_weak::objectCompare (const GALGAS_typePreconditionExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression_2D_weak::GALGAS_typePreconditionExpression_2D_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression_2D_weak & GALGAS_typePreconditionExpression_2D_weak::operator = (const GALGAS_typePreconditionExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression_2D_weak::GALGAS_typePreconditionExpression_2D_weak (const GALGAS_typePreconditionExpression & inSource) :
AC_GALGAS_weak_reference (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression_2D_weak GALGAS_typePreconditionExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typePreconditionExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typePreconditionExpression_2D_weak::bang_typePreconditionExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typePreconditionExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePreconditionExpression) ;
      result = GALGAS_typePreconditionExpression ((cPtr_typePreconditionExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typePreconditionExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak ("typePreconditionExpression-weak",
                                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePreconditionExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePreconditionExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePreconditionExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression_2D_weak GALGAS_typePreconditionExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                                    Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typePreconditionExpression_2D_weak result ;
  const GALGAS_typePreconditionExpression_2D_weak * p = (const GALGAS_typePreconditionExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePreconditionExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePreconditionExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeTrueExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeTrueExpression::cPtr_typeTrueExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeTrueExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeTrueExpression::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return ComparisonResult::operandEqual ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeTrueExpression::objectCompare (const GALGAS_typeTrueExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression::GALGAS_typeTrueExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeTrueExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeTrueExpression (inCompiler COMMA_THERE)) ;
  object->typeTrueExpression_init (inCompiler) ;
  const GALGAS_typeTrueExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeTrueExpression::
typeTrueExpression_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression::GALGAS_typeTrueExpression (const cPtr_typeTrueExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeTrueExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::class_func_new (LOCATION_ARGS) {
  GALGAS_typeTrueExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeTrueExpression (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeTrueExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeTrueExpression::cPtr_typeTrueExpression (LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeTrueExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

void cPtr_typeTrueExpression::description (String & ioString,
                                           const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@typeTrueExpression]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeTrueExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeTrueExpression (THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeTrueExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression ("typeTrueExpression",
                                                                          & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTrueExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTrueExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTrueExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeTrueExpression result ;
  const GALGAS_typeTrueExpression * p = (const GALGAS_typeTrueExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeTrueExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTrueExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeTrueExpression_2D_weak::objectCompare (const GALGAS_typeTrueExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression_2D_weak::GALGAS_typeTrueExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression_2D_weak & GALGAS_typeTrueExpression_2D_weak::operator = (const GALGAS_typeTrueExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression_2D_weak::GALGAS_typeTrueExpression_2D_weak (const GALGAS_typeTrueExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression_2D_weak GALGAS_typeTrueExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeTrueExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression GALGAS_typeTrueExpression_2D_weak::bang_typeTrueExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeTrueExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeTrueExpression) ;
      result = GALGAS_typeTrueExpression ((cPtr_typeTrueExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeTrueExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression_2D_weak ("typeTrueExpression-weak",
                                                                                  & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTrueExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTrueExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTrueExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTrueExpression_2D_weak GALGAS_typeTrueExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeTrueExpression_2D_weak result ;
  const GALGAS_typeTrueExpression_2D_weak * p = (const GALGAS_typeTrueExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeTrueExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTrueExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeFalseExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeFalseExpression::cPtr_typeFalseExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeFalseExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeFalseExpression::dynamicObjectCompare (const acPtr_class * /* inOperandPtr */) const {
  return ComparisonResult::operandEqual ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeFalseExpression::objectCompare (const GALGAS_typeFalseExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression::GALGAS_typeFalseExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeFalseExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeFalseExpression (inCompiler COMMA_THERE)) ;
  object->typeFalseExpression_init (inCompiler) ;
  const GALGAS_typeFalseExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeFalseExpression::
typeFalseExpression_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression::GALGAS_typeFalseExpression (const cPtr_typeFalseExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeFalseExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::class_func_new (LOCATION_ARGS) {
  GALGAS_typeFalseExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeFalseExpression (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeFalseExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeFalseExpression::cPtr_typeFalseExpression (LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE) {
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeFalseExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

void cPtr_typeFalseExpression::description (String & ioString,
                                            const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@typeFalseExpression]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeFalseExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeFalseExpression (THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeFalseExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression ("typeFalseExpression",
                                                                           & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeFalseExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeFalseExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeFalseExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression::extractObject (const GALGAS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeFalseExpression result ;
  const GALGAS_typeFalseExpression * p = (const GALGAS_typeFalseExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeFalseExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeFalseExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeFalseExpression_2D_weak::objectCompare (const GALGAS_typeFalseExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression_2D_weak::GALGAS_typeFalseExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression_2D_weak & GALGAS_typeFalseExpression_2D_weak::operator = (const GALGAS_typeFalseExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression_2D_weak::GALGAS_typeFalseExpression_2D_weak (const GALGAS_typeFalseExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression_2D_weak GALGAS_typeFalseExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeFalseExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression GALGAS_typeFalseExpression_2D_weak::bang_typeFalseExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeFalseExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeFalseExpression) ;
      result = GALGAS_typeFalseExpression ((cPtr_typeFalseExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeFalseExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression_2D_weak ("typeFalseExpression-weak",
                                                                                   & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeFalseExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeFalseExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeFalseExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeFalseExpression_2D_weak GALGAS_typeFalseExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeFalseExpression_2D_weak result ;
  const GALGAS_typeFalseExpression_2D_weak * p = (const GALGAS_typeFalseExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeFalseExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeFalseExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeComplementExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeComplementExpression::cPtr_typeComplementExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mExpression () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeComplementExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mExpression.printNonNullClassInstanceProperties ("mExpression") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeComplementExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeComplementExpression * p = (const cPtr_typeComplementExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeComplementExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mExpression.objectCompare (p->mProperty_mExpression) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeComplementExpression::objectCompare (const GALGAS_typeComplementExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression::GALGAS_typeComplementExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression::
init_21_ (const GALGAS_typePreconditionExpression & in_mExpression,
          Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeComplementExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeComplementExpression (inCompiler COMMA_THERE)) ;
  object->typeComplementExpression_init_21_ (in_mExpression, inCompiler) ;
  const GALGAS_typeComplementExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeComplementExpression::
typeComplementExpression_init_21_ (const GALGAS_typePreconditionExpression & in_mExpression,
                                   Compiler * /* inCompiler */) {
  mProperty_mExpression = in_mExpression ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression::GALGAS_typeComplementExpression (const cPtr_typeComplementExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeComplementExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression::class_func_new (const GALGAS_typePreconditionExpression & in_mExpression
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_typeComplementExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeComplementExpression (in_mExpression COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeComplementExpression::readProperty_mExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_typePreconditionExpression () ;
  }else{
    cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    return p->mProperty_mExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeComplementExpression::setProperty_mExpression (const GALGAS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    p->mProperty_mExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeComplementExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeComplementExpression::cPtr_typeComplementExpression (const GALGAS_typePreconditionExpression & in_mExpression
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mExpression () {
  mProperty_mExpression = in_mExpression ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeComplementExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

void cPtr_typeComplementExpression::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@typeComplementExpression:") ;
  mProperty_mExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeComplementExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeComplementExpression (mProperty_mExpression COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeComplementExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression ("typeComplementExpression",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeComplementExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeComplementExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeComplementExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeComplementExpression result ;
  const GALGAS_typeComplementExpression * p = (const GALGAS_typeComplementExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeComplementExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeComplementExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeComplementExpression_2D_weak::objectCompare (const GALGAS_typeComplementExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression_2D_weak::GALGAS_typeComplementExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression_2D_weak & GALGAS_typeComplementExpression_2D_weak::operator = (const GALGAS_typeComplementExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression_2D_weak::GALGAS_typeComplementExpression_2D_weak (const GALGAS_typeComplementExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression_2D_weak GALGAS_typeComplementExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeComplementExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression GALGAS_typeComplementExpression_2D_weak::bang_typeComplementExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeComplementExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeComplementExpression) ;
      result = GALGAS_typeComplementExpression ((cPtr_typeComplementExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeComplementExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression_2D_weak ("typeComplementExpression-weak",
                                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeComplementExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeComplementExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeComplementExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeComplementExpression_2D_weak GALGAS_typeComplementExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeComplementExpression_2D_weak result ;
  const GALGAS_typeComplementExpression_2D_weak * p = (const GALGAS_typeComplementExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeComplementExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeComplementExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeAndExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeAndExpression::cPtr_typeAndExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeAndExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mLeftExpression.printNonNullClassInstanceProperties ("mLeftExpression") ;
    mProperty_mRightExpression.printNonNullClassInstanceProperties ("mRightExpression") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeAndExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeAndExpression * p = (const cPtr_typeAndExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAndExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mLeftExpression.objectCompare (p->mProperty_mLeftExpression) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mRightExpression.objectCompare (p->mProperty_mRightExpression) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeAndExpression::objectCompare (const GALGAS_typeAndExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression::GALGAS_typeAndExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression::
init_21__21_ (const GALGAS_typePreconditionExpression & in_mLeftExpression,
              const GALGAS_typePreconditionExpression & in_mRightExpression,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeAndExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeAndExpression (inCompiler COMMA_THERE)) ;
  object->typeAndExpression_init_21__21_ (in_mLeftExpression, in_mRightExpression, inCompiler) ;
  const GALGAS_typeAndExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAndExpression::
typeAndExpression_init_21__21_ (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                const GALGAS_typePreconditionExpression & in_mRightExpression,
                                Compiler * /* inCompiler */) {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression::GALGAS_typeAndExpression (const cPtr_typeAndExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAndExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression::class_func_new (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                                                   const GALGAS_typePreconditionExpression & in_mRightExpression
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_typeAndExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAndExpression (in_mLeftExpression, in_mRightExpression COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeAndExpression::readProperty_mLeftExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_typePreconditionExpression () ;
  }else{
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    return p->mProperty_mLeftExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAndExpression::setProperty_mLeftExpression (const GALGAS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeAndExpression::readProperty_mRightExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_typePreconditionExpression () ;
  }else{
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    return p->mProperty_mRightExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAndExpression::setProperty_mRightExpression (const GALGAS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAndExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeAndExpression::cPtr_typeAndExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                                const GALGAS_typePreconditionExpression & in_mRightExpression
                                                COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAndExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression ;
}

void cPtr_typeAndExpression::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("[@typeAndExpression:") ;
  mProperty_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mRightExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAndExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAndExpression (mProperty_mLeftExpression, mProperty_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeAndExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression ("typeAndExpression",
                                                                         & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAndExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAndExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAndExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression::extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeAndExpression result ;
  const GALGAS_typeAndExpression * p = (const GALGAS_typeAndExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAndExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAndExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeAndExpression_2D_weak::objectCompare (const GALGAS_typeAndExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression_2D_weak::GALGAS_typeAndExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression_2D_weak & GALGAS_typeAndExpression_2D_weak::operator = (const GALGAS_typeAndExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression_2D_weak::GALGAS_typeAndExpression_2D_weak (const GALGAS_typeAndExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression_2D_weak GALGAS_typeAndExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeAndExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression GALGAS_typeAndExpression_2D_weak::bang_typeAndExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeAndExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAndExpression) ;
      result = GALGAS_typeAndExpression ((cPtr_typeAndExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeAndExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression_2D_weak ("typeAndExpression-weak",
                                                                                 & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAndExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAndExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAndExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAndExpression_2D_weak GALGAS_typeAndExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeAndExpression_2D_weak result ;
  const GALGAS_typeAndExpression_2D_weak * p = (const GALGAS_typeAndExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAndExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAndExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeOrExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeOrExpression::cPtr_typeOrExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeOrExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mLeftExpression.printNonNullClassInstanceProperties ("mLeftExpression") ;
    mProperty_mRightExpression.printNonNullClassInstanceProperties ("mRightExpression") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeOrExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeOrExpression * p = (const cPtr_typeOrExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeOrExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mLeftExpression.objectCompare (p->mProperty_mLeftExpression) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mRightExpression.objectCompare (p->mProperty_mRightExpression) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeOrExpression::objectCompare (const GALGAS_typeOrExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression::GALGAS_typeOrExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression::
init_21__21_ (const GALGAS_typePreconditionExpression & in_mLeftExpression,
              const GALGAS_typePreconditionExpression & in_mRightExpression,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeOrExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeOrExpression (inCompiler COMMA_THERE)) ;
  object->typeOrExpression_init_21__21_ (in_mLeftExpression, in_mRightExpression, inCompiler) ;
  const GALGAS_typeOrExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeOrExpression::
typeOrExpression_init_21__21_ (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                               const GALGAS_typePreconditionExpression & in_mRightExpression,
                               Compiler * /* inCompiler */) {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression::GALGAS_typeOrExpression (const cPtr_typeOrExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeOrExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression::class_func_new (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                                                 const GALGAS_typePreconditionExpression & in_mRightExpression
                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_typeOrExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeOrExpression (in_mLeftExpression, in_mRightExpression COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeOrExpression::readProperty_mLeftExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_typePreconditionExpression () ;
  }else{
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    return p->mProperty_mLeftExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeOrExpression::setProperty_mLeftExpression (const GALGAS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeOrExpression::readProperty_mRightExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_typePreconditionExpression () ;
  }else{
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    return p->mProperty_mRightExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeOrExpression::setProperty_mRightExpression (const GALGAS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeOrExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeOrExpression::cPtr_typeOrExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                              const GALGAS_typePreconditionExpression & in_mRightExpression
                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeOrExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression ;
}

void cPtr_typeOrExpression::description (String & ioString,
                                         const int32_t inIndentation) const {
  ioString.appendCString ("[@typeOrExpression:") ;
  mProperty_mLeftExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mRightExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeOrExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeOrExpression (mProperty_mLeftExpression, mProperty_mRightExpression COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeOrExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression ("typeOrExpression",
                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeOrExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeOrExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeOrExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression::extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeOrExpression result ;
  const GALGAS_typeOrExpression * p = (const GALGAS_typeOrExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeOrExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeOrExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeOrExpression_2D_weak::objectCompare (const GALGAS_typeOrExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression_2D_weak::GALGAS_typeOrExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression_2D_weak & GALGAS_typeOrExpression_2D_weak::operator = (const GALGAS_typeOrExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression_2D_weak::GALGAS_typeOrExpression_2D_weak (const GALGAS_typeOrExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression_2D_weak GALGAS_typeOrExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeOrExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression GALGAS_typeOrExpression_2D_weak::bang_typeOrExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeOrExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeOrExpression) ;
      result = GALGAS_typeOrExpression ((cPtr_typeOrExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeOrExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression_2D_weak ("typeOrExpression-weak",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeOrExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeOrExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeOrExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeOrExpression_2D_weak GALGAS_typeOrExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeOrExpression_2D_weak result ;
  const GALGAS_typeOrExpression_2D_weak * p = (const GALGAS_typeOrExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeOrExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeOrExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeEqualExpression_2D_weak::objectCompare (const GALGAS_typeEqualExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression_2D_weak::GALGAS_typeEqualExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression_2D_weak & GALGAS_typeEqualExpression_2D_weak::operator = (const GALGAS_typeEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression_2D_weak::GALGAS_typeEqualExpression_2D_weak (const GALGAS_typeEqualExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression_2D_weak GALGAS_typeEqualExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeEqualExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression_2D_weak::bang_typeEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeEqualExpression) ;
      result = GALGAS_typeEqualExpression ((cPtr_typeEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeEqualExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression_2D_weak ("typeEqualExpression-weak",
                                                                                   & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeEqualExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeEqualExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeEqualExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression_2D_weak GALGAS_typeEqualExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeEqualExpression_2D_weak result ;
  const GALGAS_typeEqualExpression_2D_weak * p = (const GALGAS_typeEqualExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeEqualExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeEqualExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeNonEqualExpression_2D_weak::objectCompare (const GALGAS_typeNonEqualExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression_2D_weak::GALGAS_typeNonEqualExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression_2D_weak & GALGAS_typeNonEqualExpression_2D_weak::operator = (const GALGAS_typeNonEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression_2D_weak::GALGAS_typeNonEqualExpression_2D_weak (const GALGAS_typeNonEqualExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression_2D_weak GALGAS_typeNonEqualExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression_2D_weak::bang_typeNonEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeNonEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeNonEqualExpression) ;
      result = GALGAS_typeNonEqualExpression ((cPtr_typeNonEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeNonEqualExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression_2D_weak ("typeNonEqualExpression-weak",
                                                                                      & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeNonEqualExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeNonEqualExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeNonEqualExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression_2D_weak GALGAS_typeNonEqualExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression_2D_weak result ;
  const GALGAS_typeNonEqualExpression_2D_weak * p = (const GALGAS_typeNonEqualExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeNonEqualExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeNonEqualExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeInfOrEqualExpression_2D_weak::objectCompare (const GALGAS_typeInfOrEqualExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression_2D_weak::GALGAS_typeInfOrEqualExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression_2D_weak & GALGAS_typeInfOrEqualExpression_2D_weak::operator = (const GALGAS_typeInfOrEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression_2D_weak::GALGAS_typeInfOrEqualExpression_2D_weak (const GALGAS_typeInfOrEqualExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression_2D_weak GALGAS_typeInfOrEqualExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression_2D_weak::bang_typeInfOrEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeInfOrEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeInfOrEqualExpression) ;
      result = GALGAS_typeInfOrEqualExpression ((cPtr_typeInfOrEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeInfOrEqualExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2D_weak ("typeInfOrEqualExpression-weak",
                                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInfOrEqualExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInfOrEqualExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInfOrEqualExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression_2D_weak GALGAS_typeInfOrEqualExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression_2D_weak result ;
  const GALGAS_typeInfOrEqualExpression_2D_weak * p = (const GALGAS_typeInfOrEqualExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeInfOrEqualExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInfOrEqualExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeSupOrEqualExpression_2D_weak::objectCompare (const GALGAS_typeSupOrEqualExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression_2D_weak::GALGAS_typeSupOrEqualExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression_2D_weak & GALGAS_typeSupOrEqualExpression_2D_weak::operator = (const GALGAS_typeSupOrEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression_2D_weak::GALGAS_typeSupOrEqualExpression_2D_weak (const GALGAS_typeSupOrEqualExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression_2D_weak GALGAS_typeSupOrEqualExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression_2D_weak::bang_typeSupOrEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeSupOrEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeSupOrEqualExpression) ;
      result = GALGAS_typeSupOrEqualExpression ((cPtr_typeSupOrEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeSupOrEqualExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2D_weak ("typeSupOrEqualExpression-weak",
                                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSupOrEqualExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSupOrEqualExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSupOrEqualExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression_2D_weak GALGAS_typeSupOrEqualExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression_2D_weak result ;
  const GALGAS_typeSupOrEqualExpression_2D_weak * p = (const GALGAS_typeSupOrEqualExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeSupOrEqualExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSupOrEqualExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeStrictInfExpression_2D_weak::objectCompare (const GALGAS_typeStrictInfExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression_2D_weak::GALGAS_typeStrictInfExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression_2D_weak & GALGAS_typeStrictInfExpression_2D_weak::operator = (const GALGAS_typeStrictInfExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression_2D_weak::GALGAS_typeStrictInfExpression_2D_weak (const GALGAS_typeStrictInfExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression_2D_weak GALGAS_typeStrictInfExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression_2D_weak::bang_typeStrictInfExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeStrictInfExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeStrictInfExpression) ;
      result = GALGAS_typeStrictInfExpression ((cPtr_typeStrictInfExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeStrictInfExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression_2D_weak ("typeStrictInfExpression-weak",
                                                                                       & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictInfExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictInfExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictInfExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression_2D_weak GALGAS_typeStrictInfExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression_2D_weak result ;
  const GALGAS_typeStrictInfExpression_2D_weak * p = (const GALGAS_typeStrictInfExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeStrictInfExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictInfExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeStrictSupExpression_2D_weak::objectCompare (const GALGAS_typeStrictSupExpression_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression_2D_weak::GALGAS_typeStrictSupExpression_2D_weak (void) :
GALGAS_typePreconditionExpression_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression_2D_weak & GALGAS_typeStrictSupExpression_2D_weak::operator = (const GALGAS_typeStrictSupExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression_2D_weak::GALGAS_typeStrictSupExpression_2D_weak (const GALGAS_typeStrictSupExpression & inSource) :
GALGAS_typePreconditionExpression_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression_2D_weak GALGAS_typeStrictSupExpression_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression_2D_weak::bang_typeStrictSupExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeStrictSupExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeStrictSupExpression) ;
      result = GALGAS_typeStrictSupExpression ((cPtr_typeStrictSupExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeStrictSupExpression-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression_2D_weak ("typeStrictSupExpression-weak",
                                                                                       & kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictSupExpression_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictSupExpression_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictSupExpression_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression_2D_weak GALGAS_typeStrictSupExpression_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression_2D_weak result ;
  const GALGAS_typeStrictSupExpression_2D_weak * p = (const GALGAS_typeStrictSupExpression_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeStrictSupExpression_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictSupExpression-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typePostcondition reference class
//--------------------------------------------------------------------------------------------------

cPtr_typePostcondition::cPtr_typePostcondition (Compiler * /* inCompiler */ COMMA_LOCATION_ARGS) :
acStrongPtr_class (THERE) {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePostcondition::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------



ComparisonResult GALGAS_typePostcondition::objectCompare (const GALGAS_typePostcondition & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition::GALGAS_typePostcondition (void) :
AC_GALGAS_reference_class () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition::GALGAS_typePostcondition (const cPtr_typePostcondition * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostcondition) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostcondition class
//--------------------------------------------------------------------------------------------------

cPtr_typePostcondition::cPtr_typePostcondition (LOCATION_ARGS) :
acStrongPtr_class (THERE) {
}


//--------------------------------------------------------------------------------------------------
//
//     @typePostcondition generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition ("typePostcondition",
                                                                         nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostcondition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostcondition ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostcondition::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostcondition (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostcondition::extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostcondition result ;
  const GALGAS_typePostcondition * p = (const GALGAS_typePostcondition *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostcondition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostcondition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typePostcondition_2D_weak::objectCompare (const GALGAS_typePostcondition_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition_2D_weak::GALGAS_typePostcondition_2D_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition_2D_weak & GALGAS_typePostcondition_2D_weak::operator = (const GALGAS_typePostcondition & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition_2D_weak::GALGAS_typePostcondition_2D_weak (const GALGAS_typePostcondition & inSource) :
AC_GALGAS_weak_reference (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition_2D_weak GALGAS_typePostcondition_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typePostcondition_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostcondition_2D_weak::bang_typePostcondition_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typePostcondition result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostcondition) ;
      result = GALGAS_typePostcondition ((cPtr_typePostcondition *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typePostcondition-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition_2D_weak ("typePostcondition-weak",
                                                                                 nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostcondition_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostcondition_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostcondition_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostcondition_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition_2D_weak GALGAS_typePostcondition_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostcondition_2D_weak result ;
  const GALGAS_typePostcondition_2D_weak * p = (const GALGAS_typePostcondition_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostcondition_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostcondition-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typePostIncrement_2D_weak::objectCompare (const GALGAS_typePostIncrement_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement_2D_weak::GALGAS_typePostIncrement_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement_2D_weak & GALGAS_typePostIncrement_2D_weak::operator = (const GALGAS_typePostIncrement & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement_2D_weak::GALGAS_typePostIncrement_2D_weak (const GALGAS_typePostIncrement & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement_2D_weak GALGAS_typePostIncrement_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typePostIncrement_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement_2D_weak::bang_typePostIncrement_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typePostIncrement result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostIncrement) ;
      result = GALGAS_typePostIncrement ((cPtr_typePostIncrement *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typePostIncrement-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement_2D_weak ("typePostIncrement-weak",
                                                                                 & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostIncrement_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostIncrement_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostIncrement_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement_2D_weak GALGAS_typePostIncrement_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostIncrement_2D_weak result ;
  const GALGAS_typePostIncrement_2D_weak * p = (const GALGAS_typePostIncrement_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostIncrement_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostIncrement-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typePostDecrement_2D_weak::objectCompare (const GALGAS_typePostDecrement_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement_2D_weak::GALGAS_typePostDecrement_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement_2D_weak & GALGAS_typePostDecrement_2D_weak::operator = (const GALGAS_typePostDecrement & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement_2D_weak::GALGAS_typePostDecrement_2D_weak (const GALGAS_typePostDecrement & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement_2D_weak GALGAS_typePostDecrement_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typePostDecrement_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement_2D_weak::bang_typePostDecrement_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typePostDecrement result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostDecrement) ;
      result = GALGAS_typePostDecrement ((cPtr_typePostDecrement *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typePostDecrement-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement_2D_weak ("typePostDecrement-weak",
                                                                                 & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostDecrement_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostDecrement_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostDecrement_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement_2D_weak GALGAS_typePostDecrement_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostDecrement_2D_weak result ;
  const GALGAS_typePostDecrement_2D_weak * p = (const GALGAS_typePostDecrement_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostDecrement_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostDecrement-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeAddConstant_2D_weak::objectCompare (const GALGAS_typeAddConstant_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant_2D_weak::GALGAS_typeAddConstant_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant_2D_weak & GALGAS_typeAddConstant_2D_weak::operator = (const GALGAS_typeAddConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant_2D_weak::GALGAS_typeAddConstant_2D_weak (const GALGAS_typeAddConstant & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant_2D_weak GALGAS_typeAddConstant_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeAddConstant_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant_2D_weak::bang_typeAddConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeAddConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAddConstant) ;
      result = GALGAS_typeAddConstant ((cPtr_typeAddConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeAddConstant-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant_2D_weak ("typeAddConstant-weak",
                                                                               & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAddConstant_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAddConstant_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAddConstant_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant_2D_weak GALGAS_typeAddConstant_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeAddConstant_2D_weak result ;
  const GALGAS_typeAddConstant_2D_weak * p = (const GALGAS_typeAddConstant_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAddConstant_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAddConstant-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeSubConstant_2D_weak::objectCompare (const GALGAS_typeSubConstant_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant_2D_weak::GALGAS_typeSubConstant_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant_2D_weak & GALGAS_typeSubConstant_2D_weak::operator = (const GALGAS_typeSubConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant_2D_weak::GALGAS_typeSubConstant_2D_weak (const GALGAS_typeSubConstant & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant_2D_weak GALGAS_typeSubConstant_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeSubConstant_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant_2D_weak::bang_typeSubConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeSubConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeSubConstant) ;
      result = GALGAS_typeSubConstant ((cPtr_typeSubConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeSubConstant-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant_2D_weak ("typeSubConstant-weak",
                                                                               & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSubConstant_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSubConstant_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSubConstant_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant_2D_weak GALGAS_typeSubConstant_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeSubConstant_2D_weak result ;
  const GALGAS_typeSubConstant_2D_weak * p = (const GALGAS_typeSubConstant_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeSubConstant_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSubConstant-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeAssignConstant_2D_weak::objectCompare (const GALGAS_typeAssignConstant_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant_2D_weak::GALGAS_typeAssignConstant_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant_2D_weak & GALGAS_typeAssignConstant_2D_weak::operator = (const GALGAS_typeAssignConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant_2D_weak::GALGAS_typeAssignConstant_2D_weak (const GALGAS_typeAssignConstant & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant_2D_weak GALGAS_typeAssignConstant_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeAssignConstant_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant_2D_weak::bang_typeAssignConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeAssignConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAssignConstant) ;
      result = GALGAS_typeAssignConstant ((cPtr_typeAssignConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeAssignConstant-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant_2D_weak ("typeAssignConstant-weak",
                                                                                  & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignConstant_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignConstant_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignConstant_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant_2D_weak GALGAS_typeAssignConstant_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignConstant_2D_weak result ;
  const GALGAS_typeAssignConstant_2D_weak * p = (const GALGAS_typeAssignConstant_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAssignConstant_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignConstant-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeAssignInfinity_2D_weak::objectCompare (const GALGAS_typeAssignInfinity_2D_weak & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    cPtr_weakReference_proxy * myPtr = mProxyPtr ;
    const size_t myObjectPtr = size_t (myPtr) ;
    cPtr_weakReference_proxy * operandPtr = inOperand.mProxyPtr ;
    const size_t operandObjectPtr = size_t (operandPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity_2D_weak::GALGAS_typeAssignInfinity_2D_weak (void) :
GALGAS_typePostcondition_2D_weak () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity_2D_weak & GALGAS_typeAssignInfinity_2D_weak::operator = (const GALGAS_typeAssignInfinity & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity_2D_weak::GALGAS_typeAssignInfinity_2D_weak (const GALGAS_typeAssignInfinity & inSource) :
GALGAS_typePostcondition_2D_weak (inSource) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity_2D_weak GALGAS_typeAssignInfinity_2D_weak::class_func_nil (LOCATION_ARGS) {
  GALGAS_typeAssignInfinity_2D_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity_2D_weak::bang_typeAssignInfinity_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GALGAS_typeAssignInfinity result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAssignInfinity) ;
      result = GALGAS_typeAssignInfinity ((cPtr_typeAssignInfinity *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeAssignInfinity-weak generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity_2D_weak ("typeAssignInfinity-weak",
                                                                                  & kTypeDescriptor_GALGAS_typePostcondition_2D_weak) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignInfinity_2D_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity_2D_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignInfinity_2D_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignInfinity_2D_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity_2D_weak GALGAS_typeAssignInfinity_2D_weak::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignInfinity_2D_weak result ;
  const GALGAS_typeAssignInfinity_2D_weak * p = (const GALGAS_typeAssignInfinity_2D_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAssignInfinity_2D_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignInfinity-weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Class for element of '@typePostconditionList' list
//
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typePostconditionList : public cCollectionElement {
  public: GALGAS_typePostconditionList_2D_element mObject ;

//--- Class functions
  public: cCollectionElement_typePostconditionList (const GALGAS_typePostcondition & in_mPostcondition
                                                    COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typePostconditionList (const GALGAS_typePostconditionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual ComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GALGAS_typePostcondition & in_mPostcondition
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mPostcondition) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GALGAS_typePostconditionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mPostcondition) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement_typePostconditionList::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typePostconditionList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_typePostconditionList (mObject.mProperty_mPostcondition COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement_typePostconditionList::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mPostcondition" ":") ;
  mObject.mProperty_mPostcondition.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cCollectionElement_typePostconditionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typePostconditionList * operand = (cCollectionElement_typePostconditionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typePostconditionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList::GALGAS_typePostconditionList (void) :
AC_GALGAS_list () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList::GALGAS_typePostconditionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typePostconditionList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_typePostconditionList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::enterElement (const GALGAS_typePostconditionList_2D_element & inValue,
                                                 Compiler * /* inCompiler */
                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement * p = nullptr ;
  macroMyNew (p, cCollectionElement_typePostconditionList (inValue COMMA_THERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  appendObject (attributes) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::class_func_listWithValue (const GALGAS_typePostcondition & inOperand0
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                              const GALGAS_typePostcondition & in_mPostcondition
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_typePostconditionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typePostconditionList (in_mPostcondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::addAssign_operation (const GALGAS_typePostcondition & inOperand0
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typePostconditionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_append (const GALGAS_typePostcondition inOperand0,
                                                  Compiler * /* inCompiler */
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typePostconditionList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_insertAtIndex (const GALGAS_typePostcondition inOperand0,
                                                         const GALGAS_uint inInsertionIndex,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_removeAtIndex (GALGAS_typePostcondition & outOperand0,
                                                         const GALGAS_uint inRemoveIndex,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
      if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_popFirst (GALGAS_typePostcondition & outOperand0,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_popLast (GALGAS_typePostcondition & outOperand0,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::method_first (GALGAS_typePostcondition & outOperand0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::method_last (GALGAS_typePostcondition & outOperand0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    outOperand0 = p->mObject.mProperty_mPostcondition ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::add_operation (const GALGAS_typePostconditionList & inOperand,
                                                                          Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::class_func_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::class_func_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_typePostconditionList result = GALGAS_typePostconditionList::class_func_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::plusAssign_operation (const GALGAS_typePostconditionList inOperand,
                                                         Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList::setter_setMPostconditionAtIndex (GALGAS_typePostcondition inOperand,
                                                                    GALGAS_uint inIndex,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPostcondition = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typePostconditionList::getter_mPostconditionAtIndex (const GALGAS_uint & inIndex,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) attributes.ptr () ;
  GALGAS_typePostcondition result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    result = p->mObject.mProperty_mPostcondition ;
  }
  return result ;
}



//--------------------------------------------------------------------------------------------------

cEnumerator_typePostconditionList::cEnumerator_typePostconditionList (const GALGAS_typePostconditionList & inEnumeratedObject,
                                                                      const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element cEnumerator_typePostconditionList::current (LOCATION_ARGS) const {
  const cCollectionElement_typePostconditionList * p = (const cCollectionElement_typePostconditionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
  return p->mObject ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition cEnumerator_typePostconditionList::current_mPostcondition (LOCATION_ARGS) const {
  const cCollectionElement_typePostconditionList * p = (const cCollectionElement_typePostconditionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
  return p->mObject.mProperty_mPostcondition ;
}




//--------------------------------------------------------------------------------------------------
//
//     @typePostconditionList generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList ("typePostconditionList",
                                                                             nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostconditionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostconditionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostconditionList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typePostconditionList::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typePostconditionList result ;
  const GALGAS_typePostconditionList * p = (const GALGAS_typePostconditionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostconditionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Class for element of '@typeTransitionList' list
//
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typeTransitionList : public cCollectionElement {
  public: GALGAS_typeTransitionList_2D_element mObject ;

//--- Class functions
  public: cCollectionElement_typeTransitionList (const GALGAS_lstring & in_mTransitionName,
                                                 const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                 const GALGAS_typePostconditionList & in_mPostconditionList,
                                                 const GALGAS_uint & in_mLowTemporalBound,
                                                 const GALGAS_uint & in_mHighTemporalBound
                                                 COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typeTransitionList (const GALGAS_typeTransitionList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual ComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GALGAS_lstring & in_mTransitionName,
                                                                              const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                                              const GALGAS_typePostconditionList & in_mPostconditionList,
                                                                              const GALGAS_uint & in_mLowTemporalBound,
                                                                              const GALGAS_uint & in_mHighTemporalBound
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTransitionName, in_mPreconditionExpression, in_mPostconditionList, in_mLowTemporalBound, in_mHighTemporalBound) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GALGAS_typeTransitionList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mTransitionName, inElement.mProperty_mPreconditionExpression, inElement.mProperty_mPostconditionList, inElement.mProperty_mLowTemporalBound, inElement.mProperty_mHighTemporalBound) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement_typeTransitionList::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typeTransitionList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_typeTransitionList (mObject.mProperty_mTransitionName, mObject.mProperty_mPreconditionExpression, mObject.mProperty_mPostconditionList, mObject.mProperty_mLowTemporalBound, mObject.mProperty_mHighTemporalBound COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement_typeTransitionList::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mTransitionName" ":") ;
  mObject.mProperty_mTransitionName.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mPreconditionExpression" ":") ;
  mObject.mProperty_mPreconditionExpression.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mPostconditionList" ":") ;
  mObject.mProperty_mPostconditionList.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mLowTemporalBound" ":") ;
  mObject.mProperty_mLowTemporalBound.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mHighTemporalBound" ":") ;
  mObject.mProperty_mHighTemporalBound.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cCollectionElement_typeTransitionList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typeTransitionList * operand = (cCollectionElement_typeTransitionList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typeTransitionList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList::GALGAS_typeTransitionList (void) :
AC_GALGAS_list () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList::GALGAS_typeTransitionList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeTransitionList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_typeTransitionList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::enterElement (const GALGAS_typeTransitionList_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeTransitionList (inValue COMMA_THERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  appendObject (attributes) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::class_func_listWithValue (const GALGAS_lstring & inOperand0,
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_lstring & in_mTransitionName,
                                                           const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                           const GALGAS_typePostconditionList & in_mPostconditionList,
                                                           const GALGAS_uint & in_mLowTemporalBound,
                                                           const GALGAS_uint & in_mHighTemporalBound
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeTransitionList (in_mTransitionName,
                                                        in_mPreconditionExpression,
                                                        in_mPostconditionList,
                                                        in_mLowTemporalBound,
                                                        in_mHighTemporalBound COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                                     const GALGAS_typePreconditionExpression & inOperand1,
                                                     const GALGAS_typePostconditionList & inOperand2,
                                                     const GALGAS_uint & inOperand3,
                                                     const GALGAS_uint & inOperand4
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typeTransitionList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_append (const GALGAS_lstring inOperand0,
                                               const GALGAS_typePreconditionExpression inOperand1,
                                               const GALGAS_typePostconditionList inOperand2,
                                               const GALGAS_uint inOperand3,
                                               const GALGAS_uint inOperand4,
                                               Compiler * /* inCompiler */
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typeTransitionList (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                      const GALGAS_typePreconditionExpression inOperand1,
                                                      const GALGAS_typePostconditionList inOperand2,
                                                      const GALGAS_uint inOperand3,
                                                      const GALGAS_uint inOperand4,
                                                      const GALGAS_uint inInsertionIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid ()) {
      cCollectionElement * p = nullptr ;
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                      GALGAS_typePreconditionExpression & outOperand1,
                                                      GALGAS_typePostconditionList & outOperand2,
                                                      GALGAS_uint & outOperand3,
                                                      GALGAS_uint & outOperand4,
                                                      const GALGAS_uint inRemoveIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
      if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_popFirst (GALGAS_lstring & outOperand0,
                                                 GALGAS_typePreconditionExpression & outOperand1,
                                                 GALGAS_typePostconditionList & outOperand2,
                                                 GALGAS_uint & outOperand3,
                                                 GALGAS_uint & outOperand4,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_popLast (GALGAS_lstring & outOperand0,
                                                GALGAS_typePreconditionExpression & outOperand1,
                                                GALGAS_typePostconditionList & outOperand2,
                                                GALGAS_uint & outOperand3,
                                                GALGAS_uint & outOperand4,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::method_first (GALGAS_lstring & outOperand0,
                                              GALGAS_typePreconditionExpression & outOperand1,
                                              GALGAS_typePostconditionList & outOperand2,
                                              GALGAS_uint & outOperand3,
                                              GALGAS_uint & outOperand4,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::method_last (GALGAS_lstring & outOperand0,
                                             GALGAS_typePreconditionExpression & outOperand1,
                                             GALGAS_typePostconditionList & outOperand2,
                                             GALGAS_uint & outOperand3,
                                             GALGAS_uint & outOperand4,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::add_operation (const GALGAS_typeTransitionList & inOperand,
                                                                    Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::class_func_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::class_func_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_typeTransitionList result = GALGAS_typeTransitionList::class_func_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::plusAssign_operation (const GALGAS_typeTransitionList inOperand,
                                                      Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMTransitionNameAtIndex (GALGAS_lstring inOperand,
                                                                  GALGAS_uint inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mTransitionName = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeTransitionList::getter_mTransitionNameAtIndex (const GALGAS_uint & inIndex,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mTransitionName ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMPreconditionExpressionAtIndex (GALGAS_typePreconditionExpression inOperand,
                                                                          GALGAS_uint inIndex,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPreconditionExpression = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_typeTransitionList::getter_mPreconditionExpressionAtIndex (const GALGAS_uint & inIndex,
                                                                                                    Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_typePreconditionExpression result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mPreconditionExpression ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMPostconditionListAtIndex (GALGAS_typePostconditionList inOperand,
                                                                     GALGAS_uint inIndex,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mPostconditionList = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList GALGAS_typeTransitionList::getter_mPostconditionListAtIndex (const GALGAS_uint & inIndex,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_typePostconditionList result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mPostconditionList ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMLowTemporalBoundAtIndex (GALGAS_uint inOperand,
                                                                    GALGAS_uint inIndex,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mLowTemporalBound = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList::getter_mLowTemporalBoundAtIndex (const GALGAS_uint & inIndex,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mLowTemporalBound ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList::setter_setMHighTemporalBoundAtIndex (GALGAS_uint inOperand,
                                                                     GALGAS_uint inIndex,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mHighTemporalBound = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeTransitionList::getter_mHighTemporalBoundAtIndex (const GALGAS_uint & inIndex,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) attributes.ptr () ;
  GALGAS_uint result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    result = p->mObject.mProperty_mHighTemporalBound ;
  }
  return result ;
}



//--------------------------------------------------------------------------------------------------

cEnumerator_typeTransitionList::cEnumerator_typeTransitionList (const GALGAS_typeTransitionList & inEnumeratedObject,
                                                                const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element cEnumerator_typeTransitionList::current (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_typeTransitionList::current_mTransitionName (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mTransitionName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cEnumerator_typeTransitionList::current_mPreconditionExpression (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mPreconditionExpression ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList cEnumerator_typeTransitionList::current_mPostconditionList (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mPostconditionList ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeTransitionList::current_mLowTemporalBound (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mLowTemporalBound ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint cEnumerator_typeTransitionList::current_mHighTemporalBound (LOCATION_ARGS) const {
  const cCollectionElement_typeTransitionList * p = (const cCollectionElement_typeTransitionList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
  return p->mObject.mProperty_mHighTemporalBound ;
}




//--------------------------------------------------------------------------------------------------
//
//     @typeTransitionList generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList ("typeTransitionList",
                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTransitionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTransitionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTransitionList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList GALGAS_typeTransitionList::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeTransitionList result ;
  const GALGAS_typeTransitionList * p = (const GALGAS_typeTransitionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeTransitionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Class for element of '@typeInitialMarkingList' list
//
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typeInitialMarkingList : public cCollectionElement {
  public: GALGAS_typeInitialMarkingList_2D_element mObject ;

//--- Class functions
  public: cCollectionElement_typeInitialMarkingList (const GALGAS_typePostcondition & in_mInitValue
                                                     COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typeInitialMarkingList (const GALGAS_typeInitialMarkingList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual ComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GALGAS_typePostcondition & in_mInitValue
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mInitValue) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GALGAS_typeInitialMarkingList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mInitValue) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement_typeInitialMarkingList::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_typeInitialMarkingList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_typeInitialMarkingList (mObject.mProperty_mInitValue COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement_typeInitialMarkingList::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mInitValue" ":") ;
  mObject.mProperty_mInitValue.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cCollectionElement_typeInitialMarkingList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_typeInitialMarkingList * operand = (cCollectionElement_typeInitialMarkingList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_typeInitialMarkingList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList::GALGAS_typeInitialMarkingList (void) :
AC_GALGAS_list () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList::GALGAS_typeInitialMarkingList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_typeInitialMarkingList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_typeInitialMarkingList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::enterElement (const GALGAS_typeInitialMarkingList_2D_element & inValue,
                                                  Compiler * /* inCompiler */
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeInitialMarkingList (inValue COMMA_THERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  appendObject (attributes) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::class_func_listWithValue (const GALGAS_typePostcondition & inOperand0
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                               const GALGAS_typePostcondition & in_mInitValue
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_typeInitialMarkingList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeInitialMarkingList (in_mInitValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::addAssign_operation (const GALGAS_typePostcondition & inOperand0
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typeInitialMarkingList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_append (const GALGAS_typePostcondition inOperand0,
                                                   Compiler * /* inCompiler */
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_typeInitialMarkingList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_insertAtIndex (const GALGAS_typePostcondition inOperand0,
                                                          const GALGAS_uint inInsertionIndex,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = nullptr ;
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_removeAtIndex (GALGAS_typePostcondition & outOperand0,
                                                          const GALGAS_uint inRemoveIndex,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
      if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_popFirst (GALGAS_typePostcondition & outOperand0,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_popLast (GALGAS_typePostcondition & outOperand0,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::method_first (GALGAS_typePostcondition & outOperand0,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::method_last (GALGAS_typePostcondition & outOperand0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    outOperand0 = p->mObject.mProperty_mInitValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::add_operation (const GALGAS_typeInitialMarkingList & inOperand,
                                                                            Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::class_func_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::class_func_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_typeInitialMarkingList result = GALGAS_typeInitialMarkingList::class_func_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::plusAssign_operation (const GALGAS_typeInitialMarkingList inOperand,
                                                          Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList::setter_setMInitValueAtIndex (GALGAS_typePostcondition inOperand,
                                                                 GALGAS_uint inIndex,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mInitValue = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition GALGAS_typeInitialMarkingList::getter_mInitValueAtIndex (const GALGAS_uint & inIndex,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) attributes.ptr () ;
  GALGAS_typePostcondition result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    result = p->mObject.mProperty_mInitValue ;
  }
  return result ;
}



//--------------------------------------------------------------------------------------------------

cEnumerator_typeInitialMarkingList::cEnumerator_typeInitialMarkingList (const GALGAS_typeInitialMarkingList & inEnumeratedObject,
                                                                        const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element cEnumerator_typeInitialMarkingList::current (LOCATION_ARGS) const {
  const cCollectionElement_typeInitialMarkingList * p = (const cCollectionElement_typeInitialMarkingList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
  return p->mObject ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_typePostcondition cEnumerator_typeInitialMarkingList::current_mInitValue (LOCATION_ARGS) const {
  const cCollectionElement_typeInitialMarkingList * p = (const cCollectionElement_typeInitialMarkingList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
  return p->mObject.mProperty_mInitValue ;
}




//--------------------------------------------------------------------------------------------------
//
//     @typeInitialMarkingList generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList ("typeInitialMarkingList",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInitialMarkingList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInitialMarkingList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInitialMarkingList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList GALGAS_typeInitialMarkingList::extractObject (const GALGAS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList result ;
  const GALGAS_typeInitialMarkingList * p = (const GALGAS_typeInitialMarkingList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeInitialMarkingList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//Class for element of '@countList' list
//
//--------------------------------------------------------------------------------------------------

class cCollectionElement_countList : public cCollectionElement {
  public: GALGAS_countList_2D_element mObject ;

//--- Class functions
  public: cCollectionElement_countList (const GALGAS_lstring & in_mName,
                                        const GALGAS_typePreconditionExpression & in_mCondition
                                        COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_countList (const GALGAS_countList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual ComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GALGAS_lstring & in_mName,
                                                            const GALGAS_typePreconditionExpression & in_mCondition
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mName, in_mCondition) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GALGAS_countList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_mName, inElement.mProperty_mCondition) {
}

//--------------------------------------------------------------------------------------------------

bool cCollectionElement_countList::isValid (void) const {
  return true ;
}

//--------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_countList::copy (void) {
  cCollectionElement * result = nullptr ;
  macroMyNew (result, cCollectionElement_countList (mObject.mProperty_mName, mObject.mProperty_mCondition COMMA_HERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cCollectionElement_countList::description (String & ioString, const int32_t inIndentation) const {
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mName" ":") ;
  mObject.mProperty_mName.description (ioString, inIndentation) ;
  ioString.appendNewLine () ;
  ioString.appendStringMultiple ("| ", inIndentation) ;
  ioString.appendCString ("mCondition" ":") ;
  mObject.mProperty_mCondition.description (ioString, inIndentation) ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult cCollectionElement_countList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_countList * operand = (cCollectionElement_countList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_countList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList::GALGAS_countList (void) :
AC_GALGAS_list () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList::GALGAS_countList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_countList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  return GALGAS_countList (capCollectionElementArray ()) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::enterElement (const GALGAS_countList_2D_element & inValue,
                                     Compiler * /* inCompiler */
                                     COMMA_LOCATION_ARGS) {
  cCollectionElement * p = nullptr ;
  macroMyNew (p, cCollectionElement_countList (inValue COMMA_THERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  appendObject (attributes) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::class_func_listWithValue (const GALGAS_lstring & inOperand0,
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

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const GALGAS_lstring & in_mName,
                                                  const GALGAS_typePreconditionExpression & in_mCondition
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = nullptr ;
  macroMyNew (p, cCollectionElement_countList (in_mName,
                                               in_mCondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::addAssign_operation (const GALGAS_lstring & inOperand0,
                                            const GALGAS_typePreconditionExpression & inOperand1
                                            COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_countList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_append (const GALGAS_lstring inOperand0,
                                      const GALGAS_typePreconditionExpression inOperand1,
                                      Compiler * /* inCompiler */
                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    cCollectionElement * p = nullptr ;
    macroMyNew (p, cCollectionElement_countList (inOperand0, inOperand1 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    appendObject (attributes) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                             const GALGAS_typePreconditionExpression inOperand1,
                                             const GALGAS_uint inInsertionIndex,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid () && inOperand1.isValid ()) {
      cCollectionElement * p = nullptr ;
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

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                             GALGAS_typePreconditionExpression & outOperand1,
                                             const GALGAS_uint inRemoveIndex,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
      if (nullptr == p) {
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

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_popFirst (GALGAS_lstring & outOperand0,
                                        GALGAS_typePreconditionExpression & outOperand1,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_popLast (GALGAS_lstring & outOperand0,
                                       GALGAS_typePreconditionExpression & outOperand1,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::method_first (GALGAS_lstring & outOperand0,
                                     GALGAS_typePreconditionExpression & outOperand1,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::method_last (GALGAS_lstring & outOperand0,
                                    GALGAS_typePreconditionExpression & outOperand1,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  if (nullptr == p) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_countList) ;
    outOperand0 = p->mObject.mProperty_mName ;
    outOperand1 = p->mObject.mProperty_mCondition ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::add_operation (const GALGAS_countList & inOperand,
                                                  Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_countList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListWithRange (const GALGAS_range & inRange,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::class_func_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::class_func_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const {
  GALGAS_countList result = GALGAS_countList::class_func_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::plusAssign_operation (const GALGAS_countList inOperand,
                                             Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_setMNameAtIndex (GALGAS_lstring inOperand,
                                               GALGAS_uint inIndex,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = (cCollectionElement_countList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mName = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_countList::getter_mNameAtIndex (const GALGAS_uint & inIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    result = p->mObject.mProperty_mName ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList::setter_setMConditionAtIndex (GALGAS_typePreconditionExpression inOperand,
                                                    GALGAS_uint inIndex,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = (cCollectionElement_countList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_mCondition = inOperand ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression GALGAS_countList::getter_mConditionAtIndex (const GALGAS_uint & inIndex,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_countList * p = (cCollectionElement_countList *) attributes.ptr () ;
  GALGAS_typePreconditionExpression result ;
  if (nullptr != p) {
    macroValidSharedObject (p, cCollectionElement_countList) ;
    result = p->mObject.mProperty_mCondition ;
  }
  return result ;
}



//--------------------------------------------------------------------------------------------------

cEnumerator_countList::cEnumerator_countList (const GALGAS_countList & inEnumeratedObject,
                                              const EnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element cEnumerator_countList::current (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject ;
}


//--------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_countList::current_mName (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject.mProperty_mName ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePreconditionExpression cEnumerator_countList::current_mCondition (LOCATION_ARGS) const {
  const cCollectionElement_countList * p = (const cCollectionElement_countList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_countList) ;
  return p->mObject.mProperty_mCondition ;
}




//--------------------------------------------------------------------------------------------------
//
//     @countList generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList ("countList",
                                                                 nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_countList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_countList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_countList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList GALGAS_countList::extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_countList result ;
  const GALGAS_countList * p = (const GALGAS_countList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_countList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                                            GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                            GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                                            Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 60)) ;
      GALGAS_typePreconditionExpression var_right_1818 ;
      nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_1818, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeOrExpression::init_21__21_ (outArgument_outPreConditions, var_right_1818, inCompiler COMMA_HERE) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_parse (Lexique_spec_5F_scanner * inCompiler) {
  nt_term_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 60)) ;
      nt_term_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_indexing (Lexique_spec_5F_scanner * inCompiler) {
  nt_term_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 60)) ;
      nt_term_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                           GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                           GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                           Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.ggs", 75)) ;
      GALGAS_typePreconditionExpression var_right_2251 ;
      nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_2251, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeAndExpression::init_21__21_ (outArgument_outPreConditions, var_right_2251, inCompiler COMMA_HERE) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_parse (Lexique_spec_5F_scanner * inCompiler) {
  nt_factor_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.ggs", 75)) ;
      nt_factor_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_indexing (Lexique_spec_5F_scanner * inCompiler) {
  nt_factor_indexing (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.ggs", 75)) ;
      nt_factor_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                             GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                             GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 88)) ;
    nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
    outArgument_outPreConditions = GALGAS_typeComplementExpression::init_21_ (outArgument_outPreConditions, inCompiler COMMA_HERE) ;
  } break ;
  case 2: {
    nt_primary_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_parse (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 88)) ;
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

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_indexing (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 88)) ;
    nt_factor_indexing (inCompiler) ;
  } break ;
  case 2: {
    nt_primary_indexing (inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_ (GALGAS_typeVarMap & ioArgument_inPlacesMap,
                                                              GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                              GALGAS_typePreconditionExpression & outArgument_outPreConditions,
                                                              Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("spec_parser.ggs", 103)) ;
    nt_parse_5F_precondition_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("spec_parser.ggs", 105)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_true COMMA_SOURCE_FILE ("spec_parser.ggs", 107)) ;
    outArgument_outPreConditions = GALGAS_typeTrueExpression::init (inCompiler COMMA_HERE) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.ggs", 110)) ;
    outArgument_outPreConditions = GALGAS_typeFalseExpression::init (inCompiler COMMA_HERE) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 113)) ;
    GALGAS_lstring var_name_3254 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 114)) ;
    GALGAS_uint var_idx_3299 ;
    ioArgument_inPlacesMap.method_searchKey (var_name_3254, var_idx_3299, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 115)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 117)) ;
      GALGAS_bool var_sign_3372 ;
      GALGAS_luint var_cst_3383 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3372, var_cst_3383, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeEqualExpression::init_21__21__21_ (var_idx_3299, var_sign_3372, var_cst_3383, inCompiler COMMA_HERE) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 121)) ;
      GALGAS_bool var_sign_3524 ;
      GALGAS_luint var_cst_3535 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3524, var_cst_3535, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeNonEqualExpression::init_21__21__21_ (var_idx_3299, var_sign_3524, var_cst_3535, inCompiler COMMA_HERE) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 125)) ;
      GALGAS_bool var_sign_3679 ;
      GALGAS_luint var_cst_3690 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3679, var_cst_3690, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeInfOrEqualExpression::init_21__21__21_ (var_idx_3299, var_sign_3679, var_cst_3690, inCompiler COMMA_HERE) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 129)) ;
      GALGAS_bool var_sign_3836 ;
      GALGAS_luint var_cst_3847 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3836, var_cst_3847, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeSupOrEqualExpression::init_21__21__21_ (var_idx_3299, var_sign_3836, var_cst_3847, inCompiler COMMA_HERE) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 133)) ;
      GALGAS_bool var_sign_3992 ;
      GALGAS_luint var_cst_4003 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3992, var_cst_4003, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeStrictInfExpression::init_21__21__21_ (var_idx_3299, var_sign_3992, var_cst_4003, inCompiler COMMA_HERE) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 137)) ;
      GALGAS_bool var_sign_4147 ;
      GALGAS_luint var_cst_4158 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_4147, var_cst_4158, inCompiler) ;
      outArgument_outPreConditions = GALGAS_typeStrictSupExpression::init_21__21__21_ (var_idx_3299, var_sign_4147, var_cst_4158, inCompiler COMMA_HERE) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 141)) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_parse (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("spec_parser.ggs", 103)) ;
    nt_parse_5F_precondition_parse (inCompiler) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("spec_parser.ggs", 105)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_true COMMA_SOURCE_FILE ("spec_parser.ggs", 107)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.ggs", 110)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 113)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 114)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 117)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 121)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 125)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 129)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 133)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 137)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 141)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_indexing (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("spec_parser.ggs", 103)) ;
    nt_parse_5F_precondition_indexing (inCompiler) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("spec_parser.ggs", 105)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_true COMMA_SOURCE_FILE ("spec_parser.ggs", 107)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.ggs", 110)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 113)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 114)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 117)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 121)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 125)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 129)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 133)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 137)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 141)) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_ (GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                        GALGAS_bool & outArgument_outSign,
                                                                        GALGAS_luint & outArgument_outValue,
                                                                        Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outSign.drop () ; // Release 'out' argument
  outArgument_outValue.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_constantName_4469 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 152)) ;
    ioArgument_ioConstantMap.method_searchKey (var_constantName_4469, outArgument_outSign, outArgument_outValue, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 153)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 155)) ;
    outArgument_outSign = GALGAS_bool (true) ;
    outArgument_outValue = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 157)) ;
  } break ;
  case 3: {
    outArgument_outSign = GALGAS_bool (false) ;
    outArgument_outValue = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 160)) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_parse (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 152)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 155)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 157)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 160)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_indexing (Lexique_spec_5F_scanner * inCompiler) {
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 152)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 155)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 157)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 160)) ;
  } break ;
  default:
    break ;
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_ (GALGAS_typeVarMap & ioArgument_outPlacesMap,
                                                                             GALGAS_typeCstMap & ioArgument_ioConstantMap,
                                                                             GALGAS_typePostconditionList & outArgument_outPostConditionsList,
                                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPostConditionsList.drop () ; // Release 'out' argument
  GALGAS_typePostconditionList temp_0 = GALGAS_typePostconditionList::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 170)) ;
  outArgument_outPostConditionsList = temp_0 ;
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    GALGAS_lstring var_name_4987 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 172)) ;
    GALGAS_uint var_idx_5033 ;
    ioArgument_outPlacesMap.method_searchKey (var_name_4987, var_idx_5033, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 173)) ;
    GALGAS_typePostcondition var_p_5065 ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 176)) ;
      var_p_5065 = GALGAS_typePostDecrement::init_21__21_ (var_name_4987, var_idx_5033, inCompiler COMMA_HERE) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 179)) ;
      var_p_5065 = GALGAS_typePostIncrement::init_21__21_ (var_name_4987, var_idx_5033, inCompiler COMMA_HERE) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 182)) ;
      GALGAS_bool var_sign_5269 ;
      GALGAS_luint var_cst_5280 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5269, var_cst_5280, inCompiler) ;
      var_p_5065 = GALGAS_typeAddConstant::init_21__21__21__21_ (var_name_4987, var_idx_5033, var_sign_5269, var_cst_5280, inCompiler COMMA_HERE) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 186)) ;
      GALGAS_bool var_sign_5409 ;
      GALGAS_luint var_cst_5420 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5409, var_cst_5420, inCompiler) ;
      var_p_5065 = GALGAS_typeSubConstant::init_21__21__21__21_ (var_name_4987, var_idx_5033, var_sign_5409, var_cst_5420, inCompiler COMMA_HERE) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 190)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        GALGAS_bool var_sign_5564 ;
        GALGAS_luint var_cst_5575 ;
        nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5564, var_cst_5575, inCompiler) ;
        var_p_5065 = GALGAS_typeAssignConstant::init_21__21__21__21_ (var_name_4987, var_idx_5033, var_sign_5564, var_cst_5575, inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 195)) ;
        var_p_5065 = GALGAS_typeAssignInfinity::init_21__21_ (var_name_4987, var_idx_5033, inCompiler COMMA_HERE) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    {
    outArgument_outPostConditionsList.setter_append (var_p_5065, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 199)) ;
    }
    if (select_spec_5F_parser_6 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 201)) ;
    }else{
      repeatFlag_1 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_parse (Lexique_spec_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 172)) ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 176)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 179)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 182)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 186)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 190)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        nt_parse_5F_constant_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 195)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_6 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 201)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_indexing (Lexique_spec_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 172)) ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 176)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 179)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 182)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 186)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 190)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        nt_parse_5F_constant_indexing (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 195)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_6 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 201)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_ (GALGAS_uint & outArgument_lowTemporalBound,
                                                                     GALGAS_uint & outArgument_highTemporalBound,
                                                                     Lexique_spec_5F_scanner * /* inCompiler */) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  outArgument_lowTemporalBound = GALGAS_uint (uint32_t (0U)) ;
  outArgument_highTemporalBound = GALGAS_uint (uint32_t (0U)) ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_parse (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_indexing (Lexique_spec_5F_scanner * /* inCompiler */) {
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_ (GALGAS_uint & outArgument_lowTemporalBound,
                                                                     GALGAS_uint & outArgument_highTemporalBound,
                                                                     Lexique_spec_5F_scanner * inCompiler) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 219)) ;
  GALGAS_luint var_low_6197 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 220)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 221)) ;
  GALGAS_luint var_high_6234 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 222)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 223)) ;
  outArgument_lowTemporalBound = var_low_6197.readProperty_uint () ;
  outArgument_highTemporalBound = var_high_6234.readProperty_uint () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (ComparisonKind::greaterThan, outArgument_lowTemporalBound.objectCompare (outArgument_highTemporalBound)).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (var_high_6234.readProperty_location (), GALGAS_string ("High bound must be greater than or equal to low bound"), fixItArray1  COMMA_SOURCE_FILE ("spec_parser.ggs", 227)) ;
    }
  }
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_parse (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 219)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 220)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 221)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 222)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 223)) ;
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_indexing (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 219)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 220)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 221)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 222)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 223)) ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_ (GALGAS_uint & outArgument_outHashMapSize,
                                                             GALGAS_uint & outArgument_outGarbagePeriod,
                                                             GALGAS_typeVarMap & outArgument_outPlacesMap,
                                                             GALGAS_typeTransitionList & outArgument_outTransitionList,
                                                             GALGAS_typeInitialMarkingList & outArgument_outInitialMarkingList,
                                                             GALGAS_countList & outArgument_outCountList,
                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outHashMapSize.drop () ; // Release 'out' argument
  outArgument_outGarbagePeriod.drop () ; // Release 'out' argument
  outArgument_outPlacesMap.drop () ; // Release 'out' argument
  outArgument_outTransitionList.drop () ; // Release 'out' argument
  outArgument_outInitialMarkingList.drop () ; // Release 'out' argument
  outArgument_outCountList.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 255)) ;
    GALGAS_luint var_n_7153 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 256)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 257)) ;
    outArgument_outHashMapSize = var_n_7153.readProperty_uint () ;
  } break ;
  case 2: {
    outArgument_outHashMapSize = GALGAS_uint (uint32_t (16U)) ;
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 263)) ;
    GALGAS_luint var_n_7284 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 264)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
    outArgument_outGarbagePeriod = var_n_7284.readProperty_uint () ;
  } break ;
  case 2: {
    outArgument_outGarbagePeriod = GALGAS_uint (uint32_t (16U)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_typeTransitionList temp_0 = GALGAS_typeTransitionList::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 270)) ;
  outArgument_outTransitionList = temp_0 ;
  GALGAS_typeVarMap temp_1 = GALGAS_typeVarMap::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 271)) ;
  outArgument_outPlacesMap = temp_1 ;
  GALGAS_typeCstMap temp_2 = GALGAS_typeCstMap::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 272)) ;
  GALGAS_typeCstMap var_constantMap_7445 = temp_2 ;
  GALGAS_countList temp_3 = GALGAS_countList::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 273)) ;
  outArgument_outCountList = temp_3 ;
  bool repeatFlag_4 = true ;
  while (repeatFlag_4) {
    switch (select_spec_5F_parser_11 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 277)) ;
      GALGAS_lstring var_constantName_7570 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 279)) ;
      GALGAS_bool var_sign_7634 ;
      GALGAS_luint var_value_7645 ;
      nt_parse_5F_constant_ (var_constantMap_7445, var_sign_7634, var_value_7645, inCompiler) ;
      {
      var_constantMap_7445.setter_insertKey (var_constantName_7570, var_sign_7634, var_value_7645, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 281)) ;
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 282)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 285)) ;
      bool repeatFlag_5 = true ;
      while (repeatFlag_5) {
        GALGAS_lstring var_placeName_7788 = inCompiler->synthetizedAttribute_theString () ;
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
        {
        outArgument_outPlacesMap.setter_insertKey (var_placeName_7788, outArgument_outPlacesMap.getter_count (SOURCE_FILE ("spec_parser.ggs", 288)), inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 288)) ;
        }
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 290)) ;
        }else{
          repeatFlag_5 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 292)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 295)) ;
      GALGAS_lstring var_transitionName_7959 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 296)) ;
      GALGAS_typePreconditionExpression var_preConditions_8037 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7445, var_preConditions_8037, inCompiler) ;
      GALGAS_uint var_lowTemporalBound_8076 ;
      GALGAS_uint var_highTemporalBound_8099 ;
      nt_parse_5F_bound_ (var_lowTemporalBound_8076, var_highTemporalBound_8099, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
      GALGAS_typePostconditionList var_postConditions_8189 ;
      nt_parse_5F_postcondition_ (outArgument_outPlacesMap, var_constantMap_7445, var_postConditions_8189, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 301)) ;
      {
      outArgument_outTransitionList.setter_append (var_transitionName_7959, var_preConditions_8037, var_postConditions_8189, var_lowTemporalBound_8076, var_highTemporalBound_8099, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 302)) ;
      }
    } break ;
    default:
      repeatFlag_4 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 311)) ;
  GALGAS_typeInitialMarkingList temp_6 = GALGAS_typeInitialMarkingList::init (inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 312)) ;
  outArgument_outInitialMarkingList = temp_6 ;
  bool repeatFlag_7 = true ;
  while (repeatFlag_7) {
    GALGAS_lstring var_placeName_8475 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 314)) ;
    GALGAS_uint var_placeID_8531 ;
    outArgument_outPlacesMap.method_searchKey (var_placeName_8475, var_placeID_8531, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 315)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 316)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      GALGAS_bool var_sign_8604 ;
      GALGAS_luint var_cst_8615 ;
      nt_parse_5F_constant_ (var_constantMap_7445, var_sign_8604, var_cst_8615, inCompiler) ;
      GALGAS_typePostcondition var_initValue_8649 = GALGAS_typeAssignConstant::init_21__21__21__21_ (var_placeName_8475, var_placeID_8531, var_sign_8604, var_cst_8615, inCompiler COMMA_HERE) ;
      {
      outArgument_outInitialMarkingList.setter_append (var_initValue_8649, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 320)) ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
      GALGAS_typePostcondition var_initValue_8825 = GALGAS_typeAssignInfinity::init_21__21_ (var_placeName_8475, var_placeID_8531, inCompiler COMMA_HERE) ;
      {
      outArgument_outInitialMarkingList.setter_append (var_initValue_8825, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 324)) ;
      }
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 327)) ;
    }else{
      repeatFlag_7 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 329)) ;
  bool repeatFlag_8 = true ;
  while (repeatFlag_8) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 333)) ;
      GALGAS_lstring var_name_9043 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 334)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 335)) ;
      GALGAS_typePreconditionExpression var_conditions_9119 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7445, var_conditions_9119, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 337)) ;
      {
      outArgument_outCountList.setter_append (var_name_9043, var_conditions_9119, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 338)) ;
      }
    }else{
      repeatFlag_8 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 340)) ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_parse (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 255)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 256)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 257)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 263)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 264)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
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
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 277)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 279)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 282)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 285)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 290)) ;
        }else{
          repeatFlag_1 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 292)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 295)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 296)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      nt_parse_5F_bound_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
      nt_parse_5F_postcondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 301)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 311)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 314)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 316)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 327)) ;
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 329)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 333)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 334)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 335)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 337)) ;
    }else{
      repeatFlag_3 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 340)) ;
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_indexing (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 255)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 256)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 257)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 263)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 264)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
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
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 277)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 279)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 282)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 285)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 290)) ;
        }else{
          repeatFlag_1 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 292)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 295)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 296)) ;
      nt_parse_5F_precondition_indexing (inCompiler) ;
      nt_parse_5F_bound_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
      nt_parse_5F_postcondition_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 301)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 311)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 314)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 316)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 327)) ;
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 329)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 333)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 334)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 335)) ;
      nt_parse_5F_precondition_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 337)) ;
    }else{
      repeatFlag_3 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 340)) ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::GALGAS_typePostconditionList_2D_element (void) :
mProperty_mPostcondition () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::~ GALGAS_typePostconditionList_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element GALGAS_typePostconditionList_2D_element::init_21_ (const GALGAS_typePostcondition & in_mPostcondition,
                                                                                           Compiler * inCompiler
                                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typePostconditionList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mPostcondition = in_mPostcondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element::GALGAS_typePostconditionList_2D_element (const GALGAS_typePostcondition & inOperand0) :
mProperty_mPostcondition (inOperand0) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element GALGAS_typePostconditionList_2D_element::class_func_new (const GALGAS_typePostcondition & in_mPostcondition,
                                                                                                 Compiler * inCompiler
                                                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typePostconditionList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mPostcondition = in_mPostcondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typePostconditionList_2D_element::objectCompare (const GALGAS_typePostconditionList_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mPostcondition.objectCompare (inOperand.mProperty_mPostcondition) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typePostconditionList_2D_element::isValid (void) const {
  return mProperty_mPostcondition.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList_2D_element::drop (void) {
  mProperty_mPostcondition.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostconditionList_2D_element::description (String & ioString,
                                                           const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typePostconditionList-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mPostcondition.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typePostconditionList-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList_2D_element ("typePostconditionList-element",
                                                                                        nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostconditionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostconditionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostconditionList_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostconditionList_2D_element GALGAS_typePostconditionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typePostconditionList_2D_element result ;
  const GALGAS_typePostconditionList_2D_element * p = (const GALGAS_typePostconditionList_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostconditionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::GALGAS_typeInitialMarkingList_2D_element (void) :
mProperty_mInitValue () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::~ GALGAS_typeInitialMarkingList_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element GALGAS_typeInitialMarkingList_2D_element::init_21_ (const GALGAS_typePostcondition & in_mInitValue,
                                                                                             Compiler * inCompiler
                                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mInitValue = in_mInitValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element::GALGAS_typeInitialMarkingList_2D_element (const GALGAS_typePostcondition & inOperand0) :
mProperty_mInitValue (inOperand0) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element GALGAS_typeInitialMarkingList_2D_element::class_func_new (const GALGAS_typePostcondition & in_mInitValue,
                                                                                                   Compiler * inCompiler
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mInitValue = in_mInitValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeInitialMarkingList_2D_element::objectCompare (const GALGAS_typeInitialMarkingList_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mInitValue.objectCompare (inOperand.mProperty_mInitValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeInitialMarkingList_2D_element::isValid (void) const {
  return mProperty_mInitValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList_2D_element::drop (void) {
  mProperty_mInitValue.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInitialMarkingList_2D_element::description (String & ioString,
                                                            const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeInitialMarkingList-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mInitValue.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeInitialMarkingList-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ("typeInitialMarkingList-element",
                                                                                         nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInitialMarkingList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInitialMarkingList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInitialMarkingList_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInitialMarkingList_2D_element GALGAS_typeInitialMarkingList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typeInitialMarkingList_2D_element result ;
  const GALGAS_typeInitialMarkingList_2D_element * p = (const GALGAS_typeInitialMarkingList_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeInitialMarkingList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeEqualExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeEqualExpression::cPtr_typeEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeEqualExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeEqualExpression * p = (const cPtr_typeEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeEqualExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeEqualExpression::objectCompare (const GALGAS_typeEqualExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression::GALGAS_typeEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeEqualExpression::
typeEqualExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                      const GALGAS_bool & in_mNegativeConstant,
                                      const GALGAS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression::GALGAS_typeEqualExpression (const cPtr_typeEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                       const GALGAS_bool & in_mNegativeConstant,
                                                                       const GALGAS_luint & in_mConstant
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_typeEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeEqualExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeEqualExpression::cPtr_typeEqualExpression (const GALGAS_uint & in_mVar,
                                                    const GALGAS_bool & in_mNegativeConstant,
                                                    const GALGAS_luint & in_mConstant
                                                    COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression ;
}

void cPtr_typeEqualExpression::description (String & ioString,
                                            const int32_t inIndentation) const {
  ioString.appendCString ("[@typeEqualExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeEqualExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression ("typeEqualExpression",
                                                                           & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeEqualExpression GALGAS_typeEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_typeEqualExpression result ;
  const GALGAS_typeEqualExpression * p = (const GALGAS_typeEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeNonEqualExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeNonEqualExpression::cPtr_typeNonEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeNonEqualExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeNonEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeNonEqualExpression * p = (const cPtr_typeNonEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeNonEqualExpression::objectCompare (const GALGAS_typeNonEqualExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression::GALGAS_typeNonEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeNonEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeNonEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeNonEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeNonEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeNonEqualExpression::
typeNonEqualExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                         const GALGAS_bool & in_mNegativeConstant,
                                         const GALGAS_luint & in_mConstant,
                                         Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression::GALGAS_typeNonEqualExpression (const cPtr_typeNonEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeNonEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                             const GALGAS_bool & in_mNegativeConstant,
                                                                             const GALGAS_luint & in_mConstant
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeNonEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeNonEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeNonEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeNonEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeNonEqualExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeNonEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeNonEqualExpression::cPtr_typeNonEqualExpression (const GALGAS_uint & in_mVar,
                                                          const GALGAS_bool & in_mNegativeConstant,
                                                          const GALGAS_luint & in_mConstant
                                                          COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeNonEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression ;
}

void cPtr_typeNonEqualExpression::description (String & ioString,
                                               const int32_t inIndentation) const {
  ioString.appendCString ("[@typeNonEqualExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeNonEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeNonEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeNonEqualExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression ("typeNonEqualExpression",
                                                                              & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeNonEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeNonEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeNonEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeNonEqualExpression GALGAS_typeNonEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_typeNonEqualExpression result ;
  const GALGAS_typeNonEqualExpression * p = (const GALGAS_typeNonEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeNonEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeNonEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeInfOrEqualExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeInfOrEqualExpression::cPtr_typeInfOrEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeInfOrEqualExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeInfOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeInfOrEqualExpression * p = (const cPtr_typeInfOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeInfOrEqualExpression::objectCompare (const GALGAS_typeInfOrEqualExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression::GALGAS_typeInfOrEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeInfOrEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeInfOrEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeInfOrEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeInfOrEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeInfOrEqualExpression::
typeInfOrEqualExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                           const GALGAS_bool & in_mNegativeConstant,
                                           const GALGAS_luint & in_mConstant,
                                           Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression::GALGAS_typeInfOrEqualExpression (const cPtr_typeInfOrEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeInfOrEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                                 const GALGAS_bool & in_mNegativeConstant,
                                                                                 const GALGAS_luint & in_mConstant
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeInfOrEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeInfOrEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeInfOrEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeInfOrEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeInfOrEqualExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeInfOrEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeInfOrEqualExpression::cPtr_typeInfOrEqualExpression (const GALGAS_uint & in_mVar,
                                                              const GALGAS_bool & in_mNegativeConstant,
                                                              const GALGAS_luint & in_mConstant
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeInfOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;
}

void cPtr_typeInfOrEqualExpression::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@typeInfOrEqualExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeInfOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeInfOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeInfOrEqualExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression ("typeInfOrEqualExpression",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeInfOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeInfOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeInfOrEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeInfOrEqualExpression GALGAS_typeInfOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeInfOrEqualExpression result ;
  const GALGAS_typeInfOrEqualExpression * p = (const GALGAS_typeInfOrEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeInfOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInfOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeSupOrEqualExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeSupOrEqualExpression::cPtr_typeSupOrEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeSupOrEqualExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeSupOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeSupOrEqualExpression * p = (const cPtr_typeSupOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeSupOrEqualExpression::objectCompare (const GALGAS_typeSupOrEqualExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression::GALGAS_typeSupOrEqualExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeSupOrEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeSupOrEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeSupOrEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeSupOrEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeSupOrEqualExpression::
typeSupOrEqualExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                           const GALGAS_bool & in_mNegativeConstant,
                                           const GALGAS_luint & in_mConstant,
                                           Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression::GALGAS_typeSupOrEqualExpression (const cPtr_typeSupOrEqualExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSupOrEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                                 const GALGAS_bool & in_mNegativeConstant,
                                                                                 const GALGAS_luint & in_mConstant
                                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeSupOrEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeSupOrEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeSupOrEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeSupOrEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSupOrEqualExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeSupOrEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeSupOrEqualExpression::cPtr_typeSupOrEqualExpression (const GALGAS_uint & in_mVar,
                                                              const GALGAS_bool & in_mNegativeConstant,
                                                              const GALGAS_luint & in_mConstant
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeSupOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;
}

void cPtr_typeSupOrEqualExpression::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@typeSupOrEqualExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeSupOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeSupOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeSupOrEqualExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression ("typeSupOrEqualExpression",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSupOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSupOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSupOrEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSupOrEqualExpression GALGAS_typeSupOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_typeSupOrEqualExpression result ;
  const GALGAS_typeSupOrEqualExpression * p = (const GALGAS_typeSupOrEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeSupOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSupOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeStrictInfExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictInfExpression::cPtr_typeStrictInfExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeStrictInfExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeStrictInfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeStrictInfExpression * p = (const cPtr_typeStrictInfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeStrictInfExpression::objectCompare (const GALGAS_typeStrictInfExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression::GALGAS_typeStrictInfExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeStrictInfExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeStrictInfExpression (inCompiler COMMA_THERE)) ;
  object->typeStrictInfExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeStrictInfExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeStrictInfExpression::
typeStrictInfExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                          const GALGAS_bool & in_mNegativeConstant,
                                          const GALGAS_luint & in_mConstant,
                                          Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression::GALGAS_typeStrictInfExpression (const cPtr_typeStrictInfExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictInfExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                               const GALGAS_bool & in_mNegativeConstant,
                                                                               const GALGAS_luint & in_mConstant
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeStrictInfExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeStrictInfExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeStrictInfExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeStrictInfExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictInfExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictInfExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictInfExpression::cPtr_typeStrictInfExpression (const GALGAS_uint & in_mVar,
                                                            const GALGAS_bool & in_mNegativeConstant,
                                                            const GALGAS_luint & in_mConstant
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeStrictInfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression ;
}

void cPtr_typeStrictInfExpression::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("[@typeStrictInfExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeStrictInfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeStrictInfExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeStrictInfExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression ("typeStrictInfExpression",
                                                                               & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictInfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictInfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictInfExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictInfExpression GALGAS_typeStrictInfExpression::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictInfExpression result ;
  const GALGAS_typeStrictInfExpression * p = (const GALGAS_typeStrictInfExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeStrictInfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictInfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeStrictSupExpression reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictSupExpression::cPtr_typeStrictSupExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeStrictSupExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeStrictSupExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeStrictSupExpression * p = (const cPtr_typeStrictSupExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeStrictSupExpression::objectCompare (const GALGAS_typeStrictSupExpression & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression::GALGAS_typeStrictSupExpression (void) :
GALGAS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::
init_21__21__21_ (const GALGAS_uint & in_mVar,
                  const GALGAS_bool & in_mNegativeConstant,
                  const GALGAS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeStrictSupExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeStrictSupExpression (inCompiler COMMA_THERE)) ;
  object->typeStrictSupExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeStrictSupExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeStrictSupExpression::
typeStrictSupExpression_init_21__21__21_ (const GALGAS_uint & in_mVar,
                                          const GALGAS_bool & in_mNegativeConstant,
                                          const GALGAS_luint & in_mConstant,
                                          Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression::GALGAS_typeStrictSupExpression (const cPtr_typeStrictSupExpression * inSourcePtr) :
GALGAS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictSupExpression) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::class_func_new (const GALGAS_uint & in_mVar,
                                                                               const GALGAS_bool & in_mNegativeConstant,
                                                                               const GALGAS_luint & in_mConstant
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeStrictSupExpression (in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeStrictSupExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeStrictSupExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeStrictSupExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeStrictSupExpression::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictSupExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictSupExpression::cPtr_typeStrictSupExpression (const GALGAS_uint & in_mVar,
                                                            const GALGAS_bool & in_mNegativeConstant,
                                                            const GALGAS_luint & in_mConstant
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeStrictSupExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression ;
}

void cPtr_typeStrictSupExpression::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("[@typeStrictSupExpression:") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeStrictSupExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeStrictSupExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeStrictSupExpression generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression ("typeStrictSupExpression",
                                                                               & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeStrictSupExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeStrictSupExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeStrictSupExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeStrictSupExpression GALGAS_typeStrictSupExpression::extractObject (const GALGAS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeStrictSupExpression result ;
  const GALGAS_typeStrictSupExpression * p = (const GALGAS_typeStrictSupExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeStrictSupExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictSupExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typePostIncrement reference class
//--------------------------------------------------------------------------------------------------

cPtr_typePostIncrement::cPtr_typePostIncrement (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePostIncrement::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typePostIncrement::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typePostIncrement * p = (const cPtr_typePostIncrement *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typePostIncrement) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typePostIncrement::objectCompare (const GALGAS_typePostIncrement & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement::GALGAS_typePostIncrement (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::
init_21__21_ (const GALGAS_lstring & in_mVarName,
              const GALGAS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typePostIncrement * object = nullptr ;
  macroMyNew (object, cPtr_typePostIncrement (inCompiler COMMA_THERE)) ;
  object->typePostIncrement_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GALGAS_typePostIncrement result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typePostIncrement::
typePostIncrement_init_21__21_ (const GALGAS_lstring & in_mVarName,
                                const GALGAS_uint & in_mVar,
                                Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement::GALGAS_typePostIncrement (const cPtr_typePostIncrement * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostIncrement) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::class_func_new (const GALGAS_lstring & in_mVarName,
                                                                   const GALGAS_uint & in_mVar
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_typePostIncrement result ;
  macroMyNew (result.mObjectPtr, cPtr_typePostIncrement (in_mVarName, in_mVar COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typePostIncrement::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostIncrement::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typePostIncrement::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostIncrement::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostIncrement class
//--------------------------------------------------------------------------------------------------

cPtr_typePostIncrement::cPtr_typePostIncrement (const GALGAS_lstring & in_mVarName,
                                                const GALGAS_uint & in_mVar
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typePostIncrement::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement ;
}

void cPtr_typePostIncrement::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("[@typePostIncrement:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typePostIncrement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typePostIncrement (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typePostIncrement generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement ("typePostIncrement",
                                                                         & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostIncrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostIncrement::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostIncrement (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostIncrement GALGAS_typePostIncrement::extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostIncrement result ;
  const GALGAS_typePostIncrement * p = (const GALGAS_typePostIncrement *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostIncrement *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostIncrement", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typePostDecrement reference class
//--------------------------------------------------------------------------------------------------

cPtr_typePostDecrement::cPtr_typePostDecrement (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePostDecrement::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typePostDecrement::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typePostDecrement * p = (const cPtr_typePostDecrement *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typePostDecrement) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typePostDecrement::objectCompare (const GALGAS_typePostDecrement & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement::GALGAS_typePostDecrement (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::
init_21__21_ (const GALGAS_lstring & in_mVarName,
              const GALGAS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typePostDecrement * object = nullptr ;
  macroMyNew (object, cPtr_typePostDecrement (inCompiler COMMA_THERE)) ;
  object->typePostDecrement_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GALGAS_typePostDecrement result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typePostDecrement::
typePostDecrement_init_21__21_ (const GALGAS_lstring & in_mVarName,
                                const GALGAS_uint & in_mVar,
                                Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement::GALGAS_typePostDecrement (const cPtr_typePostDecrement * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostDecrement) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::class_func_new (const GALGAS_lstring & in_mVarName,
                                                                   const GALGAS_uint & in_mVar
                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_typePostDecrement result ;
  macroMyNew (result.mObjectPtr, cPtr_typePostDecrement (in_mVarName, in_mVar COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typePostDecrement::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostDecrement::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typePostDecrement::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typePostDecrement::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostDecrement class
//--------------------------------------------------------------------------------------------------

cPtr_typePostDecrement::cPtr_typePostDecrement (const GALGAS_lstring & in_mVarName,
                                                const GALGAS_uint & in_mVar
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typePostDecrement::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement ;
}

void cPtr_typePostDecrement::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("[@typePostDecrement:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typePostDecrement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typePostDecrement (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typePostDecrement generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement ("typePostDecrement",
                                                                         & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typePostDecrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typePostDecrement::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typePostDecrement (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typePostDecrement GALGAS_typePostDecrement::extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_typePostDecrement result ;
  const GALGAS_typePostDecrement * p = (const GALGAS_typePostDecrement *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typePostDecrement *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostDecrement", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeAddConstant reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeAddConstant::cPtr_typeAddConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeAddConstant::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeAddConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeAddConstant * p = (const cPtr_typeAddConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAddConstant) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeAddConstant::objectCompare (const GALGAS_typeAddConstant & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant::GALGAS_typeAddConstant (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::
init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                      const GALGAS_uint & in_mVar,
                      const GALGAS_bool & in_mNegativeConstant,
                      const GALGAS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeAddConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeAddConstant (inCompiler COMMA_THERE)) ;
  object->typeAddConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeAddConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::
typeAddConstant_init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                                      const GALGAS_uint & in_mVar,
                                      const GALGAS_bool & in_mNegativeConstant,
                                      const GALGAS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant::GALGAS_typeAddConstant (const cPtr_typeAddConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAddConstant) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::class_func_new (const GALGAS_lstring & in_mVarName,
                                                               const GALGAS_uint & in_mVar,
                                                               const GALGAS_bool & in_mNegativeConstant,
                                                               const GALGAS_luint & in_mConstant
                                                               COMMA_LOCATION_ARGS) {
  GALGAS_typeAddConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAddConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAddConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAddConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeAddConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeAddConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAddConstant::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAddConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeAddConstant::cPtr_typeAddConstant (const GALGAS_lstring & in_mVarName,
                                            const GALGAS_uint & in_mVar,
                                            const GALGAS_bool & in_mNegativeConstant,
                                            const GALGAS_luint & in_mConstant
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAddConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant ;
}

void cPtr_typeAddConstant::description (String & ioString,
                                        const int32_t inIndentation) const {
  ioString.appendCString ("[@typeAddConstant:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAddConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAddConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeAddConstant generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant ("typeAddConstant",
                                                                       & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAddConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAddConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAddConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAddConstant GALGAS_typeAddConstant::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeAddConstant result ;
  const GALGAS_typeAddConstant * p = (const GALGAS_typeAddConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAddConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAddConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeSubConstant reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeSubConstant::cPtr_typeSubConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeSubConstant::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeSubConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeSubConstant * p = (const cPtr_typeSubConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeSubConstant) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeSubConstant::objectCompare (const GALGAS_typeSubConstant & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant::GALGAS_typeSubConstant (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::
init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                      const GALGAS_uint & in_mVar,
                      const GALGAS_bool & in_mNegativeConstant,
                      const GALGAS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeSubConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeSubConstant (inCompiler COMMA_THERE)) ;
  object->typeSubConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeSubConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::
typeSubConstant_init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                                      const GALGAS_uint & in_mVar,
                                      const GALGAS_bool & in_mNegativeConstant,
                                      const GALGAS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant::GALGAS_typeSubConstant (const cPtr_typeSubConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSubConstant) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::class_func_new (const GALGAS_lstring & in_mVarName,
                                                               const GALGAS_uint & in_mVar,
                                                               const GALGAS_bool & in_mNegativeConstant,
                                                               const GALGAS_luint & in_mConstant
                                                               COMMA_LOCATION_ARGS) {
  GALGAS_typeSubConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeSubConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeSubConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeSubConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeSubConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeSubConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeSubConstant::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeSubConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeSubConstant::cPtr_typeSubConstant (const GALGAS_lstring & in_mVarName,
                                            const GALGAS_uint & in_mVar,
                                            const GALGAS_bool & in_mNegativeConstant,
                                            const GALGAS_luint & in_mConstant
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeSubConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant ;
}

void cPtr_typeSubConstant::description (String & ioString,
                                        const int32_t inIndentation) const {
  ioString.appendCString ("[@typeSubConstant:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeSubConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeSubConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeSubConstant generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant ("typeSubConstant",
                                                                       & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeSubConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeSubConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeSubConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeSubConstant GALGAS_typeSubConstant::extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_typeSubConstant result ;
  const GALGAS_typeSubConstant * p = (const GALGAS_typeSubConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeSubConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSubConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeAssignConstant reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignConstant::cPtr_typeAssignConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeAssignConstant::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
    mProperty_mNegativeConstant.printNonNullClassInstanceProperties ("mNegativeConstant") ;
    mProperty_mConstant.printNonNullClassInstanceProperties ("mConstant") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeAssignConstant::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeAssignConstant * p = (const cPtr_typeAssignConstant *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAssignConstant) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mNegativeConstant.objectCompare (p->mProperty_mNegativeConstant) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mConstant.objectCompare (p->mProperty_mConstant) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeAssignConstant::objectCompare (const GALGAS_typeAssignConstant & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant::GALGAS_typeAssignConstant (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::
init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                      const GALGAS_uint & in_mVar,
                      const GALGAS_bool & in_mNegativeConstant,
                      const GALGAS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeAssignConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeAssignConstant (inCompiler COMMA_THERE)) ;
  object->typeAssignConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GALGAS_typeAssignConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::
typeAssignConstant_init_21__21__21__21_ (const GALGAS_lstring & in_mVarName,
                                         const GALGAS_uint & in_mVar,
                                         const GALGAS_bool & in_mNegativeConstant,
                                         const GALGAS_luint & in_mConstant,
                                         Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant::GALGAS_typeAssignConstant (const cPtr_typeAssignConstant * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignConstant) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::class_func_new (const GALGAS_lstring & in_mVarName,
                                                                     const GALGAS_uint & in_mVar,
                                                                     const GALGAS_bool & in_mNegativeConstant,
                                                                     const GALGAS_luint & in_mConstant
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAssignConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAssignConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAssignConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_typeAssignConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setProperty_mNegativeConstant (const GALGAS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_luint GALGAS_typeAssignConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_luint () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignConstant::setProperty_mConstant (const GALGAS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignConstant::cPtr_typeAssignConstant (const GALGAS_lstring & in_mVarName,
                                                  const GALGAS_uint & in_mVar,
                                                  const GALGAS_bool & in_mNegativeConstant,
                                                  const GALGAS_luint & in_mConstant
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAssignConstant::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant ;
}

void cPtr_typeAssignConstant::description (String & ioString,
                                           const int32_t inIndentation) const {
  ioString.appendCString ("[@typeAssignConstant:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mNegativeConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mConstant.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAssignConstant::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAssignConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeAssignConstant generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant ("typeAssignConstant",
                                                                          & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignConstant GALGAS_typeAssignConstant::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignConstant result ;
  const GALGAS_typeAssignConstant * p = (const GALGAS_typeAssignConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAssignConstant *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignConstant", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeAssignInfinity reference class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignInfinity::cPtr_typeAssignInfinity (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeAssignInfinity::printNonNullClassInstanceProperties (void) const {
    cPtr_typePostcondition::printNonNullClassInstanceProperties () ;
    mProperty_mVarName.printNonNullClassInstanceProperties ("mVarName") ;
    mProperty_mVar.printNonNullClassInstanceProperties ("mVar") ;
  }
#endif

//--------------------------------------------------------------------------------------------------

ComparisonResult cPtr_typeAssignInfinity::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  ComparisonResult result = ComparisonResult::operandEqual ;
  const cPtr_typeAssignInfinity * p = (const cPtr_typeAssignInfinity *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVarName.objectCompare (p->mProperty_mVarName) ;
  }
  if (ComparisonResult::operandEqual == result) {
    result = mProperty_mVar.objectCompare (p->mProperty_mVar) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------


ComparisonResult GALGAS_typeAssignInfinity::objectCompare (const GALGAS_typeAssignInfinity & inOperand) const {
  ComparisonResult result = ComparisonResult::invalid ;
  if (isValid () && inOperand.isValid ()) {
    const size_t myObjectPtr = size_t (mObjectPtr) ;
    const size_t operandObjectPtr = size_t (inOperand.mObjectPtr) ;
    if (myObjectPtr < operandObjectPtr) {
      result = ComparisonResult::firstOperandLowerThanSecond ;
    }else if (myObjectPtr > operandObjectPtr) {
      result = ComparisonResult::firstOperandGreaterThanSecond ;
    }else{
      result = ComparisonResult::operandEqual ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity::GALGAS_typeAssignInfinity (void) :
GALGAS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::
init_21__21_ (const GALGAS_lstring & in_mVarName,
              const GALGAS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeAssignInfinity * object = nullptr ;
  macroMyNew (object, cPtr_typeAssignInfinity (inCompiler COMMA_THERE)) ;
  object->typeAssignInfinity_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GALGAS_typeAssignInfinity result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAssignInfinity::
typeAssignInfinity_init_21__21_ (const GALGAS_lstring & in_mVarName,
                                 const GALGAS_uint & in_mVar,
                                 Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity::GALGAS_typeAssignInfinity (const cPtr_typeAssignInfinity * inSourcePtr) :
GALGAS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignInfinity) ;
}
//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::class_func_new (const GALGAS_lstring & in_mVarName,
                                                                     const GALGAS_uint & in_mVar
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignInfinity result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAssignInfinity (in_mVarName, in_mVar COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_typeAssignInfinity::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignInfinity::setProperty_mVarName (const GALGAS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_typeAssignInfinity::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeAssignInfinity::setProperty_mVar (const GALGAS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignInfinity class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignInfinity::cPtr_typeAssignInfinity (const GALGAS_lstring & in_mVarName,
                                                  const GALGAS_uint & in_mVar
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_typeAssignInfinity::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity ;
}

void cPtr_typeAssignInfinity::description (String & ioString,
                                           const int32_t inIndentation) const {
  ioString.appendCString ("[@typeAssignInfinity:") ;
  mProperty_mVarName.description (ioString, inIndentation+1) ;
  ioString.appendCString (", ") ;
  mProperty_mVar.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeAssignInfinity::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAssignInfinity (mProperty_mVarName, mProperty_mVar COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------
//
//     @typeAssignInfinity generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity ("typeAssignInfinity",
                                                                          & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeAssignInfinity::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeAssignInfinity::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeAssignInfinity (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeAssignInfinity GALGAS_typeAssignInfinity::extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_typeAssignInfinity result ;
  const GALGAS_typeAssignInfinity * p = (const GALGAS_typeAssignInfinity *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeAssignInfinity *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignInfinity", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

#include "MF_MemoryControl.h"
#include "C_galgas_CLI_Options.h"

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//                                     LL(1) PRODUCTION RULES                                       
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductions_spec_grammar [] = {
// At index 0 : <axiome>, in file 'spec_parser.ggs', line 245
  TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_system) // $system$
, TOP_DOWN_NONTERMINAL (17) // <select_spec_5F_parser_9>
, TOP_DOWN_NONTERMINAL (18) // <select_spec_5F_parser_10>
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_init) // $init$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (22) // <select_spec_5F_parser_14>
, TOP_DOWN_NONTERMINAL (21) // <select_spec_5F_parser_13>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (23) // <select_spec_5F_parser_15>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
// At index 13 : <parse_precondition>, in file 'spec_parser.ggs', line 53
, TOP_DOWN_NONTERMINAL (2) // <term>
, TOP_DOWN_NONTERMINAL (8) // <select_spec_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 16 : <term>, in file 'spec_parser.ggs', line 68
, TOP_DOWN_NONTERMINAL (3) // <factor>
, TOP_DOWN_NONTERMINAL (9) // <select_spec_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 19 : <factor>, in file 'spec_parser.ggs', line 83
, TOP_DOWN_NONTERMINAL (10) // <select_spec_5F_parser_2>
, TOP_DOWN_END_PRODUCTION ()
// At index 21 : <primary>, in file 'spec_parser.ggs', line 98
, TOP_DOWN_NONTERMINAL (11) // <select_spec_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 23 : <parse_postcondition>, in file 'spec_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (15) // <select_spec_5F_parser_7>
, TOP_DOWN_NONTERMINAL (14) // <select_spec_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 27 : <parse_constant>, in file 'spec_parser.ggs', line 147
, TOP_DOWN_NONTERMINAL (13) // <select_spec_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 29 : <parse_bound>, in file 'spec_parser.ggs', line 207
, TOP_DOWN_END_PRODUCTION ()
// At index 30 : <parse_bound>, in file 'spec_parser.ggs', line 216
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
//---- Added productions from 'select' and 'repeat' instructions
// At index 36 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
, TOP_DOWN_END_PRODUCTION ()
// At index 37 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__7C_) // $|$
, TOP_DOWN_NONTERMINAL (2) // <term>
, TOP_DOWN_NONTERMINAL (8) // <select_spec_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 41 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 73
, TOP_DOWN_END_PRODUCTION ()
// At index 42 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__26_) // $&$
, TOP_DOWN_NONTERMINAL (3) // <factor>
, TOP_DOWN_NONTERMINAL (9) // <select_spec_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 46 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 87
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__7E_) // $~$
, TOP_DOWN_NONTERMINAL (3) // <factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 49 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 87
, TOP_DOWN_NONTERMINAL (4) // <primary>
, TOP_DOWN_END_PRODUCTION ()
// At index 51 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (1) // <parse_precondition>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 55 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_true) // $true$
, TOP_DOWN_END_PRODUCTION ()
// At index 57 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_false) // $false$
, TOP_DOWN_END_PRODUCTION ()
// At index 59 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__7B_) // ${$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (12) // <select_spec_5F_parser_4>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__7D_) // $}$
, TOP_DOWN_END_PRODUCTION ()
// At index 64 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3D__3D_) // $==$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 67 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__21__3D_) // $!=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 70 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3C__3D_) // $<=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 73 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3E__3D_) // $>=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 76 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3C_) // $<$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 79 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3E_) // $>$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 82 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 84 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2D_) // $-$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 87 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_END_PRODUCTION ()
// At index 89 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 171
, TOP_DOWN_END_PRODUCTION ()
// At index 90 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 171
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (15) // <select_spec_5F_parser_7>
, TOP_DOWN_NONTERMINAL (14) // <select_spec_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 95 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2D__2D_) // $--$
, TOP_DOWN_END_PRODUCTION ()
// At index 97 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2B__2B_) // $++$
, TOP_DOWN_END_PRODUCTION ()
// At index 99 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2B__3D_) // $+=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 102 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2D__3D_) // $-=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 105 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (16) // <select_spec_5F_parser_8>
, TOP_DOWN_END_PRODUCTION ()
// At index 108 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 191
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 110 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 191
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_infinity) // $infinity$
, TOP_DOWN_END_PRODUCTION ()
// At index 112 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 254
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_hashmapsize) // $hashmapsize$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_END_PRODUCTION ()
// At index 116 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 254
, TOP_DOWN_END_PRODUCTION ()
// At index 117 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_garbageperiod) // $garbageperiod$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_END_PRODUCTION ()
// At index 121 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_END_PRODUCTION ()
// At index 122 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_END_PRODUCTION ()
// At index 123 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_const) // $const$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3D_) // $=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 130 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_var) // $var$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (20) // <select_spec_5F_parser_12>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 136 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_rule) // $rule$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_string) // $literal_string$
, TOP_DOWN_NONTERMINAL (1) // <parse_precondition>
, TOP_DOWN_NONTERMINAL (7) // <parse_bound>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (5) // <parse_postcondition>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 145 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 286
, TOP_DOWN_END_PRODUCTION ()
// At index 146 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 286
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (20) // <select_spec_5F_parser_12>
, TOP_DOWN_END_PRODUCTION ()
// At index 150 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 313
, TOP_DOWN_END_PRODUCTION ()
// At index 151 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 313
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (22) // <select_spec_5F_parser_14>
, TOP_DOWN_NONTERMINAL (21) // <select_spec_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 157 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 317
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 159 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 317
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_infinity) // $infinity$
, TOP_DOWN_END_PRODUCTION ()
// At index 161 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 331
, TOP_DOWN_END_PRODUCTION ()
// At index 162 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 331
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_count) // $count$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_string) // $literal_string$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (1) // <parse_precondition>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (23) // <select_spec_5F_parser_15>
, TOP_DOWN_END_PRODUCTION ()
// At index 169 : <>, in file '.ggs', line 0
, TOP_DOWN_NONTERMINAL (0) // <axiome>
, TOP_DOWN_END_PRODUCTION ()
} ;

//--------------------------------------------------------------------------------------------------
//
//                                P R O D U C T I O N    N A M E S                                  
//
//--------------------------------------------------------------------------------------------------

static const ProductionNameDescriptor gProductionNames_spec_grammar [54] = {
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

//--------------------------------------------------------------------------------------------------
//
//                       L L ( 1 )    P R O D U C T I O N    I N D E X E S                          
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductionIndexes_spec_grammar [54] = {
0, // index 0 : <axiome>, in file 'spec_parser.ggs', line 245
13, // index 1 : <parse_precondition>, in file 'spec_parser.ggs', line 53
16, // index 2 : <term>, in file 'spec_parser.ggs', line 68
19, // index 3 : <factor>, in file 'spec_parser.ggs', line 83
21, // index 4 : <primary>, in file 'spec_parser.ggs', line 98
23, // index 5 : <parse_postcondition>, in file 'spec_parser.ggs', line 166
27, // index 6 : <parse_constant>, in file 'spec_parser.ggs', line 147
29, // index 7 : <parse_bound>, in file 'spec_parser.ggs', line 207
30, // index 8 : <parse_bound>, in file 'spec_parser.ggs', line 216
36, // index 9 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
37, // index 10 : <select_spec_5F_parser_0>, in file 'spec_parser.ggs', line 58
41, // index 11 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 73
42, // index 12 : <select_spec_5F_parser_1>, in file 'spec_parser.ggs', line 73
46, // index 13 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 87
49, // index 14 : <select_spec_5F_parser_2>, in file 'spec_parser.ggs', line 87
51, // index 15 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
55, // index 16 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
57, // index 17 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
59, // index 18 : <select_spec_5F_parser_3>, in file 'spec_parser.ggs', line 102
64, // index 19 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
67, // index 20 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
70, // index 21 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
73, // index 22 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
76, // index 23 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
79, // index 24 : <select_spec_5F_parser_4>, in file 'spec_parser.ggs', line 116
82, // index 25 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
84, // index 26 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
87, // index 27 : <select_spec_5F_parser_5>, in file 'spec_parser.ggs', line 151
89, // index 28 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 171
90, // index 29 : <select_spec_5F_parser_6>, in file 'spec_parser.ggs', line 171
95, // index 30 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
97, // index 31 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
99, // index 32 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
102, // index 33 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
105, // index 34 : <select_spec_5F_parser_7>, in file 'spec_parser.ggs', line 175
108, // index 35 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 191
110, // index 36 : <select_spec_5F_parser_8>, in file 'spec_parser.ggs', line 191
112, // index 37 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 254
116, // index 38 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 254
117, // index 39 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 262
121, // index 40 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 262
122, // index 41 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
123, // index 42 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
130, // index 43 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
136, // index 44 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 274
145, // index 45 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 286
146, // index 46 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 286
150, // index 47 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 313
151, // index 48 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 313
157, // index 49 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 317
159, // index 50 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 317
161, // index 51 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 331
162, // index 52 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 331
169 // index 53 : <>, in file '.ggs', line 0
} ;

//--------------------------------------------------------------------------------------------------
//
//                 L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                   
//
//--------------------------------------------------------------------------------------------------

static const int32_t gFirstProductionIndexes_spec_grammar [26] = {
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

//--------------------------------------------------------------------------------------------------
//
//                          L L ( 1 )    D E C I S I O N    T A B L E S                             
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecision_spec_grammar [] = {
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
Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 12 : <select_spec_5F_parser_0>
Lexique_spec_5F_scanner::kToken__29_, Lexique_spec_5F_scanner::kToken__5B_, Lexique_spec_5F_scanner::kToken__3B_, Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__7C_, -1, // Choice 2
  -1,
// At index 20 : <select_spec_5F_parser_1>
Lexique_spec_5F_scanner::kToken__7C_, Lexique_spec_5F_scanner::kToken__29_, Lexique_spec_5F_scanner::kToken__5B_, Lexique_spec_5F_scanner::kToken__3B_, Lexique_spec_5F_scanner::kToken__3A_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 29 : <select_spec_5F_parser_2>
Lexique_spec_5F_scanner::kToken__7E_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__28_, Lexique_spec_5F_scanner::kToken_true, Lexique_spec_5F_scanner::kToken_false, Lexique_spec_5F_scanner::kToken__7B_, -1, // Choice 2
  -1,
// At index 37 : <select_spec_5F_parser_3>
Lexique_spec_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_true, -1, // Choice 2
Lexique_spec_5F_scanner::kToken_false, -1, // Choice 3
Lexique_spec_5F_scanner::kToken__7B_, -1, // Choice 4
  -1,
// At index 46 : <select_spec_5F_parser_4>
Lexique_spec_5F_scanner::kToken__3D__3D_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__21__3D_, -1, // Choice 2
Lexique_spec_5F_scanner::kToken__3C__3D_, -1, // Choice 3
Lexique_spec_5F_scanner::kToken__3E__3D_, -1, // Choice 4
Lexique_spec_5F_scanner::kToken__3C_, -1, // Choice 5
Lexique_spec_5F_scanner::kToken__3E_, -1, // Choice 6
  -1,
// At index 59 : <select_spec_5F_parser_5>
Lexique_spec_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__2D_, -1, // Choice 2
Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 3
  -1,
// At index 66 : <select_spec_5F_parser_6>
Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 71 : <select_spec_5F_parser_7>
Lexique_spec_5F_scanner::kToken__2D__2D_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__2B__2B_, -1, // Choice 2
Lexique_spec_5F_scanner::kToken__2B__3D_, -1, // Choice 3
Lexique_spec_5F_scanner::kToken__2D__3D_, -1, // Choice 4
Lexique_spec_5F_scanner::kToken__3A__3D_, -1, // Choice 5
  -1,
// At index 82 : <select_spec_5F_parser_8>
Lexique_spec_5F_scanner::kToken_identifier, Lexique_spec_5F_scanner::kToken__2D_, Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_infinity, -1, // Choice 2
  -1,
// At index 89 : <select_spec_5F_parser_9>
Lexique_spec_5F_scanner::kToken_hashmapsize, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_garbageperiod, Lexique_spec_5F_scanner::kToken_const, Lexique_spec_5F_scanner::kToken_var, Lexique_spec_5F_scanner::kToken_rule, Lexique_spec_5F_scanner::kToken_init, -1, // Choice 2
  -1,
// At index 98 : <select_spec_5F_parser_10>
Lexique_spec_5F_scanner::kToken_garbageperiod, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_const, Lexique_spec_5F_scanner::kToken_var, Lexique_spec_5F_scanner::kToken_rule, Lexique_spec_5F_scanner::kToken_init, -1, // Choice 2
  -1,
// At index 106 : <select_spec_5F_parser_11>
Lexique_spec_5F_scanner::kToken_init, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_const, -1, // Choice 2
Lexique_spec_5F_scanner::kToken_var, -1, // Choice 3
Lexique_spec_5F_scanner::kToken_rule, -1, // Choice 4
  -1,
// At index 115 : <select_spec_5F_parser_12>
Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 120 : <select_spec_5F_parser_13>
Lexique_spec_5F_scanner::kToken__3B_, -1, // Choice 1
Lexique_spec_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 125 : <select_spec_5F_parser_14>
Lexique_spec_5F_scanner::kToken_identifier, Lexique_spec_5F_scanner::kToken__2D_, Lexique_spec_5F_scanner::kToken_literal_5F_integer, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_infinity, -1, // Choice 2
  -1,
// At index 132 : <select_spec_5F_parser_15>
Lexique_spec_5F_scanner::kToken_end, -1, // Choice 1
Lexique_spec_5F_scanner::kToken_count, -1, // Choice 2
  -1,
// At index 137 : <> only one production, no choice
  -1,
0} ;

//--------------------------------------------------------------------------------------------------
//
//                  L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                    
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecisionIndexes_spec_grammar [26] = {
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

//--------------------------------------------------------------------------------------------------
//
//                              'axiome' non terminal implementation                                
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_axiome_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_axiome_i8_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_axiome_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_axiome_i8_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_axiome_ (GALGAS_uint & parameter_1,
                                GALGAS_uint & parameter_2,
                                GALGAS_typeVarMap & parameter_3,
                                GALGAS_typeTransitionList & parameter_4,
                                GALGAS_typeInitialMarkingList & parameter_5,
                                GALGAS_countList & parameter_6,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_axiome_i8_(parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, inLexique) ;
}

void cGrammar_spec_5F_grammar::performIndexing (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_spec_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_spec_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                                    gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
    if (ok) {
      cGrammar_spec_5F_grammar grammar ;
      grammar.nt_axiome_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_spec_5F_grammar::performOnlyLexicalAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_spec_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_spec_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_spec_5F_grammar::performOnlySyntaxAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_spec_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_spec_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                    gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
  }
  macroDetachSharedObject (scanner) ;
}

//--------------------------------------------------------------------------------------------------
//
//                              Grammar start symbol implementation                                 
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::_performSourceFileParsing_ (Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_uint &  parameter_1,
                                GALGAS_uint &  parameter_2,
                                GALGAS_typeVarMap &  parameter_3,
                                GALGAS_typeTransitionList &  parameter_4,
                                GALGAS_typeInitialMarkingList &  parameter_5,
                                GALGAS_countList &  parameter_6
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    String filePath = filePathAsString.stringValue () ;
    if (! FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (FileManager::fileExistsAtPath (filePath)) {
    Lexique_spec_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_spec_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                                      gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_spec_5F_grammar grammar ;
        grammar.nt_axiome_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, scanner) ;
        }
      }else{
        String message ;
        message.appendString ("the '") ;
        message.appendString (filePath) ;
        message.appendString ("' file exists, but cannot be read") ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      String message ;
      message.appendString ("the '") ;
      message.appendString (filePath) ;
      message.appendString ("' file does not exist") ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <FixItDescription> () COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::_performSourceStringParsing_ (Compiler * inCompiler,
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
    const String sourceString = inSourceString.stringValue () ;
    const String nameString = inNameString.stringValue () ;
    Lexique_spec_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_spec_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_spec_grammar, gProductionNames_spec_grammar, gProductionIndexes_spec_grammar,
                                                    gFirstProductionIndexes_spec_grammar, gDecision_spec_grammar, gDecisionIndexes_spec_grammar, 169) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_spec_5F_grammar grammar ;
      grammar.nt_axiome_ (parameter_1, parameter_2, parameter_3, parameter_4, parameter_5, parameter_6, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                        'parse_precondition' non terminal implementation                          
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_precondition_i0_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_precondition_i0_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_precondition_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                               'term' non terminal implementation                                 
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_term_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_term_i1_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_term_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_term_i1_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_term_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_term_i1_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                              'factor' non terminal implementation                                
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_factor_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_factor_i2_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_factor_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_factor_i2_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_factor_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_factor_i2_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                             'primary' non terminal implementation                                
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_primary_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_primary_i3_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_primary_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_primary_i3_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_primary_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePreconditionExpression & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_primary_i3_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                       'parse_postcondition' non terminal implementation                          
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_postcondition_i5_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_postcondition_i5_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_ (GALGAS_typeVarMap & parameter_1,
                                GALGAS_typeCstMap & parameter_2,
                                GALGAS_typePostconditionList & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_postcondition_i5_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                          'parse_constant' non terminal implementation                            
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_parse (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_constant_i4_parse(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_indexing (Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_constant_i4_indexing(inLexique) ;
}

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_ (GALGAS_typeCstMap & parameter_1,
                                GALGAS_bool & parameter_2,
                                GALGAS_luint & parameter_3,
                                Lexique_spec_5F_scanner * inLexique) {
  rule_spec_5F_parser_parse_5F_constant_i4_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                           'parse_bound' non terminal implementation                              
//
//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_parse (Lexique_spec_5F_scanner * inLexique) {
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

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_indexing (Lexique_spec_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_spec_5F_parser_parse_5F_bound_i6_indexing(inLexique) ;
    break ;
  case 2 :
    rule_spec_5F_parser_parse_5F_bound_i7_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_ (GALGAS_uint & parameter_1,
                                GALGAS_uint & parameter_2,
                                Lexique_spec_5F_scanner * inLexique) {
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

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_0' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_0 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_1' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_1 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_2' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_2 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_3' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_3 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_4' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_4 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_5' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_5 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_6' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_6 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_7' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_7 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_8' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_8 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_9' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_9 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_10' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_10 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_11' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_11 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_12' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_12 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_13' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_13 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_14' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_14 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_spec_5F_parser_15' added non terminal implementation                    
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_spec_5F_grammar::select_spec_5F_parser_15 (Lexique_spec_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::GALGAS__32_lstringlist_2D_element (void) :
mProperty_mValue_30_ (),
mProperty_mValue_31_ () {
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::~ GALGAS__32_lstringlist_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::init_21__21_ (const GALGAS_lstring & in_mValue_30_,
                                                                                   const GALGAS_lstring & in_mValue_31_,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS__32_lstringlist_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue_30_ ;
  result.mProperty_mValue_31_ = in_mValue_31_ ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element::GALGAS__32_lstringlist_2D_element (const GALGAS_lstring & inOperand0,
                                                                      const GALGAS_lstring & inOperand1) :
mProperty_mValue_30_ (inOperand0),
mProperty_mValue_31_ (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::class_func_new (const GALGAS_lstring & in_mValue0,
                                                                                     const GALGAS_lstring & in_mValue1,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS__32_lstringlist_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue0 ;
  result.mProperty_mValue_31_ = in_mValue1 ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS__32_lstringlist_2D_element::objectCompare (const GALGAS__32_lstringlist_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mValue_30_.objectCompare (inOperand.mProperty_mValue_30_) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mValue_31_.objectCompare (inOperand.mProperty_mValue_31_) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS__32_lstringlist_2D_element::isValid (void) const {
  return mProperty_mValue_30_.isValid () && mProperty_mValue_31_.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist_2D_element::drop (void) {
  mProperty_mValue_30_.drop () ;
  mProperty_mValue_31_.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS__32_lstringlist_2D_element::description (String & ioString,
                                                     const int32_t inIndentation) const {
  ioString.appendCString ("<struct @2lstringlist-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mValue_30_.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mValue_31_.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @2lstringlist-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist_2D_element ("2lstringlist-element",
                                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS__32_lstringlist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS__32_lstringlist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS__32_lstringlist_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS__32_lstringlist_2D_element GALGAS__32_lstringlist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS__32_lstringlist_2D_element result ;
  const GALGAS__32_lstringlist_2D_element * p = (const GALGAS__32_lstringlist_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS__32_lstringlist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::GALGAS_typeVarMap_2D_element (void) :
mProperty_lkey (),
mProperty_mIndex () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::~ GALGAS_typeVarMap_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::init_21__21_ (const GALGAS_lstring & in_lkey,
                                                                         const GALGAS_uint & in_mIndex,
                                                                         Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeVarMap_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element::GALGAS_typeVarMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_uint & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::class_func_new (const GALGAS_lstring & in_lkey,
                                                                           const GALGAS_uint & in_mIndex,
                                                                           Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeVarMap_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeVarMap_2D_element::objectCompare (const GALGAS_typeVarMap_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mIndex.objectCompare (inOperand.mProperty_mIndex) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeVarMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeVarMap_2D_element::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeVarMap-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mIndex.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeVarMap-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap_2D_element ("typeVarMap-element",
                                                                             nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeVarMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeVarMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeVarMap_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeVarMap_2D_element GALGAS_typeVarMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeVarMap_2D_element result ;
  const GALGAS_typeVarMap_2D_element * p = (const GALGAS_typeVarMap_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeVarMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::GALGAS_typeCstMap_2D_element (void) :
mProperty_lkey (),
mProperty_mSign (),
mProperty_mValue () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::~ GALGAS_typeCstMap_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::init_21__21__21_ (const GALGAS_lstring & in_lkey,
                                                                             const GALGAS_bool & in_mSign,
                                                                             const GALGAS_luint & in_mValue,
                                                                             Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeCstMap_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mSign = in_mSign ;
  result.mProperty_mValue = in_mValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element::GALGAS_typeCstMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_bool & inOperand1,
                                                            const GALGAS_luint & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_mSign (inOperand1),
mProperty_mValue (inOperand2) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::class_func_new (const GALGAS_lstring & in_lkey,
                                                                           const GALGAS_bool & in_mSign,
                                                                           const GALGAS_luint & in_mValue,
                                                                           Compiler * inCompiler
                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeCstMap_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mSign = in_mSign ;
  result.mProperty_mValue = in_mValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeCstMap_2D_element::objectCompare (const GALGAS_typeCstMap_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mSign.objectCompare (inOperand.mProperty_mSign) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mValue.objectCompare (inOperand.mProperty_mValue) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeCstMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mSign.isValid () && mProperty_mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mSign.drop () ;
  mProperty_mValue.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeCstMap_2D_element::description (String & ioString,
                                                const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeCstMap-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mSign.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mValue.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeCstMap-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap_2D_element ("typeCstMap-element",
                                                                             nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeCstMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeCstMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeCstMap_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeCstMap_2D_element GALGAS_typeCstMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeCstMap_2D_element result ;
  const GALGAS_typeCstMap_2D_element * p = (const GALGAS_typeCstMap_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeCstMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element::GALGAS_typeTransitionList_2D_element (void) :
mProperty_mTransitionName (),
mProperty_mPreconditionExpression (),
mProperty_mPostconditionList (),
mProperty_mLowTemporalBound (),
mProperty_mHighTemporalBound () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element::~ GALGAS_typeTransitionList_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element GALGAS_typeTransitionList_2D_element::init_21__21__21__21__21_ (const GALGAS_lstring & in_mTransitionName,
                                                                                                     const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                                                                     const GALGAS_typePostconditionList & in_mPostconditionList,
                                                                                                     const GALGAS_uint & in_mLowTemporalBound,
                                                                                                     const GALGAS_uint & in_mHighTemporalBound,
                                                                                                     Compiler * inCompiler
                                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeTransitionList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mTransitionName = in_mTransitionName ;
  result.mProperty_mPreconditionExpression = in_mPreconditionExpression ;
  result.mProperty_mPostconditionList = in_mPostconditionList ;
  result.mProperty_mLowTemporalBound = in_mLowTemporalBound ;
  result.mProperty_mHighTemporalBound = in_mHighTemporalBound ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element GALGAS_typeTransitionList_2D_element::class_func_new (const GALGAS_lstring & in_mTransitionName,
                                                                                           const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                                                           const GALGAS_typePostconditionList & in_mPostconditionList,
                                                                                           const GALGAS_uint & in_mLowTemporalBound,
                                                                                           const GALGAS_uint & in_mHighTemporalBound,
                                                                                           Compiler * inCompiler
                                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_typeTransitionList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mTransitionName = in_mTransitionName ;
  result.mProperty_mPreconditionExpression = in_mPreconditionExpression ;
  result.mProperty_mPostconditionList = in_mPostconditionList ;
  result.mProperty_mLowTemporalBound = in_mLowTemporalBound ;
  result.mProperty_mHighTemporalBound = in_mHighTemporalBound ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_typeTransitionList_2D_element::objectCompare (const GALGAS_typeTransitionList_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mTransitionName.objectCompare (inOperand.mProperty_mTransitionName) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mPreconditionExpression.objectCompare (inOperand.mProperty_mPreconditionExpression) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mPostconditionList.objectCompare (inOperand.mProperty_mPostconditionList) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mLowTemporalBound.objectCompare (inOperand.mProperty_mLowTemporalBound) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mHighTemporalBound.objectCompare (inOperand.mProperty_mHighTemporalBound) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_typeTransitionList_2D_element::isValid (void) const {
  return mProperty_mTransitionName.isValid () && mProperty_mPreconditionExpression.isValid () && mProperty_mPostconditionList.isValid () && mProperty_mLowTemporalBound.isValid () && mProperty_mHighTemporalBound.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList_2D_element::drop (void) {
  mProperty_mTransitionName.drop () ;
  mProperty_mPreconditionExpression.drop () ;
  mProperty_mPostconditionList.drop () ;
  mProperty_mLowTemporalBound.drop () ;
  mProperty_mHighTemporalBound.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_typeTransitionList_2D_element::description (String & ioString,
                                                        const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeTransitionList-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mTransitionName.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPreconditionExpression.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mPostconditionList.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mLowTemporalBound.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mHighTemporalBound.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @typeTransitionList-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList_2D_element ("typeTransitionList-element",
                                                                                     nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_typeTransitionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_typeTransitionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_typeTransitionList_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_typeTransitionList_2D_element GALGAS_typeTransitionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_typeTransitionList_2D_element result ;
  const GALGAS_typeTransitionList_2D_element * p = (const GALGAS_typeTransitionList_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_typeTransitionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::GALGAS_countList_2D_element (void) :
mProperty_mName (),
mProperty_mCondition () {
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::~ GALGAS_countList_2D_element (void) {
}

//---Synthetized initializer -----------------------------------------------------------------------

GALGAS_countList_2D_element GALGAS_countList_2D_element::init_21__21_ (const GALGAS_lstring & in_mName,
                                                                       const GALGAS_typePreconditionExpression & in_mCondition,
                                                                       Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_countList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mName = in_mName ;
  result.mProperty_mCondition = in_mCondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList_2D_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element::GALGAS_countList_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_typePreconditionExpression & inOperand1) :
mProperty_mName (inOperand0),
mProperty_mCondition (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element GALGAS_countList_2D_element::class_func_new (const GALGAS_lstring & in_mName,
                                                                         const GALGAS_typePreconditionExpression & in_mCondition,
                                                                         Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_countList_2D_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mName = in_mName ;
  result.mProperty_mCondition = in_mCondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GALGAS_countList_2D_element::objectCompare (const GALGAS_countList_2D_element & inOperand) const {
   ComparisonResult result = ComparisonResult::operandEqual ;
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mName.objectCompare (inOperand.mProperty_mName) ;
  }
  if (result == ComparisonResult::operandEqual) {
    result = mProperty_mCondition.objectCompare (inOperand.mProperty_mCondition) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GALGAS_countList_2D_element::isValid (void) const {
  return mProperty_mName.isValid () && mProperty_mCondition.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList_2D_element::drop (void) {
  mProperty_mName.drop () ;
  mProperty_mCondition.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GALGAS_countList_2D_element::description (String & ioString,
                                               const int32_t inIndentation) const {
  ioString.appendCString ("<struct @countList-element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mName.description (ioString, inIndentation+1) ;
    ioString.appendCString (", ") ;
    mProperty_mCondition.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//
//     @countList-element generic code implementation
//
//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList_2D_element ("countList-element",
                                                                            nullptr) ;

//--------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_countList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList_2D_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_countList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_countList_2D_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GALGAS_countList_2D_element GALGAS_countList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_countList_2D_element result ;
  const GALGAS_countList_2D_element * p = (const GALGAS_countList_2D_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_countList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

BoolCommandLineOption gOption_spec_5F_options_doNotPrintIteration ("spec_options",
                                         "doNotPrintIteration",
                                         68,
                                         "do-not-print-iterations-message",
                                         "do not print a message for every iteration") ;

BoolCommandLineOption gOption_spec_5F_options_computeSimultaneousFiring ("spec_options",
                                         "computeSimultaneousFiring",
                                         0,
                                         "simultaneous-firing",
                                         "perform simultaneous firing") ;

BoolCommandLineOption gOption_spec_5F_options_printNodes ("spec_options",
                                         "printNodes",
                                         78,
                                         "print-nodes",
                                         "print accessibility set nodes") ;

BoolCommandLineOption gOption_spec_5F_options_printStates ("spec_options",
                                         "printStates",
                                         83,
                                         "print-states",
                                         "print accessibility states") ;

BoolCommandLineOption gOption_spec_5F_options_printInference ("spec_options",
                                         "printInference",
                                         0,
                                         "print-inference",
                                         "print inference expression for each transition") ;

BoolCommandLineOption gOption_spec_5F_options_printMinMax ("spec_options",
                                         "printMinMax",
                                         112,
                                         "print-min-maxs",
                                         "print min and max value for each variable") ;

BoolCommandLineOption gOption_spec_5F_options_printPreConditions ("spec_options",
                                         "printPreConditions",
                                         80,
                                         "print-preconditions",
                                         "print precondition expression for each transition") ;

BoolCommandLineOption gOption_spec_5F_options_printIterationStates ("spec_options",
                                         "printIterationStates",
                                         105,
                                         "print-iterations-states",
                                         "print source and target states for each transition of every iteration") ;

BoolCommandLineOption gOption_spec_5F_options_printTemporalBounds ("spec_options",
                                         "printTemporalBounds",
                                         116,
                                         "print-temporal-bounds",
                                         "print temporal bounds for each transition") ;

BoolCommandLineOption gOption_spec_5F_options_printFiring ("spec_options",
                                         "printFiring",
                                         102,
                                         "print-transitions-firing-count",
                                         "print transitions firing count") ;

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

UIntCommandLineOption gOption_spec_5F_options_stopAfterIteration ("spec_options",
                                         "stopAfterIteration",
                                         115,
                                         "stop-after-iteration",
                                         "stop after performing given iterations (0 means never stop)",
                                         0) ;

//--------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------


#include "project_header.h"
#include "F_mainForLIBPM.h"
#include "analyzeCommandLineOptions.h"
#include "builtin-command-line-options.h"
#include "C_galgas_CLI_Options.h"
#include "F_verbose_output.h"
#include "cLexiqueIntrospection.h"
#include "F_DisplayException.h"

//--------------------------------------------------------------------------------------------------
//                      print_tool_help_message                                                  
//--------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  gCout.appendCString ("Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n") ;
}

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "mg",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.mg' source file",
  nullptr
} ;    

//--------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "0.0.1" ;
}

//--------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//--------------------------------------------------------------------------------------------------

static void routine_before (Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//--------------------------------------------------------------------------------------------------

static void routine_after (Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//--------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_hashMapSize_539 ;
  GALGAS_uint var_garbagePeriod_561 ;
  GALGAS_typeVarMap var_placesMap_585 ;
  GALGAS_typeTransitionList var_transitionList_605 ;
  GALGAS_typeInitialMarkingList var_initialMarkingList_630 ;
  GALGAS_countList var_countList_659 ;
  var_hashMapSize_539.drop () ;
  var_garbagePeriod_561.drop () ;
  var_placesMap_585.drop () ;
  var_transitionList_605.drop () ;
  var_initialMarkingList_630.drop () ;
  var_countList_659.drop () ;
  cGrammar_spec_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_hashMapSize_539, var_garbagePeriod_561, var_placesMap_585, var_transitionList_605, var_initialMarkingList_630, var_countList_659  COMMA_SOURCE_FILE ("spec_main.ggs", 11)) ;
  {
  routine_generate_5F_code_3F__3F__3F__3F__3F__3F_ (var_hashMapSize_539, var_garbagePeriod_561, var_placesMap_585, var_transitionList_605, var_initialMarkingList_630, var_countList_659, inCompiler  COMMA_SOURCE_FILE ("spec_main.ggs", 19)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//--------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <String> sourceFilesArray ;
  analyzeCommandLineOptions (inArgc, inArgv,
                             sourceFilesArray,
                             kSourceFileExtensions,
                             kSourceFileHelpMessages,
                             print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    gCout.appendString (executionModeOptionErrorMessage) ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    Compiler * commonCompiler = nullptr ;
    macroMyNew (commonCompiler, Compiler (nullptr COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
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
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString ()) ;
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
        String message ;
        if (totalWarningCount () == 0) {
          message.appendCString ("No warning") ;
        }else if (totalWarningCount () == 1) {
          message.appendCString ("1 warning") ;
        }else{
          message.appendSigned (totalWarningCount ()) ;
          message.appendCString (" warnings") ;
        }
        message.appendCString (", ") ;
        if (totalErrorCount () == 0) {
          message.appendCString ("no error") ;
        }else if (totalErrorCount () == 1) {
          message.appendCString ("1 error") ;
        }else{
          message.appendSigned (totalErrorCount ()) ;
          message.appendCString (" errors") ;
        }
        message.appendCString (".\n") ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std::exception & e) {
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

