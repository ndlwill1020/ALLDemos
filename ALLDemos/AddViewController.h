//
//  AddViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/17.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AddViewController : UIViewController<UITableViewDataSource,UITableViewDelegate,UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UINavigationItem *navItem;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (strong, nonatomic) IBOutlet UITextField *textField;
@property (nonatomic,strong) NSMutableArray* teams;


@end
