//
//  searchDemoViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/14.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "searchDemoViewController.h"

@implementation searchDemoViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    //设定搜索栏ScopeBar􏲈􏲉
    [self.searchBar setShowsScopeBar:NO];
    [self.searchBar sizeToFit];
    NSBundle *bundle = [NSBundle mainBundle];
    NSString *plistPath = [bundle pathForResource:@"team"
                                           ofType:@"plist"];
    self.listTeams = [[NSArray alloc] initWithContentsOfFile:plistPath];
    //初次进入界面􏱼查询􏲁􏲂数据
    [self filterContentForSearchText:@"" scope:-1];
}

- (void)filterContentForSearchText:(NSString*)searchText scope:(NSUInteger)scope
{
    if ([searchText length] == 0) {
        //查询􏲁􏲂
        self.listFilterTeams = [NSMutableArray arrayWithArray:self.listTeams];
        return;
    }
    
    NSPredicate* scopePredicate;
    NSArray* tempArray;
    
    /*
     NSMutableArray *array = [NSMutableArray arrayWithObjects:@"Bill", @"Ben", @"Chris", @"Melissa", nil];
     NSPredicate *bPredicate = [NSPredicate predicateWithFormat:
     @"SELF beginswith[c] 'b'"];
     NSArray *beginWithB = [array filteredArrayUsingPredicate:bPredicate]; //beginWithB 包􏳳 { @"Bill", @"Ben" }.
     NSPredicate *sPredicate = [NSPredicate predicateWithFormat:
     @"SELF contains[c]  's'"];
     [array filterUsingPredicate:sPredicate]; //数组包􏳳 { @"Chris", @"Melissa" }
     */
    
    switch (scope) {
        case 0://eng
            //[c]不区分大小写
            scopePredicate = [NSPredicate predicateWithFormat:@"self.name contains[c] %@",searchText];
            
            tempArray =[self.listTeams filteredArrayUsingPredicate:scopePredicate];
            self.listFilterTeams = [NSMutableArray arrayWithArray:tempArray];
            break;
        case 1:
            scopePredicate = [NSPredicate predicateWithFormat:@"SELF.image contains[c] %@",searchText];
            tempArray =[self.listTeams filteredArrayUsingPredicate:scopePredicate];
            self.listFilterTeams = [NSMutableArray arrayWithArray:tempArray];
            break;
            
        default:
            self.listFilterTeams = [NSMutableArray arrayWithArray:self.listTeams];
            break;
    }
}

- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar
{
    //查询􏲁􏲂
    [self filterContentForSearchText:@"" scope:-1];
}


//点􏰎Scope Bar进行切换
- (BOOL)searchDisplayController:(UISearchDisplayController *)controller shouldReloadTableForSearchScope:(NSInteger)searchOption
{
    [self filterContentForSearchText:self.searchBar.text scope:searchOption]; //如果􏱻回YES􏱼􏱽表视图可􏱾重新加载
    return YES;
}

//DEPRECATED
- (BOOL)searchDisplayController:(UISearchDisplayController *)controller shouldReloadTableForSearchString:(NSString *)searchString
{
    [self filterContentForSearchText:searchString scope:self.searchBar.selectedScopeButtonIndex];
    //如果􏱻回YES􏱼􏱽表视图可􏱾重新加载
    
    /*如果采用UISearchBarDelegate委托对象的searchBar:textDidChange:方法实现搜索功能,我们还需
    要自己调用[tableView reloadData]方法重新加载表视图数据。*/
    return YES;
}

@end
