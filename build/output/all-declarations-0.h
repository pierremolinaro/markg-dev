#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
// Phase 1: @2lstringlist list
//
//--------------------------------------------------------------------------------------------------

class GGS__32_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS__32_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS__32_lstringlist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_lstring & in_mValue_30_,
                                                 const class GGS_lstring & in_mValue_31_
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS__32_lstringlist init (Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS__32_lstringlist extractObject (const GGS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS__32_lstringlist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS__32_lstringlist class_func_listWithValue (const class GGS_lstring & inOperand0,
                                                                     const class GGS_lstring & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS__32_lstringlist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_lstring & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS__32_lstringlist add_operation (const GGS__32_lstringlist & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_lstring constinArgument0,
                                               class GGS_lstring constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_lstring constinArgument0,
                                                      class GGS_lstring constinArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_lstring & outArgument0,
                                                 class GGS_lstring & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_lstring & outArgument0,
                                                class GGS_lstring & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_lstring & outArgument0,
                                                      class GGS_lstring & outArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GGS_lstring constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GGS_lstring constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_lstring & outArgument0,
                                              class GGS_lstring & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_lstring & outArgument0,
                                             class GGS_lstring & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mValue_30_AtIndex (const class GGS_uint & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mValue_31_AtIndex (const class GGS_uint & constinOperand0,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS__32_lstringlist getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS__32_lstringlist_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator__32_lstringlist ;
 
} ; // End of GGS__32_lstringlist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator__32_lstringlist : public cGenericAbstractEnumerator {
  public: cEnumerator__32_lstringlist (const GGS__32_lstringlist & inEnumeratedObject,
                                       const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_mValue_30_ (LOCATION_ARGS) const ;
  public: class GGS_lstring current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS__32_lstringlist_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @_32_lstringlist_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS__32_lstringlist_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_mValue_30_ ;
  public: inline GGS_lstring readProperty_mValue_30_ (void) const {
    return mProperty_mValue_30_ ;
  }

  public: GGS_lstring mProperty_mValue_31_ ;
  public: inline GGS_lstring readProperty_mValue_31_ (void) const {
    return mProperty_mValue_31_ ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS__32_lstringlist_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMValue_30_ (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_30_ = inValue ;
  }

  public: inline void setter_setMValue_31_ (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue_31_ = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS__32_lstringlist_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS__32_lstringlist_2E_element (const GGS_lstring & in_mValue_30_,
                                          const GGS_lstring & in_mValue_31_) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS__32_lstringlist_2E_element init_21__21_ (const class GGS_lstring & inOperand0,
                                                              const class GGS_lstring & inOperand1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS__32_lstringlist_2E_element extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS__32_lstringlist_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                      const class GGS_lstring & inOperand1,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS__32_lstringlist_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist_2E_element ;

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
  public: static GGS_stringlist symbols (LOCATION_ARGS) ;

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
  public: GGS_lstring synthetizedAttribute_theString (void) const ;
  public: GGS_luint synthetizedAttribute_ulongValue (void) const ;


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

class GGS_typeVarMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_typeVarMap (void) ;

//--------------------------------- Handle copy
  public: GGS_typeVarMap (const GGS_typeVarMap & inSource) ;
  public: GGS_typeVarMap & operator = (const GGS_typeVarMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeVarMap init (Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeVarMap extractObject (const GGS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeVarMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_typeVarMap class_func_mapWithMapToOverride (const class GGS_typeVarMap & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_typeVarMap add_operation (const GGS_typeVarMap & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint constinArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMIndexForKey (class GGS_uint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_uint & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mIndexForKey (const class GGS_string & constinOperand0,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeVarMap getter_overriddenMap (Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_typeVarMap_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_typeVarMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GGS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_typeVarMap_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeVarMap ;
 
} ; // End of GGS_typeVarMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeVarMap : public cGenericAbstractEnumerator {
  public: cEnumerator_typeVarMap (const GGS_typeVarMap & inEnumeratedObject,
                                  const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_uint current_mIndex (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_typeVarMap_2E_element current (LOCATION_ARGS) const ;
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
  public: GGS_uint mProperty_mIndex ;

//--- Constructors
  public: cMapElement_typeVarMap (const GGS_typeVarMap_2E_element & inValue
                                  COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_typeVarMap (const GGS_lstring & inKey,
                                  const GGS_uint & in_mIndex
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
// Phase 1: @typeVarMap_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_typeVarMap_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_uint mProperty_mIndex ;
  public: inline GGS_uint readProperty_mIndex (void) const {
    return mProperty_mIndex ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_typeVarMap_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMIndex (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mIndex = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_typeVarMap_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_typeVarMap_2E_element (const GGS_lstring & in_lkey,
                                     const GGS_uint & in_mIndex) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeVarMap_2E_element init_21__21_ (const class GGS_lstring & inOperand0,
                                                         const class GGS_uint & inOperand1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeVarMap_2E_element extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeVarMap_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                 const class GGS_uint & inOperand1,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeVarMap_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: typeVarMap.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_typeVarMap_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_typeVarMap_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_typeVarMap_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_typeVarMap_2E_element_3F_ (const GGS_typeVarMap_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_typeVarMap_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_typeVarMap_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeVarMap_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeVarMap_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeVarMap_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeCstMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_typeCstMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_typeCstMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GGS_typeCstMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GGS_typeCstMap (void) ;

//--------------------------------- Handle copy
  public: GGS_typeCstMap (const GGS_typeCstMap & inSource) ;
  public: GGS_typeCstMap & operator = (const GGS_typeCstMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeCstMap init (Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeCstMap extractObject (const GGS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeCstMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GGS_typeCstMap class_func_mapWithMapToOverride (const class GGS_typeCstMap & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_bool & inOperand1,
                                                     const class GGS_luint & inOperand2,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_typeCstMap add_operation (const GGS_typeCstMap & inOperand,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GGS_lstring constinArgument0,
                                                  class GGS_bool constinArgument1,
                                                  class GGS_luint constinArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMSignForKey (class GGS_bool constinArgument0,
                                                       class GGS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMValueForKey (class GGS_luint constinArgument0,
                                                        class GGS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GGS_lstring constinArgument0,
                                                  class GGS_bool & outArgument1,
                                                  class GGS_luint & outArgument2,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_bool getter_mSignForKey (const class GGS_string & constinOperand0,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_luint getter_mValueForKey (const class GGS_string & constinOperand0,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeCstMap getter_overriddenMap (Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts
  public: VIRTUAL_IN_DEBUG class GGS_typeCstMap_2E_element_3F_ readSubscript__3F_ (const class GGS_string & in0,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_typeCstMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GGS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;


//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_typeCstMap_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeCstMap ;
 
} ; // End of GGS_typeCstMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeCstMap : public cGenericAbstractEnumerator {
  public: cEnumerator_typeCstMap (const GGS_typeCstMap & inEnumeratedObject,
                                  const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GGS_bool current_mSign (LOCATION_ARGS) const ;
  public: class GGS_luint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_typeCstMap_2E_element current (LOCATION_ARGS) const ;
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
  public: GGS_bool mProperty_mSign ;
  public: GGS_luint mProperty_mValue ;

//--- Constructors
  public: cMapElement_typeCstMap (const GGS_typeCstMap_2E_element & inValue
                                  COMMA_LOCATION_ARGS) ;
 
  public: cMapElement_typeCstMap (const GGS_lstring & inKey,
                                  const GGS_bool & in_mSign,
                                  const GGS_luint & in_mValue
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
// Phase 1: @typeCstMap_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_typeCstMap_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_lkey ;
  public: inline GGS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GGS_bool mProperty_mSign ;
  public: inline GGS_bool readProperty_mSign (void) const {
    return mProperty_mSign ;
  }

  public: GGS_luint mProperty_mValue ;
  public: inline GGS_luint readProperty_mValue (void) const {
    return mProperty_mValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_typeCstMap_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMSign (const GGS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mSign = inValue ;
  }

  public: inline void setter_setMValue (const GGS_luint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mValue = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_typeCstMap_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_typeCstMap_2E_element (const GGS_lstring & in_lkey,
                                     const GGS_bool & in_mSign,
                                     const GGS_luint & in_mValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeCstMap_2E_element init_21__21__21_ (const class GGS_lstring & inOperand0,
                                                             const class GGS_bool & inOperand1,
                                                             const class GGS_luint & inOperand2,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeCstMap_2E_element extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeCstMap_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                 const class GGS_bool & inOperand1,
                                                                 const class GGS_luint & inOperand2,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeCstMap_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: typeCstMap.element? optional
//
//--------------------------------------------------------------------------------------------------

class GGS_typeCstMap_2E_element_3F_ : public AC_GALGAS_root {
//--------------------------------- Private property
  private: GGS_typeCstMap_2E_element mValue ;
  private: OptionalState mState ;

//--------------------------------- Default constructor
  public: GGS_typeCstMap_2E_element_3F_ (void) ;

//--------------------------------- Constructor from unwrapped type
  public: GGS_typeCstMap_2E_element_3F_ (const GGS_typeCstMap_2E_element & inSource) ;

//--------------------------------- Constructor from weak type

//--------------------------------- nil initializer
  public: static GGS_typeCstMap_2E_element_3F_ init_nil (void) ;

  public: inline bool isNil (void) const { return mState == OptionalState::isNil ; }

  public: bool isValuated (void) const ;
  public: inline GGS_typeCstMap_2E_element unwrappedValue (void) const {
    return mValue ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::isNil) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (mState != OptionalState::invalid, mState == OptionalState::valuated) ;
  }

  
//--- Methods that every type should implement
  public: virtual bool isValid (void) const override ;
  
  public: virtual void drop (void) override ;

  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeCstMap_2E_element_3F_ extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeCstMap_2E_element_3F_ class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeCstMap_2E_element_3F_ ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePreconditionExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePreconditionExpression : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GGS_typePreconditionExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typePreconditionExpression (const class cPtr_typePreconditionExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePreconditionExpression init (Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePreconditionExpression extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePreconditionExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePreconditionExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression ;

#include "separateHeaderFor_typePreconditionExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePreconditionExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePreconditionExpression_2E_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GGS_typePreconditionExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typePreconditionExpression_2E_weak (const class GGS_typePreconditionExpression & inSource) ;

  public: GGS_typePreconditionExpression_2E_weak & operator = (const class GGS_typePreconditionExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typePreconditionExpression_2E_weak init_nil (void) {
    GGS_typePreconditionExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typePreconditionExpression bang_typePreconditionExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typePreconditionExpression unwrappedValue (void) const {
    GGS_typePreconditionExpression result ;
    if (isValid ()) {
      const cPtr_typePreconditionExpression * p = (cPtr_typePreconditionExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typePreconditionExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePreconditionExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePreconditionExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePreconditionExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePreconditionExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePreconditionExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTrueExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeTrueExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeTrueExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeTrueExpression (const class cPtr_typeTrueExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeTrueExpression init (Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeTrueExpression extractObject (const GGS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeTrueExpression class_func_new (Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeTrueExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeTrueExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression ;

#include "separateHeaderFor_typeTrueExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTrueExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeTrueExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeTrueExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeTrueExpression_2E_weak (const class GGS_typeTrueExpression & inSource) ;

  public: GGS_typeTrueExpression_2E_weak & operator = (const class GGS_typeTrueExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeTrueExpression_2E_weak init_nil (void) {
    GGS_typeTrueExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeTrueExpression bang_typeTrueExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeTrueExpression unwrappedValue (void) const {
    GGS_typeTrueExpression result ;
    if (isValid ()) {
      const cPtr_typeTrueExpression * p = (cPtr_typeTrueExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeTrueExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeTrueExpression_2E_weak extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeTrueExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeTrueExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeTrueExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTrueExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeFalseExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeFalseExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeFalseExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeFalseExpression (const class cPtr_typeFalseExpression * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeFalseExpression init (Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeFalseExpression extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeFalseExpression class_func_new (Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeFalseExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeFalseExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression ;

#include "separateHeaderFor_typeFalseExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeFalseExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeFalseExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeFalseExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeFalseExpression_2E_weak (const class GGS_typeFalseExpression & inSource) ;

  public: GGS_typeFalseExpression_2E_weak & operator = (const class GGS_typeFalseExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeFalseExpression_2E_weak init_nil (void) {
    GGS_typeFalseExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeFalseExpression bang_typeFalseExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeFalseExpression unwrappedValue (void) const {
    GGS_typeFalseExpression result ;
    if (isValid ()) {
      const cPtr_typeFalseExpression * p = (cPtr_typeFalseExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeFalseExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeFalseExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeFalseExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeFalseExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeFalseExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeFalseExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeComplementExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeComplementExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeComplementExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeComplementExpression (const class cPtr_typeComplementExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_typePreconditionExpression readProperty_mExpression (void) const ;
  public: void setProperty_mExpression (const GGS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeComplementExpression init_21_ (const class GGS_typePreconditionExpression & inOperand0,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeComplementExpression extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeComplementExpression class_func_new (const class GGS_typePreconditionExpression & inOperand0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeComplementExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeComplementExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression ;

#include "separateHeaderFor_typeComplementExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeComplementExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeComplementExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeComplementExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeComplementExpression_2E_weak (const class GGS_typeComplementExpression & inSource) ;

  public: GGS_typeComplementExpression_2E_weak & operator = (const class GGS_typeComplementExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeComplementExpression_2E_weak init_nil (void) {
    GGS_typeComplementExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeComplementExpression bang_typeComplementExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeComplementExpression unwrappedValue (void) const {
    GGS_typeComplementExpression result ;
    if (isValid ()) {
      const cPtr_typeComplementExpression * p = (cPtr_typeComplementExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeComplementExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeComplementExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeComplementExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeComplementExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeComplementExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeComplementExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAndExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAndExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeAndExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeAndExpression (const class cPtr_typeAndExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_typePreconditionExpression readProperty_mLeftExpression (void) const ;
  public: void setProperty_mLeftExpression (const GGS_typePreconditionExpression & inValue) ;

  public: class GGS_typePreconditionExpression readProperty_mRightExpression (void) const ;
  public: void setProperty_mRightExpression (const GGS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeAndExpression init_21__21_ (const class GGS_typePreconditionExpression & inOperand0,
                                                     const class GGS_typePreconditionExpression & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAndExpression extractObject (const GGS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAndExpression class_func_new (const class GGS_typePreconditionExpression & inOperand0,
                                                             const class GGS_typePreconditionExpression & inOperand1,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAndExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAndExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression ;

#include "separateHeaderFor_typeAndExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAndExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAndExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeAndExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeAndExpression_2E_weak (const class GGS_typeAndExpression & inSource) ;

  public: GGS_typeAndExpression_2E_weak & operator = (const class GGS_typeAndExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeAndExpression_2E_weak init_nil (void) {
    GGS_typeAndExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeAndExpression bang_typeAndExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeAndExpression unwrappedValue (void) const {
    GGS_typeAndExpression result ;
    if (isValid ()) {
      const cPtr_typeAndExpression * p = (cPtr_typeAndExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeAndExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAndExpression_2E_weak extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAndExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAndExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAndExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAndExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeOrExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeOrExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeOrExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeOrExpression (const class cPtr_typeOrExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_typePreconditionExpression readProperty_mLeftExpression (void) const ;
  public: void setProperty_mLeftExpression (const GGS_typePreconditionExpression & inValue) ;

  public: class GGS_typePreconditionExpression readProperty_mRightExpression (void) const ;
  public: void setProperty_mRightExpression (const GGS_typePreconditionExpression & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeOrExpression init_21__21_ (const class GGS_typePreconditionExpression & inOperand0,
                                                    const class GGS_typePreconditionExpression & inOperand1,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeOrExpression extractObject (const GGS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeOrExpression class_func_new (const class GGS_typePreconditionExpression & inOperand0,
                                                            const class GGS_typePreconditionExpression & inOperand1,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeOrExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeOrExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression ;

#include "separateHeaderFor_typeOrExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeOrExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeOrExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeOrExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeOrExpression_2E_weak (const class GGS_typeOrExpression & inSource) ;

  public: GGS_typeOrExpression_2E_weak & operator = (const class GGS_typeOrExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeOrExpression_2E_weak init_nil (void) {
    GGS_typeOrExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeOrExpression bang_typeOrExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeOrExpression unwrappedValue (void) const {
    GGS_typeOrExpression result ;
    if (isValid ()) {
      const cPtr_typeOrExpression * p = (cPtr_typeOrExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeOrExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeOrExpression_2E_weak extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeOrExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeOrExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeOrExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeOrExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeEqualExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeEqualExpression (const class cPtr_typeEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeEqualExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                           const class GGS_bool & inOperand1,
                                                           const class GGS_luint & inOperand2,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeEqualExpression extractObject (const GGS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeEqualExpression class_func_new (const class GGS_uint & inOperand0,
                                                               const class GGS_bool & inOperand1,
                                                               const class GGS_luint & inOperand2,
                                                               class Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression ;

#include "separateHeaderFor_typeEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeEqualExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeEqualExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeEqualExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeEqualExpression_2E_weak (const class GGS_typeEqualExpression & inSource) ;

  public: GGS_typeEqualExpression_2E_weak & operator = (const class GGS_typeEqualExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeEqualExpression_2E_weak init_nil (void) {
    GGS_typeEqualExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeEqualExpression bang_typeEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeEqualExpression unwrappedValue (void) const {
    GGS_typeEqualExpression result ;
    if (isValid ()) {
      const cPtr_typeEqualExpression * p = (cPtr_typeEqualExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeEqualExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeEqualExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeEqualExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeEqualExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeEqualExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeEqualExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeNonEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeNonEqualExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeNonEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeNonEqualExpression (const class cPtr_typeNonEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeNonEqualExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                              const class GGS_bool & inOperand1,
                                                              const class GGS_luint & inOperand2,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeNonEqualExpression extractObject (const GGS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeNonEqualExpression class_func_new (const class GGS_uint & inOperand0,
                                                                  const class GGS_bool & inOperand1,
                                                                  const class GGS_luint & inOperand2,
                                                                  class Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeNonEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeNonEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression ;

#include "separateHeaderFor_typeNonEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeNonEqualExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeNonEqualExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeNonEqualExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeNonEqualExpression_2E_weak (const class GGS_typeNonEqualExpression & inSource) ;

  public: GGS_typeNonEqualExpression_2E_weak & operator = (const class GGS_typeNonEqualExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeNonEqualExpression_2E_weak init_nil (void) {
    GGS_typeNonEqualExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeNonEqualExpression bang_typeNonEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeNonEqualExpression unwrappedValue (void) const {
    GGS_typeNonEqualExpression result ;
    if (isValid ()) {
      const cPtr_typeNonEqualExpression * p = (cPtr_typeNonEqualExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeNonEqualExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeNonEqualExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeNonEqualExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeNonEqualExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeNonEqualExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeNonEqualExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInfOrEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeInfOrEqualExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeInfOrEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeInfOrEqualExpression (const class cPtr_typeInfOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeInfOrEqualExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                                const class GGS_bool & inOperand1,
                                                                const class GGS_luint & inOperand2,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeInfOrEqualExpression extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeInfOrEqualExpression class_func_new (const class GGS_uint & inOperand0,
                                                                    const class GGS_bool & inOperand1,
                                                                    const class GGS_luint & inOperand2,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeInfOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeInfOrEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression ;

#include "separateHeaderFor_typeInfOrEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInfOrEqualExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeInfOrEqualExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeInfOrEqualExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeInfOrEqualExpression_2E_weak (const class GGS_typeInfOrEqualExpression & inSource) ;

  public: GGS_typeInfOrEqualExpression_2E_weak & operator = (const class GGS_typeInfOrEqualExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeInfOrEqualExpression_2E_weak init_nil (void) {
    GGS_typeInfOrEqualExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeInfOrEqualExpression bang_typeInfOrEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeInfOrEqualExpression unwrappedValue (void) const {
    GGS_typeInfOrEqualExpression result ;
    if (isValid ()) {
      const cPtr_typeInfOrEqualExpression * p = (cPtr_typeInfOrEqualExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeInfOrEqualExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeInfOrEqualExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeInfOrEqualExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeInfOrEqualExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeInfOrEqualExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInfOrEqualExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSupOrEqualExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeSupOrEqualExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeSupOrEqualExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeSupOrEqualExpression (const class cPtr_typeSupOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeSupOrEqualExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                                const class GGS_bool & inOperand1,
                                                                const class GGS_luint & inOperand2,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeSupOrEqualExpression extractObject (const GGS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeSupOrEqualExpression class_func_new (const class GGS_uint & inOperand0,
                                                                    const class GGS_bool & inOperand1,
                                                                    const class GGS_luint & inOperand2,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeSupOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeSupOrEqualExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression ;

#include "separateHeaderFor_typeSupOrEqualExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSupOrEqualExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeSupOrEqualExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeSupOrEqualExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeSupOrEqualExpression_2E_weak (const class GGS_typeSupOrEqualExpression & inSource) ;

  public: GGS_typeSupOrEqualExpression_2E_weak & operator = (const class GGS_typeSupOrEqualExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeSupOrEqualExpression_2E_weak init_nil (void) {
    GGS_typeSupOrEqualExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeSupOrEqualExpression bang_typeSupOrEqualExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeSupOrEqualExpression unwrappedValue (void) const {
    GGS_typeSupOrEqualExpression result ;
    if (isValid ()) {
      const cPtr_typeSupOrEqualExpression * p = (cPtr_typeSupOrEqualExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeSupOrEqualExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeSupOrEqualExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeSupOrEqualExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeSupOrEqualExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeSupOrEqualExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSupOrEqualExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictInfExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeStrictInfExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeStrictInfExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeStrictInfExpression (const class cPtr_typeStrictInfExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeStrictInfExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                               const class GGS_bool & inOperand1,
                                                               const class GGS_luint & inOperand2,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeStrictInfExpression extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeStrictInfExpression class_func_new (const class GGS_uint & inOperand0,
                                                                   const class GGS_bool & inOperand1,
                                                                   const class GGS_luint & inOperand2,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeStrictInfExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeStrictInfExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression ;

#include "separateHeaderFor_typeStrictInfExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictInfExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeStrictInfExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeStrictInfExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeStrictInfExpression_2E_weak (const class GGS_typeStrictInfExpression & inSource) ;

  public: GGS_typeStrictInfExpression_2E_weak & operator = (const class GGS_typeStrictInfExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeStrictInfExpression_2E_weak init_nil (void) {
    GGS_typeStrictInfExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeStrictInfExpression bang_typeStrictInfExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeStrictInfExpression unwrappedValue (void) const {
    GGS_typeStrictInfExpression result ;
    if (isValid ()) {
      const cPtr_typeStrictInfExpression * p = (cPtr_typeStrictInfExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeStrictInfExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeStrictInfExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeStrictInfExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeStrictInfExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeStrictInfExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictInfExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictSupExpression reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeStrictSupExpression : public GGS_typePreconditionExpression {
//--------------------------------- Default constructor
  public: GGS_typeStrictSupExpression (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeStrictSupExpression (const class cPtr_typeStrictSupExpression * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeStrictSupExpression init_21__21__21_ (const class GGS_uint & inOperand0,
                                                               const class GGS_bool & inOperand1,
                                                               const class GGS_luint & inOperand2,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeStrictSupExpression extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeStrictSupExpression class_func_new (const class GGS_uint & inOperand0,
                                                                   const class GGS_bool & inOperand1,
                                                                   const class GGS_luint & inOperand2,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeStrictSupExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeStrictSupExpression class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression ;

#include "separateHeaderFor_typeStrictSupExpression.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeStrictSupExpression_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeStrictSupExpression_2E_weak : public GGS_typePreconditionExpression_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeStrictSupExpression_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeStrictSupExpression_2E_weak (const class GGS_typeStrictSupExpression & inSource) ;

  public: GGS_typeStrictSupExpression_2E_weak & operator = (const class GGS_typeStrictSupExpression & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeStrictSupExpression_2E_weak init_nil (void) {
    GGS_typeStrictSupExpression_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeStrictSupExpression bang_typeStrictSupExpression_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeStrictSupExpression unwrappedValue (void) const {
    GGS_typeStrictSupExpression result ;
    if (isValid ()) {
      const cPtr_typeStrictSupExpression * p = (cPtr_typeStrictSupExpression *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeStrictSupExpression (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeStrictSupExpression_2E_weak extractObject (const GGS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeStrictSupExpression_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeStrictSupExpression_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeStrictSupExpression_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeStrictSupExpression_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostcondition reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostcondition : public AC_GALGAS_reference_class {
//--------------------------------- Default constructor
  public: GGS_typePostcondition (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typePostcondition (const class cPtr_typePostcondition * inSourcePtr) ;

//--------------------------------- Property access
//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePostcondition init (Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostcondition extractObject (const GGS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostcondition & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostcondition class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition ;

#include "separateHeaderFor_typePostcondition.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostcondition_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostcondition_2E_weak : public AC_GALGAS_weak_reference {
//--------------------------------- Default constructor
  public: GGS_typePostcondition_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typePostcondition_2E_weak (const class GGS_typePostcondition & inSource) ;

  public: GGS_typePostcondition_2E_weak & operator = (const class GGS_typePostcondition & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typePostcondition_2E_weak init_nil (void) {
    GGS_typePostcondition_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typePostcondition bang_typePostcondition_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typePostcondition unwrappedValue (void) const {
    GGS_typePostcondition result ;
    if (isValid ()) {
      const cPtr_typePostcondition * p = (cPtr_typePostcondition *) ptr () ;
      if (nullptr != p) {
        result = GGS_typePostcondition (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostcondition_2E_weak extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostcondition_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostcondition_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostcondition_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostcondition_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostIncrement reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostIncrement : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typePostIncrement (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typePostIncrement (const class cPtr_typePostIncrement * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePostIncrement init_21__21_ (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostIncrement extractObject (const GGS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostIncrement class_func_new (const class GGS_lstring & inOperand0,
                                                             const class GGS_uint & inOperand1,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostIncrement & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostIncrement class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement ;

#include "separateHeaderFor_typePostIncrement.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostIncrement_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostIncrement_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typePostIncrement_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typePostIncrement_2E_weak (const class GGS_typePostIncrement & inSource) ;

  public: GGS_typePostIncrement_2E_weak & operator = (const class GGS_typePostIncrement & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typePostIncrement_2E_weak init_nil (void) {
    GGS_typePostIncrement_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typePostIncrement bang_typePostIncrement_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typePostIncrement unwrappedValue (void) const {
    GGS_typePostIncrement result ;
    if (isValid ()) {
      const cPtr_typePostIncrement * p = (cPtr_typePostIncrement *) ptr () ;
      if (nullptr != p) {
        result = GGS_typePostIncrement (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostIncrement_2E_weak extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostIncrement_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostIncrement_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostIncrement_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostIncrement_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostDecrement reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostDecrement : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typePostDecrement (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typePostDecrement (const class cPtr_typePostDecrement * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePostDecrement init_21__21_ (const class GGS_lstring & inOperand0,
                                                     const class GGS_uint & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostDecrement extractObject (const GGS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostDecrement class_func_new (const class GGS_lstring & inOperand0,
                                                             const class GGS_uint & inOperand1,
                                                             class Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostDecrement & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostDecrement class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement ;

#include "separateHeaderFor_typePostDecrement.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostDecrement_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostDecrement_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typePostDecrement_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typePostDecrement_2E_weak (const class GGS_typePostDecrement & inSource) ;

  public: GGS_typePostDecrement_2E_weak & operator = (const class GGS_typePostDecrement & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typePostDecrement_2E_weak init_nil (void) {
    GGS_typePostDecrement_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typePostDecrement bang_typePostDecrement_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typePostDecrement unwrappedValue (void) const {
    GGS_typePostDecrement result ;
    if (isValid ()) {
      const cPtr_typePostDecrement * p = (cPtr_typePostDecrement *) ptr () ;
      if (nullptr != p) {
        result = GGS_typePostDecrement (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostDecrement_2E_weak extractObject (const GGS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostDecrement_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typePostDecrement_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostDecrement_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostDecrement_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAddConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAddConstant : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typeAddConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeAddConstant (const class cPtr_typeAddConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeAddConstant init_21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                           const class GGS_uint & inOperand1,
                                                           const class GGS_bool & inOperand2,
                                                           const class GGS_luint & inOperand3,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAddConstant extractObject (const GGS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAddConstant class_func_new (const class GGS_lstring & inOperand0,
                                                           const class GGS_uint & inOperand1,
                                                           const class GGS_bool & inOperand2,
                                                           const class GGS_luint & inOperand3,
                                                           class Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAddConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAddConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant ;

#include "separateHeaderFor_typeAddConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAddConstant_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAddConstant_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeAddConstant_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeAddConstant_2E_weak (const class GGS_typeAddConstant & inSource) ;

  public: GGS_typeAddConstant_2E_weak & operator = (const class GGS_typeAddConstant & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeAddConstant_2E_weak init_nil (void) {
    GGS_typeAddConstant_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeAddConstant bang_typeAddConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeAddConstant unwrappedValue (void) const {
    GGS_typeAddConstant result ;
    if (isValid ()) {
      const cPtr_typeAddConstant * p = (cPtr_typeAddConstant *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeAddConstant (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAddConstant_2E_weak extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAddConstant_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAddConstant_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAddConstant_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAddConstant_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSubConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeSubConstant : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typeSubConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeSubConstant (const class cPtr_typeSubConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeSubConstant init_21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                           const class GGS_uint & inOperand1,
                                                           const class GGS_bool & inOperand2,
                                                           const class GGS_luint & inOperand3,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeSubConstant extractObject (const GGS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeSubConstant class_func_new (const class GGS_lstring & inOperand0,
                                                           const class GGS_uint & inOperand1,
                                                           const class GGS_bool & inOperand2,
                                                           const class GGS_luint & inOperand3,
                                                           class Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeSubConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeSubConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant ;

#include "separateHeaderFor_typeSubConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeSubConstant_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeSubConstant_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeSubConstant_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeSubConstant_2E_weak (const class GGS_typeSubConstant & inSource) ;

  public: GGS_typeSubConstant_2E_weak & operator = (const class GGS_typeSubConstant & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeSubConstant_2E_weak init_nil (void) {
    GGS_typeSubConstant_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeSubConstant bang_typeSubConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeSubConstant unwrappedValue (void) const {
    GGS_typeSubConstant result ;
    if (isValid ()) {
      const cPtr_typeSubConstant * p = (cPtr_typeSubConstant *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeSubConstant (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeSubConstant_2E_weak extractObject (const GGS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeSubConstant_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeSubConstant_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeSubConstant_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeSubConstant_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignConstant reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAssignConstant : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typeAssignConstant (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeAssignConstant (const class cPtr_typeAssignConstant * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

  public: class GGS_bool readProperty_mNegativeConstant (void) const ;
  public: void setProperty_mNegativeConstant (const GGS_bool & inValue) ;

  public: class GGS_luint readProperty_mConstant (void) const ;
  public: void setProperty_mConstant (const GGS_luint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeAssignConstant init_21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                              const class GGS_uint & inOperand1,
                                                              const class GGS_bool & inOperand2,
                                                              const class GGS_luint & inOperand3,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAssignConstant extractObject (const GGS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAssignConstant class_func_new (const class GGS_lstring & inOperand0,
                                                              const class GGS_uint & inOperand1,
                                                              const class GGS_bool & inOperand2,
                                                              const class GGS_luint & inOperand3,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAssignConstant & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAssignConstant class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant ;

#include "separateHeaderFor_typeAssignConstant.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignConstant_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAssignConstant_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeAssignConstant_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeAssignConstant_2E_weak (const class GGS_typeAssignConstant & inSource) ;

  public: GGS_typeAssignConstant_2E_weak & operator = (const class GGS_typeAssignConstant & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeAssignConstant_2E_weak init_nil (void) {
    GGS_typeAssignConstant_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeAssignConstant bang_typeAssignConstant_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeAssignConstant unwrappedValue (void) const {
    GGS_typeAssignConstant result ;
    if (isValid ()) {
      const cPtr_typeAssignConstant * p = (cPtr_typeAssignConstant *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeAssignConstant (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAssignConstant_2E_weak extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAssignConstant_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAssignConstant_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAssignConstant_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignConstant_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignInfinity reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAssignInfinity : public GGS_typePostcondition {
//--------------------------------- Default constructor
  public: GGS_typeAssignInfinity (void) ;

//--------------------------------- Constructor from pointer
  public: GGS_typeAssignInfinity (const class cPtr_typeAssignInfinity * inSourcePtr) ;

//--------------------------------- Property access
  public: class GGS_lstring readProperty_mVarName (void) const ;
  public: void setProperty_mVarName (const GGS_lstring & inValue) ;

  public: class GGS_uint readProperty_mVar (void) const ;
  public: void setProperty_mVar (const GGS_uint & inValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeAssignInfinity init_21__21_ (const class GGS_lstring & inOperand0,
                                                      const class GGS_uint & inOperand1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAssignInfinity extractObject (const GGS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAssignInfinity class_func_new (const class GGS_lstring & inOperand0,
                                                              const class GGS_uint & inOperand1,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAssignInfinity & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAssignInfinity class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity ;

#include "separateHeaderFor_typeAssignInfinity.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeAssignInfinity_2E_weak weak reference class
//
//--------------------------------------------------------------------------------------------------

class GGS_typeAssignInfinity_2E_weak : public GGS_typePostcondition_2E_weak {
//--------------------------------- Default constructor
  public: GGS_typeAssignInfinity_2E_weak (void) ;

//--------------------------------- Constructor and assignment from strong reference
  public: GGS_typeAssignInfinity_2E_weak (const class GGS_typeAssignInfinity & inSource) ;

  public: GGS_typeAssignInfinity_2E_weak & operator = (const class GGS_typeAssignInfinity & inSource) ;

//--------------------------------- Constructor and assignment from optional reference

//--------------------------------- nil initializer
  public: inline static GGS_typeAssignInfinity_2E_weak init_nil (void) {
    GGS_typeAssignInfinity_2E_weak result ;
    macroMyNew (result.mProxyPtr, cPtr_weakReference_proxy (HERE)) ;
    return result ;
  }

//--------------------------------- Bang operator
  public: GGS_typeAssignInfinity bang_typeAssignInfinity_2E_weak (Compiler * inCompiler COMMA_LOCATION_ARGS) const ;

//--------------------------------- isValuated
  public: inline bool isValuated (void) const {
    return isValid () && (ptr () != nullptr) ;
  }

//--------------------------------- Unwrapped value
  public: inline GGS_typeAssignInfinity unwrappedValue (void) const {
    GGS_typeAssignInfinity result ;
    if (isValid ()) {
      const cPtr_typeAssignInfinity * p = (cPtr_typeAssignInfinity *) ptr () ;
      if (nullptr != p) {
        result = GGS_typeAssignInfinity (p) ;
      }
    }
    return result ;
  }

//--------------------------------- GALGAS read only properties
  public: inline GGS_bool readProperty_isNil (void) const {
    return GGS_bool (isValid (), ptr () == nullptr) ;
  }

  public: inline GGS_bool readProperty_isSome (void) const {
    return GGS_bool (isValid (), ptr () != nullptr) ;
  }

//-- Start of type generic part

//--------------------------------- Initializers

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeAssignInfinity_2E_weak extractObject (const GGS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeAssignInfinity_2E_weak class_func_nil (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: ComparisonResult objectCompare (const GGS_typeAssignInfinity_2E_weak & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeAssignInfinity_2E_weak class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeAssignInfinity_2E_weak ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList list
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostconditionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS_typePostconditionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS_typePostconditionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_typePostcondition & in_mPostcondition
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePostconditionList init (Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostconditionList extractObject (const GGS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostconditionList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS_typePostconditionList class_func_listWithValue (const class GGS_typePostcondition & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS_typePostconditionList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_typePostcondition & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_typePostconditionList add_operation (const GGS_typePostconditionList & inOperand,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_typePostcondition constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_typePostcondition constinArgument0,
                                                      class GGS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_typePostcondition & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_typePostcondition & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_typePostcondition & outArgument0,
                                                      class GGS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPostconditionAtIndex (class GGS_typePostcondition constinArgument0,
                                                                 class GGS_uint constinArgument1,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_typePostcondition & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_typePostcondition & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_typePostcondition getter_mPostconditionAtIndex (const class GGS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typePostconditionList getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typePostconditionList getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typePostconditionList getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_typePostconditionList_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typePostconditionList ;
 
} ; // End of GGS_typePostconditionList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typePostconditionList : public cGenericAbstractEnumerator {
  public: cEnumerator_typePostconditionList (const GGS_typePostconditionList & inEnumeratedObject,
                                             const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_typePostcondition current_mPostcondition (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_typePostconditionList_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typePostconditionList_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_typePostconditionList_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_typePostcondition mProperty_mPostcondition ;
  public: inline GGS_typePostcondition readProperty_mPostcondition (void) const {
    return mProperty_mPostcondition ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_typePostconditionList_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMPostcondition (const GGS_typePostcondition & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPostcondition = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_typePostconditionList_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_typePostconditionList_2E_element (const GGS_typePostcondition & in_mPostcondition) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typePostconditionList_2E_element init_21_ (const class GGS_typePostcondition & inOperand0,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typePostconditionList_2E_element extractObject (const GGS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typePostconditionList_2E_element class_func_new (const class GGS_typePostcondition & inOperand0,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typePostconditionList_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typePostconditionList_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList list
//
//--------------------------------------------------------------------------------------------------

class GGS_typeTransitionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS_typeTransitionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS_typeTransitionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_lstring & in_mTransitionName,
                                                 const class GGS_typePreconditionExpression & in_mPreconditionExpression,
                                                 const class GGS_typePostconditionList & in_mPostconditionList,
                                                 const class GGS_uint & in_mLowTemporalBound,
                                                 const class GGS_uint & in_mHighTemporalBound
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeTransitionList init (Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeTransitionList extractObject (const GGS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeTransitionList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS_typeTransitionList class_func_listWithValue (const class GGS_lstring & inOperand0,
                                                                        const class GGS_typePreconditionExpression & inOperand1,
                                                                        const class GGS_typePostconditionList & inOperand2,
                                                                        const class GGS_uint & inOperand3,
                                                                        const class GGS_uint & inOperand4
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS_typeTransitionList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_typePreconditionExpression & inOperand1,
                                                     const class GGS_typePostconditionList & inOperand2,
                                                     const class GGS_uint & inOperand3,
                                                     const class GGS_uint & inOperand4
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_typeTransitionList add_operation (const GGS_typeTransitionList & inOperand,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_lstring constinArgument0,
                                               class GGS_typePreconditionExpression constinArgument1,
                                               class GGS_typePostconditionList constinArgument2,
                                               class GGS_uint constinArgument3,
                                               class GGS_uint constinArgument4,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_lstring constinArgument0,
                                                      class GGS_typePreconditionExpression constinArgument1,
                                                      class GGS_typePostconditionList constinArgument2,
                                                      class GGS_uint constinArgument3,
                                                      class GGS_uint constinArgument4,
                                                      class GGS_uint constinArgument5,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_lstring & outArgument0,
                                                 class GGS_typePreconditionExpression & outArgument1,
                                                 class GGS_typePostconditionList & outArgument2,
                                                 class GGS_uint & outArgument3,
                                                 class GGS_uint & outArgument4,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_lstring & outArgument0,
                                                class GGS_typePreconditionExpression & outArgument1,
                                                class GGS_typePostconditionList & outArgument2,
                                                class GGS_uint & outArgument3,
                                                class GGS_uint & outArgument4,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_lstring & outArgument0,
                                                      class GGS_typePreconditionExpression & outArgument1,
                                                      class GGS_typePostconditionList & outArgument2,
                                                      class GGS_uint & outArgument3,
                                                      class GGS_uint & outArgument4,
                                                      class GGS_uint constinArgument5,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMHighTemporalBoundAtIndex (class GGS_uint constinArgument0,
                                                                     class GGS_uint constinArgument1,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMLowTemporalBoundAtIndex (class GGS_uint constinArgument0,
                                                                    class GGS_uint constinArgument1,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPostconditionListAtIndex (class GGS_typePostconditionList constinArgument0,
                                                                     class GGS_uint constinArgument1,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMPreconditionExpressionAtIndex (class GGS_typePreconditionExpression constinArgument0,
                                                                          class GGS_uint constinArgument1,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTransitionNameAtIndex (class GGS_lstring constinArgument0,
                                                                  class GGS_uint constinArgument1,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_lstring & outArgument0,
                                              class GGS_typePreconditionExpression & outArgument1,
                                              class GGS_typePostconditionList & outArgument2,
                                              class GGS_uint & outArgument3,
                                              class GGS_uint & outArgument4,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_lstring & outArgument0,
                                             class GGS_typePreconditionExpression & outArgument1,
                                             class GGS_typePostconditionList & outArgument2,
                                             class GGS_uint & outArgument3,
                                             class GGS_uint & outArgument4,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mHighTemporalBoundAtIndex (const class GGS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_uint getter_mLowTemporalBoundAtIndex (const class GGS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typePostconditionList getter_mPostconditionListAtIndex (const class GGS_uint & constinOperand0,
                                                                                             Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typePreconditionExpression getter_mPreconditionExpressionAtIndex (const class GGS_uint & constinOperand0,
                                                                                                       Compiler * inCompiler
                                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mTransitionNameAtIndex (const class GGS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeTransitionList getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeTransitionList getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeTransitionList getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_typeTransitionList_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeTransitionList ;
 
} ; // End of GGS_typeTransitionList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeTransitionList : public cGenericAbstractEnumerator {
  public: cEnumerator_typeTransitionList (const GGS_typeTransitionList & inEnumeratedObject,
                                          const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_mTransitionName (LOCATION_ARGS) const ;
  public: class GGS_typePreconditionExpression current_mPreconditionExpression (LOCATION_ARGS) const ;
  public: class GGS_typePostconditionList current_mPostconditionList (LOCATION_ARGS) const ;
  public: class GGS_uint current_mLowTemporalBound (LOCATION_ARGS) const ;
  public: class GGS_uint current_mHighTemporalBound (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_typeTransitionList_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeTransitionList_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_typeTransitionList_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_mTransitionName ;
  public: inline GGS_lstring readProperty_mTransitionName (void) const {
    return mProperty_mTransitionName ;
  }

  public: GGS_typePreconditionExpression mProperty_mPreconditionExpression ;
  public: inline GGS_typePreconditionExpression readProperty_mPreconditionExpression (void) const {
    return mProperty_mPreconditionExpression ;
  }

  public: GGS_typePostconditionList mProperty_mPostconditionList ;
  public: inline GGS_typePostconditionList readProperty_mPostconditionList (void) const {
    return mProperty_mPostconditionList ;
  }

  public: GGS_uint mProperty_mLowTemporalBound ;
  public: inline GGS_uint readProperty_mLowTemporalBound (void) const {
    return mProperty_mLowTemporalBound ;
  }

  public: GGS_uint mProperty_mHighTemporalBound ;
  public: inline GGS_uint readProperty_mHighTemporalBound (void) const {
    return mProperty_mHighTemporalBound ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_typeTransitionList_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMTransitionName (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mTransitionName = inValue ;
  }

  public: inline void setter_setMPreconditionExpression (const GGS_typePreconditionExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPreconditionExpression = inValue ;
  }

  public: inline void setter_setMPostconditionList (const GGS_typePostconditionList & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mPostconditionList = inValue ;
  }

  public: inline void setter_setMLowTemporalBound (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mLowTemporalBound = inValue ;
  }

  public: inline void setter_setMHighTemporalBound (const GGS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mHighTemporalBound = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_typeTransitionList_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_typeTransitionList_2E_element (const GGS_lstring & in_mTransitionName,
                                             const GGS_typePreconditionExpression & in_mPreconditionExpression,
                                             const GGS_typePostconditionList & in_mPostconditionList,
                                             const GGS_uint & in_mLowTemporalBound,
                                             const GGS_uint & in_mHighTemporalBound) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeTransitionList_2E_element init_21__21__21__21__21_ (const class GGS_lstring & inOperand0,
                                                                             const class GGS_typePreconditionExpression & inOperand1,
                                                                             const class GGS_typePostconditionList & inOperand2,
                                                                             const class GGS_uint & inOperand3,
                                                                             const class GGS_uint & inOperand4,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeTransitionList_2E_element extractObject (const GGS_object & inObject,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeTransitionList_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                         const class GGS_typePreconditionExpression & inOperand1,
                                                                         const class GGS_typePostconditionList & inOperand2,
                                                                         const class GGS_uint & inOperand3,
                                                                         const class GGS_uint & inOperand4,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeTransitionList_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeTransitionList_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList list
//
//--------------------------------------------------------------------------------------------------

class GGS_typeInitialMarkingList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS_typeInitialMarkingList (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS_typeInitialMarkingList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_typePostcondition & in_mInitValue
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeInitialMarkingList init (Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeInitialMarkingList extractObject (const GGS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeInitialMarkingList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS_typeInitialMarkingList class_func_listWithValue (const class GGS_typePostcondition & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS_typeInitialMarkingList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_typePostcondition & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_typeInitialMarkingList add_operation (const GGS_typeInitialMarkingList & inOperand,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_typePostcondition constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_typePostcondition constinArgument0,
                                                      class GGS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_typePostcondition & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_typePostcondition & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_typePostcondition & outArgument0,
                                                      class GGS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMInitValueAtIndex (class GGS_typePostcondition constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_typePostcondition & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_typePostcondition & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_typePostcondition getter_mInitValueAtIndex (const class GGS_uint & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeInitialMarkingList getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeInitialMarkingList getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_typeInitialMarkingList getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_typeInitialMarkingList_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_typeInitialMarkingList ;
 
} ; // End of GGS_typeInitialMarkingList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_typeInitialMarkingList : public cGenericAbstractEnumerator {
  public: cEnumerator_typeInitialMarkingList (const GGS_typeInitialMarkingList & inEnumeratedObject,
                                              const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_typePostcondition current_mInitValue (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_typeInitialMarkingList_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @typeInitialMarkingList_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_typeInitialMarkingList_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_typePostcondition mProperty_mInitValue ;
  public: inline GGS_typePostcondition readProperty_mInitValue (void) const {
    return mProperty_mInitValue ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_typeInitialMarkingList_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMInitValue (const GGS_typePostcondition & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mInitValue = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_typeInitialMarkingList_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_typeInitialMarkingList_2E_element (const GGS_typePostcondition & in_mInitValue) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_typeInitialMarkingList_2E_element init_21_ (const class GGS_typePostcondition & inOperand0,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_typeInitialMarkingList_2E_element extractObject (const GGS_object & inObject,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_typeInitialMarkingList_2E_element class_func_new (const class GGS_typePostcondition & inOperand0,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_typeInitialMarkingList_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typeInitialMarkingList_2E_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @countList list
//
//--------------------------------------------------------------------------------------------------

class GGS_countList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GGS_countList (void) ;

//--------------------------------- List constructor used by listmap
  public: GGS_countList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GGS_lstring & in_mName,
                                                 const class GGS_typePreconditionExpression & in_mCondition
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_countList init (Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_countList extractObject (const GGS_object & inObject,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_countList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GGS_countList class_func_listWithValue (const class GGS_lstring & inOperand0,
                                                               const class GGS_typePreconditionExpression & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GGS_countList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GGS_lstring & inOperand0,
                                                     const class GGS_typePreconditionExpression & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GGS_countList add_operation (const GGS_countList & inOperand,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GGS_lstring constinArgument0,
                                               class GGS_typePreconditionExpression constinArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GGS_lstring constinArgument0,
                                                      class GGS_typePreconditionExpression constinArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GGS_lstring & outArgument0,
                                                 class GGS_typePreconditionExpression & outArgument1,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GGS_lstring & outArgument0,
                                                class GGS_typePreconditionExpression & outArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GGS_lstring & outArgument0,
                                                      class GGS_typePreconditionExpression & outArgument1,
                                                      class GGS_uint constinArgument2,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMConditionAtIndex (class GGS_typePreconditionExpression constinArgument0,
                                                             class GGS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMNameAtIndex (class GGS_lstring constinArgument0,
                                                        class GGS_uint constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GGS_lstring & outArgument0,
                                              class GGS_typePreconditionExpression & outArgument1,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GGS_lstring & outArgument0,
                                             class GGS_typePreconditionExpression & outArgument1,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GGS_typePreconditionExpression getter_mConditionAtIndex (const class GGS_uint & constinOperand0,
                                                                                          Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_lstring getter_mNameAtIndex (const class GGS_uint & constinOperand0,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_countList getter_subListFromIndex (const class GGS_uint & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_countList getter_subListToIndex (const class GGS_uint & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GGS_countList getter_subListWithRange (const class GGS_range & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Read subscripts

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;

//--- Append element
  public: VIRTUAL_IN_DEBUG void enterElement (const class GGS_countList_2E_element & inValue,
                                              Compiler * /* inCompiler */
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend
  friend class cEnumerator_countList ;
 
} ; // End of GGS_countList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_countList : public cGenericAbstractEnumerator {
  public: cEnumerator_countList (const GGS_countList & inEnumeratedObject,
                                 const EnumerationOrder inOrder) ;

//--- Current element access
  public: class GGS_lstring current_mName (LOCATION_ARGS) const ;
  public: class GGS_typePreconditionExpression current_mCondition (LOCATION_ARGS) const ;
//--- Current element access
  public: class GGS_countList_2E_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @countList_2E_element struct
//
//--------------------------------------------------------------------------------------------------

class GGS_countList_2E_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GGS_lstring mProperty_mName ;
  public: inline GGS_lstring readProperty_mName (void) const {
    return mProperty_mName ;
  }

  public: GGS_typePreconditionExpression mProperty_mCondition ;
  public: inline GGS_typePreconditionExpression readProperty_mCondition (void) const {
    return mProperty_mCondition ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GGS_countList_2E_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setMName (const GGS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mName = inValue ;
  }

  public: inline void setter_setMCondition (const GGS_typePreconditionExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mCondition = inValue ;
  }

//--------------------------------- Virtual destructor
  public: virtual ~ GGS_countList_2E_element (void) ;

//--------------------------------- Set initialized properties
  private: void setInitializedProperties (Compiler * inCompiler) ;

//--------------------------------- Native constructor
  public: GGS_countList_2E_element (const GGS_lstring & in_mName,
                                    const GGS_typePreconditionExpression & in_mCondition) ;

//-- Start of type generic part

//--------------------------------- Initializers
  public: static GGS_countList_2E_element init_21__21_ (const class GGS_lstring & inOperand0,
                                                        const class GGS_typePreconditionExpression & inOperand1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GGS_countList_2E_element extractObject (const GGS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GGS_countList_2E_element class_func_new (const class GGS_lstring & inOperand0,
                                                                const class GGS_typePreconditionExpression & inOperand1,
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

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GGS_countList_2E_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_countList_2E_element ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'spec_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_spec_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_spec_5F_parser (void) { }

//--- Non terminal declarations
  protected: virtual void nt_axiome_ (class GGS_uint & outArgument0,
                                      class GGS_uint & outArgument1,
                                      class GGS_typeVarMap & outArgument2,
                                      class GGS_typeTransitionList & outArgument3,
                                      class GGS_typeInitialMarkingList & outArgument4,
                                      class GGS_countList & outArgument5,
                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_axiome_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_ (class GGS_typeVarMap & ioArgument0,
                                      class GGS_typeCstMap & ioArgument1,
                                      class GGS_typePreconditionExpression & outArgument2,
                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_factor_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_ (class GGS_uint & outArgument0,
                                              class GGS_uint & outArgument1,
                                              class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_bound_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_ (class GGS_typeCstMap & ioArgument0,
                                                 class GGS_bool & outArgument1,
                                                 class GGS_luint & outArgument2,
                                                 class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_constant_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_ (class GGS_typeVarMap & ioArgument0,
                                                      class GGS_typeCstMap & ioArgument1,
                                                      class GGS_typePostconditionList & outArgument2,
                                                      class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_postcondition_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_ (class GGS_typeVarMap & ioArgument0,
                                                     class GGS_typeCstMap & ioArgument1,
                                                     class GGS_typePreconditionExpression & outArgument2,
                                                     class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_parse_5F_precondition_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_ (class GGS_typeVarMap & ioArgument0,
                                       class GGS_typeCstMap & ioArgument1,
                                       class GGS_typePreconditionExpression & outArgument2,
                                       class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_primary_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_ (class GGS_typeVarMap & ioArgument0,
                                    class GGS_typeCstMap & ioArgument1,
                                    class GGS_typePreconditionExpression & outArgument2,
                                    class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_parse (class Lexique_spec_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_term_indexing (class Lexique_spec_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_ (GGS_typeVarMap & ioArgument0,
                                                                 GGS_typeCstMap & ioArgument1,
                                                                 GGS_typePreconditionExpression & outArgument2,
                                                                 Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_precondition_i0_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_ (GGS_typeVarMap & ioArgument0,
                                                GGS_typeCstMap & ioArgument1,
                                                GGS_typePreconditionExpression & outArgument2,
                                                Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_term_i1_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_ (GGS_typeVarMap & ioArgument0,
                                                  GGS_typeCstMap & ioArgument1,
                                                  GGS_typePreconditionExpression & outArgument2,
                                                  Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_factor_i2_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_ (GGS_typeVarMap & ioArgument0,
                                                   GGS_typeCstMap & ioArgument1,
                                                   GGS_typePreconditionExpression & outArgument2,
                                                   Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_primary_i3_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_ (GGS_typeCstMap & ioArgument0,
                                                             GGS_bool & outArgument1,
                                                             GGS_luint & outArgument2,
                                                             Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_constant_i4_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_ (GGS_typeVarMap & ioArgument0,
                                                                  GGS_typeCstMap & ioArgument1,
                                                                  GGS_typePostconditionList & outArgument2,
                                                                  Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_postcondition_i5_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_ (GGS_uint & outArgument0,
                                                          GGS_uint & outArgument1,
                                                          Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i6_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_ (GGS_uint & outArgument0,
                                                          GGS_uint & outArgument1,
                                                          Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_parse (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_parse_5F_bound_i7_indexing (Lexique_spec_5F_scanner * inLexique) ;

  protected: void rule_spec_5F_parser_axiome_i8_ (GGS_uint & outArgument0,
                                                  GGS_uint & outArgument1,
                                                  GGS_typeVarMap & outArgument2,
                                                  GGS_typeTransitionList & outArgument3,
                                                  GGS_typeInitialMarkingList & outArgument4,
                                                  GGS_countList & outArgument5,
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
  public: virtual void nt_axiome_ (GGS_uint & outArgument0,
                                   GGS_uint & outArgument1,
                                   GGS_typeVarMap & outArgument2,
                                   GGS_typeTransitionList & outArgument3,
                                   GGS_typeInitialMarkingList & outArgument4,
                                   GGS_countList & outArgument5,
                                   Lexique_spec_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GGS_lstring inFileName,
                                                  GGS_uint & outArgument0,
                                                  GGS_uint & outArgument1,
                                                  GGS_typeVarMap & outArgument2,
                                                  GGS_typeTransitionList & outArgument3,
                                                  GGS_typeInitialMarkingList & outArgument4,
                                                  GGS_countList & outArgument5
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GGS_string inSourceString,
                                                    GGS_string inNameString,
                                                    GGS_uint & outArgument0,
                                                    GGS_uint & outArgument1,
                                                    GGS_typeVarMap & outArgument2,
                                                    GGS_typeTransitionList & outArgument3,
                                                    GGS_typeInitialMarkingList & outArgument4,
                                                    GGS_countList & outArgument5
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
  public: virtual void nt_factor_ (GGS_typeVarMap & ioArgument0,
                                   GGS_typeCstMap & ioArgument1,
                                   GGS_typePreconditionExpression & outArgument2,
                                   Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_bound' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_bound_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_bound_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_bound_ (GGS_uint & outArgument0,
                                           GGS_uint & outArgument1,
                                           Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_constant' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_constant_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_constant_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_constant_ (GGS_typeCstMap & ioArgument0,
                                              GGS_bool & outArgument1,
                                              GGS_luint & outArgument2,
                                              Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_postcondition' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_postcondition_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_postcondition_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_postcondition_ (GGS_typeVarMap & ioArgument0,
                                                   GGS_typeCstMap & ioArgument1,
                                                   GGS_typePostconditionList & outArgument2,
                                                   Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'parse_precondition' non terminal
//--- 'parse' label
  public: virtual void nt_parse_5F_precondition_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_parse_5F_precondition_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_parse_5F_precondition_ (GGS_typeVarMap & ioArgument0,
                                                  GGS_typeCstMap & ioArgument1,
                                                  GGS_typePreconditionExpression & outArgument2,
                                                  Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'primary' non terminal
//--- 'parse' label
  public: virtual void nt_primary_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_primary_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_primary_ (GGS_typeVarMap & ioArgument0,
                                    GGS_typeCstMap & ioArgument1,
                                    GGS_typePreconditionExpression & outArgument2,
                                    Lexique_spec_5F_scanner * inCompiler) ;

//------------------------------------- 'term' non terminal
//--- 'parse' label
  public: virtual void nt_term_parse (Lexique_spec_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_term_indexing (Lexique_spec_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_term_ (GGS_typeVarMap & ioArgument0,
                                 GGS_typeCstMap & ioArgument1,
                                 GGS_typePreconditionExpression & outArgument2,
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

void routine_println_3F_ (const class GGS_string constinArgument0,
                          class Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'print?'
//
//--------------------------------------------------------------------------------------------------

void routine_print_3F_ (const class GGS_string constinArgument0,
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

void routine_generate_5F_code_3F__3F__3F__3F__3F__3F_ (const class GGS_uint constinArgument0,
                                                       const class GGS_uint constinArgument1,
                                                       const class GGS_typeVarMap constinArgument2,
                                                       const class GGS_typeTransitionList constinArgument3,
                                                       const class GGS_typeInitialMarkingList constinArgument4,
                                                       const class GGS_countList constinArgument5,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

