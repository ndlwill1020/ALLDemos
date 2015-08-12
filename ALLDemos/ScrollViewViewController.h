//
//  ScrollViewViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/12.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ScrollViewViewController : UIViewController<UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UIScrollView *showScrollView;
@property (weak, nonatomic) IBOutlet UITextField *inputTextField;
@property (nonatomic,assign) BOOL isKeyBoardVisible;
@end
