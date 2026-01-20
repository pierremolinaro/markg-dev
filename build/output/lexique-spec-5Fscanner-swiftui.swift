//--- START OF USER ZONE 1


//--- END OF USER ZONE 1
//--------------------------------------------------------------------------------------------------
//   LEXIQUE spec_scanner
//--------------------------------------------------------------------------------------------------

import SwiftUI

//--------------------------------------------------------------------------------------------------

struct SettingViewFor_spec_scanner : View {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  @AppStorage("FontFor_spec_scanner")
  private var mFont = CustomFont (nsFont: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular))

  @AppStorage("LineHeightFor_spec_scanner")
  private var mLineHeight : Int = 12

  @AppStorage("ColorFor_spec_scanner")
  private var mDefaultColor : Color = .black

  @AppStorage("ColorFor_spec_scanner-identifier")
  private var mColorFor_identifier : Color = .black

  @AppStorage("BoldFor_spec_scanner-identifier")
  private var mBoldFor_identifier : Bool = false

  @AppStorage("ItalicFor_spec_scanner-identifier")
  private var mItalicFor_identifier : Bool = false

  @AppStorage("ColorFor_spec_scanner-keyWords")
  private var mColorFor_keyWords : Color = .black

  @AppStorage("BoldFor_spec_scanner-keyWords")
  private var mBoldFor_keyWords : Bool = false

  @AppStorage("ItalicFor_spec_scanner-keyWords")
  private var mItalicFor_keyWords : Bool = false

  @AppStorage("ColorFor_spec_scanner-delimitors")
  private var mColorFor_delimitors : Color = .black

  @AppStorage("BoldFor_spec_scanner-delimitors")
  private var mBoldFor_delimitors : Bool = false

  @AppStorage("ItalicFor_spec_scanner-delimitors")
  private var mItalicFor_delimitors : Bool = false

  @AppStorage("ColorFor_spec_scanner-integerStyle")
  private var mColorFor_integerStyle : Color = .black

  @AppStorage("BoldFor_spec_scanner-integerStyle")
  private var mBoldFor_integerStyle : Bool = false

  @AppStorage("ItalicFor_spec_scanner-integerStyle")
  private var mItalicFor_integerStyle : Bool = false

  @AppStorage("ColorFor_spec_scanner-stringStyle")
  private var mColorFor_stringStyle : Color = .black

  @AppStorage("BoldFor_spec_scanner-stringStyle")
  private var mBoldFor_stringStyle : Bool = false

  @AppStorage("ItalicFor_spec_scanner-stringStyle")
  private var mItalicFor_stringStyle : Bool = false


  @AppStorage("ColorFor_spec_scanner_lexical_error")
  private var mColorFor_lexical_error : Color = .red

  @AppStorage("BoldFor_spec_scanner_lexical_error")
  private var mBoldFor_lexical_error : Bool = false

  @AppStorage("ItalicFor_spec_scanner_lexical_error")
  private var mItalicFor_lexical_error : Bool = false

  @AppStorage("ColorFor_spec_scanner_template")
  private var mColorFor_template : Color = .gray

  @AppStorage("BoldFor_spec_scanner_template")
  private var mBoldFor_template : Bool = false

  @AppStorage("ItalicFor_spec_scanner_template")
  private var mItalicFor_template : Bool = false

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  var body : some View {
    Form {
      LabeledContent ("Font") { CustomFontPicker (fontBinding: self.$mFont) }
      Picker("Line Height", selection: self.$mLineHeight) {
        Text("1.0").tag(10)
        Text("1.1").tag(11)
        Text("1.2").tag(12)
        Text("1.5").tag(15)
        Text("1.7").tag(17)
        Text("2.0").tag(20)
      }.pickerStyle(.automatic)
      ColorPicker ("Default Color", selection: self.$mDefaultColor)
      LabeledContent ("Identifiers") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_identifier).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_identifier)
          Toggle ("Italic", isOn: self.$mItalicFor_identifier)
        }
      }
      LabeledContent ("Key words") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_keyWords).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_keyWords)
          Toggle ("Italic", isOn: self.$mItalicFor_keyWords)
        }
      }
      LabeledContent ("Delimitors") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_delimitors).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_delimitors)
          Toggle ("Italic", isOn: self.$mItalicFor_delimitors)
        }
      }
      LabeledContent ("Integer constants") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_integerStyle).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_integerStyle)
          Toggle ("Italic", isOn: self.$mItalicFor_integerStyle)
        }
      }
      LabeledContent ("String constants") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_stringStyle).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_stringStyle)
          Toggle ("Italic", isOn: self.$mItalicFor_stringStyle)
        }
      }
      LabeledContent ("Lexical Error") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_lexical_error).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_lexical_error)
          Toggle ("Italic", isOn: self.$mItalicFor_lexical_error)
        }
      }
      LabeledContent ("Template") {
        HStack {
          ColorPicker ("", selection: self.$mColorFor_template).labelsHidden ()
          Toggle ("Bold", isOn: self.$mBoldFor_template)
          Toggle ("Italic", isOn: self.$mItalicFor_template)
        }
      }
    }.padding (20)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------

