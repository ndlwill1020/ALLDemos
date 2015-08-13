//
//  MainViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/13.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "MainViewController.h"
#import "landscapeViewController.h"
@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    landscapeViewController* landscapeController = [[UIStoryboard storyboardWithName:@"landscapeStoryboard" bundle:nil] instantiateViewControllerWithIdentifier:@"landScapeViewController"];
    self.landscapeView = landscapeController.view;
    self.portraitView = self.view;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)onClick:(id)sender {
    NSDate* date = self.datePicker.date;
    NSLog(@"%@",[date descriptionWithLocale:[NSLocale currentLocale]]);
    NSDateFormatter* format = [[NSDateFormatter alloc] init];
    [format setDateFormat:@"YYYY-MM-dd HH:mm:ss"];
    NSLog(@"%@",[format stringFromDate:date]);
}


//􏰾定􏰿前视图是􏱀􏲔持􏰕􏰖
- (BOOL)shouldAutorotate
{
    return YES;
}

//具体􏰾 定视图􏲔持哪个方􏰅的􏰕􏰖
- (NSUInteger)supportedInterfaceOrientations
{
    //除了􏱊􏰑􏰅下以外的其􏲆3个方􏰅
    return UIInterfaceOrientationMaskAllButUpsideDown;
}

//- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
//{
//    
//}

//- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id<UIViewControllerTransitionCoordinator>)coordinator

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
