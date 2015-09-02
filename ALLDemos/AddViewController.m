//
//  AddViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/17.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "AddViewController.h"

@interface AddViewController ()

@end

@implementation AddViewController

+ (void)initialize
{
    NSLog(@"initialize");
}

- (void)viewDidLoad {
    NSLog(@"view did load");
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //设置导航栏  编辑按钮是视图控制器中已经定义好的按钮
    self.navItem.rightBarButtonItem = self.editButtonItem;
    self.navItem.title = @"单元格插入和删除";
    //设置单元格文本框
    self.textField.hidden = YES;
    self.textField.delegate = self;
    //将当前视图控制器分配给表视图的委托和数据源
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    self.teams = [[NSMutableArray alloc] initWithObjects:@"黑龙江", @"吉林", @"辽宁", nil];
}

//用于响应视图编辑状态变化
//该方法是UIViewController生命周期的方法,用于响应视图编辑状态的变化
- (void)setEditing:(BOOL)editing animated:(BOOL)animated
{
    NSLog(@"editing");
    [super setEditing:editing animated:animated];
    [self.tableView setEditing:editing animated:YES];
    if (editing) {
        self.textField.hidden = NO;
    } else {
        self.textField.hidden = YES;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.teams count] + 1;
}



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    NSLog(@"%ld",self.teams.count);
    NSLog(@"%ld",indexPath.row);
    BOOL b_addCell = (indexPath.row == self.teams.count);
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    if (!b_addCell) {
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
        cell.textLabel.text = [self.teams objectAtIndex:indexPath.row];
    } else {
        self.textField.frame = CGRectMake(10,0,300,44);
        self.textField.text = @"";
        [cell.contentView addSubview:self.textField];
    }
    return cell;
}

//用于单元格编辑图标的设定
- (UITableViewCellEditingStyle)tableView:(UITableView *)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath
{
//    if (indexPath.row == [self.teams count]) {
//        return UITableViewCellEditingStyleInsert;
//    } else {
//        return UITableViewCellEditingStyleDelete;
//    }
    return UITableViewCellEditingStyleNone;
}

#pragma mark - 移动单元格

- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    return YES;
}

- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)sourceIndexPath toIndexPath:(NSIndexPath *)destinationIndexPath
{
    NSLog(@"move##############");
    NSString *stringToMove = [self.teams objectAtIndex:sourceIndexPath.row];
    [self.teams removeObjectAtIndex:sourceIndexPath.row];
    [self.teams insertObject:stringToMove atIndex:destinationIndexPath.row];
}



#pragma mark - UITableViewDataSource协议方法
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        [self.teams removeObjectAtIndex: indexPath.row];
        [self.tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                              withRowAnimation:UITableViewRowAnimationFade];
        [self.tableView reloadData];
    }else if (editingStyle == UITableViewCellEditingStyleInsert) {
        [self.teams insertObject:self.textField.text atIndex:[self.teams count]];
        [self.tableView insertRowsAtIndexPaths:[NSArray arrayWithObject:indexPath]
                              withRowAnimation:UITableViewRowAnimationFade];
        [self.tableView reloadData];
    }
}

- (BOOL)tableView:(UITableView *)tableView shouldHighlightRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row == [self.teams count]) {
        return NO;
    } else {
        return YES;
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    UITableViewCell *cell = (UITableViewCell*) [[textField superview] superview];
    [self.tableView setContentOffset:CGPointMake(0.0,cell.frame.origin.y) animated:YES];
}


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
