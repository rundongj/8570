    define($IP 192.168.1.2);    
    // This MAC must be identical with the one you defined in config.xen
    define($MAC 00:00:00:00:01:00);

    source :: FromDevice;
    sink   :: ToDevice;
    c :: Classifier(
        12/0806 20/0001, 
        12/0806 20/0002, 
        12/0800, 
        -); 

    arpq :: ARPQuerier($IP, $MAC);
    arpr :: ARPResponder($IP $MAC);  // No comma here. 

    source -> c;
    c[0] -> ARPPrint -> arpr -> sink;
    c[1] -> [1]arpq;
    Idle -> [0]arpq;
    arpq -> ARPPrint -> sink;
    c[2] -> CheckIPHeader(14) -> ICMPPingResponder() -> Print('Responder') -> EtherMirror() -> sink;
    c[3] -> Discard;

