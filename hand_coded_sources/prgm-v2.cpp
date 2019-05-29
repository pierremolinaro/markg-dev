#include "spec_semantics.h"

/*--------------------------------------------------------------------------*/

#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "collections/TC_Array2.h"
#include "collections/TC_UniqueArray.h"
#include "streams/C_ConsoleOut.h"
#include "files/C_TextFileWrite.h"
#include "C_AEDD.h"
#include "C_PCL.h"
#include "C_VDD.h"
#include "time/C_Timer.h"
#include "spec_options.h"

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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost != UNDEFINED_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be assigned (has been already assigned or incremented)",
         TC_Array <C_FixItDescription> ()
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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost != UNDEFINED_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be assigned (has been already assigned or incremented)",
         TC_Array <C_FixItDescription> ()
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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be decremented (has been already assigned)",
         TC_Array <C_FixItDescription> ()
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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be incremented (has been already assigned)",
         TC_Array <C_FixItDescription> ()
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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be incremented (has been already assigned)",
         TC_Array <C_FixItDescription> ()
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
                    C_Compiler * inCompiler,
                    cPostConditionArray & ioPostCondition) const {
  const int32_t varIndex = (int32_t) mProperty_mVar.uintValue () ;
  if (ioPostCondition (inTransition, varIndex COMMA_HERE).mPost == ASSIGN_POST) {
    inCompiler->semanticErrorAtLocation (mProperty_mVarName.mProperty_location,
         "This variable cannot be decremented (has been already assigned)",
         TC_Array <C_FixItDescription> ()
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
  return ~ (mProperty_mExpression.ptr ()->buildAEDDexpression ()) ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeAndExpression::buildAEDDexpression (void) const {
  return mProperty_mLeftExpression.ptr ()->buildAEDDexpression () &
         mProperty_mRightExpression.ptr ()->buildAEDDexpression () ;
}

/*--------------------------------------------------------------------------*/

C_AEDD cPtr_typeOrExpression::buildAEDDexpression (void) const {
  return mProperty_mLeftExpression.ptr ()->buildAEDDexpression () |
         mProperty_mRightExpression.ptr ()->buildAEDDexpression () ;
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
                const C_String & /* inSourceFileName */,
                const int32_t inTransitionsCount,
                const C_VDD & inInitialMarking,
                const TC_UniqueArray <C_AEDD> & inPreConditions,
                const TC_UniqueArray <C_PCL> & inIncidenceVectors,
                const TC_UniqueArray <C_String> & inPlaceNames,
                const TC_UniqueArray <C_String> & inTransitionNames,
                const GALGAS_countList & inCountList,
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
   co << "Computation with vector decision diagrams...\n" ;
   fflush (stdout) ;
//--- Vector of transition source set
  TC_UniqueArray <C_VDD> transitionSourceSet (inTransitionsCount, C_VDD () COMMA_HERE) ;
//--- Vector of transition target set
  TC_UniqueArray <C_VDD> transitionTargetSet (inTransitionsCount, C_VDD () COMMA_HERE) ;
//--- Loop ------------------------------
  C_Timer timer ;
  timer.startTimer () ;
  bool loop = true ;
  uint32_t iteration = 0 ;
  while (loop) {
    iteration ++ ;
  //--- Garbage ?
    if ((iteration % inGarbagePeriod) == 0) {
      C_Timer garbageTimer ;
      garbageTimer.startTimer () ;
      const uint32_t previousNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      C_VDD::collectUnusedNodes () ;
      const uint32_t newNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      uint32_t ramSize = C_VDD::getCachesSizeInBytes () ;
      ramSize += C_VDD::getUniqueTableSizeInBytes () ;
      ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
      ramSize /= 1 << 20 ;
      garbageTimer.stopTimer () ;
      if (! inDoNotPrintIterationsMessages) {
        co << "Garbage (RAM " << cStringWithUnsigned (ramSize) << " Mb) : "
           << cStringWithUnsigned (previousNodeCount) << " nodes -> " << cStringWithUnsigned (newNodeCount) << " ("
           << garbageTimer << ")\n" ;
        fflush (stdout) ;
      }
    }
  //--- Fire transitions
    C_Timer iterationTimer ;
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
          co << "** Firable for " << inTransitionNames (i COMMA_HERE) << " :\n" ;
          newSource.printSet (co, inPlaceNames) ;
          co << "** Target for " << inTransitionNames (i COMMA_HERE) << " :\n" ;
          newTarget.printSet (co, inPlaceNames) ;
          co.flush () ;
        }
      }
    }
    iterationTimer.stopTimer () ;
  //--- Loop again ?
    loop = (newAllStates != allStatesSet) && (iteration != inLastIteration) ;
    allStatesSet = newAllStates ;
  //--- Print iteration characteristics
    if (! inDoNotPrintIterationsMessages) {
      co << "Iteration " << cStringWithUnsigned (iteration) << " : " << cStringWithUnsigned (allStatesSet.getSetCardinal ())
         << " states, bound : " << cStringWithSigned (allStatesSet.getMaxValue ()) << ", max tokens "
         << cStringWithSigned (allStatesSet.getMaxTokens ()) << " ("
         << iterationTimer
         << ")\n" ;
      fflush (stdout) ;
     }
  }
  timer.stopTimer () ;
//--- Compute count list
  cEnumerator_countList current (inCountList, kENUMERATION_UP) ;
  while (current.hasCurrentObject ()) {
    const C_AEDD aedd = current.current_mCondition (HERE).ptr ()->buildAEDDexpression () ;
    const C_VDD s = allStatesSet.getFirableFromAEDD (aedd) ;
    const uint64_t c = s.getSetCardinal () ;
    co << "'" << current.current_mName (HERE) << "' : " << cStringWithUnsigned (c) << " state" << ((c > 1) ? "s" : "") << "\n" ;
//    s.printSet (co, inPlaceNames) ;
    current.gotoNextObject () ;
  }
//--- Compute transition firing count
  if (inPrintTransitionsFiring) {
    co << "Transitions firing :\n" ;
    uint64_t VDDtransitionsCount = 0 ;
    for (int32_t i=0 ; i<inTransitionsCount ; i++) {
      VDDtransitionsFiringCount (i COMMA_HERE) = transitionSourceSet (i COMMA_HERE).getSetCardinal () ;
      VDDtransitionsCount += VDDtransitionsFiringCount (i COMMA_HERE) ;
      co << "  " << inTransitionNames (i COMMA_HERE) << " : "
         << cStringWithUnsigned (VDDtransitionsFiringCount (i COMMA_HERE))
         << " states in " << cStringWithSigned (transitionSourceSet (i COMMA_HERE).getNodesCount ())
         << " VDD nodes\n" ;
    }
  }
//--- Print min and max token for each place ?
  if (inPrintMinAndMax) {
  co << "---------------- Print min and max for each variable\n" ;
    TC_UniqueArray <int32_t> minToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    TC_UniqueArray <int32_t> maxToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    allStatesSet.computeMinAndMax (minToken, maxToken, inPlaceNames.count ()) ;
    for (int32_t i=0 ; i<inPlaceNames.count () ; i++) {
      co << "  Variable " << inPlaceNames (i COMMA_HERE)
         << " : min = " << cStringWithSigned (minToken (i COMMA_HERE))
         << ", max = " << cStringWithSigned (maxToken (i COMMA_HERE))
         << "\n" ;
     }
     co << "\n" ;
  }
//--- Print nodes ?
  if (inPrintAllNodes) {
    co << "----------- Marking graph VDD nodes :\n" ;
    allStatesSet.printSetNodes (co, inPlaceNames) ;
  }
//--- Print states ?
  if (inPrintAllStates) {
    co << "Marking graph states :\n" ;
    allStatesSet.printSet (co, inPlaceNames) ;
  }
//--- Display  state count, transitions count, duration and used RAM size
  uint32_t ramSize = C_VDD::getCachesSizeInBytes () ;
  ramSize += C_VDD::getUniqueTableSizeInBytes () ;
  ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
  ramSize /= 1 << 20 ; // in Mb
  stateCount = allStatesSet.getSetCardinal () ;
  uint64_t VDDtransitionsCount = 0 ;
  for (int32_t i=0 ; i<inTransitionsCount ; i++) {
    VDDtransitionsCount += transitionSourceSet (i COMMA_HERE).getSetCardinal () ;
  }
  co << cStringWithUnsigned (stateCount) << " states (" << cStringWithSigned (allStatesSet.getNodesCount ())
     << " nodes) reached in " << cStringWithUnsigned (iteration) << " iterations ;\n"
     << cStringWithUnsigned (VDDtransitionsCount) << " transitions, used RAM : " << cStringWithUnsigned (ramSize) << " Mb.\n" ;
//    C_VDD::printVDDsummary (co) ;
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
                  const TC_UniqueArray <C_String> & inPlaceNames,
                  const TC_UniqueArray <C_String> & inTransitionNames,
                  TC_UniqueArray <bool> & ioFirableFlags) {
  if (inDecisionTree != NULL) {
    if (inDecisionTree->mCanBeFired) {
      const uint64_t firingCount = inDecisionTree->mFirableSet.getSetCardinal () ;
      if (firingCount > 0) {
        co << "  " ;
        for (int32_t i=0 ; i<inTransitionIndex ; i++) {
          if (ioFirableFlags (i COMMA_HERE)) {
            co << inTransitionNames (i COMMA_HERE) << "-" ;
          }
        }
        co << inTransitionNames (inTransitionIndex COMMA_HERE) << ": "
           << cStringWithUnsigned (firingCount)
           << " states in " << cStringWithSigned (inDecisionTree->mFirableSet.getNodesCount ())
           << " VDD nodes\n" ;
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
                const C_String & /* inSourceFileName */,
                const int32_t inTransitionsCount,
                const C_VDD & inInitialMarking,
                const TC_UniqueArray <C_AEDD> & inPreConditions,
                const TC_UniqueArray <C_PCL> & inIncidenceVectors,
                const TC_UniqueArray <C_String> & inPlaceNames,
                const TC_UniqueArray <C_String> & inTransitionNames,
                const GALGAS_countList & inCountList,
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
   co << "Computation (simultaneous firings) with vector decision diagrams...\n" ;
   fflush (stdout) ;
//--- Decision tree
  cComputationNode * mDecisionTree = NULL ;
//--- Vector for maintaining firable transition set during tree traversing
  TC_UniqueArray <bool> firableFlags (inTransitionsCount, false COMMA_HERE) ;
//--- Loop ------------------------------
  C_Timer timer ;
  timer.startTimer () ;
  bool loop = true ;
  uint32_t iteration = 0 ;
  while (loop) {
    iteration ++ ;
  //--- Garbage ?
    if ((iteration % inGarbagePeriod) == 0) {
      C_Timer garbageTimer ;
      garbageTimer.startTimer () ;
      const uint32_t previousNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      C_VDD::collectUnusedNodes () ;
      const uint32_t newNodeCount = C_VDD::getCurrentVDDnodeCount () ;
      uint32_t ramSize = C_VDD::getCachesSizeInBytes () ;
      ramSize += C_VDD::getUniqueTableSizeInBytes () ;
      ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
      ramSize /= 1 << 20 ;
      garbageTimer.stopTimer () ;
      if (! inDoNotPrintIterationsMessages) {
        co << "Garbage (RAM " << cStringWithUnsigned (ramSize) << " Mb) : "
           << cStringWithUnsigned (previousNodeCount) << " nodes -> " << cStringWithUnsigned (newNodeCount) << " ("
           << garbageTimer << ")\n" ;
        fflush (stdout) ;
      }
    }
  //--- Fire transitions
    C_Timer iterationTimer ;
    iterationTimer.startTimer () ;
    C_VDD newAllStates = allStatesSet ;
    computeWithDecisionTree (mDecisionTree, newAllStates, 0, allStatesSet, inPreConditions, inIncidenceVectors, firableFlags) ;
    iterationTimer.stopTimer () ;
  //--- Loop again ?
    loop = (newAllStates != allStatesSet) && (iteration != inLastIteration) ;
    allStatesSet = newAllStates ;
  //--- Print iteration characteristics
    if (! inDoNotPrintIterationsMessages) {
      co << "Iteration " << cStringWithUnsigned (iteration) << " : " << cStringWithUnsigned (allStatesSet.getSetCardinal ())
         << " states, bound : " << cStringWithSigned (allStatesSet.getMaxValue ()) << ", max tokens "
         << cStringWithSigned (allStatesSet.getMaxTokens ()) << " ("
         << iterationTimer
         << ")\n" ;
      fflush (stdout) ;
     }
  }
  timer.stopTimer () ;
//--- Compute count list
  cEnumerator_countList current (inCountList, kENUMERATION_UP) ;
  while (current.hasCurrentObject ()) {
    const C_AEDD aedd = current.current_mCondition (HERE).ptr ()->buildAEDDexpression () ;
    const C_VDD s = allStatesSet.getFirableFromAEDD (aedd) ;
    const uint64_t c = s.getSetCardinal () ;
    co << "'" << current.current_mName (HERE) << "' : " << cStringWithUnsigned (c) << " state" << ((c > 1) ? "s" : "") << "\n" ;
//    s.printSet (co, inPlaceNames) ;
    current.gotoNextObject () ;
  }
//--- Compute transition firing count
  if (inPrintTransitionsFiring) {
    co << "Transitions firing :\n" ;
    printFiringCount (mDecisionTree, 0, inPlaceNames, inTransitionNames, firableFlags) ;
  }
//--- Print min and max token for each place ?
  if (inPrintMinAndMax) {
  co << "---------------- Print min and max for each variable\n" ;
    TC_UniqueArray <int32_t> minToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    TC_UniqueArray <int32_t> maxToken (inPlaceNames.count (), 0 COMMA_HERE) ;
    allStatesSet.computeMinAndMax (minToken, maxToken, inPlaceNames.count ()) ;
    for (int32_t i=0 ; i<inPlaceNames.count () ; i++) {
      co << "  Variable " << inPlaceNames (i COMMA_HERE)
         << " : min = " << cStringWithSigned (minToken (i COMMA_HERE))
         << ", max = " << cStringWithSigned (maxToken (i COMMA_HERE))
         << "\n" ;
     }
     co << "\n" ;
  }
//--- Print nodes ?
  if (inPrintAllNodes) {
    co << "----------- Marking graph VDD nodes :\n" ;
    allStatesSet.printSetNodes (co, inPlaceNames) ;
  }
//--- Print states ?
  if (inPrintAllStates) {
    co << "Marking graph states :\n" ;
    allStatesSet.printSet (co, inPlaceNames) ;
  }
//--- Display  state count, transitions count, duration and used RAM size
  uint32_t ramSize = C_VDD::getCachesSizeInBytes () ;
  ramSize += C_VDD::getUniqueTableSizeInBytes () ;
  ramSize += C_VDD::getSizeOf_cVDDmaxInfos_objects () ;
  ramSize /= 1 << 20 ; // in Mb
  stateCount = allStatesSet.getSetCardinal () ;
  const uint64_t VDDtransitionsCount = transitionCount (mDecisionTree, 0) ;
  co << cStringWithUnsigned (stateCount) << " states (" << cStringWithSigned (allStatesSet.getNodesCount ())
     << " nodes) reached in " << cStringWithUnsigned (iteration) << " iterations ;\n"
     << cStringWithUnsigned (VDDtransitionsCount) << " transitions, used RAM : " << cStringWithUnsigned (ramSize) << " Mb.\n" ;
//    C_VDD::printVDDsummary (co) ;
  delete mDecisionTree ;
  C_VDD::collectUnusedNodes () ;
}

/*--------------------------------------------------------------------------*/

void
routine_generate_5F_code (const GALGAS_uint inHashMapSize,
                       const GALGAS_uint inGarbagePeriod,
                       const GALGAS_typeVarMap inPlacesMap,
                       const GALGAS_typeTransitionList inTransitionList,
                       const GALGAS_typeInitialMarkingList inInitialMarkingList,
                       const GALGAS_countList inCountList,
                       C_Compiler * inCompiler
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
  TC_UniqueArray <C_String> placeNames (placesCount COMMA_HERE) ;
  cEnumerator_typeVarMap current (inPlacesMap, kENUMERATION_UP) ;
  while (current.hasCurrentObject ()) {
    placeNames.appendObject (current.current_lkey (HERE).mProperty_string.stringValue ()) ;
    current.gotoNextObject () ;
  }
//--- Build initial marking vdd
//  printf ("BUILD INITIAL MARKING ARRAY\n") ; fflush (stdout) ;
  C_VDD initialMarking ;
  initialMarking.setToNullSet () ;
  cEnumerator_typeInitialMarkingList currentPlace (inInitialMarkingList, kENUMERATION_UP) ;
  while (currentPlace.hasCurrentObject ()) {
    currentPlace.current_mInitValue (HERE).ptr ()->buildInitialMarking (initialMarking) ;
    currentPlace.gotoNextObject () ;
  }
//--- Build transition name array, precondition expression array, post condition array
//  printf ("BUILD DATA FROM TRANSITIONS\n") ; fflush (stdout) ;
  TC_UniqueArray <C_String> transitionsNames (transitionsCount COMMA_HERE) ;
  TC_UniqueArray <C_AEDD> preconditionExp (transitionsCount, C_AEDD () COMMA_HERE) ;
  cPostConditionArray postcondition (transitionsCount, placesCount COMMA_HERE) ;
  TC_UniqueArray <uint32_t> lowBounds (transitionsCount COMMA_HERE) ;
  TC_UniqueArray <uint32_t> highBounds (transitionsCount COMMA_HERE) ;
  cEnumerator_typeTransitionList currentTrans (inTransitionList, kENUMERATION_UP) ;
  int32_t t = 0 ;
  while (currentTrans.hasCurrentObject ()) {
    lowBounds.appendObject (currentTrans.current_mLowTemporalBound (HERE).uintValue ()) ;
    highBounds.appendObject (currentTrans.current_mHighTemporalBound (HERE).uintValue ()) ;
    transitionsNames.appendObject (currentTrans.current_mTransitionName (HERE).mProperty_string.stringValue ()) ;
//    printf ("BUILD FROM TRANSITION '%s'\n", currentTrans->mTransitionName.cString ()) ; fflush (stdout) ;
    preconditionExp (t COMMA_HERE) = currentTrans.current_mPreconditionExpression (HERE).ptr ()->buildAEDDexpression () ;
    const uintptr_t nodesCount = preconditionExp (t COMMA_HERE).getAEDDnodesCount () ;
    if (nodesCount == 0) {
      co << "*** WARNING: NO AEDD NODES FOR '" << currentTrans.current_mTransitionName (HERE) << "' TRANSITION ***\n" ;
      fflush (stdout) ;
    }
//    printf ("post expression\n") ; fflush (stdout) ;
    cEnumerator_typePostconditionList p (currentTrans.current_mPostconditionList (HERE), kENUMERATION_UP) ;
    while (p.hasCurrentObject ()) {
      p.current_mPostcondition (HERE).ptr ()->buildPostCondition (t, inCompiler, postcondition) ;
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
  co << "  " << cStringWithSigned (placesCount) << " variable" << ((placesCount > 1) ? "s" : "") << "\n" ;
  co << "  " << cStringWithSigned (transitionsCount) << " transition" << ((transitionsCount > 1) ? "s" : "") << "\n" ;
//--- Print Garbage period
  co << "  Garbage period : " << cStringWithUnsigned (inGarbagePeriod.uintValue ()) << "\n" ;
//--- VDD map
  co << "  VDD hash map parameter : " << cStringWithUnsigned (inHashMapSize.uintValue ()) << " -> " << cStringWithSigned (C_VDD::getHashMapEntriesCount ())
     << " entries (" << cStringWithUnsigned ((uint32_t) (C_VDD::getMapSizeInBytes () / (1 << 20))) << " Mb).\n" ;
//--- VDD map
  co << "  VDD operations cache hash maps parameter : " << cStringWithUnsigned (inHashMapSize.uintValue ()) << " -> " << cStringWithSigned (C_VDD::getCachesSizeEntriesCount ())
     << " entries (" << cStringWithUnsigned ((uint32_t) (C_VDD::getCachesSizeInBytes () / (1UL << 20))) << " Mb).\n" ;
  fflush (stdout) ;
//--- Print preconditions
  if (printPreConditions) {
    co << "--------------- Precondition expressions :\n" ;
    for (int32_t i=0 ; i<transitionsCount ; i++) {
      const uintptr_t nodesCount = preconditionExp (i COMMA_HERE).getAEDDnodesCount () ;
      C_String s ;
      s << "Transition \"" << transitionsNames (i COMMA_HERE) << "\" ("
        << cStringWithUnsigned (nodesCount) << " node" << ((nodesCount > 1) ? "s" : "") << "): " ;
      preconditionExp (i COMMA_HERE).printAEDDnodes (s.cString (HERE)) ;
    }
    cEnumerator_countList currentCount (inCountList, kENUMERATION_UP) ;
    while (currentCount.hasCurrentObject ()) {
      C_String s ;
      s << "Count \"" << currentCount.current_mName (HERE) << "\" : " ;
      const C_AEDD expr = currentCount.current_mCondition (HERE).ptr ()->buildAEDDexpression () ;
      expr.printAEDDnodes (s.cString (HERE)) ;
      currentCount.gotoNextObject () ;
    }
    co << "\n" ;
  }
//--- Print post conditions
  if (printInference) {
    co << "--------------- Postcondition expressions :\n" ;
    for (int32_t tt=0 ; tt<transitionsCount ; tt++) {
      co << "\nTransition \"" << transitionsNames (tt COMMA_HERE) << "\" : " ;
      bool first = true ;
      for (int32_t p=0 ; p<placesCount ; p++) {
        const int32_t v = postcondition (tt, p COMMA_HERE).mConstant ;
        switch (postcondition (tt, p COMMA_HERE).mPost) {
        case UNDEFINED_POST :
          break ;
        case ASSIGN_POST :
          if (first) { first = false ; } else { co << ", " ; }
          co << placeNames (p COMMA_HERE) << " := " << cStringWithSigned (v) ;
          break ;
        case INC_POST :
          if (first) { first = false ; } else { co << ", " ; }
          co << placeNames (p COMMA_HERE) << " += " << cStringWithSigned (v) ;
          break ;
        }
      }
      co << "\n" ;
    }
    co << "\n" ;
  }
//--- Print temporal bounds
  if (printTemporalBounds) {
    co << "--------------- Temporal bounds :\n" ;
    for (int32_t tt=0 ; tt<transitionsCount ; tt++) {
      co << "  \"" << transitionsNames (tt COMMA_HERE) << "\" : ["
         << cStringWithUnsigned (lowBounds (tt COMMA_HERE)) << ", "
         << cStringWithUnsigned (highBounds (tt COMMA_HERE)) << "]\n" ;
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
    //C_Timer timer ;
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

