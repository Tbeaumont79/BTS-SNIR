void    setup()
{
    Serial.begin(9600);
    char * typeMesure[2]={"LDR = ","CTN = "};
}

void    loop()
{
    Serial.println(analogRead(A3),DEC);
    delay(500);
}
