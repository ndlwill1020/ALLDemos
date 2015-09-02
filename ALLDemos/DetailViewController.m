//
//  DetailViewController.m
//  ALLDemos
//
//  Created by macuser on 15/8/24.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#import "DetailViewController.h"
#import <AddressBook/AddressBook.h>
@implementation DetailViewController

-(void)viewDidLoad
{
    [super viewDidLoad];
    ABRecordID personID = [self.personIDAsNumber intValue];
    CFErrorRef error = NULL;
    ABAddressBookRef addressBook = ABAddressBookCreateWithOptions(NULL, &error);
    ABRecordRef person = ABAddressBookGetPersonWithRecordID(addressBook, personID);
    //......
    ABMultiValueRef emailsProperty = ABRecordCopyValue(person, kABPersonEmailProperty);//###
    NSArray* emailsArray = CFBridgingRelease(ABMultiValueCopyArrayOfAllValues(emailsProperty)); for(int index = 0; index< [emailsArray count]; index++){
        NSString *email = [emailsArray objectAtIndex:index];
        NSString *emailLabel = CFBridgingRelease(ABMultiValueCopyLabelAtIndex (emailsProperty, index));
        if ([emailLabel isEqualToString:(NSString*)kABWorkLabel]) {
            [self.lblWorkEmail setText:email];
        } else if ([emailLabel isEqualToString:(NSString*)kABHomeLabel]) { [self.lblHomeEmail setText:email];
        } else {
            NSLog(@"%@: %@", @"其他Email", email); }
    }
    CFRelease(emailsProperty);
    
    /*
     取得电话号码多值属性的代码如下
     ABMultiValueRef phoneNumberProperty = ABRecordCopyValue(person,
     kABPersonPhoneProperty);
     NSArray* phoneNumberArray = CFBridgingRelease(ABMultiValueCopyArrayOfAllValues (phoneNumberProperty));
     for(int index = 0; index< [phoneNumberArray count]; index++){
     NSString *phoneNumber = [phoneNumberArray objectAtIndex:index];
     NSString *phoneNumberLabel = CFBridgingRelease(ABMultiValueCopyLabelAtIndex
     (phoneNumberProperty, index));
     if ([phoneNumberLabel isEqualToString:(NSString*)kABPersonPhoneMobileLabel]) { [self.lblMobile setText:phoneNumber];
     } else if ([phoneNumberLabel isEqualToString:(NSString*)kABPersonPhoneIPhoneLabel]) { [self.lblIPhone setText:phoneNumber];
     } else {
     NSLog(@"%@: %@", @"其他电话", phoneNumber); }
     }
     CFRelease(phoneNumberProperty);
     
     kABPersonPhoneMainLabel。主要电话号码标签。
      kABPersonPhoneHomeFAXLabel。家庭传真电话号码标签。  kABPersonPhoneWorkFAXLabel。工作传真电话号码标签。  kABPersonPhonePagerLabel。寻呼机号码标签。
     */
}

@end
