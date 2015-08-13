//
//  MainViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/13.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MainViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIDatePicker *datePicker;
@property (nonatomic,strong)UIView* portraitView;
@property (nonatomic,strong)UIView* landscapeView;
@end
