//
//  TLYShyNavBarManager.h
//  TLYShyNavBarDemo
//
//  Created by Mazyad Alabduljaleel on 6/13/14.
//  Copyright (c) 2014 Telly, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

/*  CLASS DESCRIPTION:
 *  ==================
 *      Manages the relationship between a scrollView and a view
 *  controller. Must be instantiated and assigned the scrollView
 *  that drives the contraction/expansion, then assigned to the
 *  viewController that needs the functionality. Must be assigned
 *  throught the UIViewController category:
 *      
 *  viewController.shyNavManager = ...;
 *
 *      OR
 *
 *  [viewController addShyNavManagerWithScrollView:scrollView]
 */

@interface TLYShyNavBarManager : NSObject

/* The view controller that is part of the navigation stack
 * IMPORTANT: Must have access to navigationController
 */
@property (nonatomic, readonly, weak) UIViewController *viewController;

/* The scrollView subclass that will drive the contraction/expansion */
@property (nonatomic, weak) UIScrollView *scrollView;

/* The container to contain the extension view, if any. Exposed to
 * allow the developer to adjust content offset as necessary
 */
@property (nonatomic, readonly) UIView *extensionViewContainer;

/* Control the resistance when scrolling up/down before the navbar 
 * expands/contracts again.
 */
@property (nonatomic) CGFloat expansionResistance;      // default 200
@property (nonatomic) CGFloat contractionResistance;    // default 0

- (void)setExtensionView:(UIView *)view;

@end


/*  CATEGORY DESCRIPTION:
 *  =====================
 *      The category described in the TLYShyNavBarManager usage, and it
 *  simply uses associated objects to attatch a TLYShyNavBar to the 
 *  designated view controller.
 *
 *      We also perform some swizzling to pass notifications to the 
 *  TLYShyNavBar. Things like, viewDidLayoutSubviews, viewWillAppear and
 *   Disappear, ... etc.
 */

@interface UIViewController (ShyNavBar)

@property (nonatomic, strong) TLYShyNavBarManager *shyNavBarManager;

// Convenience
- (void)addShyNavBarManagerWithScrollView:(UIScrollView *)scrollView;

@end
