//
//  AddressViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/24.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AddressBook/AddressBook.h>
@interface AddressViewController : UITableViewController<UISearchBarDelegate,UISearchDisplayDelegate>
@property (nonatomic, strong) NSArray *listContacts;
- (void)filterContentForSearchText:(NSString*)searchText;
@end
