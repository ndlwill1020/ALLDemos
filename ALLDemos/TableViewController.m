//
//  TableViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/13.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "TableViewController.h"
//如果通过代码来实现单元格的创建,图5-20storyboard中的Prototype Cells项要设为0
@implementation TableViewController

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
    static NSString* CellIdentifier = @"CellIdentifier";
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    /*
     //这里代码创建 需要  通过storyboard设置TableViewCell属性 不需要
     if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }*/
    NSUInteger row = [indexPath row];
    NSDictionary *rowDict = [self.teams objectAtIndex:row];
    cell.textLabel.text =  [rowDict objectForKey:@"name"];
    NSString *imagePath = [rowDict objectForKey:@"image"];
    imagePath = [imagePath stringByAppendingString:@".png"];
    cell.imageView.image = [UIImage imageNamed:imagePath];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    return  cell;
}

@end
