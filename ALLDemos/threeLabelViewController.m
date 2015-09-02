//
//  threeLabelViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/18.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "threeLabelViewController.h"

@interface threeLabelViewController ()

@end

@implementation threeLabelViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.scrollView.contentSize = CGSizeMake(self.view.frame.size.width*3, self.scrollView.frame.size.height);
    self.scrollView.frame = self.view.frame;
    
    UIStoryboard *mainStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    UIViewController* page1ViewController = [mainStoryboard instantiateViewControllerWithIdentifier:@"oneViewController"];
    self.page1 = page1ViewController.view;
    self.page1.frame = CGRectMake(0.0f, 0.0f, 320.0f, 420.0f);
    
    UIViewController* page2ViewController = [mainStoryboard
                                             instantiateViewControllerWithIdentifier:@"twoViewController"];
    self.page2 = page2ViewController.view;
    self.page2.frame = CGRectMake(320.0f, 0.0f, 320.0f, 420.0f);
    
    UIViewController* page3ViewController = [mainStoryboard
                                             instantiateViewControllerWithIdentifier:@"threeViewController"];
    self.page3 = page3ViewController.view;
    self.page3.frame = CGRectMake(2 * 320.0f, 0.0f, 320.0f, 420.0f);
    
    self.scrollView.delegate = self;
    [self.scrollView addSubview:self.page1];
    [self.scrollView addSubview:self.page2];
    [self.scrollView addSubview:self.page3];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    CGPoint offset = scrollView.contentOffset;
    self.pageControl.currentPage = offset.x / 320.0f;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/
- (IBAction)changePage:(id)sender {
    [UIView animateWithDuration:0.3f animations:^{
        int whichPage = self.pageControl.currentPage;
        self.scrollView.contentOffset = CGPointMake(320.0f * whichPage, 0.0f);
    }];
}

@end
