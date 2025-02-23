//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//--------------------------------------------------------------------------------------------------

func enterOptionsFor_spec_5F_options () -> [SWIFT_CommandLineOption] {
  var array = [SWIFT_CommandLineOption] ()
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "doNotPrintIteration",
    commandChar: "D",
    commandString: "do-not-print-iterations-message",
    comment: "do not print a message for every iteration"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "computeSimultaneousFiring",
    commandChar: "",
    commandString: "simultaneous-firing",
    comment: "perform simultaneous firing"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printNodes",
    commandChar: "N",
    commandString: "print-nodes",
    comment: "print accessibility set nodes"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printStates",
    commandChar: "S",
    commandString: "print-states",
    comment: "print accessibility states"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printInference",
    commandChar: "",
    commandString: "print-inference",
    comment: "print inference expression for each transition"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printMinMax",
    commandChar: "p",
    commandString: "print-min-maxs",
    comment: "print min and max value for each variable"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printPreConditions",
    commandChar: "P",
    commandString: "print-preconditions",
    comment: "print precondition expression for each transition"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printIterationStates",
    commandChar: "i",
    commandString: "print-iterations-states",
    comment: "print source and target states for each transition of every iteration"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printTemporalBounds",
    commandChar: "t",
    commandString: "print-temporal-bounds",
    comment: "print temporal bounds for each transition"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .bool,
    identifier: "printFiring",
    commandChar: "f",
    commandString: "print-transitions-firing-count",
    comment: "print transitions firing count"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    type: .uint,
    identifier: "stopAfterIteration",
    commandChar: "s",
    commandString: "stop-after-iteration",
    comment: "stop after performing given iterations (0 means never stop)"
  ))
  array.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    type: .bool,
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output"
  ))
  return array
}

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


