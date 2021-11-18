//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeTrueExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_typeTrueExpression : public cPtr_typePreconditionExpression {

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const ;

//--- END OF USER ZONE 2
//--- Properties

//--- Constructor
  public: cPtr_typeTrueExpression (LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

