//
//  ViewController.swift
//  IntegrationSample
//
//  Created by Dmitriy Lihachov on 18/01/16.
//  Copyright © 2016 MobileBridge. All rights reserved.
//

import UIKit

class ViewController: UIViewController, MobileBridgeLibraryDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()

        let clientKey = "d3a5964d"
        let clientSecret = "wUn5VXQHHiFkENlMr5r73n1FbCgeKTp2dUx8LQwj"
        MobileBridgeLibrary.MB_InitLibrary(clientKey, clientSecret: clientSecret, delegate: self);

        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MobileBridgeLibraryDelegate
    
    func MB_LibraryInitialized(mbLib: MobileBridgeLibrary!) {
        print("MobileBridge library is initialized: \(mbLib)");
    }
    
    func MB_SettingEventReply(response: [NSObject : AnyObject]!) {
    }
    
    func MB_NetworkAlertPrompt(alertId: Int32) {
        
    }
    
    func MB_LocationUpdate(position: Int32, max: Int32) {
        
    }
    
    func MB_UpdateCachingDataFinished() {
        
    }
}

