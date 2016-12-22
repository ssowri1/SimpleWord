//
//  LMParagraph.h
//  SimpleWord
//
//  Created by Chenly on 2016/12/21.
//  Copyright © 2016年 Little Meaning. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const LMParagraphAttributeName;

@class LMParagraphStyle;

typedef NS_ENUM(NSUInteger, LMParagraphType) {
    LMParagraphTypeNone = 0,
    LMParagraphTypeUnorderedList,
    LMParagraphTypeOrderedList,
    LMParagraphTypeCheckbox,
};

@interface LMParagraph : NSObject <NSCopying>

@property (nonatomic, assign) LMParagraphType type;
@property (nonatomic, assign) NSRange textRange;

@property (nonatomic, assign) UITextView *textView;
@property (nonatomic, strong) LMParagraphStyle *paragraphStyle;
@property (nonatomic, readonly) NSDictionary *typingAttributes;
@property (nonatomic, strong) UIBezierPath *exclusionPath;

- (instancetype)initWithType:(LMParagraphType)type textRange:(NSRange)textRange;

- (void)addToTextViewIfNeed:(UITextView *)textView;
- (void)removeFromTextView;
- (void)updateForTextChanging;

@end

@interface UITextView (LMParagraphStyle)

// 获取所有选中的段落，通过"\n"来判断段落。
- (NSArray *)rangesOfParagraphForRange:(NSRange)selectedRange;
- (NSArray *)rangesOfParagraph;

- (LMParagraphStyle *)lm_paragraphStyleForTextRange:(NSRange)textRange;

@end
