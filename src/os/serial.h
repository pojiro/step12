int serial_init(int index);
int serial_is_send_enable(int index);
int serial_send_byte(int index, char b);
int serial_is_recv_enable(int index);
char serial_recv_byte(int index);
