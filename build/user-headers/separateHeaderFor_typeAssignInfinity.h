//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @typeAssignInfinity class
//
//--------------------------------------------------------------------------------------------------

class cPtr_typeAssignInfinity : public cPtr_typePostcondition {

  #ifndef DO_NOT_GENERATE_CHECKINGS
    public: virtual void printNonNullClassInstanceProperties (void) const override ;
  #endif

//--------------------------------- Initializers
  public: void typeAssignInfinity_init_21__21_ (const class GGS_lstring & inOperand0,
                                                const class GGS_uint & inOperand1,
                                                Compiler * inCompiler) ;


//--- START OF USER ZONE 2

  public : virtual void buildPostCondition (const int32_t inTransition,
                                            Compiler * inLexique,
                                            cPostConditionArray & ioPostCondition) const override ;
  public : virtual void buildInitialMarking (C_VDD & ioInitialMarking) const override ;

//--- END OF USER ZONE 2
//--- Properties
  public: GGS_lstring mProperty_mVarName ;
  public: GGS_uint mProperty_mVar ;


//--- Default constructor
  public: cPtr_typeAssignInfinity (Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--- Constructor
  public: cPtr_typeAssignInfinity (const GGS_lstring & in_mVarName,
                                   const GGS_uint & in_mVar,
                                   Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (Compiler * inCompiler COMMA_LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

//--- Class descriptor
  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

