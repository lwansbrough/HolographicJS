// Reference:
// https://fosterelli.co/getting-started-with-webrtc-data-channels.html


const defaultConfig = {

}

class SharingManager {

    constructor(config = defaultConfig) {
        // Keep track of our connection state
        this.running = false;

        // Use Google's public servers for STUN
        // STUN is a component of the actual WebRTC connection
        var servers = {
            iceServers: [{
                url: 'stun:stun.l.google.com:19302'
            }]
        };

        // Generate this browser a unique ID
        // On Firebase peers use this unique ID to address messages to each other
        // after they have found each other in the announcement channel
        this.id = Math.random().toString().replace('.', '');

        // Unique identifier for two clients to use
        // They MUST share this to find each other
        // Each peer waits in the announcement channel to find its matching identifier
        // When it finds its matching identifier, it initiates a WebRTC offer with
        // that client. This unique identifier can be pretty much anything in practice.
        // Configure, connect, and set up Firebase
        this.sharedKey = prompt("Please enter a shared identifier");

        // You probably want to replace the text below with your own Firebase URL
        var firebaseUrl = 'https://amber-fire-244.firebaseio.com/';
        var database = new Firebase(firebaseUrl);
        this._announceChannel = database.child('announce');
        this._signalChannel = database.child('messages').child(id);
        this._signalChannel.on('child_added', handleSignalChannelMessage);
        this._announceChannel.on('child_added', handleAnnounceChannelMessage);

        // Send a message to the announcement channel
        // If our partner is already waiting, they will send us a WebRTC offer
        // over our Firebase signalling channel and we can begin delegating WebRTC
        _sendAnnounceChannelMessage();
    }

    // Announce our arrival to the announcement channel
    _sendAnnounceChannelMessage = (announceChannel) => {
        this._announceChannel.remove(() => {
            this._announceChannel.push({
                sharedKey: this.sharedKey,
                id: this.id
            });
            console.log('Announced our sharedKey is ' + this.sharedKey);
            console.log('Announced our ID is ' + this.id);
        });
    }

    // Handle an incoming message on the announcement channel
    _handleAnnounceChannelMessage = (snapshot) => {
        const message = snapshot.val();
        if (message.id != id && message.sharedKey == sharedKey) {
            console.log('Discovered matching announcement from ' + message.id);
            remote = message.id;
            initiateWebRTCState();
            this._connect();
        }
    }

    // Send a message to the remote client via Firebase
    _sendSignalChannelMessage = (message) => {
        message.sender = this.id;
        database.child('messages').child(remote).push(message);
    }

    // Handle a WebRTC offer request from a remote client
    _handleOfferSignal = (message) => {
        this.running = true;
        // ID of the remote peer -- set once they send an offer
        this.remote = message.sender;
        this._initiateWebRTCState();
        this._startSendingCandidates();
        this._peerConnection.setRemoteDescription(new RTCSessionDescription(message));
        this._peerConnection.createAnswer((sessionDescription) => {
            console.log('Sending answer to ' + message.sender);
            this._peerConnection.setLocalDescription(sessionDescription);
            this._sendSignalChannelMessage(sessionDescription.toJSON());
        }, (err) => {
            console.error('Could not create offer', err);
        });
    }

    // Handle a WebRTC answer response to our offer we gave the remote client
    _handleAnswerSignal = (message) => {
        this._peerConnection.setRemoteDescription(new RTCSessionDescription(message));
    }

    // Handle an ICE candidate notification from the remote client
    _handleCandidateSignal = (message) => {
        const candidate = new RTCIceCandidate(message);
        this._peerConnection.addIceCandidate(candidate);
    }

    // This is the general handler for a message from our remote client
    // Determine what type of message it is, and call the appropriate handler
    _handleSignalChannelMessage = (snapshot) => {
        const message = snapshot.val();
        const sender = message.sender;
        const type = message.type;
        console.log('Recieved a \'' + type + '\' signal from ' + sender);
        if (type == 'offer') this._handleOfferSignal(message);
        else if (type == 'answer') this._handleAnswerSignal(message);
        else if (type == 'candidate' && this.running) this._handleCandidateSignal(message);
    }

    // Add listener functions to ICE Candidate events
    _startSendingCandidates = () => {
        this._peerConnection.oniceconnectionstatechange = this._handleICEConnectionStateChange;
        this._peerConnection.onicecandidate = this._handleICECandidate;
    }

    // This is how we determine when the WebRTC connection has ended
    // This is most likely because the other peer left the page
    _handleICEConnectionStateChange = () => {
        if (this._peerConnection.iceConnectionState == 'disconnected') {
            console.log('Client disconnected!');
            this._sendAnnounceChannelMessage();
        }
    }

    // Handle ICE Candidate events by sending them to our remote
    // Send the ICE Candidates via the signal channel
    _handleICECandidate = (event) => {
        let candidate = event.candidate;
        if (candidate) {
            candidate = candidate.toJSON();
            candidate.type = 'candidate';
            console.log('Sending candidate to ' + remote);
            sendSignalChannelMessage(candidate);
        } else {
            console.log('All candidates sent');
        }
    }

    // This is our receiving data channel event
    // We receive this channel when our peer opens a sending channel
    // We will bind to trigger a handler when an incoming message happens
    _handleDataChannel = (event) => {
        event.channel.onmessage = _handleDataChannelMessage;
    }

    // This is called on an incoming message from our peer
    // You probably want to overwrite this to do something more useful!
    _handleDataChannelMessage = (event) => {
        console.log('Recieved Message: ' + event.data);
        document.write(event.data + '<br />');
    }

    // This is called when the WebRTC sending data channel is offically 'open'
    _handleDataChannelOpen = () => {
        console.log('Data channel created!');
        this._dataChannel.send('Hello! I am ' + this.id);
    }

    // Called when the data channel has closed
    _handleDataChannelClosed = () => {
        console.log('The data channel has been closed!');
    }

    // Function to offer to start a WebRTC connection with a peer
    _connect = () => {
        this.running = true;
        this._startSendingCandidates();
        this._peerConnection.createOffer((sessionDescription) => {
            console.log('Sending offer to ' + this.remote);
            this._peerConnection.setLocalDescription(sessionDescription);
            this._sendSignalChannelMessage(sessionDescription.toJSON());
        }, (err) => {
            console.error('Could not create offer', err);
        });
    }

    // Function to initiate the WebRTC peerconnection and dataChannel
    _initiateWebRTCState = () => {
        // This is our WebRTC connection
        this._peerConnection = new RTCPeerConnection(servers);
        this._peerConnection.ondatachannel = handleDataChannel;
        // This is our outgoing data channel within WebRTC
        this._dataChannel = peerConnection.createDataChannel('myDataChannel');
        this._dataChannel.onmessage = handleDataChannelMessage;
        this._dataChannel.onopen = handleDataChannelOpen;
    }
}
