//
//  AddressViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/24.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "AddressViewController.h"
#import "DetailViewController.h"
@implementation AddressViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    CFErrorRef error = NULL;
    ABAddressBookRef addressBook = ABAddressBookCreateWithOptions(NULL, &error);
    ABAddressBookRequestAccessWithCompletion(addressBook, ^(bool granted, CFErrorRef error) {
        if (granted) {
            [self filterContentForSearchText:@""];
        }
    });
    //###typedef CFTypeRef ABAddressBookRef;
    CFRelease(addressBook);
}

- (void)filterContentForSearchText:(NSString*)searchText
{
    //如果没有授权,则退出
    if (ABAddressBookGetAuthorizationStatus() != kABAuthorizationStatusAuthorized) {
        return ;
    }
    CFErrorRef error = NULL;
    ABAddressBookRef addressBook = ABAddressBookCreateWithOptions(NULL, &error);
    if([searchText length]==0)
    {
        //查询所有
        self.listContacts = CFBridgingRelease(ABAddressBookCopyArrayOfAllPeople(addressBook));
    } else {
        //条件查询
        CFStringRef cfSearchText = (CFStringRef)CFBridgingRetain(searchText);
        self.listContacts = CFBridgingRelease(ABAddressBookCopyPeopleWithName(addressBook, cfSearchText));
        /*
         而CFBridgingRelease函数实现的是Core Foundation类型到Foundation类型的转化并把对象所有权转让ARC(自动引用计数),因此不需要释放属性 listContacts对应的成员变量。类似的还有CFBridgingRetain函数,它实现的是Foundation类型到Core
         Foundation类型的转化,并把对象所有权转让调用者,因此需要释放这个对象,
         */
        CFRelease(cfSearchText);
    }
    [self.tableView reloadData];
    CFRelease(addressBook);
}

- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar
{
    //查询所有
    [self filterContentForSearchText:@""];
}

////当文本内容发生改变时,向表视图数据源发出重新加载消息
- (BOOL)searchDisplayController:(UISearchDisplayController *)controller
shouldReloadTableForSearchString:(NSString *)searchString
{
    [self filterContentForSearchText:searchString]; //返回YES的情况下,表视图可以重新加载
    return YES;
}

#pragma mark - tableViewDataSource

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:
(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier]; if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    ABRecordRef thisPerson = CFBridgingRetain([self.listContacts objectAtIndex:
                                               [indexPath row]]);//foundation->cf
    NSString *firstName = CFBridgingRelease(ABRecordCopyValue(thisPerson, kABPersonFirstNameProperty));//cf->f
    firstName = firstName != nil?firstName:@"";
    NSString *lastName = CFBridgingRelease(ABRecordCopyValue(thisPerson,
                                                             kABPersonLastNameProperty));
    lastName = lastName != nil?lastName:@"";
    cell.textLabel.text = [NSString stringWithFormat:@"%@ %@",firstName,lastName];
    CFRelease(thisPerson);
    return cell;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([[segue identifier] isEqualToString:@"showDetail"]) {
        NSIndexPath *indexPath = [self.tableView indexPathForSelectedRow];
        ABRecordRef thisPerson = CFBridgingRetain([self.listContacts
                                                   objectAtIndex:[indexPath row]]);
        DetailViewController *detailViewController = [segue
                                                      destinationViewController];
        ABRecordID personID = ABRecordGetRecordID(thisPerson);
        NSNumber *personIDAsNumber = [NSNumber numberWithInt:personID];
        detailViewController.personIDAsNumber = personIDAsNumber;
        CFRelease(thisPerson);
    }
}

//多值属性访问方式与单值属性访问方式类似,都使用ABRecordCopyValue函数。不同的是,多值属性访问的返回值是ABMultiValueRef,然后使用ABMultiValueCopyArrayOfAllValues函数从ABMultiValueRef 中获取CFArrayRef数组。
/*
 从ABMultiValueRef 中获取CFArrayRef数组
 CFArrayRef ABMultiValueCopyArrayOfAllValues (
 ABMultiValueRef multiValue
 );
 
 可以从ABMultiValueRef对象中返回标签
 CFStringRef ABMultiValueCopyLabelAtIndex (
 ABMultiValueRef multiValue,
 CFIndex index
 );
 
 可以从ABMultiValueRef对象中返回ID
 ABMultiValueIdentifier ABMultiValueGetIdentifierAtIndex (
 ABMultiValueRef multiValue,
 CFIndex index
 );
 */

@end
