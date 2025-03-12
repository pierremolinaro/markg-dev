#include "spec_semantics.h"

/*--------------------------------------------------------------------------*/

#include "Compiler.h"
#include "TC_Array2.h"
#include "TC_UniqueArray.h"
#include "C_AEDD.h"
#include "C_PCL.h"
#include "C_VDD.h"
#include "spec_options.h"
#include "Timer.h"

/*--------------------------------------------------------------------------*/

typedef enum {UNDEFINED_POST, INC_POST, ASSIGN_POST} enumPost ;

/*--------------------------------------------------------------------------*/

class cPostCondition {
  public : cPostCondition (void) ;
  public : enumPost mPost ;
  public : int32_t mConstant ;
} ;

/*--------------------------------------------------------------------------*/

cPostCondition::cPostCondition (void) :
mPost (UNDEFINED_POST),
mConstant (0) {
}

/*--------------------------------------------------------------------------*/

class cPostConditionArray : public TC_Array2 <cPostCondition> {
  public : cPostConditionArray (const int32_t inRowCount,
                                const int32_t inColumnCount COMMA_LOCATION_ARGS) ;
} ;

/*--------------------------------------------------------------------------*/

cPostConditionArray::
cPostConditionArray (const int32_t inRowCount,
                     const int32_t inColumnCount COMMA_LOCATION_ARGS) :
