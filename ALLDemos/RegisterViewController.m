//
//  RegisterViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/11.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "RegisterViewController.h"

@interface RegisterViewController ()

@end

@implementation RegisterViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    //用代码设置delegate 也可以连线
    //self.userNameText.delegate = self;
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)barButtonDoneOnClick:(id)sender {
    [self dismissViewControllerAnimated:YES completion:^{
        NSLog(@"Modal View done");
        NSDictionary* data = [NSDictionary dictionaryWithObject:self.userNameText.text forKey:@"username"];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"RegisterCompletionNotification"
                                                            object:nil
                                                          userInfo:data];
    }];
}
- (IBAction)barButtonSaveOnClick:(id)sender {
}

/*
 
 */
- (IBAction)doneOnclick:(id)sender {
    [self dismissViewControllerAnimated:YES completion:^{
        NSLog(@"Modal View done");
        NSDictionary* data = [NSDictionary dictionaryWithObject:self.userNameText.text forKey:@"username"];
        [[NSNotificationCenter defaultCenter] postNotificationName:@"RegisterCompletionNotification"
                                                            object:nil
                                                          userInfo:data];
    }];
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField
{
    NSLog(@"textFieldShouldBeginEditing");
    return YES;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    NSLog(@"textFieldDidBeginEditing");
}

- (BOOL)textFieldShouldEndEditing:(UITextField *)textField
{
    NSLog(@"textFieldShouldEndEditing");
    return  YES;
}
- (void)textFieldDidEndEditing:(UITextField *)textField
{
    NSLog(@"textFieldDidEndEditing");
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    NSLog(@"textFieldShouldReturn");
    [textField resignFirstResponder];
    return YES;
}

@end
