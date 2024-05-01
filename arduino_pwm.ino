#define pulso  A4
#define tensao A3

int high, low, duty, leitura;
float periodo, sensor;

void setup()
{
    pinMode(pulso, INPUT);
    pinMode(tensao, INPUT);
    Serial.begin(9600);
}

void loop()
{
    high    = pulseIn(pulso, HIGH);
    low     = pulseIn(pulso, LOW);
    periodo = high + low;
    duty    = (high/periodo)*100;
    leitura  = analogRead(tensao);
    sensor   = leitura*(5.0/1023.0);
    //Serial.print("HIGH: ");
    //Serial.println(high);
    //Serial.print("LOW: ");
    //Serial.println(low);
    //Serial.print("Periodo: ");
    //Serial.println(periodo);
    Serial.print("DutyCicle: ");
    Serial.print(duty);
    Serial.println("%");
    Serial.print("Tensao: ");
    Serial.print(sensor);
    Serial.println("V");
    Serial.println("--------------------------");
    delay(1000);
}