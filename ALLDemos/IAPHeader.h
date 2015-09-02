//
//  IAPHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/28.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_IAPHeader_h
#define ALLDemos_IAPHeader_h

/*
 #import <UIKit/UIKit.h>
 #import <StoreKit/StoreKit.h>
 @interface ViewController : UITableViewController <SKProductsRequestDelegate,SKPaymentTransactionObserver> 1
 //点击刷新按钮
 - (IBAction) request:(id)sender; //点击恢复按钮
 - (IBAction)restore:(id)sender;
 //刷新按钮属性
 @property (weak, nonatomic) IBOutlet UIBarButtonItem *refreshButton; 2 //恢复按钮属性
 @property (weak, nonatomic) IBOutlet UIBarButtonItem *restoreButton; 3 //产品列表
 @property (nonatomic,strong) NSArray* skProducts;
 //数字格式
 @property (nonatomic,strong) NSNumberFormatter * priceFormatter;
 //产品标识集合
 @property (nonatomic,strong) NSSet * productIdentifiers;
 @end
 
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 //设置数字格式
 self.priceFormatter = [[NSNumberFormatter alloc] init];
 [self.priceFormatter setFormatterBehavior:NSNumberFormatterBehavior10_4]; 2 [self.priceFormatter setNumberStyle:NSNumberFormatterCurrencyStyle]; 3
 //从ProductIdentifiers.plist文件读取应用内产品标识
 NSString* path = [[NSBundle mainBundle] pathForResource:@"ProductIdentifiers"
 ofType:@"plist"]; 4 NSArray* array = [[NSArray alloc] initWithContentsOfFile:path]; 5 //从NSArray转化为NSSet
 self.productIdentifiers = [[NSSet alloc] initWithArray:array]; 6
 //添加self作为交易观察者对象
 [[SKPaymentQueue defaultQueue] addTransactionObserver:self]; 7
 }
 
 - (IBAction)request:(id)sender {
 //检查设备是否在家长控制中禁止应用内购买
 if ([SKPaymentQueue canMakePayments]) { 1
 //没有设置可以请求应用内购买信息
 SKProductsRequest *request= [[SKProductsRequest alloc] 2
 initWithProductIdentifiers:self.productIdentifiers];
 request.delegate = self; 3 [request start]; 4
 self.navigationItem.prompt = @"刷新中..."; 5 self.refreshButton.enabled = NO; 6 self.restoreButton.enabled = NO; 7
 } else { //有设置的情况下
 UIAlertView *alertView = [[UIAlertView alloc] initWithTitle:@"访问限制" message:@"您不能进行应用内购买!"
 delegate:nil
 cancelButtonTitle:@"Ok"
 otherButtonTitles: nil];
 [alertView show];
 } }
 
 
 - (void)productsRequest:(SKProductsRequest *)request didReceiveResponse:
 (SKProductsResponse *)response
 {
 NSLog(@"加载应用内购买产品...");
 self.navigationItem.prompt = nil;
 self.refreshButton.enabled = YES;
 self.restoreButton.enabled = YES;
 self.skProducts = response.products;
 for (SKProduct * skProduct in self.skProducts) {
 NSLog(@"找到产品: %@ %@ %0.2f", skProduct.productIdentifier, skProduct.localizedTitle, skProduct.price.floatValue);
 }
 [self.tableView reloadData];
 }
 该方法在请求产品返回后回调,其中response参数是返回的应答对象,它的products属性返回skProduct 对象的集合。skProduct对象描述产品信息,其productIdentifier属性是产品标识符,localizedTitle属 性是产品的名字,price属性是产品的价格。
 
 - (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath: (NSIndexPath *)indexPath {
 static NSString *CellIdentifier = @"Cell";
 UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier]; if (cell == nil) {
 cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:CellIdentifier];
 }
 int row = [indexPath row];
 SKProduct * product = self.skProducts[row]; 1
 cell.textLabel.text = product.localizedTitle; 2
 [self.priceFormatter setLocale:product.priceLocale]; 3 cell.detailTextLabel.text = [self.priceFormatter
 stringFromNumber:product.price]; 4
 //从应用设置文件中读取购买信息
 BOOL productPurchased = [[NSUserDefaults standardUserDefaults]
 boolForKey:product.productIdentifier]; 5 if (productPurchased) {
 cell.accessoryType = UITableViewCellAccessoryCheckmark;
 cell.accessoryView = nil;
 } else {
 UIImage *buttonUpImage = [UIImage imageNamed:@"button_up.png"];
 UIImage *buttonDownImage = [UIImage imageNamed:@"button_down.png"]; 6
 UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom]; button.frame = CGRectMake(0.0f, 0.0f, buttonUpImage.size.width,
 buttonUpImage.size.height);
 [button setBackgroundImage:buttonUpImage forState:UIControlStateNormal]; [button setBackgroundImage:buttonDownImage
 forState:UIControlStateHighlighted];
 [button setTitle:@"购买" forState:UIControlStateNormal];
 button.tag = indexPath.row; 7 [button addTarget:self action:@selector(buttonTapped:)
 forControlEvents:UIControlEventTouchUpInside]; 8 cell.accessoryView = button;
 }
 return cell;
 }
 
 - (void)buttonTapped:(id)sender {
 UIButton *buyButton = (UIButton *)sender; //通过按钮的tag属性获得被点击按钮的索引,使用索引从数组中取出SKProduct对象
 SKProduct *product = self.skProducts[buyButton.tag]; 1 //获得产品的付款对象
 SKPayment * payment = [SKPayment paymentWithProduct:product]; 2 //把付款对象添加到付款队列中
 [[SKPaymentQueue defaultQueue] addPayment:payment]; 3
 }
 
 实现SKPaymentTransactionObserver协议的代码:
 该方法在交易结果更新时被调用,其中transactions参数是更新的交易(SKPaymentTransaction)对象 的集合,我们通过循环遍历交易集合逐一处理交易。交易状态(transactionState)有3种:交易完成 (SKPaymentTransactionStatePurchased)、交易失败(SKPaymentTransactionStateFailed)和交易恢
 复(SKPaymentTransactionStateRestored)。
 - (void)paymentQueue:(SKPaymentQueue *)queue updatedTransactions:(NSArray *)transactions
 {
 for (SKPaymentTransaction * transaction in transactions) {
 switch (transaction.transactionState)
 {
 case SKPaymentTransactionStatePurchased: //交易完成
 [self completeTransaction:transaction];
 break;
 case SKPaymentTransactionStateFailed: //交易失败
 [self failedTransaction:transaction];
 break;
 case SKPaymentTransactionStateRestored: //交易恢复
 [self restoreTransaction:transaction];
 default:
 break; }
 } }
 
 //交易完成
 - (void)completeTransaction:(SKPaymentTransaction *)transaction {
 NSLog(@"交易完成...");
 [self provideContentForProductIdentifier:transaction.payment.productIdentifier]; 1 //把交易从付款队列中移除
 [[SKPaymentQueue defaultQueue] finishTransaction:transaction]; 2
 }
 //交易恢复
 - (void)restoreTransaction:(SKPaymentTransaction *)transaction {
 NSLog(@"交易恢复...");
 self.navigationItem.prompt = nil;
 self.refreshButton.enabled = YES;
 self.restoreButton.enabled = YES;
 [self provideContentForProductIdentifier:transaction.originalTransaction. payment.productIdentifier];
 [[SKPaymentQueue defaultQueue] finishTransaction:transaction];
 //交易失败
 - (void)failedTransaction:(SKPaymentTransaction *)transaction {
 NSLog(@"交易失败...");
 if (transaction.error.code != SKErrorPaymentCancelled)
 {
 NSLog(@"交易失败: %@", transaction.error.localizedDescription);
 }
 [[SKPaymentQueue defaultQueue] finishTransaction: transaction]; }
 
 /购买成功
 - (void)provideContentForProductIdentifier:(NSString *)productIdentifier { 5
 [[NSUserDefaults standardUserDefaults] setBool:YES forKey:productIdentifier]; 6 [[NSUserDefaults standardUserDefaults] synchronize]; 7 [self.tableView reloadData]; 8
 }
 
 completeTransaction:是处理交易成功的方法,其中第1行代码传递产品标识符调用
 provideContentForProductIdentifier:方法处理交易,第2行代码[[SKPaymentQueue defaultQueue] finishTransaction:transaction]语句结束交易,并把交易从付款队列中移除。无论什么状态下的交易,都 应该调用第2行语句结束交易。
 provideContentForProductIdentifier:是我们自己编写的方法,用于处理交易成功和恢复交易这两种 情况。在该方法中,我们主要将交易中的产品记录到本地的应用设置文件中。
 
////////////////恢复交易
 - (IBAction)restore:(id)sender {
 self.navigationItem.prompt = @"恢复中..."; self.refreshButton.enabled = NO;
 self.restoreButton.enabled = NO;
 [[SKPaymentQueue defaultQueue] restoreCompletedTransactions];
 }
 
 恢复交易主要通过[[SKPaymentQueue defaultQueue] restoreCompletedTransactions]语句实现的。
 此外,恢复时,也会触发SKPaymentTransactionObserver观察者的paymentQueue:updatedTransactions: 方法。
 */

#endif
