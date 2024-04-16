//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeAndExpression class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typeAndExpression : public cPtr_typePreconditionExpression {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeAndExpression_init_21__21_ (const class GALGAS_typePreconditionExpression & inOperand0,
                                               const class GALGAS_typePreconditionExpression & inOperand1,
                                               Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_typePreconditionExpression mProperty_mLeftExpression ;
  public: GALGAS_typePreconditionExpression mProperty_mRightExpression ;


//--- Default constructor
  public: cPtr_typeAndExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeAndExpression (const GALGAS_typePreconditionExpression & in_mLeftExpression,
                                  const GALGAS_typePreconditionExpression & in_mRightExpression
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//--- Class descriptor
  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

