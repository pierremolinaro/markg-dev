//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "lexique-spec-5F-scanner-cocoa.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------
//            Unicode test functions                                                             
//----------------------------------------------------------------------------------------------------------------------
 
//----------------------------------------------------------------------------------------------------------------------

@implementation OC_Lexique_spec_scanner

//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Replacements                                               
//
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//
//                           Template Delimiters                                                 
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------

- (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_theString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_ulongValue = 0 ;
  }
  return self ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) dealloc {
  noteObjectDeallocation (self) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                 I N D E X I N G    D I R E C T O R Y                                          
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) indexingDirectory {
  return @"" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                 I N D E X I N G    T I T L E S                                                
//
//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) indexingTitles { // Array of NSString

  return [NSArray array] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark                                 
//
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'galgasKeyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

static const C_cocoa_lexique_table_entry ktable_for_spec_5F_scanner_galgasKeyWordList [12] = {
  {"end", spec_scanner_1_end},
  {"var", spec_scanner_1_var},
  {"init", spec_scanner_1_init},
  {"rule", spec_scanner_1_rule},
  {"true", spec_scanner_1_true},
  {"const", spec_scanner_1_const},
  {"count", spec_scanner_1_count},
  {"false", spec_scanner_1_false},
  {"system", spec_scanner_1_system},
  {"infinity", spec_scanner_1_infinity},
  {"hashmapsize", spec_scanner_1_hashmapsize},
  {"garbageperiod", spec_scanner_1_garbageperiod}
} ;

static NSInteger search_into_spec_5F_scanner_galgasKeyWordList (NSString * inSearchedString) {
  return searchStringInTable (inSearchedString, ktable_for_spec_5F_scanner_galgasKeyWordList, 12) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N                                         
//
//----------------------------------------------------------------------------------------------------------------------

- (void) parseLexicalTokenForLexicalColoring {
  mLoop = YES ;
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    mTokenStartLocation = mCurrentLocation ;
    [mLexicalAttribute_theString setString:@""] ;
    mLexicalAttribute_ulongValue = 0 ;
    mTokenStartLocation = mCurrentLocation ;
    if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90])) {
      do {
        scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_theString, mPreviousChar) ;
        if (scanningOk && ([self testForInputFromChar:97 toChar:122] || [self testForInputFromChar:65 toChar:90] || [self testForInputChar:95] || [self testForInputFromChar:48 toChar:57])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (mTokenCode == 0) {
        mTokenCode = search_into_spec_5F_scanner_galgasKeyWordList (mLexicalAttribute_theString) ;
      }
      if (mTokenCode == 0) {
        mTokenCode = spec_scanner_1_identifier ;
      }
    }else if (scanningOk && ([self testForInputChar:34])) {
      do {
        if (scanningOk && ([self testForInputChar:32] || [self testForInputChar:33] || [self testForInputFromChar:35 toChar:126])) {
          scanner_cocoa_routine_enterCharacterIntoString (& scanningOk, mLexicalAttribute_theString, mPreviousChar) ;
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      if (scanningOk && ([self testForInputChar:34])) {
        mTokenCode = spec_scanner_1_literal_5F_string ;
      }else{
        scanningOk = NO ;
      }
    }else if (scanningOk && [self testForInputString:@">=" advance:YES]) {
      mTokenCode = spec_scanner_1__3E__3D_ ;
    }else if (scanningOk && [self testForInputString:@"==" advance:YES]) {
      mTokenCode = spec_scanner_1__3D__3D_ ;
    }else if (scanningOk && [self testForInputString:@"<=" advance:YES]) {
      mTokenCode = spec_scanner_1__3C__3D_ ;
    }else if (scanningOk && [self testForInputString:@":=" advance:YES]) {
      mTokenCode = spec_scanner_1__3A__3D_ ;
    }else if (scanningOk && [self testForInputString:@"-=" advance:YES]) {
      mTokenCode = spec_scanner_1__2D__3D_ ;
    }else if (scanningOk && [self testForInputString:@"--" advance:YES]) {
      mTokenCode = spec_scanner_1__2D__2D_ ;
    }else if (scanningOk && [self testForInputString:@"+=" advance:YES]) {
      mTokenCode = spec_scanner_1__2B__3D_ ;
    }else if (scanningOk && [self testForInputString:@"++" advance:YES]) {
      mTokenCode = spec_scanner_1__2B__2B_ ;
    }else if (scanningOk && [self testForInputString:@"!=" advance:YES]) {
      mTokenCode = spec_scanner_1__21__3D_ ;
    }else if (scanningOk && [self testForInputString:@"~" advance:YES]) {
      mTokenCode = spec_scanner_1__7E_ ;
    }else if (scanningOk && [self testForInputString:@"}" advance:YES]) {
      mTokenCode = spec_scanner_1__7D_ ;
    }else if (scanningOk && [self testForInputString:@"|" advance:YES]) {
      mTokenCode = spec_scanner_1__7C_ ;
    }else if (scanningOk && [self testForInputString:@"{" advance:YES]) {
      mTokenCode = spec_scanner_1__7B_ ;
    }else if (scanningOk && [self testForInputString:@"]" advance:YES]) {
      mTokenCode = spec_scanner_1__5D_ ;
    }else if (scanningOk && [self testForInputString:@"[" advance:YES]) {
      mTokenCode = spec_scanner_1__5B_ ;
    }else if (scanningOk && [self testForInputString:@">" advance:YES]) {
      mTokenCode = spec_scanner_1__3E_ ;
    }else if (scanningOk && [self testForInputString:@"=" advance:YES]) {
      mTokenCode = spec_scanner_1__3D_ ;
    }else if (scanningOk && [self testForInputString:@"<" advance:YES]) {
      mTokenCode = spec_scanner_1__3C_ ;
    }else if (scanningOk && [self testForInputString:@";" advance:YES]) {
      mTokenCode = spec_scanner_1__3B_ ;
    }else if (scanningOk && [self testForInputString:@":" advance:YES]) {
      mTokenCode = spec_scanner_1__3A_ ;
    }else if (scanningOk && [self testForInputString:@"-" advance:YES]) {
      mTokenCode = spec_scanner_1__2D_ ;
    }else if (scanningOk && [self testForInputString:@"," advance:YES]) {
      mTokenCode = spec_scanner_1__2C_ ;
    }else if (scanningOk && [self testForInputString:@")" advance:YES]) {
      mTokenCode = spec_scanner_1__29_ ;
    }else if (scanningOk && [self testForInputString:@"(" advance:YES]) {
      mTokenCode = spec_scanner_1__28_ ;
    }else if (scanningOk && [self testForInputString:@"&" advance:YES]) {
      mTokenCode = spec_scanner_1__26_ ;
    }else if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
      scanner_cocoa_routine_enterDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_ulongValue) ;
      do {
        if (scanningOk && ([self testForInputFromChar:48 toChar:57])) {
          scanner_cocoa_routine_enterDigitIntoUInt (& scanningOk, mPreviousChar, & mLexicalAttribute_ulongValue) ;
        }else if (scanningOk && ([self testForInputChar:95])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
      mTokenCode = spec_scanner_1_literal_5F_integer ;
    }else if (scanningOk && ([self testForInputChar:35])) {
      do {
        if (scanningOk && ([self testForInputFromChar:1 toChar:9] || [self testForInputChar:11] || [self testForInputChar:12] || [self testForInputFromChar:14 toChar:65533])) {
        }else{
          mLoop = NO ;
        }
      }while (mLoop && scanningOk) ;
      mLoop = YES ;
    }else if (scanningOk && ([self testForInputFromChar:1 toChar:32])) {
    }else if ([self testForInputChar:'\0']) { // End of source text ? 
      mTokenCode = spec_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      scanningOk = NO ;
      [self advance] ;
    }
  //--- Error ?
    if (! scanningOk) {
      mTokenCode = -1 ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//                   T E R M I N A L    C O U N T                                                
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) terminalVocabularyCount {
  return 40 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                     S T Y L E   C O U N T                                                     
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleCount {
  return 6 ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                I S    T E M P L A T E    L E X I Q U E                                        
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) isTemplateLexique {
  return NO ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//
//----------------------------------------------------------------------------------------------------------------------

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal {
  static const NSUInteger kTerminalSymbolStyles [41] = {0,
    1 /* spec_scanner_1_identifier */,
    5 /* spec_scanner_1_literal_5F_string */,
    4 /* spec_scanner_1_literal_5F_integer */,
    2 /* spec_scanner_1_system */,
    2 /* spec_scanner_1_var */,
    2 /* spec_scanner_1_rule */,
    2 /* spec_scanner_1_init */,
    2 /* spec_scanner_1_end */,
    2 /* spec_scanner_1_true */,
    2 /* spec_scanner_1_false */,
    2 /* spec_scanner_1_const */,
    2 /* spec_scanner_1_count */,
    2 /* spec_scanner_1_infinity */,
    2 /* spec_scanner_1_hashmapsize */,
    2 /* spec_scanner_1_garbageperiod */,
    3 /* spec_scanner_1__3E__3D_ */,
    3 /* spec_scanner_1__3E_ */,
    3 /* spec_scanner_1__3C_ */,
    3 /* spec_scanner_1__3C__3D_ */,
    3 /* spec_scanner_1__3D__3D_ */,
    3 /* spec_scanner_1__21__3D_ */,
    3 /* spec_scanner_1__26_ */,
    3 /* spec_scanner_1__7C_ */,
    3 /* spec_scanner_1__7E_ */,
    3 /* spec_scanner_1__2C_ */,
    3 /* spec_scanner_1__3B_ */,
    3 /* spec_scanner_1__28_ */,
    3 /* spec_scanner_1__29_ */,
    3 /* spec_scanner_1__2B__2B_ */,
    3 /* spec_scanner_1__2D__2D_ */,
    3 /* spec_scanner_1__2B__3D_ */,
    3 /* spec_scanner_1__2D__3D_ */,
    3 /* spec_scanner_1__3A__3D_ */,
    3 /* spec_scanner_1__7B_ */,
    3 /* spec_scanner_1__7D_ */,
    3 /* spec_scanner_1__3A_ */,
    3 /* spec_scanner_1__2D_ */,
    3 /* spec_scanner_1__3D_ */,
    3 /* spec_scanner_1__5B_ */,
    3 /* spec_scanner_1__5D_ */
  } ;
  return kTerminalSymbolStyles [inTerminal] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    A T O M I C    S E L E C T I O N   F O R    T E R M I N A L                                
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex {
  static const BOOL kTerminalAtomicSelection [41] = {NO,
    YES /* spec_scanner_1_identifier */,
    NO /* spec_scanner_1_literal_5F_string */,
    YES /* spec_scanner_1_literal_5F_integer */,
    YES /* spec_scanner_1_system */,
    YES /* spec_scanner_1_var */,
    YES /* spec_scanner_1_rule */,
    YES /* spec_scanner_1_init */,
    YES /* spec_scanner_1_end */,
    YES /* spec_scanner_1_true */,
    YES /* spec_scanner_1_false */,
    YES /* spec_scanner_1_const */,
    YES /* spec_scanner_1_count */,
    YES /* spec_scanner_1_infinity */,
    YES /* spec_scanner_1_hashmapsize */,
    YES /* spec_scanner_1_garbageperiod */,
    YES /* spec_scanner_1__3E__3D_ */,
    YES /* spec_scanner_1__3E_ */,
    YES /* spec_scanner_1__3C_ */,
    YES /* spec_scanner_1__3C__3D_ */,
    YES /* spec_scanner_1__3D__3D_ */,
    YES /* spec_scanner_1__21__3D_ */,
    YES /* spec_scanner_1__26_ */,
    YES /* spec_scanner_1__7C_ */,
    YES /* spec_scanner_1__7E_ */,
    YES /* spec_scanner_1__2C_ */,
    YES /* spec_scanner_1__3B_ */,
    YES /* spec_scanner_1__28_ */,
    YES /* spec_scanner_1__29_ */,
    YES /* spec_scanner_1__2B__2B_ */,
    YES /* spec_scanner_1__2D__2D_ */,
    YES /* spec_scanner_1__2B__3D_ */,
    YES /* spec_scanner_1__2D__3D_ */,
    YES /* spec_scanner_1__3A__3D_ */,
    YES /* spec_scanner_1__7B_ */,
    YES /* spec_scanner_1__7D_ */,
    YES /* spec_scanner_1__3A_ */,
    YES /* spec_scanner_1__2D_ */,
    YES /* spec_scanner_1__3D_ */,
    YES /* spec_scanner_1__5B_ */,
    YES /* spec_scanner_1__5D_ */
  } ;
  return kTerminalAtomicSelection [inTokenIndex] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//             S T Y L E   N A M E    F O R    I N D E X                                         
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"Default Style",
      @"Identifiers",
      @"Key words",
      @"Delimitors",
      @"Integer constants",
      @"String constants"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//         S T Y L E   I D E N T I F I E R    F O R    I N D E X                                 
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex {
  NSString * result = nil ;
  if ((inIndex >= 0) && (inIndex < 6)) {
    NSString * kStyleArray [6] = {
      @"spec_scanner",
      @"spec_scanner-identifier",
      @"spec_scanner-keyWords",
      @"spec_scanner-delimitors",
      @"spec_scanner-integerStyle",
      @"spec_scanner-stringStyle"
    } ;
    result = kStyleArray [inIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//         L E X I Q U E   I D E N T I F I E R                                                   
//
//----------------------------------------------------------------------------------------------------------------------

- (NSString *) lexiqueIdentifier {
  return @"spec_scanner" ;
}

//----------------------------------------------------------------------------------------------------------------------

@end

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


