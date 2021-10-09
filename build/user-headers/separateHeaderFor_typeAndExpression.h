//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeAndExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typeAndExpression : public cPtr_typePreconditionExpression {
//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const ;

//--- END OF USER ZONE 2
//--- Attributes
  public: GALGAS_typePreconditionExpression mProperty_mLeftExpression ;
  public: GALGAS_typePreconditionExpression mProperty_mRightExpression ;

//--- Constructor
  public: cPtr_typeAndExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                  const GALGAS_typePreconditionExpression & in_mRightExpression
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_typePreconditionExpression getter_mLeftExpression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMLeftExpression (GALGAS_typePreconditionExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_typePreconditionExpression getter_mRightExpression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMRightExpression (GALGAS_typePreconditionExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

