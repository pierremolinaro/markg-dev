//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typePostDecrement class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typePostDecrement : public cPtr_typePostcondition {
//--- START OF USER ZONE 2

  public : virtual void buildPostCondition (const int32_t inTransition,
                                            C_Compiler * inLexique,
                                            cPostConditionArray & ioPostCondition) const ;
  public : virtual void buildInitialMarking (C_VDD & ioInitialMarking) const ;

//--- END OF USER ZONE 2
//--- Attributes
  public : GALGAS_lstring mProperty_mVarName ;
  public : GALGAS_uint mProperty_mVar ;

//--- Constructor
  public : cPtr_typePostDecrement (const GALGAS_lstring & in_mVarName,
                                   const GALGAS_uint & in_mVar
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_mVarName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setMVarName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_mVar (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setMVar (GALGAS_uint inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

