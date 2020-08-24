//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeStrictInfExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typeStrictInfExpression : public cPtr_typePreconditionExpression {
//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const ;

//--- END OF USER ZONE 2
//--- Attributes
  public : GALGAS_uint mProperty_mVar ;
  public : GALGAS_bool mProperty_mNegativeConstant ;
  public : GALGAS_luint mProperty_mConstant ;

//--- Constructor
  public : cPtr_typeStrictInfExpression (const GALGAS_uint & in_mVar,
                                         const GALGAS_bool & in_mNegativeConstant,
                                         const GALGAS_luint & in_mConstant
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_mVar (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setMVar (GALGAS_uint inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_mNegativeConstant (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setMNegativeConstant (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_luint getter_mConstant (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void setter_setMConstant (GALGAS_luint inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

