//
//  AddressBookHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/24.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_AddressBookHeader_h
#define ALLDemos_AddressBookHeader_h

/*
 
 Foundation框架提供 Objective-C接口,Core Foundation框架提供C接口
 
 ABAddressBook
 ABPerson
 ABGroup
 ABRecord
 封装访问通讯录接口。Core Foundation框架中对应的类型是ABAddressBookRef 
 封装通讯录个人信息数据,是数据库的一条记录。Core Foundation框架中对应的类型是ABPersonRef
 封装通讯录组信息数据,一个组包含了多个人的信息,一个人也可以隶属多个组。Core Foundation框架 中对应的类型是ABGroupRef
 封装了数据库的一条记录,记录由属性组成。Core Foundation框架中对应的类型是ABRecordRef
 
 
 ABPeoplePickerNavigationController
 ABPersonViewController
 ABNewPersonViewController
 ABUnknownPersonViewController
 
 它是从数据库中选取联系人的导航控制器,对应的委托协议为ABPeoplePickerNavigationControllerDelegate
 查看并编辑单个联系人信息,对应的委托协议为ABPersonViewControllerDelegate
 创建新联系人信息,对应的委托协议ABNewPersonViewControllerDelegate
 呈现记录部分信息,这些信息可以创建新联系人信息,或添加到已经存在的联系 人,对应的委托协议为ABUnknownPersonViewControllerDelegate
 
 //单值
 kABPersonFirstNameProperty。名字。
  kABPersonLastNameProperty。姓氏。
  kABPersonMiddleNameProperty。中间名。  kABPersonPrefixProperty。前缀。
  kABPersonSuffixProperty。后缀。
 kABPersonNicknameProperty。昵称。
  kABPersonFirstNamePhoneticProperty。名字汉语拼音或音标。
  kABPersonLastNamePhoneticProperty。姓氏汉语拼音或音标。
  kABPersonMiddleNamePhoneticProperty。中间名汉语拼音或音标。  kABPersonOrganizationProperty。组织名。
  kABPersonJobTitleProperty。头衔。
  kABPersonDepartmentProperty。部门。
  kABPersonNoteProperty。备注。
 
 //多值
 kABPersonPhoneProperty。电话号码属性,kABMultiStringPropertyType类型的多值属性。
  kABPersonEmailProperty。E-mail属性,kABMultiStringPropertyType类型的多值属性。
  kABPersonURLProperty。URL属性,kABMultiStringPropertyType类型的多值属性。
  kABPersonRelatedNamesProperty。亲属关系人属性,kABMultiStringPropertyType类型的多值 属性。
  kABPersonAddressProperty。地址属性,kABMultiDictionaryPropertyType类型的多值属性。
  kABPersonInstantMessageProperty。即时聊天属性,kABMultiDictionaryPropertyType类型的
 多值属性。
  kABPersonSocialProfileProperty。社交账号属性,kABMultiDictionaryPropertyType类型的多
 值属性。
 */

#endif
