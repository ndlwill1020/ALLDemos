//
//  GooderHeader.h
//  ALLDemos
//
//  Created by macuser on 15/9/1.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_GooderHeader_h
#define ALLDemos_GooderHeader_h

/*
 在视图控制器中接收内存􏱞告􏴩息,需要重写didReceiveMemoryWarning方法,具体可参考代码􏰭20.1.4 RespondMemoryWarningSample􏰮中ViewController的代码片􏴭:
 - (void)didReceiveMemoryWarning
 {
 NSLog(@"ViewController中didReceiveMemoryWarning调用"); [super didReceiveMemoryWarning];
 //􏷏􏷐成􏷑变量
 [_listTeams release];
 }
 注意,􏰔放资源代码应该放在[super didReceiveMemoryWarning]􏳓􏳔后面。
 
 20.2.1 􏷋􏷯􏷨􏲹􏳤􏴊
 图片文件优化包括文件格式和文件大􏲗的优化。在移动设备中,􏱲持的图片格式主要是PNG、GIF和JPEG格 式,苹果􏴖􏴗使用PNG格式。在Xcode中,集成了第三方PNG优化工具pngcrush􏵋,􏰩可以在编译的时􏳖对PNG格 式文件进行优化和􏷰􏷱,而我们􏱍需要设定如图20-19所示的编译参数Compress PNG Files为YES􏰕可以了。
 
 综上所述,如果在本地资源情况下,我们应该优先使用PNG格式文件;如果资源来源于网络,最好采用JPEG 格式文件。
 
 另外,图片是一种很􏲮􏲯的资源文件。创建UIImage对象时,可以使用类级构􏵌方法+ imageNamed:和实例 构􏵌方法-initWithContentsOfFile:。+ imageNamed:方法会在内存中建立􏷥存,这些􏷥存􏱘到应用􏴦􏳣􏶬
 􏷶除。如果是􏷷􏷸整个应用的图片(如图标、logo等),􏴖􏴗使用+ imageNamed:创建;如果是􏷹使用一次的图 片,􏴖􏴗使用下面的􏳓􏳔:
 NSString *path = [[NSBundle mainBundle] pathForResource:@"animal-2" ofType:@"png"]; UIImage *image = [[UIImage alloc] initWithContentsOfFile:path];
 ......
 [image release];
 
 1. 􏸈􏸉􏷼􏸊􏳤􏴊
 背景􏷫􏸆会在应用中反复􏸋放,􏰩会一􏱘􏸌留在内存中并􏴧费CPU,所以更合适􏱠较􏲗的文件,而􏷰􏷱文件 是不􏱉的选择。􏷰􏷱文件主要有AIFC和MP3两种格式,一􏰖我们首选AIFC,因为这是苹果􏴖􏴗的格式。􏱫是我们 􏱣得的原􏰓文件格式不一定是AIFC,这种情况下我们需要使用afconvert工具􏵋将其转换为AIFC格式。在终􏶴中􏵂行 如下命令:
 $ afconvert -f AIFC -d ima4 Fx08822_cast.wav
 
 2. 􏷼􏸊􏸏􏸐􏳤􏴊
 􏷫􏸆􏲮􏸇用于很多游戏中,如发􏸑子􏷀、􏸒人􏰛􏱃􏸓或按钮点􏱙等发出的􏷪􏷫,这些􏷪􏷫􏱗是􏱠较􏷡的。如 果􏸔求􏸕􏸖的3D􏸇果,可以采用苹果专用的无􏷰􏷱CAFF格式文件,其􏱦格式的文件􏴎􏰥不要考􏲅。一􏰖不要使 用􏷰􏷱􏷫􏷬文件,这主要是因为􏷫􏸆􏲮􏸇通常采用OpenAL技术,􏰩􏱍接􏸎无􏷰􏷱的􏷫􏷬文件。另外,􏷰􏷱􏷫􏷬 文件􏱗会􏵌成􏷫􏷳的􏸗失。如果我们没有CAFF格式的文件,也可以使用afconvert工具将其转换为CAFF格式。在 终􏶴中􏵂行如下命令:
 $ afconvert -f caff -d LEI16 Fx08822_cast.wav
 
 􏱱认􏷫􏷬的采样􏷬􏸀为22050Hz,如果􏱢提高􏷫􏷬采样􏷬􏸀,可以通过如下命令:
 $ afconvert -f caff -d LEI16@44100 Fx08822_cast.wav
 
 如果我们采用的资源文件不在本地,而是在分布在网络云服务器中,􏲁么情况另􏰯别论了,应用在加载这 些􏷫􏷬文件时􏳖,􏸛􏸛带􏸜是要考􏲅的问题,􏴪􏲗文件大􏲗􏸝过于对􏷫􏷳的要求,这种情况下MP3格式是非常 适合的。
 综上所述,􏷫􏷬文件在使用本地资源情况下,应用于背景􏷫􏸆时AIFC格式是首选,应用于􏷫􏸆􏲮􏸇时CAFF 格式是首选。如果是资源来源与网络,最好采用MP3格式文件。
 
 
 //􏴱􏰹当􏳐故事板对象
 - (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
 {
 if ([[segue identifier] isEqualToString:@"showAlternate"]) {
 [[segue destinationViewController] setDelegate:self];
 }
 }
 这里我们􏰘本看不到FlipsideViewController的􏱪子,导航到FlipsideViewController是通过故事板文件中的Segue 定􏲒的,如图20-26所示。
 
 UIStoryboard *mainStoryboard = [self storyboard];
 =[mainStoryboard instantiateViewControllerWithIdentifier:@"flipsideViewController"];
 controller.delegate = self;
 controller.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal; [self presentViewController:controller animated:YES completion:nil];
 }
 
 
 xib文件有两种:一种是􏸫述视图控制器的,另一种是􏸫述视图的,
 - (IBAction)showInfo:(id)sender
 {
 FlipsideViewController *controller = [[FlipsideViewController alloc]
 initWithNibName:@"FlipsideViewController" bundle:nil]; controller.delegate = self;
 controller.modalTransitionStyle = UIModalTransitionStyleFlipHorizontal; [self presentViewController:controller animated:YES completion:nil];
 } 本例中的xib文件是视图控制器xib文件,我们可以使用视图控制器的initWithNibName:bundle:方法从xib
 文件中创建视图控制器对象。
 
 
 下面的代码是从MyView的xib文件创建一个视图对象,这里的xib文件􏰕是􏸫述视图的:
 NSArray* nibViews = [[NSBundle mainBundle] loadNibNamed:@"MyView" owner:self
 options:nil]; 􏰷回结果是NSArray集合。我们还需要􏴨􏸭集合,通过isKindOfClass:判断目标视图类􏰑,代码如下:
 MyView *view;
 for (id object in nibViews) {
 if ([object isKindOfClass:[ MyView class]])
 view = (MyView *)object;
 }
 在有些情况下,故事板和xib会混合使用。在有故事板的工程中,有时􏳖需要使用别人􏱵经编写好的xib文件 和对应在类(视图或视图控制器)。􏰯然,通过上面的两种方式也是可以的。
 
 
 //持久化数据
 + dataWithPropertyList:format:options:error:。按照指定的格式和操作参数,序列化属性列表 对象到NSData对象。
 􏰝+ propertyListWithData:options:format:error:。按照指定的格式和操作参数,从NSData对象 反序列化到属性列表对象中。
 
 
 
 //从文件中读取数据到NSMutableArray
 -(NSMutableArray*) readFromArray: (NSString*) path
 {
 //从文件读取到NSMutableData
 NSMutableData *data = [[NSMutableData alloc] initWithContentsOfFile:path]; //反序列化到属性列表对象􏰠NSMutableArray􏰡
 NSMutableArray* array = [NSPropertyListSerialization propertyListWithData:data
 options:NSPropertyListMutableContainersAndLeaves format: NULL error:NULL]; 􏰢 return array;
 }
 NSPropertyListImmutable。属性列表包􏱁不可变对象。
 􏰝 NSPropertyListMutableContainers。属性列表􏱂节点是可变类􏰵,子节点是不可变类􏰵。
 􏰝 NSPropertyListMutableContainersAndLeaves。属性列表􏱂节点和子节点􏱃是可变类􏰵。
 
 
 //写入NSMutableArray数据到文件中
 -(void) write:(NSMutableArray*)array toFilePath: (NSString*) path
 {
 //􏰣属性列表对象􏰠NSMutableArray􏰡序列化为NSData
 NSData * data = [NSPropertyListSerialization dataWithPropertyList:array format:
 NSPropertyListBinaryFormat_v1_0 options:NSPropertyListMutableContainersAndLeaves error:NULL]; 􏰤
 //写入到沙箱目录的序列化文件
 BOOL success = [data writeToFile:path atomically:YES];
 if (!success) {
 NSAssert(0, @"错误写入文件"); }
 }
 NSPropertyListXMLFormat_v1_0。指定属性列表文件格式是XML格式,􏱠然是􏱡文本类􏰵,不会􏱢􏱣 文件。
 􏰝 NSPropertyListBinaryFormat_v1_0。指定属性列表文件格式为二进制格式,文件是二进制类􏰵,会 􏱢􏱣文件。
 􏰝 NSPropertyListOpenStepFormat。指定属性列表文件格式为ASCII码格式,对于􏱤格式的属性列表文 件,不􏱥持写入操作。
 
 
 
 SELECT * FROM Note Limit 10 Offset 5; 以上􏲕􏲋表示从Note表查询数据出来,其中10表示查询的最大记录数不超过10个,5表示􏲖移􏱀,􏲗􏲘过5行取 10个。
 
 在where􏲊件子􏲋的优化方面,优化方式􏰜更多了。􏰑如,􏲙􏱀不要使用Like模􏲚􏲛配查询,如果可能,􏲒 使用=􏲜查询;􏲙􏱀不要使用IN􏲕􏲋,可以使用=􏲜和or􏲝代。此外,在多个􏲊件中,要把非文本的􏲊件放在前面, 文本􏲊件放在后面,示例代码如下:
 (salary > 5000000) AND (lastName LIKE 'Guan') 优于 (lastName LIKE 'Guan') AND (salary > 5000000) 这是因为非文本的􏲊件判断􏰑较􏲞,如果不􏲟􏲠,􏰜不􏰼计􏲡后面的􏲊件表􏱨式了。
 
 在SQLite中,有一些PRAGMA指令可以改变数据库的行为。PRAGMA synchronous指令用于设置数据同􏲬操作。 同􏲬是指在插入数据时,将数据同时􏰟存到存储介􏲭中。如果PRAGMA synchronous = OFF,􏲒表示关􏲮了数据同 􏲬,不等􏲯数据􏰟存到存储介􏲭􏰜可􏲰􏲱􏲲行插入操作,这在大􏱀数据插入时可以大大提高􏱧度。在Objective-C中, 可以调用sqlite3_exec􏲳数设置数据是否同􏲬,相关􏲕􏲋如下:
 sqlite3_open(DATABASE, &db);
 sqlite3_exec(db, "PRAGMA synchronous = OFF", NULL, NULL, &err);
 插入完成后,也可以重新设置PRAGMA synchronous = NORMAL或PRAGMA synchronous = FULL。
 
 
 NSFetchRequest *request = [[NSFetchRequest alloc] init]; //􏲽制一次提取记录数
 [request setFetchLimit:10];
 //􏲽制提取记录􏲾移量
 [request setFetchOffset:5];
 
 可以使用可重用对象的􏱂视图有表视图、集合视图 (UICollectionView)和地图视图(MKMapView)。
 
 dequeueReusableCellWithIdentifier:forIndexPath:方法是iOS6之后提供的方法。与上一个方法􏰑, 该方法的签􏰻多了forIndexPath:部分。􏰛可以通过指定单元格位置􏴳得可重用单元格,不需要判断,模式代码 如下:
 - (UITableViewCell *)tableView:(UITableView *)tableView
 cellForRowAtIndexPath:(NSIndexPath *)indexPath
 {
 static NSString *CellIdentifier = @"CellIdentifier";
 UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:
 CellIdentifier forIndexPath:indexPath];
 􏵖􏵖
 return cell;
 }
 这个方法的使用有一些􏲈制,􏰛􏱼能应用于iOS故事板中,并且在故事板中设计表视图单元格后,指定表视 图单元格为动态的,Identifier属性设置为CellIdentifier。图20-33设定了表视图单元格的属性。
 
 - (UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
 {
 static NSString *headerReuseIdentifier =
 @"TableViewSectionHeaderViewIdentifier";
 UITableViewHeaderFooterView *sectionHeaderView = [tableView dequeueReusableHeaderFooterViewWithIdentifier:headerReuseIdentifier];
 if (!sectionHeaderView) {
 sectionHeaderView  = [[UITableViewHeaderFooterView alloc]initWithReuseIdentifier:headerReuseIdentifier];
 return sectionHeaderView;
 
 - (UICollectionViewCell *)collectionView:(UICollectionView *)
 collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath {
 Cell *cell = [collectionView dequeueReusableCellWithReuseIdentifier: @"CellIdentifier" forIndexPath:indexPath];
 􏵖􏵖
 return cell;
 }
 在上述代码中,collectionView:cellForItemAtIndexPath:方法是集合视图数据源方法,其中Cell是我 们自定􏰿的􏲰􏴴自UICollectionReusableView的单元格类。使用dequeueReusableCellWithReuseIdentifier: 时,需要使用故事板设计UI,并且需要将单元格的Identifier属性设置为CellIdentifier
 
 
 2. 􏴯􏴰􏴱􏴲
 集 合 视 图 单 元 格 可 以 使 用 UICollectionView 的 dequeueReusableSupplementaryView-OfKind: withReuseIdentifier:forIndexPath:方法􏴳得可重用的􏱽􏱾视图,模式代码如下:
 - (UICollectionReusableView *)collectionView:(UICollectionView *)collectionView
 viewForSupplementaryElementOfKind:(NSString *)kind atIndexPath: (NSIndexPath *)indexPath {
 HeaderView *headerView = [collectionView dequeueReusableSupplementaryViewOfKind:UICollectionElementKindSectionHeader withReuseIdentifier:@"HeaderIdentifier" forIndexPath:indexPath];
 headerView.headerLabel.text = [self.eventDate objectAtIndex:indexPath.section];
 return headerView;
 }
 collectionView:viewForSupplementaryElementOfKind:atIndexPath:方法是集合视图的数据源方 法,其中HeaderView是我们自定􏰿的􏲰􏴴自UICollectionReusableView的􏱽􏱾视图类。使用 dequeueReusableSupplementaryViewOfKind:withReuseIdentifier:forIndexPath:时,需要使用故事 板设计UI,并将􏱽􏱾视图的Identifier属性设置为HeaderIdentifier(如图20-35所示)。
 
 
 20.5.3 􏴵􏴲􏴱􏴲􏴖􏳢􏴶􏴷􏱬􏴸􏴹
 在开发地图应用时,也有一个可重用对象MKPinAnnotationView,􏰛是在地图上的一个标注。使用地图视 图的dequeueReusableAnnotationViewWithIdentifier:方法,可以􏴳得MKPinAnnotationView对象。如 果没有可重用的MKPinAnnotationView对象,􏲒使用initWithAnnotation:reuseIdentifier:构􏲪方法创 建。其模式代码如下:
 MKPinAnnotationView *annotationView
 = (MKPinAnnotationView *)[_mapView dequeueReusableAnnotationViewWithIdentifier:
 @"PIN_ANNOTATION"];
 if(annotationView == nil) {
 annotationView = [[MKPinAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"PIN_ANNOTATION"];
 }
 
 主线程所􏳮的事情应该是􏰬应用户􏵦入、事件处理、更新UI,而􏲔时的任务不要在主线程中处理。由于􏲔时 任务使得主线程􏵧􏵞􏵟了,不能􏰬应用户的请求,这样应用的用户体􏵨会很差。
 
 
 //thread########
 - (IBAction)testNSThread:(id)sender {
 [NSThread detachNewThreadSelector:@selector(calculationThreadEntry)
 toTarget:self withObject:nil];
 - (void) calculationThreadEntry
 {
 @autoreleasepool {
 NSUInteger counter = 0;
 while ([[NSThread currentThread] isCancelled] == NO)
 {
 [self doCalculation]; counter++;
 if (counter >= 100)
 {
 break; }
 } }
 }
 
 GCD是基于C􏲕􏲋级别的API,􏰛提供了C􏲳数。下面的代码是ConcurrencyTest工程中使用GCD创建管理线程, 然后􏲲行100次处理:
 - (IBAction)testGCD:(id)sender {
 dispatch_queue_t queue = dispatch_get_global_queue
 (DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
 size_t numberOfIterations = 100;
 dispatch_async(queue, ^(void) { dispatch_apply(numberOfIterations,
 queue, ^(size_t iteration){
 [self doCalculation];
 });
 }); }
 􏰑较上面的两个例子,我们会发现NSThread类􏰑GCD代码要􏵶􏵸,管理􏰊来也不方􏰒。GCD代码编写简单, 还􏱥持多核CPU处理。GCD是苹果重点􏲴􏲵的并发技术,􏵹一的􏵺􏵻是􏰛是基于C􏲕言的API。
 在GCD中,有一个重要的概念,􏵯􏰜是􏵼发队列(dispatch queue)。􏵼发队列是一个对象,􏰛可以接􏵽任务, 并将任务以先到先􏲲行的􏵾序来􏲲行。􏵼发队列可以是并发的或􏰸行的。并发队列可以􏲲行多任务,􏰸行队列同 一时间􏱼􏲲行单一任务。在GCD中,有3种类􏰵的􏵼发队列。
 􏰝 􏵿􏶀􏶁􏶂。􏰸行队列通常用于同􏲬访问一个􏶃定的资源,每次􏱼能􏲲行一个任务。使用􏲳数 dispatch_ queue_create,可以创建􏰸行队列。
 􏰝 􏴺􏴻􏶁􏶂。也􏶄为全局􏵼发队列,可以并发地􏲲行一个或多个任务。并发队列分为高、中、􏱷3个优先级 队列,中级为􏳊认级别。可以使用调用dispatch_get_global_queue􏲳数设定优先级来访问队列。在 上面介绍的ConcurrencyTest工程中,dispatch_queue_t queue = dispatch_get_global_queue (DISPATCH_QUEUE_PRIORITY_DEFAULT, 0)􏲕􏲋用于􏴳得并发队列对象,其中DISPATCH_QUEUE_ PRIORITY_DEFAULT是􏳊认的优先级常􏱀。
 􏰝 􏵠􏶁􏶂。􏰛在应用程序的主线程中,用于更新UI。其􏱪的两个队列不能更新UI。使用dispatch_get_ main_queue􏲳数,可以􏴳得主队列。
 
 
 - (IBAction)click:(id)sender {
 NSURL *imgkURL = [NSURL URLWithString:@"http://www.51work6.com/ios_book/animals/animal-3.png"]; dispatch_queue_t downloadQueue = dispatch_queue_create("com.51work6.image.downloader",
 NULL);
 dispatch_async(downloadQueue, ^{
 NSData *imgData = [NSData dataWithContentsOfURL:imgkURL];
 UIImage *img = [UIImage imageWithData:imgData];
 dispatch_async(dispatch_get_main_queue(), ^{
 self.imageView.image = img;
 });
 });
 }
 在上述代码中,我们使用dispatch_queue_create􏲳数创建􏰸行队列,其中第一个参数com.51work6.
 image.downloader用于给队列指定一个􏰻字,苹果􏲴􏲵使用􏲿􏰻反写,这样􏰒于查看日􏳀信息。 dispatch_queue_t是队列对象。dispatch_async􏲳数异􏲬􏲲行任务,􏱴是􏰛在􏰸行队列中􏱠然是同􏲬􏲲行的。 在更新UI时,如self.imageView.image = img􏲕􏲋,dispatch_async􏲳数必􏳁在主线程中􏲲行。我们使用 􏲕􏲋dispatch_async(dispatch_get_main_queue(),^{...})在主队列中更新UI,其中^{...}是􏳂代码。
 */

#endif
