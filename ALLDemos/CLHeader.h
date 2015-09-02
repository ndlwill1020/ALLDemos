//
//  CLHeader.h
//  ALLDemos
//
//  Created by macuser on 15/8/26.
//  Copyright (c) 2015年 ndl. All rights reserved.
//

#ifndef ALLDemos_CLHeader_h
#define ALLDemos_CLHeader_h

/*
 CLLocationManager。用于定位服务管理类,它能够给我们提供位置信息和高度信息,也可以监控设备 进入或离开某个区域,还可以获得设备的运行方向等。
  CLLocationManagerDelegate。它是CLLocationManager类的委托协议。
  CLLocation。该类封装了位置和高度信息。
 
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 //初始化定位服务管理对象
 _locationManager = [[CLLocationManager alloc] init];
 _locationManager.delegate = self;
 _locationManager.desiredAccuracy = kCLLocationAccuracyBest; 1 _locationManager.distanceFilter = 1000.0f; 2
 }
 
 - (void)viewWillAppear:(BOOL)animated
 {
 [super viewWillAppear:animated]; //开始定位
 [_locationManager startUpdatingLocation];
 }
 
 - (void)viewWillDisappear:(BOOL)animated
 {
 [super viewWillDisappear:animated]; //停止定位
 [_locationManager stopUpdatingLocation];
 }
 
 #pragma mark Core Location委托方法用于实现位置的更新
 - (void)locationManager:(CLLocationManager *)manager didUpdateLocations:
 (NSArray *)locations
 {
 CLLocation * currLocation = [locations lastObject]; 1 _txtLat.text = [NSString stringWithFormat:@"%3.5f",
 currLocation.coordinate.latitude]; 2 _txtLng.text = [NSString stringWithFormat:@"%3.5f",
 currLocation.coordinate.longitude]; 3 _txtAlt.text = [NSString stringWithFormat:@"%3.5f",currLocation.altitude]; 4
 }
 
 
 在上一节的案例中,我们知道了经度和纬度,那又能怎么样呢?一般人很难知道这些数字(比如(114.15818, 22.28468))代表的是什么地方,地理信息反编码就是用来解决这个问题的它通过地理坐标返回某个地点的相关 文字描述信息。
 CLPlacemark类
 addressDictionary。地址信息的字典,包含一些键值对,其中的键在Address Book framework(地址簿 框架)中定义。
  ISOcountryCode。ISO国家代号。
  Country。国家信息。
  postalCode。邮政编码。
  administrativeArea。行政区域信息。
  subAdministrativeArea。行政区域附加信息。
  locality。指定城市信息。
  subLocality。指定城市信息附加信息。
  thoroughfare。指定街道级别信息。
  subThoroughfare。指定街道级别的附加信息。
 
 - (IBAction)reverseGeocode:(id)sender {
 CLGeocoder *geocoder = [[CLGeocoder alloc] init];
 [geocoder reverseGeocodeLocation:_currLocation
 completionHandler:^(NSArray *placemarks, NSError *error) { 1
 if ([placemarks count] > 0) { 2 CLPlacemark *placemark = placemarks[0]; 3 NSDictionary *addressDictionary = placemark.addressDictionary; 4
 NSString *address = [addressDictionary objectForKey:(NSString *) kABPersonAddressStreetKey]; 5
 address = address == nil ? @"": address;
 NSString *state = [addressDictionary objectForKey:(NSString *) kABPersonAddressStateKey]; 6
 state = state == nil ? @"": state;
 NSString *city = [addressDictionary objectForKey:(NSString *) kABPersonAddressCityKey]; 7
 city = city == nil ? @"": city;
 _txtView.text = [NSString stringWithFormat:@"%@ \n%@ \n%@",state, address,city];
 }
 }]; }
 
 
 geocodeAddressDictionary:completionHandler:。通过指定一个地址信息字典对象参数进行查询。  geocodeAddressString:completionHandler:。通过指定一个地址字符串参数进行查询。
  geocodeAddressString:inRegion:completionHandler:。通过指定地址字符串和查询的范围作为
 参数进行查询,其中inRegion部分的参数用于指定查询范围,它是CLRegion类型。
 
 
 ////////////MAP
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 _mapView.mapType = MKMapTypeStandard;
 _mapView.delegate = self;
 }
 在viewDidLoad方法中,我们设置了地图的类型,其中共有3种类型,具体如下所示。
  MKMapTypeStandard。标注地图类型,如图15-16所示。
  MKMapTypeSatellite。卫星地图类型。如图15-17所示,在卫星地图中没有街道名称等信息。
  MKMapTypeHybrid。混合地图类型。如图15-18所示,混合地图是在卫星地图上标注出街道等信息。
 
 typedef struct {
 CLLocationCoordinate2D center; //中心点 MKCoordinateSpan span; //跨度
 } MKCoordinateRegion;
 
 typedef struct {
 CLLocationDegrees latitudeDelta; //区域的南北跨度 CLLocationDegrees longitudeDelta; //区域的东西跨度
 } MKCoordinateSpan;
 
 在赤道上1度大约是111公里,随着靠近两极,这个距离逐步变小,在地球的两个极点时变为0公里。它 们是有差别的,这源于我们地球经线和纬线的中心点不同。
 
 - (IBAction)geocodeQuery:(id)sender {
 if (_txtQueryKey.text == nil || [_txtQueryKey.text length] == 0) {
 return; }
 CLGeocoder *geocoder = [[CLGeocoder alloc] init];
 [geocoder geocodeAddressString:_txtQueryKey.text completionHandler:            ／／＃＃＃＃＃
 ^(NSArray *placemarks, NSError *error) {
 NSLog(@"查询记录数:%i",[placemarks count]);
 if ([placemarks count] > 0) {
 [_mapView removeAnnotations:_mapView.annotations]; 1 }
 for (int i = 0; i < [placemarks count]; i++) {
 CLPlacemark* placemark = placemarks[i];
 //关闭键盘
 [_txtQueryKey resignFirstResponder];
 //调整地图位置和缩放比例
 MKCoordinateRegion viewRegion = MKCoordinateRegionMakeWithDistance( placemark.location.coordinate, 10000, 10000);
 [_mapView setRegion:viewRegion animated:YES];
 MapLocation *annotation = [[MapLocation alloc] init];
 annotation.streetAddress = placemark.thoroughfare;
 annotation.city = placemark.locality;
 annotation.state = placemark.administrativeArea;
 annotation.zip = placemark.postalCode;
 annotation.coordinate = placemark.location.coordinate;
 [_mapView addAnnotation:annotation];
 
 第6行代码把标注点MapLocation对象添加到地图视图上。一旦该方法被调用,地图视图委托方法 mapView:viewForAnnotation:就会被回调。
 
 - (MKAnnotationView *) mapView:(MKMapView *)theMapView
 viewForAnnotation:(id <MKAnnotation>) annotation { 1
 MKPinAnnotationView *annotationView = (MKPinAnnotationView *)[_mapView dequeueReusableAnnotationViewWithIdentifier:@"PIN_ANNOTATION"]; 2 if(annotationView == nil) { 3
 annotationView = [[MKPinAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"PIN_ANNOTATION"]; 4
 }
 annotationView.pinColor = MKPinAnnotationColorPurple; 5 annotationView.animatesDrop = YES; 6 annotationView.canShowCallout = YES; 7
 ￼        return annotationView;
 }
 
 #import <MapKit/MapKit.h>
 @interface MapLocation : NSObject<MKAnnotation>
 @property (nonatomic, readwrite) CLLocationCoordinate2D coordinate; //街道信息属性
 @property (nonatomic, copy) NSString *streetAddress;
 //城市信息属性
 @property (nonatomic, copy) NSString *city; //州、省、市信息
 @property (nonatomic, copy) NSString *state; //邮编
 @property (nonatomic, copy) NSString *zip; //地理坐标
 @property (nonatomic, readwrite) CLLocationCoordinate2D coordinate;
 @end
 
 
 MKAnnotation协议需要实现如下所示的两个方法。
 - (NSString *)title {
 return @"您的位置!"; }
 - (NSString *)subtitle {
 NSMutableString *ret = [NSMutableString new];
 if (_state)
 [ret appendString:_state];
 if (_city)
 [ret appendString:_city];
 if (_city && _state)
 [ret appendString:@", "];
 if (_streetAddress && (_city || _state || _zip))
 [ret appendString:@" • "]; if (_streetAddress)
 [ret appendString:_streetAddress];
 if (_zip)
 [ret appendFormat:@", %@", _zip];
 return ret;
 } @end
 
 跟踪用户位置变化
 - (void)viewDidLoad
 {
 [super viewDidLoad];
 if ([CLLocationManager locationServicesEnabled])
 {
 _mapView.mapType = MKMapTypeStandard;
 _mapView.delegate = self;
 _mapView.showsUserLocation = YES;
 [_mapView setUserTrackingMode:MKUserTrackingModeFollow animated:YES];
 } }
 
 然后,我们还需要实现地图视图委托方法mapView:didUpdateUserLocation:,它的代码如下:
 - (void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation
 {
 _mapView.centerCoordinate = userLocation.location.coordinate;
 
 
 
 MKPlacemark与CLPlacemark不同,前 者是地图上的地标类,后者是定位使用的地标类。
 - (IBAction)geocodeQuery:(id)sender {
 if (_txtQueryKey.text == nil || [_txtQueryKey.text length] == 0) {
 return; }
 CLGeocoder *geocoder = [[CLGeocoder alloc] init];
 [geocoder geocodeAddressString:_txtQueryKey.text completionHandler:^(NSArray
 *placemarks, NSError *error) { NSLog(@"查询记录数:%i",[placemarks count]); if ([placemarks count] > 0) {
 CLPlacemark* placemark = placemarks[0];
 CLLocationCoordinate2D coordinate = placemark.location.coordinate; 1 NSDictionary* address = placemark.addressDictionary; 2 MKPlacemark *place = [[MKPlacemark alloc]
 initWithCoordinate:coordinate addressDictionary:address]; 3 MKMapItem *mapItem = [[MKMapItem alloc]initWithPlacemark:place]; 4
 [mapItem openInMapsWithLaunchOptions:nil]; 5
 //关闭键盘
 [_txtQueryKey resignFirstResponder];
 }
 }]; }
 
 NSDictionary* options =[[NSDictionary alloc]initWithObjectsAndKeys: MKLaunchOptionsDirectionsModeDriving,MKLaunchOptionsDirectionsModeKey, nil];
 MKMapItem *mapItem = [[MKMapItem alloc]initWithPlacemark:place]; [mapItem openInMapsWithLaunchOptions:options];
 */

#endif
