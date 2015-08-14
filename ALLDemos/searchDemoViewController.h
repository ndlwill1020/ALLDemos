//
//  searchDemoViewController.h
//  ALLDemos
//
//  Created by macuser on 15/8/14.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface searchDemoViewController : UITableViewController<UISearchBarDelegate,UISearchDisplayDelegate>
@property (weak, nonatomic) IBOutlet UISearchBar *searchBar;
@property (nonatomic, strong) NSArray *listTeams;
@property (nonatomic, strong) NSMutableArray *listFilterTeams;
//属性listTeams是为了􏰻载全部􏰹队的信息,listFilterTeams是查询之后的􏰹队信息。
- (void)filterContentForSearchText:(NSString*)searchText scope:(NSUInteger)scope;
@end
