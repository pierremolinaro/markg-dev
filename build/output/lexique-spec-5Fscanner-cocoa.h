//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "OC_Lexique.h"

//--------------------------------------------------------------------------------------------------
//
//                    E X T E R N    R O U T I N E S
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                    E X T E R N    F U N C T I O N S
//
//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//
//--------------------------------------------------------------------------------------------------

enum {spec_scanner_1_,
  spec_scanner_1_identifier,
  spec_scanner_1_literal_5F_string,
  spec_scanner_1_literal_5F_integer,
  spec_scanner_1_system,
  spec_scanner_1_var,
  spec_scanner_1_rule,
  spec_scanner_1_init,
  spec_scanner_1_end,
  spec_scanner_1_true,
  spec_scanner_1_false,
  spec_scanner_1_const,
  spec_scanner_1_count,
  spec_scanner_1_infinity,
  spec_scanner_1_hashmapsize,
  spec_scanner_1_garbageperiod,
  spec_scanner_1__3E__3D_,
  spec_scanner_1__3E_,
  spec_scanner_1__3C_,
  spec_scanner_1__3C__3D_,
  spec_scanner_1__3D__3D_,
  spec_scanner_1__21__3D_,
  spec_scanner_1__26_,
  spec_scanner_1__7C_,
  spec_scanner_1__7E_,
  spec_scanner_1__2C_,
  spec_scanner_1__3B_,
  spec_scanner_1__28_,
  spec_scanner_1__29_,
  spec_scanner_1__2B__2B_,
  spec_scanner_1__2D__2D_,
  spec_scanner_1__2B__3D_,
  spec_scanner_1__2D__3D_,
  spec_scanner_1__3A__3D_,
  spec_scanner_1__7B_,
  spec_scanner_1__7D_,
  spec_scanner_1__3A_,
  spec_scanner_1__2D_,
  spec_scanner_1__3D_,
  spec_scanner_1__5B_,
  spec_scanner_1__5D_
} ;

//--------------------------------------------------------------------------------------------------
//
//                     S C A N N E R    C L A S S
//
//--------------------------------------------------------------------------------------------------

@interface OC_Lexique_spec_scanner : OC_Lexique {
//--- Attributes
  @protected NSMutableString * mLexicalAttribute_theString ;
  @protected UInt32 mLexicalAttribute_ulongValue ;

}

- (NSUInteger) terminalVocabularyCount ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (BOOL) internalParseLexicalTokenForLexicalColoring ;

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleCount ;

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) isTemplateLexique ;

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;

@end

//--------------------------------------------------------------------------------------------------
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

