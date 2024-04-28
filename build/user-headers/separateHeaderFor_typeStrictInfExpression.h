//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeStrictInfExpression class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typeStrictInfExpression : public cPtr_typePreconditionExpression {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeStrictInfExpression_init_21__21__21_ (const class GGS_uint & inOperand0,
                                                         const class GGS_bool & inOperand1,
                                                         const class GGS_luint & inOperand2,
                                                         Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual C_AEDD buildAEDDexpression (void) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GGS_uint mProperty_mVar ;
  public: GGS_bool mProperty_mNegativeConstant ;
  public: GGS_luint mProperty_mConstant ;


//--- Default constructor
  public: cPtr_typeStrictInfExpression (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeStrictInfExpression (const GGS_uint & in_mVar,
                                        const GGS_bool & in_mNegativeConstant,
                                        const GGS_luint & in_mConstant
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

