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
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
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

@end