class ScannerFor_spec_scanner : AbstractScanner {

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private let mDebug = false
  private let mVerboseDebug = false
  private var mTokenArray = [LexicalToken] ()

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  final override func popUpDefinitionList () -> [[UInt16]] {
    return gPopUpData_spec_scanner
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  final override func blockComment () -> String? {
    return gBlockComment_spec_scanner
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func selectionRange (forProposedRange inProposedSelectionRange : NSRange,
                                granularity inGranularity : NSSelectionGranularity,
                                nsTextViewComputedRange inTextViewComputedRange : NSRange) -> NSRange {
    var result = inTextViewComputedRange
    switch inGranularity {
    case .selectByCharacter :
      ()
    case .selectByWord :
      var found = false
      var idx = 0
      while idx < self.mTokenArray.count, !found {
        let token = self.mTokenArray [idx]
        idx += 1
        let tokenRange = token.range
        found = ((tokenRange.location + tokenRange.length) > inProposedSelectionRange.location)
           && (tokenRange.location <= inProposedSelectionRange.location)
        if found, self.atomicSelectionFor (token: token.tokenCode) {
          result = tokenRange
        }
      }
    case .selectByParagraph :
      var found = false
      var idx = 0
      while idx < self.mTokenArray.count, !found {
        let token = self.mTokenArray [idx]
        idx += 1
        let tokenRange = token.range
        found = ((tokenRange.location + tokenRange.length) > inProposedSelectionRange.location)
           && (tokenRange.location <= inProposedSelectionRange.location)
        if found {
          result = tokenRange
        }
      }
    @unknown default:
      ()
    }
    return result
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Scanner
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  private var mLexicalAttribute_theString : String = ""
  private var mLexicalAttribute_ulongValue : UInt32 = 0

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func lexiqueIdentifier () -> String {
    return spec_scanner_lexiqueIdentifier ()
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func isTemplateLexique () -> Bool {
    return false
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func terminalVocabularyCount () -> Int {
    return 40
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func indexingTitles () -> [String] {

    return []
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //  S T Y L E S
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleCount () -> UInt8 {
    return 5
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleNameFor (styleIndex inIndex : UInt8) -> String {
    return spec_scanner_styleNameFor (styleIndex: inIndex)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func styleIdentifierFor (styleIndex inIndex : UInt8) -> String {
    return spec_scanner_styleIdentifierFor (styleIndex: inIndex)
  }

 // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  final var mFont = CustomFont (nsFont: NSFont.monospacedSystemFont (ofSize: 13.0, weight: .regular))
  final var mLineHeight : Int = 12
  final var mDefaultColor : Color = .black
  final var mColorFor_identifier : Color = .black
  final var mBoldFor_identifier : Bool = false
  final var mItalicFor_identifier : Bool = false
  final var mColorFor_keyWords : Color = .black
  final var mBoldFor_keyWords : Bool = false
  final var mItalicFor_keyWords : Bool = false
  final var mColorFor_delimitors : Color = .black
  final var mBoldFor_delimitors : Bool = false
  final var mItalicFor_delimitors : Bool = false
  final var mColorFor_integerStyle : Color = .black
  final var mBoldFor_integerStyle : Bool = false
  final var mItalicFor_integerStyle : Bool = false
  final var mColorFor_stringStyle : Color = .black
  final var mBoldFor_stringStyle : Bool = false
  final var mItalicFor_stringStyle : Bool = false
  final var mColorFor_lexical_error : Color = .red
  final var mBoldFor_lexical_error : Bool = false
  final var mItalicFor_lexical_error : Bool = false
  final var mColorFor_template : Color = .gray
  final var mBoldFor_template : Bool = false
  final var mItalicFor_template : Bool = false
  final var mTokenAttributeArray = [[NSAttributedString.Key : Any]?] ()

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func updateTokenStyleArrays (_ ioStyleDidChange : inout Bool) {
    ioStyleDidChange = false
    let ud = UserDefaults.standard
    if let s = ud.string (forKey: "FontFor_spec_scanner"), let v = CustomFont (rawValue: s) {
      if self.mFont != v {
        self.mFont = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "LineHeightFor_spec_scanner"), let v = Int (s) {
      if self.mLineHeight != v {
        self.mLineHeight = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner"), let v = Color (rawValue: s) {
      if self.mDefaultColor != v {
        self.mDefaultColor = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner-identifier"), let v = Color (rawValue: s) {
      if self.mColorFor_identifier != v {
        self.mColorFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner-identifier") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner-identifier")
      if self.mBoldFor_identifier != v {
        self.mBoldFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner-identifier") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner-identifier")
      if self.mItalicFor_identifier != v {
        self.mItalicFor_identifier = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner-keyWords"), let v = Color (rawValue: s) {
      if self.mColorFor_keyWords != v {
        self.mColorFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner-keyWords") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner-keyWords")
      if self.mBoldFor_keyWords != v {
        self.mBoldFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner-keyWords") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner-keyWords")
      if self.mItalicFor_keyWords != v {
        self.mItalicFor_keyWords = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner-delimitors"), let v = Color (rawValue: s) {
      if self.mColorFor_delimitors != v {
        self.mColorFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner-delimitors") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner-delimitors")
      if self.mBoldFor_delimitors != v {
        self.mBoldFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner-delimitors") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner-delimitors")
      if self.mItalicFor_delimitors != v {
        self.mItalicFor_delimitors = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner-integerStyle"), let v = Color (rawValue: s) {
      if self.mColorFor_integerStyle != v {
        self.mColorFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner-integerStyle") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner-integerStyle")
      if self.mBoldFor_integerStyle != v {
        self.mBoldFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner-integerStyle") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner-integerStyle")
      if self.mItalicFor_integerStyle != v {
        self.mItalicFor_integerStyle = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner-stringStyle"), let v = Color (rawValue: s) {
      if self.mColorFor_stringStyle != v {
        self.mColorFor_stringStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner-stringStyle") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner-stringStyle")
      if self.mBoldFor_stringStyle != v {
        self.mBoldFor_stringStyle = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner-stringStyle") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner-stringStyle")
      if self.mItalicFor_stringStyle != v {
        self.mItalicFor_stringStyle = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner_lexical_error"), let v = Color (rawValue: s) {
      if self.mColorFor_lexical_error != v {
        self.mColorFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner_lexical_error") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner_lexical_error")
      if self.mBoldFor_lexical_error != v {
        self.mBoldFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner_lexical_error") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner_lexical_error")
      if self.mItalicFor_lexical_error != v {
        self.mItalicFor_lexical_error = v
        ioStyleDidChange = true
      }
    }
    if let s = ud.string (forKey: "ColorFor_spec_scanner_template"), let v = Color (rawValue: s) {
      if self.mColorFor_template != v {
        self.mColorFor_template = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "BoldFor_spec_scanner_template") != nil {
      let v = ud.bool (forKey: "BoldFor_spec_scanner_template")
      if self.mBoldFor_template != v {
        self.mBoldFor_template = v
        ioStyleDidChange = true
      }
    }
    if ud.string (forKey: "ItalicFor_spec_scanner_template") != nil {
      let v = ud.bool (forKey: "ItalicFor_spec_scanner_template")
      if self.mItalicFor_template != v {
        self.mItalicFor_template = v
        ioStyleDidChange = true
      }
    }
  //--- Build token attribute array
    if ioStyleDidChange {
      let fontManager = NSFontManager.shared
      let boldFont = fontManager.convert (self.mFont.nsFont, toHaveTrait: .boldFontMask)
      let italicFont = fontManager.convert (self.mFont.nsFont, toHaveTrait: .italicFontMask)
      let boldItalicFont = fontManager.convert (boldFont, toHaveTrait: .italicFontMask)
      self.mTokenAttributeArray.removeAll (keepingCapacity: true)
      var attributes = [NSAttributedString.Key : Any] ()
    //--- Attributes for identifier
      if self.mColorFor_identifier != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_identifier)
      }
      if self.mBoldFor_identifier && self.mItalicFor_identifier {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_identifier {
        attributes [.font] = boldFont
      }else if self.mItalicFor_identifier {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for keyWords
      if self.mColorFor_keyWords != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_keyWords)
      }
      if self.mBoldFor_keyWords && self.mItalicFor_keyWords {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_keyWords {
        attributes [.font] = boldFont
      }else if self.mItalicFor_keyWords {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for delimitors
      if self.mColorFor_delimitors != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_delimitors)
      }
      if self.mBoldFor_delimitors && self.mItalicFor_delimitors {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_delimitors {
        attributes [.font] = boldFont
      }else if self.mItalicFor_delimitors {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for integerStyle
      if self.mColorFor_integerStyle != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_integerStyle)
      }
      if self.mBoldFor_integerStyle && self.mItalicFor_integerStyle {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_integerStyle {
        attributes [.font] = boldFont
      }else if self.mItalicFor_integerStyle {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Attributes for stringStyle
      if self.mColorFor_stringStyle != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_stringStyle)
      }
      if self.mBoldFor_stringStyle && self.mItalicFor_stringStyle {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_stringStyle {
        attributes [.font] = boldFont
      }else if self.mItalicFor_stringStyle {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Lexical error
      if self.mColorFor_lexical_error != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_lexical_error)
      }
      if self.mBoldFor_lexical_error && self.mItalicFor_lexical_error {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_lexical_error {
        attributes [.font] = boldFont
      }else if self.mItalicFor_lexical_error {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
      attributes.removeAll (keepingCapacity: true)
    //--- Template
      if self.mColorFor_template != self.mDefaultColor {
        attributes [.foregroundColor] = NSColor (self.mColorFor_template)
      }
      if self.mBoldFor_template && self.mItalicFor_template {
        attributes [.font] = boldItalicFont
      }else if self.mBoldFor_template {
        attributes [.font] = boldFont
      }else if self.mItalicFor_template {
        attributes [.font] = italicFont
      }
      self.mTokenAttributeArray.append (attributes.isEmpty ? nil : attributes)
    }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func performLexicalColoringAfterUserDefaultChange (textStorage inTextStorage : NSTextStorage) {
    if self.mDebug { Swift.print ("performLexicalColoringAfterUserDefaultChange") }
    let start = Date ()
    var styleDidChange = false
    self.updateTokenStyleArrays (&styleDidChange)
    if styleDidChange {
      let nsString = inTextStorage.string as NSString
      let fullRange = NSRange (location: 0, length: nsString.length)
    //---- Apply default attributes
      let tsDelegate : (any NSTextStorageDelegate)? = inTextStorage.delegate
      inTextStorage.delegate = nil // NSTextStorageDelegate
      inTextStorage.beginEditing ()
      let defaultFont = self.mFont.nsFont
      inTextStorage.font = defaultFont
      let ps = NSMutableParagraphStyle ()
      ps.lineHeightMultiple = CGFloat (self.mLineHeight) / 10.0
      let defaultAttributes : [NSAttributedString.Key : Any] = [
        .font: defaultFont,
        .foregroundColor: NSColor (self.mDefaultColor),
        .paragraphStyle : ps
      ]
      inTextStorage.setAttributes (defaultAttributes, range: fullRange)
    //--- Apply styles
      for token in self.mTokenArray {
        let idx = Int (self.styleIndexFor (token: token.tokenCode))
        if idx > 0, idx < (self.mTokenAttributeArray.count - 1), let attributes = self.mTokenAttributeArray [idx - 1] {
          inTextStorage.addAttributes (attributes, range: token.range)
        }
      }
      inTextStorage.endEditing ()
      inTextStorage.delegate = tsDelegate // NSTextStorageDelegate
    }
    if self.mDebug { Swift.print ("  done: \(Int (Date ().timeIntervalSince (start) * 1000.0)) ms") }
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  override func performLexicalAnalysisAndColoring (textStorage inTextStorage : NSTextStorage,
                                                   editedRange inEditedRange : NSRange,
                                                   changeInLength inDelta : Int,
                                                   popMenuItems ioPopupMenuItems : inout [IdentifiableAttributedString]) {
    if self.mDebug { Swift.print ("performLexicalAnalysisAndColoring \(inEditedRange), delta \(inDelta)") }
    let nsString = inTextStorage.string as NSString
  //---
    var savedTokenCount = 0
    var found = false
    while savedTokenCount < self.mTokenArray.count, !found {
      if self.mTokenArray [savedTokenCount].range.upperBound < inEditedRange.location {
        savedTokenCount += 1
      }else{
        found = true
      }
    }
    if self.mDebug { Swift.print ("  savedTokenCount \(savedTokenCount), currently \(self.mTokenArray.count) tokens") }
  //--- Eliminate tokens beyond end of source string
    while let lastToken = self.mTokenArray.last, lastToken.range.upperBound > nsString.length {
      if self.mVerboseDebug { Swift.print ("Remove last token \(lastToken.range), beyond end") }
      _ = self.mTokenArray.removeLast ()
    }
    if self.mDebug { Swift.print ("  Eliminate token beyond end: \(self.mTokenArray.count) tokens") }
  //--- Translater les tokens suivants
    var i = savedTokenCount + 1
    while i < self.mTokenArray.count {
      let token = self.mTokenArray [i]
      let newToken = LexicalToken (
        range: NSRange (location: token.range.location + inDelta, length: token.range.length),
        tokenCode: token.tokenCode,
        templateDelimiterIndex: token.templateDelimiterIndex
      )
      self.mTokenArray [i] = newToken
      i += 1
    }
  //--- Eliminate tokens beyond end of source string
    while let lastToken = self.mTokenArray.last, lastToken.range.upperBound > nsString.length {
      if self.mVerboseDebug { Swift.print ("Remove last token \(lastToken.range), beyond end") }
      _ = self.mTokenArray.removeLast ()
    }
    if self.mDebug { Swift.print ("  Eliminate token beyond end, after delta correction: \(self.mTokenArray.count) tokens") }
  //--- Perform lexical analysis
    let start = Date ()
    if savedTokenCount == 0 {
      self.resetScannerLocation (withString: nsString)
    }else{
      self.resetScanner (
        withString: nsString,
        location: self.mTokenArray [savedTokenCount-1].range.upperBound,
        templateDelimiterIndex : self.mTokenArray [savedTokenCount-1].templateDelimiterIndex
      )
    }
    if self.mDebug { Swift.print ("  Scanning start location: \(self.currentLocation)") }
    var stop = false
    var insertionIndex = savedTokenCount
    while self.currentLocation < nsString.length, !stop {
      let token : LexicalToken = self.parseLexicalTokenForLexicalColoring ()
      if token.tokenCode > 0 { // For eliminating separators
        if self.mVerboseDebug { Swift.print ("  -> new token \(token.range) '\(nsString.substring (with: token.range))'") }
      //--- Eliminate previous tokens before new token location
        if insertionIndex < self.mTokenArray.count,
              self.mTokenArray [insertionIndex] == token,
              token.range.location > inEditedRange.upperBound {
          if self.mVerboseDebug { Swift.print ("    stop at \(insertionIndex)") }
          stop = true
        }else{
          while insertionIndex < self.mTokenArray.count,
                self.mTokenArray [insertionIndex].range.lowerBound <= token.range.location {
            if self.mVerboseDebug { Swift.print ("    remove token \(self.mTokenArray [insertionIndex].range) at \(insertionIndex)") }
            self.mTokenArray.remove (at: insertionIndex)
          }
          if insertionIndex == self.mTokenArray.count {
            if self.mVerboseDebug { Swift.print ("    append token \(token.range) at \(insertionIndex)") }
            self.mTokenArray.append (token)
            insertionIndex += 1
          }else{
            if self.mVerboseDebug {  Swift.print ("    insert token \(token.range) at \(insertionIndex)") }
            self.mTokenArray.insert (token, at: insertionIndex)
            insertionIndex += 1
          }
        }
      }
    }
    if self.mDebug { Swift.print ("  Lexical analysis time: \(Int (Date ().timeIntervalSince (start) * 1000.0)) ms") }
  //---- Apply default attributes
    let modificationStart = min (inEditedRange.location, (savedTokenCount == 0)
      ? 0
      : self.mTokenArray [savedTokenCount - 1].range.upperBound)
    let modificationEnd = max (inEditedRange.upperBound, (insertionIndex == self.mTokenArray.count)
       ? nsString.length
       : self.mTokenArray [insertionIndex].range.upperBound
    )
    if self.mDebug { Swift.print ("  Attributes will change from char index \(modificationStart) to \(modificationEnd)") }
    let start2 = Date ()
    if modificationStart < modificationEnd {
      let modifiedRange = NSRange (location: modificationStart, length: modificationEnd - modificationStart)
      let tsDelegate : (any NSTextStorageDelegate)? = inTextStorage.delegate
      inTextStorage.delegate = nil // NSTextStorageDelegate
      inTextStorage.beginEditing ()
      let defaultFont = self.mFont.nsFont
      let ps = NSMutableParagraphStyle ()
      ps.lineHeightMultiple = CGFloat (self.mLineHeight) / 10.0
      let defaultAttributes : [NSAttributedString.Key : Any] = [
        .font: defaultFont,
        .foregroundColor: NSColor (self.mDefaultColor),
        .paragraphStyle : ps
      ]
      if self.mVerboseDebug { Swift.print ("Apply default attributes \(modifiedRange)") }
      inTextStorage.setAttributes (defaultAttributes, range: modifiedRange)
    //--- Apply styles
      var idx = 0
      stop = false
      while idx < self.mTokenArray.count, !stop { // Apply token styles
        let token = self.mTokenArray [idx]
        idx += 1
        if token.range.lowerBound >= modifiedRange.upperBound {
          stop = true
        }else if token.range.upperBound > modifiedRange.lowerBound {
          let styleIndex = Int (self.styleIndexFor (token: token.tokenCode))
          if styleIndex > 0, styleIndex < (self.mTokenAttributeArray.count - 1), let attributes = self.mTokenAttributeArray [styleIndex - 1] {
            inTextStorage.addAttributes (attributes, range: token.range)
          }
        }
      }
      inTextStorage.endEditing ()
      inTextStorage.delegate = tsDelegate // NSTextStorageDelegate
    }
    if self.mDebug { Swift.print ("  Adding attributes: \(Int (Date ().timeIntervalSince (start2) * 1000.0)) ms") }
    ioPopupMenuItems = self.updateEntryPopUpButtons (self.mTokenArray)
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
  //   Lexical analysis
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  func parseLexicalTokenForLexicalColoring () -> LexicalToken {
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
    return LexicalToken (
      range: NSRange (location: startLocation, length: self.currentLocation - startLocation),
      tokenCode: tokenCode,
      templateDelimiterIndex: self.mEndTemplateDelimiterIndex
    )
  }

  // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

}

//--------------------------------------------------------------------------------------------------
//             Key words table 'galgasKeyWordList'      
//--------------------------------------------------------------------------------------------------

fileprivate let kDictionary_spec_5F_scanner_galgasKeyWordList : [String : UInt16] = [
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

fileprivate func search_into_spec_5F_scanner_galgasKeyWordList (_ inSearchedString : String) -> UInt16 {
  return kDictionary_spec_5F_scanner_galgasKeyWordList [inSearchedString, default: spec_scanner_1_]
}



//--------------------------------------------------------------------------------------------------

func spec_scanner_lexiqueIdentifier () -> String {
  return "spec_scanner"
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------
//                           Template Replacements
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//                           Template Delimiters
//--------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


