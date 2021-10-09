//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeComplementExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typeComplementExpression : public cPtr_typePreconditionExpression {
//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const ;

//--- END OF USER ZONE 2
//--- Attributes
  public: GALGAS_typePreconditionExpression mProperty_mExpression ;

//--- Constructor
  public: cPtr_typeComplementExpression (const GALGAS_typePreconditionExpression & in_mExpression
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_typePreconditionExpression getter_mExpression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMExpression (GALGAS_typePreconditionExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

