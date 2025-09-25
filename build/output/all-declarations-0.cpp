#include "Compiler.h"
#include "galgas-input-output.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-0.h"

//--------------------------------------------------------------------------------------------------
//Class for element of '@_32_lstringlist' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement__32_lstringlist : public cCollectionElement {
  public: GGS__32_lstringlist_2E_element mObject ;

//--- Class functions
  public: cCollectionElement__32_lstringlist (const GGS_lstring & in_mValue_30_,
                                              const GGS_lstring & in_mValue_31_
                                              COMMA_LOCATION_ARGS) ;
  public: cCollectionElement__32_lstringlist (const GGS__32_lstringlist_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GGS_lstring & in_mValue_30_,
                                                                        const GGS_lstring & in_mValue_31_
                                                                        COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mValue_30_, in_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement__32_lstringlist::cCollectionElement__32_lstringlist (const GGS__32_lstringlist_2E_element & inElement COMMA_LOCATION_ARGS) :
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
// List type @_32_lstringlist
//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist::GGS__32_lstringlist (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist::GGS__32_lstringlist (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement__32_lstringlist * p = (cCollectionElement__32_lstringlist *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement__32_lstringlist) ;
    const GGS__32_lstringlist_2E_element element (p->mObject.mProperty_mValue_30_, p->mObject.mProperty_mValue_31_) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                     const GGS_lstring & in_mValue_30_,
                                                     const GGS_lstring & in_mValue_31_
                                                     COMMA_LOCATION_ARGS) {
  cCollectionElement__32_lstringlist * p = nullptr ;
  macroMyNew (p, cCollectionElement__32_lstringlist (in_mValue_30_, in_mValue_31_ COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS__32_lstringlist::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS__32_lstringlist::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::description (String & ioString,
                                       const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mValue0:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mValue_30_.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mValue1:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mValue_31_.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::plusPlusAssignOperation (const GGS__32_lstringlist_2E_element & inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::class_func_listWithValue (const GGS_lstring & inOperand0,
                                                                   const GGS_lstring & inOperand1
                                                                   COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element element (inOperand0, inOperand1) ;
  GGS__32_lstringlist result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::addAssignOperation (const GGS_lstring & inOperand0,
                                              const GGS_lstring & inOperand1
                                              COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_append (const GGS_lstring inOperand0,
                                         const GGS_lstring inOperand1,
                                         Compiler * /* inCompiler */
                                         COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_insertAtIndex (const GGS_lstring inOperand0,
                                                const GGS_lstring inOperand1,
                                                const GGS_uint inInsertionIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  const GGS__32_lstringlist_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_removeAtIndex (GGS_lstring & outOperand0,
                                                GGS_lstring & outOperand1,
                                                const GGS_uint inRemoveIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (idx COMMA_HERE).mProperty_mValue_31_ ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_popFirst (GGS_lstring & outOperand0,
                                           GGS_lstring & outOperand1,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mValue_31_ ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_popLast (GGS_lstring & outOperand0,
                                          GGS_lstring & outOperand1,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mValue_31_ ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::method_first (GGS_lstring & outOperand0,
                                        GGS_lstring & outOperand1,
                                        Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mValue_30_ ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mValue_31_ ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::method_last (GGS_lstring & outOperand0,
                                       GGS_lstring & outOperand1,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mValue_30_ ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mValue_31_ ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::add_operation (const GGS__32_lstringlist & inOperand,
                                                        Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::subList (const int32_t inStart,
                                                  const int32_t inLength,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListWithRange (const GGS_range & inRange,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListFromIndex (const GGS_uint & inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::getter_subListToIndex (const GGS_uint & inIndex,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GGS__32_lstringlist result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::plusAssignOperation (const GGS__32_lstringlist inList,
                                               Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_setMValue_30_AtIndex (GGS_lstring inOperand,
                                                       GGS_uint inIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_30_ = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS__32_lstringlist::getter_mValue_30_AtIndex (const GGS_uint & inIndex,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_30_ ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist::setter_setMValue_31_AtIndex (GGS_lstring inOperand,
                                                       GGS_uint inIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_31_ = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS__32_lstringlist::getter_mValue_31_AtIndex (const GGS_uint & inIndex,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mValue_31_ ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @_32_lstringlist
//--------------------------------------------------------------------------------------------------

DownEnumerator__32_lstringlist::DownEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element DownEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_30_ ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_31_ ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @_32_lstringlist
//--------------------------------------------------------------------------------------------------

UpEnumerator__32_lstringlist::UpEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element UpEnumerator__32_lstringlist::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator__32_lstringlist::current_mValue_30_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_30_ ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator__32_lstringlist::current_mValue_31_ (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mValue_31_ ;
}




//--------------------------------------------------------------------------------------------------
//     @2lstringlist generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS__32_lstringlist ("2lstringlist",
                                                                    nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS__32_lstringlist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS__32_lstringlist::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS__32_lstringlist (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist GGS__32_lstringlist::extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GGS__32_lstringlist result ;
  const GGS__32_lstringlist * p = (const GGS__32_lstringlist *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS__32_lstringlist *> (p)) {
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
#include "LexiqueIntrospection.h"

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

GGS_lstring Lexique_spec_5F_scanner::synthetizedAttribute_theString (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GGS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GGS_string value (ptr->mLexicalAttribute_theString) ;
  GGS_lstring result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint Lexique_spec_5F_scanner::synthetizedAttribute_ulongValue (void) const {
  cTokenFor_spec_5F_scanner * ptr = (cTokenFor_spec_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_spec_5F_scanner) ;
  GGS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GGS_uint value (ptr->mLexicalAttribute_ulongValue) ;
  GGS_luint result (value, currentLocation) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//--------------------------------------------------------------------------------------------------

GGS_stringlist Lexique_spec_5F_scanner::symbols (LOCATION_ARGS) {
  GGS_stringlist result = GGS_stringlist::class_func_emptyList (THERE) ;
  result.addAssignOperation (GGS_string ("identifier") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("literal_string") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("literal_integer") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("system") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("var") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("rule") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("init") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("end") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("true") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("false") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("const") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("count") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("infinity") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("hashmapsize") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("garbageperiod") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (">=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (">") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("<") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("<=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("==") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("!=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("&") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("|") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("~") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (",") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (";") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("(") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (")") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("++") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("--") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("+=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("-=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (":=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("{") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("}") COMMA_HERE) ;
  result.addAssignOperation (GGS_string (":") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("-") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("=") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("[") COMMA_HERE) ;
  result.addAssignOperation (GGS_string ("]") COMMA_HERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordLists_spec_5F_scanner (GenericUniqueArray <String> & ioList) {
  ioList.appendObject ("spec_scanner:delimitorsList") ;
  ioList.appendObject ("spec_scanner:galgasKeyWordList") ;
}

//--------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_spec_5F_scanner (const String & inIdentifier,
                                                      bool & ioFound,
                                                      GenericUniqueArray <String> & ioList) {
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

static LexiqueIntrospection lexiqueIntrospection_spec_5F_scanner
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
//  Map type @typeVarMap
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap::GGS_typeVarMap (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap::~ GGS_typeVarMap (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap::GGS_typeVarMap (const GGS_typeVarMap & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap & GGS_typeVarMap::operator = (const GGS_typeVarMap & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap GGS_typeVarMap::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_typeVarMap result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap GGS_typeVarMap::class_func_emptyMap (LOCATION_ARGS) {
  GGS_typeVarMap result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeVarMap::getter_hasKey (const GGS_string & inKey
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeVarMap::getter_hasKeyAtLevel (const GGS_string & inKey,
                                               const GGS_uint & inLevel
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeVarMap::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeVarMap::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_typeVarMap::getter_locationForKey (const GGS_string & inKey,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_typeVarMap::getter_keyList (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeVarMap::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_typeVarMap_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::performInsert (const GGS_typeVarMap_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_typeVarMap_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element>
GGS_typeVarMap::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_typeVarMap::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element>>
GGS_typeVarMap::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_typeVarMap::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element_3F_ GGS_typeVarMap
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_typeVarMap_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_typeVarMap_2E_element_3F_::init_nil () ;
    }else{
      GGS_typeVarMap_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mIndex = info->mProperty_mIndex ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap GGS_typeVarMap::class_func_mapWithMapToOverride (const GGS_typeVarMap & inMapToOverride
                                                                COMMA_LOCATION_ARGS) {
  GGS_typeVarMap result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_typeVarMap_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap GGS_typeVarMap::getter_overriddenMap (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_typeVarMap result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::setter_insertKey (GGS_lstring inLKey,
                                       GGS_uint inArgument0,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const GGS_typeVarMap_2E_element element (inLKey, inArgument0) ;
  const char * kInsertErrorMessage = "the '%K' place is already declared" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::method_searchKey (GGS_lstring inLKey,
                                       GGS_uint & outArgument0,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "the '%K' place is not declared" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
  }else{
    outArgument0 = info->mProperty_mIndex ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeVarMap::getter_mIndexForKey (const GGS_string & inKey,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mIndex ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::setter_setMIndexForKey (GGS_uint inValue,
                                             GGS_string inKey,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_typeVarMap_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mIndex = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_typeVarMap_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mIndex:") ;
    inArray (i COMMA_HERE)->mProperty_mIndex.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeVarMap_2E_element>> array = sortedInfoArray () ;
    GGS_typeVarMap_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_typeVarMap_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_typeVarMap_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @typeVarMap
//--------------------------------------------------------------------------------------------------

DownEnumerator_typeVarMap::DownEnumerator_typeVarMap (const GGS_typeVarMap & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element DownEnumerator_typeVarMap::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_typeVarMap::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_typeVarMap::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @typeVarMap
//--------------------------------------------------------------------------------------------------

UpEnumerator_typeVarMap::UpEnumerator_typeVarMap (const GGS_typeVarMap & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element UpEnumerator_typeVarMap::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_typeVarMap::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_typeVarMap::current_mIndex (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mIndex ;
}


//--------------------------------------------------------------------------------------------------
//     @typeVarMap generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeVarMap ("typeVarMap",
                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeVarMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeVarMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeVarMap (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap GGS_typeVarMap::extractObject (const GGS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GGS_typeVarMap result ;
  const GGS_typeVarMap * p = (const GGS_typeVarMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeVarMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//  Map type @typeCstMap
//--------------------------------------------------------------------------------------------------

#include "GALGAS_GenericMapRoot.h"

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap::GGS_typeCstMap (void) :
mSharedRoot () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap::~ GGS_typeCstMap (void) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap::GGS_typeCstMap (const GGS_typeCstMap & inSource) :
mSharedRoot (inSource.mSharedRoot) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap & GGS_typeCstMap::operator = (const GGS_typeCstMap & inSource) {
  mSharedRoot = inSource.mSharedRoot ;
  return * this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap GGS_typeCstMap::init (Compiler * COMMA_LOCATION_ARGS) {
  GGS_typeCstMap result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap GGS_typeCstMap::class_func_emptyMap (LOCATION_ARGS) {
  GGS_typeCstMap result ;
  result.build (THERE) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeCstMap::getter_hasKey (const GGS_string & inKey
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), 0)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeCstMap::getter_hasKeyAtLevel (const GGS_string & inKey,
                                               const GGS_uint & inLevel
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    result = GGS_bool (mSharedRoot->hasKey (inKey.stringValue (), inLevel.uintValue ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeCstMap::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (uint32_t (mSharedRoot->count ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeCstMap::getter_levels (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (mSharedRoot->levels ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_location GGS_typeCstMap::getter_locationForKey (const GGS_string & inKey,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GGS_location result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      String message = "'locationForKey' map reader run-time error: the '" ;
      message.appendString (inKey.stringValue ()) ;
      message.appendCString ("' does not exist in map") ;
      inCompiler->onTheFlyRunTimeError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_lkey.mProperty_location ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstringlist GGS_typeCstMap::getter_keyList (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_lstringlist result ;
  if (isValid ()) {
    result = GGS_lstringlist::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeyList (result) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeCstMap::isValid (void) const {
  return mSharedRoot.isNotNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::drop (void)  {
  mSharedRoot.setToNil () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::build (LOCATION_ARGS) {
  mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_typeCstMap_2E_element>>::make (THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::performInsert (const GGS_typeCstMap_2E_element & inElement,
                                 const char * inInsertErrorMessage,
                                 const char * inShadowErrorMessage,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inElement.mProperty_lkey.isValid ()) {
    OptionalSharedRef <GenericMapNode <GGS_typeCstMap_2E_element>> existingNode ;
    const bool allowReplacing = false ;
    mSharedRoot.insulate (THERE) ;
    mSharedRoot->insertOrReplaceInfo (
      inElement,
      allowReplacing,
      existingNode
      COMMA_THERE
    ) ;
    const GGS_lstring lkey = inElement.mProperty_lkey ;
    if (existingNode.isNotNil ()) {
      const GGS_location lstring_existingKey_location = existingNode->mSharedInfo->mProperty_lkey.mProperty_location ;
      inCompiler->semanticErrorWith_K_L_message (lkey, inInsertErrorMessage, lstring_existingKey_location COMMA_THERE) ;
    }else if ((inShadowErrorMessage != nullptr) && (mSharedRoot->overriddenRoot ().isNotNil ())) {
      const auto existingInfo = mSharedRoot->overriddenRoot ()->infoForKey (lkey.mProperty_string.stringValue()) ;
      if (existingInfo.isNotNil ()) {
        const GGS_location lstring_existingKey_location = existingInfo->mProperty_lkey.mProperty_location ;
        inCompiler->semanticErrorWith_K_L_message (lkey, inShadowErrorMessage, lstring_existingKey_location COMMA_THERE) ;
      }
    }
  }
}

//--------------------------------------------------------------------------------------------------

const SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element>
GGS_typeCstMap::infoForKey (const String & inKey) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->infoForKey (inKey) ;
  }else{
    return SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> () ;
  }
}

//--------------------------------------------------------------------------------------------------

int32_t GGS_typeCstMap::count (void) const  {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->count () ;
  }else{
    return 0 ;
  }
}

//--------------------------------------------------------------------------------------------------

GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element>>
GGS_typeCstMap::sortedInfoArray (void) const {
  if (mSharedRoot.isNotNil ()) {
    return mSharedRoot->sortedInfoArray () ;
  }else{
    return GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element>> () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_stringset GGS_typeCstMap::getter_keySet (Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const {
  GGS_stringset result ;
  if (isValid ()) {
    result = GGS_stringset::init (inCompiler COMMA_THERE) ;
    mSharedRoot->populateKeySet (result, inCompiler) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::findNearestKey (const String & inKey,
                                  GenericUniqueArray <String> & outNearestKeyArray) const {
  mSharedRoot->findNearestKey (inKey, outNearestKeyArray) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element_3F_ GGS_typeCstMap
::readSubscript__3F_ (const class GGS_string & inKey,
                      Compiler * /* inCompiler */
                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_typeCstMap_2E_element_3F_ result ;
  if (isValid () && inKey.isValid ()) {
    const SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> info = infoForKey (inKey.stringValue ()) ;
    if (info.isNil ()) {
      result = GGS_typeCstMap_2E_element_3F_::init_nil () ;
    }else{
      GGS_typeCstMap_2E_element element ;
      element.mProperty_lkey = info->mProperty_lkey ;
      element.mProperty_mSign = info->mProperty_mSign ;
      element.mProperty_mValue = info->mProperty_mValue ;
      result = element ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap GGS_typeCstMap::class_func_mapWithMapToOverride (const GGS_typeCstMap & inMapToOverride
                                                                COMMA_LOCATION_ARGS) {
  GGS_typeCstMap result ;
  if (inMapToOverride.isValid ()) {
    result.mSharedRoot = OptionalSharedRef <GenericMapRoot <GGS_typeCstMap_2E_element>>::make (inMapToOverride.mSharedRoot COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap GGS_typeCstMap::getter_overriddenMap (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const {
  GGS_typeCstMap result ;
  if (isValid ()) {
    result.mSharedRoot = mSharedRoot->overriddenRoot () ;
    if (result.mSharedRoot.isNil ()) {
      inCompiler->onTheFlySemanticError ("getter 'overriddenMap': no overriden map" COMMA_THERE) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::setter_insertKey (GGS_lstring inLKey,
                                       GGS_bool inArgument0,
                                       GGS_luint inArgument1,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const GGS_typeCstMap_2E_element element (inLKey, inArgument0, inArgument1) ;
  const char * kInsertErrorMessage = "the '%K' constant is already declared" ;
  const char * kShadowErrorMessage = nullptr ;
  performInsert (element, kInsertErrorMessage, kShadowErrorMessage, inCompiler COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::method_searchKey (GGS_lstring inLKey,
                                       GGS_bool & outArgument0,
                                       GGS_luint & outArgument1,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> info ;
  if (isValid () && inLKey.isValid ()) {
    const String key = inLKey.mProperty_string.stringValue () ;
    info = infoForKey (key) ;
    if (info.isNil ()) {
      GenericUniqueArray <String> nearestKeyArray ;
      findNearestKey (key, nearestKeyArray) ;
      const char * kSearchErrorMessage = "there '%K' constant is not defined" ;
      inCompiler->semanticErrorWith_K_message (inLKey, nearestKeyArray, kSearchErrorMessage COMMA_THERE) ;
    }
  }
  if (info.isNil ()) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    outArgument0 = info->mProperty_mSign ;
    outArgument1 = info->mProperty_mValue ;
  }
}
//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeCstMap::getter_mSignForKey (const GGS_string & inKey,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  GGS_bool result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mSign ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeCstMap::getter_mValueForKey (const GGS_string & inKey,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  GGS_luint result ;
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    const SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element> info = infoForKey (key) ;
    if (info.isNil ()) {
      String message = "cannot read property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      result = info->mProperty_mValue ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::setter_setMSignForKey (GGS_bool inValue,
                                            GGS_string inKey,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_typeCstMap_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mSign = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::setter_setMValueForKey (GGS_luint inValue,
                                             GGS_string inKey,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (isValid () && inKey.isValid ()) {
    const String key = inKey.stringValue () ;
    mSharedRoot.insulate (HERE) ;
    OptionalSharedRef <GenericMapNode <GGS_typeCstMap_2E_element>> node = mSharedRoot->searchNode (key) ;
    if (node.isNil ()) {
      String message = "cannot write property in map: the '" ;
      message.appendString (key) ;
      message.appendCString ("' key does not exist") ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }else{
      node->mSharedInfo->mProperty_mValue = inValue ;
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void GGS_typeCstMap_internalDescription (const GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element>> & inArray,
                                                        String & ioString,
                                                        const int32_t inIndentation) {
  const int32_t n = inArray.count () ;
  ioString.appendString (" (") ;
  ioString.appendSigned (n) ;
  ioString.appendString (" object") ;
  if (n > 1) {
    ioString.appendString ("s") ;
  }
  ioString.appendString ("):") ;
  for (int32_t i = 0 ; i < n ; i++) {
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation) ;
    ioString.appendString ("|-at ") ;
    ioString.appendSigned (i) ;
    ioString.appendString (": key '") ;
    ioString.appendString (inArray (i COMMA_HERE)->mProperty_lkey.mProperty_string.stringValue ()) ;
    ioString.appendString ("'") ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mSign:") ;
    inArray (i COMMA_HERE)->mProperty_mSign.description (ioString, inIndentation + 1) ;
    ioString.appendNewLine () ;
    ioString.appendStringMultiple ("| ", inIndentation + 2) ;
    ioString.appendString ("mValue:") ;
    inArray (i COMMA_HERE)->mProperty_mValue.description (ioString, inIndentation + 1) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<map @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  if (isValid ()) {
    const GenericArray <SharedGenericPtrWithValueSemantics <GGS_typeCstMap_2E_element>> array = sortedInfoArray () ;
    GGS_typeCstMap_internalDescription (array, ioString, inIndentation) ;
    OptionalSharedRef <GenericMapRoot <GGS_typeCstMap_2E_element>> subRoot = mSharedRoot->overriddenRoot () ;
    uint32_t idx = 0 ;
    while (subRoot.isNotNil ()) {
     idx += 1 ;
     ioString.appendNewLine () ;
     ioString.appendStringMultiple ("| ", inIndentation + 1) ;
     ioString.appendString (" override #") ;
     ioString.appendUnsigned (idx) ;
     const auto subRootArray = subRoot->sortedInfoArray () ;
     GGS_typeCstMap_internalDescription (subRootArray, ioString, inIndentation) ;
     subRoot = subRoot->overriddenRoot () ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}



//--------------------------------------------------------------------------------------------------
//  Down Enumerator for @typeCstMap
//--------------------------------------------------------------------------------------------------

DownEnumerator_typeCstMap::DownEnumerator_typeCstMap (const GGS_typeCstMap & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
  mIndex = mInfoArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element DownEnumerator_typeCstMap::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_typeCstMap::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool DownEnumerator_typeCstMap::current_mSign (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mSign ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint DownEnumerator_typeCstMap::current_mValue (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mValue ;
}

//--------------------------------------------------------------------------------------------------
//  Up Enumerator for @typeCstMap
//--------------------------------------------------------------------------------------------------

UpEnumerator_typeCstMap::UpEnumerator_typeCstMap (const GGS_typeCstMap & inMap) :
mInfoArray (inMap.sortedInfoArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element UpEnumerator_typeCstMap::current (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE).value () ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_typeCstMap::current_lkey (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_lkey ;
}

//--------------------------------------------------------------------------------------------------

GGS_bool UpEnumerator_typeCstMap::current_mSign (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mSign ;
}

//--------------------------------------------------------------------------------------------------

GGS_luint UpEnumerator_typeCstMap::current_mValue (LOCATION_ARGS) const {
  return mInfoArray (mIndex COMMA_THERE)->mProperty_mValue ;
}


//--------------------------------------------------------------------------------------------------
//     @typeCstMap generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeCstMap ("typeCstMap",
                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeCstMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeCstMap::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeCstMap (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap GGS_typeCstMap::extractObject (const GGS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GGS_typeCstMap result ;
  const GGS_typeCstMap * p = (const GGS_typeCstMap *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeCstMap *> (p)) {
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

ComparisonResult GGS_typePreconditionExpression::objectCompare (const GGS_typePreconditionExpression & inOperand) const {
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

GGS_typePreconditionExpression::GGS_typePreconditionExpression (void) :
AC_GALGAS_reference_class () {
}


void cPtr_typePreconditionExpression::
typePreconditionExpression_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression::GGS_typePreconditionExpression (const cPtr_typePreconditionExpression * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePreconditionExpression) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @typePreconditionExpression class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_typePreconditionExpression::cPtr_typePreconditionExpression (Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) :
acStrongPtr_class (inCompiler COMMA_THERE) {
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePreconditionExpression::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @typePreconditionExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePreconditionExpression ("typePreconditionExpression",
                                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePreconditionExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePreconditionExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePreconditionExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePreconditionExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typePreconditionExpression::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_typePreconditionExpression result ;
  const GGS_typePreconditionExpression * p = (const GGS_typePreconditionExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePreconditionExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePreconditionExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typePreconditionExpression_2E_weak::objectCompare (const GGS_typePreconditionExpression_2E_weak & inOperand) const {
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

GGS_typePreconditionExpression_2E_weak::GGS_typePreconditionExpression_2E_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression_2E_weak & GGS_typePreconditionExpression_2E_weak::operator = (const GGS_typePreconditionExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression_2E_weak::GGS_typePreconditionExpression_2E_weak (const GGS_typePreconditionExpression & inSource) :
AC_GALGAS_weak_reference (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression_2E_weak GGS_typePreconditionExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typePreconditionExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typePreconditionExpression_2E_weak::unwrappedValue (void) const {
  GGS_typePreconditionExpression result ;
  if (isValid ()) {
    const cPtr_typePreconditionExpression * p = (cPtr_typePreconditionExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typePreconditionExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typePreconditionExpression_2E_weak::bang_typePreconditionExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typePreconditionExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePreconditionExpression) ;
      result = GGS_typePreconditionExpression ((cPtr_typePreconditionExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typePreconditionExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak ("typePreconditionExpression.weak",
                                                                                       nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePreconditionExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePreconditionExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePreconditionExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression_2E_weak GGS_typePreconditionExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GGS_typePreconditionExpression_2E_weak result ;
  const GGS_typePreconditionExpression_2E_weak * p = (const GGS_typePreconditionExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePreconditionExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePreconditionExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeTrueExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeTrueExpression::objectCompare (const GGS_typeTrueExpression & inOperand) const {
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

GGS_typeTrueExpression::GGS_typeTrueExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeTrueExpression GGS_typeTrueExpression::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeTrueExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeTrueExpression (inCompiler COMMA_THERE)) ;
  object->typeTrueExpression_init (inCompiler) ;
  const GGS_typeTrueExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeTrueExpression::
typeTrueExpression_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression::GGS_typeTrueExpression (const cPtr_typeTrueExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeTrueExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression GGS_typeTrueExpression::class_func_new (Compiler * inCompiler COMMA_LOCATION_ARGS) {
  GGS_typeTrueExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeTrueExpression (inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeTrueExpression class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_typeTrueExpression::cPtr_typeTrueExpression (Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeTrueExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

void cPtr_typeTrueExpression::description (String & ioString,
                                           const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@typeTrueExpression]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeTrueExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeTrueExpression (inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeTrueExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @typeTrueExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeTrueExpression ("typeTrueExpression",
                                                                       & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeTrueExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeTrueExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeTrueExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression GGS_typeTrueExpression::extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GGS_typeTrueExpression result ;
  const GGS_typeTrueExpression * p = (const GGS_typeTrueExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeTrueExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTrueExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeTrueExpression_2E_weak::objectCompare (const GGS_typeTrueExpression_2E_weak & inOperand) const {
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

GGS_typeTrueExpression_2E_weak::GGS_typeTrueExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression_2E_weak & GGS_typeTrueExpression_2E_weak::operator = (const GGS_typeTrueExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression_2E_weak::GGS_typeTrueExpression_2E_weak (const GGS_typeTrueExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression_2E_weak GGS_typeTrueExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeTrueExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression GGS_typeTrueExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeTrueExpression result ;
  if (isValid ()) {
    const cPtr_typeTrueExpression * p = (cPtr_typeTrueExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeTrueExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression GGS_typeTrueExpression_2E_weak::bang_typeTrueExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeTrueExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeTrueExpression) ;
      result = GGS_typeTrueExpression ((cPtr_typeTrueExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeTrueExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeTrueExpression_2E_weak ("typeTrueExpression.weak",
                                                                               & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeTrueExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTrueExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeTrueExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeTrueExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTrueExpression_2E_weak GGS_typeTrueExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_typeTrueExpression_2E_weak result ;
  const GGS_typeTrueExpression_2E_weak * p = (const GGS_typeTrueExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeTrueExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTrueExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeFalseExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeFalseExpression::objectCompare (const GGS_typeFalseExpression & inOperand) const {
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

GGS_typeFalseExpression::GGS_typeFalseExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeFalseExpression GGS_typeFalseExpression::
init (Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeFalseExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeFalseExpression (inCompiler COMMA_THERE)) ;
  object->typeFalseExpression_init (inCompiler) ;
  const GGS_typeFalseExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeFalseExpression::
typeFalseExpression_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression::GGS_typeFalseExpression (const cPtr_typeFalseExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeFalseExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression GGS_typeFalseExpression::class_func_new (Compiler * inCompiler COMMA_LOCATION_ARGS) {
  GGS_typeFalseExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeFalseExpression (inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeFalseExpression class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_typeFalseExpression::cPtr_typeFalseExpression (Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE) {
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeFalseExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

void cPtr_typeFalseExpression::description (String & ioString,
                                            const int32_t /* inIndentation */) const {
  ioString.appendCString ("[@typeFalseExpression]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeFalseExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeFalseExpression (inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeFalseExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @typeFalseExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeFalseExpression ("typeFalseExpression",
                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeFalseExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeFalseExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeFalseExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression GGS_typeFalseExpression::extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GGS_typeFalseExpression result ;
  const GGS_typeFalseExpression * p = (const GGS_typeFalseExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeFalseExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeFalseExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeFalseExpression_2E_weak::objectCompare (const GGS_typeFalseExpression_2E_weak & inOperand) const {
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

GGS_typeFalseExpression_2E_weak::GGS_typeFalseExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression_2E_weak & GGS_typeFalseExpression_2E_weak::operator = (const GGS_typeFalseExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression_2E_weak::GGS_typeFalseExpression_2E_weak (const GGS_typeFalseExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression_2E_weak GGS_typeFalseExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeFalseExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression GGS_typeFalseExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeFalseExpression result ;
  if (isValid ()) {
    const cPtr_typeFalseExpression * p = (cPtr_typeFalseExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeFalseExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression GGS_typeFalseExpression_2E_weak::bang_typeFalseExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeFalseExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeFalseExpression) ;
      result = GGS_typeFalseExpression ((cPtr_typeFalseExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeFalseExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeFalseExpression_2E_weak ("typeFalseExpression.weak",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeFalseExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeFalseExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeFalseExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeFalseExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeFalseExpression_2E_weak GGS_typeFalseExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GGS_typeFalseExpression_2E_weak result ;
  const GGS_typeFalseExpression_2E_weak * p = (const GGS_typeFalseExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeFalseExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeFalseExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeComplementExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeComplementExpression::objectCompare (const GGS_typeComplementExpression & inOperand) const {
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

GGS_typeComplementExpression::GGS_typeComplementExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeComplementExpression GGS_typeComplementExpression::
init_21_ (const GGS_typePreconditionExpression & in_mExpression,
          Compiler * inCompiler
          COMMA_LOCATION_ARGS) {
  cPtr_typeComplementExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeComplementExpression (inCompiler COMMA_THERE)) ;
  object->typeComplementExpression_init_21_ (in_mExpression, inCompiler) ;
  const GGS_typeComplementExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeComplementExpression::
typeComplementExpression_init_21_ (const GGS_typePreconditionExpression & in_mExpression,
                                   Compiler * /* inCompiler */) {
  mProperty_mExpression = in_mExpression ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression::GGS_typeComplementExpression (const cPtr_typeComplementExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeComplementExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression GGS_typeComplementExpression::class_func_new (const GGS_typePreconditionExpression & in_mExpression,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  GGS_typeComplementExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeComplementExpression (in_mExpression,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typeComplementExpression::readProperty_mExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_typePreconditionExpression () ;
  }else{
    cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    return p->mProperty_mExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeComplementExpression::setProperty_mExpression (const GGS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeComplementExpression) ;
    p->mProperty_mExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeComplementExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeComplementExpression::cPtr_typeComplementExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mExpression () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeComplementExpression::cPtr_typeComplementExpression (const GGS_typePreconditionExpression & in_mExpression,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mExpression () {
  mProperty_mExpression = in_mExpression ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeComplementExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

void cPtr_typeComplementExpression::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("[@typeComplementExpression:") ;
  mProperty_mExpression.description (ioString, inIndentation+1) ;
  ioString.appendCString ("]") ;
}

//--------------------------------------------------------------------------------------------------

acPtr_class * cPtr_typeComplementExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeComplementExpression (mProperty_mExpression, inCompiler COMMA_THERE)) ;
  return ptr ;
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typeComplementExpression::printNonNullClassInstanceProperties (void) const {
    cPtr_typePreconditionExpression::printNonNullClassInstanceProperties () ;
    mProperty_mExpression.printNonNullClassInstanceProperties ("mExpression") ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @typeComplementExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeComplementExpression ("typeComplementExpression",
                                                                             & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeComplementExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeComplementExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeComplementExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression GGS_typeComplementExpression::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeComplementExpression result ;
  const GGS_typeComplementExpression * p = (const GGS_typeComplementExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeComplementExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeComplementExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeComplementExpression_2E_weak::objectCompare (const GGS_typeComplementExpression_2E_weak & inOperand) const {
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

GGS_typeComplementExpression_2E_weak::GGS_typeComplementExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression_2E_weak & GGS_typeComplementExpression_2E_weak::operator = (const GGS_typeComplementExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression_2E_weak::GGS_typeComplementExpression_2E_weak (const GGS_typeComplementExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression_2E_weak GGS_typeComplementExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeComplementExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression GGS_typeComplementExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeComplementExpression result ;
  if (isValid ()) {
    const cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeComplementExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression GGS_typeComplementExpression_2E_weak::bang_typeComplementExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeComplementExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeComplementExpression) ;
      result = GGS_typeComplementExpression ((cPtr_typeComplementExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeComplementExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeComplementExpression_2E_weak ("typeComplementExpression.weak",
                                                                                     & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeComplementExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeComplementExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeComplementExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeComplementExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeComplementExpression_2E_weak GGS_typeComplementExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeComplementExpression_2E_weak result ;
  const GGS_typeComplementExpression_2E_weak * p = (const GGS_typeComplementExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeComplementExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeComplementExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeAndExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeAndExpression::objectCompare (const GGS_typeAndExpression & inOperand) const {
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

GGS_typeAndExpression::GGS_typeAndExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeAndExpression GGS_typeAndExpression::
init_21__21_ (const GGS_typePreconditionExpression & in_mLeftExpression,
              const GGS_typePreconditionExpression & in_mRightExpression,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeAndExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeAndExpression (inCompiler COMMA_THERE)) ;
  object->typeAndExpression_init_21__21_ (in_mLeftExpression, in_mRightExpression, inCompiler) ;
  const GGS_typeAndExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAndExpression::
typeAndExpression_init_21__21_ (const GGS_typePreconditionExpression & in_mLeftExpression,
                                const GGS_typePreconditionExpression & in_mRightExpression,
                                Compiler * /* inCompiler */) {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression::GGS_typeAndExpression (const cPtr_typeAndExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAndExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression GGS_typeAndExpression::class_func_new (const GGS_typePreconditionExpression & in_mLeftExpression,
                                                             const GGS_typePreconditionExpression & in_mRightExpression,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  GGS_typeAndExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAndExpression (in_mLeftExpression, in_mRightExpression,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typeAndExpression::readProperty_mLeftExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_typePreconditionExpression () ;
  }else{
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    return p->mProperty_mLeftExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAndExpression::setProperty_mLeftExpression (const GGS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typeAndExpression::readProperty_mRightExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_typePreconditionExpression () ;
  }else{
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    return p->mProperty_mRightExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAndExpression::setProperty_mRightExpression (const GGS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAndExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAndExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeAndExpression::cPtr_typeAndExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeAndExpression::cPtr_typeAndExpression (const GGS_typePreconditionExpression & in_mLeftExpression,
                                                const GGS_typePreconditionExpression & in_mRightExpression,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeAndExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeAndExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAndExpression (mProperty_mLeftExpression, mProperty_mRightExpression, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeAndExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAndExpression ("typeAndExpression",
                                                                      & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAndExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAndExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAndExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression GGS_typeAndExpression::extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GGS_typeAndExpression result ;
  const GGS_typeAndExpression * p = (const GGS_typeAndExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAndExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAndExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeAndExpression_2E_weak::objectCompare (const GGS_typeAndExpression_2E_weak & inOperand) const {
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

GGS_typeAndExpression_2E_weak::GGS_typeAndExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression_2E_weak & GGS_typeAndExpression_2E_weak::operator = (const GGS_typeAndExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression_2E_weak::GGS_typeAndExpression_2E_weak (const GGS_typeAndExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression_2E_weak GGS_typeAndExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeAndExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression GGS_typeAndExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeAndExpression result ;
  if (isValid ()) {
    const cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeAndExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression GGS_typeAndExpression_2E_weak::bang_typeAndExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeAndExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAndExpression) ;
      result = GGS_typeAndExpression ((cPtr_typeAndExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeAndExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAndExpression_2E_weak ("typeAndExpression.weak",
                                                                              & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAndExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAndExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAndExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAndExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAndExpression_2E_weak GGS_typeAndExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typeAndExpression_2E_weak result ;
  const GGS_typeAndExpression_2E_weak * p = (const GGS_typeAndExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAndExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAndExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeOrExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeOrExpression::objectCompare (const GGS_typeOrExpression & inOperand) const {
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

GGS_typeOrExpression::GGS_typeOrExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeOrExpression GGS_typeOrExpression::
init_21__21_ (const GGS_typePreconditionExpression & in_mLeftExpression,
              const GGS_typePreconditionExpression & in_mRightExpression,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeOrExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeOrExpression (inCompiler COMMA_THERE)) ;
  object->typeOrExpression_init_21__21_ (in_mLeftExpression, in_mRightExpression, inCompiler) ;
  const GGS_typeOrExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeOrExpression::
typeOrExpression_init_21__21_ (const GGS_typePreconditionExpression & in_mLeftExpression,
                               const GGS_typePreconditionExpression & in_mRightExpression,
                               Compiler * /* inCompiler */) {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression::GGS_typeOrExpression (const cPtr_typeOrExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeOrExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression GGS_typeOrExpression::class_func_new (const GGS_typePreconditionExpression & in_mLeftExpression,
                                                           const GGS_typePreconditionExpression & in_mRightExpression,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  GGS_typeOrExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeOrExpression (in_mLeftExpression, in_mRightExpression,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typeOrExpression::readProperty_mLeftExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_typePreconditionExpression () ;
  }else{
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    return p->mProperty_mLeftExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeOrExpression::setProperty_mLeftExpression (const GGS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mLeftExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression GGS_typeOrExpression::readProperty_mRightExpression (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_typePreconditionExpression () ;
  }else{
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    return p->mProperty_mRightExpression ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeOrExpression::setProperty_mRightExpression (const GGS_typePreconditionExpression & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeOrExpression) ;
    p->mProperty_mRightExpression = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeOrExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeOrExpression::cPtr_typeOrExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeOrExpression::cPtr_typeOrExpression (const GGS_typePreconditionExpression & in_mLeftExpression,
                                              const GGS_typePreconditionExpression & in_mRightExpression,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mLeftExpression (),
mProperty_mRightExpression () {
  mProperty_mLeftExpression = in_mLeftExpression ;
  mProperty_mRightExpression = in_mRightExpression ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeOrExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeOrExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeOrExpression (mProperty_mLeftExpression, mProperty_mRightExpression, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeOrExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeOrExpression ("typeOrExpression",
                                                                     & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeOrExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeOrExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeOrExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression GGS_typeOrExpression::extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GGS_typeOrExpression result ;
  const GGS_typeOrExpression * p = (const GGS_typeOrExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeOrExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeOrExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeOrExpression_2E_weak::objectCompare (const GGS_typeOrExpression_2E_weak & inOperand) const {
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

GGS_typeOrExpression_2E_weak::GGS_typeOrExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression_2E_weak & GGS_typeOrExpression_2E_weak::operator = (const GGS_typeOrExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression_2E_weak::GGS_typeOrExpression_2E_weak (const GGS_typeOrExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression_2E_weak GGS_typeOrExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeOrExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression GGS_typeOrExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeOrExpression result ;
  if (isValid ()) {
    const cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeOrExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression GGS_typeOrExpression_2E_weak::bang_typeOrExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeOrExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeOrExpression) ;
      result = GGS_typeOrExpression ((cPtr_typeOrExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeOrExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeOrExpression_2E_weak ("typeOrExpression.weak",
                                                                             & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeOrExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeOrExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeOrExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeOrExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeOrExpression_2E_weak GGS_typeOrExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeOrExpression_2E_weak result ;
  const GGS_typeOrExpression_2E_weak * p = (const GGS_typeOrExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeOrExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeOrExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeEqualExpression_2E_weak::objectCompare (const GGS_typeEqualExpression_2E_weak & inOperand) const {
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

GGS_typeEqualExpression_2E_weak::GGS_typeEqualExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression_2E_weak & GGS_typeEqualExpression_2E_weak::operator = (const GGS_typeEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression_2E_weak::GGS_typeEqualExpression_2E_weak (const GGS_typeEqualExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression_2E_weak GGS_typeEqualExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeEqualExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression GGS_typeEqualExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeEqualExpression result ;
  if (isValid ()) {
    const cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeEqualExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression GGS_typeEqualExpression_2E_weak::bang_typeEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeEqualExpression) ;
      result = GGS_typeEqualExpression ((cPtr_typeEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeEqualExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeEqualExpression_2E_weak ("typeEqualExpression.weak",
                                                                                & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeEqualExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeEqualExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeEqualExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression_2E_weak GGS_typeEqualExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GGS_typeEqualExpression_2E_weak result ;
  const GGS_typeEqualExpression_2E_weak * p = (const GGS_typeEqualExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeEqualExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeEqualExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeNonEqualExpression_2E_weak::objectCompare (const GGS_typeNonEqualExpression_2E_weak & inOperand) const {
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

GGS_typeNonEqualExpression_2E_weak::GGS_typeNonEqualExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression_2E_weak & GGS_typeNonEqualExpression_2E_weak::operator = (const GGS_typeNonEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression_2E_weak::GGS_typeNonEqualExpression_2E_weak (const GGS_typeNonEqualExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression_2E_weak GGS_typeNonEqualExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeNonEqualExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression GGS_typeNonEqualExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeNonEqualExpression result ;
  if (isValid ()) {
    const cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeNonEqualExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression GGS_typeNonEqualExpression_2E_weak::bang_typeNonEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeNonEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeNonEqualExpression) ;
      result = GGS_typeNonEqualExpression ((cPtr_typeNonEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeNonEqualExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeNonEqualExpression_2E_weak ("typeNonEqualExpression.weak",
                                                                                   & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeNonEqualExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeNonEqualExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeNonEqualExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression_2E_weak GGS_typeNonEqualExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GGS_typeNonEqualExpression_2E_weak result ;
  const GGS_typeNonEqualExpression_2E_weak * p = (const GGS_typeNonEqualExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeNonEqualExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeNonEqualExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeInfOrEqualExpression_2E_weak::objectCompare (const GGS_typeInfOrEqualExpression_2E_weak & inOperand) const {
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

GGS_typeInfOrEqualExpression_2E_weak::GGS_typeInfOrEqualExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression_2E_weak & GGS_typeInfOrEqualExpression_2E_weak::operator = (const GGS_typeInfOrEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression_2E_weak::GGS_typeInfOrEqualExpression_2E_weak (const GGS_typeInfOrEqualExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression_2E_weak GGS_typeInfOrEqualExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeInfOrEqualExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression GGS_typeInfOrEqualExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeInfOrEqualExpression result ;
  if (isValid ()) {
    const cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeInfOrEqualExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression GGS_typeInfOrEqualExpression_2E_weak::bang_typeInfOrEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeInfOrEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeInfOrEqualExpression) ;
      result = GGS_typeInfOrEqualExpression ((cPtr_typeInfOrEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeInfOrEqualExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2E_weak ("typeInfOrEqualExpression.weak",
                                                                                     & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeInfOrEqualExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeInfOrEqualExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeInfOrEqualExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression_2E_weak GGS_typeInfOrEqualExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeInfOrEqualExpression_2E_weak result ;
  const GGS_typeInfOrEqualExpression_2E_weak * p = (const GGS_typeInfOrEqualExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeInfOrEqualExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInfOrEqualExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeSupOrEqualExpression_2E_weak::objectCompare (const GGS_typeSupOrEqualExpression_2E_weak & inOperand) const {
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

GGS_typeSupOrEqualExpression_2E_weak::GGS_typeSupOrEqualExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression_2E_weak & GGS_typeSupOrEqualExpression_2E_weak::operator = (const GGS_typeSupOrEqualExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression_2E_weak::GGS_typeSupOrEqualExpression_2E_weak (const GGS_typeSupOrEqualExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression_2E_weak GGS_typeSupOrEqualExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeSupOrEqualExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression GGS_typeSupOrEqualExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeSupOrEqualExpression result ;
  if (isValid ()) {
    const cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeSupOrEqualExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression GGS_typeSupOrEqualExpression_2E_weak::bang_typeSupOrEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeSupOrEqualExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeSupOrEqualExpression) ;
      result = GGS_typeSupOrEqualExpression ((cPtr_typeSupOrEqualExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeSupOrEqualExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2E_weak ("typeSupOrEqualExpression.weak",
                                                                                     & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeSupOrEqualExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeSupOrEqualExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeSupOrEqualExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression_2E_weak GGS_typeSupOrEqualExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeSupOrEqualExpression_2E_weak result ;
  const GGS_typeSupOrEqualExpression_2E_weak * p = (const GGS_typeSupOrEqualExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeSupOrEqualExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSupOrEqualExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeStrictInfExpression_2E_weak::objectCompare (const GGS_typeStrictInfExpression_2E_weak & inOperand) const {
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

GGS_typeStrictInfExpression_2E_weak::GGS_typeStrictInfExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression_2E_weak & GGS_typeStrictInfExpression_2E_weak::operator = (const GGS_typeStrictInfExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression_2E_weak::GGS_typeStrictInfExpression_2E_weak (const GGS_typeStrictInfExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression_2E_weak GGS_typeStrictInfExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeStrictInfExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression GGS_typeStrictInfExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeStrictInfExpression result ;
  if (isValid ()) {
    const cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeStrictInfExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression GGS_typeStrictInfExpression_2E_weak::bang_typeStrictInfExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeStrictInfExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeStrictInfExpression) ;
      result = GGS_typeStrictInfExpression ((cPtr_typeStrictInfExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeStrictInfExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeStrictInfExpression_2E_weak ("typeStrictInfExpression.weak",
                                                                                    & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeStrictInfExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeStrictInfExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeStrictInfExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression_2E_weak GGS_typeStrictInfExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeStrictInfExpression_2E_weak result ;
  const GGS_typeStrictInfExpression_2E_weak * p = (const GGS_typeStrictInfExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeStrictInfExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictInfExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeStrictSupExpression_2E_weak::objectCompare (const GGS_typeStrictSupExpression_2E_weak & inOperand) const {
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

GGS_typeStrictSupExpression_2E_weak::GGS_typeStrictSupExpression_2E_weak (void) :
GGS_typePreconditionExpression_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression_2E_weak & GGS_typeStrictSupExpression_2E_weak::operator = (const GGS_typeStrictSupExpression & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression_2E_weak::GGS_typeStrictSupExpression_2E_weak (const GGS_typeStrictSupExpression & inSource) :
GGS_typePreconditionExpression_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression_2E_weak GGS_typeStrictSupExpression_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeStrictSupExpression_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression GGS_typeStrictSupExpression_2E_weak::unwrappedValue (void) const {
  GGS_typeStrictSupExpression result ;
  if (isValid ()) {
    const cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeStrictSupExpression (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression GGS_typeStrictSupExpression_2E_weak::bang_typeStrictSupExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeStrictSupExpression result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeStrictSupExpression) ;
      result = GGS_typeStrictSupExpression ((cPtr_typeStrictSupExpression *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeStrictSupExpression.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeStrictSupExpression_2E_weak ("typeStrictSupExpression.weak",
                                                                                    & kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeStrictSupExpression_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeStrictSupExpression_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeStrictSupExpression_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression_2E_weak GGS_typeStrictSupExpression_2E_weak::extractObject (const GGS_object & inObject,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeStrictSupExpression_2E_weak result ;
  const GGS_typeStrictSupExpression_2E_weak * p = (const GGS_typeStrictSupExpression_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeStrictSupExpression_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeStrictSupExpression.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typePostcondition reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typePostcondition::objectCompare (const GGS_typePostcondition & inOperand) const {
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

GGS_typePostcondition::GGS_typePostcondition (void) :
AC_GALGAS_reference_class () {
}


void cPtr_typePostcondition::
typePostcondition_init (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition::GGS_typePostcondition (const cPtr_typePostcondition * inSourcePtr) :
AC_GALGAS_reference_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostcondition) ;
}
//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostcondition class
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------

cPtr_typePostcondition::cPtr_typePostcondition (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) :
acStrongPtr_class (inCompiler COMMA_THERE) {
}


//--------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  void cPtr_typePostcondition::printNonNullClassInstanceProperties (void) const {
    acStrongPtr_class::printNonNullClassInstanceProperties () ;
  }
#endif

//--------------------------------------------------------------------------------------------------
//     @typePostcondition generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostcondition ("typePostcondition",
                                                                      nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostcondition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostcondition ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostcondition::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostcondition (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition GGS_typePostcondition::extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostcondition result ;
  const GGS_typePostcondition * p = (const GGS_typePostcondition *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostcondition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostcondition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typePostcondition_2E_weak::objectCompare (const GGS_typePostcondition_2E_weak & inOperand) const {
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

GGS_typePostcondition_2E_weak::GGS_typePostcondition_2E_weak (void) :
AC_GALGAS_weak_reference () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition_2E_weak & GGS_typePostcondition_2E_weak::operator = (const GGS_typePostcondition & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition_2E_weak::GGS_typePostcondition_2E_weak (const GGS_typePostcondition & inSource) :
AC_GALGAS_weak_reference (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typePostcondition_2E_weak GGS_typePostcondition_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typePostcondition_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition GGS_typePostcondition_2E_weak::unwrappedValue (void) const {
  GGS_typePostcondition result ;
  if (isValid ()) {
    const cPtr_typePostcondition * p = (cPtr_typePostcondition *) ptr () ;
    if (nullptr != p) {
      result = GGS_typePostcondition (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition GGS_typePostcondition_2E_weak::bang_typePostcondition_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typePostcondition result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostcondition) ;
      result = GGS_typePostcondition ((cPtr_typePostcondition *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typePostcondition.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostcondition_2E_weak ("typePostcondition.weak",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostcondition_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostcondition_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostcondition_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostcondition_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition_2E_weak GGS_typePostcondition_2E_weak::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostcondition_2E_weak result ;
  const GGS_typePostcondition_2E_weak * p = (const GGS_typePostcondition_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostcondition_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostcondition.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typePostIncrement_2E_weak::objectCompare (const GGS_typePostIncrement_2E_weak & inOperand) const {
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

GGS_typePostIncrement_2E_weak::GGS_typePostIncrement_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement_2E_weak & GGS_typePostIncrement_2E_weak::operator = (const GGS_typePostIncrement & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement_2E_weak::GGS_typePostIncrement_2E_weak (const GGS_typePostIncrement & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement_2E_weak GGS_typePostIncrement_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typePostIncrement_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement GGS_typePostIncrement_2E_weak::unwrappedValue (void) const {
  GGS_typePostIncrement result ;
  if (isValid ()) {
    const cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) ptr () ;
    if (nullptr != p) {
      result = GGS_typePostIncrement (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement GGS_typePostIncrement_2E_weak::bang_typePostIncrement_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typePostIncrement result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostIncrement) ;
      result = GGS_typePostIncrement ((cPtr_typePostIncrement *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typePostIncrement.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostIncrement_2E_weak ("typePostIncrement.weak",
                                                                              & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostIncrement_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostIncrement_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostIncrement_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement_2E_weak GGS_typePostIncrement_2E_weak::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostIncrement_2E_weak result ;
  const GGS_typePostIncrement_2E_weak * p = (const GGS_typePostIncrement_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostIncrement_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostIncrement.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typePostDecrement_2E_weak::objectCompare (const GGS_typePostDecrement_2E_weak & inOperand) const {
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

GGS_typePostDecrement_2E_weak::GGS_typePostDecrement_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement_2E_weak & GGS_typePostDecrement_2E_weak::operator = (const GGS_typePostDecrement & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement_2E_weak::GGS_typePostDecrement_2E_weak (const GGS_typePostDecrement & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement_2E_weak GGS_typePostDecrement_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typePostDecrement_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement GGS_typePostDecrement_2E_weak::unwrappedValue (void) const {
  GGS_typePostDecrement result ;
  if (isValid ()) {
    const cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) ptr () ;
    if (nullptr != p) {
      result = GGS_typePostDecrement (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement GGS_typePostDecrement_2E_weak::bang_typePostDecrement_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typePostDecrement result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typePostDecrement) ;
      result = GGS_typePostDecrement ((cPtr_typePostDecrement *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typePostDecrement.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostDecrement_2E_weak ("typePostDecrement.weak",
                                                                              & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostDecrement_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostDecrement_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostDecrement_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement_2E_weak GGS_typePostDecrement_2E_weak::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostDecrement_2E_weak result ;
  const GGS_typePostDecrement_2E_weak * p = (const GGS_typePostDecrement_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostDecrement_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostDecrement.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeAddConstant_2E_weak::objectCompare (const GGS_typeAddConstant_2E_weak & inOperand) const {
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

GGS_typeAddConstant_2E_weak::GGS_typeAddConstant_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant_2E_weak & GGS_typeAddConstant_2E_weak::operator = (const GGS_typeAddConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant_2E_weak::GGS_typeAddConstant_2E_weak (const GGS_typeAddConstant & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant_2E_weak GGS_typeAddConstant_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeAddConstant_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant GGS_typeAddConstant_2E_weak::unwrappedValue (void) const {
  GGS_typeAddConstant result ;
  if (isValid ()) {
    const cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeAddConstant (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant GGS_typeAddConstant_2E_weak::bang_typeAddConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeAddConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAddConstant) ;
      result = GGS_typeAddConstant ((cPtr_typeAddConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeAddConstant.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAddConstant_2E_weak ("typeAddConstant.weak",
                                                                            & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAddConstant_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAddConstant_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAddConstant_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant_2E_weak GGS_typeAddConstant_2E_weak::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeAddConstant_2E_weak result ;
  const GGS_typeAddConstant_2E_weak * p = (const GGS_typeAddConstant_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAddConstant_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAddConstant.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeSubConstant_2E_weak::objectCompare (const GGS_typeSubConstant_2E_weak & inOperand) const {
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

GGS_typeSubConstant_2E_weak::GGS_typeSubConstant_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant_2E_weak & GGS_typeSubConstant_2E_weak::operator = (const GGS_typeSubConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant_2E_weak::GGS_typeSubConstant_2E_weak (const GGS_typeSubConstant & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant_2E_weak GGS_typeSubConstant_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeSubConstant_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant GGS_typeSubConstant_2E_weak::unwrappedValue (void) const {
  GGS_typeSubConstant result ;
  if (isValid ()) {
    const cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeSubConstant (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant GGS_typeSubConstant_2E_weak::bang_typeSubConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeSubConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeSubConstant) ;
      result = GGS_typeSubConstant ((cPtr_typeSubConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeSubConstant.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeSubConstant_2E_weak ("typeSubConstant.weak",
                                                                            & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeSubConstant_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeSubConstant_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeSubConstant_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant_2E_weak GGS_typeSubConstant_2E_weak::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeSubConstant_2E_weak result ;
  const GGS_typeSubConstant_2E_weak * p = (const GGS_typeSubConstant_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeSubConstant_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeSubConstant.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeAssignConstant_2E_weak::objectCompare (const GGS_typeAssignConstant_2E_weak & inOperand) const {
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

GGS_typeAssignConstant_2E_weak::GGS_typeAssignConstant_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant_2E_weak & GGS_typeAssignConstant_2E_weak::operator = (const GGS_typeAssignConstant & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant_2E_weak::GGS_typeAssignConstant_2E_weak (const GGS_typeAssignConstant & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant_2E_weak GGS_typeAssignConstant_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeAssignConstant_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant GGS_typeAssignConstant_2E_weak::unwrappedValue (void) const {
  GGS_typeAssignConstant result ;
  if (isValid ()) {
    const cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeAssignConstant (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant GGS_typeAssignConstant_2E_weak::bang_typeAssignConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeAssignConstant result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAssignConstant) ;
      result = GGS_typeAssignConstant ((cPtr_typeAssignConstant *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeAssignConstant.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAssignConstant_2E_weak ("typeAssignConstant.weak",
                                                                               & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAssignConstant_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAssignConstant_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAssignConstant_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant_2E_weak GGS_typeAssignConstant_2E_weak::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_typeAssignConstant_2E_weak result ;
  const GGS_typeAssignConstant_2E_weak * p = (const GGS_typeAssignConstant_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAssignConstant_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignConstant.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeAssignInfinity_2E_weak::objectCompare (const GGS_typeAssignInfinity_2E_weak & inOperand) const {
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

GGS_typeAssignInfinity_2E_weak::GGS_typeAssignInfinity_2E_weak (void) :
GGS_typePostcondition_2E_weak () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity_2E_weak & GGS_typeAssignInfinity_2E_weak::operator = (const GGS_typeAssignInfinity & inSource) {
  cPtr_weakReference_proxy * proxyPtr = nullptr ;
  acStrongPtr_class * p = (acStrongPtr_class *) inSource.ptr () ;
  if (p != nullptr) {
    proxyPtr = p->getProxy () ;
  }
  macroAssignSharedObject (mProxyPtr, proxyPtr) ;
  return *this ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity_2E_weak::GGS_typeAssignInfinity_2E_weak (const GGS_typeAssignInfinity & inSource) :
GGS_typePostcondition_2E_weak (inSource) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity_2E_weak GGS_typeAssignInfinity_2E_weak::class_func_nil (LOCATION_ARGS) {
  GGS_typeAssignInfinity_2E_weak result ;
  macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity GGS_typeAssignInfinity_2E_weak::unwrappedValue (void) const {
  GGS_typeAssignInfinity result ;
  if (isValid ()) {
    const cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) ptr () ;
    if (nullptr != p) {
      result = GGS_typeAssignInfinity (p) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity GGS_typeAssignInfinity_2E_weak::bang_typeAssignInfinity_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  GGS_typeAssignInfinity result ;
  if (mProxyPtr != nullptr) {
    acStrongPtr_class * strongPtr = mProxyPtr->strongObject () ;
    if (strongPtr == nullptr) {
      inCompiler->onTheFlySemanticError ("weak reference is nil" COMMA_THERE) ;
    }else{
      macroValidSharedObject (strongPtr, cPtr_typeAssignInfinity) ;
      result = GGS_typeAssignInfinity ((cPtr_typeAssignInfinity *) strongPtr) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//     @typeAssignInfinity.weak generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAssignInfinity_2E_weak ("typeAssignInfinity.weak",
                                                                               & kTypeDescriptor_GALGAS_typePostcondition_2E_weak) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAssignInfinity_2E_weak::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity_2E_weak ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAssignInfinity_2E_weak::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAssignInfinity_2E_weak (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity_2E_weak GGS_typeAssignInfinity_2E_weak::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS_typeAssignInfinity_2E_weak result ;
  const GGS_typeAssignInfinity_2E_weak * p = (const GGS_typeAssignInfinity_2E_weak *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAssignInfinity_2E_weak *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeAssignInfinity.weak", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Class for element of '@typePostconditionList' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typePostconditionList : public cCollectionElement {
  public: GGS_typePostconditionList_2E_element mObject ;

//--- Class functions
  public: cCollectionElement_typePostconditionList (const GGS_typePostcondition & in_mPostcondition
                                                    COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typePostconditionList (const GGS_typePostconditionList_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GGS_typePostcondition & in_mPostcondition
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mPostcondition) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typePostconditionList::cCollectionElement_typePostconditionList (const GGS_typePostconditionList_2E_element & inElement COMMA_LOCATION_ARGS) :
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
// List type @typePostconditionList
//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList::GGS_typePostconditionList (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList::GGS_typePostconditionList (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement_typePostconditionList * p = (cCollectionElement_typePostconditionList *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement_typePostconditionList) ;
    const GGS_typePostconditionList_2E_element element (p->mObject.mProperty_mPostcondition) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GGS_typePostcondition & in_mPostcondition
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_typePostconditionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typePostconditionList (in_mPostcondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typePostconditionList::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS_typePostconditionList::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mPostcondition:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mPostcondition.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS_typePostconditionList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typePostconditionList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::plusPlusAssignOperation (const GGS_typePostconditionList_2E_element & inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::class_func_listWithValue (const GGS_typePostcondition & inOperand0
                                                                               COMMA_LOCATION_ARGS) {
  const GGS_typePostconditionList_2E_element element (inOperand0) ;
  GGS_typePostconditionList result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::addAssignOperation (const GGS_typePostcondition & inOperand0
                                                    COMMA_LOCATION_ARGS) {
  const GGS_typePostconditionList_2E_element newElement (inOperand0) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_append (const GGS_typePostcondition inOperand0,
                                               Compiler * /* inCompiler */
                                               COMMA_LOCATION_ARGS) {
  const GGS_typePostconditionList_2E_element newElement (inOperand0) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_insertAtIndex (const GGS_typePostcondition inOperand0,
                                                      const GGS_uint inInsertionIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  const GGS_typePostconditionList_2E_element newElement (inOperand0) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_removeAtIndex (GGS_typePostcondition & outOperand0,
                                                      const GGS_uint inRemoveIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mPostcondition ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_popFirst (GGS_typePostcondition & outOperand0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mPostcondition ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_popLast (GGS_typePostcondition & outOperand0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mPostcondition ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::method_first (GGS_typePostcondition & outOperand0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mPostcondition ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::method_last (GGS_typePostcondition & outOperand0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mPostcondition ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::add_operation (const GGS_typePostconditionList & inOperand,
                                                                    Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::subList (const int32_t inStart,
                                                              const int32_t inLength,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::getter_subListWithRange (const GGS_range & inRange,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::getter_subListFromIndex (const GGS_uint & inIndex,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::getter_subListToIndex (const GGS_uint & inIndex,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::plusAssignOperation (const GGS_typePostconditionList inList,
                                                     Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList::setter_setMPostconditionAtIndex (GGS_typePostcondition inOperand,
                                                                 GGS_uint inIndex,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mPostcondition = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_typePostcondition GGS_typePostconditionList::getter_mPostconditionAtIndex (const GGS_uint & inIndex,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GGS_typePostcondition result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mPostcondition ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @typePostconditionList
//--------------------------------------------------------------------------------------------------

DownEnumerator_typePostconditionList::DownEnumerator_typePostconditionList (const GGS_typePostconditionList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element DownEnumerator_typePostconditionList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition DownEnumerator_typePostconditionList::current_mPostcondition (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPostcondition ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @typePostconditionList
//--------------------------------------------------------------------------------------------------

UpEnumerator_typePostconditionList::UpEnumerator_typePostconditionList (const GGS_typePostconditionList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element UpEnumerator_typePostconditionList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition UpEnumerator_typePostconditionList::current_mPostcondition (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPostcondition ;
}




//--------------------------------------------------------------------------------------------------
//     @typePostconditionList generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostconditionList ("typePostconditionList",
                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostconditionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostconditionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostconditionList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList GGS_typePostconditionList::extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GGS_typePostconditionList result ;
  const GGS_typePostconditionList * p = (const GGS_typePostconditionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostconditionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Class for element of '@typeTransitionList' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typeTransitionList : public cCollectionElement {
  public: GGS_typeTransitionList_2E_element mObject ;

//--- Class functions
  public: cCollectionElement_typeTransitionList (const GGS_lstring & in_mTransitionName,
                                                 const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                 const GGS_typePostconditionList & in_mPostconditionList,
                                                 const GGS_uint & in_mLowTemporalBound,
                                                 const GGS_uint & in_mHighTemporalBound
                                                 COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typeTransitionList (const GGS_typeTransitionList_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GGS_lstring & in_mTransitionName,
                                                                              const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                                              const GGS_typePostconditionList & in_mPostconditionList,
                                                                              const GGS_uint & in_mLowTemporalBound,
                                                                              const GGS_uint & in_mHighTemporalBound
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mTransitionName, in_mPreconditionExpression, in_mPostconditionList, in_mLowTemporalBound, in_mHighTemporalBound) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeTransitionList::cCollectionElement_typeTransitionList (const GGS_typeTransitionList_2E_element & inElement COMMA_LOCATION_ARGS) :
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
// List type @typeTransitionList
//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList::GGS_typeTransitionList (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList::GGS_typeTransitionList (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement_typeTransitionList * p = (cCollectionElement_typeTransitionList *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement_typeTransitionList) ;
    const GGS_typeTransitionList_2E_element element (p->mObject.mProperty_mTransitionName, p->mObject.mProperty_mPreconditionExpression, p->mObject.mProperty_mPostconditionList, p->mObject.mProperty_mLowTemporalBound, p->mObject.mProperty_mHighTemporalBound) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                        const GGS_lstring & in_mTransitionName,
                                                        const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                        const GGS_typePostconditionList & in_mPostconditionList,
                                                        const GGS_uint & in_mLowTemporalBound,
                                                        const GGS_uint & in_mHighTemporalBound
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement_typeTransitionList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeTransitionList (in_mTransitionName, in_mPreconditionExpression, in_mPostconditionList, in_mLowTemporalBound, in_mHighTemporalBound COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeTransitionList::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS_typeTransitionList::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::description (String & ioString,
                                          const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mTransitionName:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mTransitionName.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mPreconditionExpression:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mPreconditionExpression.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mPostconditionList:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mPostconditionList.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mLowTemporalBound:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mLowTemporalBound.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mHighTemporalBound:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mHighTemporalBound.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS_typeTransitionList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeTransitionList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::plusPlusAssignOperation (const GGS_typeTransitionList_2E_element & inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::class_func_listWithValue (const GGS_lstring & inOperand0,
                                                                         const GGS_typePreconditionExpression & inOperand1,
                                                                         const GGS_typePostconditionList & inOperand2,
                                                                         const GGS_uint & inOperand3,
                                                                         const GGS_uint & inOperand4
                                                                         COMMA_LOCATION_ARGS) {
  const GGS_typeTransitionList_2E_element element (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  GGS_typeTransitionList result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::addAssignOperation (const GGS_lstring & inOperand0,
                                                 const GGS_typePreconditionExpression & inOperand1,
                                                 const GGS_typePostconditionList & inOperand2,
                                                 const GGS_uint & inOperand3,
                                                 const GGS_uint & inOperand4
                                                 COMMA_LOCATION_ARGS) {
  const GGS_typeTransitionList_2E_element newElement (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_append (const GGS_lstring inOperand0,
                                            const GGS_typePreconditionExpression inOperand1,
                                            const GGS_typePostconditionList inOperand2,
                                            const GGS_uint inOperand3,
                                            const GGS_uint inOperand4,
                                            Compiler * /* inCompiler */
                                            COMMA_LOCATION_ARGS) {
  const GGS_typeTransitionList_2E_element newElement (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_insertAtIndex (const GGS_lstring inOperand0,
                                                   const GGS_typePreconditionExpression inOperand1,
                                                   const GGS_typePostconditionList inOperand2,
                                                   const GGS_uint inOperand3,
                                                   const GGS_uint inOperand4,
                                                   const GGS_uint inInsertionIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  const GGS_typeTransitionList_2E_element newElement (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_removeAtIndex (GGS_lstring & outOperand0,
                                                   GGS_typePreconditionExpression & outOperand1,
                                                   GGS_typePostconditionList & outOperand2,
                                                   GGS_uint & outOperand3,
                                                   GGS_uint & outOperand4,
                                                   const GGS_uint inRemoveIndex,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mTransitionName ;
      outOperand1 = mArray (idx COMMA_HERE).mProperty_mPreconditionExpression ;
      outOperand2 = mArray (idx COMMA_HERE).mProperty_mPostconditionList ;
      outOperand3 = mArray (idx COMMA_HERE).mProperty_mLowTemporalBound ;
      outOperand4 = mArray (idx COMMA_HERE).mProperty_mHighTemporalBound ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_popFirst (GGS_lstring & outOperand0,
                                              GGS_typePreconditionExpression & outOperand1,
                                              GGS_typePostconditionList & outOperand2,
                                              GGS_uint & outOperand3,
                                              GGS_uint & outOperand4,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mTransitionName ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mPreconditionExpression ;
      outOperand2 = mArray (0 COMMA_THERE).mProperty_mPostconditionList ;
      outOperand3 = mArray (0 COMMA_THERE).mProperty_mLowTemporalBound ;
      outOperand4 = mArray (0 COMMA_THERE).mProperty_mHighTemporalBound ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_popLast (GGS_lstring & outOperand0,
                                             GGS_typePreconditionExpression & outOperand1,
                                             GGS_typePostconditionList & outOperand2,
                                             GGS_uint & outOperand3,
                                             GGS_uint & outOperand4,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mTransitionName ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mPreconditionExpression ;
      outOperand2 = mArray.lastObject (HERE).mProperty_mPostconditionList ;
      outOperand3 = mArray.lastObject (HERE).mProperty_mLowTemporalBound ;
      outOperand4 = mArray.lastObject (HERE).mProperty_mHighTemporalBound ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::method_first (GGS_lstring & outOperand0,
                                           GGS_typePreconditionExpression & outOperand1,
                                           GGS_typePostconditionList & outOperand2,
                                           GGS_uint & outOperand3,
                                           GGS_uint & outOperand4,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mTransitionName ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mPreconditionExpression ;
      outOperand2 = mArray (0 COMMA_THERE).mProperty_mPostconditionList ;
      outOperand3 = mArray (0 COMMA_THERE).mProperty_mLowTemporalBound ;
      outOperand4 = mArray (0 COMMA_THERE).mProperty_mHighTemporalBound ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::method_last (GGS_lstring & outOperand0,
                                          GGS_typePreconditionExpression & outOperand1,
                                          GGS_typePostconditionList & outOperand2,
                                          GGS_uint & outOperand3,
                                          GGS_uint & outOperand4,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mTransitionName ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mPreconditionExpression ;
      outOperand2 = mArray.lastObject (HERE).mProperty_mPostconditionList ;
      outOperand3 = mArray.lastObject (HERE).mProperty_mLowTemporalBound ;
      outOperand4 = mArray.lastObject (HERE).mProperty_mHighTemporalBound ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
    outOperand2.drop () ;
    outOperand3.drop () ;
    outOperand4.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::add_operation (const GGS_typeTransitionList & inOperand,
                                                              Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_typeTransitionList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::subList (const int32_t inStart,
                                                        const int32_t inLength,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const {
  GGS_typeTransitionList result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::getter_subListWithRange (const GGS_range & inRange,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GGS_typeTransitionList result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::getter_subListFromIndex (const GGS_uint & inIndex,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GGS_typeTransitionList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::getter_subListToIndex (const GGS_uint & inIndex,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GGS_typeTransitionList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::plusAssignOperation (const GGS_typeTransitionList inList,
                                                  Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_setMTransitionNameAtIndex (GGS_lstring inOperand,
                                                               GGS_uint inIndex,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mTransitionName = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS_typeTransitionList::getter_mTransitionNameAtIndex (const GGS_uint & inIndex,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mTransitionName ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_setMPreconditionExpressionAtIndex (GGS_typePreconditionExpression inOperand,
                                                                       GGS_uint inIndex,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mPreconditionExpression = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_typePreconditionExpression GGS_typeTransitionList::getter_mPreconditionExpressionAtIndex (const GGS_uint & inIndex,
                                                                                              Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const {
  GGS_typePreconditionExpression result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mPreconditionExpression ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_setMPostconditionListAtIndex (GGS_typePostconditionList inOperand,
                                                                  GGS_uint inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mPostconditionList = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_typePostconditionList GGS_typeTransitionList::getter_mPostconditionListAtIndex (const GGS_uint & inIndex,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GGS_typePostconditionList result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mPostconditionList ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_setMLowTemporalBoundAtIndex (GGS_uint inOperand,
                                                                 GGS_uint inIndex,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mLowTemporalBound = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_uint GGS_typeTransitionList::getter_mLowTemporalBoundAtIndex (const GGS_uint & inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mLowTemporalBound ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList::setter_setMHighTemporalBoundAtIndex (GGS_uint inOperand,
                                                                  GGS_uint inIndex,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mHighTemporalBound = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_uint GGS_typeTransitionList::getter_mHighTemporalBoundAtIndex (const GGS_uint & inIndex,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mHighTemporalBound ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @typeTransitionList
//--------------------------------------------------------------------------------------------------

DownEnumerator_typeTransitionList::DownEnumerator_typeTransitionList (const GGS_typeTransitionList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element DownEnumerator_typeTransitionList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_typeTransitionList::current_mTransitionName (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mTransitionName ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression DownEnumerator_typeTransitionList::current_mPreconditionExpression (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPreconditionExpression ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList DownEnumerator_typeTransitionList::current_mPostconditionList (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPostconditionList ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_typeTransitionList::current_mLowTemporalBound (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mLowTemporalBound ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint DownEnumerator_typeTransitionList::current_mHighTemporalBound (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mHighTemporalBound ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @typeTransitionList
//--------------------------------------------------------------------------------------------------

UpEnumerator_typeTransitionList::UpEnumerator_typeTransitionList (const GGS_typeTransitionList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element UpEnumerator_typeTransitionList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_typeTransitionList::current_mTransitionName (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mTransitionName ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression UpEnumerator_typeTransitionList::current_mPreconditionExpression (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPreconditionExpression ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList UpEnumerator_typeTransitionList::current_mPostconditionList (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mPostconditionList ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_typeTransitionList::current_mLowTemporalBound (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mLowTemporalBound ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint UpEnumerator_typeTransitionList::current_mHighTemporalBound (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mHighTemporalBound ;
}




//--------------------------------------------------------------------------------------------------
//     @typeTransitionList generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeTransitionList ("typeTransitionList",
                                                                       nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeTransitionList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeTransitionList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeTransitionList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList GGS_typeTransitionList::extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GGS_typeTransitionList result ;
  const GGS_typeTransitionList * p = (const GGS_typeTransitionList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeTransitionList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Class for element of '@typeInitialMarkingList' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement_typeInitialMarkingList : public cCollectionElement {
  public: GGS_typeInitialMarkingList_2E_element mObject ;

//--- Class functions
  public: cCollectionElement_typeInitialMarkingList (const GGS_typePostcondition & in_mInitValue
                                                     COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_typeInitialMarkingList (const GGS_typeInitialMarkingList_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GGS_typePostcondition & in_mInitValue
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mInitValue) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_typeInitialMarkingList::cCollectionElement_typeInitialMarkingList (const GGS_typeInitialMarkingList_2E_element & inElement COMMA_LOCATION_ARGS) :
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
// List type @typeInitialMarkingList
//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList::GGS_typeInitialMarkingList (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList::GGS_typeInitialMarkingList (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement_typeInitialMarkingList * p = (cCollectionElement_typeInitialMarkingList *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement_typeInitialMarkingList) ;
    const GGS_typeInitialMarkingList_2E_element element (p->mObject.mProperty_mInitValue) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                            const GGS_typePostcondition & in_mInitValue
                                                            COMMA_LOCATION_ARGS) {
  cCollectionElement_typeInitialMarkingList * p = nullptr ;
  macroMyNew (p, cCollectionElement_typeInitialMarkingList (in_mInitValue COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeInitialMarkingList::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS_typeInitialMarkingList::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::description (String & ioString,
                                              const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mInitValue:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mInitValue.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS_typeInitialMarkingList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeInitialMarkingList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::plusPlusAssignOperation (const GGS_typeInitialMarkingList_2E_element & inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::class_func_listWithValue (const GGS_typePostcondition & inOperand0
                                                                                 COMMA_LOCATION_ARGS) {
  const GGS_typeInitialMarkingList_2E_element element (inOperand0) ;
  GGS_typeInitialMarkingList result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::addAssignOperation (const GGS_typePostcondition & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  const GGS_typeInitialMarkingList_2E_element newElement (inOperand0) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_append (const GGS_typePostcondition inOperand0,
                                                Compiler * /* inCompiler */
                                                COMMA_LOCATION_ARGS) {
  const GGS_typeInitialMarkingList_2E_element newElement (inOperand0) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_insertAtIndex (const GGS_typePostcondition inOperand0,
                                                       const GGS_uint inInsertionIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  const GGS_typeInitialMarkingList_2E_element newElement (inOperand0) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_removeAtIndex (GGS_typePostcondition & outOperand0,
                                                       const GGS_uint inRemoveIndex,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mInitValue ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_popFirst (GGS_typePostcondition & outOperand0,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mInitValue ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_popLast (GGS_typePostcondition & outOperand0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mInitValue ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::method_first (GGS_typePostcondition & outOperand0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mInitValue ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::method_last (GGS_typePostcondition & outOperand0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mInitValue ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::add_operation (const GGS_typeInitialMarkingList & inOperand,
                                                                      Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_typeInitialMarkingList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::subList (const int32_t inStart,
                                                                const int32_t inLength,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  GGS_typeInitialMarkingList result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::getter_subListWithRange (const GGS_range & inRange,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GGS_typeInitialMarkingList result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::getter_subListFromIndex (const GGS_uint & inIndex,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GGS_typeInitialMarkingList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::getter_subListToIndex (const GGS_uint & inIndex,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GGS_typeInitialMarkingList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::plusAssignOperation (const GGS_typeInitialMarkingList inList,
                                                      Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList::setter_setMInitValueAtIndex (GGS_typePostcondition inOperand,
                                                              GGS_uint inIndex,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mInitValue = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_typePostcondition GGS_typeInitialMarkingList::getter_mInitValueAtIndex (const GGS_uint & inIndex,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GGS_typePostcondition result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mInitValue ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @typeInitialMarkingList
//--------------------------------------------------------------------------------------------------

DownEnumerator_typeInitialMarkingList::DownEnumerator_typeInitialMarkingList (const GGS_typeInitialMarkingList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element DownEnumerator_typeInitialMarkingList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition DownEnumerator_typeInitialMarkingList::current_mInitValue (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mInitValue ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @typeInitialMarkingList
//--------------------------------------------------------------------------------------------------

UpEnumerator_typeInitialMarkingList::UpEnumerator_typeInitialMarkingList (const GGS_typeInitialMarkingList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element UpEnumerator_typeInitialMarkingList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostcondition UpEnumerator_typeInitialMarkingList::current_mInitValue (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mInitValue ;
}




//--------------------------------------------------------------------------------------------------
//     @typeInitialMarkingList generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeInitialMarkingList ("typeInitialMarkingList",
                                                                           nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeInitialMarkingList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeInitialMarkingList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeInitialMarkingList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList GGS_typeInitialMarkingList::extractObject (const GGS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GGS_typeInitialMarkingList result ;
  const GGS_typeInitialMarkingList * p = (const GGS_typeInitialMarkingList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeInitialMarkingList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Class for element of '@countList' list
//--------------------------------------------------------------------------------------------------

class cCollectionElement_countList : public cCollectionElement {
  public: GGS_countList_2E_element mObject ;

//--- Class functions
  public: cCollectionElement_countList (const GGS_lstring & in_mName,
                                        const GGS_typePreconditionExpression & in_mCondition
                                        COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_countList (const GGS_countList_2E_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;
} ;

//--------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GGS_lstring & in_mName,
                                                            const GGS_typePreconditionExpression & in_mCondition
                                                            COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_mName, in_mCondition) {
}

//--------------------------------------------------------------------------------------------------

cCollectionElement_countList::cCollectionElement_countList (const GGS_countList_2E_element & inElement COMMA_LOCATION_ARGS) :
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
// List type @countList
//--------------------------------------------------------------------------------------------------

GGS_countList::GGS_countList (void) :
mArray () {
}

//--------------------------------------------------------------------------------------------------

GGS_countList::GGS_countList (const capCollectionElementArray & inArray) :
mArray () {
  mArray.setCapacity (std::max (16, int32_t (inArray.count ()))) ;
  for (uint32_t i = 0 ; i < inArray.count () ; i++) {
    const capCollectionElement v = inArray.objectAtIndex (i COMMA_HERE) ;
    cCollectionElement_countList * p = (cCollectionElement_countList *) v.ptr () ;
    macroValidSharedObject (p, cCollectionElement_countList) ;
    const GGS_countList_2E_element element (p->mObject.mProperty_mName, p->mObject.mProperty_mCondition) ;
    mArray.appendObject (element) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                               const GGS_lstring & in_mName,
                                               const GGS_typePreconditionExpression & in_mCondition
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_countList * p = nullptr ;
  macroMyNew (p, cCollectionElement_countList (in_mName, in_mCondition COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_countList::getter_count (UNUSED_LOCATION_ARGS) const {
  GGS_uint result ;
  if (isValid ()) {
    result = GGS_uint (count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_range GGS_countList::getter_range (UNUSED_LOCATION_ARGS) const {
  GGS_range result ;
  if (isValid ()) {
    result = GGS_range (0, count ()) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::description (String & ioString,
                                 const int32_t inIndentation) const {
  ioString.appendCString ("<list @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (" (") ;
  ioString.appendUnsigned (count()) ;
  ioString.appendCString (" object") ;
  ioString.appendString ((count() > 1) ? "s" : "") ;
  ioString.appendCString ("):") ;
  if (isValid ()) {
    for (uint32_t i = 0 ; i < count () ; i++) {
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation) ;
      ioString.appendString ("|-at ") ;
      ioString.appendUnsigned (i) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mName:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mName.description (ioString, inIndentation + 1) ;
      ioString.appendNewLine () ;
      ioString.appendStringMultiple ("| ", inIndentation + 1) ;
      ioString.appendString ("mCondition:") ;
      mArray (int32_t (i) COMMA_HERE).mProperty_mCondition.description (ioString, inIndentation + 1) ;
    }
  }else{
    ioString.appendCString (" not built") ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::class_func_emptyList (UNUSED_LOCATION_ARGS) {
  GGS_countList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::init (Compiler * COMMA_UNUSED_LOCATION_ARGS) {
  GGS_countList result ;
  result.mArray.setCapacity (16) ; // Build
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::plusPlusAssignOperation (const GGS_countList_2E_element & inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inValue.isValid ()) {
    mArray.appendObject (inValue) ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::class_func_listWithValue (const GGS_lstring & inOperand0,
                                                       const GGS_typePreconditionExpression & inOperand1
                                                       COMMA_LOCATION_ARGS) {
  const GGS_countList_2E_element element (inOperand0, inOperand1) ;
  GGS_countList result ;
  if (element.isValid ()) {
    result.mArray.setCapacity (16) ; // Build
    result.plusPlusAssignOperation (element COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::addAssignOperation (const GGS_lstring & inOperand0,
                                        const GGS_typePreconditionExpression & inOperand1
                                        COMMA_LOCATION_ARGS) {
  const GGS_countList_2E_element newElement (inOperand0, inOperand1) ;
  plusPlusAssignOperation (newElement COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_append (const GGS_lstring inOperand0,
                                   const GGS_typePreconditionExpression inOperand1,
                                   Compiler * /* inCompiler */
                                   COMMA_LOCATION_ARGS) {
  const GGS_countList_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && newElement.isValid ()) {
    plusPlusAssignOperation (newElement COMMA_THERE) ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_insertAtIndex (const GGS_lstring inOperand0,
                                          const GGS_typePreconditionExpression inOperand1,
                                          const GGS_uint inInsertionIndex,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  const GGS_countList_2E_element newElement (inOperand0, inOperand1) ;
  if (isValid () && inInsertionIndex.isValid () && newElement.isValid ()) {
    const int32_t idx = int32_t (inInsertionIndex.uintValue ()) ;
    if (idx <= mArray.count ()) {
      mArray.insertObjectAtIndex (newElement, idx COMMA_THERE) ;
    }else{
      String message = "cannot insert at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_removeAtIndex (GGS_lstring & outOperand0,
                                          GGS_typePreconditionExpression & outOperand1,
                                          const GGS_uint inRemoveIndex,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid () && inRemoveIndex.isValid ()) {
    const int32_t idx = int32_t (inRemoveIndex.uintValue ()) ;
    if (idx < mArray.count ()) {
      removed = true ;
      outOperand0 = mArray (idx COMMA_HERE).mProperty_mName ;
      outOperand1 = mArray (idx COMMA_HERE).mProperty_mCondition ;
      mArray.removeObjectAtIndex (idx COMMA_HERE) ;
    }else{
      String message = "cannot remove at index " ;
      message.appendSigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_popFirst (GGS_lstring & outOperand0,
                                     GGS_typePreconditionExpression & outOperand1,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mName ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mCondition ;
      mArray.removeObjectAtIndex (0 COMMA_HERE) ;
    }else{
      const String message = "cannot remove first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_popLast (GGS_lstring & outOperand0,
                                    GGS_typePreconditionExpression & outOperand1,
                                    Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  bool removed = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      removed = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mName ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mCondition ;
      mArray.removeLastObject (HERE) ;
    }else{
      const String message = "cannot remove last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!removed) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::method_first (GGS_lstring & outOperand0,
                                  GGS_typePreconditionExpression & outOperand1,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray (0 COMMA_THERE).mProperty_mName ;
      outOperand1 = mArray (0 COMMA_THERE).mProperty_mCondition ;
    }else{
      const String message = "cannot get first element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::method_last (GGS_lstring & outOperand0,
                                 GGS_typePreconditionExpression & outOperand1,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) const {
  bool found = false ;
  if (isValid ()) {
    if (mArray.count () > 0) {
      found = true ;
      outOperand0 = mArray.lastObject (HERE).mProperty_mName ;
      outOperand1 = mArray.lastObject (HERE).mProperty_mCondition ;
    }else{
      const String message = "cannot get last element, list is empty" ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  if (!found) {
    outOperand0.drop () ;
    outOperand1.drop () ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::add_operation (const GGS_countList & inOperand,
                                            Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_countList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.mArray.setCapacity (1 + result.mArray.count () + inOperand.mArray.count ()) ;
    for (int32_t i = 0 ; i < inOperand.mArray.count () ; i++) {
      result.mArray.appendObject (inOperand.mArray (i COMMA_HERE)) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::subList (const int32_t inStart,
                                      const int32_t inLength,
                                      Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) const {
  GGS_countList result ;
  const bool ok = (inStart >= 0) && (inLength >= 0) && ((inStart + inLength) <= int32_t (count ())) ;
  if (ok) {
    result.mArray.setCapacity (std::max (16, inLength)) ;
    for (int32_t i = inStart ; i < (inStart + inLength) ; i++) {
      result.mArray.appendObject (mArray (i COMMA_HERE)) ;
    }
  }else{
    String message = "cannot get sublist [start: " ;
    message.appendSigned (inStart) ;
    message.appendCString (", length: ") ;
    message.appendSigned (inLength) ;
    message.appendCString ("], list count is ") ;
    message.appendSigned (mArray.count ()) ;
    inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::getter_subListWithRange (const GGS_range & inRange,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GGS_countList result ;
  if (isValid () && inRange.isValid ()) {
    const int32_t start  = int32_t (inRange.mProperty_start.uintValue ()) ;
    const int32_t length = int32_t (inRange.mProperty_length.uintValue ()) ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::getter_subListFromIndex (const GGS_uint & inIndex,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  GGS_countList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = int32_t (inIndex.uintValue ()) ;
    const int32_t length = int32_t (count ()) - start ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::getter_subListToIndex (const GGS_uint & inIndex,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  GGS_countList result ;
  if (isValid () && inIndex.isValid ()) {
    const int32_t start  = 0 ;
    const int32_t length = int32_t (inIndex.uintValue ()) + 1 ;
    result = subList (start, length, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::plusAssignOperation (const GGS_countList inList,
                                         Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  if (isValid () && inList.isValid ()) {
    mArray.setCapacity (1 + mArray.count () + inList.mArray.count ()) ;
    for (int32_t i=0 ; i < int32_t (inList.count ()) ; i++) {
      mArray.appendObject (inList.mArray (i COMMA_HERE)) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_setMNameAtIndex (GGS_lstring inOperand,
                                            GGS_uint inIndex,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mName = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_lstring GGS_countList::getter_mNameAtIndex (const GGS_uint & inIndex,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  GGS_lstring result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mName ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------

void GGS_countList::setter_setMConditionAtIndex (GGS_typePreconditionExpression inOperand,
                                                 GGS_uint inIndex,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand.isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      mArray (int32_t (idx) COMMA_HERE).mProperty_mCondition = inOperand ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
  
GGS_typePreconditionExpression GGS_countList::getter_mConditionAtIndex (const GGS_uint & inIndex,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  GGS_typePreconditionExpression result ;
  if (isValid () && inIndex.isValid ()) {
    const uint32_t idx = inIndex.uintValue () ;
    if (idx < count ()) {
      result = mArray (int32_t (idx) COMMA_HERE).mProperty_mCondition ;
    }else{
      String message = "cannot access at index " ;
      message.appendUnsigned (idx) ;
      message.appendCString (", list count is ") ;
      message.appendSigned (mArray.count ()) ;
      inCompiler->onTheFlySemanticError (message COMMA_THERE) ;
    }
  }
  return result ;
}
//--------------------------------------------------------------------------------------------------
// Down Enumerator for @countList
//--------------------------------------------------------------------------------------------------

DownEnumerator_countList::DownEnumerator_countList (const GGS_countList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
  mIndex = mArray.count () - 1 ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element DownEnumerator_countList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring DownEnumerator_countList::current_mName (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mName ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression DownEnumerator_countList::current_mCondition (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mCondition ;
}



//--------------------------------------------------------------------------------------------------
// Up Enumerator for @countList
//--------------------------------------------------------------------------------------------------

UpEnumerator_countList::UpEnumerator_countList (const GGS_countList & inEnumeratedObject) :
mArray (inEnumeratedObject.sortedElementArray ()),
mIndex (0) {
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element UpEnumerator_countList::current (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE) ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring UpEnumerator_countList::current_mName (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mName ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePreconditionExpression UpEnumerator_countList::current_mCondition (LOCATION_ARGS) const {
  return mArray (mIndex COMMA_THERE).mProperty_mCondition ;
}




//--------------------------------------------------------------------------------------------------
//     @countList generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_countList ("countList",
                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_countList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_countList::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_countList (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList GGS_countList::extractObject (const GGS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GGS_countList result ;
  const GGS_countList * p = (const GGS_countList *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_countList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_precondition_i0_ (GGS_typeVarMap & ioArgument_inPlacesMap,
                                                                            GGS_typeCstMap & ioArgument_ioConstantMap,
                                                                            GGS_typePreconditionExpression & outArgument_outPreConditions,
                                                                            Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 60)) ;
      GGS_typePreconditionExpression var_right_1770 ;
      nt_term_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_1770, inCompiler) ;
      outArgument_outPreConditions = GGS_typeOrExpression::init_21__21_ (outArgument_outPreConditions, var_right_1770, inCompiler COMMA_HERE) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_term_i1_ (GGS_typeVarMap & ioArgument_inPlacesMap,
                                                           GGS_typeCstMap & ioArgument_ioConstantMap,
                                                           GGS_typePreconditionExpression & outArgument_outPreConditions,
                                                           Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_spec_5F_parser_1 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__26_ COMMA_SOURCE_FILE ("spec_parser.ggs", 75)) ;
      GGS_typePreconditionExpression var_right_2219 ;
      nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, var_right_2219, inCompiler) ;
      outArgument_outPreConditions = GGS_typeAndExpression::init_21__21_ (outArgument_outPreConditions, var_right_2219, inCompiler COMMA_HERE) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_factor_i2_ (GGS_typeVarMap & ioArgument_inPlacesMap,
                                                             GGS_typeCstMap & ioArgument_ioConstantMap,
                                                             GGS_typePreconditionExpression & outArgument_outPreConditions,
                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPreConditions.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 88)) ;
    nt_factor_ (ioArgument_inPlacesMap, ioArgument_ioConstantMap, outArgument_outPreConditions, inCompiler) ;
    outArgument_outPreConditions = GGS_typeComplementExpression::init_21_ (outArgument_outPreConditions, inCompiler COMMA_HERE) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_primary_i3_ (GGS_typeVarMap & ioArgument_inPlacesMap,
                                                              GGS_typeCstMap & ioArgument_ioConstantMap,
                                                              GGS_typePreconditionExpression & outArgument_outPreConditions,
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
    outArgument_outPreConditions = GGS_typeTrueExpression::init (inCompiler COMMA_HERE) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_false COMMA_SOURCE_FILE ("spec_parser.ggs", 110)) ;
    outArgument_outPreConditions = GGS_typeFalseExpression::init (inCompiler COMMA_HERE) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__7B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 113)) ;
    GGS_lstring var_name_3250 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 114)) ;
    GGS_uint var_idx_3295 ;
    ioArgument_inPlacesMap.method_searchKey (var_name_3250, var_idx_3295, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 115)) ;
    switch (select_spec_5F_parser_4 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 117)) ;
      GGS_bool var_sign_3368 ;
      GGS_luint var_cst_3379 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3368, var_cst_3379, inCompiler) ;
      outArgument_outPreConditions = GGS_typeEqualExpression::init_21__21__21_ (var_idx_3295, var_sign_3368, var_cst_3379, inCompiler COMMA_HERE) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__21__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 121)) ;
      GGS_bool var_sign_3515 ;
      GGS_luint var_cst_3526 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3515, var_cst_3526, inCompiler) ;
      outArgument_outPreConditions = GGS_typeNonEqualExpression::init_21__21__21_ (var_idx_3295, var_sign_3515, var_cst_3526, inCompiler COMMA_HERE) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 125)) ;
      GGS_bool var_sign_3665 ;
      GGS_luint var_cst_3676 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3665, var_cst_3676, inCompiler) ;
      outArgument_outPreConditions = GGS_typeInfOrEqualExpression::init_21__21__21_ (var_idx_3295, var_sign_3665, var_cst_3676, inCompiler COMMA_HERE) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 129)) ;
      GGS_bool var_sign_3817 ;
      GGS_luint var_cst_3828 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3817, var_cst_3828, inCompiler) ;
      outArgument_outPreConditions = GGS_typeSupOrEqualExpression::init_21__21__21_ (var_idx_3295, var_sign_3817, var_cst_3828, inCompiler COMMA_HERE) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 133)) ;
      GGS_bool var_sign_3968 ;
      GGS_luint var_cst_3979 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_3968, var_cst_3979, inCompiler) ;
      outArgument_outPreConditions = GGS_typeStrictInfExpression::init_21__21__21_ (var_idx_3295, var_sign_3968, var_cst_3979, inCompiler COMMA_HERE) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("spec_parser.ggs", 137)) ;
      GGS_bool var_sign_4118 ;
      GGS_luint var_cst_4129 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_4118, var_cst_4129, inCompiler) ;
      outArgument_outPreConditions = GGS_typeStrictSupExpression::init_21__21__21_ (var_idx_3295, var_sign_4118, var_cst_4129, inCompiler COMMA_HERE) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_constant_i4_ (GGS_typeCstMap & ioArgument_ioConstantMap,
                                                                        GGS_bool & outArgument_outSign,
                                                                        GGS_luint & outArgument_outValue,
                                                                        Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outSign.drop () ; // Release 'out' argument
  outArgument_outValue.drop () ; // Release 'out' argument
  switch (select_spec_5F_parser_5 (inCompiler)) {
  case 1: {
    GGS_lstring var_constantName_4456 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 152)) ;
    ioArgument_ioConstantMap.method_searchKey (var_constantName_4456, outArgument_outSign, outArgument_outValue, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 153)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 155)) ;
    outArgument_outSign = GGS_bool (true) ;
    outArgument_outValue = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 157)) ;
  } break ;
  case 3: {
    outArgument_outSign = GGS_bool (false) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_postcondition_i5_ (GGS_typeVarMap & ioArgument_outPlacesMap,
                                                                             GGS_typeCstMap & ioArgument_ioConstantMap,
                                                                             GGS_typePostconditionList & outArgument_outPostConditionsList,
                                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outPostConditionsList.drop () ; // Release 'out' argument
  outArgument_outPostConditionsList = GGS_typePostconditionList::init (inCompiler COMMA_HERE) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GGS_lstring var_name_4995 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 172)) ;
    GGS_uint var_idx_5041 ;
    ioArgument_outPlacesMap.method_searchKey (var_name_4995, var_idx_5041, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 173)) ;
    GGS_typePostcondition var_p_5073 ;
    switch (select_spec_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__2D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 176)) ;
      var_p_5073 = GGS_typePostDecrement::init_21__21_ (var_name_4995, var_idx_5041, inCompiler COMMA_HERE) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__2B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 179)) ;
      var_p_5073 = GGS_typePostIncrement::init_21__21_ (var_name_4995, var_idx_5041, inCompiler COMMA_HERE) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 182)) ;
      GGS_bool var_sign_5267 ;
      GGS_luint var_cst_5278 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5267, var_cst_5278, inCompiler) ;
      var_p_5073 = GGS_typeAddConstant::init_21__21__21__21_ (var_name_4995, var_idx_5041, var_sign_5267, var_cst_5278, inCompiler COMMA_HERE) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 186)) ;
      GGS_bool var_sign_5402 ;
      GGS_luint var_cst_5413 ;
      nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5402, var_cst_5413, inCompiler) ;
      var_p_5073 = GGS_typeSubConstant::init_21__21__21__21_ (var_name_4995, var_idx_5041, var_sign_5402, var_cst_5413, inCompiler COMMA_HERE) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 190)) ;
      switch (select_spec_5F_parser_8 (inCompiler)) {
      case 1: {
        GGS_bool var_sign_5552 ;
        GGS_luint var_cst_5563 ;
        nt_parse_5F_constant_ (ioArgument_ioConstantMap, var_sign_5552, var_cst_5563, inCompiler) ;
        var_p_5073 = GGS_typeAssignConstant::init_21__21__21__21_ (var_name_4995, var_idx_5041, var_sign_5552, var_cst_5563, inCompiler COMMA_HERE) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 195)) ;
        var_p_5073 = GGS_typeAssignInfinity::init_21__21_ (var_name_4995, var_idx_5041, inCompiler COMMA_HERE) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      break ;
    }
    {
    outArgument_outPostConditionsList.setter_append (var_p_5073, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 199)) ;
    }
    if (select_spec_5F_parser_6 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 201)) ;
    }else{
      repeatFlag_0 = false ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_ (GGS_uint & outArgument_lowTemporalBound,
                                                                     GGS_uint & outArgument_highTemporalBound,
                                                                     Lexique_spec_5F_scanner * /* inCompiler */) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  outArgument_lowTemporalBound = GGS_uint (uint32_t (0U)) ;
  outArgument_highTemporalBound = GGS_uint (uint32_t (0U)) ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_parse (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i6_indexing (Lexique_spec_5F_scanner * /* inCompiler */) {
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_parse_5F_bound_i7_ (GGS_uint & outArgument_lowTemporalBound,
                                                                     GGS_uint & outArgument_highTemporalBound,
                                                                     Lexique_spec_5F_scanner * inCompiler) {
  outArgument_lowTemporalBound.drop () ; // Release 'out' argument
  outArgument_highTemporalBound.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 219)) ;
  GGS_luint var_low_6217 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 220)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 221)) ;
  GGS_luint var_high_6254 = inCompiler->synthetizedAttribute_ulongValue () ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 222)) ;
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 223)) ;
  outArgument_lowTemporalBound = var_low_6217.readProperty_uint () ;
  outArgument_highTemporalBound = var_high_6254.readProperty_uint () ;
  GalgasBool test_0 = GalgasBool::boolTrue ;
  if (GalgasBool::boolTrue == test_0) {
    test_0 = GGS_bool (ComparisonKind::greaterThan, outArgument_lowTemporalBound.objectCompare (outArgument_highTemporalBound)).boolEnum () ;
    if (GalgasBool::boolTrue == test_0) {
      GenericArray <FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (var_high_6254.readProperty_location (), GGS_string ("High bound must be greater than or equal to low bound"), fixItArray1  COMMA_SOURCE_FILE ("spec_parser.ggs", 227)) ;
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

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_ (GGS_uint & outArgument_outHashMapSize,
                                                             GGS_uint & outArgument_outGarbagePeriod,
                                                             GGS_typeVarMap & outArgument_outPlacesMap,
                                                             GGS_typeTransitionList & outArgument_outTransitionList,
                                                             GGS_typeInitialMarkingList & outArgument_outInitialMarkingList,
                                                             GGS_countList & outArgument_outCountList,
                                                             Lexique_spec_5F_scanner * inCompiler) {
  outArgument_outHashMapSize.drop () ; // Release 'out' argument
  outArgument_outGarbagePeriod.drop () ; // Release 'out' argument
  outArgument_outPlacesMap.drop () ; // Release 'out' argument
  outArgument_outTransitionList.drop () ; // Release 'out' argument
  outArgument_outInitialMarkingList.drop () ; // Release 'out' argument
  outArgument_outCountList.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 240)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 243)) ;
    GGS_luint var_n_6856 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 244)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 245)) ;
    outArgument_outHashMapSize = var_n_6856.readProperty_uint () ;
  } break ;
  case 2: {
    outArgument_outHashMapSize = GGS_uint (uint32_t (16U)) ;
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 251)) ;
    GGS_luint var_n_6987 = inCompiler->synthetizedAttribute_ulongValue () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 253)) ;
    outArgument_outGarbagePeriod = var_n_6987.readProperty_uint () ;
  } break ;
  case 2: {
    outArgument_outGarbagePeriod = GGS_uint (uint32_t (16U)) ;
  } break ;
  default:
    break ;
  }
  outArgument_outTransitionList = GGS_typeTransitionList::init (inCompiler COMMA_HERE) ;
  outArgument_outPlacesMap = GGS_typeVarMap::init (inCompiler COMMA_HERE) ;
  GGS_typeCstMap var_constantMap_7148 = GGS_typeCstMap::init (inCompiler COMMA_HERE) ;
  outArgument_outCountList = GGS_countList::init (inCompiler COMMA_HERE) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_spec_5F_parser_11 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
      GGS_lstring var_constantName_7275 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 266)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 267)) ;
      GGS_bool var_sign_7339 ;
      GGS_luint var_value_7350 ;
      nt_parse_5F_constant_ (var_constantMap_7148, var_sign_7339, var_value_7350, inCompiler) ;
      {
      var_constantMap_7148.setter_insertKey (var_constantName_7275, var_sign_7339, var_value_7350, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 269)) ;
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 270)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 273)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        GGS_lstring var_placeName_7494 = inCompiler->synthetizedAttribute_theString () ;
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 275)) ;
        {
        outArgument_outPlacesMap.setter_insertKey (var_placeName_7494, outArgument_outPlacesMap.getter_count (SOURCE_FILE ("spec_parser.ggs", 276)), inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 276)) ;
        }
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
        }else{
          repeatFlag_1 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 280)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 283)) ;
      GGS_lstring var_transitionName_7666 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 284)) ;
      GGS_typePreconditionExpression var_preConditions_7744 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7148, var_preConditions_7744, inCompiler) ;
      GGS_uint var_lowTemporalBound_7783 ;
      GGS_uint var_highTemporalBound_7806 ;
      nt_parse_5F_bound_ (var_lowTemporalBound_7783, var_highTemporalBound_7806, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
      GGS_typePostconditionList var_postConditions_7896 ;
      nt_parse_5F_postcondition_ (outArgument_outPlacesMap, var_constantMap_7148, var_postConditions_7896, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 289)) ;
      {
      outArgument_outTransitionList.setter_append (var_transitionName_7666, var_preConditions_7744, var_postConditions_7896, var_lowTemporalBound_7783, var_highTemporalBound_7806, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 290)) ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
  outArgument_outInitialMarkingList = GGS_typeInitialMarkingList::init (inCompiler COMMA_HERE) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GGS_lstring var_placeName_8183 = inCompiler->synthetizedAttribute_theString () ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 302)) ;
    GGS_uint var_placeID_8239 ;
    outArgument_outPlacesMap.method_searchKey (var_placeName_8183, var_placeID_8239, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 303)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 304)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      GGS_bool var_sign_8312 ;
      GGS_luint var_cst_8323 ;
      nt_parse_5F_constant_ (var_constantMap_7148, var_sign_8312, var_cst_8323, inCompiler) ;
      GGS_typePostcondition var_initValue_8357 = GGS_typeAssignConstant::init_21__21__21__21_ (var_placeName_8183, var_placeID_8239, var_sign_8312, var_cst_8323, inCompiler COMMA_HERE) ;
      {
      outArgument_outInitialMarkingList.setter_append (var_initValue_8357, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 308)) ;
      }
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 310)) ;
      GGS_typePostcondition var_initValue_8528 = GGS_typeAssignInfinity::init_21__21_ (var_placeName_8183, var_placeID_8239, inCompiler COMMA_HERE) ;
      {
      outArgument_outInitialMarkingList.setter_append (var_initValue_8528, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 312)) ;
      }
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 315)) ;
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 317)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 321)) ;
      GGS_lstring var_name_8742 = inCompiler->synthetizedAttribute_theString () ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 323)) ;
      GGS_typePreconditionExpression var_conditions_8818 ;
      nt_parse_5F_precondition_ (outArgument_outPlacesMap, var_constantMap_7148, var_conditions_8818, inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 325)) ;
      {
      outArgument_outCountList.setter_append (var_name_8742, var_conditions_8818, inCompiler COMMA_SOURCE_FILE ("spec_parser.ggs", 326)) ;
      }
    }else{
      repeatFlag_3 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 328)) ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_parse (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 240)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 243)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 244)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 245)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 251)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 253)) ;
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
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 266)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 267)) ;
      nt_parse_5F_constant_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 270)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 273)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 275)) ;
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
        }else{
          repeatFlag_1 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 280)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 283)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 284)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      nt_parse_5F_bound_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
      nt_parse_5F_postcondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 289)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 302)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 304)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      nt_parse_5F_constant_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 310)) ;
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 315)) ;
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 317)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 321)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 323)) ;
      nt_parse_5F_precondition_parse (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 325)) ;
    }else{
      repeatFlag_3 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 328)) ;
  inCompiler->resetTemplateString () ;
}

//------------------------------------------------------------------------------------------------

void cParser_spec_5F_parser::rule_spec_5F_parser_axiome_i8_indexing (Lexique_spec_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_system COMMA_SOURCE_FILE ("spec_parser.ggs", 240)) ;
  switch (select_spec_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_hashmapsize COMMA_SOURCE_FILE ("spec_parser.ggs", 243)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 244)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 245)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_spec_5F_parser_10 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_garbageperiod COMMA_SOURCE_FILE ("spec_parser.ggs", 251)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_integer COMMA_SOURCE_FILE ("spec_parser.ggs", 252)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 253)) ;
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
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_const COMMA_SOURCE_FILE ("spec_parser.ggs", 265)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 266)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 267)) ;
      nt_parse_5F_constant_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 270)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_var COMMA_SOURCE_FILE ("spec_parser.ggs", 273)) ;
      bool repeatFlag_1 = true ;
      while (repeatFlag_1) {
        inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 275)) ;
        if (select_spec_5F_parser_12 (inCompiler) == 2) {
          inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 278)) ;
        }else{
          repeatFlag_1 = false ;
        }
      }
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 280)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_rule COMMA_SOURCE_FILE ("spec_parser.ggs", 283)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 284)) ;
      nt_parse_5F_precondition_indexing (inCompiler) ;
      nt_parse_5F_bound_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 287)) ;
      nt_parse_5F_postcondition_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 289)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_init COMMA_SOURCE_FILE ("spec_parser.ggs", 299)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("spec_parser.ggs", 302)) ;
    inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("spec_parser.ggs", 304)) ;
    switch (select_spec_5F_parser_14 (inCompiler)) {
    case 1: {
      nt_parse_5F_constant_indexing (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_infinity COMMA_SOURCE_FILE ("spec_parser.ggs", 310)) ;
    } break ;
    default:
      break ;
    }
    if (select_spec_5F_parser_13 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("spec_parser.ggs", 315)) ;
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 317)) ;
  bool repeatFlag_3 = true ;
  while (repeatFlag_3) {
    if (select_spec_5F_parser_15 (inCompiler) == 2) {
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_count COMMA_SOURCE_FILE ("spec_parser.ggs", 321)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_literal_5F_string COMMA_SOURCE_FILE ("spec_parser.ggs", 322)) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("spec_parser.ggs", 323)) ;
      nt_parse_5F_precondition_indexing (inCompiler) ;
      inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken__3B_ COMMA_SOURCE_FILE ("spec_parser.ggs", 325)) ;
    }else{
      repeatFlag_3 = false ;
    }
  }
  inCompiler->acceptTerminal (Lexique_spec_5F_scanner::kToken_end COMMA_SOURCE_FILE ("spec_parser.ggs", 328)) ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element::GGS_typePostconditionList_2E_element (void) :
mProperty_mPostcondition () {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element::GGS_typePostconditionList_2E_element (const GGS_typePostconditionList_2E_element & inSource) :
mProperty_mPostcondition (inSource.mProperty_mPostcondition) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element & GGS_typePostconditionList_2E_element::operator = (const GGS_typePostconditionList_2E_element & inSource) {
  mProperty_mPostcondition = inSource.mProperty_mPostcondition ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_typePostconditionList_2E_element GGS_typePostconditionList_2E_element::init_21_ (const GGS_typePostcondition & in_mPostcondition,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typePostconditionList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mPostcondition = in_mPostcondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element::GGS_typePostconditionList_2E_element (const GGS_typePostcondition & inOperand0) :
mProperty_mPostcondition (inOperand0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element GGS_typePostconditionList_2E_element::class_func_new (const GGS_typePostcondition & in_mPostcondition,
                                                                                           Compiler * inCompiler
                                                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typePostconditionList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mPostcondition = in_mPostcondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typePostconditionList_2E_element::isValid (void) const {
  return mProperty_mPostcondition.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList_2E_element::drop (void) {
  mProperty_mPostcondition.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostconditionList_2E_element::description (String & ioString,
                                                        const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typePostconditionList.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mPostcondition.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @typePostconditionList.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostconditionList_2E_element ("typePostconditionList.element",
                                                                                     nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostconditionList_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostconditionList_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostconditionList_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostconditionList_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostconditionList_2E_element GGS_typePostconditionList_2E_element::extractObject (const GGS_object & inObject,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GGS_typePostconditionList_2E_element result ;
  const GGS_typePostconditionList_2E_element * p = (const GGS_typePostconditionList_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostconditionList_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typePostconditionList.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element::GGS_typeInitialMarkingList_2E_element (void) :
mProperty_mInitValue () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element::GGS_typeInitialMarkingList_2E_element (const GGS_typeInitialMarkingList_2E_element & inSource) :
mProperty_mInitValue (inSource.mProperty_mInitValue) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element & GGS_typeInitialMarkingList_2E_element::operator = (const GGS_typeInitialMarkingList_2E_element & inSource) {
  mProperty_mInitValue = inSource.mProperty_mInitValue ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element GGS_typeInitialMarkingList_2E_element::init_21_ (const GGS_typePostcondition & in_mInitValue,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeInitialMarkingList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mInitValue = in_mInitValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element::GGS_typeInitialMarkingList_2E_element (const GGS_typePostcondition & inOperand0) :
mProperty_mInitValue (inOperand0) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element GGS_typeInitialMarkingList_2E_element::class_func_new (const GGS_typePostcondition & in_mInitValue,
                                                                                             Compiler * inCompiler
                                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeInitialMarkingList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mInitValue = in_mInitValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeInitialMarkingList_2E_element::isValid (void) const {
  return mProperty_mInitValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList_2E_element::drop (void) {
  mProperty_mInitValue.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInitialMarkingList_2E_element::description (String & ioString,
                                                         const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeInitialMarkingList.element:") ;
  if (! isValid ()) {
    ioString.appendCString (" not built") ;
  }else{
    mProperty_mInitValue.description (ioString, inIndentation+1) ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @typeInitialMarkingList.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeInitialMarkingList_2E_element ("typeInitialMarkingList.element",
                                                                                      nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeInitialMarkingList_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInitialMarkingList_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeInitialMarkingList_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeInitialMarkingList_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInitialMarkingList_2E_element GGS_typeInitialMarkingList_2E_element::extractObject (const GGS_object & inObject,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) {
  GGS_typeInitialMarkingList_2E_element result ;
  const GGS_typeInitialMarkingList_2E_element * p = (const GGS_typeInitialMarkingList_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeInitialMarkingList_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeInitialMarkingList.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
// @typeEqualExpression reference class
//--------------------------------------------------------------------------------------------------

ComparisonResult GGS_typeEqualExpression::objectCompare (const GGS_typeEqualExpression & inOperand) const {
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

GGS_typeEqualExpression::GGS_typeEqualExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeEqualExpression GGS_typeEqualExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeEqualExpression::
typeEqualExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                      const GGS_bool & in_mNegativeConstant,
                                      const GGS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression::GGS_typeEqualExpression (const cPtr_typeEqualExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression GGS_typeEqualExpression::class_func_new (const GGS_uint & in_mVar,
                                                                 const GGS_bool & in_mNegativeConstant,
                                                                 const GGS_luint & in_mConstant,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  GGS_typeEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeEqualExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeEqualExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeEqualExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeEqualExpression::cPtr_typeEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeEqualExpression::cPtr_typeEqualExpression (const GGS_uint & in_mVar,
                                                    const GGS_bool & in_mNegativeConstant,
                                                    const GGS_luint & in_mConstant,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeEqualExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeEqualExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeEqualExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeEqualExpression ("typeEqualExpression",
                                                                        & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeEqualExpression GGS_typeEqualExpression::extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GGS_typeEqualExpression result ;
  const GGS_typeEqualExpression * p = (const GGS_typeEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeEqualExpression *> (p)) {
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

ComparisonResult GGS_typeNonEqualExpression::objectCompare (const GGS_typeNonEqualExpression & inOperand) const {
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

GGS_typeNonEqualExpression::GGS_typeNonEqualExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeNonEqualExpression GGS_typeNonEqualExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeNonEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeNonEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeNonEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeNonEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeNonEqualExpression::
typeNonEqualExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                         const GGS_bool & in_mNegativeConstant,
                                         const GGS_luint & in_mConstant,
                                         Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression::GGS_typeNonEqualExpression (const cPtr_typeNonEqualExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeNonEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression GGS_typeNonEqualExpression::class_func_new (const GGS_uint & in_mVar,
                                                                       const GGS_bool & in_mNegativeConstant,
                                                                       const GGS_luint & in_mConstant,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) {
  GGS_typeNonEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeNonEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeNonEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeNonEqualExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeNonEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeNonEqualExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeNonEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeNonEqualExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeNonEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeNonEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeNonEqualExpression::cPtr_typeNonEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeNonEqualExpression::cPtr_typeNonEqualExpression (const GGS_uint & in_mVar,
                                                          const GGS_bool & in_mNegativeConstant,
                                                          const GGS_luint & in_mConstant,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeNonEqualExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeNonEqualExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeNonEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeNonEqualExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeNonEqualExpression ("typeNonEqualExpression",
                                                                           & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeNonEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeNonEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeNonEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeNonEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeNonEqualExpression GGS_typeNonEqualExpression::extractObject (const GGS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GGS_typeNonEqualExpression result ;
  const GGS_typeNonEqualExpression * p = (const GGS_typeNonEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeNonEqualExpression *> (p)) {
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

ComparisonResult GGS_typeInfOrEqualExpression::objectCompare (const GGS_typeInfOrEqualExpression & inOperand) const {
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

GGS_typeInfOrEqualExpression::GGS_typeInfOrEqualExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeInfOrEqualExpression GGS_typeInfOrEqualExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeInfOrEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeInfOrEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeInfOrEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeInfOrEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeInfOrEqualExpression::
typeInfOrEqualExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                           const GGS_bool & in_mNegativeConstant,
                                           const GGS_luint & in_mConstant,
                                           Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression::GGS_typeInfOrEqualExpression (const cPtr_typeInfOrEqualExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeInfOrEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression GGS_typeInfOrEqualExpression::class_func_new (const GGS_uint & in_mVar,
                                                                           const GGS_bool & in_mNegativeConstant,
                                                                           const GGS_luint & in_mConstant,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  GGS_typeInfOrEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeInfOrEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeInfOrEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInfOrEqualExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeInfOrEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInfOrEqualExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeInfOrEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeInfOrEqualExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeInfOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeInfOrEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeInfOrEqualExpression::cPtr_typeInfOrEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeInfOrEqualExpression::cPtr_typeInfOrEqualExpression (const GGS_uint & in_mVar,
                                                              const GGS_bool & in_mNegativeConstant,
                                                              const GGS_luint & in_mConstant,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeInfOrEqualExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeInfOrEqualExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeInfOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeInfOrEqualExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression ("typeInfOrEqualExpression",
                                                                             & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeInfOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeInfOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeInfOrEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeInfOrEqualExpression GGS_typeInfOrEqualExpression::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeInfOrEqualExpression result ;
  const GGS_typeInfOrEqualExpression * p = (const GGS_typeInfOrEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeInfOrEqualExpression *> (p)) {
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

ComparisonResult GGS_typeSupOrEqualExpression::objectCompare (const GGS_typeSupOrEqualExpression & inOperand) const {
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

GGS_typeSupOrEqualExpression::GGS_typeSupOrEqualExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeSupOrEqualExpression GGS_typeSupOrEqualExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeSupOrEqualExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeSupOrEqualExpression (inCompiler COMMA_THERE)) ;
  object->typeSupOrEqualExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeSupOrEqualExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeSupOrEqualExpression::
typeSupOrEqualExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                           const GGS_bool & in_mNegativeConstant,
                                           const GGS_luint & in_mConstant,
                                           Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression::GGS_typeSupOrEqualExpression (const cPtr_typeSupOrEqualExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSupOrEqualExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression GGS_typeSupOrEqualExpression::class_func_new (const GGS_uint & in_mVar,
                                                                           const GGS_bool & in_mNegativeConstant,
                                                                           const GGS_luint & in_mConstant,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) {
  GGS_typeSupOrEqualExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeSupOrEqualExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeSupOrEqualExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSupOrEqualExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeSupOrEqualExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSupOrEqualExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeSupOrEqualExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSupOrEqualExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSupOrEqualExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeSupOrEqualExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeSupOrEqualExpression::cPtr_typeSupOrEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeSupOrEqualExpression::cPtr_typeSupOrEqualExpression (const GGS_uint & in_mVar,
                                                              const GGS_bool & in_mNegativeConstant,
                                                              const GGS_luint & in_mConstant,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeSupOrEqualExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeSupOrEqualExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeSupOrEqualExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeSupOrEqualExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression ("typeSupOrEqualExpression",
                                                                             & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeSupOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeSupOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeSupOrEqualExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSupOrEqualExpression GGS_typeSupOrEqualExpression::extractObject (const GGS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GGS_typeSupOrEqualExpression result ;
  const GGS_typeSupOrEqualExpression * p = (const GGS_typeSupOrEqualExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeSupOrEqualExpression *> (p)) {
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

ComparisonResult GGS_typeStrictInfExpression::objectCompare (const GGS_typeStrictInfExpression & inOperand) const {
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

GGS_typeStrictInfExpression::GGS_typeStrictInfExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeStrictInfExpression GGS_typeStrictInfExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeStrictInfExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeStrictInfExpression (inCompiler COMMA_THERE)) ;
  object->typeStrictInfExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeStrictInfExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeStrictInfExpression::
typeStrictInfExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                          const GGS_bool & in_mNegativeConstant,
                                          const GGS_luint & in_mConstant,
                                          Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression::GGS_typeStrictInfExpression (const cPtr_typeStrictInfExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictInfExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression GGS_typeStrictInfExpression::class_func_new (const GGS_uint & in_mVar,
                                                                         const GGS_bool & in_mNegativeConstant,
                                                                         const GGS_luint & in_mConstant,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  GGS_typeStrictInfExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeStrictInfExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeStrictInfExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictInfExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeStrictInfExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictInfExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeStrictInfExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictInfExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictInfExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictInfExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictInfExpression::cPtr_typeStrictInfExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeStrictInfExpression::cPtr_typeStrictInfExpression (const GGS_uint & in_mVar,
                                                            const GGS_bool & in_mNegativeConstant,
                                                            const GGS_luint & in_mConstant,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeStrictInfExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeStrictInfExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeStrictInfExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeStrictInfExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeStrictInfExpression ("typeStrictInfExpression",
                                                                            & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeStrictInfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictInfExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeStrictInfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeStrictInfExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictInfExpression GGS_typeStrictInfExpression::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeStrictInfExpression result ;
  const GGS_typeStrictInfExpression * p = (const GGS_typeStrictInfExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeStrictInfExpression *> (p)) {
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

ComparisonResult GGS_typeStrictSupExpression::objectCompare (const GGS_typeStrictSupExpression & inOperand) const {
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

GGS_typeStrictSupExpression::GGS_typeStrictSupExpression (void) :
GGS_typePreconditionExpression () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeStrictSupExpression GGS_typeStrictSupExpression::
init_21__21__21_ (const GGS_uint & in_mVar,
                  const GGS_bool & in_mNegativeConstant,
                  const GGS_luint & in_mConstant,
                  Compiler * inCompiler
                  COMMA_LOCATION_ARGS) {
  cPtr_typeStrictSupExpression * object = nullptr ;
  macroMyNew (object, cPtr_typeStrictSupExpression (inCompiler COMMA_THERE)) ;
  object->typeStrictSupExpression_init_21__21__21_ (in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeStrictSupExpression result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeStrictSupExpression::
typeStrictSupExpression_init_21__21__21_ (const GGS_uint & in_mVar,
                                          const GGS_bool & in_mNegativeConstant,
                                          const GGS_luint & in_mConstant,
                                          Compiler * /* inCompiler */) {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression::GGS_typeStrictSupExpression (const cPtr_typeStrictSupExpression * inSourcePtr) :
GGS_typePreconditionExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeStrictSupExpression) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression GGS_typeStrictSupExpression::class_func_new (const GGS_uint & in_mVar,
                                                                         const GGS_bool & in_mNegativeConstant,
                                                                         const GGS_luint & in_mConstant,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) {
  GGS_typeStrictSupExpression result ;
  macroMyNew (result.mObjectPtr, cPtr_typeStrictSupExpression (in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeStrictSupExpression::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictSupExpression::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeStrictSupExpression::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictSupExpression::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeStrictSupExpression::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeStrictSupExpression::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeStrictSupExpression) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeStrictSupExpression class
//--------------------------------------------------------------------------------------------------

cPtr_typeStrictSupExpression::cPtr_typeStrictSupExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeStrictSupExpression::cPtr_typeStrictSupExpression (const GGS_uint & in_mVar,
                                                            const GGS_bool & in_mNegativeConstant,
                                                            const GGS_luint & in_mConstant,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) :
cPtr_typePreconditionExpression (inCompiler COMMA_THERE),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeStrictSupExpression::classDescriptor (void) const {
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

acPtr_class * cPtr_typeStrictSupExpression::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeStrictSupExpression (mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeStrictSupExpression generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeStrictSupExpression ("typeStrictSupExpression",
                                                                            & kTypeDescriptor_GALGAS_typePreconditionExpression) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeStrictSupExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeStrictSupExpression ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeStrictSupExpression::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeStrictSupExpression (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeStrictSupExpression GGS_typeStrictSupExpression::extractObject (const GGS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GGS_typeStrictSupExpression result ;
  const GGS_typeStrictSupExpression * p = (const GGS_typeStrictSupExpression *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeStrictSupExpression *> (p)) {
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

ComparisonResult GGS_typePostIncrement::objectCompare (const GGS_typePostIncrement & inOperand) const {
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

GGS_typePostIncrement::GGS_typePostIncrement (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typePostIncrement GGS_typePostIncrement::
init_21__21_ (const GGS_lstring & in_mVarName,
              const GGS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typePostIncrement * object = nullptr ;
  macroMyNew (object, cPtr_typePostIncrement (inCompiler COMMA_THERE)) ;
  object->typePostIncrement_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GGS_typePostIncrement result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typePostIncrement::
typePostIncrement_init_21__21_ (const GGS_lstring & in_mVarName,
                                const GGS_uint & in_mVar,
                                Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement::GGS_typePostIncrement (const cPtr_typePostIncrement * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostIncrement) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement GGS_typePostIncrement::class_func_new (const GGS_lstring & in_mVarName,
                                                             const GGS_uint & in_mVar,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  GGS_typePostIncrement result ;
  macroMyNew (result.mObjectPtr, cPtr_typePostIncrement (in_mVarName, in_mVar,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typePostIncrement::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostIncrement::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typePostIncrement::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostIncrement::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostIncrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostIncrement class
//--------------------------------------------------------------------------------------------------

cPtr_typePostIncrement::cPtr_typePostIncrement (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typePostIncrement::cPtr_typePostIncrement (const GGS_lstring & in_mVarName,
                                                const GGS_uint & in_mVar,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typePostIncrement::classDescriptor (void) const {
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

acPtr_class * cPtr_typePostIncrement::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typePostIncrement (mProperty_mVarName, mProperty_mVar, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typePostIncrement generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostIncrement ("typePostIncrement",
                                                                      & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostIncrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostIncrement ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostIncrement::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostIncrement (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostIncrement GGS_typePostIncrement::extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostIncrement result ;
  const GGS_typePostIncrement * p = (const GGS_typePostIncrement *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostIncrement *> (p)) {
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

ComparisonResult GGS_typePostDecrement::objectCompare (const GGS_typePostDecrement & inOperand) const {
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

GGS_typePostDecrement::GGS_typePostDecrement (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typePostDecrement GGS_typePostDecrement::
init_21__21_ (const GGS_lstring & in_mVarName,
              const GGS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typePostDecrement * object = nullptr ;
  macroMyNew (object, cPtr_typePostDecrement (inCompiler COMMA_THERE)) ;
  object->typePostDecrement_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GGS_typePostDecrement result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typePostDecrement::
typePostDecrement_init_21__21_ (const GGS_lstring & in_mVarName,
                                const GGS_uint & in_mVar,
                                Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement::GGS_typePostDecrement (const cPtr_typePostDecrement * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typePostDecrement) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement GGS_typePostDecrement::class_func_new (const GGS_lstring & in_mVarName,
                                                             const GGS_uint & in_mVar,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  GGS_typePostDecrement result ;
  macroMyNew (result.mObjectPtr, cPtr_typePostDecrement (in_mVarName, in_mVar,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typePostDecrement::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostDecrement::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typePostDecrement::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typePostDecrement::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typePostDecrement) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typePostDecrement class
//--------------------------------------------------------------------------------------------------

cPtr_typePostDecrement::cPtr_typePostDecrement (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typePostDecrement::cPtr_typePostDecrement (const GGS_lstring & in_mVarName,
                                                const GGS_uint & in_mVar,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typePostDecrement::classDescriptor (void) const {
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

acPtr_class * cPtr_typePostDecrement::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typePostDecrement (mProperty_mVarName, mProperty_mVar, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typePostDecrement generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typePostDecrement ("typePostDecrement",
                                                                      & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typePostDecrement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typePostDecrement ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typePostDecrement::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typePostDecrement (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typePostDecrement GGS_typePostDecrement::extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GGS_typePostDecrement result ;
  const GGS_typePostDecrement * p = (const GGS_typePostDecrement *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typePostDecrement *> (p)) {
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

ComparisonResult GGS_typeAddConstant::objectCompare (const GGS_typeAddConstant & inOperand) const {
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

GGS_typeAddConstant::GGS_typeAddConstant (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeAddConstant GGS_typeAddConstant::
init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                      const GGS_uint & in_mVar,
                      const GGS_bool & in_mNegativeConstant,
                      const GGS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeAddConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeAddConstant (inCompiler COMMA_THERE)) ;
  object->typeAddConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeAddConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAddConstant::
typeAddConstant_init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                                      const GGS_uint & in_mVar,
                                      const GGS_bool & in_mNegativeConstant,
                                      const GGS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant::GGS_typeAddConstant (const cPtr_typeAddConstant * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAddConstant) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant GGS_typeAddConstant::class_func_new (const GGS_lstring & in_mVarName,
                                                         const GGS_uint & in_mVar,
                                                         const GGS_bool & in_mNegativeConstant,
                                                         const GGS_luint & in_mConstant,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  GGS_typeAddConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAddConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typeAddConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAddConstant::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeAddConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAddConstant::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeAddConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAddConstant::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeAddConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAddConstant::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAddConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAddConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeAddConstant::cPtr_typeAddConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeAddConstant::cPtr_typeAddConstant (const GGS_lstring & in_mVarName,
                                            const GGS_uint & in_mVar,
                                            const GGS_bool & in_mNegativeConstant,
                                            const GGS_luint & in_mConstant,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
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

const GALGAS_TypeDescriptor * cPtr_typeAddConstant::classDescriptor (void) const {
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

acPtr_class * cPtr_typeAddConstant::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAddConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeAddConstant generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAddConstant ("typeAddConstant",
                                                                    & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAddConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAddConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAddConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAddConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAddConstant GGS_typeAddConstant::extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GGS_typeAddConstant result ;
  const GGS_typeAddConstant * p = (const GGS_typeAddConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAddConstant *> (p)) {
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

ComparisonResult GGS_typeSubConstant::objectCompare (const GGS_typeSubConstant & inOperand) const {
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

GGS_typeSubConstant::GGS_typeSubConstant (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeSubConstant GGS_typeSubConstant::
init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                      const GGS_uint & in_mVar,
                      const GGS_bool & in_mNegativeConstant,
                      const GGS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeSubConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeSubConstant (inCompiler COMMA_THERE)) ;
  object->typeSubConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeSubConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeSubConstant::
typeSubConstant_init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                                      const GGS_uint & in_mVar,
                                      const GGS_bool & in_mNegativeConstant,
                                      const GGS_luint & in_mConstant,
                                      Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant::GGS_typeSubConstant (const cPtr_typeSubConstant * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeSubConstant) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant GGS_typeSubConstant::class_func_new (const GGS_lstring & in_mVarName,
                                                         const GGS_uint & in_mVar,
                                                         const GGS_bool & in_mNegativeConstant,
                                                         const GGS_luint & in_mConstant,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  GGS_typeSubConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeSubConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typeSubConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSubConstant::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeSubConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSubConstant::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeSubConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSubConstant::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeSubConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeSubConstant::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeSubConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeSubConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeSubConstant::cPtr_typeSubConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeSubConstant::cPtr_typeSubConstant (const GGS_lstring & in_mVarName,
                                            const GGS_uint & in_mVar,
                                            const GGS_bool & in_mNegativeConstant,
                                            const GGS_luint & in_mConstant,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
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

const GALGAS_TypeDescriptor * cPtr_typeSubConstant::classDescriptor (void) const {
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

acPtr_class * cPtr_typeSubConstant::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeSubConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeSubConstant generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeSubConstant ("typeSubConstant",
                                                                    & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeSubConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeSubConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeSubConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeSubConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeSubConstant GGS_typeSubConstant::extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  GGS_typeSubConstant result ;
  const GGS_typeSubConstant * p = (const GGS_typeSubConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeSubConstant *> (p)) {
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

ComparisonResult GGS_typeAssignConstant::objectCompare (const GGS_typeAssignConstant & inOperand) const {
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

GGS_typeAssignConstant::GGS_typeAssignConstant (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeAssignConstant GGS_typeAssignConstant::
init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                      const GGS_uint & in_mVar,
                      const GGS_bool & in_mNegativeConstant,
                      const GGS_luint & in_mConstant,
                      Compiler * inCompiler
                      COMMA_LOCATION_ARGS) {
  cPtr_typeAssignConstant * object = nullptr ;
  macroMyNew (object, cPtr_typeAssignConstant (inCompiler COMMA_THERE)) ;
  object->typeAssignConstant_init_21__21__21__21_ (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant, inCompiler) ;
  const GGS_typeAssignConstant result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAssignConstant::
typeAssignConstant_init_21__21__21__21_ (const GGS_lstring & in_mVarName,
                                         const GGS_uint & in_mVar,
                                         const GGS_bool & in_mNegativeConstant,
                                         const GGS_luint & in_mConstant,
                                         Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
  mProperty_mNegativeConstant = in_mNegativeConstant ;
  mProperty_mConstant = in_mConstant ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant::GGS_typeAssignConstant (const cPtr_typeAssignConstant * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignConstant) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant GGS_typeAssignConstant::class_func_new (const GGS_lstring & in_mVarName,
                                                               const GGS_uint & in_mVar,
                                                               const GGS_bool & in_mNegativeConstant,
                                                               const GGS_luint & in_mConstant,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  GGS_typeAssignConstant result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAssignConstant (in_mVarName, in_mVar, in_mNegativeConstant, in_mConstant,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typeAssignConstant::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignConstant::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeAssignConstant::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignConstant::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_bool GGS_typeAssignConstant::readProperty_mNegativeConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_bool () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mNegativeConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignConstant::setProperty_mNegativeConstant (const GGS_bool & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mNegativeConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_luint GGS_typeAssignConstant::readProperty_mConstant (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_luint () ;
  }else{
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    return p->mProperty_mConstant ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignConstant::setProperty_mConstant (const GGS_luint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignConstant) ;
    p->mProperty_mConstant = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignConstant class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignConstant::cPtr_typeAssignConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar (),
mProperty_mNegativeConstant (),
mProperty_mConstant () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeAssignConstant::cPtr_typeAssignConstant (const GGS_lstring & in_mVarName,
                                                  const GGS_uint & in_mVar,
                                                  const GGS_bool & in_mNegativeConstant,
                                                  const GGS_luint & in_mConstant,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
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

const GALGAS_TypeDescriptor * cPtr_typeAssignConstant::classDescriptor (void) const {
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

acPtr_class * cPtr_typeAssignConstant::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAssignConstant (mProperty_mVarName, mProperty_mVar, mProperty_mNegativeConstant, mProperty_mConstant, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeAssignConstant generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAssignConstant ("typeAssignConstant",
                                                                       & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAssignConstant::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignConstant ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAssignConstant::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAssignConstant (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignConstant GGS_typeAssignConstant::extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GGS_typeAssignConstant result ;
  const GGS_typeAssignConstant * p = (const GGS_typeAssignConstant *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAssignConstant *> (p)) {
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

ComparisonResult GGS_typeAssignInfinity::objectCompare (const GGS_typeAssignInfinity & inOperand) const {
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

GGS_typeAssignInfinity::GGS_typeAssignInfinity (void) :
GGS_typePostcondition () {
}

//--- Synthetized initializer ----------------------------------------------------------------------

GGS_typeAssignInfinity GGS_typeAssignInfinity::
init_21__21_ (const GGS_lstring & in_mVarName,
              const GGS_uint & in_mVar,
              Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  cPtr_typeAssignInfinity * object = nullptr ;
  macroMyNew (object, cPtr_typeAssignInfinity (inCompiler COMMA_THERE)) ;
  object->typeAssignInfinity_init_21__21_ (in_mVarName, in_mVar, inCompiler) ;
  const GGS_typeAssignInfinity result (object) ;
  macroDetachSharedObject (object) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void cPtr_typeAssignInfinity::
typeAssignInfinity_init_21__21_ (const GGS_lstring & in_mVarName,
                                 const GGS_uint & in_mVar,
                                 Compiler * /* inCompiler */) {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity::GGS_typeAssignInfinity (const cPtr_typeAssignInfinity * inSourcePtr) :
GGS_typePostcondition (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_typeAssignInfinity) ;
}
//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity GGS_typeAssignInfinity::class_func_new (const GGS_lstring & in_mVarName,
                                                               const GGS_uint & in_mVar,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) {
  GGS_typeAssignInfinity result ;
  macroMyNew (result.mObjectPtr, cPtr_typeAssignInfinity (in_mVarName, in_mVar,  inCompiler COMMA_THERE)) ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_lstring GGS_typeAssignInfinity::readProperty_mVarName (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_lstring () ;
  }else{
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    return p->mProperty_mVarName ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignInfinity::setProperty_mVarName (const GGS_lstring & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVarName = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------

GGS_uint GGS_typeAssignInfinity::readProperty_mVar (void) const {
  if (nullptr == mObjectPtr) {
    return GGS_uint () ;
  }else{
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    return p->mProperty_mVar ;
  }
}

//--------------------------------------------------------------------------------------------------

void GGS_typeAssignInfinity::setProperty_mVar (const GGS_uint & inValue) {
  if (nullptr != mObjectPtr) {
    cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_typeAssignInfinity) ;
    p->mProperty_mVar = inValue ;
  }
}

//--------------------------------------------------------------------------------------------------
//Pointer class for @typeAssignInfinity class
//--------------------------------------------------------------------------------------------------

cPtr_typeAssignInfinity::cPtr_typeAssignInfinity (Compiler * inCompiler COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
}

//--------------------------------------------------------------------------------------------------

cPtr_typeAssignInfinity::cPtr_typeAssignInfinity (const GGS_lstring & in_mVarName,
                                                  const GGS_uint & in_mVar,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) :
cPtr_typePostcondition (inCompiler COMMA_THERE),
mProperty_mVarName (),
mProperty_mVar () {
  mProperty_mVarName = in_mVarName ;
  mProperty_mVar = in_mVar ;
}

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * cPtr_typeAssignInfinity::classDescriptor (void) const {
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

acPtr_class * cPtr_typeAssignInfinity::duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const {
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_typeAssignInfinity (mProperty_mVarName, mProperty_mVar, inCompiler COMMA_THERE)) ;
  return ptr ;
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
//     @typeAssignInfinity generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeAssignInfinity ("typeAssignInfinity",
                                                                       & kTypeDescriptor_GALGAS_typePostcondition) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeAssignInfinity::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeAssignInfinity ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeAssignInfinity::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeAssignInfinity (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeAssignInfinity GGS_typeAssignInfinity::extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GGS_typeAssignInfinity result ;
  const GGS_typeAssignInfinity * p = (const GGS_typeAssignInfinity *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeAssignInfinity *> (p)) {
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
// At index 0 : <axiome>, in file 'spec_parser.ggs', line 233
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
// At index 112 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 242
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_hashmapsize) // $hashmapsize$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_END_PRODUCTION ()
// At index 116 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 242
, TOP_DOWN_END_PRODUCTION ()
// At index 117 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 250
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_garbageperiod) // $garbageperiod$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_integer) // $literal_integer$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_END_PRODUCTION ()
// At index 121 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 250
, TOP_DOWN_END_PRODUCTION ()
// At index 122 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_END_PRODUCTION ()
// At index 123 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_const) // $const$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3D_) // $=$
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 130 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_var) // $var$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (20) // <select_spec_5F_parser_12>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 136 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_rule) // $rule$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_literal_5F_string) // $literal_string$
, TOP_DOWN_NONTERMINAL (1) // <parse_precondition>
, TOP_DOWN_NONTERMINAL (7) // <parse_bound>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (5) // <parse_postcondition>
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3B_) // $;$
, TOP_DOWN_NONTERMINAL (19) // <select_spec_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 145 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_END_PRODUCTION ()
// At index 146 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 274
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (20) // <select_spec_5F_parser_12>
, TOP_DOWN_END_PRODUCTION ()
// At index 150 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 301
, TOP_DOWN_END_PRODUCTION ()
// At index 151 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 301
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (22) // <select_spec_5F_parser_14>
, TOP_DOWN_NONTERMINAL (21) // <select_spec_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 157 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 305
, TOP_DOWN_NONTERMINAL (6) // <parse_constant>
, TOP_DOWN_END_PRODUCTION ()
// At index 159 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 305
, TOP_DOWN_TERMINAL (Lexique_spec_5F_scanner::kToken_infinity) // $infinity$
, TOP_DOWN_END_PRODUCTION ()
// At index 161 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 319
, TOP_DOWN_END_PRODUCTION ()
// At index 162 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 319
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
0, // index 0 : <axiome>, in file 'spec_parser.ggs', line 233
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
112, // index 37 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 242
116, // index 38 : <select_spec_5F_parser_9>, in file 'spec_parser.ggs', line 242
117, // index 39 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 250
121, // index 40 : <select_spec_5F_parser_10>, in file 'spec_parser.ggs', line 250
122, // index 41 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
123, // index 42 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
130, // index 43 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
136, // index 44 : <select_spec_5F_parser_11>, in file 'spec_parser.ggs', line 262
145, // index 45 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 274
146, // index 46 : <select_spec_5F_parser_12>, in file 'spec_parser.ggs', line 274
150, // index 47 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 301
151, // index 48 : <select_spec_5F_parser_13>, in file 'spec_parser.ggs', line 301
157, // index 49 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 305
159, // index 50 : <select_spec_5F_parser_14>, in file 'spec_parser.ggs', line 305
161, // index 51 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 319
162, // index 52 : <select_spec_5F_parser_15>, in file 'spec_parser.ggs', line 319
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

void cGrammar_spec_5F_grammar::nt_axiome_ (GGS_uint & parameter_1,
                                GGS_uint & parameter_2,
                                GGS_typeVarMap & parameter_3,
                                GGS_typeTransitionList & parameter_4,
                                GGS_typeInitialMarkingList & parameter_5,
                                GGS_countList & parameter_6,
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
                                GGS_lstring inFilePath,
                                GGS_uint &  parameter_1,
                                GGS_uint &  parameter_2,
                                GGS_typeVarMap &  parameter_3,
                                GGS_typeTransitionList &  parameter_4,
                                GGS_typeInitialMarkingList &  parameter_5,
                                GGS_countList &  parameter_6
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GGS_string filePathAsString = inFilePath.readProperty_string () ;
    String filePath = filePathAsString.stringValue () ;
    if (! FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().deletingLastPathComponent ().appendingPathComponent (filePath) ;
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
        const GGS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, GenericArray <FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      String message ;
      message.appendString ("the '") ;
      message.appendString (filePath) ;
      message.appendString ("' file does not exist") ;
      const GGS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, GenericArray <FixItDescription> () COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void cGrammar_spec_5F_grammar::_performSourceStringParsing_ (Compiler * inCompiler,
                                GGS_string inSourceString,
                                GGS_string inNameString,
                                GGS_uint &  parameter_1,
                                GGS_uint &  parameter_2,
                                GGS_typeVarMap &  parameter_3,
                                GGS_typeTransitionList &  parameter_4,
                                GGS_typeInitialMarkingList &  parameter_5,
                                GGS_countList &  parameter_6
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

void cGrammar_spec_5F_grammar::nt_parse_5F_precondition_ (GGS_typeVarMap & parameter_1,
                                GGS_typeCstMap & parameter_2,
                                GGS_typePreconditionExpression & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_term_ (GGS_typeVarMap & parameter_1,
                                GGS_typeCstMap & parameter_2,
                                GGS_typePreconditionExpression & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_factor_ (GGS_typeVarMap & parameter_1,
                                GGS_typeCstMap & parameter_2,
                                GGS_typePreconditionExpression & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_primary_ (GGS_typeVarMap & parameter_1,
                                GGS_typeCstMap & parameter_2,
                                GGS_typePreconditionExpression & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_parse_5F_postcondition_ (GGS_typeVarMap & parameter_1,
                                GGS_typeCstMap & parameter_2,
                                GGS_typePostconditionList & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_parse_5F_constant_ (GGS_typeCstMap & parameter_1,
                                GGS_bool & parameter_2,
                                GGS_luint & parameter_3,
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

void cGrammar_spec_5F_grammar::nt_parse_5F_bound_ (GGS_uint & parameter_1,
                                GGS_uint & parameter_2,
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

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (void) :
mProperty_mValue_30_ (),
mProperty_mValue_31_ () {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (const GGS__32_lstringlist_2E_element & inSource) :
mProperty_mValue_30_ (inSource.mProperty_mValue_30_),
mProperty_mValue_31_ (inSource.mProperty_mValue_31_) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element & GGS__32_lstringlist_2E_element::operator = (const GGS__32_lstringlist_2E_element & inSource) {
  mProperty_mValue_30_ = inSource.mProperty_mValue_30_ ;
  mProperty_mValue_31_ = inSource.mProperty_mValue_31_ ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::init_21__21_ (const GGS_lstring & in_mValue_30_,
                                                                             const GGS_lstring & in_mValue_31_,
                                                                             Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue_30_ ;
  result.mProperty_mValue_31_ = in_mValue_31_ ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element::GGS__32_lstringlist_2E_element (const GGS_lstring & inOperand0,
                                                                const GGS_lstring & inOperand1) :
mProperty_mValue_30_ (inOperand0),
mProperty_mValue_31_ (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::class_func_new (const GGS_lstring & in_mValue0,
                                                                               const GGS_lstring & in_mValue1,
                                                                               Compiler * inCompiler
                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mValue_30_ = in_mValue0 ;
  result.mProperty_mValue_31_ = in_mValue1 ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS__32_lstringlist_2E_element::isValid (void) const {
  return mProperty_mValue_30_.isValid () && mProperty_mValue_31_.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::drop (void) {
  mProperty_mValue_30_.drop () ;
  mProperty_mValue_31_.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS__32_lstringlist_2E_element::description (String & ioString,
                                                  const int32_t inIndentation) const {
  ioString.appendCString ("<struct @2lstringlist.element:") ;
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
//     @2lstringlist.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS__32_lstringlist_2E_element ("2lstringlist.element",
                                                                               nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS__32_lstringlist_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS__32_lstringlist_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS__32_lstringlist_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS__32_lstringlist_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS__32_lstringlist_2E_element GGS__32_lstringlist_2E_element::extractObject (const GGS_object & inObject,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GGS__32_lstringlist_2E_element result ;
  const GGS__32_lstringlist_2E_element * p = (const GGS__32_lstringlist_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS__32_lstringlist_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("2lstringlist.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element::GGS_typeVarMap_2E_element (void) :
mProperty_lkey (),
mProperty_mIndex () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element::GGS_typeVarMap_2E_element (const GGS_typeVarMap_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mIndex (inSource.mProperty_mIndex) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element & GGS_typeVarMap_2E_element::operator = (const GGS_typeVarMap_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mIndex = inSource.mProperty_mIndex ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_typeVarMap_2E_element GGS_typeVarMap_2E_element::init_21__21_ (const GGS_lstring & in_lkey,
                                                                   const GGS_uint & in_mIndex,
                                                                   Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeVarMap_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element::GGS_typeVarMap_2E_element (const GGS_lstring & inOperand0,
                                                      const GGS_uint & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_mIndex (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element GGS_typeVarMap_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                     const GGS_uint & in_mIndex,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeVarMap_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mIndex = in_mIndex ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeVarMap_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mIndex.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mIndex.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap_2E_element::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeVarMap.element:") ;
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
//     @typeVarMap.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeVarMap_2E_element ("typeVarMap.element",
                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeVarMap_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeVarMap_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeVarMap_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element GGS_typeVarMap_2E_element::extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GGS_typeVarMap_2E_element result ;
  const GGS_typeVarMap_2E_element * p = (const GGS_typeVarMap_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeVarMap_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @typeVarMap_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element_3F_::GGS_typeVarMap_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element_3F_::GGS_typeVarMap_2E_element_3F_ (const GGS_typeVarMap_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element_3F_ GGS_typeVarMap_2E_element_3F_::init_nil (void) {
  GGS_typeVarMap_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeVarMap_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeVarMap_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_typeVarMap_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeVarMap_2E_element_3F_::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @typeVarMap.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeVarMap_2E_element_3F_ ("typeVarMap.element?",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeVarMap_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeVarMap_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeVarMap_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeVarMap_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeVarMap_2E_element_3F_ GGS_typeVarMap_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typeVarMap_2E_element_3F_ result ;
  const GGS_typeVarMap_2E_element_3F_ * p = (const GGS_typeVarMap_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeVarMap_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeVarMap.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element::GGS_typeCstMap_2E_element (void) :
mProperty_lkey (),
mProperty_mSign (),
mProperty_mValue () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element::GGS_typeCstMap_2E_element (const GGS_typeCstMap_2E_element & inSource) :
mProperty_lkey (inSource.mProperty_lkey),
mProperty_mSign (inSource.mProperty_mSign),
mProperty_mValue (inSource.mProperty_mValue) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element & GGS_typeCstMap_2E_element::operator = (const GGS_typeCstMap_2E_element & inSource) {
  mProperty_lkey = inSource.mProperty_lkey ;
  mProperty_mSign = inSource.mProperty_mSign ;
  mProperty_mValue = inSource.mProperty_mValue ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_typeCstMap_2E_element GGS_typeCstMap_2E_element::init_21__21__21_ (const GGS_lstring & in_lkey,
                                                                       const GGS_bool & in_mSign,
                                                                       const GGS_luint & in_mValue,
                                                                       Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeCstMap_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mSign = in_mSign ;
  result.mProperty_mValue = in_mValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element::GGS_typeCstMap_2E_element (const GGS_lstring & inOperand0,
                                                      const GGS_bool & inOperand1,
                                                      const GGS_luint & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_mSign (inOperand1),
mProperty_mValue (inOperand2) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element GGS_typeCstMap_2E_element::class_func_new (const GGS_lstring & in_lkey,
                                                                     const GGS_bool & in_mSign,
                                                                     const GGS_luint & in_mValue,
                                                                     Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeCstMap_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_lkey = in_lkey ;
  result.mProperty_mSign = in_mSign ;
  result.mProperty_mValue = in_mValue ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeCstMap_2E_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mSign.isValid () && mProperty_mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap_2E_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mSign.drop () ;
  mProperty_mValue.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap_2E_element::description (String & ioString,
                                             const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeCstMap.element:") ;
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
//     @typeCstMap.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeCstMap_2E_element ("typeCstMap.element",
                                                                          nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeCstMap_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeCstMap_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeCstMap_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element GGS_typeCstMap_2E_element::extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GGS_typeCstMap_2E_element result ;
  const GGS_typeCstMap_2E_element * p = (const GGS_typeCstMap_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeCstMap_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------
//Optional @typeCstMap_2E_element_3F_
//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element_3F_::GGS_typeCstMap_2E_element_3F_ (void) :
AC_GALGAS_root (),
mValue (),
mState (OptionalState::invalid) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element_3F_::GGS_typeCstMap_2E_element_3F_ (const GGS_typeCstMap_2E_element & inSource) :
AC_GALGAS_root (),
mValue (inSource),
mState (OptionalState::valuated) {
}


//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element_3F_ GGS_typeCstMap_2E_element_3F_::init_nil (void) {
  GGS_typeCstMap_2E_element_3F_ result ;
  result.mState = OptionalState::isNil ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeCstMap_2E_element_3F_::isValid (void) const {
  bool result = false ;
  switch (mState) {
  case OptionalState::invalid :
    break ;
  case OptionalState::isNil :
    result = true ;
    break ;
  case OptionalState::valuated :
    result = mValue.isValid () ;
    break ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeCstMap_2E_element_3F_::isValuated (void) const {
  return (mState == OptionalState::valuated) && mValue.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap_2E_element_3F_::drop (void) {
  mState = OptionalState::invalid ;
  mValue = GGS_typeCstMap_2E_element () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeCstMap_2E_element_3F_::description (String & ioString,
                                                 const int32_t inIndentation) const {
  ioString.appendCString ("<optional @") ;
  ioString.appendString (staticTypeDescriptor ()->mGalgasTypeName) ;
  ioString.appendCString (": ") ;
  switch (mState) {
  case OptionalState::invalid :
    ioString.appendCString ("invalid") ;
    break ;
  case OptionalState::isNil :
    ioString.appendCString ("nil") ;
    break ;
  case OptionalState::valuated :
    mValue.description (ioString, inIndentation) ;
    break ;
  }
  ioString.appendCString (">") ;
}

//--------------------------------------------------------------------------------------------------
//     @typeCstMap.element? generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeCstMap_2E_element_3F_ ("typeCstMap.element?",
                                                                              nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeCstMap_2E_element_3F_::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeCstMap_2E_element_3F_ ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeCstMap_2E_element_3F_::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeCstMap_2E_element_3F_ (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeCstMap_2E_element_3F_ GGS_typeCstMap_2E_element_3F_::extractObject (const GGS_object & inObject,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GGS_typeCstMap_2E_element_3F_ result ;
  const GGS_typeCstMap_2E_element_3F_ * p = (const GGS_typeCstMap_2E_element_3F_ *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeCstMap_2E_element_3F_ *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeCstMap.element?", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element::GGS_typeTransitionList_2E_element (void) :
mProperty_mTransitionName (),
mProperty_mPreconditionExpression (),
mProperty_mPostconditionList (),
mProperty_mLowTemporalBound (),
mProperty_mHighTemporalBound () {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element::GGS_typeTransitionList_2E_element (const GGS_typeTransitionList_2E_element & inSource) :
mProperty_mTransitionName (inSource.mProperty_mTransitionName),
mProperty_mPreconditionExpression (inSource.mProperty_mPreconditionExpression),
mProperty_mPostconditionList (inSource.mProperty_mPostconditionList),
mProperty_mLowTemporalBound (inSource.mProperty_mLowTemporalBound),
mProperty_mHighTemporalBound (inSource.mProperty_mHighTemporalBound) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element & GGS_typeTransitionList_2E_element::operator = (const GGS_typeTransitionList_2E_element & inSource) {
  mProperty_mTransitionName = inSource.mProperty_mTransitionName ;
  mProperty_mPreconditionExpression = inSource.mProperty_mPreconditionExpression ;
  mProperty_mPostconditionList = inSource.mProperty_mPostconditionList ;
  mProperty_mLowTemporalBound = inSource.mProperty_mLowTemporalBound ;
  mProperty_mHighTemporalBound = inSource.mProperty_mHighTemporalBound ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_typeTransitionList_2E_element GGS_typeTransitionList_2E_element::init_21__21__21__21__21_ (const GGS_lstring & in_mTransitionName,
                                                                                               const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                                                               const GGS_typePostconditionList & in_mPostconditionList,
                                                                                               const GGS_uint & in_mLowTemporalBound,
                                                                                               const GGS_uint & in_mHighTemporalBound,
                                                                                               Compiler * inCompiler
                                                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeTransitionList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mTransitionName = in_mTransitionName ;
  result.mProperty_mPreconditionExpression = in_mPreconditionExpression ;
  result.mProperty_mPostconditionList = in_mPostconditionList ;
  result.mProperty_mLowTemporalBound = in_mLowTemporalBound ;
  result.mProperty_mHighTemporalBound = in_mHighTemporalBound ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element::GGS_typeTransitionList_2E_element (const GGS_lstring & inOperand0,
                                                                      const GGS_typePreconditionExpression & inOperand1,
                                                                      const GGS_typePostconditionList & inOperand2,
                                                                      const GGS_uint & inOperand3,
                                                                      const GGS_uint & inOperand4) :
mProperty_mTransitionName (inOperand0),
mProperty_mPreconditionExpression (inOperand1),
mProperty_mPostconditionList (inOperand2),
mProperty_mLowTemporalBound (inOperand3),
mProperty_mHighTemporalBound (inOperand4) {
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element GGS_typeTransitionList_2E_element::class_func_new (const GGS_lstring & in_mTransitionName,
                                                                                     const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                                                     const GGS_typePostconditionList & in_mPostconditionList,
                                                                                     const GGS_uint & in_mLowTemporalBound,
                                                                                     const GGS_uint & in_mHighTemporalBound,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GGS_typeTransitionList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mTransitionName = in_mTransitionName ;
  result.mProperty_mPreconditionExpression = in_mPreconditionExpression ;
  result.mProperty_mPostconditionList = in_mPostconditionList ;
  result.mProperty_mLowTemporalBound = in_mLowTemporalBound ;
  result.mProperty_mHighTemporalBound = in_mHighTemporalBound ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_typeTransitionList_2E_element::isValid (void) const {
  return mProperty_mTransitionName.isValid () && mProperty_mPreconditionExpression.isValid () && mProperty_mPostconditionList.isValid () && mProperty_mLowTemporalBound.isValid () && mProperty_mHighTemporalBound.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList_2E_element::drop (void) {
  mProperty_mTransitionName.drop () ;
  mProperty_mPreconditionExpression.drop () ;
  mProperty_mPostconditionList.drop () ;
  mProperty_mLowTemporalBound.drop () ;
  mProperty_mHighTemporalBound.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_typeTransitionList_2E_element::description (String & ioString,
                                                     const int32_t inIndentation) const {
  ioString.appendCString ("<struct @typeTransitionList.element:") ;
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
//     @typeTransitionList.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_typeTransitionList_2E_element ("typeTransitionList.element",
                                                                                  nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_typeTransitionList_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_typeTransitionList_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_typeTransitionList_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_typeTransitionList_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_typeTransitionList_2E_element GGS_typeTransitionList_2E_element::extractObject (const GGS_object & inObject,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GGS_typeTransitionList_2E_element result ;
  const GGS_typeTransitionList_2E_element * p = (const GGS_typeTransitionList_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_typeTransitionList_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("typeTransitionList.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element::GGS_countList_2E_element (void) :
mProperty_mName (),
mProperty_mCondition () {
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element::GGS_countList_2E_element (const GGS_countList_2E_element & inSource) :
mProperty_mName (inSource.mProperty_mName),
mProperty_mCondition (inSource.mProperty_mCondition) {
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element & GGS_countList_2E_element::operator = (const GGS_countList_2E_element & inSource) {
  mProperty_mName = inSource.mProperty_mName ;
  mProperty_mCondition = inSource.mProperty_mCondition ;
  return *this ;
}

//---Synthetized initializer -----------------------------------------------------------------------

GGS_countList_2E_element GGS_countList_2E_element::init_21__21_ (const GGS_lstring & in_mName,
                                                                 const GGS_typePreconditionExpression & in_mCondition,
                                                                 Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GGS_countList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mName = in_mName ;
  result.mProperty_mCondition = in_mCondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList_2E_element::setInitializedProperties (Compiler * /* inCompiler */) {
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element::GGS_countList_2E_element (const GGS_lstring & inOperand0,
                                                    const GGS_typePreconditionExpression & inOperand1) :
mProperty_mName (inOperand0),
mProperty_mCondition (inOperand1) {
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element GGS_countList_2E_element::class_func_new (const GGS_lstring & in_mName,
                                                                   const GGS_typePreconditionExpression & in_mCondition,
                                                                   Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GGS_countList_2E_element result ;
  result.setInitializedProperties (inCompiler) ;
  result.mProperty_mName = in_mName ;
  result.mProperty_mCondition = in_mCondition ;
  return result ;
}

//--------------------------------------------------------------------------------------------------

bool GGS_countList_2E_element::isValid (void) const {
  return mProperty_mName.isValid () && mProperty_mCondition.isValid () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList_2E_element::drop (void) {
  mProperty_mName.drop () ;
  mProperty_mCondition.drop () ;
}

//--------------------------------------------------------------------------------------------------

void GGS_countList_2E_element::description (String & ioString,
                                            const int32_t inIndentation) const {
  ioString.appendCString ("<struct @countList.element:") ;
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
//     @countList.element generic code implementation
//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor kTypeDescriptor_GALGAS_countList_2E_element ("countList.element",
                                                                         nullptr) ;

//--------------------------------------------------------------------------------------------------

const GALGAS_TypeDescriptor * GGS_countList_2E_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_countList_2E_element ;
}

//--------------------------------------------------------------------------------------------------

AC_GALGAS_root * GGS_countList_2E_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
  if (isValid ()) {
    macroMyNew (result, GGS_countList_2E_element (*this)) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

GGS_countList_2E_element GGS_countList_2E_element::extractObject (const GGS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GGS_countList_2E_element result ;
  const GGS_countList_2E_element * p = (const GGS_countList_2E_element *) inObject.embeddedObject () ;
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GGS_countList_2E_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("countList.element", p->dynamicTypeDescriptor () COMMA_THERE) ;
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
#include "LexiqueIntrospection.h"
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

static void routine_programRule_5F__30_ (const GGS_lstring constinArgument_inSourceFile,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GGS_uint var_hashMapSize_454 ;
  GGS_uint var_garbagePeriod_476 ;
  GGS_typeVarMap var_placesMap_500 ;
  GGS_typeTransitionList var_transitionList_520 ;
  GGS_typeInitialMarkingList var_initialMarkingList_545 ;
  GGS_countList var_countList_574 ;
  var_hashMapSize_454.drop () ;
  var_garbagePeriod_476.drop () ;
  var_placesMap_500.drop () ;
  var_transitionList_520.drop () ;
  var_initialMarkingList_545.drop () ;
  var_countList_574.drop () ;
  cGrammar_spec_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_hashMapSize_454, var_garbagePeriod_476, var_placesMap_500, var_transitionList_520, var_initialMarkingList_545, var_countList_574  COMMA_SOURCE_FILE ("spec_main.ggs", 11)) ;
  {
  routine_generate_5F_code_3F__3F__3F__3F__3F__3F_ (var_hashMapSize_454, var_garbagePeriod_476, var_placesMap_500, var_transitionList_520, var_initialMarkingList_545, var_countList_574, inCompiler  COMMA_SOURCE_FILE ("spec_main.ggs", 19)) ;
  }
}


//--------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//--------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  GenericUniqueArray <String> sourceFilesArray ;
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
      LexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GGS_string sfp = GGS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GGS_location location = commonCompiler->here () ;
        const GGS_lstring sourceFilePath (sfp, location) ;
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

