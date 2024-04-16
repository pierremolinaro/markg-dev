//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeEqualExpression class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typeEqualExpression : public cPtr_typePreconditionExpression {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeEqualExpression_init_21__21__21_ (const class GALGAS_uint & inOperand0,
                                                     const class GALGAS_bool & inOperand1,
                                                     const class GALGAS_luint & inOperand2,
                                                     Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_uint mProperty_mVar ;
  public: GALGAS_bool mProperty_mNegativeConstant ;
  public: GALGAS_luint mProperty_mConstant ;


//--- Default constructor
  public: cPtr_typeEqualExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeEqualExpression (const GALGAS_uint & in_mVar,
                                    const GALGAS_bool & in_mNegativeConstant,
                                    const GALGAS_luint & in_mConstant
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

