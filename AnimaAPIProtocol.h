//
//  AnimaAPI.h
//  AnimaPlugin
//
//  Created by mac on 3/26/18.
//  Copyright © 2018 Anima App. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>

@protocol AnimaAPIDelegate
/*!
 * An optional delegate object can be passed instead of a completion block.
 * In such case, it is required that the delegate object will implement this method to be notified when the process is finished.
 */
- (void)didFinishPreparingForExport:(NSDocument *)outputDocument outputPath:(NSString *)outputPath;
@end

@protocol AnimaAPI <NSObject>

/*!
 *  Takes in a document and returns whether or not the document has Anima properties such as Auto-Layout Pins or Stacks.
 *
 *  @param document a Sketch document of type NSDocument.
 *
 *  @return a boolean indicating the existense of Anima properties.
 */
+ (BOOL)doesDocumentHaveAnimaProperties:(NSDocument *)document;


/*!
 *  Takes in a document and duplicates it. Then strips out any Anima properties such as Pins or Stacks, and detaches symbols and writes the result document to outputPath.
 *
 *  @param inputDocument a Sketch document of type NSDocument.
 *
 *  @param outputPath the requested file path for the output duplicate file or nil if the reciever should determine the path.
 *
 *  @param artboardIDs if you want only specific artboards or nil if all artboards.
 *
 *  @param completionBlock a block that will run once the process is finished or nil if not needed.
 */
+ (void)prepareForExportWithInputDocument:(NSDocument *)inputDocument
                               outputPath:(NSString *)outputPath
                              artboardIDs:(NSArray <NSString *> *)artboardIDs
                          completionBlock:(void (^)(NSDocument *outputDocument, NSError *error))completionBlock;

@end

