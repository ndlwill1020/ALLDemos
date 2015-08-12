//
//  ScrollViewViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/12.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "ScrollViewViewController.h"

@interface ScrollViewViewController ()

@end

@implementation ScrollViewViewController

- (void)viewDidLoad {
    NSLog(@"viewDidLoad");
    [super viewDidLoad];
    self.showScrollView.contentSize = CGSizeMake(320, 700);
    self.isKeyBoardVisible = NO;
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardDidShow:) name:UIKeyboardDidShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardDidHide:) name:UIKeyboardDidHideNotification object:nil];
}

- (void)viewDidAppear:(BOOL)animated
{
    NSLog(@"viewDidAppear");
    [self.showScrollView setContentOffset:CGPointMake(0, 110) animated:YES];
    [super viewDidAppear:YES];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

- (void)keyboardDidShow:(NSNotification *)notifiction
{
    NSLog(@"keyboardDidShow");
    if (_isKeyBoardVisible) {
        return;
    }
    //􏺦􏺧键盘􏺨􏺩
    NSDictionary* info = notifiction.userInfo;
    NSValue* value = [info objectForKey:UIKeyboardFrameEndUserInfoKey];
    CGSize keyboardSize = [value CGRectValue].size;
    //重新定义ScrollView的􏺨􏺩
    CGRect viewFrame = self.showScrollView.frame;
    viewFrame.size.height -= keyboardSize.height;
    self.showScrollView.frame = viewFrame;
    //􏺪动到当􏺫文本框
    CGRect textFieldRect = self.inputTextField.frame;
    [self.showScrollView scrollRectToVisible:textFieldRect animated:YES];
    _isKeyBoardVisible = YES;
}

- (void)keyboardDidHide:(NSNotification *)notifiction
{
    NSLog(@"keyboardDidHide");
    NSDictionary* info = [notifiction userInfo];
    NSValue* aValue = [info objectForKey:UIKeyboardFrameEndUserInfoKey];
    CGSize keyboardSize = [aValue CGRectValue].size;
    CGRect viewFrame = self.showScrollView.frame;
    viewFrame.size.height += keyboardSize.height;
    self.showScrollView.frame = viewFrame;
    if (!_isKeyBoardVisible)
    {
        return;
    }
        
    _isKeyBoardVisible = NO;
}


@end
