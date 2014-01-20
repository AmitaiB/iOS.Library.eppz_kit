//
//  UIImage+EPPZKit.m
//  eppz!kit
//
//  Created by Borbás Geri on 11/23/13.
//  Copyright (c) 2013 eppz! development, LLC.
//
//  donate! by following http://www.twitter.com/_eppz
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#import "UIImage+EPPZKit.h"

@implementation UIImage (EPPZKit)


-(void)saveToDocuments
{
    NSString *fileName = [NSString stringWithFormat:@"%@", @(self.hash)];
    [self saveToDocumentsWithFileName:fileName];
}

-(void)saveToDocumentsWithFileName:(NSString*) fileName
{ [self saveToDocumentsWithFileName:fileName format:UIImageFileFormatJPG]; }

-(void)saveToDocumentsWithFileName:(NSString*) fileName format:(UIImageFileFormat) format
{
    // Either JPG or PNG data.
    NSData *data = (format == UIImageFileFormatJPG) ? UIImageJPEGRepresentation(self, 1.0) : UIImagePNGRepresentation(self);
    NSString *extension = (format == UIImageFileFormatJPG) ? @"jpg" : @"png";
    NSString *path = [FILES pathForNewFileNameInDocumentsDirectory:[fileName stringByAppendingPathExtension:extension]];
    [data writeToFile:path atomically:YES];
}

-(void)saveToCache
{
    NSString *fileName = [NSString stringWithFormat:@"%@", @(self.hash)];
    [self saveToCacheWithFileName:fileName];
}

-(void)saveToCacheWithFileName:(NSString*) fileName
{ [self saveToCacheWithFileName:fileName format:UIImageFileFormatJPG]; }

-(void)saveToCacheWithFileName:(NSString*) fileName format:(UIImageFileFormat) format
{
    // Either JPG or PNG data.
    NSData *data = (format == UIImageFileFormatJPG) ? UIImageJPEGRepresentation(self, 1.0) : UIImagePNGRepresentation(self);
    NSString *extension = (format == UIImageFileFormatJPG) ? @"jpg" : @"png";
    NSString *path = [FILES pathForNewFileNameInCacheDirectory:[fileName stringByAppendingPathExtension:extension]];
    [data writeToFile:path atomically:YES];
}


@end
