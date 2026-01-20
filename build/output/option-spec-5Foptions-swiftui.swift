//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//--------------------------------------------------------------------------------------------------

import SwiftUI

//--------------------------------------------------------------------------------------------------

fileprivate let SELECTED_COMPILER_TOOL_INDEX_PREFKEY = "selected.compiler.tool.index"
fileprivate let doNotPrintIteration_PREFKEY = "spec_options:doNotPrintIteration"
fileprivate let computeSimultaneousFiring_PREFKEY = "spec_options:computeSimultaneousFiring"
fileprivate let printNodes_PREFKEY = "spec_options:printNodes"
fileprivate let printStates_PREFKEY = "spec_options:printStates"
fileprivate let printInference_PREFKEY = "spec_options:printInference"
fileprivate let printMinMax_PREFKEY = "spec_options:printMinMax"
fileprivate let printPreConditions_PREFKEY = "spec_options:printPreConditions"
fileprivate let printIterationStates_PREFKEY = "spec_options:printIterationStates"
fileprivate let printTemporalBounds_PREFKEY = "spec_options:printTemporalBounds"
fileprivate let printFiring_PREFKEY = "spec_options:printFiring"
fileprivate let stopAfterIteration_PREFKEY = "spec_options:stopAfterIteration"

//--------------------------------------------------------------------------------------------------
//   Options View
//--------------------------------------------------------------------------------------------------

struct OptionView : View {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private let mCompilerTools : [CompilerTool] = compilerTools ()
  @AppStorage(SELECTED_COMPILER_TOOL_INDEX_PREFKEY) private var mSelectedCompilerIndex = 0

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @AppStorage("prefix.by.time.utility") private var mPrefixByTimeUtility = false
  @State private var mCommandLine = compilerCommandExplained ()

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Bool options
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @AppStorage(doNotPrintIteration_PREFKEY) private var doNotPrintIteration : Bool = false
  @AppStorage(computeSimultaneousFiring_PREFKEY) private var computeSimultaneousFiring : Bool = false
  @AppStorage(printNodes_PREFKEY) private var printNodes : Bool = false
  @AppStorage(printStates_PREFKEY) private var printStates : Bool = false
  @AppStorage(printInference_PREFKEY) private var printInference : Bool = false
  @AppStorage(printMinMax_PREFKEY) private var printMinMax : Bool = false
  @AppStorage(printPreConditions_PREFKEY) private var printPreConditions : Bool = false
  @AppStorage(printIterationStates_PREFKEY) private var printIterationStates : Bool = false
  @AppStorage(printTemporalBounds_PREFKEY) private var printTemporalBounds : Bool = false
  @AppStorage(printFiring_PREFKEY) private var printFiring : Bool = false

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // UInt options
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @AppStorage(stopAfterIteration_PREFKEY) private var stopAfterIteration : UInt = 0

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // String options
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // String list options
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  // Body
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @ViewBuilder var body : some View {
    VStack {
      HStack {
        Picker("Compiler", selection: self.$mSelectedCompilerIndex) {
          ForEach (self.mCompilerTools, id: \.id) { tool in
            Text (tool.url.lastPathComponent).tag (tool.id)
          }
        }.pickerStyle (.automatic)
        Toggle ("Prefix by 'time' utility", isOn: self.$mPrefixByTimeUtility)
        Spacer ()
      }
      ScrollView {
        VStack (alignment: .leading) {
          Toggle ("do not print a message for every iteration", isOn: self.$doNotPrintIteration)
          Toggle ("perform simultaneous firing", isOn: self.$computeSimultaneousFiring)
          Toggle ("print accessibility set nodes", isOn: self.$printNodes)
          Toggle ("print accessibility states", isOn: self.$printStates)
          Toggle ("print inference expression for each transition", isOn: self.$printInference)
          Toggle ("print min and max value for each variable", isOn: self.$printMinMax)
          Toggle ("print precondition expression for each transition", isOn: self.$printPreConditions)
          Toggle ("print source and target states for each transition of every iteration", isOn: self.$printIterationStates)
          Toggle ("print temporal bounds for each transition", isOn: self.$printTemporalBounds)
          Toggle ("print transitions firing count", isOn: self.$printFiring)
          HStack { Text ("stop after performing given iterations (0 means never stop)") ; TextField ("", value: self.$stopAfterIteration, format: .number.precision (.fractionLength (0)))
        }.padding ()
      }.background (.white)
      HStack { Text ("Build Command") ; Spacer () }
      TextEditor (text: .constant (self.mCommandLine))
      .font (.system (size: 12).monospaced())
      .frame (height: 64)
    }.padding ()
    .onReceive (NotificationCenter.default.publisher (for: UserDefaults.didChangeNotification)) { _ in
      self.mCommandLine = compilerCommandExplained ()
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------

private func compilerCommandExplained () -> String {
  let command : CommandLineToolInvocation = commandLineToolInvocation ()
  var result = command.tool.lastPathComponent
  for arg in command.arguments {
    result += " " + arg
  }
  return result
}

//--------------------------------------------------------------------------------------------------

struct CommandLineToolInvocation {
  let tool : URL
  let arguments : [String]
}

//--------------------------------------------------------------------------------------------------

func commandLineToolInvocation () -> CommandLineToolInvocation {
  let ud = UserDefaults.standard
  let compilerTools : [CompilerTool] = compilerTools ()
  let selectedCompilerIndex : Int = ud.integer (forKey: SELECTED_COMPILER_TOOL_INDEX_PREFKEY)
  let tool = compilerTools [selectedCompilerIndex].url
  var arguments = [String] ()
  if ud.bool (forKey: doNotPrintIteration_PREFKEY) {
    arguments.append ("--do-not-print-iterations-message")
  }
  if ud.bool (forKey: computeSimultaneousFiring_PREFKEY) {
    arguments.append ("--simultaneous-firing")
  }
  if ud.bool (forKey: printNodes_PREFKEY) {
    arguments.append ("--print-nodes")
  }
  if ud.bool (forKey: printStates_PREFKEY) {
    arguments.append ("--print-states")
  }
  if ud.bool (forKey: printInference_PREFKEY) {
    arguments.append ("--print-inference")
  }
  if ud.bool (forKey: printMinMax_PREFKEY) {
    arguments.append ("--print-min-maxs")
  }
  if ud.bool (forKey: printPreConditions_PREFKEY) {
    arguments.append ("--print-preconditions")
  }
  if ud.bool (forKey: printIterationStates_PREFKEY) {
    arguments.append ("--print-iterations-states")
  }
  if ud.bool (forKey: printTemporalBounds_PREFKEY) {
    arguments.append ("--print-temporal-bounds")
  }
  if ud.bool (forKey: printFiring_PREFKEY) {
    arguments.append ("--print-transitions-firing-count")
  }
  do{
    let v : Int = ud.integer (forKey: stopAfterIteration_PREFKEY)
    if v != 0 {
      arguments.append ("--stop-after-iteration=" + String (v))
    }
  }
  return CommandLineToolInvocation (tool: tool, arguments: arguments)
}

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


