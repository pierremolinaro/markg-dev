//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typePreconditionExpression class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typePreconditionExpression : public acStrongPtr_class {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typePreconditionExpression_init (Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual class C_AEDD buildAEDDexpression (void) const = 0 ;

//--- END OF USER ZONE 2
//--- Properties


//--- Default constructor
  public: cPtr_typePreconditionExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typePreconditionExpression (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual ComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

