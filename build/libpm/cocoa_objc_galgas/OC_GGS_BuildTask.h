//--------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//--------------------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

//--------------------------------------------------------------------------------------------------

@class OC_GGS_Document ;

//--------------------------------------------------------------------------------------------------

@interface OC_GGS_BuildTask : NSObject {
  @private NSTask * mTask ;
  @private NSPipe * mTaskOutputPipe ;

  @private BOOL mOutputBufferedDataHasBeenTransmitted ;

//  @private BOOL mTaskCompleted ;
  
  @private OC_GGS_Document * mDocument ;
}

- (id) initWithDocument: (OC_GGS_Document *) inDocument
       filePath: (NSString *) inFilePath
       isBuildRun: (BOOL) inIsBuildRun ;

- (void) terminate ;

@end

//--------------------------------------------------------------------------------------------------
