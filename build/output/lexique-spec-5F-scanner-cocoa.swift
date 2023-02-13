//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

import AppKit

//----------------------------------------------------------------------------------------------------------------------
//   LEXIQUE spec_scanner
//----------------------------------------------------------------------------------------------------------------------

fileprivate let gFont_spec_scanner = EBGenericPreferenceProperty <NSFont> (
  defaultValue: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular),
  prefKey: "FontFor_" + spec_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gLineHeight_spec_scanner = EBGenericPreferenceProperty <Int> (
  defaultValue: 12,
  prefKey: "LineHeightFor_" + spec_scanner_lexiqueIdentifier ()
)

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gColors_spec_scanner : [EBGenericPreferenceProperty <NSColor>] = [
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner-identifier"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner-keyWords"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner-delimitors"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner-integerStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .black, prefKey: "ColorFor_spec_scanner-stringStyle"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .red, prefKey: "ColorFor_spec_scanner_lexical_error"),
  EBGenericPreferenceProperty <NSColor> (defaultValue: .gray, prefKey: "ColorFor_spec_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gBoldStyle_spec_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner-identifier"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner-keyWords"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner-delimitors"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: true, prefKey: "BoldFor_spec_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "BoldFor_spec_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------

fileprivate let gItalicStyle_spec_scanner : [EBGenericPreferenceProperty <Bool>] = [
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner-identifier"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner-keyWords"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner-delimitors"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner-integerStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner-stringStyle"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner_lexical_error"),
  EBGenericPreferenceProperty <Bool> (defaultValue: false, prefKey: "ItalicFor_spec_scanner_template")
]

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters
//----------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//----------------------------------------------------------------------------------------------------------------------

let spec_scanner_1_ : UInt16 = 0
let spec_scanner_1_identifier : UInt16 = 1
let spec_scanner_1_literal_5F_string : UInt16 = 2
let spec_scanner_1_literal_5F_integer : UInt16 = 3
let spec_scanner_1_system : UInt16 = 4
let spec_scanner_1_var : UInt16 = 5
let spec_scanner_1_rule : UInt16 = 6
let spec_scanner_1_init : UInt16 = 7
let spec_scanner_1_end : UInt16 = 8
let spec_scanner_1_true : UInt16 = 9
let spec_scanner_1_false : UInt16 = 10
let spec_scanner_1_const : UInt16 = 11
let spec_scanner_1_count : UInt16 = 12
let spec_scanner_1_infinity : UInt16 = 13
let spec_scanner_1_hashmapsize : UInt16 = 14
let spec_scanner_1_garbageperiod : UInt16 = 15
let spec_scanner_1__3E__3D_ : UInt16 = 16
let spec_scanner_1__3E_ : UInt16 = 17
let spec_scanner_1__3C_ : UInt16 = 18
let spec_scanner_1__3C__3D_ : UInt16 = 19
let spec_scanner_1__3D__3D_ : UInt16 = 20
let spec_scanner_1__21__3D_ : UInt16 = 21
let spec_scanner_1__26_ : UInt16 = 22
let spec_scanner_1__7C_ : UInt16 = 23
let spec_scanner_1__7E_ : UInt16 = 24
let spec_scanner_1__2C_ : UInt16 = 25
let spec_scanner_1__3B_ : UInt16 = 26
let spec_scanner_1__28_ : UInt16 = 27
let spec_scanner_1__29_ : UInt16 = 28
let spec_scanner_1__2B__2B_ : UInt16 = 29
let spec_scanner_1__2D__2D_ : UInt16 = 30
let spec_scanner_1__2B__3D_ : UInt16 = 31
let spec_scanner_1__2D__3D_ : UInt16 = 32
let spec_scanner_1__3A__3D_ : UInt16 = 33
let spec_scanner_1__7B_ : UInt16 = 34
let spec_scanner_1__7D_ : UInt16 = 35
let spec_scanner_1__3A_ : UInt16 = 36
let spec_scanner_1__2D_ : UInt16 = 37
let spec_scanner_1__3D_ : UInt16 = 38
let spec_scanner_1__5B_ : UInt16 = 39
let spec_scanner_1__5D_ : UInt16 = 40
let spec_scanner_2_ERROR : UInt16 = 41
let spec_scanner_2_TEMPLATE : UInt16 = 42

//----------------------------------------------------------------------------------------------------------------------

func spec_scanner_lexiqueIdentifier () -> String {
  return "spec_scanner"
}

//----------------------------------------------------------------------------------------------------------------------

func spec_scanner_styleNameFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "Default Style", // 0
    "Identifiers", // 1
    "Key words", // 2
    "Delimitors", // 3
    "Integer constants", // 4
    "String constants", // 5
    "Lexical error", // 6
    "Template" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------

func spec_scanner_styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
  let kStyleArray : [String] = [
    "spec_scanner", // 0
    "spec_scanner-identifier", // 1
    "spec_scanner-keyWords", // 2
    "spec_scanner-delimitors", // 3
    "spec_scanner-integerStyle", // 4
    "spec_scanner-stringStyle", // 5
    "spec_scanner.ERROR", // 6
    "spec_scanner.TEMPLATE" // 7
  ]
  return kStyleArray [Int (inIndex)]
}

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class SWIFT_Lexique_spec_scanner : SWIFT_Lexique {

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_theString : String = ""
  private var mLexicalAttribute_ulongValue : UInt32 = 0

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return spec_scanner_lexiqueIdentifier ()
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 40
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var font : EBGenericPreferenceProperty <NSFont> { return gFont_spec_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var lineHeight : EBGenericPreferenceProperty <Int> { return gLineHeight_spec_scanner }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func color (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <NSColor> {
    return gColors_spec_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func bold (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gBoldStyle_spec_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func italic (forStyle inStyleIndex : UInt8) -> EBGenericPreferenceProperty <Bool> {
    return gItalicStyle_spec_scanner [Int (inStyleIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIndexFor (token inTokenIndex : UInt16) -> UInt8 {
    let kTerminalSymbolStyles : [UInt8] = [
      0, // Default
      1, // 1 : spec_scanner_1_identifier
      5, // 2 : spec_scanner_1_literal_5F_string
      4, // 3 : spec_scanner_1_literal_5F_integer
      2, // 4 : spec_scanner_1_system
      2, // 5 : spec_scanner_1_var
      2, // 6 : spec_scanner_1_rule
      2, // 7 : spec_scanner_1_init
      2, // 8 : spec_scanner_1_end
      2, // 9 : spec_scanner_1_true
      2, // 10 : spec_scanner_1_false
      2, // 11 : spec_scanner_1_const
      2, // 12 : spec_scanner_1_count
      2, // 13 : spec_scanner_1_infinity
      2, // 14 : spec_scanner_1_hashmapsize
      2, // 15 : spec_scanner_1_garbageperiod
      3, // 16 : spec_scanner_1__3E__3D_
      3, // 17 : spec_scanner_1__3E_
      3, // 18 : spec_scanner_1__3C_
      3, // 19 : spec_scanner_1__3C__3D_
      3, // 20 : spec_scanner_1__3D__3D_
      3, // 21 : spec_scanner_1__21__3D_
      3, // 22 : spec_scanner_1__26_
      3, // 23 : spec_scanner_1__7C_
      3, // 24 : spec_scanner_1__7E_
      3, // 25 : spec_scanner_1__2C_
      3, // 26 : spec_scanner_1__3B_
      3, // 27 : spec_scanner_1__28_
      3, // 28 : spec_scanner_1__29_
      3, // 29 : spec_scanner_1__2B__2B_
      3, // 30 : spec_scanner_1__2D__2D_
      3, // 31 : spec_scanner_1__2B__3D_
      3, // 32 : spec_scanner_1__2D__3D_
      3, // 33 : spec_scanner_1__3A__3D_
      3, // 34 : spec_scanner_1__7B_
      3, // 35 : spec_scanner_1__7D_
      3, // 36 : spec_scanner_1__3A_
      3, // 37 : spec_scanner_1__2D_
      3, // 38 : spec_scanner_1__3D_
      3, // 39 : spec_scanner_1__5B_
      3, // 40 : spec_scanner_1__5D_
      6, // 41 : spec_scanner_2_ERROR
      7  // 42 : spec_scanner_2_TEMPLATE
    ]
    return kTerminalSymbolStyles [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func atomicSelectionFor (token inTokenIndex : UInt16) -> Bool {
    let kTerminalAtomicSelection : [Bool] = [
      false, // Default
      true, // 1 : spec_scanner_1_identifier
      false, // 2 : spec_scanner_1_literal_5F_string
      true, // 3 : spec_scanner_1_literal_5F_integer
      true, // 4 : spec_scanner_1_system
      true, // 5 : spec_scanner_1_var
      true, // 6 : spec_scanner_1_rule
      true, // 7 : spec_scanner_1_init
      true, // 8 : spec_scanner_1_end
      true, // 9 : spec_scanner_1_true
      true, // 10 : spec_scanner_1_false
      true, // 11 : spec_scanner_1_const
      true, // 12 : spec_scanner_1_count
      true, // 13 : spec_scanner_1_infinity
      true, // 14 : spec_scanner_1_hashmapsize
      true, // 15 : spec_scanner_1_garbageperiod
      true, // 16 : spec_scanner_1__3E__3D_
      true, // 17 : spec_scanner_1__3E_
      true, // 18 : spec_scanner_1__3C_
      true, // 19 : spec_scanner_1__3C__3D_
      true, // 20 : spec_scanner_1__3D__3D_
      true, // 21 : spec_scanner_1__21__3D_
      true, // 22 : spec_scanner_1__26_
      true, // 23 : spec_scanner_1__7C_
      true, // 24 : spec_scanner_1__7E_
      true, // 25 : spec_scanner_1__2C_
      true, // 26 : spec_scanner_1__3B_
      true, // 27 : spec_scanner_1__28_
      true, // 28 : spec_scanner_1__29_
      true, // 29 : spec_scanner_1__2B__2B_
      true, // 30 : spec_scanner_1__2D__2D_
      true, // 31 : spec_scanner_1__2B__3D_
      true, // 32 : spec_scanner_1__2D__3D_
      true, // 33 : spec_scanner_1__3A__3D_
      true, // 34 : spec_scanner_1__7B_
      true, // 35 : spec_scanner_1__7D_
      true, // 36 : spec_scanner_1__3A_
      true, // 37 : spec_scanner_1__2D_
      true, // 38 : spec_scanner_1__3D_
      true, // 39 : spec_scanner_1__5B_
      true, // 40 : spec_scanner_1__5D_
      false, // 41 : spec_scanner_2_ERROR
      false  // 42 : spec_scanner_2_TEMPLATE
    ]
    return kTerminalAtomicSelection [Int (inTokenIndex)]
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func indexingDirectory () -> String {
    return ""
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func indexingTitles () -> [String] {

    return []
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //  S T Y L E S
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleCount () -> UInt8 {
    return 5
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return spec_scanner_styleNameFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return spec_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> SWIFT_Token {
    var loop = true
    var scanningOk = true
    self.mLexicalAttribute_theString = ""
    self.mLexicalAttribute_ulongValue = 0
    var tokenCode : UInt16 = 0
    let startLocation = self.currentLocation
    if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90)) {
      while (loop && scanningOk) {
        scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_theString, self.previousChar)
        if scanningOk && (self.testForInputFromChar (97, toChar:122) || self.testForInputFromChar (65, toChar:90) || self.testForInputChar (95) || self.testForInputFromChar (48, toChar:57)) {
        }else{
          loop = false
        }
      }
      loop = true
      if (tokenCode == 0) {
        tokenCode = search_into_spec_5F_scanner_galgasKeyWordList (mLexicalAttribute_theString) ;
      }
      if tokenCode == 0 {
        tokenCode = spec_scanner_1_identifier ;
      }
    }else if scanningOk && (self.testForInputChar (34)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputChar (32) || self.testForInputChar (33) || self.testForInputFromChar (35, toChar:126)) {
          scanner_cocoa_routine_enterCharacterIntoString (&scanningOk, &self.mLexicalAttribute_theString, self.previousChar)
        }else{
          loop = false
        }
      }
      loop = true
      if scanningOk && (self.testForInputChar (34)) {
        tokenCode = spec_scanner_1_literal_5F_string
      }else{
        scanningOk = false
      }
    }else if scanningOk && self.testForInputString (">=", advance: true) {
      tokenCode = spec_scanner_1__3E__3D_
    }else if scanningOk && self.testForInputString ("==", advance: true) {
      tokenCode = spec_scanner_1__3D__3D_
    }else if scanningOk && self.testForInputString ("<=", advance: true) {
      tokenCode = spec_scanner_1__3C__3D_
    }else if scanningOk && self.testForInputString (":=", advance: true) {
      tokenCode = spec_scanner_1__3A__3D_
    }else if scanningOk && self.testForInputString ("-=", advance: true) {
      tokenCode = spec_scanner_1__2D__3D_
    }else if scanningOk && self.testForInputString ("--", advance: true) {
      tokenCode = spec_scanner_1__2D__2D_
    }else if scanningOk && self.testForInputString ("+=", advance: true) {
      tokenCode = spec_scanner_1__2B__3D_
    }else if scanningOk && self.testForInputString ("++", advance: true) {
      tokenCode = spec_scanner_1__2B__2B_
    }else if scanningOk && self.testForInputString ("!=", advance: true) {
      tokenCode = spec_scanner_1__21__3D_
    }else if scanningOk && self.testForInputString ("~", advance: true) {
      tokenCode = spec_scanner_1__7E_
    }else if scanningOk && self.testForInputString ("}", advance: true) {
      tokenCode = spec_scanner_1__7D_
    }else if scanningOk && self.testForInputString ("|", advance: true) {
      tokenCode = spec_scanner_1__7C_
    }else if scanningOk && self.testForInputString ("{", advance: true) {
      tokenCode = spec_scanner_1__7B_
    }else if scanningOk && self.testForInputString ("]", advance: true) {
      tokenCode = spec_scanner_1__5D_
    }else if scanningOk && self.testForInputString ("[", advance: true) {
      tokenCode = spec_scanner_1__5B_
    }else if scanningOk && self.testForInputString (">", advance: true) {
      tokenCode = spec_scanner_1__3E_
    }else if scanningOk && self.testForInputString ("=", advance: true) {
      tokenCode = spec_scanner_1__3D_
    }else if scanningOk && self.testForInputString ("<", advance: true) {
      tokenCode = spec_scanner_1__3C_
    }else if scanningOk && self.testForInputString (";", advance: true) {
      tokenCode = spec_scanner_1__3B_
    }else if scanningOk && self.testForInputString (":", advance: true) {
      tokenCode = spec_scanner_1__3A_
    }else if scanningOk && self.testForInputString ("-", advance: true) {
      tokenCode = spec_scanner_1__2D_
    }else if scanningOk && self.testForInputString (",", advance: true) {
      tokenCode = spec_scanner_1__2C_
    }else if scanningOk && self.testForInputString (")", advance: true) {
      tokenCode = spec_scanner_1__29_
    }else if scanningOk && self.testForInputString ("(", advance: true) {
      tokenCode = spec_scanner_1__28_
    }else if scanningOk && self.testForInputString ("&", advance: true) {
      tokenCode = spec_scanner_1__26_
    }else if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
      scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (48, toChar:57)) {
          scanner_cocoa_routine_enterDigitIntoUInt (&scanningOk, self.previousChar, &self.mLexicalAttribute_ulongValue)
        }else if scanningOk && (self.testForInputChar (95)) {
        }else{
          loop = false
        }
      }
      loop = true
      tokenCode = spec_scanner_1_literal_5F_integer
    }else if scanningOk && (self.testForInputChar (35)) {
      while (loop && scanningOk) {
        if scanningOk && (self.testForInputFromChar (1, toChar:9) || self.testForInputChar (11) || self.testForInputChar (12) || self.testForInputFromChar (14, toChar:65533)) {
        }else{
          loop = false
        }
      }
      loop = true
    }else if scanningOk && (self.testForInputFromChar (1, toChar:32)) {
    }else if self.testForInputChar (0) { // End of source text ?
      tokenCode = spec_scanner_1_ ; // Empty string code
    }else{ // Unknown input character
      tokenCode = spec_scanner_2_TEMPLATE
      self.advance ()
    }
    return SWIFT_Token (
      range: NSRange (location: startLocation, length: self.currentLocation - startLocation),
      tokenCode: tokenCode,
      templateDelimiterIndex: self.mEndTemplateDelimiterIndex
    )
  }
  
  //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//----------------------------------------------------------------------------------------------------------------------

/* - (instancetype) init {
  self = [super init] ;
  if (self) {
    noteObjectAllocation (self) ;
    mLexicalAttribute_theString = [[NSMutableString alloc] init] ;
    mLexicalAttribute_ulongValue = 0 ;
  }
  return self ;
} */

//----------------------------------------------------------------------------------------------------------------------
//
//            Terminal Symbols as end of script in template mark
//
//----------------------------------------------------------------------------------------------------------------------

/*

*/


//----------------------------------------------------------------------------------------------------------------------
//
//             Key words table 'galgasKeyWordList'      
//
//----------------------------------------------------------------------------------------------------------------------

fileprivate func search_into_spec_5F_scanner_galgasKeyWordList (_ inSearchedString : String) -> UInt16 {
  let dictionary : [String : UInt16] = [
    "end" : spec_scanner_1_end,
    "var" : spec_scanner_1_var,
    "init" : spec_scanner_1_init,
    "rule" : spec_scanner_1_rule,
    "true" : spec_scanner_1_true,
    "const" : spec_scanner_1_const,
    "count" : spec_scanner_1_count,
    "false" : spec_scanner_1_false,
    "system" : spec_scanner_1_system,
    "infinity" : spec_scanner_1_infinity,
    "hashmapsize" : spec_scanner_1_hashmapsize,
    "garbageperiod" : spec_scanner_1_garbageperiod
  ]
  return dictionary [inSearchedString, default: spec_scanner_1_]
}





//----------------------------------------------------------------------------------------------------------------------
//
//               P A R S E    L E X I C A L    T O K E N
//
//----------------------------------------------------------------------------------------------------------------------

/* - (void) parseLexicalTokenForLexicalColoring {
  BOOL scanningOk = YES ;
  mTokenCode = 0 ;
  while ((mTokenCode == 0) && (mCurrentChar != '\0')) {
    scanningOk = [self internalParseLexicalTokenForLexicalColoring] ;
  }
//--- Error ?
  if (! scanningOk) {
    mTokenCode = -1 ;
  }
}

*/

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


