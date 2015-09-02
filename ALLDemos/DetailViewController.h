//
//  DetailViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/24.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UILabel *lblName;
@property (weak, nonatomic) IBOutlet UILabel *lblMobile;
@property (weak, nonatomic) IBOutlet UILabel *lblIPhone;
@property (weak, nonatomic) IBOutlet UILabel *lblWorkEmail;
@property (weak, nonatomic) IBOutlet UILabel *lblHomeEmail;
@property (strong, nonatomic) NSNumber* personIDAsNumber;
@end
