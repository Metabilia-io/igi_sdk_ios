//
//  IGIPhotoViewerVC.h
//  igi_sdk
//
//  Created by Jameel Khan on 25/05/2019.
//  Copyright © 2019 I Got It. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <igi_sdk/IGIBaseVC.h>


@interface IGIPhotoViewerVC : IGIBaseVC

@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (weak, nonatomic) IBOutlet UIPageControl *pageControl;

+ (id)photosVCWithPhotoItems:(NSArray *)photos;
- (id)initPhotosVCWithPhotoItems:(NSArray *)photos;



@end


