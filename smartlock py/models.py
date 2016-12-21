import bluetooth
import subprocess

class Listener:
    def __init__(self):
        self.sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    def start(self):
        port = 1
        self.sock.bind(("",bluetooth.PORT_ANY))
        self.sock.listen(1)
        

        id = '00001101-0000-1000-8000-00805f9b34fb'
        
        bluetooth.advertise_service(self.sock, "wright", service_id = id, service_classes = [ id, bluetooth.SERIAL_PORT_CLASS], profiles = [ bluetooth.SERIAL_PORT_PROFILE ])
        print 'Listening'
        while True:
            client, addr = self.sock.accept()


            buffer = ""

            try:

                recv_data = client.recv(1024)

                if len(recv_data) == 0:
                    print 'Did not receive data'

                print 'data received'
                buffer += recv_data;
                print buffer
                if buffer == 'get!':
                    f = open('/var/smartlock/status.txt', 'r')
                    contents = f.read()
                    f.close();
                    print 'Contents: ' + contents
                    if contents == 'unlocked!':
                        client.send('unlocked!')
                    elif contents == 'locked!':
                        client.send('locked!')
                    else:
                        client.send('server-side error!')
                    print 'End of get!'
                elif buffer == 'unlock!':
                    subprocess.call(['smartlock','unlock'])
                    print 'Unlocked'
                    client.send('unlocked!')
                elif buffer == 'lock!':
                    subprocess.call(['smartlock','lock'])
                    print 'Locked'
                    client.send('locked!')
                else:
                    client.send('server-side error!')
                    print 'EPIC PHAIL!'
            except bluetooth.btcommon.BluetoothError:
                client.close()
                continue

