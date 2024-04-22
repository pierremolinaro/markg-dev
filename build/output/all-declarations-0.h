#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
// Phase 1: @2lstringlist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS__32_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS__32_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS__32_lstringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_mValue_30_,
                                                 const class GALGAS_lstring & in_mValue_31_
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS__32_lstringlist init (Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS__32_lstringlist extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS__32_lstringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS__32_lstringlist class_func_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_lstring & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS__32_lstringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_lstring & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS__32_lstringlist add_operation (const GALGAS__32_lstringlist & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               class GALGAS_lstring constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_lstring constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_lstring & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                class GALGAS_lstring & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_lstring & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GALGAS_lstring constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GALGAS_lstring constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             class GALGAS_lstring & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_30_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_31_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS__32_lstringlist_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator__32_lstringlist ;
 
} ; // End of GALGAS__32_lstringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator__32_lstringlist : public cGenericAbstractEnumerator {
  public: cEnumerator__32_lstringlist (const GALGAS__32_lstringlist & inEnumeratedObject,
                                       const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_mValue_30_ (LOCATION_ARGS) const ;
  public: class GALGAS_lstring current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS__32_lstringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @_32_lstringlist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS__32_lstringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_mValue_30_ ;
  public: inline GALGAS_lstring readProperty_mValue_30_ (void) const {
    return mProperty_mValue_30_ ;
  }

  public: GALGAS_lstring mProperty_mValue_31_ ;
  public: inline GALGAS_lstring readProperty_mValue_31_ (void) const {
    return mProperty_mValue_31_ ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS__32_lstringlist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue_30_ (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_30_ = inValue ;
  }

  public: inline void setter_setMValue_31_ (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_31_ = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS__32_lstringlist_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS__32_lstringlist_2D_element (const GALGAS_lstring & in_mValue_30_,
                                             const GALGAS_lstring & in_mValue_31_) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS__32_lstringlist_2D_element init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_lstring & inOperand1,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS__32_lstringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS__32_lstringlist_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_lstring & inOperand1,
                                                                         class Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS__32_lstringlist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//LEXIQUE spec_5F_scanner
//
//--------------------------------------------------------------------------------------------------

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//--------------------------------------------------------------------------------------------------

class cTokenFor_spec_5F_scanner : public cToken {
  public: String mLexicalAttribute_theString ;
  public: uint32_t mLexicalAttribute_ulongValue ;

  public: cTokenFor_spec_5F_scanner (void) ;
} ;

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class Lexique_spec_5F_scanner : public Lexique {
//--- Constructors
  public: Lexique_spec_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: Lexique_spec_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceString,
                       const String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ Lexique_spec_5F_scanner (void) { }
  #endif



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_identifier /* 1 */ ,
   kToken_literal_5F_string /* 2 */ ,
   kToken_literal_5F_integer /* 3 */ ,
   kToken_system /* 4 */ ,
   kToken_var /* 5 */ ,
   kToken_rule /* 6 */ ,
   kToken_init /* 7 */ ,
   kToken_end /* 8 */ ,
   kToken_true /* 9 */ ,
   kToken_false /* 10 */ ,
   kToken_const /* 11 */ ,
   kToken_count /* 12 */ ,
   kToken_infinity /* 13 */ ,
   kToken_hashmapsize /* 14 */ ,
   kToken_garbageperiod /* 15 */ ,
   kToken__3E__3D_ /* 16 */ ,
   kToken__3E_ /* 17 */ ,
   kToken__3C_ /* 18 */ ,
   kToken__3C__3D_ /* 19 */ ,
   kToken__3D__3D_ /* 20 */ ,
   kToken__21__3D_ /* 21 */ ,
   kToken__26_ /* 22 */ ,
   kToken__7C_ /* 23 */ ,
   kToken__7E_ /* 24 */ ,
   kToken__2C_ /* 25 */ ,
   kToken__3B_ /* 26 */ ,
   kToken__28_ /* 27 */ ,
   kToken__29_ /* 28 */ ,
   kToken__2B__2B_ /* 29 */ ,
   kToken__2D__2D_ /* 30 */ ,
   kToken__2B__3D_ /* 31 */ ,
   kToken__2D__3D_ /* 32 */ ,
   kToken__3A__3D_ /* 33 */ ,
   kToken__7B_ /* 34 */ ,
   kToken__7D_ /* 35 */ ,
   kToken__3A_ /* 36 */ ,
   kToken__2D_ /* 37 */ ,
   kToken__3D_ /* 38 */ ,
   kToken__5B_ /* 39 */ ,
   kToken__5D_ /* 40 */ } ;

//--- Key words table 'galgasKeyWordList'
  public: static int32_t search_into_galgasKeyWordList (const String & inSearchedString) ;

//--- Key words table 'delimitorsList'
  public: static int32_t search_into_delimitorsList (const String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_theString (void) const ;
  public: GALGAS_luint synthetizedAttribute_ulongValue (void) const ;


//--- Attribute access
  public: String attributeValue_theString (void) const ;
  public: uint32_t attributeValue_ulongValue (void) const ;


//--- indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_spec_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 40 ; }

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_spec_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeVarMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_typeVarMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_typeVarMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GALGAS_typeVarMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_typeVarMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_typeVarMap (const GALGAS_typeVarMap & inSource) ;
  public: GALGAS_typeVarMap & operator = (const GALGAS_typeVarMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeVarMap init (Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeVarMap extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeVarMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_typeVarMap class_func_mapWithMapToOverride (const class GALGAS_typeVarMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typeVarMap add_operation (const GALGAS_typeVarMap & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint constinArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GALGAS_uint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_uint & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mIndexForKey (const class GALGAS_string & constinOperand0,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeVarMap getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_uint & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_typeVarMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_typeVarMap_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeVarMap ;
 
} ; // End of GALGAS_typeVarMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeVarMap : public cGenericAbstractEnumerator {
  public: cEnumerator_typeVarMap (const GALGAS_typeVarMap & inEnumeratedObject,
                                  const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mIndex (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typeVarMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@typeVarMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_typeVarMap : public cMapElement {
//--- Map attributes
  public: GALGAS_uint mProperty_mIndex ;

//--- Constructors
  public: cMapElement_typeVarMap (const GALGAS_typeVarMap_2D_element & inValue
                                  COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_typeVarMap (const GALGAS_lstring & inKey,
                                  const GALGAS_uint & in_mIndex
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeVarMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeVarMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_uint mProperty_mIndex ;
  public: inline GALGAS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typeVarMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_typeVarMap_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_typeVarMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_uint & in_mIndex) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeVarMap_2D_element init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                            const class GALGAS_uint & inOperand1,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeVarMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeVarMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_uint & inOperand1,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeVarMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeCstMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_typeCstMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_typeCstMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GALGAS_typeCstMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_typeCstMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_typeCstMap (const GALGAS_typeCstMap & inSource) ;
  public: GALGAS_typeCstMap & operator = (const GALGAS_typeCstMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeCstMap init (Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeCstMap extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeCstMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_typeCstMap class_func_mapWithMapToOverride (const class GALGAS_typeCstMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_bool & inOperand1,
                                                     const class GALGAS_luint & inOperand2,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typeCstMap add_operation (const GALGAS_typeCstMap & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_bool constinArgument1,
                                                  class GALGAS_luint constinArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMSignForKey (class GALGAS_bool constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueForKey (class GALGAS_luint constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_bool & outArgument1,
                                                  class GALGAS_luint & outArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_mSignForKey (const class GALGAS_string & constinOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValueForKey (const class GALGAS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeCstMap getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_bool & outOperand1,
                                                    class GALGAS_luint & outOperand2) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_typeCstMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_typeCstMap_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeCstMap ;
 
} ; // End of GALGAS_typeCstMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeCstMap : public cGenericAbstractEnumerator {
  public: cEnumerator_typeCstMap (const GALGAS_typeCstMap & inEnumeratedObject,
                                  const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_bool current_mSign (LOCATION_ARGS) const ;
  public: class GALGAS_luint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typeCstMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@typeCstMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_typeCstMap : public cMapElement {
//--- Map attributes
  public: GALGAS_bool mProperty_mSign ;
  public: GALGAS_luint mProperty_mValue ;

//--- Constructors
  public: cMapElement_typeCstMap (const GALGAS_typeCstMap_2D_element & inValue
                                  COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_typeCstMap (const GALGAS_lstring & inKey,
                                  const GALGAS_bool & in_mSign,
                                  const GALGAS_luint & in_mValue
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeCstMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeCstMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_bool mProperty_mSign ;
  public: inline GALGAS_bool readProperty_mSign (void) const {
    return mProperty_mSign ;
  }

  public: GALGAS_luint mProperty_mValue ;
  public: inline GALGAS_luint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typeCstMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMSign (const GALGAS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mSign = inValue ;
  }

  public: inline void setter_setMValue (const GALGAS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_typeCstMap_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_typeCstMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_bool & in_mSign,
                                        const GALGAS_luint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeCstMap_2D_element init_21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_bool & inOperand1,
                                                                const class GALGAS_luint & inOperand2,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeCstMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeCstMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_bool & inOperand1,
                                                                    const class GALGAS_luint & inOperand2,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeCstMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePreconditionExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePreconditionExpression : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GALGAS_typePreconditionExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typePreconditionExpression (const class cPtr_typePreconditionExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePreconditionExpression init (Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePreconditionExpression extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePreconditionExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePreconditionExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression ;

#include "separateHeaderFor_typePreconditionExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePreconditionExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePreconditionExpression_2D_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GALGAS_typePreconditionExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typePreconditionExpression_2D_weak (const class GALGAS_typePreconditionExpression & inSource) ;

  public: GALGAS_typePreconditionExpression_2D_weak & operator = (const class GALGAS_typePreconditionExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typePreconditionExpression bang_typePreconditionExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePreconditionExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePreconditionExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePreconditionExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePreconditionExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTrueExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeTrueExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeTrueExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeTrueExpression (const class cPtr_typeTrueExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeTrueExpression init (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeTrueExpression extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeTrueExpression class_func_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeTrueExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeTrueExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression ;

#include "separateHeaderFor_typeTrueExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTrueExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeTrueExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeTrueExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeTrueExpression_2D_weak (const class GALGAS_typeTrueExpression & inSource) ;

  public: GALGAS_typeTrueExpression_2D_weak & operator = (const class GALGAS_typeTrueExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeTrueExpression bang_typeTrueExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeTrueExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeTrueExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeTrueExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeTrueExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeFalseExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeFalseExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeFalseExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeFalseExpression (const class cPtr_typeFalseExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeFalseExpression init (Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeFalseExpression extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeFalseExpression class_func_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeFalseExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeFalseExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression ;

#include "separateHeaderFor_typeFalseExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeFalseExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeFalseExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeFalseExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeFalseExpression_2D_weak (const class GALGAS_typeFalseExpression & inSource) ;

  public: GALGAS_typeFalseExpression_2D_weak & operator = (const class GALGAS_typeFalseExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeFalseExpression bang_typeFalseExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeFalseExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeFalseExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeFalseExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeFalseExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeComplementExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeComplementExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeComplementExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeComplementExpression (const class cPtr_typeComplementExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_typePreconditionExpression readProperty_mExpression (void) const ;
  public: void setProperty_mExpression (const GALGAS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeComplementExpression init_21_ (const class GALGAS_typePreconditionExpression & inOperand0,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeComplementExpression extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeComplementExpression class_func_new (const class GALGAS_typePreconditionExpression & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeComplementExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeComplementExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression ;

#include "separateHeaderFor_typeComplementExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeComplementExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeComplementExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeComplementExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeComplementExpression_2D_weak (const class GALGAS_typeComplementExpression & inSource) ;

  public: GALGAS_typeComplementExpression_2D_weak & operator = (const class GALGAS_typeComplementExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeComplementExpression bang_typeComplementExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeComplementExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeComplementExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeComplementExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeComplementExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAndExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAndExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeAndExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeAndExpression (const class cPtr_typeAndExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_typePreconditionExpression readProperty_mLeftExpression (void) const ;
  public: void setProperty_mLeftExpression (const GALGAS_typePreconditionExpression & inValue) ;

  public: class GALGAS_typePreconditionExpression readProperty_mRightExpression (void) const ;
  public: void setProperty_mRightExpression (const GALGAS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeAndExpression init_21__21_ (const class GALGAS_typePreconditionExpression & inOperand0,
                                                        const class GALGAS_typePreconditionExpression & inOperand1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAndExpression extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAndExpression class_func_new (const class GALGAS_typePreconditionExpression & inOperand0,
                                                                const class GALGAS_typePreconditionExpression & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAndExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAndExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression ;

#include "separateHeaderFor_typeAndExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAndExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAndExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeAndExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeAndExpression_2D_weak (const class GALGAS_typeAndExpression & inSource) ;

  public: GALGAS_typeAndExpression_2D_weak & operator = (const class GALGAS_typeAndExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeAndExpression bang_typeAndExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAndExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAndExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAndExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAndExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeOrExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeOrExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeOrExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeOrExpression (const class cPtr_typeOrExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_typePreconditionExpression readProperty_mLeftExpression (void) const ;
  public: void setProperty_mLeftExpression (const GALGAS_typePreconditionExpression & inValue) ;

  public: class GALGAS_typePreconditionExpression readProperty_mRightExpression (void) const ;
  public: void setProperty_mRightExpression (const GALGAS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeOrExpression init_21__21_ (const class GALGAS_typePreconditionExpression & inOperand0,
                                                       const class GALGAS_typePreconditionExpression & inOperand1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeOrExpression extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeOrExpression class_func_new (const class GALGAS_typePreconditionExpression & inOperand0,
                                                               const class GALGAS_typePreconditionExpression & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeOrExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeOrExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression ;

#include "separateHeaderFor_typeOrExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeOrExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeOrExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeOrExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeOrExpression_2D_weak (const class GALGAS_typeOrExpression & inSource) ;

  public: GALGAS_typeOrExpression_2D_weak & operator = (const class GALGAS_typeOrExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeOrExpression bang_typeOrExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeOrExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeOrExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeOrExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeOrExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeEqualExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeEqualExpression (const class cPtr_typeEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeEqualExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                              const class GALGAS_bool & inOperand1,
                                                              const class GALGAS_luint & inOperand2,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeEqualExpression extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeEqualExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                  const class GALGAS_bool & inOperand1,
                                                                  const class GALGAS_luint & inOperand2
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression ;

#include "separateHeaderFor_typeEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeEqualExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeEqualExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeEqualExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeEqualExpression_2D_weak (const class GALGAS_typeEqualExpression & inSource) ;

  public: GALGAS_typeEqualExpression_2D_weak & operator = (const class GALGAS_typeEqualExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeEqualExpression bang_typeEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeEqualExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeEqualExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeEqualExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeEqualExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeNonEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeNonEqualExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeNonEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeNonEqualExpression (const class cPtr_typeNonEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeNonEqualExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                                 const class GALGAS_bool & inOperand1,
                                                                 const class GALGAS_luint & inOperand2,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeNonEqualExpression extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeNonEqualExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                     const class GALGAS_bool & inOperand1,
                                                                     const class GALGAS_luint & inOperand2
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeNonEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeNonEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression ;

#include "separateHeaderFor_typeNonEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeNonEqualExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeNonEqualExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeNonEqualExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeNonEqualExpression_2D_weak (const class GALGAS_typeNonEqualExpression & inSource) ;

  public: GALGAS_typeNonEqualExpression_2D_weak & operator = (const class GALGAS_typeNonEqualExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeNonEqualExpression bang_typeNonEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeNonEqualExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeNonEqualExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeNonEqualExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeNonEqualExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInfOrEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeInfOrEqualExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeInfOrEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeInfOrEqualExpression (const class cPtr_typeInfOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeInfOrEqualExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                                   const class GALGAS_bool & inOperand1,
                                                                   const class GALGAS_luint & inOperand2,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeInfOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeInfOrEqualExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                       const class GALGAS_bool & inOperand1,
                                                                       const class GALGAS_luint & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeInfOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeInfOrEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;

#include "separateHeaderFor_typeInfOrEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInfOrEqualExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeInfOrEqualExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeInfOrEqualExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeInfOrEqualExpression_2D_weak (const class GALGAS_typeInfOrEqualExpression & inSource) ;

  public: GALGAS_typeInfOrEqualExpression_2D_weak & operator = (const class GALGAS_typeInfOrEqualExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeInfOrEqualExpression bang_typeInfOrEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeInfOrEqualExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeInfOrEqualExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeInfOrEqualExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeInfOrEqualExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSupOrEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeSupOrEqualExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeSupOrEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeSupOrEqualExpression (const class cPtr_typeSupOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeSupOrEqualExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                                   const class GALGAS_bool & inOperand1,
                                                                   const class GALGAS_luint & inOperand2,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeSupOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeSupOrEqualExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                       const class GALGAS_bool & inOperand1,
                                                                       const class GALGAS_luint & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeSupOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeSupOrEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;

#include "separateHeaderFor_typeSupOrEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSupOrEqualExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeSupOrEqualExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeSupOrEqualExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeSupOrEqualExpression_2D_weak (const class GALGAS_typeSupOrEqualExpression & inSource) ;

  public: GALGAS_typeSupOrEqualExpression_2D_weak & operator = (const class GALGAS_typeSupOrEqualExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeSupOrEqualExpression bang_typeSupOrEqualExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeSupOrEqualExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeSupOrEqualExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeSupOrEqualExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeSupOrEqualExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictInfExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeStrictInfExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeStrictInfExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeStrictInfExpression (const class cPtr_typeStrictInfExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeStrictInfExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                                  const class GALGAS_bool & inOperand1,
                                                                  const class GALGAS_luint & inOperand2,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeStrictInfExpression extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeStrictInfExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                      const class GALGAS_bool & inOperand1,
                                                                      const class GALGAS_luint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeStrictInfExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeStrictInfExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression ;

#include "separateHeaderFor_typeStrictInfExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictInfExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeStrictInfExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeStrictInfExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeStrictInfExpression_2D_weak (const class GALGAS_typeStrictInfExpression & inSource) ;

  public: GALGAS_typeStrictInfExpression_2D_weak & operator = (const class GALGAS_typeStrictInfExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeStrictInfExpression bang_typeStrictInfExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeStrictInfExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeStrictInfExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeStrictInfExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeStrictInfExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictSupExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeStrictSupExpression : public GALGAS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GALGAS_typeStrictSupExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeStrictSupExpression (const class cPtr_typeStrictSupExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeStrictSupExpression init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                                  const class GALGAS_bool & inOperand1,
                                                                  const class GALGAS_luint & inOperand2,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeStrictSupExpression extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeStrictSupExpression class_func_new (const class GALGAS_uint & inOperand0,
                                                                      const class GALGAS_bool & inOperand1,
                                                                      const class GALGAS_luint & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeStrictSupExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeStrictSupExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression ;

#include "separateHeaderFor_typeStrictSupExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictSupExpression_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeStrictSupExpression_2D_weak : public GALGAS_typePreconditionExpression_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeStrictSupExpression_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeStrictSupExpression_2D_weak (const class GALGAS_typeStrictSupExpression & inSource) ;

  public: GALGAS_typeStrictSupExpression_2D_weak & operator = (const class GALGAS_typeStrictSupExpression & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeStrictSupExpression bang_typeStrictSupExpression_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeStrictSupExpression_2D_weak extractObject (const GALGAS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeStrictSupExpression_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeStrictSupExpression_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeStrictSupExpression_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostcondition reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostcondition : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GALGAS_typePostcondition (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typePostcondition (const class cPtr_typePostcondition * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePostcondition init (Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostcondition extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostcondition & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostcondition class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition ;

#include "separateHeaderFor_typePostcondition.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostcondition_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostcondition_2D_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GALGAS_typePostcondition_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typePostcondition_2D_weak (const class GALGAS_typePostcondition & inSource) ;

  public: GALGAS_typePostcondition_2D_weak & operator = (const class GALGAS_typePostcondition & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typePostcondition bang_typePostcondition_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostcondition_2D_weak extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostcondition_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostcondition_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostcondition_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostIncrement reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostIncrement : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typePostIncrement (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typePostIncrement (const class cPtr_typePostIncrement * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePostIncrement init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                        const class GALGAS_uint & inOperand1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostIncrement extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostIncrement class_func_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_uint & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostIncrement & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostIncrement class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement ;

#include "separateHeaderFor_typePostIncrement.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostIncrement_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostIncrement_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typePostIncrement_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typePostIncrement_2D_weak (const class GALGAS_typePostIncrement & inSource) ;

  public: GALGAS_typePostIncrement_2D_weak & operator = (const class GALGAS_typePostIncrement & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typePostIncrement bang_typePostIncrement_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostIncrement_2D_weak extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostIncrement_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostIncrement_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostIncrement_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostDecrement reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostDecrement : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typePostDecrement (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typePostDecrement (const class cPtr_typePostDecrement * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePostDecrement init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                        const class GALGAS_uint & inOperand1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostDecrement extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostDecrement class_func_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_uint & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostDecrement & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostDecrement class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement ;

#include "separateHeaderFor_typePostDecrement.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostDecrement_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostDecrement_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typePostDecrement_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typePostDecrement_2D_weak (const class GALGAS_typePostDecrement & inSource) ;

  public: GALGAS_typePostDecrement_2D_weak & operator = (const class GALGAS_typePostDecrement & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typePostDecrement bang_typePostDecrement_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostDecrement_2D_weak extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostDecrement_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typePostDecrement_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostDecrement_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAddConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAddConstant : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typeAddConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeAddConstant (const class cPtr_typeAddConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeAddConstant init_21__21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_uint & inOperand1,
                                                              const class GALGAS_bool & inOperand2,
                                                              const class GALGAS_luint & inOperand3,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAddConstant extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAddConstant class_func_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_uint & inOperand1,
                                                              const class GALGAS_bool & inOperand2,
                                                              const class GALGAS_luint & inOperand3
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAddConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAddConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant ;

#include "separateHeaderFor_typeAddConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAddConstant_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAddConstant_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeAddConstant_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeAddConstant_2D_weak (const class GALGAS_typeAddConstant & inSource) ;

  public: GALGAS_typeAddConstant_2D_weak & operator = (const class GALGAS_typeAddConstant & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeAddConstant bang_typeAddConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAddConstant_2D_weak extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAddConstant_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAddConstant_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAddConstant_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSubConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeSubConstant : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typeSubConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeSubConstant (const class cPtr_typeSubConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeSubConstant init_21__21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_uint & inOperand1,
                                                              const class GALGAS_bool & inOperand2,
                                                              const class GALGAS_luint & inOperand3,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeSubConstant extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeSubConstant class_func_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_uint & inOperand1,
                                                              const class GALGAS_bool & inOperand2,
                                                              const class GALGAS_luint & inOperand3
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeSubConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeSubConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant ;

#include "separateHeaderFor_typeSubConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSubConstant_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeSubConstant_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeSubConstant_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeSubConstant_2D_weak (const class GALGAS_typeSubConstant & inSource) ;

  public: GALGAS_typeSubConstant_2D_weak & operator = (const class GALGAS_typeSubConstant & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeSubConstant bang_typeSubConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeSubConstant_2D_weak extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeSubConstant_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeSubConstant_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeSubConstant_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAssignConstant : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typeAssignConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeAssignConstant (const class cPtr_typeAssignConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

  public: class GALGAS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GALGAS_bool & inValue) ;

  public: class GALGAS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GALGAS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeAssignConstant init_21__21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_uint & inOperand1,
                                                                 const class GALGAS_bool & inOperand2,
                                                                 const class GALGAS_luint & inOperand3,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAssignConstant extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAssignConstant class_func_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_uint & inOperand1,
                                                                 const class GALGAS_bool & inOperand2,
                                                                 const class GALGAS_luint & inOperand3
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAssignConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAssignConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant ;

#include "separateHeaderFor_typeAssignConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignConstant_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAssignConstant_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeAssignConstant_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeAssignConstant_2D_weak (const class GALGAS_typeAssignConstant & inSource) ;

  public: GALGAS_typeAssignConstant_2D_weak & operator = (const class GALGAS_typeAssignConstant & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeAssignConstant bang_typeAssignConstant_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAssignConstant_2D_weak extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAssignConstant_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAssignConstant_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAssignConstant_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignInfinity reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAssignInfinity : public GALGAS_typePostcondition {
//--------------------------------- Default constructor
  public: GALGAS_typeAssignInfinity (void) ;

//--------------------------------- Constructor from pointer
  public: GALGAS_typeAssignInfinity (const class cPtr_typeAssignInfinity * inSourcePtr) ;

//--------------------------------- Property access
  public: class GALGAS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GALGAS_lstring & inValue) ;

  public: class GALGAS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GALGAS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeAssignInfinity init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                         const class GALGAS_uint & inOperand1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAssignInfinity extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAssignInfinity class_func_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_uint & inOperand1
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAssignInfinity & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAssignInfinity class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity ;

#include "separateHeaderFor_typeAssignInfinity.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignInfinity_2D_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeAssignInfinity_2D_weak : public GALGAS_typePostcondition_2D_weak {
//--------------------------------- Default constructor
  public: GALGAS_typeAssignInfinity_2D_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GALGAS_typeAssignInfinity_2D_weak (const class GALGAS_typeAssignInfinity & inSource) ;

  public: GALGAS_typeAssignInfinity_2D_weak & operator = (const class GALGAS_typeAssignInfinity & inSource) ;

//--------------------------------- Bang operator
  public: GALGAS_typeAssignInfinity bang_typeAssignInfinity_2D_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeAssignInfinity_2D_weak extractObject (const GALGAS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeAssignInfinity_2D_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GALGAS_typeAssignInfinity_2D_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeAssignInfinity_2D_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity_2D_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostconditionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_typePostconditionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_typePostconditionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_typePostcondition & in_mPostcondition
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePostconditionList init (Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostconditionList extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostconditionList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_typePostconditionList class_func_listWithValue (const class GALGAS_typePostcondition & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typePostconditionList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_typePostcondition & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typePostconditionList add_operation (const GALGAS_typePostconditionList & inOperand,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_typePostcondition constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_typePostcondition & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_typePostcondition & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_typePostcondition & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPostconditionAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                                 class GALGAS_uint constinArgument1,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_typePostcondition & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_typePostcondition & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mPostconditionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_typePostconditionList_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typePostconditionList ;
 
} ; // End of GALGAS_typePostconditionList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typePostconditionList : public cGenericAbstractEnumerator {
  public: cEnumerator_typePostconditionList (const GALGAS_typePostconditionList & inEnumeratedObject,
                                             const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_typePostcondition current_mPostcondition (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typePostconditionList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typePostconditionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_typePostcondition mProperty_mPostcondition ;
  public: inline GALGAS_typePostcondition readProperty_mPostcondition (void) const {
    return mProperty_mPostcondition ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typePostconditionList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMPostcondition (const GALGAS_typePostcondition & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPostcondition = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_typePostconditionList_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_typePostconditionList_2D_element (const GALGAS_typePostcondition & in_mPostcondition) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typePostconditionList_2D_element init_21_ (const class GALGAS_typePostcondition & inOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typePostconditionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typePostconditionList_2D_element class_func_new (const class GALGAS_typePostcondition & inOperand0,
                                                                               class Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typePostconditionList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeTransitionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_typeTransitionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_typeTransitionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_mTransitionName,
                                                 const class GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                 const class GALGAS_typePostconditionList & in_mPostconditionList,
                                                 const class GALGAS_uint & in_mLowTemporalBound,
                                                 const class GALGAS_uint & in_mHighTemporalBound
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeTransitionList init (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeTransitionList extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeTransitionList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_typeTransitionList class_func_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_typePreconditionExpression & inOperand1,
                                                                           const class GALGAS_typePostconditionList & inOperand2,
                                                                           const class GALGAS_uint & inOperand3,
                                                                           const class GALGAS_uint & inOperand4
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typeTransitionList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_typePreconditionExpression & inOperand1,
                                                     const class GALGAS_typePostconditionList & inOperand2,
                                                     const class GALGAS_uint & inOperand3,
                                                     const class GALGAS_uint & inOperand4
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typeTransitionList add_operation (const GALGAS_typeTransitionList & inOperand,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               class GALGAS_typePreconditionExpression constinArgument1,
                                               class GALGAS_typePostconditionList constinArgument2,
                                               class GALGAS_uint constinArgument3,
                                               class GALGAS_uint constinArgument4,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_typePreconditionExpression constinArgument1,
                                                      class GALGAS_typePostconditionList constinArgument2,
                                                      class GALGAS_uint constinArgument3,
                                                      class GALGAS_uint constinArgument4,
                                                      class GALGAS_uint constinArgument5,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_typePreconditionExpression & outArgument1,
                                                 class GALGAS_typePostconditionList & outArgument2,
                                                 class GALGAS_uint & outArgument3,
                                                 class GALGAS_uint & outArgument4,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                class GALGAS_typePreconditionExpression & outArgument1,
                                                class GALGAS_typePostconditionList & outArgument2,
                                                class GALGAS_uint & outArgument3,
                                                class GALGAS_uint & outArgument4,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_typePreconditionExpression & outArgument1,
                                                      class GALGAS_typePostconditionList & outArgument2,
                                                      class GALGAS_uint & outArgument3,
                                                      class GALGAS_uint & outArgument4,
                                                      class GALGAS_uint constinArgument5,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMHighTemporalBoundAtIndex (class GALGAS_uint constinArgument0,
                                                                     class GALGAS_uint constinArgument1,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMLowTemporalBoundAtIndex (class GALGAS_uint constinArgument0,
                                                                    class GALGAS_uint constinArgument1,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPostconditionListAtIndex (class GALGAS_typePostconditionList constinArgument0,
                                                                     class GALGAS_uint constinArgument1,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPreconditionExpressionAtIndex (class GALGAS_typePreconditionExpression constinArgument0,
                                                                          class GALGAS_uint constinArgument1,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTransitionNameAtIndex (class GALGAS_lstring constinArgument0,
                                                                  class GALGAS_uint constinArgument1,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              class GALGAS_typePreconditionExpression & outArgument1,
                                              class GALGAS_typePostconditionList & outArgument2,
                                              class GALGAS_uint & outArgument3,
                                              class GALGAS_uint & outArgument4,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             class GALGAS_typePreconditionExpression & outArgument1,
                                             class GALGAS_typePostconditionList & outArgument2,
                                             class GALGAS_uint & outArgument3,
                                             class GALGAS_uint & outArgument4,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mHighTemporalBoundAtIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_mLowTemporalBoundAtIndex (const class GALGAS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typePostconditionList getter_mPostconditionListAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mPreconditionExpressionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                                          Compiler * inCompiler
                                                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mTransitionNameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeTransitionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_typeTransitionList_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeTransitionList ;
 
} ; // End of GALGAS_typeTransitionList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeTransitionList : public cGenericAbstractEnumerator {
  public: cEnumerator_typeTransitionList (const GALGAS_typeTransitionList & inEnumeratedObject,
                                          const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_mTransitionName (LOCATION_ARGS) const ;
  public: class GALGAS_typePreconditionExpression current_mPreconditionExpression (LOCATION_ARGS) const ;
  public: class GALGAS_typePostconditionList current_mPostconditionList (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mLowTemporalBound (LOCATION_ARGS) const ;
  public: class GALGAS_uint current_mHighTemporalBound (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typeTransitionList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeTransitionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_mTransitionName ;
  public: inline GALGAS_lstring readProperty_mTransitionName (void) const {
    return mProperty_mTransitionName ;
  }

  public: GALGAS_typePreconditionExpression mProperty_mPreconditionExpression ;
  public: inline GALGAS_typePreconditionExpression readProperty_mPreconditionExpression (void) const {
    return mProperty_mPreconditionExpression ;
  }

  public: GALGAS_typePostconditionList mProperty_mPostconditionList ;
  public: inline GALGAS_typePostconditionList readProperty_mPostconditionList (void) const {
    return mProperty_mPostconditionList ;
  }

  public: GALGAS_uint mProperty_mLowTemporalBound ;
  public: inline GALGAS_uint readProperty_mLowTemporalBound (void) const {
    return mProperty_mLowTemporalBound ;
  }

  public: GALGAS_uint mProperty_mHighTemporalBound ;
  public: inline GALGAS_uint readProperty_mHighTemporalBound (void) const {
    return mProperty_mHighTemporalBound ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typeTransitionList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMTransitionName (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mTransitionName = inValue ;
  }

  public: inline void setter_setMPreconditionExpression (const GALGAS_typePreconditionExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPreconditionExpression = inValue ;
  }

  public: inline void setter_setMPostconditionList (const GALGAS_typePostconditionList & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPostconditionList = inValue ;
  }

  public: inline void setter_setMLowTemporalBound (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mLowTemporalBound = inValue ;
  }

  public: inline void setter_setMHighTemporalBound (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mHighTemporalBound = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_typeTransitionList_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_typeTransitionList_2D_element (const GALGAS_lstring & in_mTransitionName,
                                                const GALGAS_typePreconditionExpression & in_mPreconditionExpression,
                                                const GALGAS_typePostconditionList & in_mPostconditionList,
                                                const GALGAS_uint & in_mLowTemporalBound,
                                                const GALGAS_uint & in_mHighTemporalBound) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeTransitionList_2D_element init_21__21__21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                                                const class GALGAS_typePreconditionExpression & inOperand1,
                                                                                const class GALGAS_typePostconditionList & inOperand2,
                                                                                const class GALGAS_uint & inOperand3,
                                                                                const class GALGAS_uint & inOperand4,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeTransitionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeTransitionList_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                            const class GALGAS_typePreconditionExpression & inOperand1,
                                                                            const class GALGAS_typePostconditionList & inOperand2,
                                                                            const class GALGAS_uint & inOperand3,
                                                                            const class GALGAS_uint & inOperand4,
                                                                            class Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeTransitionList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeInitialMarkingList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_typeInitialMarkingList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_typeInitialMarkingList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_typePostcondition & in_mInitValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeInitialMarkingList init (Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeInitialMarkingList extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeInitialMarkingList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_typeInitialMarkingList class_func_listWithValue (const class GALGAS_typePostcondition & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typeInitialMarkingList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_typePostcondition & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_typeInitialMarkingList add_operation (const GALGAS_typeInitialMarkingList & inOperand,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_typePostcondition constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_typePostcondition & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_typePostcondition & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_typePostcondition & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMInitValueAtIndex (class GALGAS_typePostcondition constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_typePostcondition & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_typePostcondition & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_typePostcondition getter_mInitValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_typeInitialMarkingList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_typeInitialMarkingList_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeInitialMarkingList ;
 
} ; // End of GALGAS_typeInitialMarkingList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeInitialMarkingList : public cGenericAbstractEnumerator {
  public: cEnumerator_typeInitialMarkingList (const GALGAS_typeInitialMarkingList & inEnumeratedObject,
                                              const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_typePostcondition current_mInitValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_typeInitialMarkingList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_typeInitialMarkingList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_typePostcondition mProperty_mInitValue ;
  public: inline GALGAS_typePostcondition readProperty_mInitValue (void) const {
    return mProperty_mInitValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_typeInitialMarkingList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMInitValue (const GALGAS_typePostcondition & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mInitValue = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_typeInitialMarkingList_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_typeInitialMarkingList_2D_element (const GALGAS_typePostcondition & in_mInitValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_typeInitialMarkingList_2D_element init_21_ (const class GALGAS_typePostcondition & inOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_typeInitialMarkingList_2D_element extractObject (const GALGAS_object & inObject,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_typeInitialMarkingList_2D_element class_func_new (const class GALGAS_typePostcondition & inOperand0,
                                                                                class Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_typeInitialMarkingList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @countList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_countList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_countList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_countList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_mName,
                                                 const class GALGAS_typePreconditionExpression & in_mCondition
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_countList init (Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_countList extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_countList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_countList class_func_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                  const class GALGAS_typePreconditionExpression & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_countList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_typePreconditionExpression & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_countList add_operation (const GALGAS_countList & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               class GALGAS_typePreconditionExpression constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_typePreconditionExpression constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_typePreconditionExpression & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                class GALGAS_typePreconditionExpression & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_typePreconditionExpression & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMConditionAtIndex (class GALGAS_typePreconditionExpression constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMNameAtIndex (class GALGAS_lstring constinArgument0,
                                                        class GALGAS_uint constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              class GALGAS_typePreconditionExpression & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             class GALGAS_typePreconditionExpression & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_typePreconditionExpression getter_mConditionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                             Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mNameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_countList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GALGAS_countList_2D_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_countList ;
 
} ; // End of GALGAS_countList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_countList : public cGenericAbstractEnumerator {
  public: cEnumerator_countList (const GALGAS_countList & inEnumeratedObject,
                                 const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_mName (LOCATION_ARGS) const ;
  public: class GALGAS_typePreconditionExpression current_mCondition (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_countList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @countList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_countList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_mName ;
  public: inline GALGAS_lstring readProperty_mName (void) const {
    return mProperty_mName ;
  }

  public: GALGAS_typePreconditionExpression mProperty_mCondition ;
  public: inline GALGAS_typePreconditionExpression readProperty_mCondition (void) const {
    return mProperty_mCondition ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_countList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMName (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mName = inValue ;
  }

  public: inline void setter_setMCondition (const GALGAS_typePreconditionExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mCondition = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GALGAS_countList_2D_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GALGAS_countList_2D_element (const GALGAS_lstring & in_mName,
                                       const GALGAS_typePreconditionExpression & in_mCondition) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GALGAS_countList_2D_element init_21__21_ (const class GALGAS_lstring & inOperand0,
                                                           const class GALGAS_typePreconditionExpression & inOperand1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_countList_2D_element extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_countList_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_typePreconditionExpression & inOperand1,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_countList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'spec_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_spec_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_spec_5F_parser (void) { }

//--- Non terminal declarations
  protected: virtual void nt_axiome_ (class GALGAS_uint & outArgument0,
                                      class GALGAS_uint & outArgument1,
                                      class GALGAS_typeVarMap & outArgument2,
                                      class GALGAS_typeTransitionList & outArgument3,
                                      class GALGAS_typeInitialMarkingList & outArgument4,
                                      class GALGAS_countList & outArgument5,
                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_ (class GALGAS_typeVarMap & ioArgument0,
                                      class GALGAS_typeCstMap & ioArgument1,
                                      class GALGAS_typePreconditionExpression & outArgument2,
                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_ (class GALGAS_uint & outArgument0,
                                              class GALGAS_uint & outArgument1,
                                              class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_ (class GALGAS_typeCstMap & ioArgument0,
                                                 class GALGAS_bool & outArgument1,
                                                 class GALGAS_luint & outArgument2,
                                                 class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_ (class GALGAS_typeVarMap & ioArgument0,
                                                      class GALGAS_typeCstMap & ioArgument1,
                                                      class GALGAS_typePostconditionList & outArgument2,
                                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_ (class GALGAS_typeVarMap & ioArgument0,
                                                     class GALGAS_typeCstMap & ioArgument1,
                                                     class GALGAS_typePreconditionExpression & outArgument2,
                                                     class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_ (class GALGAS_typeVarMap & ioArgument0,
                                       class GALGAS_typeCstMap & ioArgument1,
                                       class GALGAS_typePreconditionExpression & outArgument2,
                                       class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_ (class GALGAS_typeVarMap & ioArgument0,
                                    class GALGAS_typeCstMap & ioArgument1,
                                    class GALGAS_typePreconditionExpression & outArgument2,
                                    class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_ (GALGAS_typeVarMap & ioArgument0,
                                                                 GALGAS_typeCstMap & ioArgument1,
                                                                 GALGAS_typePreconditionExpression & outArgument2,
                                                                 Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_ (GALGAS_typeVarMap & ioArgument0,
                                                GALGAS_typeCstMap & ioArgument1,
                                                GALGAS_typePreconditionExpression & outArgument2,
                                                Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_ (GALGAS_typeVarMap & ioArgument0,
                                                  GALGAS_typeCstMap & ioArgument1,
                                                  GALGAS_typePreconditionExpression & outArgument2,
                                                  Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_ (GALGAS_typeVarMap & ioArgument0,
                                                   GALGAS_typeCstMap & ioArgument1,
                                                   GALGAS_typePreconditionExpression & outArgument2,
                                                   Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_ (GALGAS_typeCstMap & ioArgument0,
                                                             GALGAS_bool & outArgument1,
                                                             GALGAS_luint & outArgument2,
                                                             Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_ (GALGAS_typeVarMap & ioArgument0,
                                                                  GALGAS_typeCstMap & ioArgument1,
                                                                  GALGAS_typePostconditionList & outArgument2,
                                                                  Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_ (GALGAS_uint & outArgument0,
                                                          GALGAS_uint & outArgument1,
                                                          Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_ (GALGAS_uint & outArgument0,
                                                          GALGAS_uint & outArgument1,
                                                          Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_axiome_i8_ (GALGAS_uint & outArgument0,
                                                  GALGAS_uint & outArgument1,
                                                  GALGAS_typeVarMap & outArgument2,
                                                  GALGAS_typeTransitionList & outArgument3,
                                                  GALGAS_typeInitialMarkingList & outArgument4,
                                                  GALGAS_countList & outArgument5,
                                                  Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_axiome_i8_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_axiome_i8_indexing (Lexique_spec_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_spec_5F_parser_0 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_1 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_2 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_3 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_4 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_5 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_6 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_7 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_8 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_9 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_10 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_11 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_12 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_13 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_14 (Lexique_spec_5F_scanner *) = 0 ;

  protected: virtual int32_t select_spec_5F_parser_15 (Lexique_spec_5F_scanner *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR spec_grammar
//--------------------------------------------------------------------------------------------------

class cGrammar_spec_5F_grammar : public cParser_spec_5F_parser {
//------------------------------------- 'axiome' non terminal
//--- 'parse' label
  public: virtual void nt_axiome_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_axiome_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_axiome_ (GALGAS_uint & outArgument0,
                                   GALGAS_uint & outArgument1,
                                   GALGAS_typeVarMap & outArgument2,
                                   GALGAS_typeTransitionList & outArgument3,
                                   GALGAS_typeInitialMarkingList & outArgument4,
                                   GALGAS_countList & outArgument5,
                                   Lexique_spec_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_uint & outArgument0,
                                                  GALGAS_uint & outArgument1,
                                                  GALGAS_typeVarMap & outArgument2,
                                                  GALGAS_typeTransitionList & outArgument3,
                                                  GALGAS_typeInitialMarkingList & outArgument4,
                                                  GALGAS_countList & outArgument5
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
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
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'factor' non terminal
//--- 'parse' label
  public: virtual void nt_factor_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_factor_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_factor_ (GALGAS_typeVarMap & ioArgument0,
                                   GALGAS_typeCstMap & ioArgument1,
                                   GALGAS_typePreconditionExpression & outArgument2,
                                   Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_bound' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_bound_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_bound_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_bound_ (GALGAS_uint & outArgument0,
                                           GALGAS_uint & outArgument1,
                                           Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_constant' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_constant_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_constant_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_constant_ (GALGAS_typeCstMap & ioArgument0,
                                              GALGAS_bool & outArgument1,
                                              GALGAS_luint & outArgument2,
                                              Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_postcondition' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_postcondition_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_postcondition_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_postcondition_ (GALGAS_typeVarMap & ioArgument0,
                                                   GALGAS_typeCstMap & ioArgument1,
                                                   GALGAS_typePostconditionList & outArgument2,
                                                   Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_precondition' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_precondition_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_precondition_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_precondition_ (GALGAS_typeVarMap & ioArgument0,
                                                  GALGAS_typeCstMap & ioArgument1,
                                                  GALGAS_typePreconditionExpression & outArgument2,
                                                  Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'primary' non terminal
//--- 'parse' label
  public: virtual void nt_primary_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_primary_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_primary_ (GALGAS_typeVarMap & ioArgument0,
                                    GALGAS_typeCstMap & ioArgument1,
                                    GALGAS_typePreconditionExpression & outArgument2,
                                    Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'term' non terminal
//--- 'parse' label
  public: virtual void nt_term_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_term_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_term_ (GALGAS_typeVarMap & ioArgument0,
                                 GALGAS_typeCstMap & ioArgument1,
                                 GALGAS_typePreconditionExpression & outArgument2,
                                 Lexique_spec_5F_scanner * inCompiler) ;

  public: virtual int32_t select_spec_5F_parser_0 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_1 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_2 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_3 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_4 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_5 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_6 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_7 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_8 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_9 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_10 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_11 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_12 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_13 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_14 (Lexique_spec_5F_scanner *) ;

  public: virtual int32_t select_spec_5F_parser_15 (Lexique_spec_5F_scanner *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Routine 'println?'
//
//--------------------------------------------------------------------------------------------------

void routine_println_3F_ (const class GALGAS_string constinArgument0,
                          class Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'print?'
//
//--------------------------------------------------------------------------------------------------

void routine_print_3F_ (const class GALGAS_string constinArgument0,
                        class Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;


//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

extern BoolCommandLineOption gOption_spec_5F_options_doNotPrintIteration ;

extern BoolCommandLineOption gOption_spec_5F_options_computeSimultaneousFiring ;

extern BoolCommandLineOption gOption_spec_5F_options_printNodes ;

extern BoolCommandLineOption gOption_spec_5F_options_printStates ;

extern BoolCommandLineOption gOption_spec_5F_options_printInference ;

extern BoolCommandLineOption gOption_spec_5F_options_printMinMax ;

extern BoolCommandLineOption gOption_spec_5F_options_printPreConditions ;

extern BoolCommandLineOption gOption_spec_5F_options_printIterationStates ;

extern BoolCommandLineOption gOption_spec_5F_options_printTemporalBounds ;

extern BoolCommandLineOption gOption_spec_5F_options_printFiring ;

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

extern UIntCommandLineOption gOption_spec_5F_options_stopAfterIteration ;

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

//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_code??????'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_code_3F__3F__3F__3F__3F__3F_ (const class GALGAS_uint constinArgument0,
                                                       const class GALGAS_uint constinArgument1,
                                                       const class GALGAS_typeVarMap constinArgument2,
                                                       const class GALGAS_typeTransitionList constinArgument3,
                                                       const class GALGAS_typeInitialMarkingList constinArgument4,
                                                       const class GALGAS_countList constinArgument5,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

