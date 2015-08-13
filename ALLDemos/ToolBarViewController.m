//
//  ToolBarViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/12.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "ToolBarViewController.h"

@interface ToolBarViewController ()

@end

@implementation ToolBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)saveOnClick:(id)sender {
    self.showLabel.text = @"save";
}
- (IBAction)openOnClick:(id)sender {
    self.showLabel.text = @"open";
}

@end
