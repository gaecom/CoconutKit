//
//  HLSPlaceholderInsetSegue.h
//  CoconutKit
//
//  Created by Samuel Défago on 28.06.12.
//  Copyright (c) 2012 Hortis. All rights reserved.
//

#import "HLSTransitionStyle.h"

/**
 * Segue class for setting the inset view controller of an HLSPlaceholderViewController when using storyboards.
 *
 * The source view controller must either be a placeholder view controller, or a view controller already installed
 * as inset view controller of a placeholder view controller. The source view controller can implement the 
 * -prepareForSegue:sender: method to further customize transition properties (index, transition style and duration)
 *
 * A view controller can be pre-loaded into a placeholder view controllers by binding the placeholder view controller
 * with it using a segue with the reserved identifier 'init_at_index_N', where N is the index at which the view 
 * controller must be initially loaded. This index must be between 0 and 19, which allows pre-loading of 20 view 
 * controllers. This should be sufficient: Though a placeholder view controller can hold more than 20 view controllers,
 * this should never occur in practice
 */
@interface HLSPlaceholderInsetSegue : UIStoryboardSegue {
@private
    NSUInteger m_index;
    HLSTransitionStyle m_transitionStyle;
    NSTimeInterval m_duration;
}

/**
 * The placeholder view index which the destination view controller must be displayed in
 * Default value is 0
 */
@property (nonatomic, assign) NSUInteger index;

/**
 * Push animation style
 * Default value is HLSTransitionStyleNone
 */
@property (nonatomic, assign) HLSTransitionStyle transitionStyle;

/**
 * Push animation duration
 * Default is kAnimationTransitionDefaultDuration
 */
@property (nonatomic, assign) NSTimeInterval duration;

@end