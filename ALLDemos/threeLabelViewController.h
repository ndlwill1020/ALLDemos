//
//  threeLabelViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/18.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface threeLabelViewController : UIViewController<UIScrollViewDelegate>
@property (nonatomic,strong) UIView* page1;
@property (nonatomic,strong) UIView* page2;
@property (nonatomic,strong) UIView* page3;
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (weak, nonatomic) IBOutlet UIPageControl *pageControl;

@end
