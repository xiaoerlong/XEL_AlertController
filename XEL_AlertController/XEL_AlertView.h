//
//  XEL_AlertViewController.h
//  XEL_AlertController
//
//  Created by leijin on 16/12/1.
//  Copyright © 2016年 xel. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, XEL_AlertActionStyle) {
    XEL_AlertActionStyleDefault = 0,
    XEL_AlertActionStyleCancel,
    XEL_AlertActionStyleDestructive
};

typedef NS_ENUM(NSInteger, XEL_AlertControllerStyle) {
    XEL_AlertControllerStyleActionSheet = 0,
    XEL_AlertControllerStyleAlert
};

@interface XEL_AlertAction : NSObject <NSCopying>
typedef void(^actionHandle)(XEL_AlertAction *action);
+ (instancetype)xel_actionWithTitle:(NSString *)title style:(XEL_AlertActionStyle)style handler:(void (^)(XEL_AlertAction *action))handler;

@property (nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) XEL_AlertActionStyle style;
@property (nonatomic, getter=isEnabled) BOOL enabled;

@property (nonatomic, copy) actionHandle handle;

@end

@interface XEL_AlertView : UIView

+ (instancetype)xel_alertControllerWithTitle:(NSString *)title message:(NSString *)message preferredStyle:(XEL_AlertControllerStyle)preferredStyle;

- (void)xel_addAction:(XEL_AlertAction *)action;
@property (nonatomic, readonly) NSArray <XEL_AlertAction *> *actions;

@property (nonatomic, strong) XEL_AlertAction *preferredAction;

- (void)xel_addTextFieldWithConfigutationHanler:(void (^)(UITextField *textField))configurationHandler;
@property (nonatomic, readonly) NSArray <UITextField *> *textFields;

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *message;

@property (nonatomic, readonly) XEL_AlertControllerStyle preferredStyle;

- (void)showInView:(UIView *)view;

@end
