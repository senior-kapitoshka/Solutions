#include <chrono>
#include <thread>

void make_me_slow()
{
    // This function is too fast!
    std::this_thread::sleep_for(std::chrono::seconds(7));
}

///////////////////
#include <unistd.h>

void make_me_slow() 
{
  sleep(7);
}
