//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//--------------------------------------------------------------------------------------------------

func enterOptions (_ ioBoolOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioUIntOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringListOptionArray : inout [SWIFT_CommandLineOption]) {
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "computeSimultaneousFiring",
    commandChar: "",
    commandString: "simultaneous-firing",
    comment: "perform simultaneous firing",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "doNotPrintIteration",
    commandChar: "D",
    commandString: "do-not-print-iterations-message",
    comment: "do not print a message for every iteration",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printFiring",
    commandChar: "f",
    commandString: "print-transitions-firing-count",
    comment: "print transitions firing count",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printInference",
    commandChar: "",
    commandString: "print-inference",
    comment: "print inference expression for each transition",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printIterationStates",
    commandChar: "i",
    commandString: "print-iterations-states",
    comment: "print source and target states for each transition of every iteration",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printMinMax",
    commandChar: "p",
    commandString: "print-min-maxs",
    comment: "print min and max value for each variable",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printNodes",
    commandChar: "N",
    commandString: "print-nodes",
    comment: "print accessibility set nodes",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printPreConditions",
    commandChar: "P",
    commandString: "print-preconditions",
    comment: "print precondition expression for each transition",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printStates",
    commandChar: "S",
    commandString: "print-states",
    comment: "print accessibility states",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "printTemporalBounds",
    commandChar: "t",
    commandString: "print-temporal-bounds",
    comment: "print temporal bounds for each transition",
    defaultValue: ""
  ))
  ioUIntOptionArray.append (SWIFT_CommandLineOption (
    domainName: "spec_options",
    identifier: "stopAfterIteration",
    commandChar: "s",
    commandString: "stop-after-iteration",
    comment: "stop after performing given iterations (0 means never stop)",
    defaultValue: "0"
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output",
    defaultValue: ""
  ))
}

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


