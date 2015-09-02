//
//  ViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/11.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(registerCompletion:)
                                                 name:@"RegisterCompletionNotification"
                                               object:nil];
}


- (void)registerCompletion:(NSNotification *)notification{
    NSDictionary* data = [notification userInfo];
    NSString* userName = [data objectForKey:@"username"];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


/*
 􏰸 UIModalTransitionStyleCoverVertical。􏰇现时􏰹􏰺􏰻方􏰼由􏰽􏰼上􏰾出,􏰿􏱀原来视图,关􏰈时
 从上􏱁􏰽部􏰾回。
 􏰸 UIModalTransitionStyleFlipHorizontal。􏱂平􏱃􏱄,􏰇现的时􏱅从􏱆􏱁􏱇􏱃􏱄,关􏰈的时􏱅从􏱇
 􏱁􏱆􏱃􏱄回来。
 􏰸 UIModalTransitionStyleCrossDissolve。两个视图交􏱈􏱉入􏱉出。
 􏰸 UIModalTransitionStylePartialCurl。􏰇现时模􏰆视图􏱊􏰰一个􏱋角􏱃页,关􏰈时模􏰆视图􏱃回来。
 */
- (IBAction)registerOnClick:(id)sender {
    //创建viewController
    //1.通过故事版
    UIStoryboard* mainStoryBoard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    UIViewController* registerViewController = [mainStoryBoard instantiateViewControllerWithIdentifier:@"registerViewController"];
    
    //2.通过xib
    //UIViewController* registerViewController = [[UIViewController alloc] initWithNibName:@"xib文件" bundle:nil];
    
    registerViewController.modalTransitionStyle = UIModalTransitionStyleCoverVertical;
    //completion代码􏱌非常类􏱍于Java中的􏱎􏰧类
    [self presentViewController:registerViewController animated:YES completion:^{
        NSLog(@"present Modal View");
    }];
}


@end
