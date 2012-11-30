//
//  HLSRestrictedInterfaceProxy.h
//  CoconutKit
//
//  Created by Samuel Défago on 25.04.12.
//  Copyright (c) 2012 Hortis. All rights reserved.
//

// Forward declarations
@class HLSZeroingWeakRef;

/**
 * HLSRestrictedInterfaceProxy allows the easy creation of lightweight proxy objects through which interaction 
 * with the underlying object only happens through a restricted subset of its class interface. The restricted
 * interface subset is defined using a protocol. Such protocols in general only contain @required methods, but
 * @optional methods can appear as well. In such cases the caller is responsible of checking whether the proxy
 * object responds to the method before calling it.
 *
 * A typical use case is a mutable object which you want to make immutable, without having to implement a
 * dedicated immutable class. This is easily achieved by defining a readonly proxy interface protocol
 * (i.e. exposing accessor methods only) and returning the proxy object, instead of the underlying mutable
 * object, where mutability must be prevented.
 *
 * Proxy objects can therefore be useful when carefully designing immutable classes, namely by having public
 * methods return only immutable objects or readonly proxies to immutable internal objects.
 *
 * When creating a proxy object, a protocol informally compatible with the target class must be provided. By 
 * informally we mean that the target class must implement at least all methods @required by the protocol. Calls
 * to non-implemented @optional methods will crash, callers must therefore test whether the proxy object responds 
 * to @optional selectors before calling them.
 *
 * The proxy object introduces an additionaly safety indirection layer in comparison to the brute-force approach
 * of C-casting to id<RestrictedProtocol>. This approach works but makes it easy to cast the object back to its
 * original identity (either by mistake or on purpose), allowing access to the unrestricted interface.
 *
 * The proxy object does not retain the object it is created from, and if the object gets deallocated, all 
 * associated proxy objects are automatically set to nil.
 */
@interface HLSRestrictedInterfaceProxy : NSProxy {
@private
    HLSZeroingWeakRef *_targetZeroingWeakRef;
    Protocol *_protocol;
}

/**
 * Convenience constructor
 */
+ (id)proxyWithTarget:(id)target protocol:(Protocol *)protocol;

/**
 * Create a proxy object. On success a proxy object is returned, otherwise nil. The created proxy object 
 * conforms to the protocol given as parameter, you should therefore store the result as id<protocol> for 
 * further compiler-friendly use
 *
 * Currently the target cannot be another proxy object
 */
- (id)initWithTarget:(id)target protocol:(Protocol *)protocol;

@end

@interface NSObject (HLSRestrictedInterfaceProxy)

- (id)proxyWithRestrictedInterface:(Protocol *)protocol;

@end