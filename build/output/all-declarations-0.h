#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//LEXIQUE spec_5F_scanner
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S                                             
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S                                           
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S                                                  
//----------------------------------------------------------------------------------------------------------------------

class cTokenFor_spec_5F_scanner : public cToken {
  public : C_String mLexicalAttribute_theString ;
  public : uint32_t mLexicalAttribute_ulongValue ;

  public : cTokenFor_spec_5F_scanner (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S                                                
//----------------------------------------------------------------------------------------------------------------------

class C_Lexique_spec_5F_scanner : public C_Lexique {
//--- Constructors
  public : C_Lexique_spec_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_spec_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public : static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~ C_Lexique_spec_5F_scanner (void) {}
  #endif



//--- Terminal symbols enumeration
  public : enum {kToken_,
   kToken_identifier,
   kToken_literal_5F_string,
   kToken_literal_5F_integer,
   kToken_system,
   kToken_var,
   kToken_rule,
   kToken_init,
   kToken_end,
   kToken_true,
   kToken_false,
   kToken_const,
   kToken_count,
   kToken_infinity,
   kToken_hashmapsize,
   kToken_garbageperiod,
   kToken__3E__3D_,
   kToken__3E_,
   kToken__3C_,
   kToken__3C__3D_,
   kToken__3D__3D_,
   kToken__21__3D_,
   kToken__26_,
   kToken__7C_,
   kToken__7E_,
   kToken__2C_,
   kToken__3B_,
   kToken__28_,
   kToken__29_,
   kToken__2B__2B_,
   kToken__2D__2D_,
   kToken__2B__3D_,
   kToken__2D__3D_,
   kToken__3A__3D_,
   kToken__7B_,
   kToken__7D_,
   kToken__3A_,
   kToken__2D_,
   kToken__3D_,
   kToken__5B_,
   kToken__5D_} ;

//--- Key words table 'galgasKeyWordList'
  public : static int16_t search_into_galgasKeyWordList (const C_String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public : static int16_t search_into_delimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : GALGAS_lstring synthetizedAttribute_theString (void) const ;
  public : GALGAS_luint synthetizedAttribute_ulongValue (void) const ;


//--- Attribute access
  public : C_String attributeValue_theString (void) const ;
  public : uint32_t attributeValue_ulongValue (void) const ;


//--- Indexing keys

//--- Unicode test functions

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const ;

//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Get terminal message
  protected : virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const ;

//--- Get terminal count
  public : virtual int16_t terminalVocabularyCount (void) const { return 40 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (cTokenFor_spec_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected : virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const ;
  protected : virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeVarMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_typeVarMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_typeVarMap_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeVarMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_typeVarMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_typeVarMap (const GALGAS_typeVarMap & inSource) ;
  public : GALGAS_typeVarMap & operator = (const GALGAS_typeVarMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeVarMap extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeVarMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static class GALGAS_typeVarMap constructor_mapWithMapToOverride (const class GALGAS_typeVarMap & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_uint & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_uint constinArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_uint & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeVarMap getter_overriddenMap (C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public : VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                     class GALGAS_uint & outOperand1) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_typeVarMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                        const GALGAS_string & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_typeVarMap ;
 
} ; // End of GALGAS_typeVarMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typeVarMap : public cGenericAbstractEnumerator {
  public : cEnumerator_typeVarMap (const GALGAS_typeVarMap & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeVarMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@typeVarMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_typeVarMap : public cMapElement {
//--- Map attributes
  public : GALGAS_uint mProperty_mIndex ;

//--- Constructor
  public : cMapElement_typeVarMap (const GALGAS_lstring & inKey,
                                   const GALGAS_uint & in_mIndex
                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeVarMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeVarMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_lstring mProperty_lkey ;

  public : GALGAS_uint mProperty_mIndex ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeVarMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_typeVarMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_typeVarMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeVarMap_2D_element (const GALGAS_lstring & in_lkey,
                                         const GALGAS_uint & in_mIndex) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeVarMap_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeVarMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_uint & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeVarMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndex (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeVarMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeCstMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_typeCstMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_typeCstMap_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeCstMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_typeCstMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_typeCstMap (const GALGAS_typeCstMap & inSource) ;
  public : GALGAS_typeCstMap & operator = (const GALGAS_typeCstMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeCstMap extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeCstMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static class GALGAS_typeCstMap constructor_mapWithMapToOverride (const class GALGAS_typeCstMap & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_bool & inOperand1,
                                                      const class GALGAS_luint & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_bool constinArgument1,
                                                   class GALGAS_luint constinArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMSignForKey (class GALGAS_bool constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueForKey (class GALGAS_luint constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_bool & outArgument1,
                                                   class GALGAS_luint & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mSignForKey (const class GALGAS_string & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValueForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeCstMap getter_overriddenMap (C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public : VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                     class GALGAS_bool & outOperand1,
                                                     class GALGAS_luint & outOperand2) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_typeCstMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                        const GALGAS_string & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_typeCstMap ;
 
} ; // End of GALGAS_typeCstMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typeCstMap : public cGenericAbstractEnumerator {
  public : cEnumerator_typeCstMap (const GALGAS_typeCstMap & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_bool current_mSign (LOCATION_ARGS) const ;
  public : class GALGAS_luint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeCstMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@typeCstMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_typeCstMap : public cMapElement {
//--- Map attributes
  public : GALGAS_bool mProperty_mSign ;
  public : GALGAS_luint mProperty_mValue ;

//--- Constructor
  public : cMapElement_typeCstMap (const GALGAS_lstring & inKey,
                                   const GALGAS_bool & in_mSign,
                                   const GALGAS_luint & in_mValue
                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeCstMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeCstMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_lstring mProperty_lkey ;

  public : GALGAS_bool mProperty_mSign ;

  public : GALGAS_luint mProperty_mValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeCstMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_typeCstMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_typeCstMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeCstMap_2D_element (const GALGAS_lstring & in_lkey,
                                         const GALGAS_bool & in_mSign,
                                         const GALGAS_luint & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeCstMap_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeCstMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_bool & inOperand1,
                                                                      const class GALGAS_luint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeCstMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mSign (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeCstMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePreconditionExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePreconditionExpression : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_typePreconditionExpression (void) ;

//---
  public : inline const class cPtr_typePreconditionExpression * ptr (void) const { return (const cPtr_typePreconditionExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typePreconditionExpression (const cPtr_typePreconditionExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePreconditionExpression extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typePreconditionExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typePreconditionExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression ;

#include "separateHeaderFor_typePreconditionExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTrueExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeTrueExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeTrueExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeTrueExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeTrueExpression * ptr (void) const { return (const cPtr_typeTrueExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeTrueExpression (const cPtr_typeTrueExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeTrueExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeTrueExpression constructor_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeTrueExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeTrueExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression ;

#include "separateHeaderFor_typeTrueExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeFalseExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeFalseExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeFalseExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeFalseExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeFalseExpression * ptr (void) const { return (const cPtr_typeFalseExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeFalseExpression (const cPtr_typeFalseExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeFalseExpression extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeFalseExpression constructor_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeFalseExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeFalseExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression ;

#include "separateHeaderFor_typeFalseExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeComplementExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeComplementExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeComplementExpression (void) ;

//---
  public : inline const class cPtr_typeComplementExpression * ptr (void) const { return (const cPtr_typeComplementExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeComplementExpression (const cPtr_typeComplementExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeComplementExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeComplementExpression constructor_new (const class GALGAS_typePreconditionExpression & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeComplementExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMExpression (class GALGAS_typePreconditionExpression inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mExpression (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeComplementExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression ;

#include "separateHeaderFor_typeComplementExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAndExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeAndExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeAndExpression (void) ;

//---
  public : inline const class cPtr_typeAndExpression * ptr (void) const { return (const cPtr_typeAndExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeAndExpression (const cPtr_typeAndExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeAndExpression extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeAndExpression constructor_new (const class GALGAS_typePreconditionExpression & inOperand0,
                                                                  const class GALGAS_typePreconditionExpression & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeAndExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMLeftExpression (class GALGAS_typePreconditionExpression inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMRightExpression (class GALGAS_typePreconditionExpression inArgument0
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mLeftExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mRightExpression (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeAndExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression ;

#include "separateHeaderFor_typeAndExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeOrExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeOrExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeOrExpression (void) ;

//---
  public : inline const class cPtr_typeOrExpression * ptr (void) const { return (const cPtr_typeOrExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeOrExpression (const cPtr_typeOrExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeOrExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeOrExpression constructor_new (const class GALGAS_typePreconditionExpression & inOperand0,
                                                                 const class GALGAS_typePreconditionExpression & inOperand1
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeOrExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMLeftExpression (class GALGAS_typePreconditionExpression inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMRightExpression (class GALGAS_typePreconditionExpression inArgument0
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mLeftExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mRightExpression (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeOrExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression ;

#include "separateHeaderFor_typeOrExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostcondition class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePostcondition : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_typePostcondition (void) ;

//---
  public : inline const class cPtr_typePostcondition * ptr (void) const { return (const cPtr_typePostcondition *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typePostcondition (const cPtr_typePostcondition * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePostcondition extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typePostcondition & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typePostcondition class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition ;

#include "separateHeaderFor_typePostcondition.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePostconditionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_typePostconditionList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_typePostconditionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_typePostcondition & in_mPostcondition
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePostconditionList extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typePostconditionList constructor_emptyList (LOCATION_ARGS) ;

  public : static class GALGAS_typePostconditionList constructor_listWithValue (const class GALGAS_typePostcondition & inOperand0
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typePostconditionList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_typePostcondition & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_typePostconditionList add_operation (const GALGAS_typePostconditionList & inOperand,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_append (class GALGAS_typePostconditionList_2D_element inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_typePostcondition & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_typePostcondition & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_typePostcondition & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMPostconditionAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                                  class GALGAS_uint constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_typePostcondition & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_typePostcondition & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mPostconditionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_typePostconditionList ;
 
} ; // End of GALGAS_typePostconditionList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typePostconditionList : public cGenericAbstractEnumerator {
  public : cEnumerator_typePostconditionList (const GALGAS_typePostconditionList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_typePostcondition current_mPostcondition (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typePostconditionList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePostconditionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_typePostcondition mProperty_mPostcondition ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_typePostconditionList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_typePostconditionList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typePostconditionList_2D_element (const GALGAS_typePostcondition & in_mPostcondition) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePostconditionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typePostconditionList_2D_element constructor_new (const class GALGAS_typePostcondition & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typePostconditionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mPostcondition (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typePostconditionList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeTransitionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_typeTransitionList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_typeTransitionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_mTransitionName,
                                                  const class GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                  const class GALGAS_typePostconditionList & in_mPostconditionList,
                                                  const class GALGAS_uint & in_mLowTemporalBound,
                                                  const class GALGAS_uint & in_mHighTemporalBound
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeTransitionList extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeTransitionList constructor_emptyList (LOCATION_ARGS) ;

  public : static class GALGAS_typeTransitionList constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                             const class GALGAS_typePreconditionExpression & inOperand1,
                                                                             const class GALGAS_typePostconditionList & inOperand2,
                                                                             const class GALGAS_uint & inOperand3,
                                                                             const class GALGAS_uint & inOperand4
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typeTransitionList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_typePreconditionExpression & inOperand1,
                                                      const class GALGAS_typePostconditionList & inOperand2,
                                                      const class GALGAS_uint & inOperand3,
                                                      const class GALGAS_uint & inOperand4
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_typeTransitionList add_operation (const GALGAS_typeTransitionList & inOperand,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_append (class GALGAS_typeTransitionList_2D_element inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_typePreconditionExpression constinArgument1,
                                                       class GALGAS_typePostconditionList constinArgument2,
                                                       class GALGAS_uint constinArgument3,
                                                       class GALGAS_uint constinArgument4,
                                                       class GALGAS_uint constinArgument5,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_typePreconditionExpression & outArgument1,
                                                  class GALGAS_typePostconditionList & outArgument2,
                                                  class GALGAS_uint & outArgument3,
                                                  class GALGAS_uint & outArgument4,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_typePreconditionExpression & outArgument1,
                                                 class GALGAS_typePostconditionList & outArgument2,
                                                 class GALGAS_uint & outArgument3,
                                                 class GALGAS_uint & outArgument4,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                       class GALGAS_typePreconditionExpression & outArgument1,
                                                       class GALGAS_typePostconditionList & outArgument2,
                                                       class GALGAS_uint & outArgument3,
                                                       class GALGAS_uint & outArgument4,
                                                       class GALGAS_uint constinArgument5,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMHighTemporalBoundAtIndex (class GALGAS_uint constinArgument0,
                                                                      class GALGAS_uint constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMLowTemporalBoundAtIndex (class GALGAS_uint constinArgument0,
                                                                     class GALGAS_uint constinArgument1,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMPostconditionListAtIndex (class GALGAS_typePostconditionList constinArgument0,
                                                                      class GALGAS_uint constinArgument1,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMPreconditionExpressionAtIndex (class GALGAS_typePreconditionExpression constinArgument0,
                                                                           class GALGAS_uint constinArgument1,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMTransitionNameAtIndex (class GALGAS_lstring constinArgument0,
                                                                   class GALGAS_uint constinArgument1,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               class GALGAS_typePreconditionExpression & outArgument1,
                                               class GALGAS_typePostconditionList & outArgument2,
                                               class GALGAS_uint & outArgument3,
                                               class GALGAS_uint & outArgument4,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              class GALGAS_typePreconditionExpression & outArgument1,
                                              class GALGAS_typePostconditionList & outArgument2,
                                              class GALGAS_uint & outArgument3,
                                              class GALGAS_uint & outArgument4,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mHighTemporalBoundAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mLowTemporalBoundAtIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_mPostconditionListAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                 C_Compiler * inCompiler
                                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mPreconditionExpressionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                           C_Compiler * inCompiler
                                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mTransitionNameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_typeTransitionList ;
 
} ; // End of GALGAS_typeTransitionList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typeTransitionList : public cGenericAbstractEnumerator {
  public : cEnumerator_typeTransitionList (const GALGAS_typeTransitionList & inEnumeratedObject,
                                           const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_mTransitionName (LOCATION_ARGS) const ;
  public : class GALGAS_typePreconditionExpression current_mPreconditionExpression (LOCATION_ARGS) const ;
  public : class GALGAS_typePostconditionList current_mPostconditionList (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_mLowTemporalBound (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_mHighTemporalBound (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeTransitionList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeTransitionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_lstring mProperty_mTransitionName ;

  public : GALGAS_typePreconditionExpression mProperty_mPreconditionExpression ;

  public : GALGAS_typePostconditionList mProperty_mPostconditionList ;

  public : GALGAS_uint mProperty_mLowTemporalBound ;

  public : GALGAS_uint mProperty_mHighTemporalBound ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_typeTransitionList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_typeTransitionList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeTransitionList_2D_element (const GALGAS_lstring & in_mTransitionName,
                                                 const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                 const GALGAS_typePostconditionList & in_mPostconditionList,
                                                 const GALGAS_uint & in_mLowTemporalBound,
                                                 const GALGAS_uint & in_mHighTemporalBound) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeTransitionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeTransitionList_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_typePreconditionExpression & inOperand1,
                                                                              const class GALGAS_typePostconditionList & inOperand2,
                                                                              const class GALGAS_uint & inOperand3,
                                                                              const class GALGAS_uint & inOperand4
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeTransitionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mHighTemporalBound (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mLowTemporalBound (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_mPostconditionList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mPreconditionExpression (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mTransitionName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeTransitionList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeInitialMarkingList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_typeInitialMarkingList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_typeInitialMarkingList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_typePostcondition & in_mInitValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeInitialMarkingList extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeInitialMarkingList constructor_emptyList (LOCATION_ARGS) ;

  public : static class GALGAS_typeInitialMarkingList constructor_listWithValue (const class GALGAS_typePostcondition & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typeInitialMarkingList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_typePostcondition & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_typeInitialMarkingList add_operation (const GALGAS_typeInitialMarkingList & inOperand,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_append (class GALGAS_typeInitialMarkingList_2D_element inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_typePostcondition & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_typePostcondition & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_typePostcondition & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMInitValueAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_typePostcondition & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_typePostcondition & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mInitValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                       C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_typeInitialMarkingList ;
 
} ; // End of GALGAS_typeInitialMarkingList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typeInitialMarkingList : public cGenericAbstractEnumerator {
  public : cEnumerator_typeInitialMarkingList (const GALGAS_typeInitialMarkingList & inEnumeratedObject,
                                               const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_typePostcondition current_mInitValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typeInitialMarkingList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeInitialMarkingList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_typePostcondition mProperty_mInitValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_typeInitialMarkingList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_typeInitialMarkingList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typeInitialMarkingList_2D_element (const GALGAS_typePostcondition & in_mInitValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeInitialMarkingList_2D_element extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeInitialMarkingList_2D_element constructor_new (const class GALGAS_typePostcondition & inOperand0
                                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeInitialMarkingList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mInitValue (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeInitialMarkingList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @countList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_countList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_countList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_countList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_mName,
                                                  const class GALGAS_typePreconditionExpression & in_mCondition
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_countList extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_countList constructor_emptyList (LOCATION_ARGS) ;

  public : static class GALGAS_countList constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_typePreconditionExpression & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_countList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_typePreconditionExpression & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_countList add_operation (const GALGAS_countList & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_append (class GALGAS_countList_2D_element inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_typePreconditionExpression constinArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_typePreconditionExpression & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_typePreconditionExpression & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                       class GALGAS_typePreconditionExpression & outArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMConditionAtIndex (class GALGAS_typePreconditionExpression constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNameAtIndex (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               class GALGAS_typePreconditionExpression & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              class GALGAS_typePreconditionExpression & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mConditionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mNameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_countList ;
 
} ; // End of GALGAS_countList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_countList : public cGenericAbstractEnumerator {
  public : cEnumerator_countList (const GALGAS_countList & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_mName (LOCATION_ARGS) const ;
  public : class GALGAS_typePreconditionExpression current_mCondition (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_countList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @countList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_countList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public : GALGAS_lstring mProperty_mName ;

  public : GALGAS_typePreconditionExpression mProperty_mCondition ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_countList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : virtual ~ GALGAS_countList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_countList_2D_element (const GALGAS_lstring & in_mName,
                                        const GALGAS_typePreconditionExpression & in_mCondition) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_countList_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_countList_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_typePreconditionExpression & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_countList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mCondition (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_countList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'spec_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_spec_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_spec_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_axiome_ (class GALGAS_uint & outArgument0,
                                       class GALGAS_uint & outArgument1,
                                       class GALGAS_typeVarMap & outArgument2,
                                       class GALGAS_typeTransitionList & outArgument3,
                                       class GALGAS_typeInitialMarkingList & outArgument4,
                                       class GALGAS_countList & outArgument5,
                                       class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_axiome_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_factor_ (class GALGAS_typeVarMap & ioArgument0,
                                       class GALGAS_typeCstMap & ioArgument1,
                                       class GALGAS_typePreconditionExpression & outArgument2,
                                       class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_factor_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_bound_ (class GALGAS_uint & outArgument0,
                                               class GALGAS_uint & outArgument1,
                                               class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_bound_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_constant_ (class GALGAS_typeCstMap & ioArgument0,
                                                  class GALGAS_bool & outArgument1,
                                                  class GALGAS_luint & outArgument2,
                                                  class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_constant_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_postcondition_ (class GALGAS_typeVarMap & ioArgument0,
                                                       class GALGAS_typeCstMap & ioArgument1,
                                                       class GALGAS_typePostconditionList & outArgument2,
                                                       class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_postcondition_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_precondition_ (class GALGAS_typeVarMap & ioArgument0,
                                                      class GALGAS_typeCstMap & ioArgument1,
                                                      class GALGAS_typePreconditionExpression & outArgument2,
                                                      class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_parse_5F_precondition_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_primary_ (class GALGAS_typeVarMap & ioArgument0,
                                        class GALGAS_typeCstMap & ioArgument1,
                                        class GALGAS_typePreconditionExpression & outArgument2,
                                        class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_primary_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_term_ (class GALGAS_typeVarMap & ioArgument0,
                                     class GALGAS_typeCstMap & ioArgument1,
                                     class GALGAS_typePreconditionExpression & outArgument2,
                                     class C_Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_term_parse (class C_Lexique_spec_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_spec_5F_parser_parse_5F_precondition_i0_ (GALGAS_typeVarMap & ioArgument0,
                                                                  GALGAS_typeCstMap & ioArgument1,
                                                                  GALGAS_typePreconditionExpression & outArgument2,
                                                                  C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_precondition_i0_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_term_i1_ (GALGAS_typeVarMap & ioArgument0,
                                                 GALGAS_typeCstMap & ioArgument1,
                                                 GALGAS_typePreconditionExpression & outArgument2,
                                                 C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_term_i1_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_factor_i2_ (GALGAS_typeVarMap & ioArgument0,
                                                   GALGAS_typeCstMap & ioArgument1,
                                                   GALGAS_typePreconditionExpression & outArgument2,
                                                   C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_factor_i2_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_primary_i3_ (GALGAS_typeVarMap & ioArgument0,
                                                    GALGAS_typeCstMap & ioArgument1,
                                                    GALGAS_typePreconditionExpression & outArgument2,
                                                    C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_primary_i3_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_constant_i4_ (GALGAS_typeCstMap & ioArgument0,
                                                              GALGAS_bool & outArgument1,
                                                              GALGAS_luint & outArgument2,
                                                              C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_constant_i4_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_postcondition_i5_ (GALGAS_typeVarMap & ioArgument0,
                                                                   GALGAS_typeCstMap & ioArgument1,
                                                                   GALGAS_typePostconditionList & outArgument2,
                                                                   C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_postcondition_i5_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_bound_i6_ (GALGAS_uint & outArgument0,
                                                           GALGAS_uint & outArgument1,
                                                           C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_bound_i6_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_bound_i7_ (GALGAS_uint & outArgument0,
                                                           GALGAS_uint & outArgument1,
                                                           C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_parse_5F_bound_i7_parse (C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_axiome_i8_ (GALGAS_uint & outArgument0,
                                                   GALGAS_uint & outArgument1,
                                                   GALGAS_typeVarMap & outArgument2,
                                                   GALGAS_typeTransitionList & outArgument3,
                                                   GALGAS_typeInitialMarkingList & outArgument4,
                                                   GALGAS_countList & outArgument5,
                                                   C_Lexique_spec_5F_scanner * inLexique) ;

  protected : void rule_spec_5F_parser_axiome_i8_parse (C_Lexique_spec_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_spec_5F_parser_0 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_1 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_2 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_3 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_4 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_5 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_6 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_7 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_8 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_9 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_10 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_11 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_12 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_13 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_14 (C_Lexique_spec_5F_scanner *) = 0 ;

  protected : virtual int32_t select_spec_5F_parser_15 (C_Lexique_spec_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAddConstant class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeAddConstant : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typeAddConstant (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeAddConstant constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeAddConstant * ptr (void) const { return (const cPtr_typeAddConstant *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeAddConstant (const cPtr_typeAddConstant * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeAddConstant extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeAddConstant constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_uint & inOperand1,
                                                                const class GALGAS_bool & inOperand2,
                                                                const class GALGAS_luint & inOperand3
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeAddConstant & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeAddConstant class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant ;

#include "separateHeaderFor_typeAddConstant.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignConstant class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeAssignConstant : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typeAssignConstant (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeAssignConstant constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeAssignConstant * ptr (void) const { return (const cPtr_typeAssignConstant *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeAssignConstant (const cPtr_typeAssignConstant * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeAssignConstant extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeAssignConstant constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_uint & inOperand1,
                                                                   const class GALGAS_bool & inOperand2,
                                                                   const class GALGAS_luint & inOperand3
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeAssignConstant & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeAssignConstant class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant ;

#include "separateHeaderFor_typeAssignConstant.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignInfinity class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeAssignInfinity : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typeAssignInfinity (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeAssignInfinity constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeAssignInfinity * ptr (void) const { return (const cPtr_typeAssignInfinity *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeAssignInfinity (const cPtr_typeAssignInfinity * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeAssignInfinity extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeAssignInfinity constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_uint & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeAssignInfinity & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeAssignInfinity class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity ;

#include "separateHeaderFor_typeAssignInfinity.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeEqualExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeEqualExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeEqualExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeEqualExpression * ptr (void) const { return (const cPtr_typeEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeEqualExpression (const cPtr_typeEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeEqualExpression extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeEqualExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                    const class GALGAS_bool & inOperand1,
                                                                    const class GALGAS_luint & inOperand2
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeEqualExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression ;

#include "separateHeaderFor_typeEqualExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInfOrEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeInfOrEqualExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeInfOrEqualExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeInfOrEqualExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeInfOrEqualExpression * ptr (void) const { return (const cPtr_typeInfOrEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeInfOrEqualExpression (const cPtr_typeInfOrEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeInfOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeInfOrEqualExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                         const class GALGAS_bool & inOperand1,
                                                                         const class GALGAS_luint & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeInfOrEqualExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeInfOrEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;

#include "separateHeaderFor_typeInfOrEqualExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeNonEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeNonEqualExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeNonEqualExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeNonEqualExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeNonEqualExpression * ptr (void) const { return (const cPtr_typeNonEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeNonEqualExpression (const cPtr_typeNonEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeNonEqualExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeNonEqualExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                       const class GALGAS_bool & inOperand1,
                                                                       const class GALGAS_luint & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeNonEqualExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeNonEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression ;

#include "separateHeaderFor_typeNonEqualExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostDecrement class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePostDecrement : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typePostDecrement (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typePostDecrement constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typePostDecrement * ptr (void) const { return (const cPtr_typePostDecrement *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typePostDecrement (const cPtr_typePostDecrement * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePostDecrement extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typePostDecrement constructor_new (const class GALGAS_lstring & inOperand0,
                                                                  const class GALGAS_uint & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typePostDecrement & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typePostDecrement class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement ;

#include "separateHeaderFor_typePostDecrement.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostIncrement class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typePostIncrement : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typePostIncrement (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typePostIncrement constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typePostIncrement * ptr (void) const { return (const cPtr_typePostIncrement *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typePostIncrement (const cPtr_typePostIncrement * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typePostIncrement extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typePostIncrement constructor_new (const class GALGAS_lstring & inOperand0,
                                                                  const class GALGAS_uint & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typePostIncrement & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typePostIncrement class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement ;

#include "separateHeaderFor_typePostIncrement.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictInfExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeStrictInfExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeStrictInfExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeStrictInfExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeStrictInfExpression * ptr (void) const { return (const cPtr_typeStrictInfExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeStrictInfExpression (const cPtr_typeStrictInfExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeStrictInfExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeStrictInfExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                        const class GALGAS_bool & inOperand1,
                                                                        const class GALGAS_luint & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeStrictInfExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeStrictInfExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression ;

#include "separateHeaderFor_typeStrictInfExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictSupExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeStrictSupExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeStrictSupExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeStrictSupExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeStrictSupExpression * ptr (void) const { return (const cPtr_typeStrictSupExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeStrictSupExpression (const cPtr_typeStrictSupExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeStrictSupExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeStrictSupExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                        const class GALGAS_bool & inOperand1,
                                                                        const class GALGAS_luint & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeStrictSupExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeStrictSupExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression ;

#include "separateHeaderFor_typeStrictSupExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSubConstant class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeSubConstant : public GALGAS_typePostcondition {
//--- Constructor
  public : GALGAS_typeSubConstant (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeSubConstant constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeSubConstant * ptr (void) const { return (const cPtr_typeSubConstant *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeSubConstant (const cPtr_typeSubConstant * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeSubConstant extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeSubConstant constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_uint & inOperand1,
                                                                const class GALGAS_bool & inOperand2,
                                                                const class GALGAS_luint & inOperand3
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeSubConstant & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVarName (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeSubConstant class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant ;

#include "separateHeaderFor_typeSubConstant.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSupOrEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typeSupOrEqualExpression : public GALGAS_typePreconditionExpression {
//--- Constructor
  public : GALGAS_typeSupOrEqualExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_typeSupOrEqualExpression constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_typeSupOrEqualExpression * ptr (void) const { return (const cPtr_typeSupOrEqualExpression *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_typeSupOrEqualExpression (const cPtr_typeSupOrEqualExpression * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typeSupOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static class GALGAS_typeSupOrEqualExpression constructor_new (const class GALGAS_uint & inOperand0,
                                                                         const class GALGAS_bool & inOperand1,
                                                                         const class GALGAS_luint & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typeSupOrEqualExpression & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (class GALGAS_luint inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (class GALGAS_bool inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMVar (class GALGAS_uint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mVar (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typeSupOrEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;

#include "separateHeaderFor_typeSupOrEqualExpression.h"

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR spec_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_spec_5F_grammar : public cParser_spec_5F_parser {
//------------------------------------- 'axiome' non terminal
//--- 'parse' label
  public : virtual void nt_axiome_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_axiome_ (GALGAS_uint & outArgument0,
                                    GALGAS_uint & outArgument1,
                                    GALGAS_typeVarMap & outArgument2,
                                    GALGAS_typeTransitionList & outArgument3,
                                    GALGAS_typeInitialMarkingList & outArgument4,
                                    GALGAS_countList & outArgument5,
                                    C_Lexique_spec_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_uint & outArgument0,
                                                   GALGAS_uint & outArgument1,
                                                   GALGAS_typeVarMap & outArgument2,
                                                   GALGAS_typeTransitionList & outArgument3,
                                                   GALGAS_typeInitialMarkingList & outArgument4,
                                                   GALGAS_countList & outArgument5
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_string inNameString,
                                                     GALGAS_uint & outArgument0,
                                                     GALGAS_uint & outArgument1,
                                                     GALGAS_typeVarMap & outArgument2,
                                                     GALGAS_typeTransitionList & outArgument3,
                                                     GALGAS_typeInitialMarkingList & outArgument4,
                                                     GALGAS_countList & outArgument5
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'factor' non terminal
//--- 'parse' label
  public : virtual void nt_factor_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_factor_ (GALGAS_typeVarMap & ioArgument0,
                                    GALGAS_typeCstMap & ioArgument1,
                                    GALGAS_typePreconditionExpression & outArgument2,
                                    C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_bound' non terminal
//--- 'parse' label
  public : virtual void nt_parse_5F_bound_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_parse_5F_bound_ (GALGAS_uint & outArgument0,
                                            GALGAS_uint & outArgument1,
                                            C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_constant' non terminal
//--- 'parse' label
  public : virtual void nt_parse_5F_constant_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_parse_5F_constant_ (GALGAS_typeCstMap & ioArgument0,
                                               GALGAS_bool & outArgument1,
                                               GALGAS_luint & outArgument2,
                                               C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_postcondition' non terminal
//--- 'parse' label
  public : virtual void nt_parse_5F_postcondition_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_parse_5F_postcondition_ (GALGAS_typeVarMap & ioArgument0,
                                                    GALGAS_typeCstMap & ioArgument1,
                                                    GALGAS_typePostconditionList & outArgument2,
                                                    C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_precondition' non terminal
//--- 'parse' label
  public : virtual void nt_parse_5F_precondition_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_parse_5F_precondition_ (GALGAS_typeVarMap & ioArgument0,
                                                   GALGAS_typeCstMap & ioArgument1,
                                                   GALGAS_typePreconditionExpression & outArgument2,
                                                   C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'primary' non terminal
//--- 'parse' label
  public : virtual void nt_primary_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_primary_ (GALGAS_typeVarMap & ioArgument0,
                                     GALGAS_typeCstMap & ioArgument1,
                                     GALGAS_typePreconditionExpression & outArgument2,
                                     C_Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'term' non terminal
//--- 'parse' label
  public : virtual void nt_term_parse (C_Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_term_ (GALGAS_typeVarMap & ioArgument0,
                                  GALGAS_typeCstMap & ioArgument1,
                                  GALGAS_typePreconditionExpression & outArgument2,
                                  C_Lexique_spec_5F_scanner * inCompiler) ;

  public : virtual int32_t select_spec_5F_parser_0 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_1 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_2 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_3 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_4 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_5 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_6 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_7 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_8 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_9 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_10 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_11 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_12 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_13 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_14 (C_Lexique_spec_5F_scanner *) ;

  public : virtual int32_t select_spec_5F_parser_15 (C_Lexique_spec_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

extern C_BoolCommandLineOption gOption_spec_5F_options_computeSimultaneousFiring ;

extern C_BoolCommandLineOption gOption_spec_5F_options_doNotPrintIteration ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printFiring ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printInference ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printIterationStates ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printMinMax ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printNodes ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printPreConditions ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printStates ;

extern C_BoolCommandLineOption gOption_spec_5F_options_printTemporalBounds ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

extern C_UIntCommandLineOption gOption_spec_5F_options_stopAfterIteration ;

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

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_code'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_code (const class GALGAS_uint constinArgument0,
                               const class GALGAS_uint constinArgument1,
                               const class GALGAS_typeVarMap constinArgument2,
                               const class GALGAS_typeTransitionList constinArgument3,
                               const class GALGAS_typeInitialMarkingList constinArgument4,
                               const class GALGAS_countList constinArgument5,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;
