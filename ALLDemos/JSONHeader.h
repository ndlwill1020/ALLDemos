//
//  JSONHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/25.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_JSONHeader_h
#define ALLDemos_JSONHeader_h

/*
 NSJSONSerialization
 
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 self.navigationItem.leftBarButtonItem = self.editButtonItem;
 self.detailViewController = (DetailViewController *) [[self.splitViewController.viewControllers lastObject] topViewController];-
 [[NSNotificationCenter defaultCenter] addObserver:self
 selector:@selector(reloadView:)
 name:@"reloadViewNotification"
 object:nil];
 NSString* path = [[NSBundle mainBundle] pathForResource:
 @"Notes" ofType:@"json"];
 NSData *jsonData = [[NSData alloc] initWithContentsOfFile:path];
 NSError *error;
 id jsonObj = [NSJSONSerialization JSONObjectWithData:jsonData
 options:NSJSONReadingMutableContainers error:&error]; 1
 if (!jsonObj || error) {
 NSLog(@"JSON解码失败"); }
 self.listData = [jsonObj objectForKey:@"Record"];
 }
 */

#endif