TC_Array2 <cPostCondition> (inRowCount, inColumnCount COMMA_THERE) {
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAssignConstant::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost != UNDEFINED_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be assigned (has been already assigned or incremented)",
         TC_Array <FixItDescription> ()
          COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mPost = ASSIGN_POST ;
  int32_t c = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    c = - c ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant = c ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAssignConstant::
buildInitialMarking (C_VDD & ioInitialMarking) const {
  const T_vdd_zsl_index varIndex = (T_vdd_zsl_index) mProperty_mVar.uintValue () ;
  int32_t c = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    c = - c ;
  }
  ioInitialMarking.addValueAtIndex ((T_vdd_zsl_value) c, varIndex) ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAssignInfinity::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost != UNDEFINED_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be assigned (has been already assigned or incremented)",
         TC_Array <FixItDescription> ()
         COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant = MAX_VDD_ZSL_VALUE ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAssignInfinity::
buildInitialMarking (C_VDD & ioInitialMarking) const {
  const T_vdd_zsl_index varIndex = (T_vdd_zsl_index) mProperty_mVar.uintValue () ;
  ioInitialMarking.addValueAtIndex (MAX_VDD_ZSL_VALUE, varIndex) ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeSubConstant::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be decremented (has been already assigned)",
         TC_Array <FixItDescription> ()
         COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mPost = INC_POST ;
  int32_t c = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    c = - c ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant -= c ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeSubConstant::
buildInitialMarking (C_VDD & /* ioInitialMarking */) const {
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAddConstant::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be incremented (has been already assigned)",
         TC_Array <FixItDescription> ()
         COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mPost = INC_POST ;
  int32_t c = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    c = - c ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant += c ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typeAddConstant::
buildInitialMarking (C_VDD & /* ioInitialMarking */) const {
}

/*--------------------------------------------------------------------------*/

void cPtr_typePostIncrement::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be incremented (has been already assigned)",
         TC_Array <FixItDescription> ()
         COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mPost = INC_POST ;
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant ++ ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typePostIncrement::
buildInitialMarking (C_VDD & /* ioInitialMarking */) const {
}

/*--------------------------------------------------------------------------*/

void cPtr_typePostDecrement::
buildPostCondition (const int32_t inTransition,
                    Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be decremented (has been already assigned)",
         TC_Array <FixItDescription> ()
         COMMA_HERE) ;
  }
  ioPostCondition (inTransition, varIndex COMMA_HERE).mPost = INC_POST ;
  ioPostCondition (inTransition, varIndex COMMA_HERE).mConstant -- ;
}

/*--------------------------------------------------------------------------*/

void cPtr_typePostDecrement::
buildInitialMarking (C_VDD & /* ioInitialMarking */) const {
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeTrueExpression::buildAEDDexpression (void) const {
  C_AEDD aedd ; aedd.setToTrue () ;
  return aedd ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeFalseExpression::buildAEDDexpression (void) const {
  return C_AEDD () ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeComplementExpression::buildAEDDexpression (void) const {
  auto p = (const cPtr_typePreconditionExpression *) mProperty_mExpression.ptr () ;
  return ~ (p->buildAEDDexpression ()) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeAndExpression::buildAEDDexpression (void) const {
  auto p = (const cPtr_typePreconditionExpression *) mProperty_mLeftExpression.ptr () ;
  auto q = (const cPtr_typePreconditionExpression *) mProperty_mRightExpression.ptr () ;
  return p->buildAEDDexpression () & q->buildAEDDexpression () ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeOrExpression::buildAEDDexpression (void) const {
  auto p = (const cPtr_typePreconditionExpression *) mProperty_mLeftExpression.ptr () ;
  auto q = (const cPtr_typePreconditionExpression *) mProperty_mRightExpression.ptr () ;
  return p->buildAEDDexpression () | q->buildAEDDexpression () ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeEqualExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varEqualToConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeNonEqualExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue() ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varDifferentThanConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeInfOrEqualExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varInfOrEqualToConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeSupOrEqualExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varSupOrEqualToConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeStrictSupExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varStrictSupThanConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeStrictInfExpression::buildAEDDexpression (void) const {
  int32_t constant = (int32_t) mProperty_mConstant.mProperty_uint.uintValue () ;
  if (mProperty_mNegativeConstant.boolValue ()) {
    constant = - constant ;
  }
  return C_AEDD::varStrictInfThanConstant ((uint16_t) mProperty_mVar.uintValue (),  constant) ;
}

//---------------------------------------------------------------------------*

static void
vddComputation (uint32_t inGarbagePeriod,
                const bool inDoNotPrintIterationsMessages,
                const bool inPrintTransitionsFiring,
                const bool inPrintAllNodes,
                const bool inPrintAllStates,
                const bool inPrintIterationsStates,
                const bool inPrintMinAndMax,
                const String & /* inSourceFileName */,
                const int32_t inTransitionsCount,
                const C_VDD & inInitialMarking,
                const TC_UniqueArray <C_AEDD> & inPreConditions,
                const TC_UniqueArray <C_PCL> & inIncidenceVectors,
                const TC_UniqueArray <String> & inPlaceNames,
                const TC_UniqueArray <String> & inTransitionNames,
                const GGS_countList & inCountList,
                const uint32_t inLastIteration) {
  uint64_t stateCount = 0 ;
  TC_UniqueArray <uint64_t> VDDtransitionsFiringCount (inTransitionsCount, 0 COMMA_HERE) ;
  C_PCL::collectUnusedNodes () ;
  C_VDD allStatesSet = inInitialMarking ;
//--- Normalize garbage period
  if (inGarbagePeriod < 1) {
    inGarbagePeriod = 1 ; // Garbage every iteration
  }
//--------------- Computation with vector decision diagrams -----------------
   gCout.appendString ("Computation with vector decision diagrams...\n") ;
   fflush (stdout) ;
//--- Vector of transition source set
  TC_UniqueArray <C_VDD> transitionSourceSet (inTransitionsCount, C_VDD () COMMA_HERE) ;
//--- Vector of transition target set
  TC_UniqueArray <C_VDD> transitionTargetSet (inTransitionsCount, C_VDD () COMMA_HERE) ;
//--- Loop ------------------------------
  Timer timer ;
  timer.startTimer () ;
  bool loop = true ;
  uint32_t iteration = 0 ;
  while (loop) {
    iteration ++ ;
  //--- Garbage ?
    if ((iteration % inGarbagePeriod) == 0) {
      Timer garbageTimer ;
      garbageTimer.startTimer () ;
      const size_t previousNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      C_VDD::collectUnusedNodes () ;
      const size_t newNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      size_t ramSize = C_VDD::getCachesSizeInBytes () ;
      ramSize += C_VDD::getUniqueTableSizeInBytes () ;
      ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
      ramSize /= 1 << 20 ;
      garbageTimer.stopTimer () ;
      if (! inDoNotPrintIterationsMessages) {
        gCout.appendString ("Garbage (RAM ") ;
        gCout.appendUnsigned (ramSize) ;
        gCout.appendString (" Mb) : ") ;
        gCout.appendUnsigned (previousNodeCount) ;
        gCout.appendString (" nodes -> ") ;
        gCout.appendUnsigned (newNodeCount) ;
        gCout.appendString (" (") ;
        gCout.appendString (garbageTimer.timeString ()) ;
        gCout.appendString (")\n") ;
        fflush (stdout) ;
      }
    }
  //--- Fire transitions
    Timer iterationTimer ;
    iterationTimer.startTimer () ;
    C_VDD newAllStates = allStatesSet ;
    for (int32_t i=0 ; i<inTransitionsCount ; i++) {
      const C_VDD newSource = newAllStates.getFirableFromAEDD (inPreConditions (i COMMA_HERE)) ;
      if (newSource != transitionSourceSet (i COMMA_HERE)) {
        transitionSourceSet (i COMMA_HERE) = newSource ;
        const C_VDD newTarget = newSource.computeTargetVector (inIncidenceVectors (i COMMA_HERE)) ;
        transitionTargetSet (i COMMA_HERE) = newTarget ;
        newAllStates |= newTarget ;
        if (inPrintIterationsStates) {
          gCout.appendString ("** Firable for ") ;
          gCout.appendString (inTransitionNames (i COMMA_HERE)) ;
          gCout.appendString (" :\n") ;
          newSource.printSet (gCout, inPlaceNames) ;
          gCout.appendString ("** Target for ") ;
          gCout.appendString (inTransitionNames (i COMMA_HERE)) ;
          gCout.appendString (" :\n") ;
          newTarget.printSet (gCout, inPlaceNames) ;
          gCout.flush () ;
        }
      }
    }
    iterationTimer.stopTimer () ;
  //--- Loop again ?
    loop = (newAllStates != allStatesSet) && (iteration != inLastIteration) ;
    allStatesSet = newAllStates ;
  //--- Print iteration characteristics
    if (! inDoNotPrintIterationsMessages) {
      gCout.appendString ("Iteration ") ;
      gCout.appendUnsigned (iteration) ;
      gCout.appendString (" : ") ;
      gCout.appendUnsigned (allStatesSet.getSetCardinal ());
      gCout.appendString (" states, bound : ") ;
      gCout.appendSigned (allStatesSet.getMaxValue ()) ;
      gCout.appendString (", max tokens ") ;
      gCout.appendSigned (allStatesSet.getMaxTokens ()) ;
      gCout.appendString (" (") ;
      gCout.appendString (iterationTimer.timeString ()) ;
      gCout.appendString (")\n") ;
      fflush (stdout) ;
     }
  }
  timer.stopTimer () ;
//--- Compute count list
  UpEnumerator_countList current (inCountList) ;
  while (current.hasCurrentObject ()) {
    auto p = (const cPtr_typePreconditionExpression *) current.current_mCondition (HERE).ptr () ;
    const C_AEDD aedd = p->buildAEDDexpression () ;
    const C_VDD s = allStatesSet.getFirableFromAEDD (aedd) ;
    const uint64_t c = s.getSetCardinal () ;
    gCout.appendString ("'") ;
    gCout.appendString (current.current_mName (HERE).mProperty_string.stringValue ()) ;
    gCout.appendString ("' : ") ;
    gCout.appendUnsigned (c) ;
    gCout.appendString (" state") ;
    gCout.appendString ((c > 1) ? "s" : "") ;
    gCout.appendString ("\n") ;
//    s.printSet (gCout, inPlaceNames) ;
    current.gotoNextObject () ;
  }
//--- Compute transition firing count
  if (inPrintTransitionsFiring) {
    gCout.appendString ("Transitions firing :\n") ;
//    uint64_t VDDtransitionsCount = 0 ;
    for (int32_t i=0 ; i<inTransitionsCount ; i++) {
      VDDtransitionsFiringCount (i COMMA_HERE) = transitionSourceSet (i COMMA_HERE).getSetCardinal () ;
//      VDDtransitionsCount += VDDtransitionsFiringCount (i COMMA_HERE) ;
      gCout.appendString ("  ") ;
      gCout.appendString (inTransitionNames (i COMMA_HERE)) ;
      gCout.appendString (" : ") ;
      gCout.appendUnsigned (VDDtransitionsFiringCount (i COMMA_HERE));
      gCout.appendString (" states in ") ;
      gCout.appendSigned (transitionSourceSet (i COMMA_HERE).getNodesCount ());
      gCout.appendString (" VDD nodes\n") ;
    }
  }
//--- Print min and max token for each place ?
  if (inPrintMinAndMax) {
  gCout.appendString ("---------------- Print min and max for each variable\n") ;
    TC_UniqueArray <int32_t> minToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    TC_UniqueArray <int32_t> maxToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    allStatesSet.computeMinAndMax (minToken, maxToken, inPlaceNames.count ()) ;
    for (int32_t i=0 ; i<inPlaceNames.count () ; i++) {
      gCout.appendString ("  Variable ") ;
      gCout.appendString (inPlaceNames (i COMMA_HERE)) ;
      gCout.appendString (" : min = ") ;
      gCout.appendSigned (minToken (i COMMA_HERE));
      gCout.appendString (", max = ") ;
      gCout.appendSigned (maxToken (i COMMA_HERE));
      gCout.appendString ("\n") ;
     }
     gCout.appendString ("\n") ;
  }
//--- Print nodes ?
  if (inPrintAllNodes) {
    gCout.appendString ("----------- Marking graph VDD nodes :\n") ;
    allStatesSet.printSetNodes (gCout, inPlaceNames) ;
  }
//--- Print states ?
  if (inPrintAllStates) {
    gCout.appendString ("Marking graph states :\n") ;
    allStatesSet.printSet (gCout, inPlaceNames) ;
  }
//--- Display  state count, transitions count, duration and used RAM size
  size_t ramSize = C_VDD::getCachesSizeInBytes () ;
  ramSize += C_VDD::getUniqueTableSizeInBytes () ;
  ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
  ramSize /= 1 << 20 ; // in Mb
  stateCount = allStatesSet.getSetCardinal () ;
  uint64_t VDDtransitionsCount = 0 ;
  for (int32_t i=0 ; i<inTransitionsCount ; i++) {
    VDDtransitionsCount += transitionSourceSet (i COMMA_HERE).getSetCardinal () ;
  }
  gCout.appendUnsigned (stateCount) ;
  gCout.appendString (" states (") ;
  gCout.appendSigned (allStatesSet.getNodesCount ());
  gCout.appendString (" nodes) reached in ") ;
  gCout.appendUnsigned (iteration) ;
  gCout.appendString (" iterations ;\n") ;
  gCout.appendUnsigned (VDDtransitionsCount) ;
  gCout.appendString (" transitions, used RAM : ") ;
  gCout.appendUnsigned (ramSize) ;
  gCout.appendString (" Mb.\n") ;
//    C_VDD::printVDDsummary (gCout) ;
  C_VDD::collectUnusedNodes () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//          vddComputationForSimultaneousFiring                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cComputationNode {
  public : int32_t mTransitionIndex ;
  public : C_VDD mInputSet ;
  public : C_VDD mFirableSet ;
  public : C_PCL mIncidenceVector ;
  public : bool mCanBeFired ;
  public : cComputationNode * mPtrToNotFirable ;
  public : cComputationNode * mPtrToFirable ;

  public : cComputationNode (void) ;

  public : virtual ~cComputationNode (void) ;

  private : cComputationNode (const cComputationNode &) ;
  private : cComputationNode & operator = (const cComputationNode &) ;
} ;

//---------------------------------------------------------------------------*

cComputationNode::cComputationNode (void) :
mTransitionIndex (0),
mInputSet (),
mFirableSet (),
mIncidenceVector (),
mCanBeFired (false),
mPtrToNotFirable (NULL),
mPtrToFirable (NULL) {
}

//---------------------------------------------------------------------------*

cComputationNode::~cComputationNode (void) {
  delete mPtrToNotFirable ;
  delete mPtrToFirable ;
}

//---------------------------------------------------------------------------*

static void
computeWithDecisionTree (cComputationNode * & ioDecisionTree,
                         C_VDD & ioAccessibleStates,
                         const int32_t inTransitionIndex,
                         const C_VDD & inInputSet,
                         const TC_UniqueArray <C_AEDD> & inPreConditions,
                         const TC_UniqueArray <C_PCL> & inIncidenceVectors,
                         TC_UniqueArray <bool> & ioFirableFlags) {
  if (inTransitionIndex < inPreConditions.count ()) {
  //--- Allocate decision tree if needed
    if (ioDecisionTree == NULL) {
      ioDecisionTree = new cComputationNode ;
      ioDecisionTree->mTransitionIndex = inTransitionIndex ;
      ioDecisionTree->mPtrToFirable = NULL ;
      ioDecisionTree->mPtrToNotFirable = NULL ;
      ioDecisionTree->mIncidenceVector = inIncidenceVectors (inTransitionIndex COMMA_HERE) ;
      ioDecisionTree->mCanBeFired = true ;
      for (int32_t i=0 ; (i<inTransitionIndex) && ioDecisionTree->mCanBeFired ; i++) {
        if (ioFirableFlags (i COMMA_HERE)) {
          ioDecisionTree->mCanBeFired = ioDecisionTree->mIncidenceVector.merge (inIncidenceVectors (i COMMA_HERE)) ;
        }
      }
    }
    if (ioDecisionTree->mCanBeFired) {
    //--- Compute new firable set
      const C_VDD newFirableSet = inInputSet.getFirableFromAEDD (inPreConditions (inTransitionIndex COMMA_HERE)) ;
    //--- Is new firable set different from previous one ?
      if (ioDecisionTree->mFirableSet != newFirableSet) {
      //--- Retain new firable set
        ioDecisionTree->mFirableSet = newFirableSet ;
      //--- Add fired set to accessible set
        const C_VDD newTarget = newFirableSet.computeTargetVector (ioDecisionTree->mIncidenceVector) ;
        ioAccessibleStates |= newTarget ;
      //---
        ioFirableFlags (inTransitionIndex COMMA_HERE) = true ;
        computeWithDecisionTree (ioDecisionTree->mPtrToFirable, ioAccessibleStates, inTransitionIndex+1, newFirableSet, inPreConditions, inIncidenceVectors, ioFirableFlags) ;
      }
    }
  //--- Is input set different from previous one ?
    if (ioDecisionTree->mInputSet != inInputSet) {
      ioDecisionTree->mInputSet = inInputSet ;
      ioFirableFlags (inTransitionIndex COMMA_HERE) = false ;
      computeWithDecisionTree (ioDecisionTree->mPtrToNotFirable, ioAccessibleStates, inTransitionIndex+1, inInputSet, inPreConditions, inIncidenceVectors, ioFirableFlags) ;
    }
  }
}

//---------------------------------------------------------------------------*

static void
printFiringCount (const cComputationNode * inDecisionTree,
                  const int32_t inTransitionIndex,
                  const TC_UniqueArray <String> & inPlaceNames,
                  const TC_UniqueArray <String> & inTransitionNames,
                  TC_UniqueArray <bool> & ioFirableFlags) {
  if (inDecisionTree != NULL) {
    if (inDecisionTree->mCanBeFired) {
      const uint64_t firingCount = inDecisionTree->mFirableSet.getSetCardinal () ;
      if (firingCount > 0) {
        gCout.appendString ("  ") ;
        for (int32_t i=0 ; i<inTransitionIndex ; i++) {
          if (ioFirableFlags (i COMMA_HERE)) {
            gCout.appendString (inTransitionNames (i COMMA_HERE)) ;
            gCout.appendString ("-") ;
          }
        }
        gCout.appendString (inTransitionNames (inTransitionIndex COMMA_HERE)) ;
        gCout.appendString (": ") ;
        gCout.appendUnsigned (firingCount);
        gCout.appendString (" states in ") ;
        gCout.appendSigned (inDecisionTree->mFirableSet.getNodesCount ());
        gCout.appendString (" VDD nodes\n") ;
      //---
        ioFirableFlags (inTransitionIndex COMMA_HERE) = true ;
        printFiringCount (inDecisionTree->mPtrToFirable, inTransitionIndex+1, inPlaceNames, inTransitionNames, ioFirableFlags) ;
      }
    }
  //--- Is input set different from previous one ?
    ioFirableFlags (inTransitionIndex COMMA_HERE) = false ;
    printFiringCount (inDecisionTree->mPtrToNotFirable, inTransitionIndex+1, inPlaceNames, inTransitionNames, ioFirableFlags) ;
  }
}

//---------------------------------------------------------------------------*

static uint64_t
transitionCount (const cComputationNode * inDecisionTree,
                 const int32_t inTransitionIndex) {
  uint64_t count = 0 ;
  if (inDecisionTree != NULL) {
    if (inDecisionTree->mCanBeFired) {
      count += inDecisionTree->mFirableSet.getSetCardinal () ;
    //---
      count += transitionCount (inDecisionTree->mPtrToFirable, inTransitionIndex+1) ;
    }
  //--- Is input set different from previous one ?
    count += transitionCount (inDecisionTree->mPtrToNotFirable, inTransitionIndex+1) ;
  }
  return count ;
}

//---------------------------------------------------------------------------*

static void
vddComputationForSimultaneousFiring (uint32_t inGarbagePeriod,
                const bool inDoNotPrintIterationsMessages,
                const bool inPrintTransitionsFiring,
                const bool inPrintAllNodes,
                const bool inPrintAllStates,
                const bool /* inPrintIterationsStates */,
                const bool inPrintMinAndMax,
                const String & /* inSourceFileName */,
                const int32_t inTransitionsCount,
                const C_VDD & inInitialMarking,
                const TC_UniqueArray <C_AEDD> & inPreConditions,
                const TC_UniqueArray <C_PCL> & inIncidenceVectors,
                const TC_UniqueArray <String> & inPlaceNames,
                const TC_UniqueArray <String> & inTransitionNames,
                const GGS_countList & inCountList,
                const uint32_t inLastIteration) {
  uint64_t stateCount = 0 ;
  TC_UniqueArray <uint64_t> VDDtransitionsFiringCount (inTransitionsCount, 0 COMMA_HERE) ;
  C_PCL::collectUnusedNodes () ;
  C_VDD allStatesSet = inInitialMarking ;
//--- Normalize garbage period
  if (inGarbagePeriod < 1) {
    inGarbagePeriod = 1 ; // Garbage every iteration
  }
//--------------- Computation with vector decision diagrams -----------------
   gCout.appendString ("Computation (simultaneous firings) with vector decision diagrams...\n") ;
   fflush (stdout) ;
//--- Decision tree
  cComputationNode * mDecisionTree = NULL ;
//--- Vector for maintaining firable transition set during tree traversing
  TC_UniqueArray <bool> firableFlags (inTransitionsCount, false COMMA_HERE) ;
//--- Loop ------------------------------
  Timer timer ;
  timer.startTimer () ;
  bool loop = true ;
  uint32_t iteration = 0 ;
  while (loop) {
    iteration ++ ;
  //--- Garbage ?
    if ((iteration % inGarbagePeriod) == 0) {
      Timer garbageTimer ;
      garbageTimer.startTimer () ;
      const size_t previousNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      C_VDD::collectUnusedNodes () ;
      const size_t newNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      size_t ramSize = C_VDD::getCachesSizeInBytes () ;
      ramSize += C_VDD::getUniqueTableSizeInBytes () ;
      ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
      ramSize /= 1 << 20 ;
      garbageTimer.stopTimer () ;
      if (! inDoNotPrintIterationsMessages) {
        gCout.appendString ("Garbage (RAM ") ;
        gCout.appendUnsigned (ramSize) ;
        gCout.appendString (" Mb) : ") ;
        gCout.appendUnsigned (previousNodeCount) ;
        gCout.appendString (" nodes -> ") ;
        gCout.appendUnsigned (newNodeCount) ;
        gCout.appendString (" (") ;
        gCout.appendString (garbageTimer.timeString ()) ;
        gCout.appendString (")\n") ;
        fflush (stdout) ;
      }
    }
  //--- Fire transitions
    Timer iterationTimer ;
    iterationTimer.startTimer () ;
    C_VDD newAllStates = allStatesSet ;
    computeWithDecisionTree (mDecisionTree, newAllStates, 0, allStatesSet, inPreConditions, inIncidenceVectors, firableFlags) ;
    iterationTimer.stopTimer () ;
  //--- Loop again ?
    loop = (newAllStates != allStatesSet) && (iteration != inLastIteration) ;
    allStatesSet = newAllStates ;
  //--- Print iteration characteristics
    if (! inDoNotPrintIterationsMessages) {
      gCout.appendString ("Iteration ") ;
      gCout.appendUnsigned (iteration) ;
      gCout.appendString (" : ") ;
      gCout.appendUnsigned (allStatesSet.getSetCardinal ());
      gCout.appendString (" states, bound : ") ;
      gCout.appendSigned (allStatesSet.getMaxValue ()) ;
      gCout.appendString (", max tokens ") ;
      gCout.appendSigned (allStatesSet.getMaxTokens ()) ;
      gCout.appendString (" (") ;
      gCout.appendString (iterationTimer.timeString ()) ;
      gCout.appendString (")\n") ;
      fflush (stdout) ;
     }
  }
  timer.stopTimer () ;
//--- Compute count list
  UpEnumerator_countList current (inCountList) ;
  while (current.hasCurrentObject ()) {
    auto p = (const cPtr_typePreconditionExpression *) current.current_mCondition (HERE).ptr () ;
    const C_AEDD aedd = p->buildAEDDexpression () ;
    const C_VDD s = allStatesSet.getFirableFromAEDD (aedd) ;
    const uint64_t c = s.getSetCardinal () ;
    gCout.appendString ("'") ;
    gCout.appendString (current.current_mName (HERE).mProperty_string.stringValue()) ;
    gCout.appendString ("' : ") ;
    gCout.appendUnsigned (c) ;
    gCout.appendString (" state") ;
    gCout.appendString ((c > 1) ? "s" : "") ;
    gCout.appendString ("\n") ;
//    s.printSet (gCout, inPlaceNames) ;
    current.gotoNextObject () ;
  }
//--- Compute transition firing count
  if (inPrintTransitionsFiring) {
    gCout.appendString ("Transitions firing :\n") ;
    printFiringCount (mDecisionTree, 0, inPlaceNames, inTransitionNames, firableFlags) ;
  }
//--- Print min and max token for each place ?
  if (inPrintMinAndMax) {
  gCout.appendString ("---------------- Print min and max for each variable\n") ;
    TC_UniqueArray <int32_t> minToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    TC_UniqueArray <int32_t> maxToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    allStatesSet.computeMinAndMax (minToken, maxToken, inPlaceNames.count ()) ;
    for (int32_t i=0 ; i<inPlaceNames.count () ; i++) {
      gCout.appendString ("  Variable ") ;
      gCout.appendString (inPlaceNames (i COMMA_HERE)) ;
      gCout.appendString (" : min = ") ;
      gCout.appendSigned (minToken (i COMMA_HERE));
      gCout.appendString (", max = ") ;
      gCout.appendSigned (maxToken (i COMMA_HERE));
      gCout.appendString ("\n") ;
     }
     gCout.appendString ("\n") ;
  }
//--- Print nodes ?
  if (inPrintAllNodes) {
    gCout.appendString ("----------- Marking graph VDD nodes :\n") ;
    allStatesSet.printSetNodes (gCout, inPlaceNames) ;
  }
//--- Print states ?
  if (inPrintAllStates) {
    gCout.appendString ("Marking graph states :\n") ;
    allStatesSet.printSet (gCout, inPlaceNames) ;
  }
//--- Display  state count, transitions count, duration and used RAM size
  size_t ramSize = C_VDD::getCachesSizeInBytes () ;
  ramSize += C_VDD::getUniqueTableSizeInBytes () ;
  ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
  ramSize /= 1 << 20 ; // in Mb
  stateCount = allStatesSet.getSetCardinal () ;
  const uint64_t VDDtransitionsCount = transitionCount (mDecisionTree, 0) ;
  gCout.appendUnsigned (stateCount) ;
  gCout.appendString (" states (") ;
  gCout.appendSigned (allStatesSet.getNodesCount ());
  gCout.appendString (" nodes) reached in ") ;
  gCout.appendUnsigned (iteration) ;
  gCout.appendString (" iterations ;\n") ;
  gCout.appendUnsigned (VDDtransitionsCount) ;
  gCout.appendString (" transitions, used RAM : ") ;
  gCout.appendUnsigned (ramSize) ;
  gCout.appendString (" Mb.\n") ;
//    C_VDD::printVDDsummary (gCout) ;
  delete mDecisionTree ;
  C_VDD::collectUnusedNodes () ;
}

/*--------------------------------------------------------------------------*/

void routine_generate_5F_code_3F__3F__3F__3F__3F__3F_ (const GGS_uint inHashMapSize,
                       const GGS_uint inGarbagePeriod,
                       const GGS_typeVarMap inPlacesMap,
                       const GGS_typeTransitionList inTransitionList,
                       const GGS_typeInitialMarkingList inInitialMarkingList,
                       const GGS_countList inCountList,
                       Compiler * inCompiler
                       COMMA_UNUSED_LOCATION_ARGS) {
  if (totalErrorCount () == 0) {
//   C_AEDD::changeHashMapSize (1000) ;
//  printf ("AEDD unique table size : %lu\n", C_AEDD::getHashMapEntriesCount ()) ;
//  printf ("AFTER_PARSING\n") ; fflush (stdout) ;
//--- Places count
  const int32_t placesCount = (int32_t) inPlacesMap.count () ;
//--- Transitions count
  const int32_t transitionsCount = (int32_t) inTransitionList.count () ;
//--- Build places names array
  TC_UniqueArray <String> placeNames (placesCount COMMA_HERE) ;
  UpEnumerator_typeVarMap current (inPlacesMap) ;
  while (current.hasCurrentObject ()) {
    placeNames.appendObject (current.current_lkey (HERE).mProperty_string.stringValue ()) ;
    current.gotoNextObject () ;
  }
//--- Build initial marking vdd
//  printf ("BUILD INITIAL MARKING ARRAY\n") ; fflush (stdout) ;
  C_VDD initialMarking ;
  initialMarking.setToNullSet () ;
  UpEnumerator_typeInitialMarkingList currentPlace (inInitialMarkingList) ;
  while (currentPlace.hasCurrentObject ()) {
    auto q = (const cPtr_typePostcondition *) currentPlace.current_mInitValue (HERE).ptr () ;
    q->buildInitialMarking (initialMarking) ;
    currentPlace.gotoNextObject () ;
  }
//--- Build transition name array, precondition expression array, post condition array
//  printf ("BUILD DATA FROM TRANSITIONS\n") ; fflush (stdout) ;
  TC_UniqueArray <String> transitionsNames (transitionsCount COMMA_HERE) ;
  TC_UniqueArray <C_AEDD> preconditionExp (transitionsCount, C_AEDD () COMMA_HERE) ;
  cPostConditionArray postcondition (transitionsCount, placesCount COMMA_HERE) ;
  TC_UniqueArray <uint32_t> lowBounds (transitionsCount COMMA_HERE) ;
  TC_UniqueArray <uint32_t> highBounds (transitionsCount COMMA_HERE) ;
  UpEnumerator_typeTransitionList currentTrans (inTransitionList) ;
  int32_t t = 0 ;
  while (currentTrans.hasCurrentObject ()) {
    lowBounds.appendObject (currentTrans.current_mLowTemporalBound (HERE).uintValue ()) ;
    highBounds.appendObject (currentTrans.current_mHighTemporalBound (HERE).uintValue ()) ;
    transitionsNames.appendObject (currentTrans.current_mTransitionName (HERE).mProperty_string.stringValue ()) ;
//    printf ("BUILD FROM TRANSITION '%s'\n", currentTrans->mTransitionName.cString ()) ; fflush (stdout) ;
    auto ptr = (const cPtr_typePreconditionExpression *) currentTrans.current_mPreconditionExpression (HERE).ptr () ;
    preconditionExp (t COMMA_HERE) = ptr->buildAEDDexpression () ;
    const uintptr_t nodesCount = preconditionExp (t COMMA_HERE).getAEDDnodesCount () ;
    if (nodesCount == 0) {
      gCout.appendString ("*** WARNING: NO AEDD NODES FOR '") ;
      gCout.appendString (currentTrans.current_mTransitionName (HERE).mProperty_string.stringValue()) ;
      gCout.appendString ("' TRANSITION ***\n") ;
      fflush (stdout) ;
    }
//    printf ("post expression\n") ; fflush (stdout) ;
    UpEnumerator_typePostconditionList p (currentTrans.current_mPostconditionList (HERE)) ;
    while (p.hasCurrentObject ()) {
      auto q = (const cPtr_typePostcondition *) p.current_mPostcondition (HERE).ptr () ;
      q->buildPostCondition (t, inCompiler, postcondition) ;
      p.gotoNextObject () ;
    }
    t ++ ;
    currentTrans.gotoNextObject () ;
  }
//--- Build post conditions lists
//  printf ("BUILD POST CONDITION LISTS\n") ; fflush (stdout) ;
  TC_UniqueArray <C_PCL> incidenceVectors (transitionsCount, C_PCL () COMMA_HERE) ;
  for (int32_t tt=0 ; tt<transitionsCount ; tt++) {
    for (int32_t p=0 ; p<placesCount ; p++) {
      incidenceVectors (tt COMMA_HERE).defineEntry ((T_vdd_zsl_index) p,
                                                   (T_vdd_zsl_value) postcondition (tt, p COMMA_HERE).mConstant,
                                                   postcondition (tt, p COMMA_HERE).mPost == ASSIGN_POST) ;
    }
  }
//--- Options values
  const bool printTransitionsFiring = gOption_spec_5F_options_printFiring.mValue ;
  const bool doNotPrintIterationsMessages = gOption_spec_5F_options_doNotPrintIteration.mValue ;
  const bool printAllNodes = gOption_spec_5F_options_printNodes.mValue ;
  const bool printAllStates = gOption_spec_5F_options_printStates.mValue ;
  const bool printPreConditions = gOption_spec_5F_options_printPreConditions.mValue ;
  const bool printInference = gOption_spec_5F_options_printInference.mValue ;
  const bool printTemporalBounds = gOption_spec_5F_options_printTemporalBounds.mValue ;
  const bool printIterationsStates = gOption_spec_5F_options_printIterationStates.mValue ;
  const bool printMinAndMax = gOption_spec_5F_options_printMinMax.mValue ;
  const uint32_t lastIteration = gOption_spec_5F_options_stopAfterIteration.mValue ;
//--- Fix VDD hasp map size
  C_VDD::reallocUniqueTable (1 << inHashMapSize.uintValue ()) ;
//--- Realloc VDD caches
  C_VDD::reallocCaches (1 << inHashMapSize.uintValue ()) ;
//--- Print input values
  gCout.appendString ("  ") ;
  gCout.appendSigned (placesCount) ;
  gCout.appendString (" variable") ;
  gCout.appendString ((placesCount > 1) ? "s" : "") ;
  gCout.appendString ("\n") ;
  gCout.appendString ("  ") ;
  gCout.appendSigned (transitionsCount) ;
  gCout.appendString (" transition") ;
  gCout.appendString ((transitionsCount > 1) ? "s" : "") ;
  gCout.appendString ("\n") ;
//--- Print Garbage period
  gCout.appendString ("  Garbage period : ") ;
  gCout.appendUnsigned (inGarbagePeriod.uintValue ()) ;
  gCout.appendString ("\n") ;
//--- VDD map
  gCout.appendString ("  VDD hash map parameter : ") ;
  gCout.appendUnsigned (inHashMapSize.uintValue ()) ;
  gCout.appendString (" -> ") ;
  gCout.appendUnsigned (C_VDD::getHashMapEntriesCount ()) ;
  gCout.appendString (" entries (") ;
  gCout.appendUnsigned ((uint32_t) (C_VDD::getMapSizeInBytes () / (1 << 20))) ;
  gCout.appendString (" Mb).\n") ;
//--- VDD map
  gCout.appendString ("  VDD operations cache hash maps parameter : ") ;
  gCout.appendUnsigned (inHashMapSize.uintValue ()) ;
  gCout.appendString (" -> ") ;
  gCout.appendUnsigned (C_VDD::getCachesSizeEntriesCount ());
  gCout.appendString (" entries (") ;
  gCout.appendUnsigned ((uint32_t) (C_VDD::getCachesSizeInBytes () / (1UL << 20))) ;
  gCout.appendString (" Mb).\n") ;
  fflush (stdout) ;
//--- Print preconditions
  if (printPreConditions) {
    gCout.appendString ("--------------- Precondition expressions :\n") ;
    for (int32_t i=0 ; i<transitionsCount ; i++) {
      const uintptr_t nodesCount = preconditionExp (i COMMA_HERE).getAEDDnodesCount () ;
      String s ;
      s.appendString ("Transition \"") ;
      s.appendString (transitionsNames (i COMMA_HERE)) ;
      s.appendString ("\" (") ;
      s.appendUnsigned (nodesCount) ;
      s.appendString (" node") ;
      s.appendString ((nodesCount > 1) ? "s" : "") ;
      s.appendString ("): ") ;
      preconditionExp (i COMMA_HERE).printAEDDnodes (s.cString ()) ;
    }
    UpEnumerator_countList currentCount (inCountList) ;
    while (currentCount.hasCurrentObject ()) {
      String s ;
      s.appendString ("Count \"") ;
      s.appendString (currentCount.current_mName (HERE).mProperty_string.stringValue()) ;
      s.appendString ("\" : ") ;
      auto q = (const cPtr_typePreconditionExpression *) currentCount.current_mCondition (HERE).ptr () ;
      const C_AEDD expr = q->buildAEDDexpression () ;
      expr.printAEDDnodes (s.cString ()) ;
      currentCount.gotoNextObject () ;
    }
    gCout.appendString ("\n") ;
  }
//--- Print post conditions
  if (printInference) {
    gCout.appendString ("--------------- Postcondition expressions :\n") ;
    for (int32_t tt=0 ; tt<transitionsCount ; tt++) {
      gCout.appendString ("\nTransition \"") ;
      gCout.appendString (transitionsNames (tt COMMA_HERE)) ;
      gCout.appendString ("\" : ") ;
      bool first = true ;
      for (int32_t p=0 ; p<placesCount ; p++) {
        const int32_t v = postcondition (tt, p COMMA_HERE).mConstant ;
        switch (postcondition (tt, p COMMA_HERE).mPost) {
        case UNDEFINED_POST :
          break ;
        case ASSIGN_POST :
          if (first) { first = false ; } else { gCout.appendString (", ") ; }
          gCout.appendString (placeNames (p COMMA_HERE)) ;
          gCout.appendString (" := ") ;
          gCout.appendSigned (v) ;
          break ;
        case INC_POST :
          if (first) { first = false ; } else { gCout.appendString (", ") ; }
          gCout.appendString (placeNames (p COMMA_HERE)) ;
          gCout.appendString (" += ") ;
          gCout.appendSigned (v) ;
          break ;
        }
      }
      gCout.appendString ("\n") ;
    }
    gCout.appendString ("\n") ;
  }
//--- Print temporal bounds
  if (printTemporalBounds) {
    gCout.appendString ("--------------- Temporal bounds :\n") ;
    for (int32_t tt=0 ; tt<transitionsCount ; tt++) {
      gCout.appendString ("  \"") ;
      gCout.appendString (transitionsNames (tt COMMA_HERE)) ;
      gCout.appendString ("\" : [") ;
      gCout.appendUnsigned (lowBounds (tt COMMA_HERE))  ;
      gCout.appendString (", ") ;
      gCout.appendUnsigned (highBounds (tt COMMA_HERE))  ;
      gCout.appendString ("]\n") ;
    }
  }
//--- Compute marking graph
  const bool computeSimultaneousFiring = gOption_spec_5F_options_computeSimultaneousFiring.mValue ;
  if (computeSimultaneousFiring) {
    vddComputationForSimultaneousFiring (inGarbagePeriod.uintValue (),
                    doNotPrintIterationsMessages,
                    printTransitionsFiring,
                    printAllNodes,
                    printAllStates,
                    printIterationsStates,
                    printMinAndMax,
                    inCompiler->sourceFilePath(),
                    transitionsCount,
                    initialMarking,
                    preconditionExp,
                    incidenceVectors,
                    placeNames,
                    transitionsNames,
                    inCountList,
                    lastIteration) ;
  }else{
    //Timer timer ;
    vddComputation (inGarbagePeriod.uintValue (),
                    doNotPrintIterationsMessages,
                    printTransitionsFiring,
                    printAllNodes,
                    printAllStates,
                    printIterationsStates,
                    printMinAndMax,
                    inCompiler->sourceFilePath (),
                    transitionsCount,
                    initialMarking,
                    preconditionExp,
                    incidenceVectors,
                    placeNames,
                    transitionsNames,
                    inCountList,
                    lastIteration) ;
      //timer.printTimer (stdout) ;
    }
  }
}

/*--------------------------------------------------------------------------*/

