//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeAddConstant class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typeAddConstant : public cPtr_typePostcondition {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeAddConstant_init_21__21__21__21_ (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_uint & inOperand1,
                                                     const class GALGAS_bool & inOperand2,
                                                     const class GALGAS_luint & inOperand3,
                                                     Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual void buildPostCondition (const int32_t inTransition,
                                            Compiler * inLexique,
                                            cPostConditionArray & ioPostCondition) const override ;
  public : virtual void buildInitialMarking (C_VDD & ioInitialMarking) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GALGAS_lstring mProperty_mVarName ;
  public: GALGAS_uint mProperty_mVar ;
  public: GALGAS_bool mProperty_mNegativeConstant ;
  public: GALGAS_luint mProperty_mConstant ;


//--- Default constructor
  public: cPtr_typeAddConstant (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeAddConstant (const GALGAS_lstring & in_mVarName,
                                const GALGAS_uint & in_mVar,
                                const GALGAS_bool & in_mNegativeConstant,
                                const GALGAS_luint & in_mConstant
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual ComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

