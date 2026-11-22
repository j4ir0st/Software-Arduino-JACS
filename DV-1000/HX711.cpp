#include "HX711.h"

HX711::HX711() {
	PD_SCK = 0;
	DOUT = 0;
	GAIN = 1;
	OFFSET = 0;
	SCALE = 1.0f;
}

HX711::HX711(byte dout, byte pd_sck, byte gain) {
	OFFSET = 0;
	SCALE = 1.0f;
	begin(dout, pd_sck, gain);
}

HX711::~HX711() {
}

void HX711::begin(byte dout, byte pd_sck, byte gain) {
	PD_SCK = pd_sck;
	DOUT = dout;

	pinMode(PD_SCK, OUTPUT);
	pinMode(DOUT, INPUT);

	digitalWrite(PD_SCK, LOW);
	set_gain(gain);
}

bool HX711::is_ready() {
	return digitalRead(DOUT) == LOW;
}

bool HX711::wait_ready_retry(int retries, unsigned long delay_ms) {
	int count = 0;
	while (count < retries) {
		if (is_ready()) {
			return true;
		}
		delay(delay_ms);
		count++;
	}
	return false;
}

bool HX711::wait_ready_timeout(unsigned long timeout, unsigned long delay_ms) {
	unsigned long millisStarted = millis();
	while (millis() - millisStarted < timeout) {
		if (is_ready()) {
			return true;
		}
		delay(delay_ms);
	}
	return false;
}

void HX711::set_gain(byte gain) {
	switch (gain) {
		case 128:		// channel A, gain factor 128
			GAIN = 1;
			break;
		case 64:		// channel A, gain factor 64
			GAIN = 3;
			break;
		case 32:		// channel B, gain factor 32
			GAIN = 2;
			break;
		default:
			GAIN = 1;
			break;
	}

	digitalWrite(PD_SCK, LOW);
	read();
}

long HX711::read() {
	// Espera que el conversor este listo con un tiempo limite de 500 ms para no bloquear el sistema
	unsigned long timeout_start = millis();
	while (!is_ready()) {
		if (millis() - timeout_start > 500) {
			return 0;
		}
		delay(1);
	}

	unsigned long value = 0;
	uint8_t data[3] = { 0 };
	uint8_t filler = 0x00;

	// Lee los 24 bits usando shiftIn estandar
	data[2] = shiftIn(DOUT, PD_SCK, MSBFIRST);
	data[1] = shiftIn(DOUT, PD_SCK, MSBFIRST);
	data[0] = shiftIn(DOUT, PD_SCK, MSBFIRST);

	// Configura la ganancia para la siguiente lectura con pulsos adicionales de reloj
	for (unsigned int i = 0; i < GAIN; i++) {
		digitalWrite(PD_SCK, HIGH);
		delayMicroseconds(1);
		digitalWrite(PD_SCK, LOW);
		delayMicroseconds(1);
	}

	// Extension de signo para entero con signo de 32 bits (complemento a dos)
	if (data[2] & 0x80) {
		filler = 0xFF;
	} else {
		filler = 0x00;
	}

	value = ( static_cast<unsigned long>(filler) << 24
			| static_cast<unsigned long>(data[2]) << 16
			| static_cast<unsigned long>(data[1]) << 8
			| static_cast<unsigned long>(data[0]) );

	return static_cast<long>(value);
}

long HX711::read_average(byte times) {
	long sum = 0;
	byte valid_reads = 0;
	for (byte i = 0; i < times; i++) {
		sum += read();
		valid_reads++;
	}
	return (valid_reads > 0) ? (sum / valid_reads) : 0;
}

double HX711::get_value(byte times) {
	return (double)read_average(times) - (double)OFFSET;
}

float HX711::get_units(byte times) {
	if (SCALE == 0.0f) return 0.0f;
	return (float)(get_value(times) / SCALE);
}

void HX711::tare(byte times) {
	double sum = read_average(times);
	set_offset((long)sum);
}

void HX711::set_scale(float scale) {
	if (scale != 0.0f) {
		SCALE = scale;
	} else {
		SCALE = 1.0f;
	}
}

float HX711::get_scale() {
	return SCALE;
}

void HX711::set_offset(long offset) {
	OFFSET = offset;
}

long HX711::get_offset() {
	return OFFSET;
}

void HX711::power_down() {
	digitalWrite(PD_SCK, LOW);
	digitalWrite(PD_SCK, HIGH);	
}

void HX711::power_up() {
	digitalWrite(PD_SCK, LOW);	
}
