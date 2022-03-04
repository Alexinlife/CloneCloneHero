#include "Communication.h"

Communication::Communication()
{
    arduino = new SerialPort("COM8", BAUD);

    if (arduino->isConnected()) {
        cout << "Connected" << endl;
    }

    input_names = new string[10]{ "Switch1", "Switch2", "Switch3", "Switch4", "Switch5", "JoyStickX", "JoyStickY", "AccelX", "AccelY", "AccelZ" };
}

Communication::~Communication()
{

}

/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Port de communication, tampon de réception du message
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Réception du message
-----------------------------------------------------------------------------*/
bool Communication::sendTo(SerialPort* arduino, json j_msg)
{
    // Return 0 if error
    string msg = j_msg.dump();
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    return ret;
}


/*---------------------------Definition de fonctions ------------------------
Fonction de réception
Entrée : Port de communication, message à envoyer
Sortie : Code d'erreur, 1 = erreur, 0 = ok
Traitement : Envoie du message
-----------------------------------------------------------------------------*/
bool Communication::receiveFrom(SerialPort* arduino, string& msg)
{
    // Return 0 if error
    // Message output in msg
    string str_buffer;
    char char_buffer[MAX_MSG_SIZE];
    int buffer_size;

    msg.clear(); // clear string
    // Read serialport until '\n' character (Blocking)
    while (msg.empty() || msg.back() != '\n') {
        if (msg.size() > MAX_MSG_SIZE) {
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MAX_MSG_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }

    msg.pop_back(); //remove '/n' from string
    return true;
}

int* Communication::fetch()
{
    j_msg_send["led1"] = led_state;
    j_msg_send["led4"] = led_state;
    j_msg_send["led7"] = led_state;
    j_msg_send["led10"] = led_state;

    if (!sendTo(arduino, j_msg_send))
    {
        cerr << "Erreur lors de l'envoie du message. " << endl;
    }

    // Reception message Arduino
    j_msg_rcv.clear(); // effacer le message precedent
    if (!receiveFrom(arduino, raw_msg))
    {
        cerr << "Erreur lors de la reception du message. " << endl;
    }

    if (raw_msg.size() > 0) {
        j_msg_rcv = json::parse(raw_msg);
        for (int i = 0; i < 10; i++)
        {
            inputs[i] = j_msg_rcv[input_names[i]];
            // cout << inputs[i] << "(" << i << ")" << endl;
        }
    }

    led_state = !led_state;

    Sleep(10);

    return inputs;
}