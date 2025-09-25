//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
// Phase 2: pointer class for @typeOrExpression class
//--------------------------------------------------------------------------------------------------

class cPtr_typeOrExpression : public cPtr_typePreconditionExpression {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeOrExpression_init_21__21_ (const class GGS_typePreconditionExpression & inOperand0,
                                              const class GGS_typePreconditionExpression & inOperand1,
                                              Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GGS_typePreconditionExpression mProperty_mLeftExpression ;
  public: GGS_typePreconditionExpression mProperty_mRightExpression ;


//--- Default constructor
  public: cPtr_typeOrExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeOrExpression (const GGS_typePreconditionExpression & in_mLeftExpression,
                                 const GGS_typePreconditionExpression & in_mRightExpression,
                                 Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//--- Class descriptor
  public: virtual const GALGAS_TypeDescriptor * classDescriptor (void) const override ;

} ;

