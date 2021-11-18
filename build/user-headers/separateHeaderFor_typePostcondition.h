//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typePostcondition class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typePostcondition : public acStrongPtr_class {

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2

  public : virtual void buildPostCondition (const int32_t inTransition,
                                            C_Compiler * inLexique,
                                            class cPostConditionArray & ioPostCondition) const = 0 ;
  public : virtual void buildInitialMarking (class C_VDD & ioInitialMarking) const = 0 ;

//--- END OF USER ZONE 2
//--- Properties

//--- Constructor
  public: cPtr_typePostcondition (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

