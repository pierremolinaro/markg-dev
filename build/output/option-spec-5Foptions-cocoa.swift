//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//--------------------------------------------------------------------------------------------------

func enterOptions () -> [SWIFT_CommandLineOption] {
  var array = [SWIFT_CommandLineOption] ()
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "doNotPrintIteration",
    commandChar: "D",
    commandString: "do-not-print-iterations-message",
    comment: "do not print a message for every iteration",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "computeSimultaneousFiring",
    commandChar: "",
    commandString: "simultaneous-firing",
    comment: "perform simultaneous firing",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printNodes",
    commandChar: "N",
    commandString: "print-nodes",
    comment: "print accessibility set nodes",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printStates",
    commandChar: "S",
    commandString: "print-states",
    comment: "print accessibility states",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printInference",
    commandChar: "",
    commandString: "print-inference",
    comment: "print inference expression for each transition",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printMinMax",
    commandChar: "p",
    commandString: "print-min-maxs",
    comment: "print min and max value for each variable",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printPreConditions",
    commandChar: "P",
    commandString: "print-preconditions",
    comment: "print precondition expression for each transition",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printIterationStates",
    commandChar: "i",
    commandString: "print-iterations-states",
    comment: "print source and target states for each transition of every iteration",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printTemporalBounds",
    commandChar: "t",
    commandString: "print-temporal-bounds",
    comment: "print temporal bounds for each transition",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printFiring",
    commandChar: "f",
    commandString: "print-transitions-firing-count",
    comment: "print transitions firing count",
    defaultValue: ""
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .uint,
    identifier: "stopAfterIteration",
    commandChar: "s",
    commandString: "stop-after-iteration",
    comment: "stop after performing given iterations (0 means never stop)",
    defaultValue: "0"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    type: .bool,
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output",
    defaultValue: ""
  ))
  return array
}

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


