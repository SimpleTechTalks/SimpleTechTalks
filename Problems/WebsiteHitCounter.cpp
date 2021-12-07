#include <iostream>

#define TIME_PERIOD_IN_SECONDS 300

int timestamp[TIME_PERIOD_IN_SECONDS];
int hitcounter[TIME_PERIOD_IN_SECONDS];

void clear_hit_count (int time_stamp)
{
	timestamp[time_stamp % TIME_PERIOD_IN_SECONDS] = time_stamp;
	hitcounter[time_stamp % TIME_PERIOD_IN_SECONDS] = 0;
}

void increment_hit_count (int time_stamp, int count)
{
	if (timestamp[time_stamp % TIME_PERIOD_IN_SECONDS] != time_stamp) {
		clear_hit_count (time_stamp);
	}
	hitcounter[time_stamp % TIME_PERIOD_IN_SECONDS] += count;
}

int get_total_hits (int time_stamp)
{
	int start_time = time_stamp - TIME_PERIOD_IN_SECONDS;
	int total = 0;
	for (int i = 0; i < TIME_PERIOD_IN_SECONDS; i++) {
		if (start_time <= timestamp[i]) {
			total += hitcounter[i];
		}
	}
	return total;
}

int main ()
{
	for (int i = 0; i < 5000; i++) {
		if (rand () % 100 == 0) {
			std::cout << "At time: " << i << " Total hitcount: " << get_total_hits (i) << std::endl;
		}
		increment_hit_count (i, rand () % 100);
	}
}