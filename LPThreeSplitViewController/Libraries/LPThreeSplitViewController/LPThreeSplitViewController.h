//
//  FEThreeViewController.h
//  H2Oteam_Universal
//
//  Created by Luka Penger on 4/21/13.
//  Copyright (c) 2013 LukaPenger. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <QuartzCore/QuartzCore.h>

#ifndef LP_STRONG
#if __has_feature(objc_arc)
#define LP_STRONG strong
#else
#define LP_STRONG retain
#endif
#endif

#ifndef LP_WEAK
#if __has_feature(objc_arc_weak)
#define LP_WEAK weak
#elif __has_feature(objc_arc)
#define LP_WEAK unsafe_unretained
#else
#define LP_WEAK assign
#endif
#endif

@protocol LPThreeSplitViewControllerDelegate;

@interface LPThreeSplitViewController : UIViewController
{
    UIView *gestureListView;
    UITapGestureRecognizer *tapListView;
    UISwipeGestureRecognizer *swipeListView;
}

@property (nonatomic, LP_WEAK) id<LPThreeSplitViewControllerDelegate> delegate;

@property (nonatomic, LP_STRONG) UIView *menuView;
@property (nonatomic, LP_STRONG) UIView *listView;
@property (nonatomic, LP_STRONG) UIView *detailView;

@property (nonatomic, LP_STRONG) UIViewController *menuViewController;
@property (nonatomic, LP_STRONG) UIViewController *listViewController;
@property (nonatomic, LP_STRONG) UIViewController *detailViewController;

@property (nonatomic, assign) CGFloat menuWidthLandscape;
@property (nonatomic, assign) CGFloat menuWidthPortrait;

@property (nonatomic, assign) CGFloat listWidthLandscape;
@property (nonatomic, assign) CGFloat listWidthPortrait;

@property (nonatomic, assign) BOOL listPortraitClosing;
@property (nonatomic, assign) BOOL showListViewControllerWhenRotate;

@property (nonatomic, assign) UIColor *menuViewShadowColor;
@property (nonatomic, assign) CGFloat menuViewShadowOpacity;
@property (nonatomic, assign) CGFloat menuViewShadowRadius;

@property (nonatomic, assign) UIColor *listViewShadowColor;
@property (nonatomic, assign) CGFloat listViewShadowOpacity;
@property (nonatomic, assign) CGFloat listViewShadowRadius;

@property (nonatomic, assign) CGFloat listViewAnimationDuration;

@property (nonatomic, assign) CGFloat gestureListViewOpacity;
@property (nonatomic, assign) UIColor *gestureListViewColor;
@property (nonatomic, assign) CGFloat gestureListViewPaddingTop;

- (id)initWithMenuViewController:(UIViewController*)menuViewController ListViewController:(UIViewController*)listViewController DetailViewController:(UIViewController*)detailViewController;

- (void)showListViewController:(id)sender withAnimation:(BOOL)animation;
- (void)hideListViewController:(id)sender withAnimation:(BOOL)animation;

@end

#pragma mark - Delegate Protocol:
@protocol LPThreeSplitViewControllerDelegate <NSObject>

@optional

- (void)LPThreeSplitViewController:(LPThreeSplitViewController *)threeSplitViewController willShowListViewController:(UIViewController*)listViewController;
- (void)LPThreeSplitViewController:(LPThreeSplitViewController *)threeSplitViewController didShowListViewController:(UIViewController*)listViewController;
- (void)LPThreeSplitViewController:(LPThreeSplitViewController *)threeSplitViewController willHideListViewController:(UIViewController*)listViewController;
- (void)LPThreeSplitViewController:(LPThreeSplitViewController *)threeSplitViewController didHideListViewController:(UIViewController*)listViewController;

@end
