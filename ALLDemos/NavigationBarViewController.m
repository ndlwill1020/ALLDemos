//
//  NavigationBarViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/12.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "NavigationBarViewController.h"

@interface NavigationBarViewController ()

@end

@implementation NavigationBarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)saveOnClick:(id)sender {
    self.showLabel.text = @"save";
}
- (IBAction)addOnClick:(id)sender {
    self.showLabel.text = @"add";
}

@end
