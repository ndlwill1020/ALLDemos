//
//  CustomCellTableViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/13.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "CustomCellTableViewController.h"
#import "CustomCell.h"
@implementation CustomCellTableViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSBundle *bundle = [NSBundle mainBundle];
    //􏲹取属性列表文件中的􏲲􏲳数据
    NSString *plistPath = [bundle pathForResource:@"team"
                                           ofType:@"plist"];
    self.teams = [[NSArray alloc] initWithContentsOfFile:plistPath];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.teams count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"TableCell";
    CustomCell* cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    NSUInteger row = [indexPath row];
    NSDictionary *rowDic = [self.teams objectAtIndex:row];
    cell.label.text =  [rowDic objectForKey:@"name"];
    NSString *imagePath = [rowDic objectForKey:@"image"];
    imagePath = [imagePath stringByAppendingString:@".png"];
    cell.cellImageView.image = [UIImage imageNamed:imagePath];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    
    /*
     typedef NS_ENUM(NSInteger, UITableViewCellAccessoryType) {
     UITableViewCellAccessoryNone,                   // don't show any accessory view
     UITableViewCellAccessoryDisclosureIndicator,    // regular chevron. doesn't track
     UITableViewCellAccessoryDetailDisclosureButton, // info button w/ chevron. tracks
     UITableViewCellAccessoryCheckmark,              // checkmark. doesn't track
     UITableViewCellAccessoryDetailButton NS_ENUM_AVAILABLE_IOS(7_0) // info button. tracks
     };
     */
    
    return cell;
}

@end
