//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//----------------------------------------------------------------------------------------------------------------------

#import "option-spec-5F-options-cocoa.h"
#import "OC_GGS_CommandLineOption.h"

//----------------------------------------------------------------------------------------------------------------------

void enterOptionsFor_spec_5F_options (NSMutableArray * ioBoolOptionArray,
                                      NSMutableArray * ioUIntOptionArray,
                                      NSMutableArray * ioStringOptionArray,
                                      NSMutableArray * ioStringListOptionArray) {
  OC_GGS_CommandLineOption * option ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"computeSimultaneousFiring"
    commandChar:0
    commandString:@"simultaneous-firing"
    comment:@"perform simultaneous firing"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"doNotPrintIteration"
    commandChar:68
    commandString:@"do-not-print-iterations-message"
    comment:@"do not print a message for every iteration"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printFiring"
    commandChar:102
    commandString:@"print-transitions-firing-count"
    comment:@"print transitions firing count"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printInference"
    commandChar:0
    commandString:@"print-inference"
    comment:@"print inference expression for each transition"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printIterationStates"
    commandChar:105
    commandString:@"print-iterations-states"
    comment:@"print source and target states for each transition of every iteration"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printMinMax"
    commandChar:112
    commandString:@"print-min-maxs"
    comment:@"print min and max value for each variable"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printNodes"
    commandChar:78
    commandString:@"print-nodes"
    comment:@"print accessibility set nodes"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printPreConditions"
    commandChar:80
    commandString:@"print-preconditions"
    comment:@"print precondition expression for each transition"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printStates"
    commandChar:83
    commandString:@"print-states"
    comment:@"print accessibility states"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"printTemporalBounds"
    commandChar:116
    commandString:@"print-temporal-bounds"
    comment:@"print temporal bounds for each transition"
    defaultValue:@""
  ] ;
  [ioBoolOptionArray addObject:option] ;
  option = [[OC_GGS_CommandLineOption alloc]
    initWithDomainName:@"spec_options"
    identifier:@"stopAfterIteration"
    commandChar:115
    commandString:@"stop-after-iteration"
    comment:@"stop after performing given iterations (0 means never stop)"
    defaultValue:@"0"
  ] ;
  [ioUIntOptionArray addObject:option] ;
}

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


