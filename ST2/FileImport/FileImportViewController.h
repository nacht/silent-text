/*
Copyright (C) 2013-2015, Silent Circle, LLC. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Any redistribution, use, or modification is done solely for personal
      benefit and not for any commercial purpose or for monetary gain
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name Silent Circle nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL SILENT CIRCLE, LLC BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
//
//  FileImportViewController.h
//  ST2
//
//  Created by Vinnie Moscaritolo on 12/9/13.
//

#import <UIKit/UIKit.h>


@class FileImportViewController;
@class FileImportViewControllerDelegate;
@class Siren;

@protocol FileImportViewControllerDelegate <NSObject>

@required
- (void)scFileImportViewController:(FileImportViewController *)sender
          didFinishImportWithSiren:(Siren*)siren
                        fromUserID:(NSString*)uuid
                        recipients:(NSArray*)recpients
                             error:(NSError *)error;

@end


@interface FileImportViewController : UIViewController <UITableViewDataSource, UITableViewDelegate>

- (id)initWithURL:(NSURL*)inURL;
- (id)initWithURLs:(NSArray*)inURLs;

@property (nonatomic, strong) IBOutlet  UIView *fileInfoContainer;
@property (nonatomic, strong) IBOutlet UIView *segmentsContainer;
@property (nonatomic, strong) IBOutlet UIView *contactsContainer;


@property (nonatomic, strong) IBOutlet  UISegmentedControl  *contactSelectSegment;


@property (nonatomic, strong) IBOutlet  UIImageView *inputImage;
@property (nonatomic, strong) IBOutlet  UILabel* promptLabel;

@property (nonatomic, weak) IBOutlet UIButton *sendingUserButton;


@property (nonatomic, strong) IBOutlet UIBarButtonItem *sendButton;

@property (nonatomic, strong) IBOutlet UIView *horizontalRule;

- (IBAction)userChangedTapped:(id)sender;

- (IBAction)sendButtonAction:(id)sender;

@end
